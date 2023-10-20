#include <iostream>
#include <string>
#include <vector>


using namespace std;

string result = "Messi Gimossi";
int M;
vector<int> mesi;

void input(){
	cin >>M;
}

//이분탐색
int search(int Step, int order)
{
	//숫자를 게속 줄여서 가능
    if (order <= mesi[1])
        return order;
    if (order <= mesi[Step - 1])//전꺼
        return search(Step - 1, order);
    else if (order == mesi[Step - 1] + 1) // 공백
        return -1;
    else //전전꺼
        return search(Step - 2, order - mesi[Step - 1] - 1);
}

void	solve(){
	
	int a = 5;
	int b = 13;
	mesi.push_back(a);
	mesi.push_back(b);
	int now_size = 0;
	while (now_size < M){
		now_size = a+b + 1;
		a = b;
		b =now_size;
		mesi.push_back(now_size);
	}
	int size = mesi.size();
	int ret = search(size, M);
	if (ret == -1 || ret == 6)
		cout << "Messi Messi Gimossi\n";
	else 
		cout << result[ret-1] << "\n";
}

int main(){
	input();
	solve();
}