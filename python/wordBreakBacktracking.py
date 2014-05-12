
def wordBreak(string, dict):
	#solution
	if string in dict:
		return string;
	#candidates
	strlen = len(string)
	for i in range(strlen): 
		prefix = string[0:i]
		suffix = string[i:]
		if prefix in dict:
			segment = wordBreak(suffix, dict)
			if len(segment) != 0 :
				return prefix + " " + segment
	return ""



def main():
	dict = set(["mobile","samsung","sam","sung","man","mango", "icecream","and","go","i","like","ice","cream"])
	print wordBreak("ilikesamsung", dict)	
	print wordBreak("iiiiiiiii", dict)	
	
if __name__ == '__main__':
	main()