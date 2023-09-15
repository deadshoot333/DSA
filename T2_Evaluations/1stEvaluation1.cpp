#include<bits/stdc++.h>
using namespace std;
vector<int>MergeSort(vector<int>a)
{
    if(a.size()<=1)
    {
        return a;
    }
    vector<int>b;
    for(int i=0;i<a.size()/2;i++)
    {
        b.push_back(a[i]);
    }
    vector<int>c;
    for(int i=a.size()/2;i<a.size();i++)
    {
        c.push_back(a[i]);
    }
    vector<int>sorted_b=MergeSort(b);
    vector<int>sorted_c=MergeSort(c);
    int index1=0,index2=0;
    vector<int>ans;
    for(int i=0;i<a.size();i++)
    {
        if(index1>=sorted_b.size())
        {
            ans.push_back(sorted_c[index2]);
            index2++;
        }
        else if(index2>=sorted_c.size())
        {
            ans.push_back(sorted_b[index1]);
            index1++;
        }
        else if(sorted_b[index1]>sorted_c[index2])
        {
            ans.push_back(sorted_b[index1]);
            index1++;
        }
        else
        {
            ans.push_back(sorted_c[index2]);
            index2++;
        }
    }
    return ans;
}
int main()
{
    int n;
    cin>>n;
    vector<int>a;
    vector<int>freq(n+1,0);
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        a.push_back(x);
    }
    for(int i=0;i<a.size();i++)
    {
        freq[abs(a[i])]=INT_MIN;
    }
    vector<int>ans=MergeSort(a);
    int x=0;
    for(int i=0;i<n;i++)
    {
        x++;
        freq[abs(ans[i])]=a.size()-x;
    }
    for(int i=0;i<n;i++)
    {
        if(freq[i]==INT_MIN)
        {
            continue;
        }
        cout<<freq[abs(a[i])]<<" ";
    }
    cout<<"\n";
}