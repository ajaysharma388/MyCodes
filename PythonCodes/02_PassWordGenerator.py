
import random

def generatepassword(digits, noLetters, specialChar):
    letters = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z']
    numbers = ['0', '1', '2', '3', '4', '5', '6', '7', '8', '9']
    symbols = ['!', '#', '$', '%', '&', '(', ')', '*', '+']
    passwordData = [letters, numbers, symbols]

    length = digits + noLetters + specialChar
    password = ""
    while len(password) < length:
        tmp = random.randint(0, 2)
        idx = random.randint(0, len(passwordData[tmp])-1)
        if tmp == 0 and noLetters > 0:
            password += passwordData[tmp][idx]
            noLetters -= 1
        elif tmp == 1 and digits > 0:
            password += passwordData[tmp][idx]
            digits -= 1
        elif specialChar > 0:
            password += passwordData[tmp][idx]
            specialChar -= 1
    return password


def main():
    # Your code goes here
    print("Welcome to the PyPassword Generator!")
    print("generating your password")
    password = generatepassword(8, 4, 4)
    print(f"Your Secure password is : {password}")


if __name__ == "__main__":
    main()
