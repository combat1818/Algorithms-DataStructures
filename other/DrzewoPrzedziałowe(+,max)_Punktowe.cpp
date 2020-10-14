/*
	Aleksander Lorenc
	Drzewo przedzia³owe (+,max) punktowe- dodanie obci¹¿enia w punkcie, zapytanie o maximum na przedziale,
	nie przystosowane do liczb ujemnych- nale¿a³oby zainicjowaæ drzewo wartoœci¹ -INF
*/

#include<iostream>
#include<algorithm>
using namespace std;

const int MAXN = 1000005;
const int TREE_SIZE = 1048576;

// Wersja podstawowa- max wartoœæ na przedziale
/*
int tree_max[TREE_SIZE];

void TreeUpdate(int index, int change) {
    int idx = index+TREE_SIZE;
	
	tree_max[idx]=change;


    while (idx != 1) {
        idx /= 2;
        tree_max[idx] = max(tree_max[2*idx], tree_max[2*idx+1]);
    }
}

int TreeMax(int from, int to) {
    int idxFrom = from+TREE_SIZE, idxTo = to+TREE_SIZE;
    
    if(idxFrom > idxTo)
    	return -1;
    	
    	
    int result = 0, fromResult = tree_max[idxFrom], toResult = tree_max[idxTo];

    while (idxFrom / 2 != idxTo / 2) {
        if (idxFrom % 2 == 0)
            fromResult = max(fromResult, tree_max[idxFrom+1]);
        if (idxTo % 2 == 1)
            toResult = max(toResult, tree_max[idxTo-1]);

        idxFrom /= 2;
        idxTo /= 2;
    }

    result = max(fromResult, toResult);

    return result;
}
*/

// Wersja wzbogacona- (max wartoœæ, index) na przedziale  t.first- wartoœæ, t.second- index

pair<int,int> tree_max[2*TREE_SIZE];

void TreeUpdate(int index, int change) {
    int idx = index+TREE_SIZE;
	
	tree_max[idx].first=change;
	tree_max[idx].second=index;


    while (idx != 1) {
        idx /= 2;
        tree_max[idx].first = max(tree_max[2*idx].first, tree_max[2*idx+1].first);
        tree_max[idx].second= tree_max[2*idx].first > tree_max[2*idx+1].first ? tree_max[2*idx].second : tree_max[2*idx+1].second;
        /* Tutaj ustawilismy index. Jesli chcielibyœmy pierwszy albo ostatni najwiekszy trzeba zmienic znak nierownosci
		- w tym przypadku ustawiamy najwiekszy index miedzy równymi wartoœciami*/
    }
}

int TreeMax(int from, int to) {
    int idxFrom = from+TREE_SIZE, idxTo = to+TREE_SIZE;
    
    if(idxFrom > idxTo)
    	return -1;
    	
    	
    pair<int,int> result, fromResult = tree_max[idxFrom], toResult = tree_max[idxTo];

    while (idxFrom / 2 != idxTo / 2) {
        if (idxFrom % 2 == 0)
            fromResult = fromResult.first > tree_max[idxFrom+1].first ? fromResult : tree_max[idxFrom+1]; //uwaga na znak nierównoœci- szukamy najwiekszego indexu
        if (idxTo % 2 == 1)
            toResult = toResult.first >= tree_max[idxTo-1].first ? toResult: tree_max[idxTo-1]; //uwaga na znak nierównoœci- szukamy najwiekszego indexu

        idxFrom /= 2;
        idxTo /= 2;
    }

    result = fromResult.first > toResult.first ? fromResult : toResult;//max(fromResult, toResult);

    return result.second;
}


int main(){
	ios::sync_with_stdio(false);
	
	int n,x,p,k;
	cin>>n;	
	for(int i=0;i<n;i++){
		cin>>x;
		TreeUpdate(i,x);
		
	}
	for(int i=0;i<10;i++){
		cin>>p>>k;
		cout<<TreeMax(p,k);
	}
	// height[i] indeksy 1-n, nie 0-n-1
	
		
	
}
