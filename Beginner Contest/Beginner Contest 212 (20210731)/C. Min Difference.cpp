// Author : Akshay A Baiju
// Problem link : https://atcoder.jp/contests/abc212/tasks/abc212_c
// Problem tags : lower_bound, logical
// TC : O(nlogn)
// SC : O(n+m)

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
#define desc()              greater <int>()
#define endl                "\n"   //not to be used in interactive problems
#define scan_vector(v,n)    for (auto &it: v) { cin>>it; }
#define print_vector(v)     for (auto &it: v) { cout<<it<<" "; } cout<<endl;
#define print_map(mp)       for (auto &pr: mp) { cout<<pr.first<<" "<<pr.second<<endl; }
#define sync                ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
const int M = 1e9+7;

void solve()
{
	//for vector A, min abs(Ai-Bj) occurs when Bj is the lower bound to Ai, find min(abs(Ai-Bj)) for all elements in A
	//Similarily, for vector B, min abs(Bi-Aj) occurs when Aj is the lower bound to Bi, find min(abs(Bi-Aj)) for all elements in B
	//minimum of both is the required answer
	
    ll n,m;
    cin>>n>>m;
    vll a(n),b(m);
    scan_vector(a,n);
    sort(all(a));
    scan_vector(b,m);
    sort(all(b));
    ll ans=LLONG_MAX;
    for (ll i=0;i<m;i++)
    {
        ll index=lower_bound(all(a),b[i])-a.begin();
        if (index==n)   //lower_bound not present
            index--;    //move to last index of vector a
        ans=min(ans,abs(b[i]-a[index]));
    }
    for (ll i=0;i<n;i++)
    {
        ll index=lower_bound(all(b),a[i])-b.begin();
        if (index==m)   //lower_bound not present
            index--;    //move to last index of vector b
        ans=min(ans,abs(a[i]-b[index]));
    }

    cout<<ans;
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
