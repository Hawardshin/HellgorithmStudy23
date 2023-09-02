#include <iostream>
#include <algorithm>

using namespace std;

int n,m,num[1026][1026]={0,};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>n>>m;

    for(int i=1; i<=n; i++){
        for (int j=1; j<=n; j++){
            int a;
            cin>>a;

            if (i==1 && j==1) num[i][j] = a;
            else if (i==1) num[i][j] = num[i][j-1] + a;
            else if (j== 1) num[i][j] = num[i-1][j] + a;
            else num[i][j] = num[i][j-1] + num[i-1][j] - num[i-1][j-1] + a;
        }
    }

    for(int i=0; i<m; i++){
        int x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        cout<<num[x2][y2] - num[x1-1][y2] - num[x2][y1-1] + num[x1-1][y1-1]<<"\n";
    }
    
    return 0;
}