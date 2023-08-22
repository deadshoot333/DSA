#include<bits/stdc++.h>
using namespace std;

void merge(int a[],int mid,int left,int right)
{
    int subArrayLeft=mid-left+1;
    int subArrayRight=right-mid;
    int *leftArray;
    int *rightArray;
    leftArray=new int[subArrayLeft];
    rightArray=new int[subArrayRight];
    for(int i=0;i<subArrayLeft;i++)
    {
        leftArray[i]=a[left+i];
    }
    for(int i=0;i<subArrayRight;i++)
    {
        rightArray[i]=a[mid+1+i];
    }
    int index1=0,index2=0,indexMerged=left;
    while(index1<subArrayLeft && index2<subArrayRight)
    {
        if(leftArray[index1]<=rightArray[index2])
        {
            a[indexMerged]=leftArray[index1];
            index1++;
        }
        else
        {
            a[indexMerged]=rightArray[index2];
            index2++;
        }
        indexMerged++;
    }
    while(index1<subArrayLeft)
    {
        a[indexMerged]=leftArray[index1];
        indexMerged++;
        index1++;
    }
    while(index2<subArrayRight)
    {
        a[indexMerged]=rightArray[index2];
        indexMerged++;
        index2++;
    }
    delete [] leftArray;
    delete [] rightArray;
}
void MergeSort(int a[],int begin,int end)
{
    if(begin>=end)
    {
        return;
    }
    int mid=begin+(end-begin)/2;
    MergeSort(a,begin,mid);
    MergeSort(a,mid+1,end);
    merge(a,mid,begin,end);
}
int main()
{
    int a[]={9,8,7,5,6};
    MergeSort(a,0,4);
    for(int i=0;i<5;i++)
    {
        cout<<a[i]<<" ";
    }
}