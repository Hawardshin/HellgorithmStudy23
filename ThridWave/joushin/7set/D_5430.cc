#include <deque>
#include <iostream>

using namespace std;

int n;

string command;
int arSize;
string numAr;
int main(){
	ios::sync_with_stdio(0); cin.tie(0);cout.tie(0);
	cin >> n;
	for(int i=0;i<n;i++){
		deque<int>dq;
		cin >> command >> arSize>>numAr;
		int num = 0;
		for(int j=0;j<numAr.size();j++){
			if ('0' <=numAr[j] &&numAr[j]<='9'){
				num*=10;
				num+=(numAr[j] -'0');
			}else if (arSize != 0 && num !=0){
				// cout << "::"<<num <<"\n";
				dq.push_back(num);
				arSize--;
				num = 0;
			}
		}
		bool isReverse = false;
		bool isError = false;
		for(int j=0;j<command.size();j++){
			if (command[j] == 'R')
					isReverse = !isReverse;
			else if (command[j] == 'D'){
				if (dq.empty()){
					isError=true;
					break;
				}
				if (isReverse == true){
					dq.pop_back();
				}else {
					dq.pop_front();
				}
			}
		}
		if (isError)
			cout << "error\n";
		else 
		{
			cout << "[";
			while (!dq.empty()){
				if (isReverse){
					cout << dq.back();
					dq.pop_back();
				}
				else{
					cout << dq.front();
					dq.pop_front();
				}
				if (!dq.empty()){
					cout << ",";
				}
			}	
			cout << "]\n";
		}
	}

}