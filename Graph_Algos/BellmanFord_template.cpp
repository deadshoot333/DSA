#include<bits/stdc++.h>
using namespace std;
map<char,vector<pair<char,int>>>adj;
int cost;
void addEdge(char u,char v,int weight)
{
    adj[u].push_back({v,weight});
}
bool bellmanFord(map<char,int>&dis,char src)
{
    int n=dis.size();
    for(int i=0;i<n-1;i++)
    {
        for(auto it:adj)
        {
            char u=it.first;
            for(auto it2:adj[u])
            {
                if(dis[u]+it2.second<dis[it2.first])
                {
                    dis[it2.first]=dis[u]+it2.second;
                }
            }
        }
    }
    for(int i=0;i<n-1;i++)
    {
        for(auto it:adj)
        {
            char u=it.first;
            for(auto it2:adj[u])
            {
                if(dis[u]+it2.second<dis[it2.first])
                {
                    return false;
                }
            }
        }
    }
    return true;
}
int main()
{
    cout<<"Enter the number of edges = ";
    int e;
    cin>>e;
    map<char,int>dis;
    for(int i=0;i<e;i++)
    {
        char u,v;
        int w;
        cin>>u>>v>>w;
        addEdge(u,v,w);
        dis[u]=INT_MAX;
        dis[v]=INT_MAX;
    }
    cout<<"Enter the source node = ";
    char source;
    cin>>source;
    cout<<"Enter the destination node = ";
    char destination;
    cin>>destination;
    dis[source]=0;
    if(bellmanFord(dis,source))
    {
        for(auto it:dis)
        {
            cout<<"From source "<<source<<" to destination "<<it.first<<" the cost is "<<it.second<<"\n";
            if(it.first==destination)
            {
                break;
            }
        }
    }
    else
    {
        cout<<"Negative cycle detected.NO SOLUTION!!!\n";
    }
}

