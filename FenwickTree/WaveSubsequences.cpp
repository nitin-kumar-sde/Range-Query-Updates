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

const int  N=(int)1e5+5;
vl arr(N);
ll BIT[3][N+1];

void update(ll val, ll ind, int i) {
    for(; ind<=N; ind+=(ind&(-ind))) {
        BIT[i][ind]+=val;
        BIT[i][ind]%=mod;
    }
}

ll query(ll ind, int i) {
    ll sum=0;
    for(; ind>0;ind-=(ind&(-ind))) {
        sum+=BIT[i][ind];
        sum%=mod;
    }
    return sum;
}

int main()
{
    boost
    ll n; cin >> n ;
    for(int i=0;i<n;i++) cin >> arr[i]; 
    clr(BIT);

    ll ans=0;

    for(int i=0;i<n;i++) {

        ll a = query(arr[i]-1,0);
        ll b = query(N,1) - query(arr[i],1);
        
        b=(b%mod+mod)%mod;
        ans+=(a+b);    
        ans%=mod;      
        update(a+1,arr[i],1); update(b+1,arr[i],0);
    }
    
    cout<<ans<<endl;

   return 0;
}
