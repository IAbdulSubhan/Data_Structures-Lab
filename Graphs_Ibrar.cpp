#include<iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
};

struct List{
    Node *node = new Node;
    List *down;
};

class Graph{
public :
    List* list_head;
    Graph();
    List* new_vertex(int);
    Node* new_edge(int);
    void insertion();
    void print(List*);
};

Graph::Graph(){
    this->list_head = NULL;
}

List* Graph::new_vertex(int val){
    List* newVertex = new List;
    newVertex->node->data = val;
    newVertex->node->next = NULL;
    newVertex->down = NULL;
    return newVertex;
}

Node* Graph::new_edge(int val){
    Node* newEdge = new Node;
    newEdge->data = val;
    newEdge->next = NULL;
    return newEdge;
}

void Graph::insertion(){
    int choice,val;
    List* temp;
    cout<<"press (1) for new vertex insertion : "<<endl;
    cout<<"press (2) for new edge insertion : "<<endl;
    cout<<"Enter your chocie (1,2) : ";
    cin>>choice;
    if(choice == 1){
        cout<<"Enter value for new vertex : ";
        cin>>val;
        if(list_head == NULL){
            temp = new_vertex(val);
            list_head = temp;
            return;
        }else{
            temp = list_head;
            while(temp->down != NULL){
                temp = temp->down;
            }

            List* last = temp;
            temp->down = new_vertex(val);
            last->down = temp->down;
            return;
        }
    }else if(choice == 2){
        int edgeVertex;
        bool found = false;
        cout<<"Enter vertex value : ";
        cin>>val;
        cout<<"Enter edgevertex value: ";
        cin>>edgeVertex;

        if(list_head == NULL){
            cout<<"No vertex is present in graph"<<endl;
            return;
        }else{
            temp = list_head;
            while(temp->down != NULL){
                if(temp->node->data == val){
                    found = true;
                    break;
                }
            }

            if(found == false){
                cout<<"No such vertex is present in graph"<<endl;
                return;
            }else{
                List* thisVertex = temp;
                if(thisVertex->node->next == NULL){
                    thisVertex->node->next = new_edge(edgeVertex);
                    return;
                }else{
                    Node* iter = thisVertex->node->next;
                    while(iter->next != NULL){
                        iter = iter->next;
                    }

                    Node* last = iter;
                    iter->next = new_edge(edgeVertex);
                    last->next = iter->next;
                    return;
                }
            }
        }
    }else{
        cout<<"Choose the correct option"<<endl;
        return;
    }
}

void Graph::print(List* temp){
    if(list_head == NULL){
        cout<<"Graph is empty!!!"<<endl;
        return;
    }

    while(temp != NULL){
        cout<<temp->node->data<<" -> ";
        Node* iter = temp->node->next; 
        if(iter == NULL){
            continue;
        }else{
            while(iter != NULL){
                cout<<temp->node->data<<" -> ";
                iter= iter->next;
            }
        }
        cout<<endl;
        temp = temp->down;
    }
}

int main(){
    Graph graph;
    int choice;
    char ans;

    do{
        cout<<"press (1) insertion()"<<endl;
        cout<<"press (2) print()"<<endl;
        cout<<"Enter your chocie(1,2) : ";
        cin>>choice;
        switch(choice){
            case 1:
                graph.insertion();
                break;

            case 2:
                graph.print(graph.list_head);
                break;
            
            default:
                cout<<"Choose the correct option"<<endl; 
        }

        cout<<"Do you want to continue(y,n)? ";
        cin>>ans;
    }while(ans != 'n');

    return 0;
}