// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>>dp;

int lcs(vector<int>&a, vector<int>&b , int i1 , int i2){
    int n = a.size();
    int m = b.size();
    if(i1==n || i2==m)
        return 0;
    if(dp[i1][i2]!=-1)
        return dp[i1][i2];
    if(a[i1]==b[i2])
        return 1 + lcs(a,b,i1+1,i2+1);
    else{
        return max(lcs(a,b,i1,i2+1),lcs(a,b,i1+1,i2));
    }
    return 0;
}

int main() {
    int n,m;
    cin>>n>>m;
    vector<int>a(n),b(m);
    
    for(int i =0;i<n;i++){
        cin>>a[i];
    }
    for(int i =0;i<n;i++){
        cin>>b[i];
    }
    dp.assign(n+1,vector<int>(m+1,0));
    for(int i =n-1;i>=0;i--){
        for(int j =m-1;j>=0;j--){
            if(a[i]==b[j]){
                dp[i][j] = 1 + dp[i+1][j+1];
            }
            else{
                dp[i][j] = max(dp[i+1][j],dp[i][j+1]);
            }
        }
    }
    cout<<"size of lcs stribn : -"<<dp[0][0]<<endl;
    
    vector<int>ans;
    
    int i = 0, j =0;
    while(i<n && j<m){
        if(a[i]==b[j]){
            ans.push_back(a[i]);
            i++;
            j++;
        }
        else{
            if(dp[i+1][j]>dp[i][j+1])
                i++;
            else
                j++;
        }
    }
    cout<<"the actual lcs vector"<<endl;
    for(auto x: ans){
        cout<<x<<" ";
    }
    // this is how can print the code
    return 0;
}