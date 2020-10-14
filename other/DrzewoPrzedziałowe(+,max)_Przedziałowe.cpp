/* 
	Aleksander Lorenc
	Drzewo przedzia³owe (+,max) przedzia³owe - dodanie obci¹¿enia na przedziale, zapytanie o max na przedziale,
	nie przystosowane do liczb ujemnych- trzeba by zainicjalizowaæ drzewo wartoœci¹ -INF
*/

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
	
	// Test Tree
	int n,x,a,b;
	cin>>n;
	
	for(int i=0;i<n;i++){
		cin>>x;
		TreeUpdate(i,i,x);
	}
	TreeUpdate(5,7,7);
	for(int i=0;i<10;i++){
		cin>>a>>b;
		cout<<TreeMax(a,b);
	}
	
}
