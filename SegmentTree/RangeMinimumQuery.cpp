#include<bits/stdc++.h>

using namespace std;

void buildTree(int *arr,int *tree,int start,int end,int treeNode)
{
    if(start==end)
    {
        tree[treeNode]=arr[start];
        return;
    }
    int mid=(start+end)/2;
    buildTree(arr,tree,start,mid,2*treeNode);
    buildTree(arr,tree,mid+1,end,2*treeNode+1);
    tree[treeNode]=min(tree[2*treeNode],tree[2*treeNode+1]);
    
}
void update(int *arr,int *tree,int start,int end,int treeNode,int idx,int value) {
    if(start==end)
    {
        arr[idx]=value;
        tree[treeNode]=value;
        return;
    }
    int mid=(start+end)/2;
    if(idx > mid)
    update(arr,tree,mid+1,end,2*treeNode+1,idx,value);
    else
    update(arr,tree,start,mid,2*treeNode,idx,value);

    tree[treeNode]=min(tree[2*treeNode],tree[2*treeNode+1]);
    
}
int query(int *tree,int start,int end,int treeNode,int left,int right) {
    
    if(start>right || end<left)
    return INT_MAX;

    if(left<=start && right>=end)
     return tree[treeNode];

    int mid=(start+end)/2;
    int p1=query(tree,start,mid,2*treeNode,left,right);
    int p2=query(tree,mid+1,end,2*treeNode+1,left,right);
    return min(p1,p2);
}

int main() {

    int n,q;
    cin>>n>>q;
    int *arr=new int[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    int *tree=new int[3*n+5];
    buildTree(arr,tree,0,n-1,1);

    while(q--) {
        char ch;
        int l,r;
        cin>>ch>>l>>r;
        if(ch=='q') cout<<query(tree,0,n-1,1,l-1,r-1)<<endl;
        else update(arr,tree,0,n-1,1,l-1,r);      
    }
    return 0;
}

