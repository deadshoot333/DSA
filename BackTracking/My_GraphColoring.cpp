#include<bits/stdc++.h>
using namespace std;
int V;
int adj[100][100];
int color[100];

    bool isSafe(int v,int c)
{
    for(int i=1;i<=V;i++)
    {
        if(adj[v][i] && color[i]==c)
        {
            return false;
        }
    }
    return true;
}
bool ColorGraph(int v,int m)
{
    if(v==V)
    {
        return true;
    }
    for(int i=1;i<=m;i++)
    {
        if(isSafe(v,i))
        {
            color[v]=i;
        }
        if(ColorGraph(v+1,m))
        {
            return true;
        }
        color[v]=INT_MAX;
    }
    return false;
}
int main()
{
    cout<<"Enter the number of nodes = ";
    cin>>V;
    for(int i=1;i<=V;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u][v]=1;
        adj[v][u]=1;
    }
    int start;
    cout<<"Enter start node = ";
    cin>>start;
    cout<<"Enter the number of colors = ";
    int m;
    cin>>m;
    if(ColorGraph(start,m))
    {
        for(int i=1;i<=V;i++)
        {
            cout<<i<<"->"<<color[i]<<" ";
        }
        cout<<endl;
    }
    else
    {
        cout<<"NO solution\n";
    }
}