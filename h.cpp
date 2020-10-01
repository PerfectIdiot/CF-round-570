/*
author: Apoorv Singh
*/

#include <bits/stdc++.h>
using namespace std;

typedef vector <long long> vi;
typedef pair <long long, long long> pii;
#define pb push_back   
#define all(c) c.begin(), c.end()
#define FOR(i, a, b) for (long long i = a; i < b; ++i)
#define FORR(i, a, b) for (long long i = a; i > b; --i)
#define um unordered_map
#define F first
#define S second
#define int long long
#define inf LLONG_MAX
#define endl "\n"
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define _CRT_SECURE_NO_WARNINGS

#define TRACE
#ifndef ONLINE_JUDGE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
    cout << name << " : " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
    const char* comma = strchr(names + 1, ',');cout.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define trace(...)
#endif

template <class X>
void printarr(X arr[], int n)
{
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << endl;
}
template <typename X> ostream& operator << (ostream& x,const vector<X>& v){ for (X a : v) x << a << ' '; return x;} 
template <typename X, typename Y> ostream& operator << (ostream& x, const vector< pair<X, Y> >& v) {for (pair <X, Y> it : v) x << it.first << ' ' << it.second << endl; return x;} 
template <typename T, typename S> ostream& operator << (ostream& os, const map<T, S>& v) { for (pair <T, S> it : v) os << it.first << " => " << it.second << endl; return os; }

double pi = 3.14159265358979323846264338327950288419716939937510582097494459230;
int modulo = 1e9 + 7;

int fpow(int a, int n)
{
    int ans = 1;
    while (n)
    {
        if (n&1)
            ans = (ans * a)%modulo;
        a = (a*a)%modulo;
        n = n >> 1;
    }
    return ans;
}

/*
const int M = 1e6 + 10;
int composite[M] = {0};

void sieve()
{
    FOR(i,2,M)
    {
        if (!composite[i])
        {
            for (int j = 2*i; j < M; j += i)
                composite[j] = max(composite[j], i);
        }
    }
}
*/

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif 
    int n,K; cin >> n >> K;
    string s; cin >> s;
    int dp[n][n+1][26]; memset(dp,0,sizeof(dp));
    dp[0][1][s[0]-'a'] = 1;
    FOR(i,1,n)
    {
        int curr = s[i]-'a';
        FOR(len, 2, n+1)
        {
            FOR(j,0,26) dp[i][len][curr] += dp[i-1][len-1][j];
        }
        FOR(j,0,n+1)
        {
            FOR(k,0,26)
            {
                if (k == curr) continue;
                dp[i][j][k] += dp[i-1][j][k];
            }
        }
        dp[i][1][curr] = 1;
    }
    int ans = 0;
    FORR(len,n,0)
    {
        sort(dp[n-1][len], dp[n-1][len] + 26, greater <int>());
        FOR(i,0,26)
        {
            int cnt = min(dp[n-1][len][i], K);
            // trace(len,i,cnt,K);
            ans += cnt*(n-len);
            K -= cnt;
            if (K <= 0) break;
        }
        if (K <= 0) break;
    }
    if (K > 0)
    {
        --K;
        ans += n;
    }
    if (K > 0)
    {
        cout << -1;
        return 0;
    }
    cout << ans;
    return 0;
}
