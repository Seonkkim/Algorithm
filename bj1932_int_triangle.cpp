#include <bits/stdc++.h>
using namespace std;
 
vector<int> v[500];
int n;
int input;
int sum;
int flag;
 
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
 
	cin >> n;
	int cnt = 0;
	for(int i=0;i<n;i++) {
		cnt++;
		for(int j=0;j<cnt;j++){
			cin >> input;
			v[i].push_back(input);
		}
 
	}
 
	for(int i=0;i<n;i++) {
	 for(int j=0;j<v[i].size();j++){
	 	cout << v[i][j];
	 }
	 cout << '\n';
	}
	for(int i=0;i<n;i++){
		if(i==0){
			sum += v[i][0];
			flag = 0;
			continue;
		}
		if(max(v[i][flag],v[i][flag+1])==v[i][flag]){
			sum += v[i][flag];
		}
		else{
			sum += v[i][flag+1];
			flag = flag+1;
		}
		cout << max(v[i][flag],v[i][flag+1]) << ' ';
		cout << "sum:"<<sum<<' ';
	}
	cout << sum;
 
	return 0;
} //t