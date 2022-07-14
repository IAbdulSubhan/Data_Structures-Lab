// Recursive CPP program for level
// order traversal of Binary Tree
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data,
pointer to left child
and a pointer to right child */
struct node {
	int data;
	node *left, *right;
};

class Tree
{
	public:
	node *root;
	Tree()
		{
			root = NULL;
		}
	/* Function to print level
	order traversal a tree*/
	void printLevelOrder(node* root)
	{
		int h = height(root);
		int i;
		for (i = 1; i <= h; i++)
			printCurrentLevel(root, i);
	}

	/* Print nodes at a current level */
	void printCurrentLevel(node* root, int level)
	{
		if (root == NULL)
			return;
		if (level == 1)
			cout << root->data << " ";
		else if (level > 1) {
			printCurrentLevel(root->left, level - 1);
			printCurrentLevel(root->right, level - 1);
		}
	}

	/* Compute the "height" of a tree -- the number of
		nodes along the longest path from the root node
		down to the farthest leaf node.*/
	int height(node* node)
	{
		if (node == NULL)
			return 0;
		else {
			/* compute the height of each subtree */
			int lheight = height(node->left);
			int rheight = height(node->right);

			/* use the larger one */
			if (lheight > rheight) {
				return (lheight + 1);
			}
			else {
				return (rheight + 1);
			}
		}
	}

	/* Helper function that allocates
	a new node with the given data and
	NULL left and right pointers. */
	void  insert(node *temp, int number)
	{
		if (temp == NULL){
			temp = new node;
			temp->data = number;
			temp->left = NULL;
			temp->right = NULL;
			root = temp;
			return;
		}
		if (temp->data == number){
			cout<<"Given number is already present in tree\n";
			return;
		}
		if (temp->data > number){
			if (temp->left != NULL){
				insert(temp->left,number);
				return;
			}
			else{
				temp->left = new node;
				temp->left->data = number;
				temp->left->left = NULL;
				temp->left->right = NULL;
				return;
			}
		}
		if (temp->data < number){
			if (temp->right != NULL){
				insert(temp->right,number);
				return;
			}
			else{
				temp->right = new node;
				temp->right->data = number;
				temp->right->left = NULL; 
				temp->right->right = NULL;
				return; 
			}
		}
	}
};

/* Driver code*/
int main()
{
	Tree b;
	b.insert(b.root,5);
	b.insert(b.root,40);
	b.insert(b.root,45);
	b.insert(b.root,2);
	b.insert(b.root,100);
	b.insert(b.root,3);

	cout << "Level Order traversal of binary tree is \n";
	b.printLevelOrder(b.root);
    cout<<endl;

	return 0;
}

// This code is contributed by rathbhupendra
