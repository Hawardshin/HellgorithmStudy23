#include <iostream>
#include <queue>
using namespace std;
queue<pair<int,char>> Q;//몇초에 어디로 이동하는지 저장
int table[102][102];
//벽은 0번째 인덱스가 들어가거나 N+1이 될때는 다 벽이라고 칭한다.
//0은 빈칸, -1은 몸통이 있는 칸이라고 칭하자.
int N, K, L;
int mx = 1, my=1;
typedef enum dir{
	EA,
	WE,
	SO,
	NO
}dir;


class t_tail{
	public : 
		t_tail(int tail_x,int tail_y,dir tail_dir):tail_x(tail_x), tail_y(tail_y),tail_dir(tail_dir){}
	int tail_x;
	int tail_y;
	dir tail_dir;
};
dir m_dir = EA;

void	printTable(){
	cout << "----------------------\n";
	for(int i=1;i<=N;i++){
		for(int j=1; j <=N;j++){
			cout << table[i][j];
		}
		cout << "\n";
	}
}

//리턴값은 y,x
pair<int,int> getNextIdx(pair<int,char> x){
	switch(m_dir){
		case EA : 
			if (x.second == 'D'){
				m_dir = SO;
				return (make_pair(1,0));//
			}else {
				m_dir = NO;
				return (make_pair(-1,0));
			}
			break;
		case WE : 
			if (x.second == 'D'){
				m_dir = NO;
				return (make_pair(-1,0));//
			}else {
				m_dir = SO;
				return (make_pair(1,0));
			}
			break;
		case SO : 
			if (x.second == 'D'){
				m_dir = WE;
				return (make_pair(0,-1));//
			}else {
				m_dir = EA;
				return (make_pair(0,1));
			}
			break; 
		case NO :
			if (x.second == 'D'){
				m_dir = EA;
				return (make_pair(0,1));//
			}else {
				m_dir = WE;
				return (make_pair(0,-1));
			}
			break;
	}
}
void	solve(){
	int day = 0;
	queue<t_tail> TQ;
	t_tail xxx(1,1,EA);
	TQ.push(xxx);
	table[1][1] = -1;
	while(1){
		// printTable();
		day++;
		if (!Q.empty()){
			auto next_move = Q.front();
			if (next_move.first+1 == day){
				Q.pop();
				auto next_idx = getNextIdx(next_move);
				mx = mx + next_idx.second;
				my = my + next_idx.first;
			}
			else {
				switch (m_dir){
					case EA : mx++;
						break;
					case WE : mx--;
						break;
					case SO : my++;
						break;
					case NO : my--;
						break;
					}
			}
		}
		else {
			switch (m_dir){
				case EA : mx++;
					break;
				case WE : mx--;
					break;
				case SO : my++;
					break;
				case NO : my--;
					break;
			}
		}
		TQ.push(t_tail(mx,my,m_dir));
		//이동 이후 길이를 줄이는지 아니면 잘못됐는지 계산
		if (mx == 0 || my ==0 || mx >N || my > N || table[my][mx] == -1){
				cout << day<<"\n";
				return ;
		}
		if (table[my][mx] != 1){
			auto atq = TQ.front();
			TQ.pop();
			table[atq.tail_y][atq.tail_x] = 0;
		}
		table[my][mx] = -1;
	}
}

int main(){
	cin >> N >>K;
	int tx,ty;
	for(int i=0;i<K;i++){
		cin >> ty >> tx;
		table[ty][tx] = 1;
	}
	cin >> L;
	int time_;
	char t_dir;//L은 왼쪽, D는 오른쪽
	for(int i=0;i<L;i++){
		cin >> time_ >>t_dir;
		Q.push({time_,t_dir});
	}
	solve();
}

