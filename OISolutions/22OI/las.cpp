#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	int n,i;
	cin>>n;
	double *torty=new double [n];
	double *wartosci=new double [n];
	bool *niezadowolony=new bool [n];
	int *zajety=new int [n];
	int *wyniki=new int [n];
	
	for(i=0;i<n;i++) {cin>>torty[i]; zajety[i]=0;}
	
	for(i=0;i<n-1;i++)
	{
		if(torty[i]==torty[i+1]) {wartosci[i]=torty[i]; wyniki[i]=i; zajety[i]++;}
		else if(torty[i]>torty[i+1]) {wartosci[i]=torty[i]; wyniki[i]=i; zajety[i]++;}
		else if(torty[i+1]>torty[i]) {wartosci[i]=torty[i+1]; wyniki[i]=i+1; zajety[i+1]++;}
	}	
	
	// PRZYPADEK KRANCOWY//////////////////////
	if(torty[n-1]==torty[0]) {wartosci[n-1]=torty[n-1]; wyniki[n-1]=n-1; zajety[n-1]++;}
		else if(torty[n-1]>torty[0]) {wartosci[n-1]=torty[n-1]; wyniki[n-1]=n-1; zajety[n-1]++;}
		else if(torty[0]>torty[n-1]) {wartosci[n-1]=torty[0]; wyniki[n-1]=0; zajety[0]++;}
	///////////////////////////////////////////
	
	///////////////////////////////////////////
	if(zajety[0]==2) {wartosci[n-1]/=2.0; wartosci[0]/=2.0;}
	///////////////////////////////////////////
	
	for(i=1;i<n-1;i++)
	{
		if(zajety[i]==2)
		{
			wartosci[i-1]/=2.0;
			wartosci[i]/=2.0;
		}
	}
	// KRANCOWY ///////////////////////////////
	if(zajety[n-1]==2) {wartosci[n-1]/=2.0; wartosci[n-2]/=2.0;}
	///////////////////////////////////////////
	
	
	///////////////KRANCOWY DLA 0////////////////////
	if(wyniki[0]==0)
		{
			if(wartosci[0]<(torty[1]/(min(2.0, (zajety[1]+1)*1.0) ) ) )
			{
				wyniki[0]=1;
				wartosci[0]=torty[1];
				wartosci[n-1]*=2;
				zajety[0]--;
				zajety[1]++;
				
			}
		}
		else if(wyniki[0]==1)
		{
			if(wartosci[0]<(torty[0]/(min(2.0, (zajety[0]+1)*1.0) ) ) )
			{
				wyniki[0]=0;
				wartosci[0]=torty[0];
				wartosci[1]*=2;
				zajety[1]--;
				zajety[0]++;
				
			}
		}
     //////////////////////////////////////////////////////////////
	
	for(i=1;i<n-1;i++)
	{
		if(wyniki[i]==i)
		{
			if(wartosci[i]<(torty[i+1]/(min(2.0, (zajety[i+1]+1)*1.0) ) ) )
			{
				wyniki[i]=i+1;
				wartosci[i]=torty[i+1];
				wartosci[i-1]*=2;
				zajety[i]--;
				zajety[i+1]++;
				
			}
		}
		else if(wyniki[i]==i+1)
		{
			if(wartosci[i]<(torty[i]/(min(2.0, (zajety[i]+1)*1.0) ) ) )
			{
				wyniki[i]=i;
				wartosci[i]=torty[i];
				wartosci[i+1]*=2;
				zajety[i+1]--;
				zajety[i]++;
				
			}
		}
	}
	
	///////////////KRANCOWY DLA N-1////////////////////
	if(wyniki[n-1]==n-1)
		{
			if(wartosci[n-1]<(torty[0]/(min(2.0, (zajety[0]+1)*1.0) ) ) )
			{
				wyniki[n-1]=0;
				wartosci[n-1]=torty[0];
				wartosci[n-2]*=2;
				zajety[n-1]--;
				zajety[0]++;
				
			}
		}
		else if(wyniki[n-1]==0)
		{
			if(wartosci[n-1]<(torty[n-1]/(min(2.0, (zajety[n-1]+1)*1.0) ) ) )
			{
				wyniki[n-1]=n-1;;
				wartosci[n-1]=torty[n-1];
				wartosci[0]*=2;
				zajety[0]--;
				zajety[n-1]++;
				
			}
		}
    ///////////////////////////////////////////////////////////////
	

	for(i=0;i<n;i++) cout<<wyniki[i]+1<<" ";//cout<<wartosci[i]<<" "<<wyniki[i]+1<<" "<<zajety[i]<<endl;
	
}