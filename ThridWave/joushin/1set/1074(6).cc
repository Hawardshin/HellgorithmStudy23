#include <iostream>
#include <cmath>
using namespace std;

int N,r,c;

int recur(int r_,int c_,int size,int now_num){
	if (size == 1)
		return (now_num);
	else
	{
			if (r<r_+size/2 && c<c_+size/2)
				return (recur(r_,c_,size/2,now_num));
			if (r>=r_+size/2 && c<c_+size/2)
				return recur(r_+size/2,c_,size/2,now_num+pow(size/2,2) * 2);
			if (r<r_+size/2 && c>=c_+size/2)
				return recur(r_,c_+size/2,size/2,now_num+pow(size/2,2));
			if (r>=r_+size/2 && c>=c_+size/2)
				return recur(r_+size/2,c_+size/2,size/2,now_num+pow(size/2,2)*3);
	}
}


int main(){
	cin >> N>> r>>c;
	cout << recur(0,0,pow(2,N),0) << "\n";
}