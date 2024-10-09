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
#define lea(n) for(auto &u : n) cin >> u;
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define f first
#define s second

using vi = vector<int>;
using vv = vector<vector<int>>;
using vpi = vector<pair<int , int >>;

char mat[110][110];
int vis[110][100];
int n, m;

bool isvalid(int a, int b){
    if(a < 0 || b < 0 || a >= n || b >=m)return false;
    return true;
}
void dfs(int x, int y){
    if(!isvalid(x,  y))return;
    if(mat[x][y] != '@') return;
    if(vis[x][y]) return;
    
    vis[x][y] = 1;
    mat[x][y] = '0';
    
    for(auto [a, b] : vpi({{1, 1}, {-1, -1}, {1, -1}, {-1, 1}, {0, 1}, {1, 0}, {-1, 0}, {0, -1}})){
        int xx = x + a, yy = y + b;
        dfs(xx, yy);
    }
}
void test()
{
    cin >> n >> m;
    while(n!=0 && m!=0){
        
    memset(vis, 0, sizeof(vis));
        rep(i, n){
            rep(j, m){
                cin >> mat[i][j];
            }
        }
       
        int ans = 0;
        rep(i, n){
            rep(j, m){
                if(mat[i][j] == '@'){
                    dfs(i, j);
                    ans++;
                    
                   
                }
            }
        }
        cout << ans << endl;
        cin >> n >> m;
    }
    
    return;
    
}

signed main()
{
     int t = 1;
    //  cin >> t;
    //  cin.ignore();
    w(t){
        test();
    }
}
