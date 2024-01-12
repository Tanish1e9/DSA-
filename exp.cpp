#include<iostream>
#include<vector>
using namespace std;
long f(int i,int k,vector<int>&arr,auto &memo){
	if(i+1<k) return 0;
	if(k==1) {
		long sum=0;
		for(int j=0;j<=i;j++){
			sum += arr[j];
		}
		return sum;
	}
	if(memo[i][k]!=-1) return memo[i][k];
	long pick = arr[i] * f(i-1,k-1,arr,memo);
	long npick = f(i-1,k,arr,memo);
	return memo[i][k]=pick + npick;
}
int main(){
	vector<int> arr;
	for(int i=1;i<=1e3;i++) arr.push_back(i);
	int k=3;
	// vector<vector<long>> memo(arr.size(),vector<long>(k+1,-1));
	// cout<<f(arr.size()-1,k,arr,memo)<<endl;
	vector<long> prev(k+1,0);
	prev[0] = 1;
	prev[1] = arr[0];
	for(int i=1;i<arr.size();i++){
		for(int x=k;x>=1;x--){
			if(i+1<x) prev[x]=0;
			long pick = arr[i] * prev[x-1];
			long npick=0;
			if(i+1>=x) npick = prev[x];
			prev[x]=pick + npick;
		}
	}
	cout<<prev[k];
}