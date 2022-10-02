/*
	Given the number of vertices. edges of a grapth, source and destination, find the shortest distance between source and destination if possible.
*/

#include<bits/stdc++.h>

using namespace std;

int dijkstra(int v, vector<vector<int> > &edges, int src, int dst) {
	vector<vector<pair<int,int> > > adj(v+1);	// Adjacency List
	for(auto i: edges) {
		adj[i[0]].push_back({i[1],i[2]});
		adj[i[1]].push_back({i[0],i[2]});
	}

	bool vis[v+1];			// Visited Vertices
	memset(vis,0,sizeof(vis));
	priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > pq;	// Finding Shortest Available Route
	pq.push({0,src});

	while(pq.size()) {
		pair<int,int> t = pq.top();
		pq.pop();
		int d = t.first, u = t.second;
		vis[u] = true;
		if(u == dst) return d;	// Return Shortest Distance if destination is found

		for(auto v: adj[u]) {
			// Add Unvisited Vertices to Priority Queue
			if(!vis[v.first]) {
				pq.push({d + v.second, v.first});
			}
		}
	}

	// Return -1 if path not found
	return -1;
}


// Driver Code
int main() {
	cout<<"Number of Vertices: ";
	int v;
	cin>>v;
	cout<<"Number of Edges: ";
	int e;
	cin>>e;
	vector<vector<int> > edges;
	for(int i=0;i<e;i++) {
		// Vertex 1, Vertex 2, Weight of Edge
		int u,v,w;
		cin>>u>>v>>w;
		edges.push_back({u,v,w});
	}

	cout<<"Source: ";
	int src;
	cin>>src;
	cout<<"Destination: ";
	int dst;
	cin>>dst;

	cout<<"Shortest Distance: "<<dijkstra(v, edges, src, dst);
	return 0;
}
