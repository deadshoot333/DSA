#include<bits/stdc++.h>
#define MAX 1001
using namespace std;
class Student
{
    public:
    int id;
    string name;
    double cgpa;
    Student()
    {

    }
    Student(int id,string name,double cgpa)
    {
        this->id=id;
        this->name=name;
        this->cgpa=cgpa;
    }
    ~Student()
    {

    }
};
class hp
{
    public:
    Student a[MAX];
    int size=0;
    hp()
    {

    }
    void TopToBottom(int i)
    {
        int left=2*i;
        int right=2*i+1;
        int largest=i;
        if(left<=size && a[largest].cgpa<a[left].cgpa)
        {
            largest=left;
        }
        if(right<=size && a[largest].cgpa<a[right].cgpa)
        {
            right=largest;
        }
        if(largest!=i)
        {
            swap(a[i],a[largest]);
            TopToBottom(largest);
        }

    }
    void bottomToTop(int i)
    {
        while(i>1 && a[i].cgpa>a[i/2].cgpa)
        {
            swap(a[i],a[i/2]);
            i=i/2;
        }
    }
    void insert(Student s)
    {
        a[++size]=s;
        bottomToTop(size);
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
            cout<<a[parent].name<<" ";
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
    void build_heap()
    {
        for(int i=size/2;i>=1;i--)
        {
            bottomToTop(i);
        }
    }
    ~hp()
    {

    }
};
int main()
{
    int n;
    cout<<"Number of Students = ";
    cin>>n;
    hp h;
    for(int i=0;i<n;i++)
    {
        int id;
        string name;
        double cgpa;
        cin>>name>>cgpa>>id;
        Student s(id,name,cgpa);
        h.insert(s);
    }
    h.bfs();
}