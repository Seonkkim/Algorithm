#include <bits/stdc++.h>
using namespace std;
#define MAX 201
int k,w,h;
int board[MAX][MAX];
bool vis[MAX][MAX][31];
int kx[8] = {1,2,2,1,-1,-2,-2,-1};
int ky[8] = {-2,-1,1,2,2,1,-1,-2};
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};


int monkey(){
	queue<pair<pair<int,int>,pair<int,int>>> q;
	q.push({{0,0},{0,0}});
	vis[0][0][0]=true;
	while(!q.empty()){
		auto cur = q.front();
		int y = cur.first.first;
		int x = cur.first.second;
		int cnt = cur.second.first;
		int k_cnt = cur.second.second;
		q.pop();
		if(y==h-1&&x==w-1) return cnt;

		if(k>k_cnt){
			for(int d=0;d<7;d++){
				int nx = x + kx[d];
				int ny = y + ky[d];
				if(nx<0||nx>w||ny<0||ny>h) continue;
				if(board[ny][nx]==1||vis[ny][nx][k_cnt]) continue;
				vis[ny][nx][k_cnt+1] = true;
				q.push({{ny,nx},{cnt+1,k_cnt+1}});
			}
		}
		
		for(int d=0;d<4;d++){
			int nx = x + dx[d];
			int ny = y + dy[d];
			if(nx<0||nx>w||ny<0||ny>h) continue;
			if(board[ny][nx]==1||vis[ny][nx][k_cnt]) continue;
			vis[ny][nx][k_cnt+1] = true;
			q.push({{ny,nx},{cnt+1,k_cnt}});
		}

	/*	
	cout << '\n';
	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++){
			cout << vis[i][j] << ' ';	
		}
		cout << '\n';
	}
*/	
	}
	return -1;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> k;
	cin >> w >> h;
	
	for(int i=0;i<h;i++)
	for(int j=0;j<w;j++) cin >> board[i][j];
	
	
	cout << monkey() << '\n'; 
	
	/*
	
	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++){
			cout << board[i][j] << ' ';	
		}
		cout << '\n';
	}
	cout << '\n';
	
	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++){
			cout << vis[i][j] << ' ';	
		}
		cout << '\n';
	}
	*/
	return 0;
}