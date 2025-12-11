#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;
signed main() {
ios::sync_with_stdio(false); cin.tie(NULL);
 int tc; cin >> tc;
while (tc--) {
 int n, s, r;
        cin >> n >> s >> r;
        int a[n];
        int k = 1;
        a[0] = s - r;
        int p;
        if (r % 2 != 0 or n % 2 != 0)
            p = r / n + 1;
        else
            p = r / n;
        int sum = a[0];
        for (int i = 1; i < n - 1; i++)
        {

            a[i] = p;
            sum = sum + a[i];
        }
        a[n - 1] = s - sum;
        if(a[n-1]>a[0])
        a[n-1]--;
        a[n-2]++;
        for (int i = 0; i < n; i++)
        {

            cout << a[i] << " ";
        }
        cout << endl;
 }
}