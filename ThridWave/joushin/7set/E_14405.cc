#include <iostream>
#include <string>

using namespace std;

int main(){
	string input;
	cin >> input;
	int i_size = input.size();
	for(int i=0;i< i_size;i++){
		if (input[i] == 'p'){
			if (i +1 >= i_size || input[i+1] != 'i')
			{
				cout << "NO\n";
				return (0);
			}
			else i++;
		}
		else if (input[i] == 'k'){
			if (i +1 >= i_size || input[i+1] != 'a')
			{
				cout << "NO\n";
				return (0);
			}
			else i++;
		}
		else if (input[i] == 'c'){
			if (i+2 >= i_size || input[i+1] != 'h' || input[i+2] != 'u'){
				cout << "NO\n";
				return (0);
			}
			else i+=2;
		}
		else {
			cout << "NO\n";
			return (0);
		}
	}
	cout <<"YES\n";
}