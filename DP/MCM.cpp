#include<bits/stdc++.h>
using namespace std;
int dp[100][100];
int arr[100];
void init(int n)
{
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=n;j++)
		{
			dp[i][j]=INT_MAX;
		}
	}
}
int MCM(int i,int j)
{
	if(i==j)
	{
		return 0;
	}
	if(dp[i][j]!=INT_MAX)
	{
		return dp[i][j];
	}
	for(int k=i;k<j;k++)
	{
		dp[i][j]=min(dp[i][j],MCM(i,k)+MCM(k+1,j)+arr[i-1]*arr[k]*arr[j]);
	}
	return dp[i][j];
}
int main()
{
	int n;
	cin>>n;
	int row[n];
	int col[n];
	for(int i=0;i<n;i++)
	{
		cin>>row[i]>>col[i];
		arr[i]=row[i];
		arr[i+1]=col[i];	    //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
	}
	init(n);
	cout<<MCM(1,n)<<"\n";
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(dp[i][j]==INT_MAX)
			{
				cout<<"0 ";
			}
			else
			{
				cout<<dp[i][j]<<" ";
			}
		}
		cout<<"\n";
	}
}