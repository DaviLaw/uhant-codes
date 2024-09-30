#include<bits/stdc++.h>
using namespace std;
#define w(t) while(t--)
#define int long long
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep1(i, n) for(int i = 1; i <= n; i++)
#define pb push_back
#define all(a) sort(a.begin(), a.end())
#define allrv(v) reverse(v.begin(), v.end())
#define oi cout << "oi" << endl;
#define endl '\n'

using v = vector<int>;
using vv = vector<vector<int>>;

vv g;
v vis;

void dfs(int a)
{
    vis[a] = 1;
    
    for(auto u : g[a])
    {
        if(!vis[u])
        {
            dfs(u);
        }
    }
}


void solve(){               
    
    
    char a; cin >> a;
    int n = a - 'A' + 1;
    
    g.clear(); vis.clear();
    g.resize(n); vis.resize(n);
    
    fill(vis.begin(), vis.end(), 0); 
    
    cin.ignore();
    string s;
    
    while(getline(cin, s) && !s.empty())
    {
        char b = s[0], c = s[1];
        
        int x = b - 'A'; int y = c - 'A';
        g[x].pb(y);
        g[y].pb(x);
    }
    
    int ans = 0;
    
    rep(i, n)
    {
        if(!vis[i])
        {
            dfs(i);
            ans++;
        }
    }
    
    cout << ans << endl;
    
}

signed main()
{
    int t; cin >> t;
    cin.ignore();
    w(t){
        solve();
        if(t!=0)cout << endl;
    }
    
}
