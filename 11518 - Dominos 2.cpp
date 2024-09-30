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
int vis[10010101];

int ans;
void dfs(int a)
{
    vis[a] = 1;
    ans++;
    for(auto u : g[a])
    {
        if(!vis[u])
        {
            dfs(u);
        }
    }
}


void solve(){               
    ans = 0;
    int n, m, l; cin >> n >> m >> l;
    
    g.clear(); 
    g.resize(n); 
    memset(vis, false, sizeof(vis));
    rep(i, m)
    {
        int x, y; cin >> x >> y;
        
        x--; y--;
        g[x].pb(y);
    }
    
    rep(i, l)
    {
        int x; cin >> x;
        x--;
        if(!vis[x])dfs(x);
    }
    
    cout << ans << endl;
}

signed main()
{
    int t; cin >> t;
//    cin.ignore();
    w(t){
        solve();
    }
    
}
