#include <iostream>

int minus_ret,zero_ret, one_ret;
int table[5000][5000];

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
	{
		if (table[i_][j_] == 0)
			zero_ret++;
		else if (table[i_][j_] == 1)
			one_ret++;
		else if (table[i_][j_] == -1)
			minus_ret++;
	}
	else {
		for(int i=0;i<3;i++){
			for(int j=0;j<3;j++)
				recur(i_+ size/3*i, j_+ size/3*j , size/3);
		}
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
	cout << minus_ret << "\n" << zero_ret<< "\n" << one_ret << "\n";
}