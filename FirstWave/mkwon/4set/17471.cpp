#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
#define INF 2147483647

int n,res=INF,num[12]={0,},vis[12]={0,};
vector <int> vec[10];

int check(){
    queue <int> q1,q2;
    int visit[12]={0,};

    for(int i=1; i<=n; i++){
        if (vis[i]){
            q1.push(i);
            visit[i]=1;
            break;
        }
    }
    for(int i=1; i<=n; i++){
        if (!vis[i]){
            q2.push(i);
            visit[i]=1;
            break;
        }
    }

    if (q1.size() == 0 || q2.size() == 0) return 0;

    while(!q1.empty()){
        int front = q1.front();
        q1.pop();

        for(int i=0; i<vec[front].size(); i++){
            int next = vec[front][i];
            if (!visit[next] && vis[next]){
                q1.push(next);
                visit[next]=1;
            }
        }
    }

    while(!q2.empty()){
        int front = q2.front();
        q2.pop();

        for(int i=0; i<vec[front].size(); i++){
            int next = vec[front][i];
            if (!visit[next] && !vis[next]){
                q2.push(next);
                visit[next]=1;
            }
        }
    }

    for(int i=1; i<=n; i++){
        if (!visit[i]) return 0;
    }
    return 1;
}

void loop(int x){

    if (check()){
        int sum1=0,sum2=0;
        for(int i=1; i<=n; i++){
            if (vis[i]) sum1+=num[i];
            else sum2+=num[i];
        }
        if (abs(sum1-sum2) < res) res = abs(sum1-sum2);
    }

    for (int i=x; i<=n; i++){
        if (vis[i]) continue;
        vis[i] = 1;
        loop(i);
        vis[i] = 0;
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    cin>>n;
    for(int i=1; i<=n; i++) cin>>num[i];
    for(int i=1; i<=n; i++){
        int x; cin>>x;
        for(int j=0; j<x; j++){
            int y; cin>>y;
            vec[i].push_back(y);
        }
    }

    loop(1);
    if(res==INF) cout<<"-1";
    else cout<<res;

    return 0;
}