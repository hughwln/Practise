#ifndef LEETCODE_H
#define LEETCODE_H

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "tree.h"

using namespace std;

class leetCode
{
private:
	int matchStick_equation_help(int num);
	void levelOrderTraverse(TreeNode *root, size_t level, vector<vector<int>> &result);

public:
	void matchStick_equation();

	/*easy*/
	int numberOf1Bit(int n);
	int numJewelsInStones(string J, string S);
	int numUniqueEmails(vector<string>& emails);

	/*medium*/
	vector<int> rightSideView(TreeNode* root);

	/*hard*/

};

#endif