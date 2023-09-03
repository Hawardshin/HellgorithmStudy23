#include <iostream>
#include <algorithm>
#include <queue>
#include <cstdio>

using namespace std;

int n,m,res=-1;
int num[1005][1005]={0,},visit[1005][1005]={0,};

typedef struct {
    int x;
    int y;
    int cnt;
} pos;

queue <pos> q;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    cin>>n>>m;
    getchar();

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            char c = getchar();
            num[i][j]=c-'0';
        }getchar();
    }

    pos p;
    p.x=0; p.y=0; p.cnt=1;
    visit[0][0] = 1;
    q.push(p);

    int res = -1;
    while (!q.empty())
    {
        int x = q.front().x;
        int y = q.front().y;
        int cnt = q.front().cnt;
        q.pop();

        if (x == n-1 && y == m-1){
            res = cnt;
            break;
        }

        if (x!=0 && num[x-1][y]==1 && visit[x-1][y]==0){
            pos temp; temp.x=x-1; temp.y=y; temp.cnt=cnt+1; q.push(temp); visit[x-1][y] = 1;
        }
        if (y!=0 && num[x][y-1]==1 && visit[x][y-1]==0){
            pos temp; temp.x=x; temp.y=y-1; temp.cnt=cnt+1; q.push(temp); visit[x][y-1] = 1;
        }
        if (x!=n-1 && num[x+1][y]==1 && visit[x+1][y]==0){
            pos temp; temp.x=x+1; temp.y=y; temp.cnt=cnt+1; q.push(temp); visit[x+1][y] = 1;
        }
        if (y!=m-1 && num[x][y+1]==1 && visit[x][y+1]==0){
            pos temp; temp.x=x; temp.y=y+1; temp.cnt=cnt+1; q.push(temp); visit[x][y+1] = 1;
        }
    }

    cout<<res;

    return 0;
}
