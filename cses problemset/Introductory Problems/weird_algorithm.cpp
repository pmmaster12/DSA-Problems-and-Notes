#include <bits/stdc++.h>
using namespace std;
using namespace chrono;
#define int long long
#define endl '\n' 
const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int getRandomNumber(int l, int r) {return uniform_int_distribution<int>(l, r)(rng);}
signed main() {
ios::sync_with_stdio(false); cin.tie(NULL);
    int n ;
    cin>>n;
    cout<<n<<" ";
    while(n!=1){
        if(n%2==0){
            n= n/2;
            cout<<n<<" ";
        }
        else{
            n = n*3+1;
            cout<<n<<" ";
        }
    }
}