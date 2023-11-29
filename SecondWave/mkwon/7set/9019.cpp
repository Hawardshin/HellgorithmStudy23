#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

struct pos{
    int len;
    string cmd;
    int num;
};

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int t;
    cin>>t;

    while (t--){
        int a,b;
        cin>>a>>b;

        vector <int> v;
        queue <pos> pq;
        pos p; p.len=0; p.cmd=""; p.num=a;
        v.push_back(a);
        pq.push(p);
        while(!pq.empty()){
            int len = pq.front().len;
            string cmd = pq.front().cmd;
            int num = pq.front().num;
            pq.pop();

            if (num == b){
                cout<<cmd<<"\n";
                break;
            }

            pos temp; temp.len=len+1;

            // D
            int d = num*2;
            if (d > 9999) d = d%10000;
            if (find(v.begin(), v.end(), d) == v.end()){
                temp.cmd = cmd+'D';
                temp.num = d;
                pq.push(temp);
                v.push_back(d);
            } 

            // S
            int s = num-1;
            if (s < 0) s=9999;
            if (find(v.begin(), v.end(), s) == v.end()){
                temp.cmd = cmd+'S';
                temp.num = s;
                pq.push(temp);
                v.push_back(s);
            }

            int arr[4];
            int tNum = num;
            for (int i=3; i>=0; i--){
                arr[i] = tNum%10;
                tNum =tNum/10;
            }

            // L
            int l=0;
            for(int i=1,j=1000; i<4; i++){
                l+=arr[i]*j;
                j=j/10;
            }
            if (find(v.begin(), v.end(), l) == v.end()){
                l+=arr[0];
                temp.cmd = cmd+'L';
                temp.num = l;
                pq.push(temp);
                v.push_back(l);
            }

            // R
            int r = 0;
            for(int i=0,j=100; i<3; i++){
                r+=arr[i]*j;
                j=j/10;
            }
            r+=arr[3] * 1000;
            if (find(v.begin(), v.end(), r) == v.end()){
                temp.cmd = cmd+'R';
                temp.num = r;
                pq.push(temp);
                v.push_back(r);
            }
            
        }

    }
    
    return 0;
}
