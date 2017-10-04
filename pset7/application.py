from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session, url_for
from flask_session import Session
from passlib.apps import custom_app_context as pwd_context
from tempfile import mkdtemp

from helpers import *

# configure application
app = Flask(__name__)

# ensure responses aren't cached
if app.config["DEBUG"]:
    @app.after_request
    def after_request(response):
        response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
        response.headers["Expires"] = 0
        response.headers["Pragma"] = "no-cache"
        return response

# custom filter
app.jinja_env.filters["usd"] = usd

# configure session to use filesystem (instead of signed cookies)
app.config["SESSION_FILE_DIR"] = mkdtemp()
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# configure CS50 Library to use SQLite database
db = SQL("sqlite:///finance.db")

@app.route("/")
@login_required
def index():

    p_rows = db.execute("SELECT symbol, name, SUM(shares) as shares, price, SUM(total) as total FROM purchase WHERE userID = :userID GROUP BY symbol", userID=session["user_id"] )

    # select user's total bought shares
    totals = db.execute("SELECT SUM(total) as total FROM purchase WHERE userID = :userID", userID=session["user_id"])
    tot_bought = (totals[0]["total"])

    # select cash from "users" table
    cash = db.execute("SELECT cash FROM users WHERE id = :id", id=session["user_id"])
    user_cash = (cash[0]["cash"])
    user_cash = float(user_cash)

    # handle empty portfolio case
    if tot_bought == None:
        net = user_cash
        grand_total = user_cash
    else:
        net = user_cash - float(tot_bought)
        grand_total = tot_bought + net

    return render_template("index.html", purchases=p_rows, user_cash=user_cash, net=net, grand_total=grand_total)




@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    """Buy shares of stock."""

    # if route was reached via POST
    if request.method=="POST":

        # ensure symbol was submitted
        if not request.form.get("symbol"):
            return apology("Symbol not valid")
        else:
            quote = lookup(request.form.get("symbol"))
            symbol = request.form.get("symbol")
            name = quote["name"]
            price = quote["price"]

        # ensure sumbitted n° of share was positive
        if not request.form.get("shares"):
            return apology ("invalid share number")
        else:
            #insert shares into db
            shares = request.form.get("shares")

        userID = session["user_id"]

        total = price * float(shares)

        cash = db.execute("SELECT cash FROM users WHERE id = :id", id=session["user_id"])
        user_cash = cash[0]["cash"]

        if user_cash < total:
            return apology("you are poor :/")

        db.execute("INSERT INTO purchase(userID, symbol, name, shares, price, total) VALUES(:userID, :symbol, :name, :shares, :price, :total)", userID=userID, symbol=symbol, name=name, shares=shares, price=price, total=total)
        flash("Bought!")
        return redirect(url_for("index"))


    # if route was reached via GET
    else:
        if not request.args.get("symbol"):
            val=""
        else:
            val = 'value=' + request.args.get("symbol")

        return render_template("buy.html", val=val)



@app.route("/history")
@login_required
def history():
    """Show history of transactions."""

    history = db.execute("SELECT symbol, shares, price, datetime FROM purchase WHERE userID = :userID", userID = session["user_id"])

    return render_template("history.html", history=history)








@app.route("/login", methods=["GET", "POST"])
def login():
    """Log user in."""

    # forget any user_id
    session.clear()

    # if user reached route via POST (as by submitting a form via POST)
    if request.method == "POST":

        # ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username")

        # ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password")

        # query database for username
        rows = db.execute("SELECT * FROM users WHERE username = :username", username=request.form.get("username"))

        # ensure username exists and password is correct
        if len(rows) != 1 or not pwd_context.verify(request.form.get("password"), rows[0]["hash"]):
            return apology("invalid username and/or password")

        # remember which user has logged in
        session["user_id"] = rows[0]["id"]

        # redirect user to home page
        return redirect(url_for("index"))

    # else if user reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("login.html")

@app.route("/logout")
def logout():
    """Log user out."""

    # forget any user_id
    session.clear()

    # redirect user to login form
    return redirect(url_for("login"))

@app.route("/quote", methods=["GET", "POST"])
@login_required
def quote():
    """Get stock quote."""

    # if route was reached via POST (as by submitting a quote form via POST)
    if request.method =="POST":

        # look for stock symbol, price and store it
        quote = lookup( request.form.get("symbol") )

        # if symbol is invald return apology
        if not quote:
            return apology("Invalid symbol")

        #assign lookup return values to "quoted.html" template values
        name = quote["name"]
        symbol = request.form.get("symbol")
        price = quote["price"]

        # render template containing lookup returned values
        return render_template("quoted.html", name=name, symbol=symbol, price=price )

    # if route was reached via GET (as by clicking "Quote" link on navbar)
    else:
        return render_template("quote.html")

@app.route("/register", methods=["GET", "POST"])
def register():
    """Register user."""

    # forget any user's id
    session.clear()

    #
    if request.method == "POST":

        # ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username")

        # ensure password was submitted
        elif not request.form.get("password") or not request.form.get("password_again"):
            return apology("must provide password")

        # ensure passwords match
        elif request.form.get("password") != request.form.get("password_again"):
            return apology("passwords do not match")

        username = request.form.get("username")
        hash = pwd_context.hash(request.form.get("password"))

        #query db for username
        rows = db.execute("SELECT * FROM users WHERE username = :username", username=username)

        #if username in database, inform user
        if rows:
            return apology("username already exists")

        db.execute("INSERT INTO users (username, hash) VALUES (:username, :hash)", username=username, hash=hash)

        return redirect(url_for("index"))

    #if route was reached by GET (as by clicking a URL)
    else:
        return render_template("register.html")



@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    """Sell shares of stock."""

    if request.method == "POST":

        # handle stock not owned
        symbol_to_sell = request.form.get("symbol")
        symbol_owned = db.execute("SELECT symbol FROM purchase WHERE userID = :userID AND symbol = :symbol", userID = session["user_id"], symbol = symbol_to_sell)
        if not symbol_owned:
            return apology("symbol not owned")

        # handle shares to sell < shares owned
        shares_to_sell = request.form.get("shares")
        shares_row = db.execute("SELECT SUM(shares) as shares_owned FROM purchase WHERE userID = :userID and symbol = :symbol", userID = session["user_id"], symbol = symbol_to_sell)
        shares_owned = shares_row[0]["shares_owned"]
        if float(shares_to_sell) > float(shares_owned):
            return apology("too many shares")

        # insert sold shares in table
        userID=session["user_id"]
        sell = lookup(symbol_to_sell)
        symbol = symbol_to_sell
        name = (sell["name"])
        shares = -1*float(shares_to_sell)
        price = sell["price"]
        total = (price * shares)

        #insert sell in table
        db.execute("INSERT INTO purchase(userID, symbol, name, shares, price, total) VALUES(:userID, :symbol, :name, :shares, :price, :total)", userID=userID, symbol=symbol, name=name, shares=shares, price=price, total=total)

        # redirect to index
        flash("Sold!")
        return redirect(url_for("index"))


    else:

        if not request.args.get("symbol"):
            val=""
        else:
            val='value=' + request.args.get("symbol")

        return render_template("sell.html", val=val)

