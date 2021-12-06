// Author: Akshay A Baiju
// Problem: A. Long Comparison
// Contest: Codeforces - Educational Codeforces Round 118 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1613/problem/A
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Problem tag: implementation
// TC: O(t*(x+p))
// SC: O(1)

#include "bits/stdc++.h"
// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>

using namespace std;
// using namespace __gnu_pbds;

#define ll                  long long
#define ull                 unsigned long long
#define vi                  vector <int>
#define vll                 vector <ll>
#define vvll                vector <vll>
#define pii                 pair <int,int>
#define pll                 pair <ll,ll>
#define vpll                vector <pll>
#define rep(i,a,n)          for (int i=a;i<n;i++)
#define rrep(i,n,a)         for (int i=n;i>=a;i--)
#define fill1(a,x)          for (auto &it: a) it=x;
#define fill2(a,x)	    	  for (auto &v: a) { for (auto &it: v) it=x; }
#define pb                  push_back
#define pf                  push_front
#define ppb                 pop_back
#define ff                  first
#define ss                  second
#define ins                 insert
#define YY		    		      cout<<"YES"
#define NN		    		      cout<<"NO"
#define all(v)              v.begin(), v.end()
#define desc()              greater <ll>()
#define endl                "\n"   //not to be used in interactive problems
#define scan_vector(v)      for (auto &it: v) { cin>>it; }
#define print_vector(v)     for (auto &it: v) { cout<<it<<" "; } cout<<endl;
#define print_map(mp)       for (auto &pr: mp) { cout<<pr.first<<" "<<pr.second<<endl; }
#define sync                ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
// #define oset		          tree <ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> // find_by_order, order_of_key
#ifndef ONLINE_JUDGE
	#define debug(x)	    cerr<<#x<<" = "; _print(x); cerr<<"\n";
#else
	#define debug(x)
#endif

const int M = 1e9+7;
const int N = 1e5+7;
const ll inf = 1e18;

int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};

void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

struct custom_hash
{
    static uint64_t splitmix64(uint64_t x)
    {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const
    {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
template <class T, class H> using umap=unordered_map<T,H,custom_hash>;
template <class T> using uset=unordered_set<T,custom_hash>;

void makeEqual(string &a, ll d)
{
	while (d--)
		a.pb('0');
}

void solve()
{
	string x1,x2;
	ll p1,p2;
	cin>>x1>>p1>>x2>>p2;
	ll n1=x1.size(),n2=x2.size();
	if (n1<n2)
	{
		if (p1<(n2-n1)) { cout<<"<"; return; }
		p1-=(n2-n1);
		makeEqual(x1,n2-n1);		
	}
	else if (n2<n1)
	{
		if (p2<(n1-n2)) { cout<<">"; return; }
		p2-=(n1-n2);
		makeEqual(x2,n1-n2);
	}
	if (p1>p2) cout<<">";
	else if (p2>p1) cout<<"<";
	else
	{
		if (x1<x2) cout<<"<";
		else if (x1>x2) cout<<">";
		else cout<<"=";
	}
}

int main()
{
	#ifndef ONLINE_JUDGE
		// freopen("input.txt","r",stdin);
		// freopen("output.txt","w",stdout);
		// freopen("error.txt","w",stderr);
		clock_t clk = clock();
	#endif
	sync;
	int t=1;
	cin>>t;
	for (int test=1;test<=t;test++)
	{
		// cout<<"Case #"<<test<<": ";
		solve();
		cout<<endl;
	}
	#ifndef ONLINE_JUDGE
		cerr << '\n'<<"Time (in s): " << double(clock() - clk) * 1.0 / CLOCKS_PER_SEC << '\n';
	#endif
	return 0;
}
