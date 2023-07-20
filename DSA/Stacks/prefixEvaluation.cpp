#include<iostream>
#include<stack>
#include<string>
using namespace std;
int solve(int v1, int v2, char ch){
    if(ch=='+') return v1+v2;
    else if(ch=='-') return v1-v2;
    else if(ch=='*') return v1*v2;
    else return v1/v2;
}
int main(){
    string s = "-/*+26483";
    stack<int> val;
    stack<char> op;
    for(int i=s.length()-1;i>=0;i--){    
         //same as postfixEvaluation but in this we are just travelling in reverse order by using this for loop!
        if(s[i]>=48 && s[i]<=57) val.push(s[i]-48);
        else{
           int val1 = val.top();
           val.pop();
           int val2 = val.top();
           val.pop();
           int ans = solve(val1,val2,s[i]);
           val.push(ans);
     }
}
cout<<val.top();
}