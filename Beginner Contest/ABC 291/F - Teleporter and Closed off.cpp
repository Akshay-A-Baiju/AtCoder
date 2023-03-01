// Author: Akshay A Baiju
// Problem: F - Teleporter and Closed off
// Contest: AtCoder - AtCoder Beginner Contest 291（Sponsored by TOYOTA SYSTEMS）
// URL: https://atcoder.jp/contests/abc291/tasks/abc291_f
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// Problem tag: 
// TC: 
// SC: 

#include "bits/stdc++.h"
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define ll long long
#define ld double
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ff first
#define ss second
#define ins insert
#define vll vector <ll>
#define vvll vector <vll>
#define vbool vector <bool>
#define pll pair <ll,ll>
#define vpll vector <pll>
#define YY cout<<"YES"
#define NN cout<<"NO"
#define yy cout<<"Yes"
#define nn cout<<"No"
#define set_bits __builtin_popcountll
#define sz(v) (int)v.size()
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()
#define desc() greater <ll>()
#define fill1(a,x) for (auto &it: a) it=x;
#define fill2(a,x) for (auto &v: a) { for (auto &it: v) it=x; }
#define endl '\n'   //not to be used in interactive problems
#define random(l,r,T) uniform_int_distribution<T>(l,r)(rng)
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int M = 1e9+7;
const int MM = 998244353;
const int N = 2e5+7;
const ll inf = 1e18;
const ld eps = 1e-9;
#define PI 3.141592653589793238462

int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
int Dx[]={0,1,1,1,0,-1,-1,-1};
int Dy[]={1,1,0,-1,-1,-1,0,1};


// ********     Policy Based Data Structures     ********
template<class T> using oset = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
template<class key, class value> using omap = tree <key,value,less<key>,rb_tree_tag,tree_order_statistics_node_update>;
// find_by_order(k) -> returns iterator to kth element from start 0
// order_of_key(k) -> returns count of elements < k


// ********     Debug Helper     ********
vector<string> vec_splitter(string s) {
    s += ',';
    vector<string> res;
    while(!s.empty()) {
        res.push_back(s.substr(0, s.find(',')));
        s = s.substr(s.find(',') + 1);
    }
    return res;
}

void debug_out(
vector<string> __attribute__ ((unused)) args,
__attribute__ ((unused)) int idx, 
__attribute__ ((unused)) int LINE_NUM) { cerr << endl; } 
template <typename Head, typename... Tail>
void debug_out(vector<string> args, int idx, int LINE_NUM, Head H, Tail... T) {
    if(idx > 0) cerr << ", "; else cerr << "Line(" << LINE_NUM << ") ";
    stringstream ss; ss << H;
    cerr << args[idx] << " = " << ss.str();
    debug_out(args, idx + 1, LINE_NUM, T...);
}

template<typename C, 
         typename T = std::decay_t<decltype(*begin(std::declval<C>()))>,
         typename std::enable_if<!std::is_same<C, std::string>::value>::type* = nullptr
         >
std::ostream &operator<<(std::ostream &os, const C &container)
{
  bool first = true;
  std::stringstream ss; 
  ss << '[';
  for(const auto &x : container){
    if (!first){
      ss << ", ";
    }
    first = false;
    ss << x;
  }
  ss << ']';
  return os << ss.str();
}

#ifndef ONLINE_JUDGE
    #define debug(...) debug_out(vec_splitter(#__VA_ARGS__), 0, __LINE__, __VA_ARGS__)
#else
    #define debug(...) 42
#endif


// ********     Useful Fuctions     ********
ll gcd(ll a, ll b) { while (b) {a %= b; swap(a,b);} return a; }
ll lcm(ll a, ll b) { ll g=gcd(a,b); ll res=a*(b/g); return res; }
ll extended_gcd(ll a, ll b, ll &x, ll &y) { if (b==0) { x=1; y=0; return a; } ll x1,y1; ll g=extended_gcd(b,a%b,x1,y1); x=y1; y=x1-y1*(a/b); return g; }
ll binExp(ll a, ll b, ll m=M) { a = a % m; ll res = 1; while (b) { if (b&1) { res=(res * a) % m; } a=(a * a) % m; b>>=1; } return res; }
ll mod_inv(ll a, ll m=M) { a = a % m; return binExp(a,m-2,m); }        // only for prime m
ll mod_add(ll a, ll b, ll m=M) { a = a % m; b = b % m; return (((a + b) % m) + m) % m; }
ll mod_sub(ll a, ll b, ll m=M) { a = a % m; b = b % m; return (((a - b) % m) + m) % m; }
ll mod_mul(ll a, ll b, ll m=M) { a = a % m; b = b % m; return (((a * b) % m) + m) % m; }
ll mod_div(ll a, ll b, ll m=M) { a = a % m; ll binv = mod_inv(b,m); return (((a * binv) % m) + m) % m; }
ll sqrtll(ll n) { ll lo=0,hi=3037000499; while (hi-lo>1) { ll m=(hi+lo)/2; if (m*m<=n) { lo=m; } else { hi=m-1; }} if (hi*hi<=n) { return hi; } return lo; }
ld sqrtld(ll n) { ld lo=0,hi=3037000499; while (hi-lo>eps) { ld m=(hi+lo)/2; if ((n-m*m)>eps) { lo=m; } else { hi=m-eps; }} return lo; }
ll cbrtll(ll n) { ll lo=0,hi=2097151; while (hi-lo>1) { ll m=(hi+lo)/2; if (m*m*m<=n) { lo=m; } else { hi=m-1; }} if (hi*hi*hi<=n) { return hi; } return lo; }
ld cbrtld(ll n) { ld lo=0,hi=2097151; while (hi-lo>eps) { ld m=(hi+lo)/2; if ((n-m*m*m)>eps) { lo=m; } else { hi=m-eps; }} return lo; }
void init_usaco() { freopen("input.txt","r",stdin); freopen("output.txt","w",stdout); }


