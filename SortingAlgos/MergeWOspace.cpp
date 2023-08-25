#include<bits/stdc++.h>
using namespace std;
int partition(int a[],int low,int high)
{
    int pivot=a[high];
    int i=low-1;
    for(int j=low;j<high;j++)
    {
        if(a[j]<pivot)
        {
            i++;
            swap(a[i],a[j]);
        }
    }
    swap(a[i+1],a[high]);
    return i+1;
}
void quickSort(int a[],int start,int end)
{   if(start>=end)
    {
        return;
    }
    int point=partition(a,start,end);
    quickSort(a,start,point-1);
    quickSort(a,point+1,end);
}
void merge(int a1[],int a2[],int n,int m)
{
    int i=0,j=0,k=n-1;
    while(i<=k && j<m)
    {
        if(a1[i]<a2[j])
        {
            i++;
        }
        else
        {
            swap(a1[k--],a2[j++]);
        }
    }
    quickSort(a1,0,n-1);
    quickSort(a2,0,m-1);
}
int main()
{
    int n;
    cin>>n;
    int a1[n];
    for(int i=0;i<n;i++)
    {
        cin>>a1[i];
    }
    int m;
    cin>>m;
    int a2[m];
    for(int i=0;i<m;i++)
    {
        cin>>a2[i];
    }
    merge(a1,a2,n,m);
    for(int i=0;i<n;i++)
    {
        cout<<a1[i]<<" ";
    }cout<<"\n";
    for(int i=0;i<m;i++)
    {
        cout<<a2[i]<<" ";
    }
    cout<<"\n";
}