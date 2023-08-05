
#include<bits/stdc++.h>
using namespace std;
class Book{
    public:
    string ISBN;
    string title;
    string author;
    float price;
    int quantity;
    Book(){
        ISBN="";
        title="";
        author="";
        price=0;
        quantity=0;
    }
    Book(string ISBN,string title,string author,float price,int quantity){
        this->ISBN=ISBN;
        this->title=title;
        this->author=author;
        this->price=price;
        this->quantity=quantity;
    }
    void display(){
        cout<<"ISBN: "<<ISBN<<endl;
        cout<<"Title: "<<title<<endl;
        cout<<"Author: "<<author<<endl;
        cout<<"Price: "<<price<<endl;
        cout<<"Quantity: "<<quantity<<endl;
    }
};
struct Node{
    Book book;
    Node *left, *right, *parent;
};
Node *root;
void init(){
    root = NULL;
}
void insertRoot(Book book){
    root=new Node;
    root->book=book;
    root->left=NULL  ;
    root->right=NULL;
    root->parent=NULL;
}
void insertOther(Book book){
    Node *temp=root;
    Node *prev=NULL;///prev pointer is used to keep trac of previos poiter of temp
    while(temp!=NULL)
    {
        prev=temp;
        if(book.ISBN<temp->book.ISBN)
        {
            temp=temp->left;
        }
        else
        {
            temp=temp->right;
        }
    } ///while loop finish
    temp=new Node;
    temp->book=book;
    temp->left=NULL;
    temp->right=NULL;
    temp->parent=prev;
    if(book.ISBN<prev->book.ISBN)
    {
        prev->left=temp;
    }
    else{
        prev->right=temp;
    }
}
void insert(Book book){
    if(root==NULL){
        insertRoot(book);
    }
    else{
        insertOther(book);
    }
}
void inorder(Node *temp){
    if(temp==NULL){
        return;
    }
    inorder(temp->left);
    temp->book.display();
    inorder(temp->right);
}
void inorder(){
    inorder(root);
}
void preorder(Node *temp){
    if(temp==NULL){
        return;
    }
    temp->book.display();
    preorder(temp->left);
    preorder(temp->right);
}
void preorder(){
    preorder(root);
}
void postorder(Node *temp){
    if(temp==NULL){
        return;
    }
    postorder(temp->left);
    postorder(temp->right);
    temp->book.display();
}
void postorder(){
    postorder(root);
}
Node* search(Node *temp,string ISBN){
    if(temp==NULL){
        return NULL;
    }
    if(temp->book.ISBN==ISBN){
        return temp;
    }
    if(ISBN<temp->book.ISBN){
        return search(temp->left,ISBN);
    }
    else{
        return search(temp->right,ISBN);
    }
}
Node* search(string ISBN){
    return search(root,ISBN);
}
Node* findMin(Node *temp){
    if(temp==NULL){
        return NULL;
    }
    if(temp->left==NULL){
        return temp;
    }
    return findMin(temp->left);
}
Node* findMax(Node *temp){
    if(temp==NULL){
        return NULL;
    }
    if(temp->right==NULL){
        return temp;
    }
    return findMax(temp->right);
}
Node* successor(Node *temp){
    if(temp==NULL){
        return NULL;
    }
    if(temp->right!=NULL){
        return findMin(temp->right);
    }
    Node *parent=temp->parent;
    while(parent!=NULL && temp==parent->right){
        temp=parent;
        parent=parent->parent;
    }
    return parent;
}
Node* predecessor(Node *temp){
    if(temp==NULL){
        return NULL;
    }
    if(temp->left!=NULL){
        return findMax(temp->left);
    }
    Node *parent=temp->parent;
    while(parent!=NULL && temp==parent->left){
        temp=parent;
        parent=parent->parent;
    }
    return parent;
}
void remove(Node *temp,string ISBN){
    if(temp==NULL){
        return;
    }
    if(ISBN<temp->book.ISBN){
        remove(temp->left,ISBN);
    }
    else if(ISBN>temp->book.ISBN){
        remove(temp->right,ISBN);
    }
    else{
        if(temp->left==NULL && temp->right==NULL){
            if(temp==root){
                root=NULL;
            }
            else{
                Node *parent=temp->parent;
                if(parent->left==temp){
                    parent->left=NULL;
                }
                else{
                    parent->right=NULL;
                }
            }
            delete temp;
        }
        else if(temp->left!=NULL && temp->right!=NULL){
            Node *succ=successor(temp);
            temp->book=succ->book;
            remove(succ,succ->book.ISBN);
        }
        else{
            Node *child=(temp->left!=NULL)?temp->left:temp->right;
            if(temp==root){
                root=child;
            }
            else{
                Node *parent=temp->parent;
                if(parent->left==temp){
                    parent->left=child;
                }
                else{
                    parent->right=child;
                }
            }
            delete temp;
        }
    }
}
void remove(string ISBN){
    remove(root,ISBN);
}
void levelOrder(){
    if(root==NULL){
        return;
    }
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node *temp=q.front();
        q.pop();
        temp->book.display();
        if(temp->left!=NULL){
            q.push(temp->left);
        }
        if(temp->right!=NULL){
            q.push(temp->right);
        }
    }
}
int main(){
    init();
    int n;
    cout<<"Enter the number of books: ";
    cin>>n;
    for(int i=0;i<n;i++){
        string ISBN,title,author;
        float price;
        int quantity;
        cout<<"Enter the book's ISBN: ";
        cin>>ISBN;
        cout<<"Enter the book's title: ";
        cin>>title;
        cout<<"Enter the book's author: ";
        cin>>author;
        cout<<"Enter the book's price: ";
        cin>>price;
        cout<<"Enter the book's quantity: ";
        cin>>quantity;
        Book book(ISBN,title,author,price,quantity);
        insert(book);
    }
    cout<<"Inorder traversal: "<<endl;
    inorder();
    cout<<"Preorder traversal: "<<endl;
    preorder();
    cout<<"Postorder traversal: "<<endl;
    postorder();
    string ISBN;
    cout<<"Enter the ISBN of the book you want to search: ";
    cin>>ISBN;
    Node *temp=search(ISBN);
    if(temp==NULL){
        cout<<"Book not found"<<endl;
    }
    else{
        cout<<"Book found"<<endl;
        temp->book.display();
    }
    cout<<"Enter the ISBN of the book you want to delete: ";
    cin>>ISBN;
    remove(ISBN);
    cout<<"Inorder traversal: "<<endl;
    inorder();
    cout<<"Preorder traversal: "<<endl;
    preorder();
    cout<<"Postorder traversal: "<<endl;
    postorder();
    return 0;
}