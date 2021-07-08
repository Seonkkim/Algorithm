#include <bits/stdc++.h>
using namespace std;
int n,m;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int mapp[1001][1001];
bool vis[1001][1001];
int flag=0;
int cnt =1;
int cnt_1 = 1;


int bfs(pair<int,int> init,int cnt){
	
	queue<pair<int,int>> q;
	q.push(init); vis[init.first][init.second]=true;
	while(!q.empty()){
		auto cur = q.front(); q.pop();
		for(int d=0;d<4;d++){
		int ny = cur.first + dy[d];
		int nx = cur.second + dx[d];
		if(nx<0||nx>m||ny<0||ny>n||vis[ny][nx]||mapp[ny][nx] == 1) continue;
		/*if(mapp[ny][nx]==1 && flag==0){
			flag = 1;
			cout << "work plz";
			bfs({ny,nx},cnt_1);
		}*/
		//if() continue;
		vis[ny][nx]=true;
		q.push({ny,nx});
		cout << '{' << ny << ' ' << nx << '}';
		cnt++;
		}
	}
	return cnt;
	}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin >> mapp[i][j];
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
		cout << mapp[i][j] << ' ';
		}
		cout << '\n';
	}
	cout << bfs({0,0},cnt);
	
	return 0;
}