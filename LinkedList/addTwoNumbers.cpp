#include<bits/stdc++.h>
#include"SLL.h"
using namespace std;
SLL addTwoNumbers(SLL *l,SLL *l1)
{    //https://leetcode.com/problems/add-two-numbers/description/
    node *temp1=l->get_head();
    node *temp2=l1->get_head();
    int carry=0;
    SLL ans;
    while(temp1!=NULL || temp2!=NULL)
    {                                      
        if(temp1!=NULL && temp2!=NULL)
        {
            ans.insert_last((temp1->data+temp2->data+carry)%10);
            carry=(temp1->data+temp2->data)/10;
            temp1=temp1->next;
            temp2=temp2->next;
        }
        else if(temp1!=NULL && temp2==NULL)
        {
            // if(temp1->data+carry<10)
            // {
            //     ans.insert_last(temp1->data+0+carry);
            // }
            // else
            // {
                ans.insert_last((temp1->data+0+carry)%10);
                carry=(temp1->data+0+carry)/10;
            // }
            temp1=temp1->next;
        }
        else
        {
            // if(0+temp2->data+carry<10)
            // {
            //     ans.insert_last(0+temp2->data+carry);
            // }
            // else
            // {
                ans.insert_last((0+temp2->data+carry)%10);
                carry=(0+temp2->data+carry)/10;
            // }
            temp2=temp2->next;
        }
    }
    if(temp1==NULL && temp2==NULL && carry!=0)
    {
        ans.insert_last(carry);
    }
    return ans;

}
int main()
{
    SLL l;
    l.insert_last(9);
    l.insert_last(9);
    l.insert_last(9);
    l.insert_last(9);
    l.insert_last(9);
    l.insert_last(9);
    l.insert_last(9);
    SLL l1;
    l1.insert_last(9);
    l1.insert_last(9);
    l1.insert_last(9);
    l1.insert_last(9);
    SLL ans=addTwoNumbers(&l,&l1);
    node *temp=ans.get_head();
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<"\n";
    return 0;
}