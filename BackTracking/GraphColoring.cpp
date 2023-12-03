#include <iostream>
#include <map>
#include <vector>

using namespace std;

// A class to represent an undirected graph
class Graph {
private:
  map<char, vector<char>> adjList; // Adjacency list representation of the graph
  map<char, char> colorMap;       // Map to store the color assigned to each vertex

public:
  // Constructor to initialize the graph
  Graph(map<char, vector<char>> adjList) {
    this->adjList = adjList;
  }

  // Function to check if a color can be assigned to a vertex
  bool isSafe(char vertex, char color) {
    for (char neighbor : adjList[vertex]) {
      if (colorMap[neighbor] == color) {
        return false;
      }
    }
    return true;
  }

  // Function to color the graph using backtracking
  bool colorGraph(int m) {
    if (colorMap.size() == adjList.size()) {
      return true;
    }

    for (auto vertexPair : adjList) {
      char vertex = vertexPair.first;
      if (!colorMap.count(vertex)) {
        for (int i = 1; i <= m; i++) {
          if (isSafe(vertex, (char) ('A' + i - 1))) {
            colorMap[vertex] = (char) ('A' + i - 1);
            if (colorGraph(m)) {
              return true;
            }
            colorMap.erase(vertex); // Backtrack
          }
        }
        return false; // No color could be assigned to the vertex
      }
    }
    return true;
  }

  // Function to print the colored graph
  void printColorMap() {
    cout << "Vertex | Color\n";
    cout << "-------+-------\n";
    for (auto colorPair : colorMap) {
      cout << colorPair.first << " | " << colorPair.second << endl;
    }
    cout << "-------+-------\n";
  }
};

int main() {
  // Create the graph
  map<char, vector<char>> adjList;
  adjList['A'] = {'B', 'D'};
  adjList['B'] = {'A', 'C'};
  adjList['C'] = {'B', 'D'};
  adjList['D'] = {'A', 'C'};
  // adjList['E'] = {'B', 'D', 'F'};
  // adjList['F'] = {'C', 'E'};

  // Create the graph object
  Graph graph(adjList);

  // Color the graph
  int m = 3; // Number of colors
  if (graph.colorGraph(m)) {
    graph.printColorMap();
  } else {
    cout << "Graph cannot be colored with " << m << " colors" << endl;
  }

  return 0;
}
