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
#define MAX 10010010

using v = vector<int>;
using vv = vector<vector<int>>;

vv g;
int id[MAX];
int sz[MAX];
int tam[MAX];
int ans;

int find(int p)
{
    if(p == id[p]) return p;
     return id[p] = find(id[p]);
}

void uni(int p, int q)
{
    p = find(p); q = find(q);
    
    if(p == q) return;
    
    ans--;
    if(sz[p] > sz[q])swap(p, q);
    
    if(sz[p] == sz[q])
    {
        id[p] = q;
        tam[q] += tam[p];
        sz[q]++;
    }
    else{
        id[p] = q;
        tam[q] += tam[p];
    }
    
}

void ini()
{
    rep(i, MAX)
    {
        id[i] = i;
        sz[i] = 1;
        tam[i] = 1;
    }
}
void solve(){               
    
    char c; cin >> c;
    int n = c - 'A' + 1;
    
    ini();    
    ans = n;
    cin.ignore();

    string s;
    while(getline(cin , s) && !s.empty())
    {
        int x = s[0] - 'A', y = s[1] - 'A'; 
        
        uni(x, y);
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
