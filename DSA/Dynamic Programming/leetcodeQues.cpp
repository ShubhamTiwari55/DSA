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
    int f(vector<int> arr, int i){
        if(i==arr.size()-1) return arr[i];
        if(i==arr.size()-2) return max(arr[i], arr[i+1]);

        if(dp[i]!=-1) return dp[i];
        return dp[i] = max((arr[i]+f(arr,i+2)),(0+f(arr,i+1)));
    }
    int rob(vector<int>& nums) {
       dp.clear();
       dp.resize(105,-1);
       return f(nums,0);
    }
};

int main(){
}