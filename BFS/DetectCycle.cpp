#include<bits/stdc++.h>
using namespace std;
int visited[100];
int parent[100];
int adj[100][100];
int n;
bool CycleDetect(int start)
{
    visited[start]=1;
    queue<int>q;
    parent[start]=-1;
    q.push(start);
    while(!q.empty())
    {
        int king=q.front();
        q.pop();
        for(int child=0;child<n;child++)
        {
            if(adj[king][child])
            {
                if(visited[child]==0)
                {
                    visited[child]=1;
                    parent[child]=king;
                    q.push(child);
                }
                else if(child!=parent[king])
                {
                    return true;
                }
            }
        }
    }
    return false;
}
int main()
{
    cin>>n;
    int e;
    cin>>e;
    for(int i=0;i<e;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u][v]=1;
        adj[v][u]=1;
    }
    cout<<"Enter Start= ";
    int start;
    cin>>start;
    cout<<CycleDetect(start)<<" ";
}