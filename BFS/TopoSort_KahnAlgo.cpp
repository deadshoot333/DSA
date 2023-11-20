#include<bits/stdc++.h>
using namespace std;
map<char,vector<char>>adj;
map<char,int>mp;
map<char,bool>visited;
queue<char>q;
vector<char>ans;
void TopologicalSort()
{
    while(!q.empty())
    {
        char king=q.front();
        q.pop();
        visited[king]=true;
        ans.push_back(king);
        for(auto child:adj[king])
        {
            mp[child]--;
            if(mp[child]==0)
            {
                q.push(child);
            } 
        }
    }
}
int main()
{
    int e;
    cin>>e;
    for(int i=0;i<e;i++)
    {
        char u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        mp[v]++;
    }
    for(auto it:adj)
    {
        if(mp[it.first]==0)
        {
            q.push(it.first);
        }
    }
    TopologicalSort();
    for(auto it:ans)
    {
        cout<<it<<" ";
    }
    cout<<"\n";
}
