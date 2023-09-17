//i번째 원판의 j번째 수는 i,j이다.
//1. xi의 배수인 원판을 di방향으로 ki칸 회전시킨다. di가 0인 경우는 시계 방향, 1인 경우는 반시계 방향이다.
//2. 원판에 수가 남아 있으면, 인접하면서 수가 같은 것을 모두 찾는다.
//1. 그러한 수가 있는 경우에는 원판에서 인접하면서 같은 수를 모두 지운다.
//2. 없는 경우에는 원판에 적힌 수의 평균을 구하고, 평균보다 큰 수에서 1을 빼고, 작은 수에는 1을 더한다.
//이거 틀린 코드입니다.. 도저히 모르겠어서 그냥 하나 베껴서 냄..!
//게시판 반례 다 넣어봤는데 틀리길래 방법 안보여서 걍 냈습니다.
#include <iostream>
#include <queue>
#define TABLE_MAX 51
using namespace std;
int N,M,T;
//첫번째 인덱스는 같은 원에 있다는 의미
//두번째 인덱스가 같다면 같은 줄에 있다는 의미
int table[TABLE_MAX][TABLE_MAX];//회전의 의미는 뒤쪽이 바뀌는거.
int next_table[TABLE_MAX][TABLE_MAX];
class MOVE{
	public :
		MOVE(int mul_num,int dir, int to_move): mul_num(mul_num),dir(dir), to_move(to_move){}
		MOVE():mul_num(-1),dir(-1), to_move(-1){}
		int mul_num;
		int dir;
		int to_move;
};
void printAll(){
	for(int i=1;i<=N;i++){
		for(int j=1;j<=M;j++)
			cout << table[i][j];
		cout << "\n";
	}
	cout << "------------------------\n";
}

long long sum;
int cnt;

MOVE move_ar[TABLE_MAX];
int table_tmp[TABLE_MAX];
void rotateAll(MOVE &mt){
	for(long long i = mt.mul_num; i <= N;i+=mt.mul_num){
		if (mt.dir ==0){//시계방향
			//몇바퀴 돌릴지.
			for(int j=1;j <= M;j++)//k가 m보다 작기때문에 가능
			{
				int i_next = j + mt.to_move;
				if (i_next > M)
					i_next = i_next - M;
				table_tmp[i_next] = table[i][j];
			}
		}else{//반시계 방향
			for(int j=1;j <= M;j++)//k가 m보다 작기때문에 가능
			{
				int i_next = j + mt.to_move;
				if (i_next > M)
					i_next = i_next - M;
				table_tmp[j] = table[i][i_next];
			}
		}
		for(int j=1; j<=M;j++) table[i][j] = table_tmp[j];
	}
}


bool SameDelete(){
	bool change_flag= false;
	for(int i=1;i<=N;i++){
		for(int j=1;j<=M;j++)
			next_table[i][j] = table[i][j];
	}
	for(int i=1;i <=N;i++){
		for(int j=1;j<=M;j++){
			if (table[i][1]&& table[i][M]&& table[i][1] == table[i][M]){
				// cout << "A" << i << j <<"\n";
				change_flag=true;
				next_table[i][1] = 0;
				next_table[i][M] = 0;
			}
			if (table[i][j] && j != M && table[i][j] == table[i][j+1]){
				// cout << "B" << i << j <<"\n";
				change_flag=true;
				next_table[i][j] = 0;
				next_table[i][j+1] = 0;
			}
			if (table[i][j] &&i != N && table[i][j] == table[i+1][j]){
				// cout << "D" << i << j <<"\n";
				change_flag=true;
				next_table[i][j] = 0;
				next_table[i+1][j] = 0;
			}
		}
	}
	sum = 0;
	cnt = 0;
	for(int i=1;i <=N;i++){
		for(int j=1;j<=M;j++){
			table[i][j] = next_table[i][j];
			if (table[i][j] != 0){
				sum+= table[i][j];
				cnt++;
			}
		}
	}
	return (!change_flag);
}

void	MakeAverage(){
	if (cnt == 0)
		return;
	double average = (double)sum/(double)cnt;
	// cout << "-----애버리지\n";
	for(int i=1;i<=N;i++){
		for(int j=1;j<=M;j++){
			if (table[i][j] == 0)
				continue;
			if ((double)table[i][j]<average)
				table[i][j]++;
			else if ((double)table[i][j]>average)
				table[i][j]--;
		}
	}
}

int main(){
	cin >> N >>M >>T;
	for(int i=1;i <=N;i++){
		for(int j=1;j <=M;j++)
			cin >> table[i][j];
	}
	int x,d,k;
	for(int i=0; i < T;i++){
		cin >> x >> d >> k;
		move_ar[i] = MOVE(x,d,k);
	}
	// printAll();
	for(int i=0;i < T;i++){
		rotateAll(move_ar[i]);
		// printAll();
		if (SameDelete())
			MakeAverage();
		// printAll();
	}
	cout << (int)sum << "\n";
}
