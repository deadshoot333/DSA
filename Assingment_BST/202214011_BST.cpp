#include<bits/stdc++.h>
#define long long int;
#define endl "\n";
using namespace std;
class Book
{
    public:
    string isbn;
    string title;
    string author;
    double price;
    int quantity;
    void input()
    {
        cout<<"Enter the book's ISBN: ";
        cin>>isbn;
        // cout<<"Enter the book's title: ";
        // cin>>title;
        // cout<<"Enter the book's author: ";
        // cin>>author;
        // cout<<"Enter the book's price: ";
        // cin>>price;
        // cout<<"Enter the book's quantity: ";
        // cin>>quantity;                           
    }
    void display()
    {
        cout<<"ISBN: "<<isbn<<endl;
        // cout<<"Title: "<<title<<endl;
        // cout<<"Author: "<<author<<endl;
        // cout<<"Price:$"<<price<<endl;
        // cout<<"Quantity:"<<quantity<<"\n"<<endl;
    }
};
class Node
{
    public:
    Book book;
    Node *left;
    Node *right;
    Node *parent;
};
Node *root=NULL;
void insertRoot(Book book)
{
    root=new Node;
    root->book=book;
    root->left=NULL;
    root->right=NULL;
    root->parent=NULL;
}
void insertOther(Book book)
{
    Node *temp=root,*prev=NULL;
    while(temp!=NULL)
    {
        prev=temp;
        if(book.isbn<temp->book.isbn)
        {
            temp=temp->left;
        }
        else
        {
            temp=temp->right;
        }
    }
    temp=new Node;
    temp->book=book;
    temp->left=NULL;
    temp->right=NULL;
    temp->parent=prev;
    if(book.isbn < prev->book.isbn)
    {
        prev->left=temp;
    }
    else
    {
        prev->right=temp;
    }
}
void insert(Book book)
{
    if(root==NULL)
    {
        insertRoot(book);
    }
    else
    {
        insertOther(book);
    }
}
Node *findNode(string val)
{
    Node *temp=root;
    while(temp!=NULL)
    {
        if(temp->book.isbn==val)
        {
            return temp;
        }
        else if(temp->book.isbn>val)
        {
            temp=temp->left;
        }
        else
        {
            temp=temp->right;
        }
    }
}
Node *findSuxeor(Node *node)
{
    Node *temp=node->right;
    while(temp!=NULL)
    {
        temp=temp->left;
    }
    return temp;
}
void delete0child(Node *node)
{
    Node *par=node->parent;
    if(node==root)
    {
        root=NULL;
    }
    if(node->book.isbn<par->book.isbn)
    {
        par->left=NULL;
    }
    else
    {
        par->right=NULL;
    }
    free(node);
}
void delete1child(Node *node)
{
    Node *temp = node->parent;
    Node *child;
    if(node->left == NULL)
    {
    
        child = node->right;
    }   
    else
    {
        child = node->left;
    }    
    if(temp == NULL)
    {
        root = child;
        return;
    }
    if(temp->left == node) 
    {
        temp->left = child;
    }
    else 
    {
        temp->right = child;
    }
    child->parent = temp;
    free(node);
}
void delete2child(Node *node)
{
    Node *sux=findSuxeor(node);
    Node *suxParent=sux->parent;
    node->book=sux->book;
    if(node->left==NULL && node->right==NULL)
    {
        delete0child(sux);
    }
    else
    {
        delete1child(sux);
    }
}
bool deleteNode(string val)
{
    Node *node=findNode(val);
    if(node->left==NULL && node->right==NULL)
    {
        delete0child(node);
    }
    else if(node->left==NULL||node->right==NULL)
    {
        delete1child(node);
    }
    else
    {
        delete2child(node);
    }
    return true;
}
void levelOrder()
{
    if(root==NULL)
    {
        cout<<"EMPTY"<<endl;
        return;
    }
    else
    {
        queue<Node *>q;
        q.push(root);
        while(!q.empty())
        {
            Node *temp=q.front();
            q.pop();
            temp->book.display();
            if(temp->left!=NULL)
            {
                q.push(temp->left);
            }
            if(temp->right!=NULL)
            {
                q.push(temp->right);
            }
        }
    }
}
void updateBook(string id,int qnt)
{
    Node *temp=findNode(id);
    temp->book.quantity=qnt;
}
int32_t main()
{
    while(1)
    {
        cout<<"\nWelcome to the Bookstore Inventory Mangement System!"<<endl;
        cout<<"1.Add a book to the inventory\n2.Remove a book from the inventory\n3.Update the quantity of a book\n4.Search for a book by ISBN\n5.Display all books in the inventory\n6.Exit\n";
        int x;
        cout<<"Enter you choice: ";
        cin>>x;
        switch (x)
        {
        case 1:
        {
            Book b;
            b.input();
            insert(b);
            break;
        }
        case 2:
        {
            string rm;
            cout<<"Enter the ISBN of the book to remove: ";
            cin>>rm;
            if(deleteNode(rm))
            {
                cout<<"Book removed from the inventory successfully\n";
            }
            else
            {
                cout<<"Book not found\n";
            }
            break;
        }
        case 3:
        {
            string in;
            int q;
            cout<<"Enter the book ISBN: ";
            cin>>in;
            cout<<"Enter the new quantity: ";
            cin>>q;
            updateBook(in,q);
            break;
        }
        case 4:
        {
            string srch;
            cout<<"Enter the ISBN of the book to search: ";
            cin>>srch;
            Node *tmp=findNode(srch);
            tmp->book.display();
            break;
        }
        case 5:
        {
            levelOrder();
            break;
        }
        case 6:
        {
            break;
        }
        }
    }
}
 
