#include<iostream>
#include<string>
using namespace std;
int main()
{
    string pattern;
    cin>>pattern;
    int n=pattern.size();
    int lps[n];
    int len=0;
    lps[len]=0;
    for(int i=1;i<n;)
    {
        if(pattern[i]==pattern[len])
        {
            len++;
            lps[i]=len;
            i++;
        }
        else if(len!=0 && pattern[len]!=pattern[i])
        {
            len=lps[len-1];
        }
        else if(len==0 && pattern[len]!=pattern[i])
        {
          lps[i]=len;
          i++;  
        }
    }
    for(auto i:lps)
    {
        cout<<i<<" ";
    }   
}