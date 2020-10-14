#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define mp make_pair
#define endl "\n"
#define ss second
#define ff first

#ifndef ONLINE_JUDGE
#define debug(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){cerr << name << " : " << arg1 << endl;}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
	const char* comma = strchr(names + 1, ',');
	cerr.write(names, comma - names) << " : " << arg1 << "  ";
	__f(comma + 1, args...);}
#else
#define debug(...)
#endif

const int inf = 2e18;
const int ninf = -2e18;

signed main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
 
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
		freopen("error.txt", "w", stderr);
	#endif

	int q; cin >> q;
	while (q--) {
		int n, k; cin >> n >> k;
		vector<int> v(n);
		for (int i = 0; i < n; i++) cin >> v[i];

		int mx = ninf;
		int mn = inf;
		for (int i = 0; i < n; i++) {
			mx = max(mx, v[i]);
			mn = min(mn, v[i]);
		}

		if (mn + k >= mx - k) cout << mn + k << endl;
		else cout << -1 << endl;
	}

	return 0;
}
