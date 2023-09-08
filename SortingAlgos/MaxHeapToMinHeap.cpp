#include<bits/stdc++.h>
using namespace std;

class Heap
{
    int a[101];
    int size;
    public:
    Heap()
    {
        size=0;
    }
    void TopToBottom(int i)
    {
        int left=2*i;
        int right=2*i+1;
        int largest=i;
        if(left<=size && a[largest]<a[left])
        {
            largest=left;
        }
        if(right<=size && a[largest]<a[right])
        {
            largest=right;
        }
        if(largest!=i)
        {
            swap(a[1],a[largest]);
            TopToBottom(largest);
        }
    }
    void BottomToTop(int i)
    {
        if(i<=1)
        {
            return;
        }
        int parent=i/2;
        if(a[parent]<a[i])
        {
            swap(a[i],a[parent]);
            BottomToTop(parent/2);
        }
    }
    void Build()
    {
        for(int i=size/2;i>=1;i--)
        {
            TopToBottom(i);
        }
    }
    void insert(int value)
    {
        a[++size]=value;
        BottomToTop(size);
    }
    int deleteRoot()
    {
        int temp=a[1];
        a[1]=a[size];
        size--;
        TopToBottom(1);
        Build();
        return temp;
    }
    void Sort()
    {
        int sz=size;
        int temp[101];
        //Build();
        while(this->size>=1)
        {
            temp[size]=deleteRoot();
        }
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
            cout<<temp[parent]<<" ";
            if(2*parent<=sz)
            {
                q.push(2*parent);
            }
            if(2*parent+1<=sz)
            {
                q.push(2*parent+1);
            }
        }
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
            cout<<a[parent]<<" ";
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
    ~Heap()
    {

    }
};
int main()
{
    int n;
    cin>>n;
    Heap h;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        h.insert(x);
    }
    h.Build();
    cout<<"Max Heap Tree\n";
    h.bfs();
    cout<<"\nMin Heap\n";
    h.Sort();
}