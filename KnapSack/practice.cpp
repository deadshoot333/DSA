#include<bits/stdc++.h>
using namespace std;
int dp[2000][2000];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,knp;
        cin>>n>>knp;
        int weights[n+1];
        for(int i=1;i<=n;i++)
        {
            cin>>weights[i];
        }
        for(int i=0;i<=n;i++)
        {
            dp[i][0]=0;
        }
        for(int i=0;i<=knp;i++)
        {
            dp[0][i]=0;
        }
        int mx=INT_MIN;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=knp;j++)
            {
                if(j<weights[i])
                {
                    dp[i][j]=dp[i-1][j];
                }
                else
                {
                    dp[i][j]=max(weights[i]+dp[i][j-weights[i]],dp[i][j-1]);
                    if(mx<dp[i][j])
                    {
                        mx=dp[i][j];
                    }
                }
            }
        }
        cout<<mx<<"\n";
    }
}