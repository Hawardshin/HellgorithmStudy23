#include <iostream>
#include <algorithm>

using namespace std;

bool dp[2501][2501];
int dpP[2501];//0부터 숫자까지 분할하는데 드는 최소비용
string input;
//abc

int main(){
	cin >> input;
	for(int len=0; len<input.size();len++){
		for(int pos=0; pos+len<input.size();pos++){
			if (len == 0)
				dp[pos][pos] = true;
			else if (len == 1){
				if (input[pos] == input[pos+1])
					dp[pos][pos+1] = true;
			}else{
				if (dp[pos+1][pos+len-1] == true && input[pos] == input[pos+len])
					dp[pos][pos+len] = true;
			}
		}
	}

	for(int end = 0; end <input.size();end++){
		dpP[end] = 2147483643;
		for(int start=0; start<=end;start++){
			if (dp[start][end] == true){
				if (start == 0)
					dpP[end] =1;
				else 
					dpP[end] = min(dpP[end],dpP[start-1]+1);
			}
		}
	}
	
	cout << dpP[input.size()-1]<< "\n";
}
/*

AAA CC ACA CAAAC CACAC

AAACCACACAAACCACAC
correct: 5

*/