// ********     Input/Output Template     *********
template<typename T> istream& operator >>(istream &in,vector<T> &v){ for(auto &x:v) in>>x; return in;}
template<typename T> ostream& operator <<(ostream &out,const vector<T> &v){ for(auto &x:v) out<<x<<' '; return out;}
template<typename T1,typename T2> istream& operator >>(istream &in,pair<T1,T2> &p){ in>>p.first>>p.second; return in;}
template<typename T1,typename T2> ostream& operator <<(ostream &out,const pair<T1,T2> &p){ out<<p.first<<' '<<p.second; return out;}


// ********     ACCEPTED     ********
ll fun1(ll ind, ll &n, vector <string> &v, vll &dp1)	// min moves to reach n-1 from ind
{
	if (ind==n-1) return 0;
	if (dp1[ind]!=-1) return dp1[ind];
	ll m=v[0].length();
	ll minMoves=inf;
	for (ll i=0;i<m;i++)
	{
		if (v[ind][i]=='1')
		{
			ll moves=1+fun1(ind+i+1,n,v,dp1);
			minMoves=min(minMoves,moves);
		}
	}
	return dp1[ind]=minMoves;
}

ll fun2(ll ind, ll &n, vector <string> &v, vll &dp2)	// min moves to reach ind from 0
{
	if (ind==0) return 0;
	if (dp2[ind]!=-1) return dp2[ind];
	ll m=v[0].length();
	ll j=0,minMoves=inf;
	for (ll i=ind-1;i>=max(0LL,ind-m);i--,j++)
	{
		if (v[i][j]=='1')
		{
			ll moves=1+fun2(i,n,v,dp2);
			minMoves=min(minMoves,moves);
		}
	}
	return dp2[ind]=minMoves;
}

ll fun3(ll ind, ll skipInd, ll n, vector <string> &v, vvll &dp3)	// min moves to reach n-1 from ind except skipInd
{
	if (ind==n-1) return 0;
	ll m=v[0].length();
	ll skip=skipInd-ind;
	if (skip<0) skip=0;
	if (skip>m) skip=m+1;
	if (dp3[ind][skip]!=-1) return dp3[ind][skip];
	ll minMoves=inf;
	for (ll i=0;i<m;i++)
	{
		ll newInd=ind+i+1;
		if (v[ind][i]=='1' && newInd!=skipInd)
		{
			ll moves=1+fun3(newInd,skipInd,n,v,dp3);
			minMoves=min(minMoves,moves);
		}
	}
	return dp3[ind][skip]=minMoves;
}

ll fun4(ll ind, ll skipInd, ll &n, vector <string> &v, vvll &dp4)	// min moves to reach ind from 0 except skipInd
{
	if (ind==0) return 0;
	ll m=v[0].length();
	ll skip=ind-skipInd;
	if (skip>m) skip=m+1;
	if (skip<0) skip=0;
	if (dp4[ind][skip]!=-1) return dp4[ind][skip];
	ll j=0,minMoves=inf;
	for (ll i=ind-1;i>=max(0LL,ind-m) && j<m;i--,j++)
	{
		// debug(i,ind,skipInd);
		if (v[i][j]=='1' && i!=skipInd)
		{
			ll moves=1+fun4(i,skipInd,n,v,dp4);
			minMoves=min(minMoves,moves);
		}
	}
	return dp4[ind][skip]=minMoves;
}

void solve()
{
    ll n,m; cin>>n>>m;
    vector <string> v(n); cin>>v;
    // dp1[i]=min moves to reach n-1 from i
    // dp2[i]=min moves to reach i from 0
    vll dp1(n,-1),dp2(n,-1);
    vvll dp3(n, vll (m+7,-1)),dp4(n, vll (m+7,-1));
    for (ll k=1;k<n-1;k++)
    {
    	// avoid k
    	ll minMoves=inf;
    	for (ll i=k-1;i>=max(0LL,k-m);i--)
    	{
    		// 0 -> i -> (skip k)-> n-1
    		ll a=fun2(i,n,v,dp2);
    		ll b=fun3(i,k,n,v,dp3);
    		ll moves=a+b;
    		minMoves=min(minMoves,moves);
    	}
    	for (ll i=k+1;i<min(n,k+m);i++)
    	{
    		// 0 -> (skip k) -> i -> n-1
    		ll a=fun4(i,k,n,v,dp4);
    		ll b=fun1(i,n,v,dp1);
    		ll moves=a+b;
    		minMoves=min(minMoves,moves);
    	}
    	if (minMoves==inf) cout<<-1<<" ";
    	else cout<<minMoves<<" ";
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
    // init_usaco();
    fastIO;
    int t=1;
    // cin>>t;
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
