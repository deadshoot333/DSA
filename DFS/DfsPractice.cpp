#include<bits/stdc++.h>
using namespace std;
int visited[100];
vector<int>adj[100];
void dfs(int start)
{
    visited[start]=1;
    for(int child=0;child<adj[start].size();child++)
    {
        int x=adj[start][child];
        if(!visited[x])
        {
            cout<<x<<" ";
            dfs(x);
        }
    }
}
int main()
{
    int n;
    cin>>n;
    for(int i=2;i<=n;i++)
    {
        int x;
        cin>>x;
        adj[x].push_back(i);
        adj[i].push_back(x);
    }
    dfs(1);
}