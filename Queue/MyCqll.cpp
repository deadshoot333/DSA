#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *next;
};
class Cqll
{
    Node *front;
    Node *rear;
    public:
    Cqll()
    {
        front=NULL;
        rear=NULL;
    }
    void enqueu(int n)
    {
        Node *newitem;
        newitem=new Node;
        newitem->data=n;
        newitem->next=NULL;
        if(front==NULL && rear==NULL)
        {
            front=rear=newitem;
            rear->next=front;
        }
        else
        {
            rear->next=newitem;
            rear=newitem;
            newitem->next=front;
        }
    }
    void dequeu()
    {
        Node *temp;
        temp=front;
        front=front->next;
        rear->next=front;
        delete temp;
    }
    void display()
    {
        Node *temp=front;
        while(temp->next!=front)
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<temp->data<<" "<<endl;
    }
};
int main()
{
    Cqll c;
    c.enqueu(5);
    c.enqueu(6);
    c.enqueu(7);
    c.enqueu(8);
    c.enqueu(9);
    c.display();
    c.dequeu();
    c.display();
    
}