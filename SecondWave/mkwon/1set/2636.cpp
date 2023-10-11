#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int n,m;
int num[105][105]={0,},newnum[105][105]={0,},vis[105][105]={0,};
int endFlag=0,rescnt=0,realrescnt=0;

void findAir(){
    int flag=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if (num[i][j]==0 && vis[i][j]==0){
                queue <pair<int,int>> q;
                q.push({i,j}); vis[i][j]=1;

                while (!q.empty()){
                    int x = q.front().first;
                    int y= q.front().second;
                    q.pop();

                    if(x!=0 && num[x-1][y]==0 && vis[x-1][y]==0){
                        q.push({x-1,y}); vis[x-1][y]=1;
                    }
                    if(y!=0 && num[x][y-1]==0 && vis[x][y-1]==0){
                        q.push({x,y-1}); vis[x][y-1]=1;
                    }
                    if(x!=n-1 && num[x+1][y]==0 && vis[x+1][y]==0){
                        q.push({x+1,y}); vis[x+1][y]=1;
                    }
                    if(y!=m-1 && num[x][y+1]==0 && vis[x][y+1]==0){
                        q.push({x,y+1}); vis[x][y+1]=1;
                    }
                }

                flag=1;
                break;
            }
        }
        if(flag) break;
    }
}

void findisland(){
    int flag=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if (num[i][j]==1 && vis[i][j]==0){
                flag=1;
                queue <pair<int,int>> q;
                q.push({i,j}); vis[i][j]=1;

                while (!q.empty()){
                    rescnt++;
                    int x = q.front().first;
                    int y= q.front().second;
                    q.pop();

                    if(x!=0 && num[x-1][y]==1 && vis[x-1][y]==0){
                        q.push({x-1,y}); vis[x-1][y]=1;
                    }
                    if(y!=0 && num[x][y-1]==1 && vis[x][y-1]==0){
                        q.push({x,y-1}); vis[x][y-1]=1;
                    }
                    if(x!=n-1 && num[x+1][y]==1 && vis[x+1][y]==0){
                        q.push({x+1,y}); vis[x+1][y]=1;
                    }
                    if(y!=m-1 && num[x][y+1]==1 && vis[x][y+1]==0){
                        q.push({x,y+1}); vis[x][y+1]=1;
                    }

                    newnum[x][y]=1;
                    if(x!=0 && num[x-1][y]==0 && vis[x-1][y]==1) newnum[x][y]=0;
                    if(y!=0 && num[x][y-1]==0 && vis[x][y-1]==1) newnum[x][y]=0;
                    if(x!=n-1 && num[x+1][y]==0 && vis[x+1][y]==1) newnum[x][y]=0;
                    if(y!=m-1 && num[x][y+1]==0 && vis[x][y+1]==1) newnum[x][y]=0;

                }

            }
        }
    }
    if (flag == 0) endFlag=1;
}

int loop(int cnt){

    while(1){
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                vis[i][j]=0;
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                newnum[i][j]=0;
            }
        }

        findAir();
        rescnt=0;
        findisland();
        realrescnt=rescnt;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                num[i][j]=newnum[i][j];
            }
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                vis[i][j]=0;
            }
        }
        findisland();
        if(endFlag) return cnt;

        cnt++;
    }
}

int main(){

    cin>>n>>m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>num[i][j];
        }
    }
    
    cout<<loop(1)<<"\n"<<realrescnt;

    return 0;
}