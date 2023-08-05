#include<bits/stdc++.h>
using namespace std;
vector<int>adj[100];
vector<int>visited(100,0);
void DFS(int source)
{
    cout<<source<<" ";
    visited[source]=1;
    for(int child: adj[source])
    {
        if(visited[child]==0)
        {
            DFS(child);
        }
    }
}
int main()
{
    int n,e;
    cin>>n>>e;
    for(int i=0;i<e;i++)
    {
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    int start;
    cout<<"Start= ";
    cin>>start;
    DFS(start);

}