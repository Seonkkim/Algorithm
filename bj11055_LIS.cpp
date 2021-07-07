#include<bits/stdc++.h>
using namespace std;

int num;
int arr[1001];
int dp[1001];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int max_sum = 0;
	cin >> num;
	for(int i=0;i<num;i++) cin >> arr[i];
	dp[0] = 1;
	for(int i=0;i<num;i++){
		for(int j=0;j<i;j++){
			if(arr[j]<arr[i])
			dp[i]=max(dp[i],dp[j]+arr[i]);
		}
		max_sum = max(dp[i],max_sum);
	}
	cout << max_sum;
	
	return 0;
}