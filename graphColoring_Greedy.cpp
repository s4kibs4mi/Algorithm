// Graph Coloring Greedy Algorithm
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<vector>

using namespace std;

void ColorGraph(){
	vector < vector <bool> > graph;
	vector < int> colored;
	int n,e,u,v;
	cout << "Number of vertex : ";
	cin >> n;
	
	for(int i=0;i < n; i++){ // Making 2D Array using vector
		vector <bool> row;
		graph.push_back(row); // Increasing the row size
	}
	for(int i=0;i < n; i++){
		for(int j=0;j < n; j++)
			graph[i].push_back(false); // Making All vertex connectivity False
	}
	for(int i=0;i < n; i++) colored.push_back(-1);
	
	cout << "Number of Edges : ";
	cin >> e;
	for(int i=0;i < e; i++){ // Taking Edges && Connecting vertexes
		cin >> u >> v;
		graph[u][v] = true;
		graph[v][u] = true;
	}
	for(int i=0;i < n; i++){
		int color = 0;
		for(int j=0;j < n;j++){
			if(graph[i][j] && colored[j]==color) // Checking Adjcency && Adjecent vertex color
				color++;
		}
		colored[i] = color; // Selecting color
	}
	for(int i=0;i < n; i++){ // Printing Output
		cout <<"vertex " << i << " colored with " << colored[i] << " color." << endl;
	}
}

int main(){
	ColorGraph(); // Calling Graph Coloring Function
	return 0;
}
