#include <iostream>
#include <vector>
#include <queue>

const int MAXN = 1e5 + 5;

int n, m;//the number of circuit intersection/the number of 'edges'(wires)
int s, t;//the in point and the exit point 
struct edge{
	int v;
	double w;
};
std::vector<edge> G[MAXN], G2[MAXN];//the original circuits(undirected)/the actual circuit
std::queue<int> Q;//to create an directed graph
int vis[MAXN];//to note the bfs order of each intersection
std::queue<int> T;//topology's queue
int in[MAXN];//the indegree in the actual graph
double R[MAXN];//the equivalent resistance from s to i

void Bfs(){//to create the actual circuit
	vis[s] = 1;
	Q.push(s);
	while(!Q.empty()){
		int u = Q.front();
		Q.pop();
		if(u == t){
			continue;
		}
		for(int i = 0; i < G[u].size(); ++i){
			int v = G[u][i].v;
			double w = G[u][i].w;
			//if the bfs order of two intersection is the same, then there's no current in it
			if(vis[v] == vis[u]){
				continue;
			}
			if(vis[v] == 0){//first time
				vis[v] = vis[u] + 1;
				Q.push(v);
			}
			G2[u].push_back(edge{v, w});//the new graph describe the direction of current
		}
	}
	return;
}

double Inv(double x){
	return (1.00 / x);
}

void Topo(){
	while(!T.empty()){
		int u = T.front();
		T.pop();
		for(int i = 0; i < G2[u].size(); ++i){
			int v = G2[u][i].v;
			double w = G2[u][i].w;
			--in[v];
			R[v] += Inv(w);
			if(in[v] == 0){
				R[v] = Inv(R[v]);
				T.push(v);
			}
		}
	}
	return;
}

void Reads(){
	std::cin >> n >> m;
	int u, v;
	double w;
	for(int i = 1; i <= m; ++i){
		std::cin >> u >> v >> w;
		G[u].push_back(edge{v, w});
		G[v].push_back(edge{u, w});
	}
	std::cin >> s >> t;//in the current stage, I only consider circuits that has 1 in point and 1 exitpoint
	return;
}

void Solve(){
	Bfs();
	for(int i = 1; i <= n; ++i){
		for(int j = 0; j < G2[i].size(); ++j){
			int v = G2[i][j].v;
			++in[v];
		}
	}
	for(int i = 1; i <= n; ++i){
		if(in[i] == 0){
			T.push(i);
		}
	}
	Topo();
	return;
}

void Write(){
	std::cout << R[t];
	return;
}

int main(){
	freopen("Data.in", "r", stdin);
	freopen("Value.out", "w", stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	Reads();
	Solve();
	Write();
	return 0;
}
