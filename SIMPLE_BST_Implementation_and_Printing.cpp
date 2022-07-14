#include<iostream>
class TreeNode{
public:
	TreeNode *left, *right;
	int val;
	TreeNode(int val);	
};
TreeNode::TreeNode(int val)
{
	this->val = val;
	left = right = NULL;
}
class BST{
	TreeNode *root;
public:
	BST();
	void insert(int val, TreeNode* &t);
	TreeNode* get_root();
	void Pre_order(TreeNode* &t);	
	void Inorder(TreeNode* &t);
	void Post_order(TreeNode* &t);
	
};
BST::BST()
{
	root = NULL;
}
TreeNode* BST::get_root()
{
	return root;
}
void BST::insert(int val, TreeNode* &r)
{
	if(root == NULL)
	{
		root = new TreeNode(val);
		r = root;
		return;
	}
	if(val < r->val)
	{
		if(r->left == NULL)
			r->left = new TreeNode(val);
		else
			insert(val, r->left);
	}
	else
	{
		if(r->right == NULL)
			r->right  = new TreeNode(val);
		else
			insert(val, r->right);
	}
	
}
void BST::Pre_order(TreeNode* &t)
{
	std::cout << t->val << std::endl;
	if(t->left != NULL)
	Pre_order(t->left);

	if(t->right != NULL)
		Pre_order(t->right);
	
	
}
void BST::Inorder(TreeNode *&t)
{
	
	if(t->left != NULL)
	Inorder(t->left);

std::cout << t->val << std::endl;
	
	if(t->right != NULL)
		Inorder(t->right);
	
}

void BST::Post_order(TreeNode *&t)
{
	
	if(t->left != NULL)
	Post_order(t->left);

	
	if(t->right != NULL)
		Post_order(t->right);
	
	std::cout << t->val << std::endl;

}
int main()
{
	BST t;
//	t.insert(5);
//	t.insert(1);
//	t.insert(20);
//	t.insert(10);
//	t.insert(50);
//	t.insert(30);
//	t.insert(40);
//	t.insert(60);
	TreeNode *r = t.get_root();
	t.insert(23,r);
	t.insert(12,r);
	t.insert(31,r);
	t.insert(3,r);
	t.insert(15,r);
	t.insert(29,r);
	t.insert(88,r);
	t.insert(7,r);
	t.insert(53,r);
	r = t.get_root();
	std::cout << "____________________pre order ______________ " << std::endl;
	t.Pre_order(r);
	std::cout << " ________________In Order_______________ " << std::endl;
	r = t.get_root();	
	t.Inorder(r);
	std::cout << "________________Post _order ____________________________ " << std::endl;
	r= t.get_root();
	t.Post_order(r);
}