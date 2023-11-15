#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int t,n,m,k,d;
int num[505]={0,};

vector <std::pair<int,int>> v;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin>>n;
    for(int i=0; i<n; i++){
        int a,b;
        cin>>a>>b;
        v.push_back({a,b});
    }

    sort(v.begin(), v.end());

    // second에 대해 최대부분수열

    // num[0]=1;
    // for(int i=0,j=1; ;){
    //     int a = v[i].second;
    //     int b = v[j].second;

    //     if(j==n) break;

    //     if (v[j-1].second < v[j].second) {
    //         num[j] = num[j-1] + 1;
    //         j++;
    //     }
    //     else {
    //         if (v[i].second < v[j].second) num[j]=num[i]+1;
    //         else num[j]=1;
    //         i=j;
    //         j++;
    //     }
    // }
    num[0] = 1;
    for (int i = 1; i < n; i++) {
        num[i] = 1; // 초기값 설정

        for (int j = 0; j < i; j++) {
            if (v[j].second < v[i].second && num[i] < num[j] + 1) {
                num[i] = num[j] + 1;
            }
        }
    }

    int res=0;
    for(int i=0; i<n; i++){
        if (num[i] > res) res=num[i];
        // cout<<num[i]<<" ";
    } 
    // cout<<"\n";

    cout<<(n-res);

    
    return 0;
}

// 8
// 1 8
// 2 2
// 3 9
// 4 1
// 6 4
// 7 6
// 9 7
// 10 10

// 4
// 1 1
// 2 4
// 3 2
// 4 3

// 10
// 1 6
// 2 8
// 3 2
// 4 9
// 5 5
// 6 10
// 7 4
// 8 1
// 9 7
// 10 3