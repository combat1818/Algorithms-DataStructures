#include<iostream>
#include<algorithm>
#include <stdio.h>
using namespace std;
int lizak[1000005],i,j;
pair<int, int> przedzialy [2000005];
string s;

void oblicz_przedzialy(int sum)
{
	przedzialy[sum].first=i+1; przedzialy[sum].second=j+1;
	
	while(sum>2)
	{
		while( sum>2 && s[i]=='T')
		{
			sum-=2; i++;
			przedzialy[sum].first=i+1; przedzialy[sum].second=j+1;
		}
		
		while( sum>2 && s[j]=='T')
		{
			sum-=2; j--;
			przedzialy[sum].first=i+1; przedzialy[sum].second=j+1;
		}
		
		if(sum>2)
		{
			sum-=2;
			i++; j--;
			przedzialy[sum].first=i+1; przedzialy[sum].second=j+1;
		}
	}
}

int main()
{
//	ios::sync_with_stdio(false);
	int n,m,k,sum=0,newsum=0,zapytanie;
	
	scanf("%d%d", &n, &m);
	cin>>s;
	for(i=0;i<n;i++) sum+= (s[i]=='T') ? 2:1;
//	cout<<sum;
	
//	for(i=0;i<m;i++) cin>>zapytanie[i]; //cin>>zapytanie[i];
	
	i=0; j=n-1;
	
	oblicz_przedzialy(sum);
	
//	for(i=0;i<2*n;i++) cout<<przedzialy[i].first<<" "<<przedzialy[i].second<<endl;
	
	i=0; j=n-1;
	
	while(i<n && s[i]=='T') i++;
	
	while(j>0 && s[j]=='T') j--;
	
	if(s[i]=='T')
	{
		// nie ma W
	}
	else
	{
		if(i<n-1-j)
		{
			sum-=2*i+1;
			i++;
			j=n-1;
		}
		else 
		{
			sum-=(n-1-j)*2+1;
			j--;
			i=0;
		}
		oblicz_przedzialy(sum);
	}
	
	
/*	while(i<=j)
	{
		if(s[i]=='W') {i++; j=n-1; break;}
		if(s[j]=='W') {j--; i=0; break;}
		i++; j--;
	}
	
	if(i<=j)
	{
		for(k=i;k<=j;k++) newsum+= (s[k]=='T') ? 2:1;
	}
	*/
//	cout<<"XDD "<<newsum<<" XDDD"<<endl;
	
	//oblicz_przedzialy(newsum);
	
//	for(i=0;i<2*n;i++) cout<<przedzialy[i].first<<" "<<przedzialy[i].second<<endl;
	
	
	for(i=0;i<m;i++)
	{
		scanf("%d", &zapytanie);
		if(!przedzialy[zapytanie].first && !przedzialy[zapytanie].second) printf("NIE\n");
		else printf("%d %d\n", przedzialy[zapytanie].first, przedzialy[zapytanie].second);
		// cout<<przedzialy[zapytanie].first+1<<" "<<przedzialy[zapytanie].second+1<<endl;
	}
	
	
	
///	for(i=0;i<=2*n;i++)
//	{
//		cout<<przedzialy[i].first<<" "<<przedzialy[i].second<<endl;
//	}
	
	
}