#include <bits/stdc++.h>
using namespace std;
class qry
{
    public:
    int first,second,index;
};
bool comp(qry q1 ,qry q2) {  
    if(q1.second==q2.second)
    return (q1.first<q2.first);

    return (q1.second<q2.second);
}
int arr[30001];
int last[1000001];
int ans[200001];
int bit[30001]={0};
qry qr[200001];

void update(int ind, int val, int n ) {
   for(;ind<=n;ind+=(ind&(-ind)))
   bit[ind]+=val;
}

int query(int ind) {
    int s=0;
    for(;ind>0 ; ind-=(ind&(-ind)))
    s+=bit[ind];
    
    return s;
}
int main()
{
   int n; cin >> n;

   memset(last,-1,sizeof(last));
    
   for(int i=1;i<=n;i++) cin >> arr[i];
    
   int q; cin >> q;
  
  for(int i=0;i<q;i++) {
     cin >> qr[i].first;
     cin >> qr[i].second;
     qr[i].index=i;
  }
    
  sort(qr,qr+q, comp);
  int total=0;
  int ind=0;
  for(int i=1;i<=n;i++) {
      if(last[arr[i]]!=-1) update(last[arr[i]],-1,n);
      else total++;
      
      last[arr[i]]=i;
      
      update(i,1,n);
      
      while(ind <q && qr[ind].second== i ) {
          ans[qr[ind].index]=total-query(qr[ind].first-1);
          ind++;
      }
      
    
  }
  
    for(int i=0;i<q;++i)
    cout<<ans[i]<<endl;
  
    
    return 0;
}
