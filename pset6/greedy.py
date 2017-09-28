import cs50

coins = 0

#ask user for owed change
while True:
    print("O hai! How much change is owed? ")
    owed = cs50.get_float()
    if owed > 0:
        break
    else:
        print("Positive number please: ")
        owed = cs50.get_float

#ease change calculation
cents = round(owed * 100)

#calculate minumum amount of coins to give back
while True:
    if cents >= 25:
        cents -= 25
        coins += 1
    elif cents >= 10:
        cents -= 10
        coins += 1
    elif cents >= 5:
        cents -= 5
        coins += 1
    elif cents >= 1:
        cents -= 1
        coins += 1
    elif cents == 0:
        break

print("minumum n° coins is {}".format(coins))

