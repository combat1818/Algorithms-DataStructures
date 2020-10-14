#include<iostream>
#include<algorithm>
using namespace std;
long long n,l,r,Zl,Zr,Dl,Dr,C,Cm, z[10005], d[10005];
void PoprawGranice()
{
	while(Dr+d[r]<Dl)
	{
		C=C+(z[l]*(Dr+d[r]))-z[l]*Dl;
		Zr+=z[l];
		Zl-=z[l];
		Dr+=d[r];
		Dl-=d[l];
		r=(r+1)%n;
		l=(l+1)%n;
	}
}
int main()
{
	ios::sync_with_stdio(false);
	long long i,j;
	cin>>n;
	for(i=0;i<n;i++) cin>>z[i]>>d[i];
	r=0; l=1;
		for(i=n-1;i>=1;i--)
	{
		Dl+=d[i];
		Zl+=z[i];
		C+=Dl*z[i];
	}
    PoprawGranice();
	Cm=C;
		for(i=1;i<n;i++)
	{
		C=C-(Zr*d[i-1])+(Zl+z[i-1])*d[i-1];
		Zr-=z[i];
		Zl+=z[i-1];
		Dr-=d[i-1];
		Dl+=d[i-1];
		PoprawGranice();
		Cm=min(Cm,C);
	}
	cout<<Cm;
}