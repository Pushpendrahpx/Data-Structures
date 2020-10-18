#include <iostream>

using namespace std;

struct Node{
    int data;
    Node *next;
};
class CLL{
    private:
        Node *head;
    public:
        CLL(){
            this->head = NULL;
        }
        // Node* createNewNode(int);
        void insert(int);
        void see();
        void freeAllMemory();
};

/*
I created below function in hope of creating a node from start
but because of OOP constraint was not able to figure out 
how to connect with Class to initialize
I thought working with constructor help
but still it was giving segmentation fault
do look into it
------------------------------- My Reviews ---------------------------
Our Insert Function will take care of Creating Node, as 'new' keyword is used, this replaces the need of creating createNode function
*/
// Node* CLL::createNewNode(int num){
//     Node* temp = new Node;
//     temp->data = num;
//     temp->next = head;
//     return temp;
// }

void CLL::insert(int num){
    Node *temp = new Node;
    temp->data = num;
    if(head == NULL){
        head = temp;
        temp->next = head;
        
    }else{
        Node *traversal = new Node;
        traversal = head;
        while(traversal->next != head){
            traversal = traversal->next;
        }
        traversal->next = temp;
        temp->next = head;
    }
}
void CLL::see(){
    if(head == NULL){
        cout<<"\nCLL is Already Empty";
    }else{
        cout<<"Linked List Data \t [head] => ";
        Node *temp = head;
        do{
            cout<<temp->data<<" => ";
            temp = temp->next;
        }while(temp != head);
        cout<<"[head]"<<endl;
    }
}
void CLL::freeAllMemory(){
    if(head==NULL){
        cout<<"\n Linked List is Empty \n";
    }else{
        Node *temp = head;
        while(temp){
            // Here we are not updating Head Pointer Because We will be deleting All The Nodes
            cout<<"\n Deleting Node with Value = "<<temp->data;
            Node *temp2 = temp;
            temp = temp->next;
            free(temp2);
            if(temp == head){
                break;
            }
        }

    }
    cout<<"\n Deleted All Memory \n";
}
int main()
{
    CLL obj;
    obj.insert(9); 
    obj.insert(4); 
    obj.insert(2); 
    obj.insert(6); 
    obj.see();
    obj.freeAllMemory();
}