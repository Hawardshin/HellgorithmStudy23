#include <iostream>
#include <stack>
#include <algorithm>
#define CHR first
#define IDX second
using namespace std;
int n;
string str;

stack<pair<char,int>> st;
bool rightStr[200001];

int main(){
	cin >> n;
	string s;
	cin >> s;

	for(int i=0;i<n;i++){
		char a = s[i];
		if (a == '('){
			st.push({'(',i});
		}
		else if (a == ')'){
			if (!st.empty() && st.top().CHR == '('){
				rightStr[st.top().IDX] = true;
				rightStr[i] = true;
				st.pop();
			}else 
				st.push({')',i});
		}
		else
			cout << "crazy\n";
	}
	int max_len = 0;
	int now_len = 0;
	for(int i=0;i<s.size();i++){
		if (rightStr[i] == true && rightStr[i+1] == true){
			now_len+=2;
			i++;
		}else {
			max_len = max(max_len,now_len);
			now_len = 0;
		}
	}
	max_len = max(max_len,now_len);
	cout << max_len << "\n";
}