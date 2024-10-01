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
#define MAX 1001

using v = vector<int>;
using vv = vector<vector<int>>;

int value[MAX][MAX];
int g[MAX][MAX];
bool vis[MAX][MAX];

int r, c, m, n; 
v dx, dy;

bool isvalid(int a, int b){
    if(a < 0 || b < 0 || a >= r || b >= c) return false;
    return true;
}

void dfs(int x, int y){
    
    if(vis[x][y]) return;
    
    vis[x][y] = 1;
    
    int moves = 0;
    for(int i = 0; i < 8; i++)
    {
        int a = x + dx[i];
        int b = y + dy[i];
        
        if(isvalid(a,b) && g[a][b] != -1){
            moves++;
            dfs(a, b);
        }
    }
    
    value[x][y] = moves;
    
}

void solve(){               
    
    memset(vis, 0, sizeof(vis));
    memset(g, 0, sizeof(g));
    memset(value, 0, sizeof(value));
    
    cin >> r >> c >> m >> n;
     
    dx = {m, -m, n, -n, n, -n, -m, m};
    dy = {n, n, m, m, -m, -m, -n, -n};

    int w; cin >> w;
    
    rep(i, w){
        int a, b; cin >> a >> b;
        g[a][b] = -1;
    }
    
    int even = 0, odd = 0;
    
    dfs(0,0);
    rep(i, r){
        rep(j, c){
            
            if(vis[i][j] && (m == 0 || n == 0 || m == n))value[i][j]/=2;
            //Essa verificação lida com os casos em que teremos metade das possibilidades de pulos, os vetores dx e dy ainda farão 8 movimentos, mas esses casos so teão 4 movimentos possiveis
            
            if(vis[i][j] && value[i][j] & 1)odd++;
            else if(vis[i][j])even++;
        }
    }

    cout << even << " " << odd << endl;
    
}

signed main()
{
    int t; cin >> t;
    
    rep1(i, t){
        cout << "Case " << i <<": ";
        solve();
    }
    
}
