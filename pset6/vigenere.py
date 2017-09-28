import cs50
import sys

k = sys.argv[1]

while True:

    if len(sys.argv) != 2:
            print("Error 1: missing, redundant or non-alphabetical command-line argument. Please retry.\n")
    else:
        if str.isalpha(k):
            break
        else:
            print("Error 1: missing, redundant or non-alphabetical command-line argument. Please retry.\n")

#prompt user for plaintext
print("plaintext: ", end="")
p = cs50.get_string()

#prompt for ciphertext
print("ciphertext: ", end="")

j = 0

#for each letter in plaintext
for c in p:
    #if letter is alphabetic
    if c.isalpha():
        #if letter is upper case
        if c.isupper():
            jmod = j % len(k) #calculate mod of j
            k_j = k[jmod].upper()   #jth char in k to upper case
            k_j = ord(k_j)-65       #convert it to alphabetic index
            c = ord(c)-65           #convert plaintext letter to alphabetic index
            c_i = ( c + k_j ) % 26  #calculate vigenère formula
            rc = c_i + 65           #revert char to ascii
            print("{}".format(chr(rc)), end="")
            j = j + 1
        #if letter is lower case
        else:
            jmod = j % len(k)
            k_j = k[jmod].lower()   #jth char in k to lower case
            k_j = ord(k_j) - 97
            c = ord(c) - 97
            c_i = ( c + k_j ) % 26
            rc = c_i + 97
            print("{}".format(chr(rc)), end="")
            j = j + 1
    #if character is not alphabetic
    else:
        print(c, end="")

print()