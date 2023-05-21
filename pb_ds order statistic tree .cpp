#include <bits/stdc++.h>
using namespace std;
#define ll long long

/*
Binary Indexed (fenwick) tree > segment tree > order statistic tree

pb_ds = order statistic tree / augmented red black tree

Questions: 
https://cses.fi/problemset/task/1144/
https://cses.fi/problemset/task/1749

Other usecases: running median, counting inversions 

Articles: 
https://www.geeksforgeeks.org/ordered-set-gnu-c-pbds/
https://codeforces.com/blog/entry/11080
*/ 

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define op_set tree< pair<ll,ll>, null_type, less<pair<ll,ll>>, rb_tree_tag, tree_order_statistics_node_update>

// order_of_key ( { k, LLONG_MIN } ) : Number of items < k .
// order_of_key ( { k, LLONG_MAX } ) : Number of items <= k.
// find_by_order(k) : Pointer to k indexed element in the set (0 based indexing).

void solve()
{
	ll n,q;
	cin>>n>>q;
	op_set ordered_set;

	vector<int> vec(n+1);

	for(int i = 1; i<=n; i++)
	{
		cin>>vec[i];
		ordered_set.insert( {vec[i], i} );
	}

	
	// for(auto it: ordered_set)
	// {
	// 	cout<<it.first<<" "<<it.second<<endl;
	// 	// Can print just like normal set ($,$)
	// }

	while(q--)
	{
		char op;
		ll left,right;
		cin>>op>>left>>right;

		if(op == '!')
		{
			ordered_set.erase( {vec[left], left} );
			vec[left] = right;

			ordered_set.insert({ vec[left], left });
		}
		else
		{
			ll low = ordered_set.order_of_key( {left, LLONG_MIN} );
			ll high = ordered_set.order_of_key( {right, LLONG_MAX} );

			ll ans = max( high-low, 0LL) ;
			cout<<ans<<endl;
		}
	}
}

signed main() {
	//https://cses.fi/problemset/task/1144/
	solve();
	return 0;
}
