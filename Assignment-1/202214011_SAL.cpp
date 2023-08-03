#include<bits/stdc++.h>
using namespace std;
int a[10],l=0;
///Insert Array  FUNCTION START
int insert(int x,int index) 
{
  if(l==10) return 0;
  else if(index<0||index>l) return -1;
  else
  {
    int i;
    for(i=l-1;i>=index;i--)
    {
      a[i+1]=a[i];   
    }
    a[index]=x;
    l++;
    //cout<<x<<" is inserted at index "<<index<<'\n';
    cout<<"The current array list is: ";
    for(i=0;i<l;i++)
    {
      cout<<a[i]<<" ";
    }
    cout<<"\n";
  }
}
/// INSERT ARRAY FUNCTION END 
/// DELETE FUNCTION STARTS
void Delete(int k)
{
    if(k<0||k>l)
    {
        cout<<"Incorrect postional Value\n";
        return;
    }
    else
    {
    for(int i=k;i<l;i++)
    {
        a[i]=a[i+1];
    }
    l--;
    cout<<"The current array list is: ";
    for(int i=0;i<l;i++)
    {
        cout<<a[i]<<" ";
    }
    }
}
/// DELETE FUNCTION ENDS
/// SEARCH FUNCTION START
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
/// SEARCH FUNCTION END
/// PRINT  FUNCTION STARTS
void Print(int a[],int l)
{
  cout<<"The current array list is: ";
  for(int i=0;i<l;i++)
  {
    cout<<a[i]<<" ";
  }
}
///PRINT FUNCTION ENDS
int main()
{
    cout<<"\nMAX SIZE is set to 10\n\nMenu\n1.Insert Element.\n2.Delete Element.\n3.Search for an item.\n4.Print Current Array.\n5.Exit.";
    cout<<"\nEnter Choice: ";
    int choice;
    cin>>choice;
    if(choice==5) {exit(5);}
    switch(choice)
 {   /// INSERT ARRAY START
    case 1:
  {
    int x,index;
    cout<<"Enter element to insert: ";
    cin>>x;
    cout<<"\nEnter index position to insert (current array length is: "<<l<<", so choose an index between 0 and "<<l<<"): ";
    cin>>index;
    int y=insert(x,index);
    if(y==-1) 
    {
        cout<<"Incorrect Positional value\n";
    }
    else if(y==0)
    {
      cout<<"Array is Full\n";
    }
    break;
  }
    /// INSERT ARRAY END
  ///DELETE STARTS
   case 2:
   {
    int k;
    cout<<"Enter index to delete from: ";
    cin>>k;
    Delete(k);
    break;
   }
   ///DELETE ENDS
    /// Search  START
    case 3:
  {
    int k;
    cout<<"Enter Search key: ";
    cin>>k;
    int y=Search(a,k);
    if(y!=0)
    {
      cout<<"The Search key "<<k<<" is at index "<<y<<"\n";
    }
    else
    {
      cout<<"The Search key is not in the array\n";
    }
    break;
  }
  ///SEARCH ENDS
  ///PRINT STARTS
  case 4:
  {
    Print(a,l);
    break;
  }
  ///PRINT ENDS
  default :
  cout<<"\nPLEASE SELECT BETWEEN 1 TO 5";
  break;
 }
    return main();
}
