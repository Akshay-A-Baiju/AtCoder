// Author : Akshay A Baiju
// Problem link : https://atcoder.jp/contests/abc202/tasks/abc202_c
// Problem tags : hashing
// TC : O(n)
// SC : O(n)

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n";
#define sync ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
const int N=1e9+7;

void solve()
{
	//use a hash array to store frequency of B[C[j]], now for each A[i] count+=hsh[A[i]]
	
    ll n,i,count=0;
    cin>>n;
    int a[n+1],b[n+1],c[n+1],hsh[n+1];
    memset(hsh,0,sizeof(hsh));
    for (i=1;i<=n;i++)
        cin>>a[i];
    for (i=1;i<=n;i++)
        cin>>b[i];
    for (i=1;i<=n;i++)
        cin>>c[i];
    for (i=1;i<=n;i++)
        hsh[b[c[i]]]++;
    count=0;
    for (i=1;i<=n;i++)
    {
        count+=hsh[a[i]];
    }
    cout<<count;     
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
