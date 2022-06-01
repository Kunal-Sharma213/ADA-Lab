#include <bits/stdc++.h>
using namespace std;

void printSolution(int color[], int);
bool isSafe(int v, vector<vector<int>> &graph,
			int color[], int c)
{
  int V = graph.size();
	for(int i = 0; i < V; i++)
		if (graph[v][i] && c == color[i])
			return false;
			
	return true;
}

bool graphColoringUtil(vector<vector<int>> &graph, int m,
					int color[], int v)
{
	int V = graph.size();
	if (v == V)
		return true;

	for(int c = 1; c <= m; c++)
	{
		
		if (isSafe(v, graph, color, c))
		{
			color[v] = c;

			if (graphColoringUtil(
				graph, m, color, v + 1))
				return true;

			color[v] = 0;
		}
	}
	return false;
}


bool graphColoring(vector<vector<int>> graph, int m)
{
  int V = graph.size();
	int color[V];
	for(int i = 0; i < V; i++)
		color[i] = 0;
	if (graphColoringUtil(graph, m, color, 0) == false)
	{
		cout << "Solution does not exist";
		return false;
	}

	// printSolution(color,V);
	return true;
}
void printSolution(int color[], int V)
{
	cout << "Solution Exists:"
		<< " Following are the assigned colors"
		<< "\n";
	for(int i = 0; i < V; i++)
		cout << " " << color[i] << " ";
		
	cout << "\n";
}
int main()
{
  int n,m, c;
  cin >> n >> m >> c;
  vector<vector<int>> graph;
  graph.resize(n, vector<int>(n,0));
	
  for(int i = 0; i < m; i++){
    int x,y;
    cin >> x >> y;
    graph[x][y] = 1;
    graph[y][x] = 1;
  }
	graphColoring(graph, c);
	return 0;
}

