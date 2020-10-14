//OI ZADANIE TAKSOWKI
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
bool isOcc[500001];
long long t[500001];
int main()
{
    ios::sync_with_stdio(false);
    long long m,d,n,i,j,x,dist,st=-1,out=0,cPos=0,last;
    //vector<int> t;
    cin>>m>>d>>n;
    for(i=0;i<n;i++){
      cin>>t[i];
    }
    dist=m-d;  
    sort(t,t+n);

    for(i=0;i<n;i++){
      if(t[i]>=dist){
        st=t[i];
       // t.erase(t.begin()+i);
        isOcc[i]=true;
        break;
      }
    }
    if(st==-1){
      cout<<0;
      return 0;
    }

    for(i=n-1;i>=0;i--){
        if(cPos>=d) break;
        else if(2*(d-cPos)+m-d<=st){
          cout<<out+1;
          return 0;
        }
        else if(t[i]-(d-cPos)<=0) break;
        else if(!isOcc[i]){
            x=t[i]-(d-cPos);
            cPos+=x;
            out++;
            last=x;
  //      cout<<"cPos= "<<cPos<<endl;
        }
    }

    if(cPos<d){
      if(2*(d-cPos)+m-d<=st)
        cout<<out+1;
      else cout<<0;

      return 0; 
    }
    
    cPos-=last;
    if(2*(d-cPos)+m-d<=st)
      cout<<out;
    else cout<<out+1;  
    
}