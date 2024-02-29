#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

int n;

stack<pair<int,int>> st;
int main(){
	long long cnt =0;
	cin >> n;
	for(int i=0;i<n;i++){
		int a;
		cin >> a;
		int same_cnt=1;;
		while (!st.empty() && st.top().first < a){
			cnt+= st.top().second;
			st.pop();
		}
		if (!st.empty()){
			if (st.top().first ==a){
				cnt+=st.top().second;
				same_cnt = st.top().second+1;
				if (st.size()>1)
					cnt++;
				st.pop();
			}else 
				cnt++;
		}
		st.push({a,same_cnt});
	}
	cout <<cnt<<"\n";
}
/*

7 
7 8 6 5 3 7 4 7 7 10 6 1 2
*/