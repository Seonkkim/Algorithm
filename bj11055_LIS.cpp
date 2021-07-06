#include <bits/stdc++.h>
using namespace std;
int num, arr[1001];
int dp[1001];
int max_sum;

int main(){
	cin >> num;
	for(int i=0;i<num;i++){
		cin >> arr[i];
	}
	for(int i=0;i<num;i++){
		for(int j=0;j<i;j++){
			if(arr[j] < arr[i])
				dp[i] = max(dp[j]+arr[i],dp[i]);
		}
		max_sum = max(dp[i],max_sum);
	}
	
	cout << max_sum;
	return 0;
}

