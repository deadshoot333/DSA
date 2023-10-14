#include<bits/stdc++.h>
using namespace std;
class Node
{
    public:
    int Eow;
    Node *children[10];
    Node()
    {
        this->Eow=0;
        for(int i=0;i<10;i++)
        {
            this->children[i]=NULL;
        }
    }
    ~Node()
    {

    }
};
class Trie
{
    public:
    int count=0;
    void insert(string s,Node *curr)
    {
        for(int i=0;i<s.size();i++)
        {
            int pos=s[i]-'0';
            if(curr->children[pos]==NULL)
            {
                curr->children[pos]=new Node();
            }
            curr=curr->children[pos];
        }
        curr->Eow++;
    }
    bool isLeaf(Node *curr)
    {
        for(int i=0;i<10;i++)
        {
            if(curr->children[i]!=NULL)
            {
                return false;
            }
        }
        return true;
    }
    int prefix(Node *curr)
    {
        if(curr->Eow>0 && !isLeaf(curr))
        {
            count++;//Non-leaf node ar Eow>1 holei count korbe jodi count>0 tahole "NO"
        }
        for(int i=0;i<10;i++)
        {
            if(curr->children[i]!=NULL)
            {
                prefix(curr->children[i]);
            }
        }
        return count;
    }
    ~Trie()
    {

    }
};
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        Trie tr;
        Node *root=new Node();
        int n;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            string s;
            cin>>s;
            tr.insert(s,root);
        }
        if(tr.prefix(root)!=0)
        {
            cout<<"NO\n";
        }
        else
        {
            cout<<"YES\n";
        }
    }
}
