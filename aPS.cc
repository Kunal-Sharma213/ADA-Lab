#include<iostream>
#include<vector>
using namespace std;

#define INF INT_MAX

vector<vector<int> > floyd_warshall(vector<vector<int> > graph){

	vector<vector<int> > dist(graph);

	int V = graph.size();

	for(int k=0;k<V;k++){
		for(int i=0;i<V;i++){
			for(int j=0;j<V;j++){
				if(dist[i][j] > dist[i][k] + dist[k][j]){
					dist[i][j] = dist[i][k] + dist[k][j];
				}
			}

		}
	}
	return dist;
}


int main(){

	freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	for(int i = 0; i < 30; i++){
	int n,m;
	cin >> n >> m;
	vector<vector<int> > graph ;
	graph.resize(n, vector<int>(n,INF));
	for(int i=0;i<m;i++){
		int x,y,w;
		cin >> x >> y>>w;
		graph[x][y] = w;
	}

    auto start = chrono::steady_clock::now();
	auto result = floyd_warshall(graph);
    auto end = chrono::steady_clock::now();
    cout << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << "," << '\n';

	// for(int i=0;i<result.size();i++){
	// 	for(int j=0;j<result.size();j++){
	// 		cout<<result[i][j]<<" ";
	// 	}
	// 	cout<<endl;
	// }

	}
}
