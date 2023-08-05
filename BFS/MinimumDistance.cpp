/*minimum distance path using bfs and vector*/
#include<bits/stdc++.h>
using namespace std;
vector<int>adj[100];
int visited[100];
int dis[100];
int parent[100];
int n,e;
void BFS(int start,int end)
{
    if(start==end)
    {
        return;
    }
    queue<int>q;
    q.push(start);
    parent[start]=-1;
    visited[start]=1;
    dis[start]=0;
    while(!q.empty())
    {
        int king=q.front();
        q.pop();
        for(int i=0;i<adj[king].size();i++)
        {
            int child=adj[king][i];
            
            if(visited[child]==0)
            {
                visited[child]=1;
                dis[child]=dis[king]+1;
                parent[child]=king;
                q.push(child);
            }
            if(visited[child]==end)
            {
                return;
            }
        }
    }
    cout<<"Distance of "<<end<<" from "<<start<<" is "<<dis[end]<<endl;
    cout<<"Path is: ";
    int x=end;
    while(x!=-1)
    {
        cout<<x<<" ";
        x=parent[x];
    }
    cout<<endl;
}
int main()
{
    cin>>n>>e;
    for(int i=0;i<e;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int start,end;
    cout<<"Enter start node= ";
    cin>>start;
    cout<<"Enter End node= ";
    cin>>end;
    BFS(start,end);
    return 0;
}