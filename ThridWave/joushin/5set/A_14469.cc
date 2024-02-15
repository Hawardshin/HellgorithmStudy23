#include <iostream>
#include <algorithm>

using namespace std;
int N;
pair<int,int>cow[101];

int main(){
	cin >>N;
	for(int i=0;i<N;i++)
		cin >> cow[i].first >> cow[i].second;
	sort(cow,cow+N);
	int time=0;
	for(int i=0;i<N;i++){
		if (cow[i].first > time)
			time = cow[i].first;
		time += cow[i].second;
	}
	cout << time << "\n";
}