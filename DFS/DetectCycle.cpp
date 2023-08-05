/*Detect Cycle for undirected Graph using DFS*/
#include<bits/stdc++.h>
using namespace std;
vector<int>g[50];
int visited[50];
int parent[50];
bool DFS(int r);
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
        //g[y].push_back(x);
    }
    if(DFS(r))
    {
        cout<<"Cycle detected\n";
    }
    else
    {
        cout<<"Cycle not detected\n";
    }
    cout<<"\nColored Nodes= ";
    for(int i=0;i<=n;i++)
    {
        cout<<visited[i]<<" ";
    }
}
bool DFS(int r)
{
    visited[r]=1;
    cout<<r<<" ";
    for(int child: g[r])
    {
        if(visited[child]==0)
        {
            parent[child]=r;
            DFS(child);
            return false;
        }
        else if(child!=parent[r]) //emon ekta visited child ache jeta claim kortese tar child r kintu actually r er parent set kora onn kichu tkhn cycle detected. amr child amr baap hote chai tkhn cycle detect hoi
        {
            return true;
        }
    }
    visited[r]=2;
    return false;
}
