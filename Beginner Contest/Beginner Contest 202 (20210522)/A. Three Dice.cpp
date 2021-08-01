// Author : Akshay A Baiju
// Problem link : https://atcoder.jp/contests/abc202/tasks/abc202_a
// Problem tags : basic
// TC : O(1)
// SC : O(1)

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n";
#define sync ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
const int N=1e9+7;

void solve()
{
    int a,b,c;
    cin>>a>>b>>c;
    cout<<21-(a+b+c);     
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
