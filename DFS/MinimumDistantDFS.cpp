/*Mimum Distance using DFS*/
#include<bits/stdc++.h>
using namespace std;
vector<int>g[50];
int visited[50];
int parent[50];
int dist[50];
void DFS(int r);
int main()
{
    int n,e;
    cout<<"Enter the Number of Nodes= ";
    cin>>n;
    cout<<"Enter the Number of Edges= ";
    cin>>e;
    int r;
    cout<<"\nEnter the root= ";
    cin>>r;
    cout<<"\nEnter the connection= ";
    for(int i=0;i<e;i++)
    {
        int x,y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    DFS(r);
    cout<<"\nColored Nodes= ";
    for(int i=0;i<=n;i++)
    {
        cout<<visited[i]<<" ";
    }
    cout<<"\nDistance= ";
    for(int i=0;i<=n;i++)
    {
        cout<<dist[i]<<" ";
    }
}
void DFS(int r)
{
    visited[r]=1;
    cout<<r<<" ";
    for(int i: g[r])
    {
        if(visited[i]==0)
        {
            parent[i]=r;
            dist[i]=dist[r]+1;
            DFS(i);
        }
    }
    visited[r]=2;
}