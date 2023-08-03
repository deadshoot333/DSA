#include<bits/stdc++.h>
using namespace std;
int a[10],l=3;
int Search(int a[],int k)
{
    for(int i=0;i<l;i++)
    {
        if(a[i]==k)
        {
            return i;
        }
    }
    return 0;
}
int main()
{
    int k;
    cin>>k;
    for(int i=0;i<3;i++)
    {
        cin>>a[i];
    }
    int y=Search(a,k);
    cout<<y;

}