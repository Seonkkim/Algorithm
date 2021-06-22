#include <bits/stdc++.h>
using namespace std;
int N,M;
string board[11];
bool visit[11][11][11][11];
int dy[4]={0,1,0,-1};
int dx[4]={1,0,-1,0};
pair<int,int> red;
pair<int,int> blue;

int cnt; 

pair<int,int> go_straight(pair<int,int> p, int dir){
	int y = p.first;
	int x = p.second;
	while(board[y][x]!='#'||visit_b[y][x]!=cnt){
		y = y + dy[dir];
		x = x + dx[dir];
	}
	
	return {y-dy[dir],x-dx[dir]};
}

void bfs(){
	queue<pair<int,int>> rq;
	queue<pair<int,int>> bq;
	bq.push(blue);
	rq.push(red);
	visit_b[red.first][red.second][blue.first][blue.second] = true;
	
	while(!rq.empty()){

		auto rcur = rq.front(); rq.pop();
		auto bcur = bq.front(); bq.pop();

		if(board[rcur.first][rcur.second]=='O') return cnt;
		
		for(int d=0;d<4;d++){
			pair<int,int> r = go_straight(rcur,d);
			pair<int,int> b = go_straight(bcur,d);
			int ry = r.first;
			int rx = r.second;
			int by = b.first;
			int bx = b.second;
			/*
			if(rx == bx && ry == by){
				if(abs(ry-rcur.first)+abs(rx-rcur.second) > abs(by-bcur.first)+abs(bx-bur.second)){
					ry -= 
				}
			}*/
			
			if(board[ry][rx]=='#'||board[by][bx]=='#'||board[by][bx]=='O'||visit_b[ry][rx][by][bx]) continue;
			rq.push({ry,rx});
			bq.push({by,bx});
			visit_b[ry][rx][by][bx]=true;
			
			
		}
		if(cnt == 10) return -1;
		cnt++;
	}
	return -1;
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
	cout << bfs();
	
	return 0;
}