#include <bits/stdc++.h>
using namespace std;
using namespace chrono;
#define int long long
#define endl '\n' 
const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int getRandomNumber(int l, int r) {return uniform_int_distribution<int>(l, r)(rng);}
// User function Template for C++

    void solve(int n , vector<int>&ans ,vector<int>&temp){
        if(n==0){
            int num = 0;
            for(auto i:temp){
                num=num*10+i;
            }
            ans.push_back(num);
            return;
        }
        
        for(int i=1;i<10;i++){
            if(temp.empty() or i>temp[temp.size()-1] ){
                temp.push_back(i);
                solve(n-1,ans,temp);
                temp.pop_back();
            }
        }
        return;
    }
    vector<int> increasingNumbers(int n) {
        // Write Your Code here
        vector<int>ans;
        vector<int>temp;
        if(n==1){
            for(int i=0;i<10;i++)
                ans.push_back(i);
            return ans;
        }
        
        solve(n,ans,temp);
        return ans;
    }

signed main() {
ios::sync_with_stdio(false); cin.tie(NULL);

 int tc; cin >> tc;
while (tc--) {
    //problem link - https://www.geeksforgeeks.org/problems/n-digit-numbers-with-digits-in-increasing-order5903/1
 }
}