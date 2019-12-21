#include <iostream>
using namespace std;
struct Node{
    int data;
    Node *next;
};
class SinglyLinkedList{
    private:
        Node *head;
    public:
        SinglyLinkedList(){ // Constructor to set Defaults
            this->head = NULL;
        }
        void insertAtEnd(int);
        void insertAtMid(int,int);
        void insertAtStart(int);

        void peek();
        int get_count();

        void deleteAtEnd();

};
void SinglyLinkedList::insertAtEnd(int num){
    Node *temp = new Node;
    temp->data = num;
    temp->next = NULL;
	
    if(head == NULL){
        temp->next = NULL;
        head = temp;
    }else{
        Node *traversal = new Node;
        traversal = head;
        while(traversal){
            if(!traversal->next){
                traversal->next = temp;
                break;
            }else
            {
                    traversal = traversal->next;
            }
            
        }
    }
}
void SinglyLinkedList::peek(){
    if(head == NULL){
        cout<<"\nEmpty";
    }else{
    	cout<<"[ Pushpendra ]";
        Node *temp = new Node;
        temp = head;
       cout<<"\n"; 
        while(temp){
            cout<<" -> "<<temp->data<<" ->";
            temp = temp->next;
        }
    }
}
void SinglyLinkedList::insertAtStart(int num){
	Node *temp = new Node;
	temp->data = num;
	temp->next = head;
	head = temp;
}

void SinglyLinkedList::insertAtMid(int pos,int num){
	/*  Counting Head with 1 and Continuing...... */
	int count = get_count();
	Node *temp = new Node;
	temp->data = num;
	Node *traversal = new Node;
	
	for(int i = 1;i<=pos; i++){
		if(i == 1){
			traversal = head;
		}
		if(pos == i){
			temp->next = traversal->next;
			traversal->next = temp;
			break;
		}
		
		traversal = traversal->next;
	}
}
int SinglyLinkedList::get_count(){
	int c = 0;
	Node *temp = new Node;
	temp = head;
	while(temp){
		c++;
		temp = temp->next;
	}
	
	return c;
}
void SinglyLinkedList::deleteAtEnd(){
    if(head == NULL){
        cout<<"\n############## Already Empty ##################\n";
    }else{
    Node *temp = new Node;
    temp = head;
    Node *control = new Node;
    	bool c = true;
    	int count = get_count();
    	
        while(c){
            if(count == 1){
            	
				head = NULL;
				cout<<"\t Going to Delete "<<temp->data;
				delete temp;
				c = false;
				
			}else{
				
				if((temp->next)->next == NULL){
                // Confirmed that this Node is to be Deleted
                
    
                temp->next = NULL;
                control = temp->next;
				cout<<"\t Going to Delete "<<temp->data;
                delete control;
    
                
                c = false;
            }else{
            	temp = temp->next;
			}
			}
			
			
        	count--;
            
        }
    }
}
int main()
{
    SinglyLinkedList obj;
    obj.insertAtEnd(1);
    obj.peek();
    obj.insertAtEnd(2);
    obj.peek();
    obj.insertAtEnd(4);
    obj.peek();
    obj.insertAtEnd(5);
    obj.peek();
    
    obj.insertAtMid(2,3);
    obj.peek();

    obj.deleteAtEnd();
    obj.peek();
    obj.deleteAtEnd();
    obj.peek();
    obj.deleteAtEnd();
    obj.peek();
    obj.deleteAtEnd();
    obj.peek();
    obj.deleteAtEnd();
    obj.peek();
    obj.deleteAtEnd();
    obj.peek();
    obj.deleteAtEnd();
    obj.peek();
}
