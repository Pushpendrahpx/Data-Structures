#include <iostream>
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

        insertStart(int);
        see();
};
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
}
int main()
{
    CLL obj;
    obj.insertStart(9);
    obj.see();
    obj.insertStart(4);
    obj.see();
    obj.insertStart(2);
    obj.see();
    obj.insertStart(6);
    obj.see();    
}