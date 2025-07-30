#include<bits/stdc++.h>
using namespace std;

void buildTree(int arr[],int tree[],int start,int end,int treeNode)
{
  if(start==end)
  {
  	tree[treeNode]=arr[start];
  	return;
  }
    int mid=(start+end)>>1;
	buildTree(arr,tree,start,mid,2*treeNode);
	buildTree(arr,tree,mid+1,end,2*treeNode+1);
	
    int diff= end-mid;
    if(diff%2==0)
     tree[treeNode]=(tree[2*treeNode]+tree[2*treeNode+1])%3;
    else
     tree[treeNode]=(tree[2*treeNode]*2+tree[treeNode*2+1])%3;
    
}
void updateTree(int arr[],int tree[],int start,int end,int treeNode,int index)
{
	if(start==end)
	{
		arr[index]=1;
		tree[treeNode]=1;
		return ;

	}
	int mid=(start+end)/2;
		if(index>mid)
		updateTree(arr,tree,mid+1,end,2*treeNode+1,index);
	else
		updateTree(arr,tree,start,mid,2*treeNode,index);
	
    int diff= end-mid;
    if(diff%2==0)
     tree[treeNode]=(tree[2*treeNode]+tree[2*treeNode+1])%3;
    else
     tree[treeNode]=(tree[2*treeNode]*2+tree[treeNode*2+1])%3;
}


 int query(int tree[],int start,int end ,int treeNode ,int left ,int right)
 {
        //completely outside the given range
      if(left>end|| right<start) return 0;

       // completely inside the given range
      if(start>=left&&end<=right) return tree[treeNode];
   
      int mid=(end+start)/2;
      int ans1=query(tree,start,mid,2*treeNode,left,right);
      int ans2=query(tree,mid+1,end,2*treeNode+1,left,right);
       int diff=min(right,end)-mid;
      if(diff%2==1) return (ans1*2+ans2)%3;
      return (ans1+ans2)%3;
     
}

int main() 
{

    int n;
    cin>>n;
    string s;
    cin>>s;
    int arr[100001];
    
    for(int i=0; i<n; i++)
       arr[i]=s[i]-'0';
    int tree[300003];
    
    buildTree(arr, tree, 0, n-1, 1);
    
    int m;
    cin>>m;
    while(m--)
    {
       int t,u,v;
       cin>>t>>u;
       if(t==0){
          cin>>v; cout<<query(tree,0,n-1,1,u,v)<<endl;
       }
       else updateTree(arr,tree, 0, n-1,1,u);
    }
    
    
  return 0;
    
}
