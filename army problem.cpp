// In this we were given an array of powers and we had to choose numbers into two armies (not necessarily all numbers be chosen) such that the sum of two armies got equal. If not possible return 0;  
#include<iostream>
#include<vector>
#include<algorithm>   // max({a,b,c}) ke lie h
using namespace std;
// int f(int i,int t,vector<int>&nums,vector<vector<int>>&memo){
// 	if(i==0){
// 		if(t==0) return 1 + (nums[0]==t);
// 		return nums[0]==t;
// 	}
// 	if(memo[i][t]!=-1) return memo[i][t];
// 	int npick = f(i-1,t,nums,memo);
// 	int pick =0;
// 	if(t>=nums[i]) pick = f(i-1,t-nums[i],nums,memo);
// 	return memo[i][t]=pick + npick;
// }
int f(int i,int s1,int s2,auto &nums,auto &memo){
	if(i==0){
		if(s1==s2) return s1;
		else if (s1-s2== nums[0]) return s1;
		else if (s2-s1== nums[0]) return s2;
		return -1;
	}
	if(memo[i][s1][s2]!=-1) return memo[i][s1][s2];
	int a=f(i-1,s1+nums[i],s2,nums,memo);
	int b=f(i-1,s1,s2+nums[i],nums,memo);
	int c=f(i-1,s1,s2,nums,memo);
	return memo[i][s1][s2]=max({a,b,c});
}
int main(){
	vector<int> nums = {1,1,1,1,1,1000};
	int n=nums.size();
	// int s1,s2;
	// s1=s2=0;
	int tot=0;
	for(int i:nums) tot+=i;
	// vector<vector<vector<int>>> memo(tot,vector<vector<int>> (tot,vector<int>(tot+1,-1)));
	// cout<<f(n-1,s1,s2,nums,memo)<<endl;
	vector<vector<vector<int>>> memo(n,vector<vector<int>> (tot+1,vector<int>(tot+1,0)));
	for(int i=0;i<=tot;i++){
		for(int j=0;j<=tot;j++){
			if(i==j) memo[0][i][j]= i;
			else if (i-j== nums[0]) memo[0][i][j]= i;
			else if (j-i== nums[0]) memo[0][i][j]= j;
		}
	}
	for(int i=1;i<n;i++){
		for(int s1=0;s1<=tot;s1++){
			for(int s2=0;s2<=tot;s2++){
				int a=memo[i-1][s1+nums[i]][s2];
				int b=memo[i-1][s1][s2+nums[i]];
				int c=memo[i-1][s1][s2];
				memo[i][s1][s2]=max({a,b,c});
			}
		}
	}
	return memo[0][0][0];
}
