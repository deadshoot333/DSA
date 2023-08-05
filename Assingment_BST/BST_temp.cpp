#include<bits/stdc++.h>
using namespace std;

struct Node{
    int key,level;
    Node *left, *right, *parent;
};

Node *root;

void init(){
    root = NULL;
}

void insertRoot(int val){

    root=new Node;
    root->key=val;
    root->left=NULL  ;
    root->right=NULL;
    root->parent=NULL;

}

void insertOther(int val){

    Node *temp=root;
    Node *prev=NULL;///prev pointer is used to keep trac of previos poiter of temp
    while(temp!=NULL)
    {
        prev=temp;
        if(val<temp->key)
        {
            temp=temp->left;
        }
        else
        {
            temp=temp->right;
        }

    } ///while loop finish

    temp=new Node;
    temp->key=val;
    temp->left=NULL;
    temp->right=NULL;
    temp->parent=prev;

    if(val<prev->key)
    {
        prev->left=temp;
    }
    else{
        prev->right=temp;
    }



}

void insert(int val){
    if(root==NULL)
    {
        insertRoot(val);
    }
    else{
        insertOther(val);
    }
}

Node* findNode(int val){
    Node *temp=root;
    while(temp!=NULL)
    {
        if(temp->key==val)
        {
            return temp;
        }
        else if(val<temp->key)
        {
            temp=temp->left;
        }
        else
        {
            temp=temp->right;
        }
    }
    return temp;

}

Node* findMaximum(Node *node){
    Node *temp=node;
    while(temp->right!=NULL)
    {
        temp=temp->right;
    }
    return temp;

}

Node* findMinimum(Node *node){
    Node *temp=node;
    while(temp->left!=NULL)
    {
        temp=temp->left;
    }
    return temp;
}


Node* findSuccessor(Node *node){ // immediate large node of the deleted node
    Node *temp=node->right;
    while(temp->left!=NULL)
    {
       temp=temp->left;
    }
    return temp;
}

void delete0Child(Node *node){ //deletes the whole node
    Node *par=node->parent;
    if((node->key)<(par->key))
    {
        par->left=NULL;
    }
    else
    {
        par->right=NULL;
    }
    free(node);
}
void delete1Child(Node *node){  //deletes the node having 1 child
    Node *par,*child;
    par=node->parent;
    ///we will grab the child of deleting node
    if(node->left==NULL)
    {
        child=node->right;  
    }
    else{
        child=node->left;
    }
    ///deleting node will be on left
    if((node->key)<(par->key))
    {
        par->left=child;
        child->parent=par;
    }
    ///deleting node is on right
    else
    {
        par->right=child;
        child->parent=par;
    }
}

void delete2Child(Node *node){ //deletes the node having 2 child
    Node *f=findSuccessor(node);
    node->key=f->key;///so successor will set
    if(f->left==NULL && f->right==NULL)
    {
        delete0Child(f);
    }
    else
    {
        delete1Child(f);
    }
}

bool deleteNode(int val)
{
    Node *t=findNode(val);
    if(t==NULL)
    {
        return false;
    }
    else
    {
        if(t->left==NULL && t->right==NULL)
        {
            delete0Child(t);
        }

        else if(t->left==NULL || t->right==NULL)
        {
            delete1Child(t);
        }
        else
        {
            delete2Child(t);
        }
        return true;
    }
}
void displayLeft()
{
    Node *temp=root;
    cout<<"Source is "<<temp->key<<endl;
    
    cout<<"Left Nodes are= ";
    while(temp!=NULL)
    {
        cout<<temp->key<<" ";
        temp=temp->left;
    }
}
void displayRight()
{
    Node *temp=root;
    cout<<"Source is "<<temp->key<<endl;
    temp=temp->right;
    cout<<"Right Nodes are= ";
    while(temp!=NULL)
    {
        cout<<temp->key<<" ";
        temp=temp->right;
    }
}


int main(){
    init();


    while(1){
        cout<<"1. Insert\n2. Search\n3. Delete\n4. Display Left Child\n";
        int x;
        cin>>x;

        if(x==1){
            cout<<"Insert Value: ";
            int y;
            cin>>y;
            insert(y);
        }

        else if(x==2){
            cout<<"Enter the value you want to search ";
            int s;
            cin>>s;
            Node* t=findNode(s);
            if(t==NULL)
                cout<<"Not found"<<endl;
            else
                cout<<"Found"<<endl;
        }

        else if(x==3){
            cout<<"Delete Value: ";
            int y;
            cin>>y;
            bool b = deleteNode(y);
            if(b)   cout<<"Deleted"<<endl;
            else    cout<<y<<" not found"<<endl;
        }
        else if(x==4)
        {
            displayLeft();
            cout<<endl;
            displayRight();
        }

    }
}

/*
1
44

1
17

1
88

1
32

1
65

1
97

1
28

1
54

1
82

1
29

1
76

1
80
*/




















