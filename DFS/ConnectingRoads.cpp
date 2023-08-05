#include<bits/stdc++.h>
using namespace std;
vector<int>adj[100];
int visited[100];
vector<int>con;
void dfs(int start)
{
    visited[start]=1;
    //cout<<start<<" ";
    for(auto child:adj[start])
    {
        if(!visited[child])
        {
            dfs(child);
        }
    }
}
int solve(int n)
{
    int count=0;
    for(int i=0;i<n;i++)
    {
        if(!visited[i])
        {
            dfs(i);
            con.push_back(i);
            count++;
        }
    }
    return count;
}
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cout<<solve(n)-1<<"\n";
    for(int i=0;i<con.size();i++)
    {
        cout<<con[i]<<" "; 
    }
}