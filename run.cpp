#include <iostream>
using namespace std;
void clearscreen()
{
    system("cls");
    // Used ClearScreen because when Moving through Different Compiler of Turbo C++ it is really messy to edit each line getch() , clrscr() with system("cls")

}
struct Node {
    int data; // Each Node have Integer type Data in it
    Node *next; // This Memory Node Contains Address of Next Node
};
class Stack{
    private :
        Node *top; // This Top Pointer Node at the top of Stack
        /* Through this we can find all the nodes */
    public :
       Node* gettopNode()
        {
            return top; // As Top Pointer is Private member, getters are used here
        }
        Stack() // Constructor
        {
            this->top = NULL; // Initially Stack's top Points NULL
        }

        bool push(int); // To insert Data
        bool pop();
        bool peek(); // To see Stack 
        int gettotalnodes(); // Returns Total number of nodes in Stack
        void deleteall();
        /* Delete all is intentionally used, when leaving Stack Menu all Stack must be emptied before leaving Stack menu
            So that tp avoid Orphand Memory Blocks in Memory */
};
bool Stack::push(int data)
{
     Node *temp = new Node;
            
            if(top == NULL){
                 temp->data = data;
                temp->next = NULL;
                top = temp;
                return true;

            }else{
                 temp->data = data;
                temp->next = top;
                top = temp;
                return true;
            }

            return false; 
            /* Ok I Understand Code Will Never reach here, but still I added this line, I also don't know */
}
bool Stack::pop(){
    Node *temp = new Node;
            if(top == NULL){
                return false;
            }else{
                temp = top;
                top = top->next;
                delete temp;
                return true;
            }
}
bool Stack::peek(){
     Node *temp = new Node;
            if(top == NULL)
            {   // Stack is Already Empty
                return false;
            }else{
                temp = top;
                while(temp != NULL){
                    // Just for Printing Starting Block
                    if(top == temp){
                        cout<<"\n Start -> ";
                    }

                    cout<< temp->data << " -> "; // Printing Data

                    // Used to Print Null BLock At Last of Stack
                    if(temp->next == NULL){
                        cout<<"NULL";
                    }
                    
                    temp = temp->next; // Changes temp to next node address
                }

                return true;
            }
}
int Stack::gettotalnodes()
{
    if(top == NULL){
        return 0;
    }else{
        int count = 0;
        Node *temp = new Node;
        temp = top;
        while(temp != NULL)
        {
            count++;
            temp = temp->next;
        }

        return count;
    }
}
void Stack::deleteall(){
                        Node *temp = new Node;
                        Node *temp1 = new Node;
                        
                        temp = top;
                        temp1 = top;
                        while(temp1 != NULL){
                        	 if(temp1 != top){
                                 Node *temp = new Node;
                                 temp = temp1;
                             }
                             cout<<"\n"<<temp->data<<" - was Deleted\n";
                             delete temp;
                             
                             
                            temp1 = temp1->next;
						}
                            
                           
                        
}
class Queue{
    private : 
        Node *head,*tail;
    public :
        Queue()
        {
            head = tail = NULL;
        }
        bool insert(int);
        bool qdelete();
        bool see();
        bool qdeleteall();
};
bool Queue::insert(int data){
    Node *temp = new Node;
    temp->data = data;
    if(head == NULL && tail == NULL){
        temp->next = NULL;
        head = temp;
        tail = temp;

        return true;
    }else{
    	temp->next = NULL;
        tail->next = temp;
        tail = temp;

        return true;
    }

}
bool Queue::qdelete() {
    if(head == NULL && tail == NULL){
        return false;
    }else{
    	if(tail->next == NULL){
    		
        Node *temp = new Node;
        temp = head;
        head = head->next;
        tail = tail->next;
        delete temp;

        return true;
		}else{
			
        Node *temp = new Node;
        temp = head;
        head = head->next;
        delete temp;

        return true;
		}
    }
}
bool Queue::see(){
    if(head == NULL && tail == NULL){
        cout<<"\nQueue Already Empty\n";
        return true;
    }else{
        Node *temp = new Node;
        temp = head;
        while(temp != NULL){
            if(temp == head){
                cout<<"\nHEAD -> ";
            }
            cout<< temp->data <<" -> ";
            if(temp == tail){
                cout<<" NULL ( TAIL )";
            }
            temp = temp->next;
        }
        return true;
    }
}
bool Queue::qdeleteall(){
    if(head == NULL && tail == NULL){
        cout<<"\nQueue Already Empty\n";
        return false;
    }else{
        Node *temp = new Node;
        temp = head;
        while(temp != NULL){
            cout<<"\nDATA DELETED - "<<temp->data;
            delete temp;
            temp = temp->next;
        }
    }
}
void stack()
{
    int choices; bool status;
    Stack obj;
    start : 
        cout<<"\n --------------- You Selected Stack Menu ----------------------\n";
        cout<<"\n[ 1 ] - Push Data to Stack                               [ Press 1 ]\n";
        cout<<"\n[ 2 ] - Pop from Stack                            		  [ Press 2 ]\n";
        cout<<"\n[ 3 ] - Peek Data from Stack                             [ Press 3 ]\n";
        cout<<"\n[ 4 ] - Goto Main Menu                                   [ Press 4 ]\n";
        cin>>choices;
        switch(choices)
        {
            case 1 : int num;
                        cout<<"\n Enter Number to be Pushed - ";
                        cin>>num;
                        status = obj.push(num);
                        clearscreen();
                        if(status == true)
                        {   cout<<num<<" was Pushed Successfully.\n You can check it now using Peek Menu";
                            
                            goto start;
                        }else{
                            cout<<"\nUnable to Push Data";
                            goto start;
                        }
            case 2 : status = obj.pop();
                        if(status == true){
                            cout<<"Deleted";
                        }else{
                            cout<<"Stack is Already Empty";
                        }
                        goto start;
            case 3 : if(obj.peek()){
                
                         } goto start;
            case 4 :     obj.deleteall();
                         break;
                         
            default : cout<<"Wrong Key Entered";
                            goto start;
            }
        
}
void queue()
{
    int choices; bool status;
    Queue obj;
    start : 
        cout<<"\n --------------- You Selected Queue Menu ----------------------\n";
        cout<<"\n[ 1 ] - Insert Data                                      [ Press 1 ]\n";
        cout<<"\n[ 2 ] - Delete from Stack                            	  [ Press 2 ]\n";
        cout<<"\n[ 3 ] - See Data from Stack                              [ Press 3 ]\n";
        cout<<"\n[ 4 ] - Goto Main Menu                                   [ Press 4 ]\n";
        cin>>choices;
        switch(choices)
        {
            case 1 : int num;
                        cout<<"\n Enter Number to be Pushed - ";
                        cin>>num;
                        status = obj.insert(num);
                        clearscreen();
                        if(status == true)
                        {   cout<<num<<" was Pushed Successfully.\n You can check it now using Peek Menu";
                            
                            goto start;
                        }else{
                            cout<<"\nUnable to Push Data";
                            goto start;
                        }
            case 2 : status = obj.qdelete();
                        if(status == true){
                            cout<<"Deleted";
                        }else{
                            cout<<"Stack is Already Empty";
                        }
                        goto start;
            case 3 : if(obj.see()){
                
                         } goto start;
            case 4 :     obj.qdeleteall();
                         break;
                         
            default : cout<<"Wrong Key Entered";
                            goto start;
            }
        
}
int main()
{   int choices = 0;

    start : 
	
    cout<<"\n ---------------- Welcome to Stack And Queue Implementation Window -------------------- \n";
    cout<<"\n [ 1 ] - Stack --------------------------------------------------------------> [ Press 1 ]\n";
    cout<<"\n [ 2 ] - Queue --------------------------------------------------------------> [ Press 2 ]\n";
    cout<<"\n [ 3 ] - Exit  --------------------------------------------------------------> [ Press 3 ]\n";
    cout<<"\nPlease Enter Your Choice :- ";
    cin>>choices;
    switch(choices)
    {
        case 1 : 	clearscreen();
                        stack();
                    goto start;
        case 2 : clearscreen();
                        queue();
                    goto start;
        case 3 : exit(1);
        default : 
            cout<<"\n Error 1x2 - Invalid Code Entered [ Go Back and Try Another Option ] :( \n";
            goto start;
    }
}
