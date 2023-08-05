#include<bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    node *next;
};
class SLL
{
    node *head;
    node *tail;
    int sz;
    public:
    SLL()
    {
        head=NULL;
        tail=NULL;
        sz=0;
    }
    void insert_first(int value)
    {
        node *newitem;
        newitem=new node;
        newitem->data=value;
        newitem->next=NULL;
        if(head==NULL)
        {
            head=newitem;
            tail=head;
        }
        else
        {
            newitem->next=head;
            head=newitem;
        }
        sz++;
    }
    void insert(int value,int pos)
    {
        if(pos==0)
        {
            insert_first(value);
        }
        else if(pos==sz-1)
        {
            insert_last(value);
        }
        else
        {
            int i=0;
            node *temp=head;
            node *prev=NULL;
            while(i<pos)
            {
                prev=temp;
                temp=temp->next;
                i++;
            }
            node *newitem;
            newitem=new node;
            newitem->data=value;
            newitem->next=temp;
            prev->next=newitem;
        }
        sz++;
    }
    void insert_last(int value)
    {
        node *newitem;
        newitem=new node;
        newitem->data=value;
        newitem->next=NULL;
        if(head==NULL)
        {
            head=newitem;
            tail=head;
        }
        else
        {
            tail->next=newitem;
            tail=newitem;
        }
        sz++;
    }
    int size()
    {
        return sz;
    }
    void display()
    {
        node *temp=head;
        while(temp!=NULL)
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<"\n";
    }
    void delete_first()
    {
        if(head==NULL)
        {
            return ;
        }
        node *temp=head;
        head=head->next;
        delete temp;
        sz--;
    }
    void delete_at(int pos)
    {
        if(pos<0 ||pos >sz)
        {
            cout<<"Invalid Position\n";
            return;
        }
        else
        {
            int index=0;
            node *temp=head;
            while(index!=pos-1)
            {
                temp=temp->next;
                index++;
            }
            node *nxt=temp->next;
            temp->next=nxt->next;
            delete nxt;
            sz--;
        }
    }
    void insert_after_value(int target,int value)
    {
        node *temp=head;
        while(temp!=NULL)
        {
            if(temp->data==target)
            {
                break;
            }
            temp=temp->next;
        }
        if(temp==NULL)
        {
            cout<<"Invalid Data\n";
            return;
        }
        else
        {
            node *newitem=new node;
            newitem->data=value;
            newitem->next=NULL;
            node *nxt=temp->next;
            newitem->next=nxt;
            temp->next=newitem;
            sz++;
        }
    }
        node *get_head()
        {
            return head;
        }
        void display_reverse(node *temp)
        {
            if(temp==NULL)
            {
                return;
            }
            display_reverse(temp->next);
            cout<<temp->data<<" ";
        }
        void reverse_list()
        {
            node *curr=head;
            node *prev=NULL;
            node *next=NULL;
            while(curr!=NULL)
            {
                next=curr->next;
                curr->next=prev;
                prev=curr;
                curr=next;
            }
            head=prev;
        }
        bool DetectLoop()
        {
            node *slow=head;
            node *fast=head;
            while (slow!=NULL && fast->next!=NULL && slow->next!=NULL)
            {
                slow=slow->next;
                fast=fast->next->next;
                if(slow==fast)
                {
                    return true;
                }
            }
            return false;
            
        }
        void loop(int k)
        {
            int i=0;
            node *curr=head;
            while(i!=k-1)
            {
                curr=curr->next;
                i++;
            }
            tail->next=curr;
        }
    ~SLL()
    {
        cout<<"\n\tProgramme end\n";
    }
};
