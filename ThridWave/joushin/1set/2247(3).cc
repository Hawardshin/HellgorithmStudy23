#include <iostream>
#include <algorithm>

using namespace std;


int N;

void make_star(int i,int j,int size){
	if (((i / size) %3 == 1 && (j / size) %3 == 1) )
		cout << " ";
	else {
		if (size == 1)
			cout << "*";
		else 
			make_star(i,j, size/3);
	}
}

int main(){
	cin >> N;
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			make_star(i,j,N);
		}
		cout << "\n";
	}
}

// x 0 1 2 3 4 5 6 7 8
// 0 * * * * * * * * *
// 1 *   * *   * *   *
// 2 * * * * * * * * *
// 3 * * *       * * *
// 4 *   *       *   *
// 5 * * *       * * *
// 6 * * * * * * * * *
// 7 *   * *   * *   *
// 8 * * * * * * * * * 