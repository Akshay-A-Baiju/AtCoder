// Author : Akshay A Baiju
// Problem link : https://atcoder.jp/contests/arc125/tasks/arc125_a
// Problem tags : logical, implementation
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
    //logical: we calculate the first prev and next element index of !s[0], calucate its minimum distance. Once s[0]!=t[i] for traversal of t
    //we need to shift to minimum distance, after that only one move is required whenever t[i]!=element at minimum distance
    //this is because we would have traversed from left (for prev being minimum), thus this ensures that !s[prev] lies at prev+1 position
    //similarily, for next being the minimum, we would have traversed from right, thus it ensures that !s[next] lies at next-1 position
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
    ll prev,next;
    if (s[0]==0)
    {
        //prev1
        for (ll i=n-1;i>0;i--)
        {
            if (s[i]==1)
            {
                prev=i;
                break;
            }
        }
        //next1
        for (ll i=1;i<n;i++)
        {
            if (s[i]==1)
            {
                next=i;
                break;
            }
        }
    }
    else
    {
        //prev0
        for (ll i=n-1;i>0;i--)
        {
            if (s[i]==0)
            {
                prev=i;
                break;
            }
        }
        //next0
        for (ll i=1;i<n;i++)
        {
            if (s[i]==0)
            {
                next=i;
                break;
            }
        }
    }
    ll nearest=min(next,n-prev);
    ll sum=0;
    ll curr;                          //stores 0 or 1, to match with t[i]
    bool flag=false;
    for (ll i=0;i<m;i++)
    {
        if (t[i]==s[0] && !flag)
            sum++;
        else
        {
            if (!flag)                //first shifting to the nearest index of !s[0]
            {
                sum+=nearest+1;
                flag=true;
                curr=t[i];
            }
            else if (t[i]==curr)      //if t[i]==curr, we just need to increment sum
                sum++;
            else                      //we move to the adjacent position (quarenteed !t[i] - logical) and add it, so sum+=2
            {
                sum+=2;
                curr=!curr;
            }
        }
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
