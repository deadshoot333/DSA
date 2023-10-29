#include<bits/stdc++.h>
using namespace std;
int dp[100][100];
int s[100][100];
int arr[100];
void init(int n)
{
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=n;j++)       
		{
			dp[i][j]=INT_MAX;
			s[i][j]=INT_MAX;
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
		s[i][j]=k;
	}
	return dp[i][j];
}
void printMCM(int i,int j)
{
	if(i==j)
	{
		cout<<"A"<<i;
	}
	else
	{
		cout<<"(";
		printMCM(i,s[i][j]);
		printMCM(s[i][j]+1,j);
		cout<<")";
	}
}
int main()
{
	int n;
	cout<<"Enter the matrices dimensions = ";
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
				cout<<s[i][j]<<" ";
			}
		}
		cout<<"\n";
	}
	printMCM(1,n);
}