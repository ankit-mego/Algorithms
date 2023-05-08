#include <bits/stdc++.h>
using namespace std;

#define ll long long

/*
https://codeforces.com/blog/entry/90035
Lexicographically-Minimal-String-Rotation
By SPyofgame

Problem Links:
https://codeforces.com/gym/104349/problem/E
https://cses.fi/problemset/task/1110/
https://www.spoj.com/problems/MINMOVE/
https://leetcode.com/problems/orderly-queue/description/
https://www.codechef.com/problems/BIT3B
*/

//1. Brute Force Optimised with <string_view> i used in Leetcode [Requires C++17 or higher]
string bruteforce(string s)
{
	ll n = s.size();
	s += s;
	const char *p = s.c_str();
	string_view ans(p, n);
	for(int i = 1; i<n; i++) ans = min(ans,string_view ( p+i ,n));
	return string{ans};
}

// 2. Booth's Algorithm Space - O(n) Time - O(n)
string min_shift_booths (string s) 
{
	s += s;
	ll n = s.size(), i=0, ans=0;
	while (i < n/2) 
	{
		ans = i;
		ll j=i+1, k=i;
		while (j < n && s[k] <= s[j]) 
		{
			if (s[k] < s[j]) k = i;
			else ++k;
			++j;
		}
		while (i <= k)  i += j - k;
	}
	return s.substr (ans, n/2); //right rotation by ans times
}

// 3. Duval Algorithm (Optimised) Space - O(1) Time - O(n) [Inplace]
void min_shift_duval(string &s)
{
    ll n = s.size();
    ll res = 0;
    for (ll l = 0; l < n;)
    {
        res = l;
        ll r = l, p = l + 1;
        for (; r < n; ++r, ++p) /// If there is such string found, then its length wont exceed |s|
        {
            char c = (p < n) ? s[p] : s[p - n]; /// to avoid modulo
            if (s[r] > c) break;
            if (s[r] < c) r = l - 1;
        }        
        l = max(r, l + p - r); /// just skip those (s2 = sx + sx + ... + sx + sy) cases
    }

    //right rotation by res times
    reverse(s.begin(), s.begin() + res);
    reverse(s.begin() + res, s.end());
    reverse(s.begin(), s.end());
}

signed main() 
{
    string s;
	cin>>s;
	
    // 1. cout<<bruteforce(s)<<endl;

    // 2. cout<<min_shift_booths(s)<<endl;

    // 3. 
    min_shift_duval(s);
    cout<<s<<endl;

    return 0;
}
