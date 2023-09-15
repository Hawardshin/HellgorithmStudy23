#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int n,tab[105][105]={0,};
queue <pair<int,char>> q;
vector <pair<int,int>> v;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    cin>>n;
    int a,b,temp; char ch;
    cin>>temp;
    for(int i=0; i<temp; i++){
        cin>>a>>b;
        tab[a][b]=1; //apple
    }
    cin>>temp;
    for(int i=0; i<temp; i++){
        cin>>a>>ch;
        q.push({a,ch}); //move
    }

    int x=1,y=1,cnt=0; 
    char dir='d'; // w,a,s,d
    v.push_back({1,1});
    while(1){

        // 방황 변환
        if (!q.empty() && cnt == q.front().first){
            char c = q.front().second;
            q.pop();
            if (c=='D'){
                if (dir=='w') dir='d';
                else if (dir=='a') dir='w';
                else if (dir=='s') dir='a';
                else if (dir=='d') dir='s';
            }
            if(c=='L'){
                if (dir=='w') dir='a';
                else if (dir=='a') dir='s';
                else if (dir=='s') dir='d';
                else if (dir=='d') dir='w';
            }
        }

        // 이동
        if (dir=='w') x--;
        if (dir=='a') y--;
        if (dir=='s') x++;
        if (dir=='d') y++;
        cnt++;

        // 꼬리랑 부닥치거나 벽이랑 부닥침
        if (find(v.begin(), v.end(), make_pair(x,y)) != v.end()) break;
        if (x==0 || x>n || y==0 || y>n) break;

        // 좌표 이동
        if (tab[x][y]) tab[x][y]=0;
        else v.erase(v.begin());
        v.push_back({x,y});
    }
    cout<<cnt;

    return 0;
}