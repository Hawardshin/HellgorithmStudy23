/*

X= A B 
   C D
X*X = 
A*A+B*C A*B+B*D
C*A+D*C C*B+D*D
=
A*A+B*C B(A+D)
C(A+D)  D*D+C*B
*/

#include<iostream>
using namespace std;

long long n, b;
long long a[5][5];
long long tmp[5][5];
long long ans[5][5];

// 행렬 곱셈
void mulMat(auto &x, auto &y) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      tmp[i][j] = 0; 
      for (int k = 0; k < n; k++) tmp[i][j] += (x[i][k] * y[k][j]);
			tmp[i][j] %= 1000;
    }
  }
  for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)  x[i][j] = tmp[i][j];
  }
}

int main() {
  cin >> n >> b;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) cin >> a[i][j];
    ans[i][i] = 1;
  }

  while (b > 0) {
    if (b % 2 == 1) 
      mulMat(ans, a);
	  mulMat(a, a);
	  b /= 2;
	}
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) cout << ans[i][j] << " "; 
    cout << "\n";
  }
}