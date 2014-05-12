
import sys
def stringToInteger(string):

	#remove whitespaces before the number and after the number
	string = string.strip()
	
	#take care of the empty string
	if len(string) == 0:
		return 0

	
	sign = 1
	number = 0
	"""ignore all the characters following the integers numbers """
	for i, char in enumerate(string):
		if i == 0 and string[i] == '-':
			sign  = -1
			continue
		if i == 0 and string[i]== '+':
			continue
		if ord(char) >= 48 and ord(char) <= 57:
			number = number * 10 + (ord(char) - 48)
		else:
			break;
	"""check if the number is bigger than max int 
	or less than min int"""
	print sys.maxint

	 #take care of the 
	result = number * sign
	if result > sys.maxint: 
		return sys.maxint
	elif result < (-sys.maxint - 1): 
		return (-sys.maxint -1)
	else: return result

def main():
	string = raw_input("Get a string number:")
	print "number: %d " %stringToInteger(str(string))

if __name__ == '__main__':
	main()