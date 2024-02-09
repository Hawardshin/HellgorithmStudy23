#include <iostream>
#include <algorithm>
#include <deque> // 스택 대신 덱 사용
#define WHITE 0
#define RED 1
#define BLUE 2

enum e_dir{
    STOP,
    RIGHT,
    LEFT,
    UP,
    DOWN
};

int dy[5] = {0, 0, 0, -1, 1};
int dx[5] = {0, 1, -1, 0, 0};

typedef struct s_horse{
    int x;
    int y;
    int dir;
} t_horse;

using namespace std;

int N, K;
int table[11][11];
t_horse horseStore[11];
deque<int> parking[11][11]; // 스택 대신 덱 사용

void print_parking(){
    cout << "---------------------\n";
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            cout << parking[i][j].size();
        }
        cout << "\n";
    }
}

void input(){
    cin >> N >> K;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++) cin >> table[i][j];
    }
    for(int i = 1; i <= K; i++){
        int x, y, dir;
        cin >> y >> x >> dir;
        horseStore[i] = {x, y, dir};
        parking[y][x].push_back(i); // 스택의 push 대신 덱의 push_back 사용
    }
}

e_dir reverseDir(int dir){
    switch(dir){
        case LEFT: 
            return RIGHT;
        case RIGHT: 
            return LEFT;
        case UP:
            return DOWN;
        case DOWN: 
            return UP;
        default:
            return STOP;
    }
}

void updateStack(bool isRed, int now_horse, int nx, int ny, int x, int y){
    deque<int> tmp;
    // 말을 tmp에 임시로 옮깁니다.
    while(!parking[y][x].empty() && parking[y][x].front() != now_horse){
        tmp.push_back(parking[y][x].front());
        parking[y][x].pop_front();
    }
    tmp.push_back(parking[y][x].front()); // 현재 말도 tmp에 추가
    parking[y][x].pop_front(); // 현재 말을 parking에서 제거

    // 빨간 칸인 경우 tmp를 뒤집습니다.
    if(isRed){
        reverse(tmp.begin(), tmp.end());
    }

    // tmp에서 모든 말을 새 위치로 옮깁니다.
    while(!tmp.empty()){
        int horse = tmp.front();
        tmp.pop_front();
        horseStore[horse].x = nx;
        horseStore[horse].y = ny;
        parking[ny][nx].push_back(horse);
    }
}

bool moveNext(int horse, int x, int y, int dir){
    int nx = x + dx[dir];
    int ny = y + dy[dir];
    bool isRed = false;

    if(nx < 1 || ny < 1 || nx > N || ny > N || table[ny][nx] == BLUE){
        dir = reverseDir(horseStore[horse].dir);
        nx = x + dx[dir];
        ny = y + dy[dir];
        if(nx < 1 || ny < 1 || nx > N || ny > N || table[ny][nx] == BLUE){
            horseStore[horse].dir = dir; // 방향만 업데이트
            return false;
        }
    }

    if(table[ny][nx] == RED){
        isRed = true;
    }

    updateStack(isRed, horse, nx, ny, x, y);
    if(parking[ny][nx].size() >= 4) return true;
    return false;
}

int main(){
    input();
    int day = 1;
    while(day <= 1000){
        for(int i = 1; i <= K; i++){
            if(moveNext(i, horseStore[i].x, horseStore[i].y, horseStore[i].dir)){
                cout << day << "\n";
                return 0;
            }
        }
        day++;
    }
    cout << -1 << "\n";
    return 0;
}