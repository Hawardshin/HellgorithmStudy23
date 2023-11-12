#include <iostream>
#include <algorithm>
using namespace std;
int N; //계란의 갯수
pair<int,int> eggs[8];
// 무게가 높은 녀석은 최대한 많은 계란을 쳐야만 한다.
// 무게가 낮은 녀석은 최대한 적은 계란을 쳐야만 한다.
//라고 생각했지만 사실 DP가 아니었던거지.
 //7! 이라면? 이건 브루스포스로 풀어도 될 것 같다.
 //
int max_break=0;
void	break_egg(int *egg_guard,int now_idx,int break_cnt){
	// cout << "재귀 들어옴" <<now_idx << "\n";
	if (now_idx == N){
		max_break = max(max_break,break_cnt);
		// cout << "최대값 계산\n";
		return ;
	}
	if (egg_guard[now_idx] <=0){
		break_egg(egg_guard,now_idx+1,break_cnt);
		// cout <<"재귀 나감" << now_idx << "\n";
	}
	else
	{
		int cnt = 0;
		for(int i=0;i<N;i++)
		{
			if (i == now_idx || egg_guard[i] <= 0)
				continue;
			cnt++;
			egg_guard[i]-= eggs[now_idx].second;
			int now_cnt = 0;
			if (egg_guard[i] <= 0)
				now_cnt++;
			egg_guard[now_idx] -= eggs[i].second;
			if (egg_guard[now_idx] <= 0)
				now_cnt++;
			// cout << now_idx <<" 와 " <<  i <<"계란과 부딪히니"<< now_cnt << "개가 깨지네" <<"\n";
			break_egg(egg_guard,now_idx+1,break_cnt+now_cnt);
			// cout <<"재귀 나감" << now_idx << "\n";
			egg_guard[now_idx] +=eggs[i].second;
			egg_guard[i]+= eggs[now_idx].second;
		}
		if (cnt == 0)
			break_egg(egg_guard,now_idx+1,break_cnt);
	}
}

int main(){
	cin >> N;
	int egg_guard[8];
	for(int i=0;i<N;i++){
		int guard, weight;
		cin >> guard >> weight;
		eggs[i]= {guard,weight};
		egg_guard[i] = guard;
	}
	break_egg(egg_guard,0,0);
	cout << max_break << "\n";
}