#include <bits/stdc++.h>
using namespace std;

#define ull         unsigned long long
#define ll          long long

// O(root(n))
vector<ll> factorize( ll n){
    vector<ll> ans;
    while(n%2 == 0)
    {
        n /= 2;
        ans.push_back(2);
    }
    
    for(ll i = 3; i*i <= n; i+= 2)
    {
        while(n%i == 0)
        {
            n /= i;
            ans.push_back(i);
        }
    }
    if(n > 1) ans.push_back(n);
    return ans;
}

//smallest prime factor for i
//if spf[i] == i then its prime
vector<ull> spf; 

void sieve(ll N){
    spf = vector<ull>(N+1);
    for (ll i = 2; i<=N; i++){
        if (spf[i] == 0){
            spf[i] = i;
            for (ll j = i * i; j <= N; j += i) if (spf[j] == 0)spf[j] = i;
        }
    }
}

//Type 1 ~ Simple
vector<ll> factorize_with_spf(ll n){
    vector<ll> ans;
    while (n > 1)
    {
        ll fact = spf[n];
        while (n % fact == 0)
        {
            n /= fact;
            ans.push_back(fact);
        }
    }
    return ans;
}

//Type 2 ~ Unique
vector<ll> factorize_with_spf_unq(ll n){
    vector<ll> ans;
    while (n > 1)
    {
        ll fact = spf[n];
		ans.push_back(fact);
        while (n % fact == 0)
        {
            n /= fact;
        }
    }
    return ans;
}

//Type 3 ~ Frequency map
map<ll,ll> factorize_with_spf_freq(ll n){
    map<ll,ll> ans;
    while (n > 1)
    {
        ll fact = spf[n];
        while (n % fact == 0)
        {
			ans[fact]++;
            n /= fact;
        }
    }
    return ans;
}

void testcase()
{
	ll n;
	cin>>n;
	vector<ll> primefactors = factorize_with_spf_unq(n);
	for(auto it: primefactors) cout<<it<<" ";
	cout<<endl;
}

signed main() 
{
	ll N = 1e7;
	sieve(N);

    ll TT = 1;
    cin>>TT;
    for( ll TC = 1; TC <= TT; TC++)
    {
	    testcase();
    }
    return 0;
}
