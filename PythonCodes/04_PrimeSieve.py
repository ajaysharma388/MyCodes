def isPrime(num):
	to = sqrt(num)
	for i in range(2, to):
		if num % i == 0:
			return False
	return True

def getPrimes(n):
	primeList = []
	primeList.append(2)
	for num in range(3, n+1, 2):
		if isPrime(i):
			primeList.append(i)
	return primeList


num = int(input())
primes = getPrimes(num)
# printing prime numbers.
for num in primes:
	print(num, end="")
