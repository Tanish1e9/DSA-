//Basically we were given 2 strings we had to find such common subsequence of length k which had the maximum sum possible of their ASCII values
#include<bits/stdc++.h>
using namespace std;
int solve(int i,int j,string&s1,string&s2,int k,vector<vector<vector<int>>>& memo){
    if(k==0) return 0;
    if(i<0 || j<0) return -1e9;
    if(memo[i][j][k]!=-1) return memo[i][j][k];
    if(s1[i]==s2[j]){
        int a=solve(i-1,j-1,s1,s2,k,memo);
        return memo[i][j][k]=max({s1[i]+solve(i-1,j-1,s1,s2,k-1,memo),a});
    }
    return memo[i][j][k]=max({solve(i-1,j,s1,s2,k,memo),solve(i,j-1,s1,s2,k,memo)});
}
int main(){
    int t;
    cin>>t;
    while(t--){
        string s1,s2;
        cin>>s1>>s2;
        int k;
        cin>>k;
        vector<vector<vector<int>>> memo(s1.size(),vector<vector<int>>(s2.size(),vector<int>(k+1,-1)));
        cout<<max(0,solve(s1.size()-1,s2.size()-1,s1,s2,k,memo))<<endl;
    }
    return 0;
}
