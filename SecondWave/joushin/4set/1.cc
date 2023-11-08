#include <iostream>
#include <string>
using namespace std;
string input;
int main(){
	cin >> input;
	int s_size = input.size();
	for(int i=0;i < s_size;i++){
		int cnt=0;
		for(int j=0;j+i<s_size;j++){
			if (input[i+j] =='X')
				cnt++;
			else
				break;
		}
		if (cnt%2 ==1){
				cout << -1 << "\n";
				return 0 ;
		}
		while (cnt!=0){
			if (cnt % 4 == 0){
				for(int j=0;j<4;j++){
					input[i+j] = 'A';
				}
				cnt-=4;
			}else if (cnt % 2 ==0){
				for(int j=0;j<2;j++){
					input[i+j] = 'B';
				}
				cnt-=2;
			}
		}
	}
	cout << input << "\n";
}