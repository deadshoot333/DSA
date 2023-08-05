#include<bits/stdc++.h>
using namespace std;

class Node{
private:
    int val;
    Node *next;

public:
    Node(){
        next = NULL;
    }
    void setValue(int n)
    {
        val=n;
    }
    int getValue(){
        return val;
    }
    void setNext(Node *nxt)
    {
        next=nxt;
    }
    Node *getNext()
    {
        return next;
    }
};

class Stack{
private:
    Node *head;
    int SIZE;
public:
    Stack(){
        head = NULL;
        SIZE = 0;
    }

    void push(int n){
        ///Stack functionality: Inserts n in the stack
        ///Linked list functionality: Creates a node and inserts at the head of the list
        Node *newitem;
        newitem=new Node;
        newitem->setValue(n);
        if(head==NULL)
        {
            head=newitem;
        }
        else
        {
            newitem->setNext(head);
            head=newitem;
        }
            SIZE++;
    }

    bool isEmpty(){
        ///Stack functionality: Returns true if the stack is empty, otherwise returns false
        if(head==NULL)
        {
            return true;
        }
        return false;
    }

    int top(){
        ///Stack functionality: Returns the last inserted value/top value of the stack (doesn't remove from stack)
        ///Linked list functionality: Returns the value located at head
        ///If the user calls this function for an empty stack, it will generate runtime error
        return head->getValue();
    }

    void pop(){
        ///Stack functionality: Removes the top value of the stack
        ///Linked list functionality: if the list is not empty then removes the node under head and declares new head
        ///If the user calls this function for an empty stack, it will generate runtime error
        if(isEmpty())
        {
            cout<<"Stack is empty\n";
        }
        else
        {
        Node *temp;
        temp=head;
        head=head->getNext();
        delete temp;
        }
    }

    int size(){
        ///Returns the size of stack
        return SIZE;
    }

    void displaystack(){
        ///Prints the stack
        if(isEmpty())
        {
            cout<<"Stack is empty"<<endl;
        }
        else
        {
        Node *temp;
        temp=head;
        while(temp!=NULL)
        {
            cout<<temp->getValue()<<" ";
            temp=temp->getNext();
        }
        }
    }
    void reverse()
    {
        Node *curr=head,*next=NULL,*prev=NULL;
        while(curr!=NULL)
        {
            next=curr->getNext();
            curr->setNext(prev);
            prev=curr;
            curr=next;
        }
        head=prev;
    }
    void removeDuplicates()
    {
        Node *curr=head, *index, *dup;
        while (curr->getNext()!= NULL) {
            index = curr;
    
            while (index->getNext()!= NULL) {
                /* If duplicate then delete it */
                if (curr->getValue() == index->getNext()->getValue()) {
                    /* sequence of steps is important here */
                    dup = index->getNext();
                    index->setNext(index->getNext()->getNext());
                    free(dup);
                }
                else /* This is tricky */
                    index = index->getNext();
            }   
            curr = curr->getNext();
        }
}
};


int main(){
    int choice;
    Stack s;
    while(choice!=0)
    {
        cout<<"0 - Exit."<<endl;
        cout<<"1 - Push Item."<<endl;
        cout<<"2 - Pop Item."<<endl;
        cout<<"3 - View Top Item."<<endl;
        cout<<"4 - Size of Stack."<<endl;
        cout<<"5 - Display Items (Print STACK)."<<endl;
        cout<<"6 - Reverse Array."<<endl;
        cout<<"7 - Delete Same element"<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;

        switch(choice){
            case 0:
            {

            }
                break;

            case 1:
            {
                int value;
                cout<<"Enter the value: ";
                cin>>value;
                s.push(value);
            }           
                break;

            case 2:
                ///Must check whether the stack is empty or not before popping
                s.pop();
                break;

            case 3:
                ///Must check whether the stack is empty or not before viewing top item
                {
                    int x;
                    x=s.top();
                    cout<<"Top item is = "<<x<<endl;
                }
                break;

            case 4:
            {
                int x=s.size();
                cout<<"Size of the stack is = "<<x<<endl;
            }
                break;

            case 5:
            {
                s.displaystack();
                
            }
                break;
            case 6:
            {
                s.reverse();
                s.displaystack();
            }
            break;
            case 7:
            {
                s.removeDuplicates();
                s.displaystack();
            }
            break;
            default:
                cout<<"An Invalid choice."<<endl;
        }

        cout<<endl<<endl;
    }


    return 0;
}
