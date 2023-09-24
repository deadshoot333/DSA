#include<bits/stdc++.h>
using namespace std;
int dp[50][50];
int weight[50];
int price[50];
int knapsack(int item,int wgt)
{
    for(int i=0;i<=wgt;i++)
    {
        dp[wgt][0]=0;//base case handled
    }
    for(int i=0;i<=item;i++)
    {
        dp[item][0]=0;
    }
    for(int i=1;i<=item;i++)
    {
        for(int cap=0;cap<=wgt;cap++)
        {
            if(cap<weight[i])
            {
                dp[i][cap]=dp[i-1][cap];//cap kom hole dp te ager item er dp er value bosbe
            }
            else
            {
                dp[i][cap]=max(price[i]+dp[i-1][cap-weight[i]],dp[i-1][cap]);//cap beshi hole current item er price + ager item er dp ar oi cap e ager item er dp er moddhe konta max
            }
        }
    }
    return dp[item][wgt];//provided item ar capacity onujayi dp holo answer
}
int main()
{
    clock_t start,end;
    start=clock();
    int n=5,c=4;
    //cin>>c>>n;
    //for(int i=1; i<=n; i++)  cin>>weight[i]>>price[i];
    weight[1]=1;
    price[1]=8;
    weight[2]=2;
    price[2]=4;
    weight[3]=3;
    price[3]=0;
    weight[4]=2;
    price[4]=5;
    weight[5]=2;
    price[5]=3;
    cout<<knapsack(n,c)<<endl;
    for(int i=0; i<=n; i++)
    {
        for(int j=0; j<=c; j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    end=clock();
    double time_taken=(double)(end-start)/(double)CLOCKS_PER_SEC;
    cout<<"\nTIME TAKEN : "<<time_taken<<" s\n";
}