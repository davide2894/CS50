import cs50

#prompt user for pyramid height
while True:
    print("height is ", end="")
    height = cs50.get_int()

    #make sure height has range of 0-23
    if height > 0 or height < 23:
        break
    else:
        print("Retry: ", end="")
        height = cs50.get_int()


#print pyramid according to user's input
for i in range(1, height+1):
    for row in range(height-i):
        print(" ", end="")
    for row in range(i):
        print("#", end="")
    print("  ", end="")
    for row in range(i):
        print("#",end="")
    print("")


