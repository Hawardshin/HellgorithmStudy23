#include <iostream>

using namespace std;

long long X,Y;
long long Z;

long long getRatio(long long win, long long game){
	return ((win*100) /game );
}

long long find_min(long long start, long long end){
	// cout <<"s:" << start << "e:"<< end << "\n";
	if (start > end)
		return (-1);
	long long mid = (start + end) /2;
	long long n_win =mid+Y;
	long long n_game=mid+X;
	// cout << "n_win:" <<n_win << "|n_game:"<< n_game << "\n";
	if (getRatio(n_win, n_game) > Z && getRatio(n_win -1,n_game -1) == Z){
		return mid;
	}
	else if (getRatio(n_win,n_game) > Z){
		return (find_min(start, mid));
	}
	else if (getRatio(n_win, n_game) <= Z){
		return (find_min(mid+1, end));
	}
	return mid;
}

void input(){
	cin >> X >> Y;
	Z = getRatio(Y,X);
	// cout << Z << "\n";
}

int main(){
	input();
	cout << find_min(1,1000000000) << "\n";
}