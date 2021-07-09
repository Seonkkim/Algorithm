#include <bits/stdc++.h>
using namespace std;

int dp[10001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	
	cin >> T;
	int inp[T]={0,};
	for(int i=0;i<T;i++) cin >> inp[i];	
	
	for(int t=0;t<T;t++)
	for(int i=4;i<=inp[t];i++){
		dp[i] = dp[i-1]+dp[i-2]+dp[i-3];
	}
	for(int i=0;i<T;i++){
		cout << dp[inp[i]] << '\n';
	}
	
	return 0;
}