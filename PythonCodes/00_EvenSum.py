
def main():
    # Your code goes here
    # code to add the even numbers.
    num = int(input())
    sum = 0
    for i in range (0, num+1, 2):
        sum += i
    print(f"Sum of Even Numbers in Range from 1 to {num} inclusive is {sum}")

if __name__ == "__main__":
    main()
