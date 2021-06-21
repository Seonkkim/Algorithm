#include <bits/stdc++.h>
using namespace std;
int N,M;
string board[11];
int visit_r[M][N];
int visit_b[M][N];
int dy[4]={0,1,0,-1};
int dx[4]={1,0,-1,0};
int bx,by;
pair<int,int> red;
pair<int,int> blue;
void bfs_r(){ // int bfs return cnt?
	stack<pair<int,int>> q;
	q.push(red);
	visit[red.first][red.second] = true;
	int cnt = 0;
	while(!q.empty()){
		auto cur = q.front(); q.pop();
		for(int d=0;d<4;d++){
			int ny = cur.first + dy[d];
			int nx = cur.second + dx[d];
			if(board[ny][nx]=='O') return cnt;
			if(ny<0||ny>M||nx<0||nx>N) continue;
			if(board[ny][nx]=='#'||visit[ny][nx]||board[ny][nx]=='B') continue;
			q.push({ny,nx});
			visit[ny][nx] = true;
			if(board[by][bx])
		}
	}
}

void bfs_b(){
	stack<pair<int,int>> q;
	q.push(blue);
	visit[blue.first][blue.second] = true;
	int cnt = 0;
	while(!q.empty()){
		auto cur = q.front(); q.pop();
		for(int d=0;d<4;d++){
			int ny = cur.first + dy[d];
			int nx = cur.second + dx[d];
			if(board[ny][nx]=='O') return cnt;
			if(ny<0||ny>M||nx<0||nx>N) continue;
			if(board[ny][nx]=='#'||visit[ny][nx]) continue;
			q.push({ny,nx});
			visit[ny][nx] = true;
			
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;
	for(int i=0;i<M;i++){
		cin >> board[i];
	}
	
	for(int i=0;i<M;i++){
		for(int j=0;j<N;j++){
			if(board[i][j]=='R'){
				red = {i,j};
			}
			if(board[i][j]=='B'){
				blue = {i,j};
			}
		}
	}
	
	return 0;
}