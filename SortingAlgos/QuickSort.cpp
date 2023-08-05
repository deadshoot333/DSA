#include<bits/stdc++.h>
using namespace std;
int n;
int a[100];
int partition(int low,int high)
{
    int pivot=a[high],i,j,temp;
    i=low-1;
    for(j=low;j<high;j++)
    {
        if(a[j]<pivot)
        {
            i++;
            temp=a[j];
            a[j]=a[i];
            a[i]=temp;
        }
    }
    int t=a[i+1];
    a[i+1]=pivot;
    a[high]=t;
    return i+1;
}
void quickSort(int low,int high)
{
    if(low>=high)
    {
        return;
    }
    int p=partition(low,high);
    quickSort(low,p-1);
    quickSort(p+1,high);
}
int main()
{
    cout<<"Enter number of elements= ";
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    quickSort(0,n-1);
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
}