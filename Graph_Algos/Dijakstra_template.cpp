#include<bits/stdc++.h>
using namespace std;

map<char, vector<pair<char, int>>> adj;

void addEdge(char u, char v, int weight) {
  adj[u].push_back({v, weight});
}

void dijkstra(map<char, int>& dis, char src) {
  int n = dis.size();
  priority_queue<pair<int, char>, vector<pair<int, char>>, greater<pair<int, char>>> pq;
  pq.push({0, src});

  while (!pq.empty()) {
    pair<int, char> top = pq.top();
    pq.pop();

    int d = top.first;
    char u = top.second;

    if (dis[u] < d) {
      continue;
    }

    for (auto it : adj[u]) {
      char v = it.first;
      int weight = it.second;

      if (dis[v] > d + weight) {
        dis[v] = d + weight;
        pq.push({dis[v], v});
      }
    }
  }
}

int main() {
  cout << "Enter the number of edges = ";
  int e;
  cin >> e;

  map<char, int> dis;
  for (int i = 0; i < e; i++) {
    char u, v;
    int w;
    cin >> u >> v >> w;

    addEdge(u, v, w);
    dis[u] = INT_MAX;
    dis[v] = INT_MAX;
  }

  cout << "Enter the source node = ";
  char source;
  cin >> source;

  dis[source] = 0;
  dijkstra(dis, source);

  for (auto it : dis) {
    cout << "From source " << source << " to destination " << it.first << " the cost is " << it.second << "\n";
  }

  return 0;
}
