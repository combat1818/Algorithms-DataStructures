#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  int n,a,i,j,out=0,m;
  vector<int> t;
  cin>>n;
  
  for(i=1;i<=n;i++){
    cin>>a;
    t.push_back(a);
    out+=a;
  }
  sort(t.begin(),t.end());

  m=n;
  if(n%2==0){
    m/=2;
    m--;
    for(i=0;i<=m;i++) 
      out-=t[i];
    for(i=m+1;i<t.size();i++)
      out+=t[i]; 
  }else{
    m/=2;
    m--;
    for(i=0;i<=m;i++)
      out-=t[i];
    for(i=m+2;i<t.size();i++)
      out+=t[i]; 
  }
  cout<<out;
}