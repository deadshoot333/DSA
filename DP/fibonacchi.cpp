#include<bits/stdc++.h>
using namespace std;
int memo[2005];
int f(int n)
{
    if(n==0) return 0;
    if(n==1) return 1;
    // if(memo[n]!=-1) return memo[n];
    // memo[n]=f(n-1)+f(n-2);
    // return memo[n];
    return f(n-1)+f(n-2);
}
void init()
{
    for(int i=0;i<2005;i++)
    {
        memo[i]=-1;
    }
}
int main()
{
    clock_t start,end;
    start=clock();
    init();
    int n;
    cin>>n;
    cout<<f(n)<<"\n";
    end=clock();
    double time_taken=(double)(end-start)/(double)CLOCKS_PER_SEC;
    cout<<"TIME taken = "<<time_taken<<"\n";
}