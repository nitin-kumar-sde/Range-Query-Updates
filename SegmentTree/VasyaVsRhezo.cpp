#include<bits/stdc++.h>
using namespace std;
#define MAXN 1000001
void buildTree(int arr1[], int arr2[],int tree[],int start,int end,int treeNode)
{
  if(start==end)
  {
     tree[treeNode]=start;
     return; 
  }
    int mid=(start+end)>>1;
	buildTree(arr1,arr2,tree,start,mid,2*treeNode);
	buildTree(arr1,arr2,tree,mid+1,end,2*treeNode+1);
	
    int k1=tree[2*treeNode];
    int k2=tree[2*treeNode+1];
    
    if(arr1[k1]>arr1[k2])
        tree[treeNode]=k1;
    else if(arr1[k2]>arr1[k1])
        tree[treeNode]=k2;
    else
    {
        if(arr2[k1]>arr2[k2])
         tree[treeNode]=k2;
        else if(arr2[k1]<arr2[k2])
            tree[treeNode]=k1;
        else
            tree[treeNode]=k1;
           
    }
}
int query(int arr1[],int arr2[],int tree[],int start,int end ,int treeNode ,int left ,int right)
 {
    if(left>end|| right<start) return -1;

    if(start>=left &&right>=end) return tree[treeNode];
      
	int mid=(end+start)/2;
    int k1=query(arr1,arr2,tree,start,mid,2*treeNode,left,right);
    int k2=query(arr1,arr2,tree,mid+1,end,2*treeNode+1,left,right);
    
    int ans=0;
     
	if(k1==-1) ans=k2;
    else if(k2==-1)ans=k1;
    else {
    if(arr1[k1]>arr1[k2]) ans=k1;
    else if(arr1[k2]>arr1[k1]) ans=k2;
    else {
        if(arr2[k1]>arr2[k2]) ans=k2;
        else if(arr2[k1]<arr2[k2]) ans=k1;
        else ans=k1;
		}     
    }
    return ans;
 }

int main() 
{
    int n;
    cin>>n;
    
    int arr1[MAXN];
    for(int i=0;i<n;i++) cin>>arr1[i];
    
    int arr2[MAXN];
    for(int i=0;i<n;i++) cin>>arr2[i];
    int tree[3*MAXN];

    buildTree(arr1,arr2,tree,0,n-1,1);
    
    int q;
    cin>>q;
    
    while(q--) {
     int l,r; cin>>l>>r;
     int k=query(arr1,arr2,tree,0,n-1,1,--l,--r);
     cout<<k+1<<endl;    
    }
  
  return 0;
}
