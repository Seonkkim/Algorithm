#include <bits/stdc++.h>
using namespace std;

int board[9][9];
vector<pair<int,int>> blank;
bool check(pair<int,int> b){
	int x = b.first/3;
	int y = b.second/3;
	
	for(int i=0;i<9;i++){
		if(board[b.first][i]==board[b.first][b.second] && i != b.second)
		return false;
		if(board[i][b.second]==board[b.first][b.second] && i != b.first)
		return false;
	
	for(int i=3*x; i < 3*x+3; i++){
		for(int j = 3*y; j < 3*y+3; j++){
			if(board[i][j]==board[b.first][b.second]){
				if(i != b.first && j != b.second) return false;
			}
		}
	}	
		
	}
	return true;
}

void sudoku(int n){
	if(n == cnt){
		for(int i=0;i<9;i++){
			for(int j=0;j<9;j++)
			cout << board[i][j] << ' ';
		cout << '\n';
		}
		flag = true;
		return;
	}
	for(int j = 1; j <= 9; j++){
		board[p]
	}
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	for(int i=0;i<9;i++){
		for(int j=0;j<9;i++){
			if(board[i][j]==0) 
			blank.push_back({i,j});
		}
	}
	
	for(int i=0;i<blank.size();i++){
		sudoku(blank[i]);
	}
	
	return 0;
}