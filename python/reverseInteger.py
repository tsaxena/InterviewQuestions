""" Corner cases:
- How to handle the numbers that end with a 0
- How to handle overflow
"""
class Overflow(Exception):
	def __init__(self, value):
		self.value = value
	def __str__(self):
		return repr(self.value)


def reverseInteger(number):
	reverseNumber = 0;
	sign = 1
	if number < 0:
		number = abs(number)
		sign = -1

	while number > 0:
		reverseNumber = reverseNumber * 10 + number % 10
		number /= 10
	print reverseNumber *sign
	"""try: 
		raise Overflow(1)
	except Overflow as e:
		print "Overflow", e.value"""


def main():
	number = raw_input("Get a number:")
	print "test 1 %r" %reverseInteger(int(number))

if __name__ == '__main__':
	main()