#include<iostream>
#include<algorithm>
#include<stack>
using namespace std;

int t[2002][2002], K[2002][2002], zabronione[2002];
int n,k,S1,S2;

void licz_K()
{
	for(int i=1;i<=n;i++)
	 for(int j=1;j<=n;j++)
	  K[i][j]=K[i-1][j]+K[i][j-1]-K[i-1][j-1]+t[i][j];
}

int suma(int a, int b, int c, int d)
{
	return K[d][c]-K[d][a-1]-K[b-1][c]+K[b-1][a-1];
}

struct w{
	int x1, y1, x2, y2;
	
	void assign(int a, int b, int c, int d)
	{
		x1=a; y1=b; x2=c; y2=d;
	}
};
w w;

void tnij(int x1, int y1, int x2, int y2)
{
	int border;
	
	while(suma(x1,y1,x2,y2)>2*k)
	{
		if(y1!=y2)
		{
			border=(y1+y2)/2;
			S1=suma(x1, y1, x2, border);
			S2=suma(x1, border+1, x2, y2);
		
			if(S1>=k && S1<=2*k) {w.assign(x1,y1,x2,border); break;}
			else if(S2>=k && S2<=2*k) {w.assign(x1, border+1, x2, y2); break;}
			else if(S1>2*k)	y2=border;
			else if(S2>2*k)	y1=border+1;
		}
		else if(x1!=x2)
		{
			border=(x1+x2)/2;
			S1=suma(x1,y1,border,y2);
			S2=suma(border+1,y1,x2,y2);
			
			if(S1>=k && S1<=2*k) {w.assign(x1,y1,border,y2); break;}
			else if(S2>=k && S2<=2*k) {w.assign(border+1, y1, x2, y2); break;}
			else if(S1>2*k)	x2=border;
			else if(S2>2*k)	x1=border+1;
		}
		
	}
}

int main()
{
	int i,j,a,b,c,d,x,y,yPrim,xPrim,s=-1;
	
	cin>>k>>n;
	for(i=1;i<=n;i++)
	 for(j=1;j<=n;j++)
	  cin>>t[i][j];
//	cout<<endl<<endl;  
	  
	licz_K();  
	
	for(y=1;y<=n;y++)
	{
		stack<pair<int,int> > S;
		
		for(x=1;x<=n+1;x++)
		{
			zabronione[n+1]=y-1;
			if(t[y][x]>2*k)
			{
				zabronione[x]=y;
				while(!S.empty())
				{
					if(suma(S.top().first, S.top().second, x-1, y) > s)
					 {
					 	s=suma(S.top().first, S.top().second, x-1, y);
					 	w.assign(S.top().first, S.top().second, x-1, y);
				//	 	cout<<endl<<s<<endl;
					 }
					 S.pop();
				} 
			}
			else
			{
				yPrim=zabronione[x];
				xPrim=x;
				
				while(!S.empty() && S.top().second<=yPrim+1)
				{
				//	cout<<"XD";
					if(suma(S.top().first, S.top().second, x-1, y) > s)
					 {
					 	s=suma(S.top().first, S.top().second, x-1, y);
					 	w.assign(S.top().first, S.top().second, x-1, y);
				//	 	cout<<endl<<s<<endl;
					 }
					 
					xPrim=S.top().first;
					S.pop(); 
				}
				
				if((S.empty() && yPrim<y) || S.top().second>yPrim+1)
				 {
			//	 	cout<<xPrim<<"  "<<yPrim+1<<endl;
				 	S.push(make_pair(xPrim, yPrim+1));
				 }
			}
		}
	//	cout<<endl<<"KOENIEC WIRSZA"<<endl;
	}
	
//	for(i=0;i<=n;i++) cout<<zabronione[i]<<" ";
//	cout<<endl;
 //   cout<<endl<<w.x1<<" "<<w.y1<<" "<<w.x2<<" "<<w.y2<<endl;
    
    if(suma(w.x1, w.y1, w.x2, w.y2)>=k && suma(w.x1, w.y1, w.x2, w.y2)<=2*k)
    {
    	cout<<w.x1<<" "<<w.y1<<" "<<w.x2<<" "<<w.y2;
	}
	else if(suma(w.x1, w.y1, w.x2, w.y2)<k)
	{
		cout<<"NIE";
	}
	else if(suma(w.x1, w.y1, w.x2, w.y2)>2*k)
	{
		tnij(w.x1, w.y1, w.x2, w.y2);
		cout<<w.x1<<" "<<w.y1<<" "<<w.x2<<" "<<w.y2;
	}

//	cout<<s;
	
	
	  
}









/*
for(i=0;i<k;i++)
	{
		cin>>a>>b>>c>>d;
		cout<<suma(a,b,c,d)<<endl;
	}
	
	//	for(int i=1;i<=n;i++)
//	{
//		for(int j=1;j<=n;j++)
//	     cout<<K[i][j]<<" "; 
//	    cout<<endl; 
//	}
*/