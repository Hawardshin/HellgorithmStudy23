#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int t,n;
int startX,startY;
int endX,endY;

struct pos{
    int prevX;
    int prevY;
    int x;
    int y;
    int beer;
};

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    cin>>t;
    while (t--){
        queue <pos> q;
        vector <pos> v;
        int flag=0;

        cin>>n;
        cin>>startX>>startY;

        for(int i=0; i<n; i++){
            int a,b;
            cin>>a>>b;

            pos p; p.prevX=startX; p.prevY=startY; p.x=a; p.y=b; p.beer=20;
            v.push_back(p);

            int templen = abs(startX-a) + abs(startY-b);
            if (templen <= 50*20){
                q.push(p);
            }
        }

        cin>>endX>>endY;
        int templen = abs(startX-endX) + abs(startY-endY);
        if (templen <= 50*20){
            pos p; p.prevX=startX; p.prevY=startY; p.x=endX; p.y=endY; p.beer=20;
            q.push(p);
        }

        while(!q.empty()){
            pos p = q.front();
            int prevX = p.prevX; 
            int prevY = p.prevY; 
            int x = p.x;
            int y = p.y;
            int beer = p.beer;
            q.pop();

            int len = abs(prevX-x) + abs(prevY-y);
            if (len <= beer*50){

                if (x==endX && y==endY){
                    flag=1;
                    break;
                }

                for (int i=0; i<v.size(); i++){
                    if (v[i].x == x && v[i].y == y){
                        // 내가 지금 이 편의점이라면
                        v.erase (v.begin()+i);
                        break;
                    }
                }

                for (int i=0; i<v.size(); i++){
                    int templen = abs((v[i].x)-x) + abs((v[i].y)-y);
                    if (templen <= 20*50){
                        pos temp;
                        temp.prevX=x;
                        temp.prevY=y;
                        temp.x=v[i].x;
                        temp.y=v[i].y;
                        temp.beer=20;
                        q.push(temp);
                    }
                }

                int templen = abs(endX-x) + abs(endY-y);
                if (templen <= 20*50){
                    pos temp;
                    temp.prevX=x;
                    temp.prevY=y;
                    temp.x=endX;
                    temp.y=endY;
                    temp.beer=20;
                    q.push(temp);
                } 
            }
        }
        if (flag == 1)  cout<<"happy\n";
        else cout<<"sad\n";
    }

    
    return 0;
}
