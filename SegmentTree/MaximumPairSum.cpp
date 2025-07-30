#include<bits/stdc++.h>
#define ll long long
using namespace std;
class node{
  public:
     ll max;
     ll smax;
};
void buildTree(ll *arr,node *tree,int start,int end,int treeNode)
{
    if(start==end)
    {
        tree[treeNode].max=arr[start];
        tree[treeNode].smax=-1e10;
        return;
    }
    int mid=(start+end)/2;
    buildTree(arr,tree,start,mid,2*treeNode);
    buildTree(arr,tree,mid+1,end,2*treeNode+1);
    node left=tree[2*treeNode];
    node right=tree[2*treeNode+1];
    tree[treeNode].max=max(left.max,right.max);
    tree[treeNode].smax=max(min(left.max,right.max),max(right.smax,left.smax));
    
}
void update(ll *arr,node *tree,int start,int end,int treeNode,int idx,ll value)
{
    if(start==end)
    {
        arr[start]=value;
        tree[treeNode].max=arr[start];
        return;
    }
    int mid=(start+end)/2;
    if(idx > mid)
        update(arr,tree,mid+1,end,2*treeNode+1,idx,value);
    else
       update(arr,tree,start,mid,2*treeNode,idx,value);
    
    node left=tree[2*treeNode];
    node right=tree[2*treeNode+1];
    tree[treeNode].max=max(left.max,right.max);
    tree[treeNode].smax=max(min(left.max,right.max),max(right.smax,left.smax));
    
}
node query(node *tree,int start,int end,int treeNode,int left,int right)
{
    if(left>end || start>right)
    {
        node ans;
        ans.max=-1e10;
        ans.smax=-1e10;
        return ans;
    }
    if(start>=left && end<=right)
    {
        return tree[treeNode];
    }
    int mid=(start+end)/2;
    node p1=query(tree,start,mid,2*treeNode,left,right);
    node p2=query(tree,mid+1,end,2*treeNode+1,left,right);
    node ans;
    ans.max=max(p1.max,p2.max);
    ans.smax=max(min(p1.max,p2.max),max(p1.smax,p2.smax));
    
    return ans;
    
}
int main() {

	// Write your code here
    int n;
    cin>>n;
    ll *arr=new ll[n+5];
    for(int i=0;i<n;i++) cin>>arr[i];
    node *tree=new node[3*n + 5];
    buildTree(arr,tree,0,n-1,1);
    int q;
    cin>>q;
    char ch;
    ll l,r;
    while(q--)
    {
        cin>>ch>>l>>r;
        if(ch=='Q')
        {
            node ans=query(tree,0,n-1,1,l-1,r-1);
            cout<<ans.max+ans.smax<<endl;
        }
        else if(ch=='U')
        {
            update(arr,tree,0,n-1,1,l-1,r);
        }
        
    }
    
    delete []arr;
    delete []tree;
    return 0;
}
