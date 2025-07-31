#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define FR(i,a,b) for(ll i=(ll) a; i<=(ll)b ;i++)
const int N= 200005;
char C[N];
ll A[N];
ll BIT[N]={0};
ll sip[N]={0};

void update(ll val, ll ind, ll n)
{
    for(;ind<=n;ind+=(ind&(-ind)))
    BIT[ind]+=val;
}
ll query(ll  ind)
{
    ll sum=0;
    for(;ind>0;ind-=(ind&(-ind)))
    sum+=BIT[ind];
    return sum;
    
}
int main()
{
   
    ll q;
    cin >> q;
    set<ll> s;
    unordered_map<ll,ll> mp;

    for(int i=0;i<q;i++) {
        cin >> C[i] >> A[i];
        s.insert(A[i]);
    }
    
  
    
    ll k=1;
    // co - ordinate compression
    auto it=s.begin();
    while(it!=s.end()) {
        ll val=*it;
        sip[k]=val;
        mp[val]=k;
        k++;
        it++;
    }

    ll n=s.size();
    for(int i=0;i<q;i++)
    {
        if(C[i]=='I') {
            // get compressed mapping
            ll index=mp[A[i]];
            //check whether it exits in BIT or not
            if(query(index)==query(index-1))
            update(1,index,n);
            
        }
        if(C[i]=='D'){   
            ll index=-1;
            if(mp.count(A[i])==1) index=mp[A[i]];
            // remove if element exists in BIT
            if(index!=-1 && query(index)!=query(index-1))
            update(-1,index,n);    
        }
        // use binary search to find the index and decompress it
        if(C[i]=='K') {
           
            ll low=1;
            ll ans=-1;
            ll high=n;
            while(low<=high)
            {
                ll mid=(low+high)>>1;
                
                if(query(mid)==A[i] and query(mid-1)!=A[i]) {
                    ans=mid;
                    break; 
                }
                else if(query(mid)<A[i])
                    low=mid+1;
                else
                    high=mid-1;
            }
            if(ans==-1)cout<<"invalid"<<endl;
            else cout<<sip[ans]<<endl;
        }

        if(C[i]=='C') {
            ll index=mp[A[i]]; index--;
            cout<<query(index)<<endl;
        }
     
    }
    
    return 0;
}
