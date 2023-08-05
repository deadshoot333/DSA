#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *next;
};
class Qll
{
    Node *front;
    Node *rear;
    public:
    Qll()
    {
        front=NULL;
        rear=NULL;
    }
    void enqueu(int val)
    {
        Node *newitem;
        newitem=new Node;
        newitem->data=val;
        newitem->next=NULL;
        if(front==NULL && rear==NULL)
        {
            front=newitem;
            rear=newitem;
        }
        else
        {
            rear->next=newitem;
            rear=newitem;
        }
    }
    void dequeu()
    {
            Node *temp;
            temp=front;
            front=front->next;
            delete temp;
    }
    void display()
    {
        Node *temp=front;
        while(temp->next!=NULL)
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<temp->data<<endl;
    }
};
int main()
{
    Qll q;
    q.enqueu(5);
    q.enqueu(4);
    q.enqueu(3);
    q.enqueu(2);
    q.enqueu(1);
    q.display();
    q.dequeu();
    q.display();
}