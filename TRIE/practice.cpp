//https://vjudge.net/contest/440824#problem/A
#include<bits/stdc++.h>
using namespace std;
class Node
{
    public:
    int Eow;
    Node *children[26];
    Node()
    {
        this->Eow=0;
        for(int i=0;i<26;i++)
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
    void insert(string s,Node *curr)
    {
        for(int i=0;i<s.size();i++)
        {
            curr->Eow++;//protita chracter er jonno Eow rakhle prefix onujayi used words dekhabe
            int pos=s[i]-'a';
            if(curr->children[pos]==NULL)
            {
                curr->children[pos]=new Node();
            }
            curr=curr->children[pos];
        }
        curr->Eow++;
    }
    int find(string s,Node *curr,int k=0)
    {
        if(curr==NULL)
        {
            return 0;
        }
        if(k==s.size())
        {
            return curr->Eow;
        }
        int pos=s[k]-'a';
        return find(s,curr->children[pos],k+1);
    }
    ~Trie()
    {

    }
};
int main()
{
    Node *root=new Node();
    Trie t;
    string s;
    while(getline(cin,s))
    {
        if(s=="")
        {
            break;
        }
        t.insert(s,root);
    }
    while(cin>>s)
    {
        cout<<t.find(s,root)<<"\n";
    }
}