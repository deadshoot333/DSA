#include<bits/stdc++.h>
using namespace std;
int dp[100][100];
void init()
{
    for(int i=0;i<100;i++)
    {
        for(int j=0;j<100;j++)
        {
            dp[i][j]=-1;
        }
    }
}
int mcm(int i,int j,int *array)
{
    if(i==j)
    {
        return 0;
    }
    if(dp[i][j]=-1)
    {
        return dp[i][j];
    }
    dp[i][j]=INT_MAX;
    for(int k=i;k<j;k++)
    {
        dp[i][j]=min(dp[i][j],mcm(i,k,array)+mcm(k+1,j,array)+array[i-1]*array[k]*array[j]);
        cout<<dp[i][j]<<"\n";
    }
    return dp[i][j];
}
int main()
{
    init();
    int array[]={1,2,3,4};
    cout<<mcm(1,3,array)<<"\n";
}