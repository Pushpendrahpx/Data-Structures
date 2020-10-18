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
        CLL(int data){
            Node* temp = new Node;
            temp->data = data;
            temp->next =head;
        }
        Node* createNewNode(int);
        void insertStart(int);
        void see();
};

/*
I created below function in hope of creating a node from start
but because of OOP constraint was not able to figure out 
how to connect with Class to initialize
I thought working with constructor help
but still it was giving segmentation fault
do look into it

*/
Node* CLL::createNewNode(int num){
    Node* temp = new Node;
    temp->data = num;
    temp->next = head;
    return temp;
}

void CLL::insertStart(int num){
    Node *temp = new Node;
    temp->data = num;
    if(head == NULL){
        temp->next = NULL;
        head = temp;
    }else{
        Node *traversal = new Node;
        traversal = head;
        while(traversal){
            if(traversal->next == NULL){
                traversal->next = temp;
                temp->next = head;
                return;
            }else 
            traversal = traversal->next;
        }
    }
}
void CLL::see(){
    if(head == NULL){
        cout<<"\nCLL is Already Empty";
    }
    else{
        Node* temp = head->next;
        while(temp!=head){
            cout<<temp->data;
            temp = temp->next;
        }
    }
}
int main()
{
    CLL obj(3);
    obj.insertStart(9);
    obj.see();
    obj.insertStart(4);
    obj.see();
    obj.insertStart(2);
    obj.see();
    obj.insertStart(6);
    obj.see();    
}