#include<bits/stdc++.h>
using namespace std;
vector<int>adj[100];
int visited[100];
int recStack[100];
bool dfs(int start)
{
    visited[start]=1;
    recStack[start]=1;
    for(auto child:adj[start])
    {
        if(!visited[child] && dfs(child)) //amr child er child onner dara visited
        {
            return true;
        }
       else if(recStack[child]) //recstack e child false thakar kotha kintu true ache tar mane cycle detected
        {
            return true;
        }
    }
    recStack[start]=0;
    return false;
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
    }
    cout<<"Enter start= ";
    int start;
    cin>>start;
    if(dfs(start))
    {
        cout<<"Cycle detected\n";
    }
    else 
    {
        cout<<"Cycle not detected\n";
    }
    return 0;
}
