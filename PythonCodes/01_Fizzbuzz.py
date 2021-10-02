def main():
    # Your code goes here
    num = int(input())
    for no in range(1, num+1):
        if no % 15 == 0:
            print("FizBuzz")
        elif no % 3 == 0:
            print("Fiz")
        elif no % 5 == 0:
            print("Buzz")
        else:
            print(no)


if __name__ == "__main__":
    main()
