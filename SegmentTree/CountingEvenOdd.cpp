#include <bits/stdc++.h>
using namespace std;

void buildTree(int *arr,int *tree,int start,int end,int treeNode)
{
    if(start==end) {
        tree[treeNode]=arr[start] & 1;
        return;
    }
    int mid=(start+end)/2;
    buildTree(arr,tree,start,mid,2*treeNode);
    buildTree(arr,tree,mid+1,end,2*treeNode+1);
    
    tree[treeNode]= tree[2*treeNode] + tree[2*treeNode+1];
}
void update(int *arr,int *tree,int start,int end,int treeNode,int idx,int value) {
    if(start==end) {
        arr[idx]=value;
        tree[treeNode]=value&1;
        return;
    }
    int mid=(start+end)/2;
    if(idx > mid)
    update(arr,tree,mid+1,end,2*treeNode+1,idx,value);
    else
    update(arr,tree,start,mid,2*treeNode,idx,value);

    tree[treeNode]=tree[2*treeNode] + tree[2*treeNode+1];
    
}
int query(int *tree,int start,int end,int treeNode,int left,int right) {
    
    if(start>right || end<left)
    return 0;

    if(left<=start && right>=end)
     return tree[treeNode];

    int mid=(start+end)/2;
    int p1=query(tree,start,mid,2*treeNode,left,right);
    int p2=query(tree,mid+1,end,2*treeNode+1,left,right);
    return p1 + p2;
}


int main()
{
    int n, q;
    cin >> n;
    int arr[100001];
    for(int i = 0; i < n; i++) cin >> arr[i];
    cin >> q;
    int tree[300005];
    buildTree(arr, tree, 0, n - 1, 1);

    int l, r, ch;

    while(q--) {
        cin >> ch >> l >> r;
        if(ch == 2) cout << query(tree, 0, n - 1 , 1, l - 1, r - 1) << endl;
        else if(ch == 1)  cout << r - l + 1 - query(tree, 0, n - 1 , 1, l - 1, r - 1) << endl;
        else if (ch == 0) update(arr, tree, 0, n - 1, 1, l - 1, r);
    }
    return 0;
}
