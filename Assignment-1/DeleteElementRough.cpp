#include<bits/stdc++.h>
int main()
{
    int k;
    cout<<"Enter index to delete from: ";
    cin>>k;
    if(k<0||k>l)
    {
        cout<<"Incorrect postional Value\n";
    }
    else
    {
    for(int i=k;i<5;i++)
    {
        a[i]=a[i+1];
    }
    cout<<"The current array list is: ";
    for(int i=0;i<4;i++)
    {
        cout<<a[i]<<" ";
    }
    }

    
}