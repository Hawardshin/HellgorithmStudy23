#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;
//0,1,2,3 
//mid = 1 
int T,N,M;
int note[1000000];
bool binarySearch(int st,int ed, int toFind){
	int mid = (st+ed)/2;
	if (note[mid] == toFind)
		return true;
	if (st > ed)
		return false;
	if (note[mid] > toFind)
		return binarySearch(st,mid-1,toFind);
	else 
		return binarySearch(mid+1,ed,toFind);

}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >>T;
	while (T){
		cin >> N;
		for(int i=0;i<N;i++) cin >> note[i];
		sort(note,note+N);
		cin >> M;
		for(int i=0;i<M;i++) {
			int tmp;
			cin >> tmp;
			cout << binarySearch(0,N-1,tmp) << "\n";
		}
		T--;
	}
}