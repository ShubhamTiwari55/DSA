#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
int dp[105][105][2];
    int f(int n, int k, int last){
        if(n==0) return 0;
        if(n==1){
            if(k==0) return 1;
            else return 0;
    }
        if(dp[n][k][last]!=-1) return dp[n][k][last];
        if(last==1){
            return dp[n][k][last] = f(n-1,k-1,1)+f(n-1,k,0);
        }
        else return dp[n][k][last] = f(n-1,k,1)+f(n-1,k,0);
    }
int main(){
    int t;
    cin>>t;
    while(t--){
        int num,n,k;
        cin>>num>>n>>k;
        memset(dp, -1, sizeof dp);
        int ans = f(n,k,1)+f(n,k,0);
        cout<<num<<" "<<ans<<endl;
    }
}