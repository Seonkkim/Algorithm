#include <bits/stdc++.h>
using namespace std;
int k,w,h;
int board[201][201];
int vis[201][201] = {-1,};
int kx[8] = {1,2,2,1,-1,-2,-2,-1};
int ky[8] = {-2,-1,1,2,2,1,-1,-2};
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};


int monkey(){
	queue<pair<int,int>> q;
	q.push({0,0});
	vis[0][0]++;
	while(!q.empty()){
		auto cur = q.front();
		if(cur.first==h-1&&cur.second==w-1) return vis[cur.first][cur.second];

		q.pop();
		if(k!=0){
			for(int d=0;d<7;d++){
				int nx = cur.second + kx[d];
				int ny = cur.first + ky[d];
				if(nx<0||nx>w||ny<0||ny>h) continue;
				if(board[ny][nx]==1||vis[ny][nx]>0) continue;
				vis[ny][nx] = vis[cur.first][cur.second]+1;
				q.push({ny,nx});
			}
			k--;
		}
		else{
			for(int d=0;d<4;d++){
				int nx = cur.second + dx[d];
				int ny = cur.first + dy[d];
				if(nx<0||nx>w||ny<0||ny>h) continue;
				if(board[ny][nx]==1||vis[ny][nx]>0) continue;
				vis[ny][nx] = vis[cur.first][cur.second]+1;
				q.push({ny,nx});
			}
		}
	/*	cout << '\n';
	
	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++){
			cout << vis[i][j] << ' ';	
		}
		cout << '\n';
	}*/
	
		
	}
	if (vis[h-1][w-1]<=0) return -1;
	return 0;
}

int main(){
	
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