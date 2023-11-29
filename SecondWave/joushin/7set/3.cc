#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;
string input;

int make_ret(string &input){
	stack<char> a;
	int n = input.size();
	for (int i=0;i<n;i++){
		if (input[i] == '{')
			a.push('{');
		else
		{
			if (!a.empty() && a.top() == '{')
				a.pop();
			else 
				a.push('}');
		}
	}
	if (a.empty() == true)
		return (0);
	else {
		int ret = 0;
		while (!a.empty()){
			int f1 = a.top();
			a.pop();
			int f2 = a.top();
			a.pop();
			if (f1 == f2)
				ret++;
			else 
				ret+=2;
		}
		return (ret);
	}

}

int main(){
	int x =1;
	while (1){
		cin >> input;
		if (input[0] == '-')
			break;
		cout << x << ". " << make_ret(input) << "\n";
		x++;
	}
}