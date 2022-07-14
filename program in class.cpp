#include<iostream>
using namespace std;

struct node{
    int info;
    node *left,*right;

};

class trees_1{

    public:
        node *root,*temp;

        trees_1(){
            root = NULL;
             temp = NULL;

        }

        void insert(node *&temp,int key){
            if (temp == NULL){
                temp = new node;
                temp -> info = key;
                temp -> right = temp -> left = NULL;
                return;

            }

           if (key == temp -> info){
                cout<<"\nDuplicate found;\n";
                return;
            }

            if (key < temp->info){
                insert(temp->left, key);
                return;
                }

            if (key > temp->info){
                insert(temp->right, key);
                return;
            }

        }

        node* search(node *temp , int n){
        	if(temp == NULL){
        		return 0;
			}
        	if(temp -> info == n){
        		return temp;
			}
			if(temp -> info < n){
				return search(temp -> right ,n);

			}
			if(temp -> info > n){
				return search(temp -> left ,n);
			}
		}

        void inOrder(node *temp){
                
                if (temp == NULL){
                    cout<<"\nTree is Empty.\n";
                    return;
                }
                if (temp->left != NULL)
                    inOrder(temp->left);

                cout<<" "<<temp->info;

                if(temp->right != NULL)
                    inOrder(temp->right);
}

	void preOrder(node *temp){
		
				if (temp == NULL){
                    cout<<"\nTree is Empty.\n";
                    return;
                }
                cout<<" "<<temp->info;
                
                if (temp->left != NULL)
                    preOrder(temp->left);


                if(temp->right != NULL)
                    preOrder(temp->right);
		
		
	}
	
	void postOrder(node *temp){
		
		if (temp == NULL){
			cout<<"\nTree is Empty.\n";
		}
		if(temp->left != NULL)
			postOrder(temp->left);
			
		if(temp->right != NULL)
			postOrder(temp->right);
			
		 cout<<" "<<temp->info;		
	}

    int min(node* temp){
        node *min_value = temp;
        while(min_value->left != NULL)
            min_value = min_value->left;
        return min_value->info;


    }
    int max(node *temp){
        node *max_value = temp;
        while(max_value->right != NULL)
            max_value = max_value->right;
        return max_value->info;


    }

    void successor(node *p){
        node* t;
        if(p->right != NULL){
            t = p->right;
            cout<<endl;
            cout<<"Successior of "<<p->info<<" is: "<<min(t)<<endl;
        }

        if(p->right == NULL){
            node* s = root;
            node *store;
            while(s->info != p->info){
            if(s->info >= p->info){
                    store = s;
                    s=s->left;
            }
            else
                s = s->right;

        }
            cout<<endl;
            cout<<"Successior of "<<p->info<<" is: "<<store->info;
            cout<<endl;


}

    }



};


int main(){
    trees_1 t1;
    t1.insert(t1.root,100);
    t1.insert(t1.root,80);
    t1.insert(t1.root,110);
    t1.insert(t1.root,50);
    t1.insert(t1.root,90);
    t1.insert(t1.root,85);
    t1.insert(t1.root,105);
    t1.insert(t1.root,200);
	cout<<"Pre order Traversal;\n";
    t1.preOrder(t1.root);
    cout<<endl;
    cout<<"In order Traversal;\n";
    t1.inOrder(t1.root);
    cout<<endl;
    cout<<"Post order Traversal;\n";
    t1.inOrder(t1.root);
    cout<<endl;
    node *p;
    cout<<t1.search(t1.root,80);
    p=t1.search(t1.root,80);
    cout<<endl;
    cout<<"Minimum of Tree: "<<t1.min(t1.root);
    cout<<endl;
    cout<<"Maximum of Tree: "<<t1.max(t1.root);
    cout<<endl;
    t1.successor(p);
    return 0;
}
