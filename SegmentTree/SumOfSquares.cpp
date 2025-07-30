#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll ,ll >
#define fr first
#define se second
void buildTree(ll arr[], pll tree[], ll start, ll end ,ll startIndex)
{
    
    if(start==end) {
        tree[startIndex].fr=arr[start];
        tree[startIndex].se=arr[start]*arr[start];
        return ;
    }
    
    ll mid=(start + end)>>1;
    
    buildTree(arr,tree,start,mid,2*startIndex);
    buildTree(arr,tree ,mid+1 , end, 2*startIndex+1);
    
    tree[startIndex].fr=tree[2*startIndex].fr+tree[2*startIndex+1].fr;
    
    tree[startIndex].se=tree[2*startIndex].se+tree[2*startIndex+1].se;
    
}
void updateTree(pll tree[], pll lazy[], ll low , ll high , ll treeNode, ll qtype, ll left,ll right,ll val) {   
    
    if(high<low) return ;
    // propogate lazy 
    if(lazy[treeNode].fr!=0) {   
        ll x=lazy[treeNode].fr;
        tree[treeNode].fr=x*(high-low+1);
        tree[treeNode].se=x*x*(high-low+1);

        if(low!=high) {
            lazy[2*treeNode].fr=x;
            lazy[2*treeNode+1].fr=x;
            lazy[2*treeNode].se=0;
            lazy[2*treeNode+1].se=0;
        }
        lazy[treeNode].fr=0; 
    }
    
    if(lazy[treeNode].se!=0) {
        ll x=lazy[treeNode].se;
        tree[treeNode].se+=(2*x*(tree[treeNode].fr)+x*x*(high-low+1));
        tree[treeNode].fr+=(x*(high-low+1));
        if(low!=high) {
            lazy[2*treeNode].se+=x;
            lazy[2*treeNode+1].se+=x;
        }
        
        lazy[treeNode].se=0;
    }
  
    if(right<low||left>high) return;

    if(left<=low&&right>=high)
    {
        if(qtype==0)
        {
            tree[treeNode].fr=(high-low+1)*val;
            tree[treeNode].se=(high-low+1)*val*val;
            if(low!=high) {
                lazy[2*treeNode].fr=val;
                lazy[2*treeNode+1].fr=val;
                lazy[2*treeNode].se=0;
                lazy[2*treeNode+1].se=0;
            }
        }
        else {
            tree[treeNode].se+=(val*val*(high-low+1)+2*val*(tree[treeNode].fr));
            tree[treeNode].fr+=((high-low+1)*val);
            if(low!=high) {
                lazy[2*treeNode].se+=val;
                lazy[2*treeNode+1].se+=val;
            }
        }
        return;
    }
    
    ll mid=(low+high)>>1;
    updateTree(tree, lazy,low,mid ,2*treeNode,qtype, left,right,val);
    updateTree(tree,lazy,mid+1,high,2*treeNode+1,qtype,left,right,val);
    
    tree[treeNode].fr=tree[2*treeNode].fr+tree[2*treeNode+1].fr;
    tree[treeNode].se=tree[2*treeNode].se+tree[2*treeNode+1].se;
    
}
pll query(pll tree[], pll lazy[], ll low , ll high , ll treeNode, ll left, ll right)
{
     if(high<low) return {0,0};
    
     if(lazy[treeNode].fr!=0) {   
        ll x=lazy[treeNode].fr;
        lazy[treeNode].fr=x*(high-low+1);
        lazy[treeNode].se=x*x*(high-low+1);
        if(low!=high) {
            lazy[2*treeNode].fr=x;
            lazy[2*treeNode+1].fr=x;
            lazy[2*treeNode].se=0;
            lazy[2*treeNode+1].se=0;
        }
        lazy[treeNode].fr=0;
    }
    
    if(lazy[treeNode].se!=0) {
        ll x=lazy[treeNode].se;
        tree[treeNode].se+=(2*x*(tree[treeNode].fr)+x*x*(high-low+1));
        tree[treeNode].fr+=(x*(high-low+1));
        if(low!=high) {
            lazy[2*treeNode].se+=x;
            lazy[2*treeNode+1].se+=x;
        }
        
        lazy[treeNode].se=0;
    }
  if(right<low||left>high) return {0,0};
    
  if(left<=low&&right>=high ) return tree[treeNode];
  
  ll mid=(high+low)>>1;
    
  pll ans1=query(tree, lazy, low, mid, 2*treeNode, left, right);
  pll ans2=query(tree, lazy, mid+1, high, 2*treeNode+1, left, right);

  pll ans;
  ans.fr=ans1.fr+ans2.fr;
  ans.se=ans2.se+ans1.se;
  return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    ll t; cin>>t;
    ll arr[100001];
    pll tree[300005];
    pll lazy[300005];
   
    for(int T=1; T<=t;T++)
    {
        ll n,q;
        cin>>n>>q;
        for(int i=0;i<n;i++)
        cin>>arr[i];
       
      for(int i=0;i<4*n;i++)   lazy[i].fr = lazy[i].se=0;
      buildTree(arr, tree , 0, n-1, 1);
        while(q--) {
           ll qtype;
           cin>>qtype;
            if(qtype==2)
            {
                ll j,k,l; cin>>j>>k;
               cout<<query(tree,lazy,0,n-1,1,j-1,k-1).se<<endl; 
            }
            else if(qtype==1 || qtype==0)
            {
               ll j,k,l;
               cin>>j>>k>>l;
               updateTree(tree, lazy, 0, n-1, 1, qtype, j-1, k-1,l);
                
            }
            
        }
        
        
    }
    return 0;
	
}
