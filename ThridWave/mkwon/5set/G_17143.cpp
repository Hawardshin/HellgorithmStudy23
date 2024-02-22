#include <iostream>
#include <queue>
using namespace std;

int R, C, M;

struct Shark {
    int r;
    int c;
    int s;
    int d;
    int z = 0;
};
struct cmp {
    bool operator()(Shark s1, Shark s2) { return s1.z < s2.z; }
};
Shark shark;

int dr[5] = {0, -1, 1, 0, 0};
int dc[5] = {0, 0, 0, 1, -1};
int opposite[5] = {0, 2, 1, 4, 3};

Shark board[101][101];

int sum_shark_size = 0;

void fishing() {
    int c = 0;
    while (c < C) {
        // 1. 낚시왕 한 칸 이동
        c++;

        // 2. 상어 잡기
        for (int r = 1; r <= R; r++) {
            if (board[r][c].z > 0) {
                sum_shark_size += board[r][c].z;
                board[r][c].z = 0;
                break;
            }
        }

        // 3. 상어 이동
        priority_queue<Shark, vector<Shark>, cmp> pq;
        for (int r = 1; r <= R; r++) {
            for (int c = 1; c <= C; c++) {
                if (board[r][c].z == 0) continue;
                shark = board[r][c];
                board[r][c].z = 0;

                if (shark.d == 2) {
                    int n = R - shark.r;
                    if (shark.s <= n) {
                        shark.r += dr[shark.d] * shark.s;
                    } else {
                        shark.r = R;
                        int q, m;
                        q = (shark.s - n) / (R - 1);
                        m = (shark.s - n) % (R - 1);
                        if (q % 2 == 1) {
                            shark.d = 1;
                            shark.r = 1;
                        }
                        for (int i = 0; i < m; i++) {
                            shark.r += dr[shark.d];
                            if (shark.r < 1 || shark.r > R) {
                                shark.r -= dr[shark.d];
                                shark.d = opposite[shark.d];
                                shark.r += dr[shark.d];
                            }
                        }
                    }
                } else if (shark.d == 1) {
                    int n = shark.r - 1;
                    if (shark.s <= n) {
                        shark.r += dr[shark.d] * shark.s;
                    } else {
                        shark.r = 1;
                        int q, m;
                        q = (shark.s - n) / (R - 1);
                        m = (shark.s - n) % (R - 1);
                        if (q % 2 == 1) {
                            shark.d = 2;
                            shark.r = R;
                        }
                        for (int i = 0; i < m; i++) {
                            shark.r += dr[shark.d];
                            if (shark.r < 1 || shark.r > R) {
                                shark.r -= dr[shark.d];
                                shark.d = opposite[shark.d];
                                shark.r += dr[shark.d];
                            }
                        }
                    }
                } else if (shark.d == 3) {
                    int n = C - shark.c;
                    if (shark.s <= n) {
                        shark.c += dc[shark.d] * shark.s;
                    } else {
                        shark.c = C;
                        int q, m;
                        q = (shark.s - n) / (C - 1);
                        m = (shark.s - n) % (C - 1);
                        if (q % 2 == 1) {
                            shark.d = 4;
                            shark.c = 1;
                        }
                        for (int i = 0; i < m; i++) {
                            shark.c += dc[shark.d];
                            if (shark.c < 1 || shark.c > C) {
                                shark.c -= dc[shark.d];
                                shark.d = opposite[shark.d];
                                shark.c += dc[shark.d];
                            }
                        }
                    }
                } else if (shark.d == 4) {
                    int n = shark.c - 1;
                    if (shark.s <= n) {
                        shark.c += dc[shark.d] * shark.s;
                    } else {
                        shark.c = 1;
                        int q, m;
                        q = (shark.s - n) / (C - 1);
                        m = (shark.s - n) % (C - 1);
                        if (q % 2 == 1) {
                            shark.d = 3;
                            shark.c = C;
                        }
                        for (int i = 0; i < m; i++) {
                            shark.c += dc[shark.d];
                            if (shark.c < 1 || shark.c > C) {
                                shark.c -= dc[shark.d];
                                shark.d = opposite[shark.d];
                                shark.c += dc[shark.d];
                            }
                        }
                    }
                }
                pq.push(shark);
            }
        }

        while (!pq.empty()) {
            shark = pq.top();
            pq.pop();
            if (board[shark.r][shark.c].z > 0) continue;
            board[shark.r][shark.c] = shark;
        }
    }
}

int main(int argc, const char* argv[]) {
    cin >> R >> C >> M;
    for (int m = 0; m < M; m++) {
        cin >> shark.r >> shark.c >> shark.s >> shark.d >> shark.z;
        board[shark.r][shark.c] = shark;
    }

    fishing();
    cout << sum_shark_size << endl;

    return 0;
}