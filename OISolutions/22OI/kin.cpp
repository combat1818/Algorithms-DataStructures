#include<iostream>
#include<algorithm>
using namespace std;

const int MAXN = 1000005;
const int TREE_SIZE = 1048576;
long long treeSum[2*TREE_SIZE], treeMax[2*TREE_SIZE];
long long f[MAXN],w[MAXN],neext[MAXN],last[MAXN];

void TreeUpdate(long long from, long long to, long long change) {
    long long idxFrom = from+TREE_SIZE, idxTo = to+TREE_SIZE;

    if (from > to) return;

    treeSum[idxFrom] += change;
    treeMax[idxFrom] += change;
    if (idxFrom != idxTo) {
        treeSum[idxTo] += change;
        treeMax[idxTo] += change;
    }

    while (idxFrom / 2 != idxTo / 2) {
        if (idxFrom % 2 == 0) {
            treeSum[idxFrom+1] += change;
            treeMax[idxFrom+1] += change;
        }
        if (idxTo % 2 == 1) {
            treeSum[idxTo-1] += change;
            treeMax[idxTo-1] += change;
        }

        idxFrom /= 2;
        idxTo /= 2;

        treeMax[idxFrom] = max(treeMax[2*idxFrom], treeMax[2*idxFrom+1]) + treeSum[idxFrom];
        treeMax[idxTo] = max(treeMax[2*idxTo], treeMax[2*idxTo+1]) + treeSum[idxTo];
    }

    while (idxFrom != 1) {
        idxFrom /= 2;
        treeMax[idxFrom] = max(treeMax[2*idxFrom], treeMax[2*idxFrom+1]) + treeSum[idxFrom];
    }
}

long long TreeMax(long long from, long long to) {
    long long idxFrom = from+TREE_SIZE, idxTo = to+TREE_SIZE;
    long long result = 0, fromResult = treeMax[idxFrom], toResult = treeMax[idxTo]; //usuniete result=0LL

    while (idxFrom / 2 != idxTo / 2) {
        if (idxFrom % 2 == 0)
            fromResult = max(fromResult, treeMax[idxFrom+1]);
        if (idxTo % 2 == 1)
            toResult = max(toResult, treeMax[idxTo-1]);

        idxFrom /= 2;
        idxTo /= 2;

        fromResult += treeSum[idxFrom];
        toResult += treeSum[idxTo];
    }

    result = max(fromResult, toResult);

    while (idxFrom != 1) {
        idxFrom /= 2;
        result += treeSum[idxFrom];
    }

    return result;
}


int main(){
	ios::sync_with_stdio(false);
	long long n,m,i;
	cin>>n>>m;
	for(i=0;i<n;i++){
	cin>>f[i];
	f[i]--;
	}
	for(i=0;i<m;i++) cin>>w[i];

	for(i=0;i<n;i++){
		neext[i]=-1;
		last[i]=-1;
	}

	for(i=n-1;i>=0;i--){
		neext[i]=last[f[i]];
		last[f[i]]=i;
	}
	
	for(i=0;i<n;i++) last[i]=-1;
	long long ost=0;	
//	for(i=0;i<n;i++) cout<<neext[i]<<" ";
	for(i=0;i<n;i++){
		if(last[f[i]]==-1){
			last[f[i]]=-2;
			TreeUpdate(i,i,ost+w[f[i]]);
			ost=ost+w[f[i]];
		}else if(last[f[i]]==-2){
			TreeUpdate(i,i,ost-w[f[i]]);
			last[f[i]]=-3;
			ost-=w[f[i]];
		}else{
			TreeUpdate(i,i,ost);
		}
	}
	
//	long long result=TreeMax(0,n-1);
//	cout<<result;
	long long result=0;
	for(i=0;i<n;i++){
		result=max(result,TreeMax(i,n-1));
		if(neext[i]==-1){
			TreeUpdate(i,n-1,-w[f[i]]);
		}else if(neext[i]!=-1){
			if(neext[neext[i]]==-1){
				TreeUpdate(i,neext[i]-1,-w[f[i]]);
				TreeUpdate(neext[i],n-1,w[f[i]]);
			}else{
				TreeUpdate(i,neext[i]-1,-w[f[i]]);
				TreeUpdate(neext[i],neext[neext[i]]-1,w[f[i]]);
			}
		}
		
	}
	cout<<result;
	
}