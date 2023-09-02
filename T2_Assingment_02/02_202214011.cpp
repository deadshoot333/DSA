///Max Heap

#include<bits/stdc++.h>
using namespace std;

class Heap{
private:
    int a[101], size;

public:
    Heap(){
        size = 0;
    }

private:
    int left(int i)
    {
        return 2*i;
    }
    int right(int t)
    {
        return 2*t+1;
    }
    void bottomTopAdjust(int i){
        while(i!=1)
        {
            if(a[i]>a[i/2])
                swap(a[i],a[i/2]);
            else
                break;
            i=i/2;
        }
    }

    void topBottomAdjust(int i) /// HEAPIFY!
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
            topBottomAdjust(largest);
        }
    }

public:
    bool insert(int val){
        if(size>=100)
        {
            return false;
        }
        a[++size]=val;
        bottomTopAdjust(size);
        return true;
    }
    bool increaseKey(int i, int k)
    {
        if(k<a[i])
        {
            return false;
        }
        a[i]=k;
        bottomTopAdjust(i);
        return true;
    }
    int showMax(){
        return a[1];
    }

    int showSize(){
        return size;
    }

    int extractMax()
    {
        int max_element=a[1];
        a[1]=a[size];
        size--;
        topBottomAdjust(1);
        return max_element; 
    }

    void bfs(){
        if(size==0) return;
        int level = 2;
        queue<int>q;
        q.push(1);

        while(!q.empty()){
            int parent = q.front();
            q.pop();
            if(parent==level){
                cout<<endl;
                level = level * 2;
            }
            cout<<a[parent]<<" ";
            if(2*parent <= size) q.push(2*parent);
            if(2*parent + 1 <= size) q.push(2*parent + 1);
        }
    }
};

int main(){

    Heap heap;

    while(1){
        cout<<"1. Insert    2. Increase Key    3. Show Max    4. Extract Max  5. Level Order Traversal 6. End"<<endl<<endl;
        int choice;
        cin>>choice;

        if(choice==1){
            cout<<"Insert Value: ";
            int y;
            cin>>y;
            bool b = heap.insert(y);

            if(b)   cout<<y<<" is inserted in the heap"<<endl;
        }
        else if(choice==2){
            cout<<"Which node you want to increase?"<<endl;
            int nodeNo;
            cin>>nodeNo;
            cout<<"What will be the new value?"<<endl;
            int value;
            cin>>value;
            bool b=heap.increaseKey(nodeNo,value);
            if(b) cout<<"Node value increased successfully!"<<endl;
            else cout<<"Unsuccessful Operation :("<<endl;
        }
        else if(choice==3){
            if(heap.showSize()!=0)  cout<<"Max Element: "<<heap.showMax();
            else    cout<<"No element in the heap"<<endl;
        }

        else if(choice==3){
            if(heap.showSize()!=0)  cout<<"Max Element: "<<heap.showMax();
            else    cout<<"No element in the queue"<<endl;
        }

        else if(choice==4){
            if(heap.showSize()!=0)  cout<<"Max element extracted: "<<heap.extractMax();
            else    cout<<"No element in the queue"<<endl;
        }

        else if(choice==5){
           cout<<"Level Wise Traversal of the Queue:"<<endl;
           heap.bfs();
           cout<<endl;
        }
        else if(choice==6)
            break;
        else{
            cout<<"Invalid Choice"<<endl;
        }
        cout<<endl;
    }
}

/*
1 2
1 9
1 8
1 16
1 3
1 7
1 10
1 1
1 4
1 14
*/



