//시간 초과 오답코드
#include <iostream>
#include <map>



using namespace std;

int T,N,M;

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >>T;
	int tmp;
	while (T){
		cin >> N;
		map<int,bool> note;
		for(int i=0;i<N;i++) {cin >> tmp ; note[tmp]= true;}
		
		cin >> M;
		for(int i=0;i<M;i++) {
			cin >> tmp;
			cout <<  (note.find(tmp) != note.end())<< "\n";
		}
		T--;
	}
}