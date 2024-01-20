#include <iostream>

int zero_ret, one_ret;
int table[130][130];

int N;

using namespace std;
bool isAllSame(int i_,int j_, int size){
	int bef = table[i_][j_];
	for(int i=0;i<size;i++){
		for(int j=0;j<size;j++){
			if (bef != table[i_+i][j_+j])
				return false;
		}
	}
	return true;
}


void recur(int i_,int j_, int size){
	if (size == 1 || isAllSame(i_,j_,size) )
		table[i_][j_] == 1 ? one_ret++ : zero_ret++;
	else {
		recur(i_,j_,size/2);
		recur(i_+size/2,j_,size/2);
		recur(i_,j_+size/2,size/2);
		recur(i_+size/2,j_+size/2,size/2);
	}
}

int main(){
	cin >> N;
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			cin >> table[i][j];
		}
	}
	recur(0,0,N);
	cout << zero_ret<< "\n" << one_ret << "\n";
}