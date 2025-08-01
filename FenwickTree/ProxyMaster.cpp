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


const  int N=1e7;
ll BIT[N+1]={0};
ll sieve[N+1]={0};

void update(ll ind, ll val, ll  n)
{
    for(;ind<=n;ind+=(ind&(-ind)))
    {
        BIT[ind]+=val; 
        BIT[ind]%=mod;   
    }
}

ll queryBIT(ll ind)
{
    ll sum=0;
    for(;ind>0;ind-=(ind&(-ind)))
    {
        sum+=BIT[ind];
        sum%=mod;
    }
    return sum;
}

class query
{
    public:
    ll l,r,ind, val;
};

vector<pii> input;
vl ans(N);
vector<query> queries;
int main() {
    boost

    // compute the sum of primes divisors of a number
    for(int i=2; i<=N;i++) {
        if(!sieve[i]) {
            for(int j=i;j<=N;j+=i) sieve[j]+=i;
        }
    }
    
    int n,q; cin >> n >> q;
    
    for(int i=1;i<=n;i++) {
        ll foo; cin >> foo;
        input.push_back({sieve[foo], i});
    }
    sort(input.begin(), input.end(), [](pii a, pii b){
        return a.first > b.first;
    });

    for(int i=0;i<q;i++) {
        query q; cin >> q.l >> q.r >> q.val;  q.ind = i;
        queries.push_back(q);
    }
    
    sort(queries.begin(), queries.end(), [](query p, query q){
        return p.val > q.val;
    });
    
    int i = 0;
    for (int j = 0; j < q; j++) {
         while (i < n && input[i].first > queries[j].val) {
              update(input[i].second, 1LL * input[i].first * input[i].second, n);
              i++;
          }

         ans[queries[j].ind] = (queryBIT(queries[j].r) - queryBIT(queries[j].l - 1) + mod) % mod;
   }
    for(int i=0; i <q; i++)cout<<ans[i]<<endl;

   return 0;
}
