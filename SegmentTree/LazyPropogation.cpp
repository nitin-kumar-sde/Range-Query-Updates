#include<bits/stdc++.h>
using namespace std;

void buildTree(int* arr,int* tree,int start,int end,int treeNode){

	if(start == end){
		tree[treeNode] = arr[start];
		return;
	}
	int mid = (start+end)/2;

	buildTree(arr,tree,start,mid,2*treeNode);
	buildTree(arr,tree,mid+1,end,2*treeNode+1);
	tree[treeNode] = min(tree[2*treeNode],tree[2*treeNode+1]);
}

int querySegmentTreeLazy(int* tree, int* lazy, int start, int end, int startR, int endR, int currPos) {
    // Apply any pending updates
    if (lazy[currPos] != 0) {
        tree[currPos] += lazy[currPos];
        if (start != end) {
            lazy[2 * currPos] += lazy[currPos];
            lazy[2 * currPos + 1] += lazy[currPos];
        }
        lazy[currPos] = 0;
    }

    // No overlap
    if (startR > end || endR < start)
        return INT_MAX;

    // Complete overlap
    if (startR <= start && end <= endR)
        return tree[currPos];

    // Partial overlap
    int mid = (start + high) / 2;
    int leftAns = querySegmentTreeLazy(tree, lazy, start, mid, startR, endR, 2 * currPos);
    int rightAns = querySegmentTreeLazy(tree, lazy, mid + 1, end, startR, endR, 2 * currPos + 1);
    return min(leftAns, rightAns);
}


void updateSegmentTreeLazy(int* tree,int* lazy,int low,int high,int startR,int endR,int currPos,int inc){

	if(low > high){
		return;
	}

	if(lazy[currPos] !=0){
		tree[currPos] += lazy[currPos];

		if(low!=high){
			lazy[2*currPos] += lazy[currPos];
			lazy[2*currPos+1] += lazy[currPos];
		}
		lazy[currPos] = 0;
	}

	// No overlap
	if(startR > high || endR < low){
		return;
	}

	// Complete Overlap

	if(startR<= low && high <= endR){
		tree[currPos] += inc;
		if(low!=high){
			lazy[2*currPos] += inc;
			lazy[2*currPos+1] += inc;
		}
		return;
	}
  
	int mid = (low+high)/2;
	updateSegmentTreeLazy(tree,lazy,low,mid,startR,endR,2*currPos,inc);
	updateSegmentTreeLazy(tree,lazy,mid+1,high,startR,endR,2*currPos+1,inc);
	tree[currPos] = min(tree[2*currPos],tree[2*currPos+1]);
}

int main(){

	int arr[] = {1,3,-2,4};
	int* tree = new int[12]();
	buildTree(arr,tree,0,3,1);
  // lazy array track range updates
	int* lazy = new int[12]();
	updateSegmentTreeLazy(tree,lazy,0,3,0,3,1,3);
	updateSegmentTreeLazy(tree,lazy,0,3,0,1,1,2);

	for(int i=1;i<12;i++){
		cout<<tree[i]<< endl;
	}

  for(int i=1;i<12;i++){
		cout<<lazy[i]<< endl;
	}
	
	return 0;
}
