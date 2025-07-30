#include <bits/stdc++.h>
using namespace std;
#define boost ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int

const int N=1e5+5;
ll  arr[N];
ll tree[4*N];
ll lazy[4*N];

void updateLazy(int start , int end , int node , int l , int r , ll val)
{
    // check for pending updates      
    if(lazy[node]!=0)
    {
        tree[node]+=(lazy[node]*(end-start+1));
        
        if(start!=end)
        {
            lazy[node<<1]+=lazy[node];
            lazy[node<<1|1]+=lazy[node];
        }
        lazy[node]=0;
    }
    
    if(start > r or l > end) return ;
    
    if(l<=start and end <= r)
    {
        tree[node]+=((end-start+1)*(val));
        if(start!=end)
        {
            lazy[node<<1]+=val;
            lazy[node<<1|1]+=val;
        }
        return;  
    }
    int mid=(start+end)>>1;
    
    updateLazy(start,mid,node<<1,l,r,val);
    updateLazy(mid+1,end,node<<1|1,l,r,val);
    tree[node]=tree[node<<1]+tree[node<<1|1];
}
ll queryLazy(int start, int end , int node, int l, int r) {
	// check for pending updates      
	if(lazy[node]!=0)
    {
        tree[node]+=(lazy[node]*(end-start+1));
        if(start!=end)
        {
            lazy[node<<1]+=lazy[node];
            lazy[node<<1|1]+=lazy[node];
        }
        lazy[node]=0;
    }
     
    if(start > r or l > end)
    return 0;
    if(l<=start and end <= r)
    return tree[node];
    
    int mid=(start+end)>>1;
    ll q1=queryLazy(start,mid,node<<1,l,r);
    ll q2=queryLazy(mid+1,end,node<<1|1,l,r);
    return (q1+q2); 

}
int main()
{
    int t; cin >> t;
    
    while(t--) {       
    int n; cin >> n;
    for(int i=0;i<n;i++) arr[i]=0;
    for(int i=0;i<4*n;i++) lazy[i]=tree[i]=0;

    int q; cin >> q;
    while(q--) {
    	ll x,y,z;
    	cin >> x >> y >> z;
        if(x==0) {
            ll v;cin >> v;
            updateLazy(0,n-1,1,y-1,z-1,v);
        }
        else  cout << queryLazy(0,n-1,1,y-1,z-1) << endl;
    }
}   
   return 0;
}
