/******************************************************************************
* Author:           Syed Tamal
* Created:          26 May 2023  20:09:01 
******************************************************************************/
#include <bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);
#define int long long

struct node{
    int isbn;
    string title , author;
    float price;
    int quantity;

    node *parent, *left, *right;
};

node *root;

void init(){
    root = NULL;
}

void insertNode(node val){
    node *newitem = new node();
    newitem->isbn = val.isbn;
    newitem->title = val.title;
    newitem->author = val.author;
    newitem->price = val.price;
    newitem->quantity = val.quantity;
    newitem->parent = NULL;
    newitem->left = NULL;
    newitem->right = NULL;

    root = newitem;
}

void insertOther(node val){
    node *newitem = new node();
    newitem->isbn = val.isbn;
    newitem->title = val.title;
    newitem->author = val.author;
    newitem->price = val.price;
    newitem->quantity = val.quantity;
    newitem->parent = NULL;
    newitem->left = NULL;
    newitem->right = NULL;

    node *temp = root;
    node *prev = NULL;
    while(temp != NULL){
        prev = temp;
        if(temp->isbn < val.isbn) temp = temp->right;
        else temp = temp->left;
    }
    newitem->parent = prev;
    if(prev->isbn < val.isbn) prev->right = newitem;
    else prev->left = newitem;
}

void insert(node val){
    if(root == NULL) insertNode(val);
    else insertOther(val);
}

node *searchNode(int isbn){
    node *temp = root;
    while(temp != NULL){
        if(temp->isbn == isbn) return temp;
        if(temp->isbn < isbn) temp = temp->right;
        else temp = temp->left;
    }
    return temp;
}

void dlt0(node *n){
    if(n==root) root = NULL;
    else delete n;
}

void dlt1(node *n){
    node *temp = n->parent;
    node *child;
    if(n->left == NULL) child = n->right;
    else child = n->left;
    if(temp == NULL){
        root = child;
        return;
    }
    if(temp->left == n) temp->left = child;
    else temp->right = child;
    child->parent = temp;
    delete n;
}

void dlt2(node *n){
    node *temp = n->right;
    node *prev = n;
    while(temp != NULL){
        prev = temp;
        temp = temp->left;
    }
    n->isbn = prev->isbn;
    n->title = prev->title;
    n->author = prev->author;
    n->price = prev->price;
    n->quantity = prev->quantity;

    if(prev->left == NULL && prev->right == NULL) dlt0(prev);
    else dlt1(prev);
}

void dlt(node *n){
    node *temp = searchNode(n->isbn);
    if(temp == NULL){
        cout<<"The item is not found. \n";
        return ;
    }
    else{
        if(n->left == NULL && n->right == NULL) dlt0(n);
        else if(n->left == NULL || n->right == NULL) dlt1(n);
        else dlt2(n);
        cout<<"\nBook removed from the inventory successfully.\n";
    }
}

void printNode(node *n){
    cout<<"ISBN: "<<n->isbn<<"\n";
    cout<<"Title: "<<n->title<<"\n";
    cout<<"Author: "<<n->author<<"\n";
    cout<<"Price: $"<<n->price<<"\n";
    cout<<"Quantity: "<<n->quantity<<"\n";
    cout<<"\n";
}

void inorderTraverse(node *n){
    if(n==NULL) return;
    inorderTraverse(n->left); 
    printNode(n);
    inorderTraverse(n->right);
}

void changeQuan(int isbn, int quan){
    node *x = searchNode(isbn);
    x->quantity = quan;
}

void levelorderTraverse(node *start){
    queue<node *>qu;
    qu.push(start);
    while(!qu.empty()){
        node *temp = qu.front();
        printNode(temp);
        qu.pop();
        if(temp->left != NULL) qu.push(temp->left);
        if(temp->right != NULL) qu.push(temp->right);
    }
}

int32_t main(){
    cout<<"Welcome to the Bookstore Inventory Management System!\n\n";
    while(true){
        cout<<"1. Add a book to the inventory\n2. Remove a book from the inventory\n3. Update the quantity of a book\n4. Search for a book by ISBN\n5. Display all books in the inventory\n7. Exit\n";
        cout<<"\n";

        int ch;
        cout<<"Enter your choice: ";
        cin>>ch;
        cout<<"\n";

        switch(ch){
            case 1:
                {
                    node val;
                    cout<<"Enter the book's ISBN: ";
                    cin>>val.isbn;
                    cout<<"Enter the book's title: ";
                    getchar();
                    getline(cin, val.title); 
                    cout<<"Enter the book's author: ";
                    getline(cin, val.author);
                    cout<<"Enter the book's price: ";
                    cin>>val.price;
                    cout<<"Enter the book's quantity: ";
                    cin>>val.quantity;

                    insert(val);
                    cout<<"\nBook added to the inventory successfully.\n\n";
                    break;
                }

            case 2:
                {
                    cout<<"Enter the ISBN of the book to remove: ";
                    int isb;
                    cin>>isb;
                    node *book = searchNode(isb);
                    if(book != NULL) dlt(book);
                    break;
                }
                
            case 3:
                {
                    cout<<"Enter the ISBN of the book to update: ";
                    int isb;
                    cin>>isb;
                    cout<<"Enter the quantity of the book: ";
                    int quan;
                    cin>>quan;
                    changeQuan(isb, quan);
                    cout<<"\nQuantity of the books updated successfully\n\n";
                    break;
                }

            case 4:
                {
                    cout<<"Enter the ISBN of the book to search: ";
                    int isbn;
                    cin>>isbn;
                    node *book = searchNode(isbn);
                    printNode(book);        
                    break;
                }

            case 5:
                {
                    // inorderTraverse(root);
                    levelorderTraverse(root);
                    break;
                }

            case 7:
                return 0;
        }
    }
    return 0;
}
