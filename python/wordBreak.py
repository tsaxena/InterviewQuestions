
def wordBreak(s, dict):
	""" if the string is empty """
	if len(s) == 0:
		return False

	"""initialize the memoization table"""
	strlen = len(s)
	table = [[False for i in range(strlen)] for j in range(strlen)]
	for i in range(strlen):
		for j in range(i, strlen):
			if s[i:j+1] in dict:
				table[i][j] = True

	for i in range(strlen):
		for j in range(i, strlen):
			for k in range(i, j):
				if table[i][j]==False:
					table[i][j] = table[i][k] and table[k+1][j]

	return table[0][strlen-1]



def main():
	dict = set(["mobile","samsung","sam","sung","man","mango", "icecream","and","go","i","like","ice","cream"])
	print wordBreak("ilikesamsung", dict)	
	print wordBreak("iiiiiiiii", dict)	
	
if __name__ == '__main__':
	main()