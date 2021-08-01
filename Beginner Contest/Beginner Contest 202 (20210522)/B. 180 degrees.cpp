// Author : Akshay A Baiju
// Problem link : https://atcoder.jp/contests/abc202/tasks/abc202_b
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
    string str,s;
    cin>>str;
    s=str;
    int i,l=str.length();
    for (i=0;i<l;i++)
    {
        char ch=str[i];
        if (ch=='6')
            s[l-1-i]='9';
        else if (ch=='9')
            s[l-1-i]='6';
        else s[l-1-i]=ch;
    }
    cout<<s;     
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
