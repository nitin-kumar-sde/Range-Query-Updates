#include <bits/stdc++.h>
using namespace std;
#define boost ios_base::sync_with_stdio(false);cin.tie(NULL);
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define ll long long int
#define mod 1000000007
#define inf 1000000000000
#define FR(i,a,b) for(ll i=(ll) a; i<=(ll)b ;i++)
#define RFR(i,a,b) for(ll i=(ll)a; i>=(ll)b ;i--)
#define clr(x) memset(x, 0, sizeof(x))
#define PI 3.1415926535897932384626
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define vi vector<int> 
#define vl vector<ll>
#define vii vector<pii>
#define vll vector<pll>
pair<ll,ll>s4[4]={{-1,0},{1,0},{0,-1},{0,1}};
pair<ll,ll>s8[8]={{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,1},{1,0},{1,-1}};

const int N=10000+5;
vector<vii> adj(N);
vi tin(N);
vi tout(N);
vi minC(N);
vi h(N);
// stores 2^j ancesstor of i is stored at anc[i][j]
int anc[N][20];

int timer;
void  initialise() {
    for(int i=0;i<N;i++) {
		tin[i]=0;tout[i]=0;minC[i]=0;
    adj[i].clear();
	  }
    timer=0;
    clr(anc);
}

// pre compute 2^i ancessor of a node
void  dfs(int s=0, int par=0, int cost=0, int hg=0) {
    tin[s]=timer++;  h[s]=hg;
    anc[s][0]=par;
  
    for(int i= 1; i < 20; i++) 
	  anc[s][i]=anc[anc[s][i-1]][i-1];

    minC[s]=cost;
    for(auto it: adj[s]) {
        if(par==it.fi) continue;
        dfs(it.fi, s, cost+it.se, hg+1);
    }
    tout[s]=timer++;
}
// checks if u is ancessor of v or not
bool isAns(int u, int v) {
    return (tin[u]<=tin[v] && tout[u]>=tout[v]);
}
// gives LCA of u and u node
int lca(int u, int v, int n) {
    if(isAns(u,v)) return u;
    
    if(isAns(v,u)) return v;
    
    int l=ceil(log2(n));
    // binary lifting 
    for(int i=l;i>=0;--i) {
        if(!isAns(anc[u][i],v)) u=anc[u][i];
    }
    return anc[u][0];
}

int main()
{
     boost
     int t; cin >> t;
     while(t--) {
	
        int n; cin >> n; 
        initialise();
         for(int i=0;i<n-1;i++) {
             int u,v,w; cin >> u >> v >> w; --u, --v;
             adj[u].pb({v,w}), adj[v].pb({u,w});
         }
         dfs();
         int q; cin >> q; 
         while(q--)
         {
             string s; cin >> s;
             if(s[0]=='D') {
                int x,y; cin >> x >> y; --x,--y;
                int dist=minC[x]+minC[y]-2*minC[lca(x,y,n)];
                 cout<<dist<<endl;
             }
             else
             {
                 int x,y,k; cin >> x >> y >> k; --x; --y;
                 if(h[x]-h[lca(x,y,n)]+1>=k) {
                     k--;
                     for(int i=0;i<32;i++)
                     {
                          if(k&(1<<i))
                             x=anc[x][i];
                     }
                     
                     cout<<x+1<<endl;
                 }
                 else
                 {
                    k=h[x]+h[y]-2*h[lca(x,y,n)]-k+1;
                    for(int i=0;i<32;i++) {
                          if(k&(1<<i))
                            y=anc[y][i];
                     }
                     cout<<y+1<<endl;
                 }
             }
             
         }
        
         
     }
   return 0;
}
