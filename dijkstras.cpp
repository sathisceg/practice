#include<bits/stdc++.h>

using  namespace std;

#define INF 0x3f3f3f3f


void add_edge(vector<pair<int,int>> adj[],int u,int v,int w){

	adj[u].push_back({v,w});
	adj[v].push_back({u,w});
}

void graph_nodes(vector<pair<int,int>> adj[],int v){

	    for(int i=0;i<v;i++){
    		cout<<i<<endl;    	
    		for(auto t:adj[i]){
    			cout<<t.first<<"  "<<t.second<<endl;
    		}
    	cout<<"############";
    	cout<<endl;
    }
}

void shortest_path(vector<pair<int,int>> adj[],int v){

	vector<int> dist(v,INF);

	int src = 0;

	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

	dist[src]=0;

	pq.push({0,src});

	while(!pq.empty()){
		auto t  = pq.top();
		pq.pop();
		int u = t.second;

		for(auto x:adj[u]){

			int v = x.first;
			int w = x.second;

			if(dist[v] > dist[u]+w){
				pq.push({dist[u]+w,v});
				dist[v] = dist[u]+w;
			}
		}
	}

	for(int i=0;i<v;i++){
		cout<<i<<"  "<<dist[i]<<endl;
	}


}


int main(){

	int v=9;

	vector<pair<int,int>> adj[v];

    add_edge(adj, 0, 1, 4);
    add_edge(adj, 0, 7, 8);
    add_edge(adj, 1, 2, 8);
    add_edge(adj, 1, 7, 11);
    add_edge(adj, 2, 3, 7);
    add_edge(adj, 2, 8, 2);
    add_edge(adj, 2, 5, 4);
    add_edge(adj, 3, 4, 9);
    add_edge(adj, 3, 5, 14);
    add_edge(adj, 4, 5, 10);
    add_edge(adj, 5, 6, 2);
    add_edge(adj, 6, 7, 1);
    add_edge(adj, 6, 8, 6);
    add_edge(adj, 7, 8, 7);

    // graph_nodes(adj,v);

    shortest_path(adj,v);
	
	return 0;
}
