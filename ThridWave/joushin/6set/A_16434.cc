#include <iostream>
#define MONSTER 1
// 공격력, 생명력
#define PORTION 2
//파워,힐

#define ll long long
using namespace std;

typedef struct s_block{
	ll t;
	ll a;
	ll h;
}t_block;
int N;
ll attack;

t_block room[123457];
ll damage, maxDamage;
int main(){
	cin >>N >> attack;
	for(int i=0;i<N;i++){
		cin >> room[i].t >> room[i].a >> room[i].h ;
		if (room[i].t == MONSTER){
			ll monsterHp = room[i].h;
			monsterHp -= attack;
			if (monsterHp <=0)
				continue;
			ll hit_num = monsterHp / attack;
			if (monsterHp % attack != 0)
				hit_num++;
			damage+= (hit_num* room[i].a);
			maxDamage = max(maxDamage,damage);
		}else{
			attack += room[i].a;
			if (room[i].h > damage)
				damage= 0;
			else 
				damage-= room[i].h;
		}
	}
	cout << maxDamage +1 << "\n";

}