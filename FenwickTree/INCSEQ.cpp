#include <bits/stdc++.h>
using namespace std;
#define boost ios_base::sync_with_stdio(false);cin.tie(NULL);

const int N=(int)1e4+5;
#define ll long long
vector<long long>  arr(N);
#define clr(x) memset(x, 0, sizeof(x))

ll BIT[51][N];
ll dp[51][N];
int mod = 5000000;

void update(ll ind, ll i, ll val) {
   
    for(;ind<N-1;ind+=(ind&(-ind)))
    {
         BIT[i][ind]+=val; 
         BIT[i][ind]%=mod;
    }
    
}
ll query(ll ind, ll i)
{
    ll sum=0;
    for(;ind>0;ind-=(ind&(-ind)))
    {
        sum+=BIT[i][ind];
       sum%=mod;
    }
    return sum;
}
int main()
{
    boost
    clr(BIT);
    clr(dp);    
    ll n,k; cin >> n >> k; 
    
    // coordinate compression
    set<ll> s; 
    for(int i = 0; i < n; i++) { 
        ll foo; 
        cin >> foo;
        s.insert(foo); 
        arr[i]=foo;
    }
   
    map<ll,ll> mp;
    auto it=s.begin();
    int z=1;
    while(it!=s.end())
    {
       mp[*it]=z; it++; z++;
    }
    ll ans=0;
    for(int i=0;i<n;i++) arr[i]=mp[arr[i]];

    for(ll i=0;i<n;i++) { 
        dp[1][i]=1;
        update(arr[i],1,1);
        for(ll j=2;j<=min(i+1,k);j++) {
            ll foo=query(arr[i]-1,j-1); 
            dp[j][i]=foo;
            update(arr[i],j,foo);
        }
        ans+=dp[k][i];
        ans%=mod;
    }
   cout<<ans<<endl;
   return 0;
}
