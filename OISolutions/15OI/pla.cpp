#include<iostream>
#include<algorithm>
#include<stack>
using namespace std;
int wysokosci[250005];

int main()
{
	ios::sync_with_stdio(false);
	int n,i,j,x,out=0;
	stack<int> S; 
	cin>>n;
	for(i=0;i<n;i++) cin>>x>>wysokosci[i];
	
	for(i=0;i<n;i++)
	{
		while(!S.empty() && S.top()>wysokosci[i]) S.pop();
		
		if(S.empty() || S.top()<wysokosci[i])
		{
			S.push(wysokosci[i]);
			out++;
	    }
		
	}
	
	cout<<out;
	
}