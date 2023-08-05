#include<bits/stdc++.h>
using namespace std;
vector<int>quickSort(vector<int>&a)
{
	if(a.size()<=1)
	{
		return a;
	}
	int pivot=a.size()/2;//rand()%a.size() can also be used
	vector<int>b,c;
	for(int i=0;i<a.size();i++)
	{
		if(i==pivot)
		{
			continue;
		}
		if(a[i]<=a[pivot])
		{
			b.push_back(a[i]);
		}
		else
		{
			c.push_back(a[i]);
		}
	}
	vector<int>sorted_b=quickSort(b);
	vector<int>sorted_c=quickSort(c);
	vector<int>ans;
	for(int i=0;i<sorted_b.size();i++)
	{
		ans.push_back(sorted_b[i]);
	}
	ans.push_back(a[pivot]);
	for(int i=0;i<sorted_c.size();i++)
	{
		ans.push_back(sorted_c[i]);
	}
	return ans;
}
int main()
{
	int n;
	cin>>n;
	vector<int>a;
	while(n--)
	{
		int x;
		cin>>x;
		a.push_back(x);
	}
	vector<int>sorted_a=quickSort(a);
	for(int i=0;i<sorted_a.size();i++)
	{
		cout<<sorted_a[i]<<" ";
	}
	cout<<"\n";
}