import math


def isPrime(num):
	to = int(math.sqrt(num))
	for i in range(2, to):
		if num % i == 0:
			return False
	return True

def getPrimes(n):
	primeList = []
	primeList.append(2)
	for num in range(3, n+1, 2):
		if isPrime(num):
			primeList.append(num)
	return primeList


def main():
    # Your code goes here
    num = int(input())
    primes = getPrimes(num)
    # printing prime numbers.
    print(primes)
    print(f"\nprime numbers in range 1 to {num} are : {len(primes)}")


if __name__ == "__main__":
    main()
