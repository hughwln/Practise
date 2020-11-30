def main():
	l = [1,2,3,4,5,6,7]
	ls = splitIntoGroupsOf(4, l)
	print(ls)

def splitIntoGroupsOf(groupSize, theList):
	#splits a list into a list of lists
	result = []
	for i in range(0, len(theList), groupSize):
		result.append(theList[i:i + groupSize])
	return result

if __name__ == '__main__':
	main()