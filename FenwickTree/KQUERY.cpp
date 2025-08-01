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
#define PI 3. 
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define vi vector<int> 
#define vl vector<ll>
#define vii vector<pii>
#define vll vector<pll>
pair<ll,ll>s4[4]={{-1,0},{1,0},{0,-1},{0,1}};
pair<ll,ll>s8[8]={{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,1},{1,0},{1,-1}};

const int N=30000+10;

vector<int> BIT(N,0);

void  update(ll ind, ll val, ll n) {
    for(; ind<=n; ind+=(ind&(-ind)))
        BIT[ind]+=val;   
}
ll query(ll ind) {
    ll sum=0;
    for(; ind>0; ind-=(ind&(-ind)))
    sum+=BIT[ind];
    return sum;
}
class event
{
    public:
    int l,r,ind,val;
};

vector<event>  queries;
vector<pii>  input;

bool comp(event e1,event e2){
    return e1.val > e2.val;
}
vector<int> ans(200000+10);
int main()
{
    boost
    int n; cin >> n;  
    
   for(int i=1;i<=n;i++) {
       int temp; cin >> temp;
	   input.push_back({temp, i});
    }
   sort(input.begin(), input.end(), [](pii a, pii b) {
       return a.first > b.first;
   });

    int q; cin >> q; 
    
    for(int i=0;i<q;i++) {
		event e;
        cin >> e.l >> e.r >> e.val; e.ind = i;
        queries.pb(e);
    }
    
    sort(queries.begin(), queries.end(), [](event e1, event e2){
		return e1.val > e2.val;
	});
    
  
    int i = 0;
    for (int j = 0; j < q; j++) {
    while (i < n && input[i].first > queries[j].val) {
        int idx = input[i].second;
        update(idx, 1, n);
        i++;
    }

    ans[queries[j].ind] = query(queries[j].r) - query(queries[j].l - 1);
}

    for(int i=0;i<q;i++)
    cout<<ans[i]<<endl;

   return 0;
}
