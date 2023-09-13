#include<bits/stdc++.h>
using namespace std;
class Node
{
    public:
    int Eow;
    Node *children[60];
    Node()
    {
        Eow=0;
        for(int i=0;i<60;i++)
        {
            this->children[i]=NULL;
        }
    }
    ~Node()
    {

    }
};
class TRIE
{
    public:
    TRIE()
    {

    }
    void insert(Node *root,string s)
    {
        Node *u=root;
        for(int i=0;i<s.size();i++)
        {
            int k=s[i]-65;
            if(u->children[k]==NULL)
            {
                u->children[k]=new Node();
            }
            u=u->children[k];
        }
        u->Eow+=1;
        //cout<<u->Eow<<"\n";
    }
    bool isLeaf(Node *u)
    {
        for(int i=0;i<60;i++)
        {
            if(u->children[i]!=NULL)
            {
                return false;
            }
        }
        return true;
    }
    bool isJunction(Node *u)
    {
        int count=0;
        for(int i=0;i<60;i++)
        {
            if(u->children[i]!=NULL)
            {
                count++;
            }
        }
        if(u->Eow==0||count>1)
        {
            return true;
        }
        return false;
    }
    void removeEdge(Node *u,char c,int d)
    {
        if(d==0)
        {
            return;
        }
        int r=(int)c-'A';
        Node *v=u->children[r];
        u->children[r]=NULL;
        delete v;
    }
    int deleteStr(Node *u,string s,int k=0)
    {
        if(u==NULL)
        {
            return 0;
        }
        if(k==s.size())
        {
            if(u->Eow==0)
            {
                return 0;
            }
            if(!isLeaf(u))
            {
                u->Eow=0;
                return 0;
            }
            return 1;
        }
        int r=(int)s[k]-'A';
        int d=deleteStr(u->children[r],s,k+1);
        bool j=isJunction(u);
        removeEdge(u,s[k],d);
        if(j)
        {
            d=0;
        }
        return d;
    }
    void printLex(Node *curr,string s="")
    {
        if(curr->Eow>0)
        {
            cout<<s<<"\n";
        }
        for(int i=0;i<60;i++)
        {
            if(curr->children[i]!=NULL)
            {
                char c=(char)(i+65);
                printLex(curr->children[i],s+c);
            }
        }
    }
    void printReverseLex(Node *u,string s="")
    {
        if(u->Eow>0)
        {
            cout<<s<<"\n";
        }
        for(int i=59;i>=0;i--)
        {
            if(u->children[i]!=NULL)
            {
                char c=(char)i+'A';
                printReverseLex(u->children[i],s+c);
            }
        }
    }
    void printClones(Node *u,string s="")
    {
        if(u->Eow>=2)
        {
            cout<<s<<"\n";
        }
        for(int i=0;i<60;i++)
        {
            if(u->children[i]!=NULL)
            {
                char c=(char)i+'A';
                printClones(u->children[i],s+c);
            }
        }

    }
    void printSameBegin(Node *u,string s="")
    {
        if(u->Eow>0)
        {
            cout<<s<<"\n";
        }
        for(int i=0;i<60;i++)
        {
            if(u->children[i]!=NULL)
            {
                char c=(char)i+'A';
                printSameBegin(u->children[i],s+c);
            }
        }
    }
    ~TRIE()
    {
        
    }
};
int main()
{
    Node *root=new Node();//root is blank which means it acts as 0th index
    TRIE t;
    while(1)
    {
        cout<<"1.INSERT\t2.DELETE\t3.PRINT\t4.REVERSE_PRINT\t5.CLONES_PRINT\t6.Print_Same_Chracter_Begining\t0.EXIT";
        int c;
        cout<<"\nEnter choice = ";
        cin>>c;
        switch (c)
        {
        case 1:
        {   
            string s;
            cin>>s;
            t.insert(root,s); 
            break;
        }
        case 2:
        {
            string s;
            cout<<"Enter the string to be deleted = ";
            cin>>s;
            t.deleteStr(root,s);
            break;
        }
        case 3:
        {
            t.printLex(root);
            break;
        }
        case 4:
        {
            t.printReverseLex(root);
            break;
        }
        case 5:
        {
            t.printClones(root);
            break;
        }
        case 6:
        {
            cout<<"Enter the character = ";
            char c;
            cin>>c;
            int i=(char)c-65;
            root=root->children[i];
            string s=string(1,c);
            t.printSameBegin(root,s);
            break;
        }
        case 0:
        {
            exit(0);
        }
        }
    }

}