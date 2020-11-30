#ifndef TREE_H
#define TREE_H

#include <iostream>
#include <vector>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Tree
{
public:
	TreeNode *root;

	Tree();
	void constructTreeWithAllNodes(vector<int>& nodes);

	~Tree();
};

#endif