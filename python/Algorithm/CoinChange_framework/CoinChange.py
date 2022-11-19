#DO NOT CHANGE ANY EXISTING CODE IN THIS FILE
import numpy as np
class CoinChange:

	def NumberofCoins(self,denomination,value):
		 #Write your code here to find out minimum number of coins required to provide the change for given value.
		 #This method will have a denomination array and an int which specifies the value as inputs(Please see testcase file)
		 #This method should return the number of coins
		A = np.zeros(value + 1)
		for i in range(1, len(A)):
			n_min = i
			for j in range(len(denomination)):
				if i >= denomination[j]:
					n = A[i - denomination[j]] + 1
					n_min = min(n_min, n)
			A[i] = n_min
		return A[-1]
