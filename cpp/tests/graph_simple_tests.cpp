// Simple test of graph adjacency and dfs

#include <bits/stdc++.h>
#include "../headers/utils.h"

using namespace std;

struct GraphNode
{
  int id;
  vector<pair<GraphNode&, int>> adjacent_nodes;
  bool visited;

  GraphNode(int id): id(id), visited(false){}

  void AddDirectedAdjacency( GraphNode& n, int weight)
  {
    adjacent_nodes.push_back({n,weight});
  }

  void AddBiDirectionalAdjacency( GraphNode& n, int weight)
  {
    this->AddDirectedAdjacency(n, weight);
    n.AddDirectedAdjacency(*this,weight);
  }

  void print() const
  {
    for( auto p: adjacent_nodes)
      cout << id << "->" << p.first.id << " weight: " << p.second << endl;  
  }
};

void dfs( GraphNode& node)
{
  if( node.visited)
    return;

  node.visited = true;
  cout << "Visited node: " << node.id << endl;  

  for( pair<GraphNode&,int> p: node.adjacent_nodes)
    dfs(p.first);
}

int main()
{
  auto n1 = GraphNode(1);
  auto n2 = GraphNode(2);
  auto n3 = GraphNode(3);
  auto n4 = GraphNode(4);
  auto n5 = GraphNode(5);

  n1.AddBiDirectionalAdjacency(n2,0);
  n1.AddBiDirectionalAdjacency(n4,0);
  n2.AddBiDirectionalAdjacency(n3,0);
  n3.AddBiDirectionalAdjacency(n5,0);
  n5.AddBiDirectionalAdjacency(n2,0);

  n1.print();
  n2.print();
  n3.print();
  n4.print();
  n5.print();

  cout << endl << "Depth First Search:" << endl;
  dfs(n1);
}
