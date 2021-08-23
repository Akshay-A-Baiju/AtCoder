// Author : Akshay A Baiju
// Problem link : https://atcoder.jp/contests/arc125/tasks/arc125_a
// Problem tags : prefix, implementation
// TC : O(n+m)
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
#define desc()              greater <ll>()
#define endl                "\n"   //not to be used in interactive problems
#define scan_vector(v,n)    for (auto &it: v) { cin>>it; }
#define print_vector(v)     for (auto &it: v) { cout<<it<<" "; } cout<<endl;
#define print_map(mp)       for (auto &pr: mp) { cout<<pr.first<<" "<<pr.second<<endl; }
#define sync                ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
const int M = 1e9+7;

void solve()
{    
    ll n,m;
    cin>>n>>m;
    vll s(n),t(m);
    ll a=0,b=0,c=0,d=0;
    for (ll i=0;i<n;i++)
    {
        cin>>s[i];
        if (s[i]==0)
            a++;
        else
            b++;
    }
    for (ll i=0;i<m;i++)
    {
        cin>>t[i];
        if (t[i]==0)
            c++;
        else
            d++;
    }
    if ((d>0 && b==0) || (c>0 && a==0))  //cannot form t from s
    {
        cout<<-1;
        return;
    }
    //prefix to left
    ll last0=-1,last1=-1;
    vll pfleft(n);
    //round1
    for (ll i=0;i<n;i++)
    {
        if (s[i]==0)
        {
            pfleft[i]=last1;
            last0=i;
        }
        else
        {
            pfleft[i]=last0;
            last1=i;
        }
    }
    //round2
    for (ll i=0;i<n;i++)
    {
        if (s[i]==0 && pfleft[i]==-1)
        {
            pfleft[i]=last1;
            last0=i;
        }
        else if (s[i]==1 && pfleft[i]==-1)
        {
            pfleft[i]=last0;
            last1=i;
        }
    }
    //prefix to right
    last0=-1;
    last1=-1;
    vll pfright(n);
    //round1
    for (ll i=n-1;i>=0;i--)
    {
        if (s[i]==0)
        {
            pfright[i]=last1;
            last0=i;
        }
        else
        {
            pfright[i]=last0;
            last1=i;
        }
    }
    //round2
    for (ll i=n-1;i>=0;i--)
    {
        if (s[i]==0 && pfright[i]==-1)
        {
            pfright[i]=last1;
            last0=i;
        }
        else if (s[i]==1 && pfright[i]==-1)
        {
            pfright[i]=last0;
            last1=i;
        }
    }
    ll ind=0; //index in s
    ll sum=0;
    for (ll i=0;i<m;i++)
    {
        if (t[i]==s[ind])
            sum++;
        else
        {
            //move to nearest index (left/right)
            ll dist_to_left,dist_to_right;
            //case 1 - calculate distance to move to left
            if (ind>pfleft[ind])
                dist_to_left=ind-pfleft[ind];
            else
                dist_to_left=ind-pfleft[ind]+n;
            //case 2 - calculate distance to move to right
            if (pfright[ind]>ind)
                dist_to_right=pfright[ind]-ind;
            else
                dist_to_right=pfright[ind]-ind+n;
            //cout<<dist_to_left<<" - "<<dist_to_right<<endl;
            if (dist_to_left<dist_to_right)
            {
                ind=pfleft[ind];
                sum+=dist_to_left;
            }
            else
            {
                ind=pfright[ind];
                sum+=dist_to_right;
            }
            sum++;
        }
        //cout<<i<<" "<<sum<<endl;
    }
    cout<<sum;
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
    //cerr << '\n'<<"Time (in s): " << double(clock() - clk) * 1.0 / CLOCKS_PER_SEC << '\n';
    return 0;
}
