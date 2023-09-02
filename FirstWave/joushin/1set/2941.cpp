#include <iostream>

using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string input;
	cin >> input;
	int ret = input.size();
	int s = ret;
	for(int i=1;i < s;i++){
		if (input[i] == '='){
			if (i != 1 && input[i -1] == 'z' && input[i - 2] == 'd')
				ret-=2;
			else if (input[i - 1] == 'c' || input[i - 1] == 's' || input[i - 1] == 'z')
				ret--;
		}
		else if (input[i] == '-'){
			if (input[i - 1] == 'd' || input[i - 1] == 'c')
				ret--;
		}
		else if (input[i] == 'j'){
			if (input[i - 1] == 'n' || input[i - 1] == 'l')
				ret--;
		}
	}
	cout << ret << "\n";
}