#include <bits/stdc++.h>
using namespace std;

int board[9][9];

void sudoku(pair<int,int> b){
	bool check_c[9]={false,};
	bool check_r[9]={false,};
	bool check_s[9]={false,};
	
	for(int i=0;i<9;i++){
		if(!check_r[board[b.first][i]]) 
	}
	
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	vector<int,int> blank;
	for(int i=0;i<9;i++){
		for(int j=0;j<9;i++){
			if(board[i][j]==0) 
			blank.push_back({i,j});
		}
	}
	
	
	
	return 0;
}