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
#define MAX 10010011

using v = vector<int>;
using vv = vector<vector<int>>;

vv g;
int vis[MAX];
int cost[MAX];
int maior, ans;

void dfs(int a)
{
    vis[a] = 1;    
    
    for(auto u : g[a]){
        if(!vis[u]){
            if(cost[])
            dfs(u);
        }
    }   
}
void solve(){               
    ans = 0;
    maior = -99999999999;    
    memset(vis, false, sizeof(vis));
    g.clear();
    g.resize(n);
    
    rep(i, m)
    {
        int x, y, v; cin >> x >> y >> v;
        x--; y--;
        cost[y] = cost[x] = v;
        g[x].pb(y);
        g[y].pb(x);
        
        maior = max(maior, v);
    }
    
    rep(i, n)
    {
        if(!vis[i]){
            dfs(i);
        }
    }
}

signed main()
{
    cin >> n >> m;
    while(n && m)
    {
        solve();
        cin >> n >> m;
    }    
}
