#include<bits/stdc++.h>
using namespace std;
int a[5],l=0;
int insert(int x,int index)
{
  if(l==5) return 0;
  else if(index<0||index>4) return -1;
  else
  {
    int i;
    for(i=l-1;i>=index;i--)
    {
      a[i+1]=a[i];   
    }
    a[index]=x;
    l++;
    for(i=0;i<l;i++)
    {
      cout<<a[i]<<" ";
    }
    cout<<"\n";
  }
}
int main()
{
  while(1)
  {
  int x,index;
  std::cin>>x>>index;
  int y=insert(x,index);
  if(y==-1||y==0) 
  {
    cout<<"CAnt solve\n";
  }
  }
}
