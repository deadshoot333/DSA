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
    int right(int i)
    {
        return 2*i+1;
    }
    void bottomTopAdjust(int i){
       if(i<=1)
       {
            return;
       }
       int parent=i/2;
       if(a[parent]<a[i])
       {
        swap(a[parent],a[i]);
        bottomTopAdjust(parent/2);
       }

    }
    void topBottomAdjust(int i)
    {
        int l=left(i);
        int r=right(i);
        int largest;
        if(l<=size && a[l]>a[i])
        {
            largest=l;
        }
        else
        {
            largest=i;
        }
        if(r<=size && a[r]>a[largest])
        {
            largest=r;
        }
        if(largest!=i)
        {
            swap(a[i],a[largest]);
            topBottomAdjust(largest);
        }    
    }
public:
    bool insert(int val){
        if(size>=100)
        {
            return false;
        }
        size++;
        a[size]=val;
        bottomTopAdjust(size);
        return true;
      
    }

    int showMax(){
       return a[1];
    }

    int showSize(){
        return size;
    }

    bool deleteRoot(){
        if(size<1)
        {
            return false;
        }
        swap(a[1],a[size]);
        size--;
        topBottomAdjust(1);
        return true;

    }

    void buildHeap(){
        for(int i=size/2;i>=1;i--)
        {
            topBottomAdjust(i);
        }
      
    }

    void sort(){
        buildHeap();
        int sz=size;
        for(int i=size;i>=1;i--)
        {
            swap(a[i],a[1]);
            size-=1;
            topBottomAdjust(1);
        }
        size=sz;
        for(int i=1;i<=size;i++)
        {
            cout<<a[i]<<" ";
        }
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
        cout<<"1. Insert    2. Show Max    3. Delete Max    4. Sort    5. Level    6. Build Heap    7. End"<<endl<<endl;
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
            if(heap.showSize()!=0)  cout<<"Max Element: "<<heap.showMax();
            else    cout<<"No element in the heap"<<endl;
        }

        else if(choice==3){
            bool b = heap.deleteRoot();
            if(b)   cout<<"Root deleted from heap";
            else    cout<<"Heap is empty";
            cout<<endl;
        }

        else if(choice==4){
            heap.sort();
        }

        else if(choice==5){
            cout<<"Level Wise Traversal of the heap:"<<endl;
            heap.bfs();
            cout<<endl;
        }
        else if(choice==6){
            if(heap.showSize()==0)
              cout<<"Heap is Empty!"<<endl;
            else
              heap.buildHeap();
        }
        else if(choice==7){
            break;
        }

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

