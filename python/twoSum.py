
def twoSum(numbers, target):
	allpairs = []
	seen = {}
	for i, number in enumerate(numbers):
		res = target - number
		if res not in seen.keys():
			seen[number] = i+1
		else:
			allpairs.append((seen[res], i+1))
	return allpairs


def main():
	print twoSum([1,2,3,7,8], 9)

if __name__ == '__main__':
	main()