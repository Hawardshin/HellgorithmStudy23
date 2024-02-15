#include <iostream>

#define LEFT first
#define RIGHT second
using namespace std;
char circle[1001][8];
pair<int,int> circleDir[1001];//{left, right}
// 0->12시, 2->3시, 6->9시
// left->2, right->6
// 0~7  (7->8 : 0) (0->-1 : 7)
int T;



int rotate(int a,int dir){
	if (dir == -1){ //반 시계 방향
		a++;
		if (a == 8)
			return (0);
	}else {
		a--;
		if (a == -1)
			return 7;
	}
	return a;
}

void printAll(){
	cout << "---------------\n";
	for(int i=1;i<=T;i++){
		cout <<"------------"<< i << "-----------\n";
		cout << "left Idx: "<<circleDir[i].LEFT  << "| right idx:"<< circleDir[i].RIGHT << "\n";
	}
}

int reverseDir(int dir){
	if (dir == 1)
		return -1;
	return 1;
}

void	rotateAll(int num,int dir){
	bool nextLrotate=false;
	bool nextRrotate = false;
	if (num != 1 && circle[num-1][circleDir[num-1].RIGHT] != circle[num][circleDir[num].LEFT])
		nextLrotate = true;
	if (num != T && circle[num+1][circleDir[num+1].LEFT] != circle[num][circleDir[num].RIGHT])
		nextRrotate = true;
	circleDir[num].LEFT = rotate(circleDir[num].LEFT,dir);
	circleDir[num].RIGHT = rotate(circleDir[num].RIGHT,dir);

	int li = num -1;
	int ldir = reverseDir(dir);
	while (nextLrotate){
		// cout << "why"<<"\n";
		nextLrotate = false;
		if (li != 1 && circle[li-1][circleDir[li-1].RIGHT] != circle[li][circleDir[li].LEFT])
			nextLrotate = true;
		
		circleDir[li].LEFT = rotate(circleDir[li].LEFT,ldir);
		circleDir[li].RIGHT = rotate(circleDir[li].RIGHT,ldir);
		ldir = reverseDir(ldir);
		li--;
	}
	int ri = num+1;
	int rdir  = reverseDir(dir);
	while (nextRrotate){
		nextRrotate = false;
		if (ri != T && circle[ri+1][circleDir[ri+1].LEFT] != circle[ri][circleDir[ri].RIGHT])
			nextRrotate = true;
		circleDir[ri].LEFT = rotate(circleDir[ri].LEFT,rdir);
		circleDir[ri].RIGHT = rotate(circleDir[ri].RIGHT,rdir);
		rdir = reverseDir(rdir);
		ri++;
	}
	// printAll();
}


int main(){

	cin >> T;
	for(int i=1;i<=T;i++){
		char a;
		for(int j=0;j<8;j++){
			cin >>a;
			circle[i][j] = a;
		}
		circleDir[i] = {6,2};
	}

	int K;
	cin >> K;
	for(int i=0;i<K;i++){
		int num,dir;
		cin >> num>> dir;
		rotateAll(num,dir);
	}
	int ret =0;
	for(int i=1;i<=T;i++){
		int l = circleDir[i].RIGHT;
		l -=2;
		if (l <0)
			l+=8;
		if (circle[i][l] =='1')
			ret++;
	}
	cout << ret << "\n";
}
