#include <bits/stdc++.h>
using namespace std;

int mapp[101][101];
int n,m;
bool vis[n];

int bfs(int num){ // look n;
	queue<int> q;
	vis[num]=true;
	for(int i=0;i<n;i++){
	if(vis[n]) continue;
	q.push(i); vis[i]=true;
	while(!q.empty()){
		auto cur = q.front(); q.pop();
		
		}
	}
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	int a,b;
	for(int i=0;i<m;i++){
		cin >> a >> b;
		map[a][b] = 1;
		map[b][a] = 1;
	}
	
	while(){
		
	}
	
	return 0;
}