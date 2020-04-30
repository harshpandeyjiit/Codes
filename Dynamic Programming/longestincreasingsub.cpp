#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define sz size()
#define all(_v) _v.begin(), _v.end()
#define ll long long

const int MASK = (1ll << 20);
const ll MOD = 1e9 + 7;
int n;
ll dp[MASK];
ll binpow(ll a, ll n) {
    ll res = 1;
    while(n) {
        if(n & 1) res = res * a % MOD, n--;
        else {
            a = a * a % MOD;
            n >>= 1;
        }
    }
    return res;
}
bool was[MASK];
ll ans = 1;
int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    n = 1e5;
	///cin >> n;
	for(int i = 1; i <= n; ++i) {
        int x = rand() % (1ll << 20);
        ///cin >> x;
        dp[x]++;
        was[x] = 1;
	}
    for(int i = 0; i < 20; i++)
        for(int mask = (1 << 20) - 1; mask >= 0; mask--)
            if ((mask >> i) & 1)
                dp[mask ^ (1 << i)] = (dp[mask ^ (1 << i)] + dp[mask]) % MOD;
    for(int i = 0; i < MASK; ++i) if(was[i]) ans = (ans + binpow(2, dp[i] - 1)) % MOD;
    cout << (binpow(2, n) - ans + MOD) % MOD;
	return 0;
}
