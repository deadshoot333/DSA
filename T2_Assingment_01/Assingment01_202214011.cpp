#include<bits/stdc++.h>
using namespace std;/*Given an integer array “nums” and an integer “k”, return
                     the kth largest element in the array. Now solve it without sorting*/
int partition(int a[],int high,int low)
{
    int pivot=a[high];
    int i=low-1;
    for(int j=low;j<=high;j++)
    {
        if(a[j]>=pivot)
        {
            i++;
            swap(a[i],a[j]);
        }
    }
    swap(a[i+1],a[high]);
    return i+1;
}
int Kth_Largest(int a[],int start,int end,int k)
{
 
    int p=partition(a,start,end);
    if(p-1==k-1)
    {
        return a[p];
    }
    if(p-1<k-1)
    {
        return Kth_Largest(a,p+1,end,k-p+start-1);
    }
    return Kth_Largest(a,start,p-1,k);
}
int main()
{
    int n,k;
    cin>>n>>k;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int ans=Kth_Largest(a,0,n-1,k);
    cout<<ans<<"\n";
    return 0;
}
