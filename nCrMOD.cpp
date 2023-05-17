#include <bits/stdc++.h>
using namespace std;

#define ull         unsigned long long
#define ll          long long

const long long MOD = 2999999929; //1000000007;//998244353;//MOD must be prime

ll nCr (ll n, ll r) // O(n) per query
{
    ll p = 1, k = 1;
    if (n - r < r) r = n - r;
    if (r == 0) return 1; 
    while (r) 
    {
        p *= n; k *= r;
        ll m = __gcd(p, k);
        p /= m; k /= m;
        n--; r--;
    }
    return p;
}

ll binpow (ll x, ll y) 
{
    ll res = 1;
    x %= MOD;
    if (x == 0) return 0;
    while (y > 0)
    {
        if (y & 1) res *= x;
        res %= MOD;
        y = y>>1;
        x = (x*x)%MOD;
    }
    return res;
}

ll modInverse (ll a) { return binpow(a, MOD - 2); } 

vector<ull> factorial, modinversefactorial ;
void setup_ncrmod(ll N)
{
    factorial = vector<ull>(N+1);
    modinversefactorial = vector<ull>(N+1);
    factorial[0]=1;
    for(ll i=1; i<=N; i++) factorial[i] = (factorial[i-1]*i)%MOD;
    modinversefactorial[N] = modInverse(factorial[N]);
    for(ll i=N-1; i>=0; i--) modinversefactorial[i] = (modinversefactorial[i+1]*(i+1))%MOD;
}

ll nCrmod(ll n, ll r)
{
    if (n < r) return 0;
    if (r == 0 || r == n) return 1;
    return ((factorial[n] * modinversefactorial[r])%MOD * modinversefactorial[n-r]) %MOD;
}

void testcase()
{
    ll n,r;
    cin>>n>>r;
    cout<< nCrmod(n,r)<<endl;
}

signed main() 
{
    ll N = 1e7;
    setup_ncrmod(N);
    
    ll TT = 1;
    cin>>TT;
    for( ll TC = 1; TC <= TT; TC++)
    {
	    testcase();
    }
    return 0;
}
