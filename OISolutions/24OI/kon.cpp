#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;
int pref[319][100100];
int wyniki[100100];
bool uzyte[319];
int main()
{
	ios::sync_with_stdio(false);
	int n,k,i,a,l,d,p,j;
	cin>>n>>k;
	p=sqrt(n);
	for(i=0;i<k;i++)
	{
		cin>>a>>l>>d;
		
		if(d>=p)
		{
			for(j=0;j<l;j++)
			{
				wyniki[a+j*d]++;
			}
		}
		else
		{
			pref[d][a]++;
			if(a+d*l<=n)
			pref[d][a+d*l]--;
			uzyte[d]=true;
		}
	}
	
	for(i=1;i<=316;i++)
	{
		if(uzyte[i])
		{
			for(j=1;j<=n;j++)
			{
				pref[i][j]+=pref[i][j-i>=0? j-i:0];
				wyniki[j]+=pref[i][j];
			}
		}
	}
	
	for(i=1;i<=n;i++)
	{
		cout<<wyniki[i]<<" "; 
	}
}