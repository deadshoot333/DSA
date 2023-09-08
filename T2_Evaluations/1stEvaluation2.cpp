#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
    string name;
    int priority;
    Node()
    {

    }
    Node(string name,int priority)
    {
        this->name=name;
        this->priority=priority;
    }
};
class Heap
{
    Node a[101];
    int size;
    //void Build();
    public:
    Heap()
    {
        //Build();
        size=0;   
    }
    void TopToBottom(int i)
    {
        int left=2*i;
        int right=2*i+1;
        int largest=i;
        if(left<=size && a[largest].priority<a[left].priority)
        {
            largest=left;
        }
        if(right<=size && a[largest].priority<a[right].priority)
        {
            largest=right;
        }
        if(largest!=i)
        {
            swap(a[i],a[largest]);
            TopToBottom(largest);
        }
    }
    void BottomToTop(int i)
    {
        if(i<1)
        {
            return;
        }
        int parentInd=i/2;
        if(a[parentInd].priority>a[i].priority)
        {
            swap(a[parentInd],a[i]);
            BottomToTop(parentInd/2);
        }
    }
    void insert(int p,string nm)
    {
        Node temp(nm,p);
        a[++size]=temp;
        BottomToTop(size);
    }
    void Build()
    {
        for(int i=size/2;i>=1;i--)
        {
            TopToBottom(i);
        }
    }
    Node extractMax()
    {
        Node temp=a[1];
        a[1]=a[size];
        size--;
        TopToBottom(1);
        return temp;

    }
    void bfs()
    {
        int level=2;
        queue<int>q;
        q.push(1);
        while(!q.empty())
        {
            int parent=q.front();
            q.pop();
            if(parent==level)
            {
                cout<<"\n";
                level*=2;
            }
            cout<<a[parent].name<<" having priority of "<<a[parent].priority<<"      ";
            if(2*parent<=size)
            {
                q.push(2*parent);
            }
            if(2*parent+1<=size)
            {
                q.push(2*parent+1);
            }
        }
    }
};
int main()
{
    Heap h;
    int n;
    cout<<"Enter number of patients = ";
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cout<<"Patient  name = ";
        string s;
        cin>>s;
        cout<<"Patient Priority = ";
        int p;
        cin>>p;
        h.insert(p,s);
    }
    h.Build();
    cout<<"\n";
    for(int i=0;i<n;i++)
    {
        Node result=h.extractMax();
        cout<<result.name<<" having priority "<<result.priority<<"\n";
    }
}