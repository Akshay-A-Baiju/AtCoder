// Author: Akshay A Baiju
// Problem: 
// URL: 

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"   //not to be used in interactive problems
#define sync ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define PI 3.141592653589793238462

const int M = 1e9+7;
const int MM = 998244353;
const int N = 2e5+7;
const ll inf = 1e18;

vector <ll> dp;
// dp[i]=minCost to reach index i from index 0

ll minCost(ll i, vector <ll> &h)
{
    if (i==0) return 0;
    else if (i==1) return abs(h[1]-h[0]);
    if (dp[i]!=-1) return dp[i];
    ll c1=abs(h[i]-h[i-1])+minCost(i-1,h);
    ll c2=abs(h[i]-h[i-2])+minCost(i-2,h);
    ll ans=min(c1,c2);
    return dp[i]=ans;
}

void solve()
{
    ll n; cin>>n;
    dp.resize(n,-1);
    vector <ll> h(n);
    for (auto &it: h) cin>>it;
    cout<<minCost(n-1,h);
}

int main()
{
    sync;
    int t=1;
    // cin>>t;
    for (int test=1;test<=t;test++)
    {
        solve();
        cout<<endl;
    }
    return 0;
}
