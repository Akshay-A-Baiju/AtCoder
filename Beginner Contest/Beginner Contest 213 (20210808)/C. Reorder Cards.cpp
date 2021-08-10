// Author : Akshay A Baiju
// Problem link : https://atcoder.jp/contests/abc213/tasks/abc213_c
// Problem tags : logical, implementation
// TC : O(nlogn)
// SC : O(n)

#include<bits/stdc++.h>
using namespace std;
#define ll                  long long
#define ull                 unsigned long long
#define vi                  vector <int>
#define vll                 vector <ll>
#define vvll                vector <vll>
#define pii                 pair <int,int>
#define pll                 pair <ll,ll>
#define ms(a,x)             memset (a,x,sizeof(a))
#define rep(i,a,n)          for (int i=a;i<n;i++)
#define rrep(i,n,a)         for (int i=n;i>=a;i--)
#define pb                  push_back
#define pf                  push_front
#define ppb                 pop_back
#define umap                unordered_map
#define uset                unordered_set
#define all(v)              v.begin(), v.end()
#define desc()              greater <ll>()
#define endl                "\n"   //not to be used in interactive problems
#define scan_vector(v,n)    for (auto &it: v) { cin>>it; }
#define print_vector(v)     for (auto &it: v) { cout<<it<<" "; } cout<<endl;
#define print_map(mp)       for (auto &pr: mp) { cout<<pr.first<<" "<<pr.second<<endl; }
#define sync                ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
const int M = 1e9+7;

void solve()
{
	ll h,w,n;
	cin>>h>>w>>n;
	set <ll> uniquex,uniquey;		//store the unique x and unique y
	vector <pair<ll,ll>> card(n);
	for (ll i=0;i<n;i++)
	{
		ll x,y;
		cin>>x>>y;
		uniquex.insert(x);
		uniquey.insert(y);
		card[i]={x,y};
	}
	map <ll,ll> assignx,assigny;	//assign the position in new coordinates to x and y respectively
									//least x-> 1, next x->2, next x-> 3, so on...  Similarily for y
	ll ind=1;
	for (auto &it: uniquex)
		assignx[it]=ind++;
	ind=1;
	for (auto &it: uniquey)
		assigny[it]=ind++;
	for (ll i=0;i<n;i++)			//print in new coordinates
		cout<<assignx[card[i].first]<<" "<<assigny[card[i].second]<<endl;
}

int main()
{
    clock_t clk = clock();
    sync;
    int t=1;
    //cin>>t;
    while (t--)
    {
        solve();
        cout<<endl;
    }
    cerr << '\n'<<"Time (in s): " << double(clock() - clk) * 1.0 / CLOCKS_PER_SEC << '\n';
    return 0;
}
