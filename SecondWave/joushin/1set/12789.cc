#include <iostream>
#include <stack>
int N;
int idx=1;
int input[1001];
using namespace std;

int main(){
	cin >> N;
	stack<int> S;
	int x;
	for(int i=1;i<=N;i++){
		cin >> input[i];
	}
	int i=1;
	while(1){
		if (input[i] == idx){
			i++;
			idx++;
		}
		else {
			if (!S.empty()&&  S.top() == idx){
				S.pop();
				idx++;
			}else{
				S.push(input[i]);
				i++;
			}
		}
		if (i == N+1)
			break;
	}
	while (!S.empty()){
		if (S.top() == idx)
		{
			S.pop();
			idx++;
		} 
		else {
			cout << "Sad\n";
			return (0);
		}
	}
	cout << "Nice\n";
}