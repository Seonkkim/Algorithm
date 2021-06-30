#include <bits/stdc++.h>
using namespace std;

int board[10][10];
bool check[10];


void row_check(){
	for(int i=0;i<9;i++){
		if(check[i]!=true)
	}
}

void col_check(){
	
}

void square_check(){
	
}


void sudoku(){
	
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	for(int i=0;i<9;i++){
		for(int j=0;j<9;i++){
			if(board[i][j]==0) sudoku();
		}
	}
	
	return 0;
}