#include<bits/stdc++.h>
using namespace std;
#define MAX_SIZE 101
class  Max_Heap
{
    int a[MAX_SIZE];
    int size;
    public:
    Max_Heap()
    {
        size=0;
    }
    int left(int i)
    {
        return 2*i;
    }
    int right(int i)
    {
        return 2*i+1;
    }
    void topToBottom(int i)
    {
        int l=left(i);
        int r=right(i);
        int largest=i;
        if(l<=size && a[largest]<a[l])
        {
            largest=l;
        }
        if(r<=size && a[largest]<a[r])
        {
            largest=r;
        }
        if(largest!=i)
        {
            swap(a[largest],a[i]);
            topToBottom(largest);
        }
    }
    void bottomToTop(int i)
    {
        if(i<=1)
        {
            return;
        }
        int parentIndex=i/2;
        if(a[parentIndex]<a[i])
        {
            swap(a[parentIndex],a[i]);
            bottomToTop(parentIndex/2);
        }
    }
    void insert(int value)
    {
        if(size>=MAX_SIZE)
        {
            cout<<"Cannot Insert\n";
            return;
        }
        a[++size]=value;//insert korar por bottom to top adjust
        bottomToTop(size);

    }
    void build_heap()
    {
        for(int i=size/2;i>=1;i--)
        {
            bottomToTop(i);
        }
        
    }
    void heap_sort()
    {
        int cpy_size=size;
        for(int i=size;i>=1;i--)
        {
            swap(a[i],a[1]);
            size--;
            topToBottom(1);
        }
        size=cpy_size;
    }
    void print_heap()
    {
        for(int i=1;i<=size;i++)
        {
            cout<<a[i]<<" ";
        }
        cout<<"\n";
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
        cout<<"\n";
    }

};
int main()
{
    Max_Heap h;
    int n;
    cout<<"Enter the number to be inserted= ";
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        h.insert(x);
    }
    h.print_heap();
    h.build_heap();
    h.bfs();
    h.heap_sort();
    //h.build_heap();
    h.print_heap();
    h.bfs();
}