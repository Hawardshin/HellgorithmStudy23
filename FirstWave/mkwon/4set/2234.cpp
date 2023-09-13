#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

int n,m,tab[55][55]={0,},vis[55][55]={0,};
int largeroom=0,roomcnt=0,res=0;

const int dx[] = { 0,-1,0,1 }; //서, 북, 동, 남
const int dy[] = { -1,0,1,0 }; //1,2,4,8

int bfs(int i, int j){
    int sum = 1;
    queue <pair<int,int>> q;
    q.push({i,j});
    vis[i][j]=1;

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        int wall = 1;
		for (int i = 0; i < 4; i++) {
			//해당 방향에 벽이 없으면
			if ((tab[x][y] & wall) != wall) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (nx < 0 || nx >= m || ny < 0 || ny >= n)
					continue;
				if (vis[nx][ny] == 0) {
					vis[nx][ny] = 1;
					q.push({ nx,ny });
					sum++;
				}
			}
			wall = wall * 2;
		}
    }
    return sum;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    cin>>n>>m;
    for (int i=0; i<m; i++)
		for (int j=0; j<n; j++)
			cin>>tab[i][j];
    
    // 방 개수랑 가장 큰 방 구하기
    for (int i=0; i<m; i++){
		for (int j=0; j<n; j++){
            if (!vis[i][j]){
                int temp = bfs(i,j);
                if (temp>largeroom) largeroom=temp;
                roomcnt++;
            }
        }
    }

    // 벽 제거
    for (int i=0; i<m; i++){
		for (int j=0; j<n; j++){
            // 2진수의 합
            for (int wall=1; wall<=8; wall*=2) {
				if ((tab[i][j] & wall) == wall) {
					memset(vis, false, sizeof(vis));
					tab[i][j]-=wall;
					int temp = bfs(i,j);
					if (res < temp)
						res = temp;
					tab[i][j] += wall;
				}
			}
        }
    }

    cout<<roomcnt<<"\n"<<largeroom<<"\n"<<res;

    return 0;
}