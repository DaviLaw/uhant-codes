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

using vec = vector<int>;
using vv = vector<vector<int>>;
using vpi = vector<pair<int , int >>;

struct pts{
    double x;
    double y;
    
     bool operator<(const pts& other) const {
        if (x != other.x) return x < other.x;
        return y < other.y;
    }
};

int id[MAX];
int sz[MAX];
int tam[MAX];
int maior = 1;
int cnt;

vector<tuple<double, pts , pts>> grafo;

void set_(int a){
    sz[a] = tam[a] = 1;
    id[a] = a;
}

int find(int p){
    if(id[p] == p) return p;
    return id[p] = find(id[p]);
}

void uni(int p, int q){
    p = find(p), q = find(q);
    
    if(p == q) return;
    
    if(sz[p] > sz[q])swap(q, p);
    
    id[p] = q;
}


double dist(pts a, pts b){
    return sqrt(((a.x - b.x)*(a.x - b.x)) + (a.y - b.y)*(a.y - b.y));    
}

void test()
{
    int a; cin >> a;
    
    vector<pts> vertex;
    
    rep(i, a)set_(i);
    map<pts, int> tab;
    
    int tam = 0;
    w(a){
        double x, y; cin >> x >> y;
        tab[{x, y}] = tam;
        vertex.pb({x, y});
        tam++;
    }
    
    //criar grafo completo
    for(int i = 0; i < (int) vertex.size(); i++){
        for(int j = 0; j < (int) vertex.size(); j++){
            if(i!=j){
                double w = dist(vertex[i], vertex[j]);
                grafo.emplace_back(w, vertex[i], vertex[j]);
                grafo.emplace_back(w, vertex[j], vertex[i]);
            }
        }
    }
    
    sort(grafo.begin(), grafo.end());
    
    double ans = 0;
    for(auto [w, a, b] : grafo){
        if(find(tab[a]) != find(tab[b])){
            uni(id[tab[a]], id[tab[b]]);
            ans += w;
        }
    }
    
    printf("%.2lf\n", ans); 
    grafo.clear();
}

signed main()
{
     int t = 1;
     cin >> t;
     cin.ignore();
    w(t){
        test();
        if(t >= 1)cout << endl;
    }
}
