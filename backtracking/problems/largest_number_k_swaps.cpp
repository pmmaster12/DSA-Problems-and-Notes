#include <bits/stdc++.h>
using namespace std;
using namespace chrono;
#define int long long
#define endl '\n'
const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int getRandomNumber(int l, int r) { return uniform_int_distribution<int>(l, r)(rng); }

// Function to find the largest number after k swaps.
void solve(string &s, int k, string &ans, int ind)
{
    if (k == 0 or ind == s.size() - 1)
    {
        if (ans < s)
        {
            ans = s;
        }
        return;
    }
    for (int i = ind + 1; i < s.size(); i++)
    {
        char max_ele = *max_element(s.begin() + i, s.end());
        if (s[i] > s[ind] && s[i] == max_ele)
        {
            swap(s[ind], s[i]);
            solve(s, k - 1, ans, ind + 1);
            if (ans < s)
            {
                ans = s;
            }
            swap(s[ind], s[i]);
        }
    }
    solve(s, k, ans, ind + 1);
    return;
}
string findMaximumNum(string &s, int k)
{
    // code here.
    // pre computation storing largest element after each index in map
    string ans = "";
    solve(s, k, ans, 0);
    return ans;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int tc;
    cin >> tc;
    while (tc--)
    {
        // problem link - https://www.geeksforgeeks.org/problems/largest-number-in-k-swaps-1587115620/1
    }
}
