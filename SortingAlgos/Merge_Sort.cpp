#include<bits/stdc++.h>
using namespace std;
vector<int>merge_sort(vector<int>&a)
{
	if(a.size()<=1)
	{
		return a;
	}
	int mid=a.size()/2;
	vector<int>b;
	vector<int>c;
	for(int i=0;i<mid;i++)
	{
		b.push_back(a[i]);
	}
	for(int i=mid;i<a.size();i++)
	{
		c.push_back(a[i]);
	}
	vector<int>sorted_b=merge_sort(b);
	vector<int>sorted_c=merge_sort(c);
	int indx1=0;
	int indx2=0;
	vector<int>ans;
	for(int i=0;i<a.size();i++)
	{
		if(indx1==sorted_b.size())
		{
			ans.push_back(sorted_c[indx2]);
			indx2++;
		}
		else if(indx2==sorted_c.size())
		{
			ans.push_back(sorted_b[indx1]);
			indx1++;
		}
		else if(sorted_b[indx1]<sorted_c[indx2])
		{
			ans.push_back(sorted_b[indx1]);
			indx1++;
		}
		else 
		{
			ans.push_back(sorted_c[indx2]);
			indx2++;
		}
	}
	return ans;
}
int main()
{
	int n;
	cin>>n;
	vector<int>a;
	for(int i=0;i<n;i++)
	{
		int x;
		cin>>x;
		a.push_back(x);
	}
	vector<int>ans=merge_sort(a);
	for(auto i:ans)
	{
		cout<<i<<" ";
	}
	cout<<"\n";
}