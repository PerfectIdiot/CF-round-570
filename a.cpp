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


signed main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
 
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
		freopen("error.txt", "w", stderr);
	#endif

	int n; cin >> n;
	while (1) {
		int cur = n;
		n++;
		int now = 0;
		while (cur > 0) {
			now += cur % 10;
			cur /= 10;
		}
		if (now % 4 == 0) {
			cout << n - 1 << endl;
			break;
		}
	}

	return 0;
}
