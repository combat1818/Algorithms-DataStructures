#include<iostream>
#include<algorithm>
using namespace std;
 
const int N_MAX=65536;
int obc[2*N_MAX], max_obc[2*N_MAX];//,brute[2*N_MAX];
 
void insert(int a, int b, int v)
{
    int l=N_MAX+a, r=N_MAX+b;
    obc[l]+=v;
    max_obc[l]+=v;
    if(l!=r){
        obc[r]+=v;
        max_obc[r]+=v;
    }
   
    while(l>=1){
        if(l<r-1){
           
            if(l%2==0){
                obc[l+1]+=v;
                max_obc[l+1]+=v;
            }
           
            if(r%2==1){
                obc[r-1]+=v;
                max_obc[r-1]+=v;
            }
        }
       
        if(r<N_MAX){
            max_obc[l]=max(max_obc[2*l],max_obc[2*l+1])+obc[l];
            max_obc[r]=max(max_obc[2*r],max_obc[2*r+1])+obc[r];
        }
        l/=2; r/=2;
    }
}
 
void print(){
    for(int i=0;i<2*N_MAX;i++) cout<<obc[i]<<" ";
    cout<<endl;
    for(int i=0;i<2*N_MAX;i++) cout<<max_obc[i]<<" ";
    cout<<endl<<endl;
}
 
int query(int a, int b)
{
   int l = N_MAX + a, r = N_MAX + b, maxl=0, maxr=0;
 
   int res = 0;
   maxl=max_obc[l]; maxr=max_obc[r];
   
   while(l >= 1)
   {
 //     res =max(res+obc[l],res+obc[r]);
      if(l!=r && l<N_MAX){
        maxl+=obc[l];
        maxr+=obc[r];
      }
      else if(l==r && l<N_MAX){
        res=max(res, max(maxl, maxr));
        res+=obc[l];
      }
       
      if(l < r - 1)
      {
         if(l % 2 == 0){
            maxl = max(maxl,max_obc[l + 1]);
         }
 
         if(r % 2 == 1){
            maxr = max(maxr,max_obc[r - 1]);
         }
      }
     
   
   l /= 2; r /= 2;
   }
   return res;
}

 
int main()
{
	ios::sync_with_stdio(false);
	int n,m,z,i,j,p,k,l;
	cin>>n>>m>>z;
 	
 	for(i=1;i<=z;i++){
 		cin>>p>>k>>l;
 		p--; k-=2;
 //		if(i==4) cout<<"XD";
 		if(m-query(p,k)>=l){
 			cout<<"T"<<"\n";
 			insert(p,k,l);
		}
		else cout<<"N"<<"\n";
	}
   
}