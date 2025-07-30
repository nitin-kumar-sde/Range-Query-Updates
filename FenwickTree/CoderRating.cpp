#include <bits/stdc++.h>
using namespace std;
class coder
{
    public:
    int x,y,ind;
};

int bit[100001]={0};
bool comp(coder c1, coder c2)
{
    if(c1.x==c2.x)
    return (c1.y<c2.y);
    
    return (c1.x<c2.x);
}
void update(int index )
{
    for(;index<=100000;index+=(index & (-index)))
        bit[index]++;
}

// gives numbers in [1 - index]
int query(int index)
{
    int z=0;
    for(;index>0; index-=(index & (-index)))
        z+=(bit[index]);
    return z;
}

int main()
{
      int n; cin >> n;

      coder * arr= new coder [n];
    
      for(int i=0;i<n;i++) cin >> arr[i].x, cin >> arr[i].y , arr[i].ind=i;
    
      sort(arr,arr+n, comp);
    
      int * rank =new int[n];
      for(int i=0;i<n;i++) rank[i]=0;
    
      int i = 0;
      while(i<n){     

              int k=query(arr[i].y);
              int j=i;
              // process equal elements together
              while(i<n and arr[i].x== arr[j].x and arr[i].y == arr[j].y) j++;
              while(i!=j) rank[arr[i].ind]=k,  update(arr[i].y), i++;
      }
 
    for(int i=0;i<n;i++)
    cout<<rank[i]<<endl;

    return 0;
}
