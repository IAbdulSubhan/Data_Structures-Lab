#include <iostream>
using namespace std;
 
struct node{
    int data;
    struct node* left;
    struct node* right;
};
class BST
{
	public:
		node *root;
		BST()
		{
			root = NULL;
		}
		//--------------------

	void inOrder(struct  node* root){
		if(root!=NULL){
			inOrder(root->left);
			cout<<" "<<root->data;
			inOrder(root->right);
		}
	}

	void  insert(node *temp, int number){
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

	struct node *inOrderPredecessor(struct node* root){
		root = root->left;
		while (root->right!=NULL)
		{
			root = root->right;
		}
		return root;
	}

	struct node *deleteNode(struct node *root, int value){

		struct node* iPre;
		if (root == NULL){
			return NULL;
		}
		if (root->left==NULL&&root->right==NULL){
			delete(root);
			return NULL;
		}

		//searching for the node to be deleted
		if (value < root->data){
			root-> left = deleteNode(root->left,value);
		}
		else if (value > root->data){
			root-> right = deleteNode(root->right,value);
		}
		//deletion strategy when the node is found
		else{
			iPre = inOrderPredecessor(root);
			root->data = iPre->data;
			root->left = deleteNode(root->left, iPre->data);
		}
		return root;
	}
};
 
int main(){
     
    // Constructing the root node - Using Function (Recommended)
    BST b;
	b.insert(b.root,5);
	b.insert(b.root,4);
	b.insert(b.root,3);
	b.insert(b.root,2);
	b.insert(b.root,1);
    // Finally The tree looks like this:
    //      5
    //     / \
    //    3   6
    //   / \
    //  1   4  
 
    // Linking the root node with left and right children
    // p->left = p1;
    // p->right = p2;
    // p1->left = p3;
    // p1->right = p4;

    b.inOrder(b.root);
    cout<<"\nAfter Deletion: ";
    b.deleteNode(b.root, 3);
    b.inOrder(b.root);
	cout<<"\n";

    return 0;
}
