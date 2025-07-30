#include<bits/stdc++.h>
using namespace std;
class node
{
    public:
    int sum;
    int suff;
    int pref;
    int msum;
};
void buildTree( int arr[] ,node tree[] ,int start, int end, int treeNode)
{
    if(start==end)
    {
        tree[treeNode].sum=tree[treeNode].pref= tree[treeNode].suff = tree[treeNode].msum=arr[start];
        return;
    }
    
    
    int mid=(start+end)/2;
    
    buildTree(arr, tree ,start,mid ,2*treeNode);
    buildTree(arr ,tree, mid+1, end,2*treeNode+1);
    node left=tree[2*treeNode];
    node right=tree[2*treeNode+1];

    tree[treeNode].sum=right.sum+left.sum;
    tree[treeNode].pref=max(left.pref,left.sum+right.pref);
    tree[treeNode].suff=max(right.suff,right.sum+left.suff);
    tree[treeNode].msum=max(left.suff+right.pref,max(left.msum,right.msum));
}
 node query(node tree[],int start,int end ,int treeNode ,int left ,int right)
 {
        //completely outside the given range
      if(left>end|| right<start) {
             node smallAns;
             smallAns.sum=0;
             smallAns.msum=smallAns.suff=smallAns.pref=-1e9;
             return smallAns;
         }

       // completely inside the given range
      if(start>=left &&right>=end) return tree[treeNode];
      int mid=(end+start)/2;

      node l=query(tree,start,mid,2*treeNode,left,right);
      node r=query(tree,mid+1,end,2*treeNode+1,left,right);
      node ans;
      ans.sum=r.sum+l.sum;
      ans.pref=max(l.pref,l.sum+r.pref);
      ans.suff=max(r.suff,r.sum+l.suff);
      ans.msum=max(l.suff+r.pref,max(l.msum,r.msum));
      return ans; 
 }

int main() 
{

    int n;
    cin>>n;
    int arr[100001];
    for(int i=0;i<n;i++) cin>>arr[i];
    node tree[300003];
    buildTree(arr,tree ,0,n-1, 1);
    int m;
    cin>>m;
    while(m--)
    {
        int x,y;
        cin>>x>>y;
        node ans=query(tree,0,n-1,1,x-1,y-1);
        cout<<ans.msum<<endl;
    }
    
    
    
  return 0;
}
