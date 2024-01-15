#include <iostream>
using namespace std;
int table[65][65];
int N;
bool isAllSame(int i,int j,int size){
		int firstNum = table[i][j];
		for(int a=0;a<size;a++){
			for(int b=0;b <size;b++){
				if (firstNum != table[i+a][j+b])
					return false;
			}
		}
		return true;
}

void recur(int i,int j, int size){
	if (i >= N || j >= N)
		return;
	if (size == 1){
		cout << table[i][j];
	}
	else {
		if (isAllSame(i,j,size)){
			cout << table[i][j];
		}
		else {
			cout << "(";
			recur(i,j,size/2);
			recur(i,j+size/2,size/2);
			recur(i+ size/2,j,size/2);
			recur(i+size/2,j+size/2,size/2);
			cout << ")";
		}
	}
}

int main(){ 
	cin >> N;
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			char tmp;
			cin >> tmp;
			table[i][j] = tmp-'0';
		}
	}
	recur(0,0,N);
	cout << "\n";
}