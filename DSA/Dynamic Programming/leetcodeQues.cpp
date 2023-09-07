#include<iostream>
#include<vector>
using namespace std;

//leetcode ques no. 386 -> Lexicographical numbers
class Solution {
public:
    vector<int> result;
    void f(int i, int n){
        if(i>n) return;

        if(i<=n && i!=0){
            result.push_back(i);
        }
        if(i!=0){
            for(int j=0;j<=9;j++){
                f(10*i+j,n);
            }
        }else{
            for(int j=1;j<=9;j++){
                f(10*i+j,n);
            }
        }
    }
    vector<int> lexicalOrder(int n) {
        f(0,n);
        return result;
    }
};

//leetcode ques no. 198 -> House Robber
//https://leetcode.com/problems/house-robber/description/
class Solution {
public:
    vector<int> dp;
    int fTopDown(vector<int> arr, int i){
        if(i==arr.size()-1) return arr[i];
        if(i==arr.size()-2) return max(arr[i], arr[i+1]);

        if(dp[i]!=-1) return dp[i];
        return dp[i] = max((arr[i]+fTopDown(arr,i+2)),(0+fTopDown(arr,i+1)));
    }

    int fBottomUp(vector<int> &arr){
        int n = arr.size();
        dp.clear();
        dp.resize(n);
        //base case
        dp[n-1] = arr[n-1];
        dp[n-2] = max(arr[n-2],arr[n-1]);
        for(int i=n-3;i>=0;i--){
            dp[i] = max(arr[i]+dp[i+2],0+dp[n-1]);
        }
        return dp[0];
    }

    int rob(vector<int>& nums) {
       dp.clear();
       dp.resize(105,-1);
       return fTopDown(nums,0);
       //return fBottomUP(nums);    //iterative solution using recurrence relation
    }
};

//leetcode ques no. 1155 -> Number of dice rolls with target sum
//https://leetcode.com/problems/number-of-dice-rolls-with-target-sum/submissions/
#define mod 1000000007
class Solution {
public:
//As there are two parameters changing so we need to use a 2d vector//
    vector<vector<int>>dp;
    int f(int n, int k, int t){
        if(n==0 && t==0) return 1;
        if(n==0) return 0;
        if(dp[n][t]!=-1) return dp[n][t];
        int sum = 0;
        for(int i=1;i<=k;i++){
            if(t-i<0) continue;
            sum = (sum%mod + f(n-1,k,t-i)%mod)%mod;
        }
        return dp[n][t]=sum%mod;
    }
    int numRollsToTarget(int n, int k, int target) {
        dp.clear();
        dp.resize(36,vector<int>(1007,-1));
        return f(n,k,target);
    }
};
int main(){
}