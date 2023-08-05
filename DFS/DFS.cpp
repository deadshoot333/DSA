
//#include<bits/stdc++.h>
#include<iostream>
#include <vector>
#include<cstdio>
#include<cstring>
using namespace std;

int t, visited[100], discover[100], finish[100], parent[100];
vector<int> adj[100];

void dfs(int node)
{
    visited[node] = 1;
    t = t+1;
    discover[node] = t;

    for(int i=0; i<adj[node].size(); i++)
    {
        int v = adj[node][i];

        if(visited[v]==0)
        {
            cout<<v<<" ";
            parent [v]=node;
            dfs(v);
        }
    }

    t = t+1;
    finish[node] = t;
    visited[node] = -1;
}

int main(){


        int edges, nodes, a, b;
        memset(visited,0, sizeof(visited));
        memset(discover,0, sizeof(discover));
        memset(finish,0,sizeof(finish));
        t=0;
        for(int i=0; i<=100;i++)adj[i].clear();

        cin>>edges>>nodes;
        for(int i=0; i<edges;i++)
        {
            cin>>a>>b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        for(int i=0;i<nodes;i++)
        {
            cout<<i<<"->";
            for(int j=0;j<adj[i].size();j++)
            {
                cout<<adj[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
        for(int i=1; i<=nodes ;i++)
        {
            if(visited[i] == 0)
            {
                cout<<i<<" ";
                dfs(i);
            }
        }
       cout<<endl;

       cout<<"Parent:  ";
         for(int i=1;i<=nodes;i++)
        {
            cout<<parent[i]<<" ";
        }



}

