#include <iostream>
using namespace std;
void clearscreen()
{
    system("cls");
}
struct Node {
    int data;
    Node *next;
};
class Stack{
    private :
        Node *top;
    public :
       Node gettopNode()
        {
            return *top;
        }
        Stack()
        {
            this->top = NULL;
        }

        bool push(int);
        bool pop();
        bool peek();
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
                top = temp;
                while(temp != NULL){
                    // Just for Printing Starting Block
                    if(top == temp){
                        cout<<"\n Start -> ";
                    }
                    cout<< temp->data << " -> "; // Printing Data

                    if(temp->next == NULL){
                        cout<<"NULL";
                    }
                    
                    temp = temp->next;
                }

                return true;
            }
}
void stack()
{
    int choices; bool status;
    Stack obj;
    start : 
        cout<<" --------------- You Selected Stack Menu ----------------------\n";
        cout<<"[ 1 ] - Push Data to Stack                             [ Press 1 ]\n";
        cout<<"[ 2 ] - Pop from Stack                             [ Press 2 ]\n";
        cout<<"[ 3 ] - Peek Data from Stack                             [ Press 3 ]\n";
        cout<<"[ 4 ] - Goto Main Menu                                   [ Press 4 ]\n";
        cin>>choices;
        switch(choices)
        {
            case 1 : int num;
                        cout<<"\n Enter Number to be Pushed - ";
                        cin>>num;
                        status = obj.push(num);
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
                            cout<<"Error While Deleting";
                        }
                        goto start;
            case 3 : if(obj.peek()){
                
                         } goto start;
            case 4 : break;
            default : cout<<"Wrong Key Entered";
                            goto start;
            }
        
}
int main()
{   int choices = 0;

    start : 

    cout<<" ---------------- Welcome to Stack Implementation Window -------------------- \n";
    cout<<" [ 1 ] - Stack                                                               [ Press 1 ]\n";
    cout<<" [ 3 ] - Exit                                                                [ Press 3 ]\n";
    cin>>choices;
    switch(choices)
    {
        case 1 : system("cls");
                        stack();
                    goto start;
        // case 2 : system("cls");
        //                 queue();
        //             goto start;
        case 3 : exit(1);
        default : 
            cout<<"\n Error 1x2 - Invalid Code Entered [ Go Back and Try Another Option ] :( \n";
            goto start;
    }
}
