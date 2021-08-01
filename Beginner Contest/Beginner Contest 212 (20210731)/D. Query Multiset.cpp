// Author : Akshay A Baiju
// Problem link : https://atcoder.jp/contests/abc212/tasks/abc212_d
// Problem tags : priority_queue, logical
// TC : O(q * log q)
// SC : O(q)

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
	//Logical approach: instead of adding every element with 'add', we can simply store the original elements, and while popping and printing, simply add 'add' to the pop element
	//hence while inserting new x in Type 1, insert (x-add) so that while printing, it will be 'x' in Type 3
	//update 'add' according to type 2
    ll q,add=0;
    cin>>q;
    priority_queue<ll,vll,greater <ll>> pq;
    while (q--)
    {
        ll p,x;
        cin>>p;
        if (p==1)
        {
            cin>>x;
            pq.push(x-add);
        }
        else if (p==2)
        {
            cin>>x;
            add+=x;
        }
        else
        {
            cout<<add+pq.top()<<endl;
            pq.pop();
        }
    }
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
