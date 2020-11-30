#include "leetCode.h"

/*******************************************************
数字0-9分别使用火柴棍数目为{6, 2, 5, 5, 4, 5, 6, 3, 7, 6}
火柴总数为num（num<24），可以拼出多少个形如a+b=c的等式？
*******************************************************/
void leetCode::matchStick_equation()
{
	cout << "input total number of matchstick(num<=24):" << endl;
	int num;
	cin >> num;
	int a, b, c;
	int count = 0;
	for(a = 0; a <= 1111; a++)
	{
		for(b = 0; b <= 1111; b++)
		{
			c = a + b;
			if(matchStick_equation_help(a) + matchStick_equation_help(b) + matchStick_equation_help(c) == num - 4)
			{
				cout << a << " + " << b << " = " << c << endl;
				count++;
			}
		}
	}
	cout << "There are " << count << " equations." << endl;
}

int leetCode::matchStick_equation_help(int num)
{
	int n = 0;
	int f[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

	if(0 == num)
		return 6;

	while(0 != num)
	{
		n += f[num % 10];
		num /= 10;
	}
	return n;
}

/*******************************************************
191
输入一个整形数，输出其二进制表示形式中有多少个1
*******************************************************/
int leetCode::numberOf1Bit(int n)
{
	int count = 0;
	while(n)
	{
		n = n & (n-1);
		count++;
	}
	cout << "number of 1 bits:" << count << endl;
	return count;
}

/*******************************************************
771. Jewels and Stones
S中有多少个字母是J中的？
*******************************************************/
int leetCode::numJewelsInStones(string J, string S)
{
	int count = 0;
	sort(J.begin(), J.end());
	sort(S.begin(), S.end());
	cout << J << "	" << S << endl;
	int j = 0;
	int i = 0;
	while(i < J.size() && j < S.size())
	{
		if(J[i] < S[j])
			i++;
		else if(J[i] == S[j])
		{
			count++;
			j++;
		}
		else
			j++;
	}
	return count;
}

/*******************************************************
929. Unique Email Addresses

*******************************************************/
int leetCode::numUniqueEmails(vector<string>& emails)
{}

/*******************************************************
199. Binary Tree Right Side View
*******************************************************/
vector<int> leetCode::rightSideView(TreeNode* root) 
{
    vector<int> rightside;
    vector<vector<int>> result;
    levelOrderTraverse(root, 1, result);
    
    for(int i = 0; i < result.size(); i++)
        rightside.push_back(result[i][result[i].size()-1]);
    
    return rightside;
}

void leetCode::levelOrderTraverse(TreeNode *root, size_t level, vector<vector<int>> &result) 
{
    if (!root) return;
    if (level > result.size())
        result.push_back(vector<int>());
    result[level-1].push_back(root->val);
    levelOrderTraverse(root->left, level+1, result);
    levelOrderTraverse(root->right, level+1, result);
}