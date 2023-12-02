#include <bits/stdc++.h>
using namespace std;
int flag;
void PrintSubset(int i, int n, int target, vector<int> &a, vector<int> &subset)
{
    if(target==0)
    {
        flag++;
        cout<<"[ ";
        for(int i=0;i<subset.size()-1;i++)
        {
            cout<<subset[i]<<" , ";
        }
        cout<<subset[subset.size()-1]<<" ]";
        return;
    }
    if(i==n)
    {
        return;
    }
    PrintSubset(i+1,n,target,a,subset);
    if(a[i]<=target)
    {
        subset.push_back(a[i]);
        PrintSubset(i+1,n,target-a[i],a,subset);
        subset.pop_back();
    }
}
int main()
{
    int n,target;
    vector<int>a,subset;
    cout<<"Enter the number = ";
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        a.push_back(x);
    }
    cout<<"Enter the target = ";
    cin>>target;
    PrintSubset(0,n,target,a,subset);
    if(flag==0)
    {
        cout<<"NO solution found\n";
    }

}