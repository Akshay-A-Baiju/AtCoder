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
// dp[i]=min cost to reach index i from index 0

void solve()
{
    ll n; cin>>n;
    dp.resize(n,-1);
    vector <ll> h(n);
    for (auto &it: h) cin>>it;
    for (ll i=0;i<n;i++)
    {
        if (i==0) dp[i]=0;
        else if (i==1) dp[i]=abs(h[1]-h[0]);
        else
        {
            ll c1=abs(h[i]-h[i-1])+dp[i-1];
            ll c2=abs(h[i]-h[i-2])+dp[i-2];
            ll ans=min(c1,c2);
            dp[i]=ans;
        }
    }
    cout<<dp[n-1];
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
