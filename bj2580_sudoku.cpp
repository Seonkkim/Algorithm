#include <bits/stdc++.h>
using namespace std;

int board[10][10];
vector<pair<int,int>> blank;
int end_cnt=0;
bool found = false;
bool check(pair<int,int> b){
	int x = b.first/3;
	int y = b.second/3;
	
	for(int i=0;i<9;i++){
		if(board[b.first][i]==board[b.first][b.second] && i != b.second)
		return false;
		if(board[i][b.second]==board[b.first][b.second] && i != b.first)
		return false;
	}
	for(int i=3*x; i < 3*x+3; i++){
		for(int j = 3*y; j < 3*y+3; j++){
			if(board[i][j]==board[b.first][b.second]){
				if(i != b.first && j != b.second) return false;
			}
		}
	}	
		
	return true;
}

void sudoku(int cnt){
	if(cnt == end_cnt){
	found = true;
	return;
	}
	
	for(int i=1;i<=9;i++){
	board[blank[cnt].first][blank[cnt].second] = i;
	if(check(blank[cnt])) sudoku(cnt+1);
	if(found) return; 
	}
    board[blank[cnt].first][blank[cnt].second] = 0;
    return;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	for(int i=0;i<9;i++){
		for(int j=0;j<9;j++){
			cin >> board[i][j];
			if(board[i][j]==0) 
			blank.push_back({i,j});
		}
	}
	end_cnt = blank.size();
	sudoku(0);
	
	for(int i=0;i<9;i++){
		for(int j=0;j<9;j++){
			cout << board[i][j] << ' ';
		}
		cout << '\n';
	}
	
	return 0;
}