#include <iostream>
#include <algorithm>

using namespace std;

int n;
long m,num[10005];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>n>>m;

    for (int i=0; i<n; i++){
        int a;
        cin>>a;
        if (i==0) num[i] = a;
        else num[i] = num[i-1] + a;
    }

    int cnt = 0;
    if (num[0] == m) cnt++;
    for (int i=0,j=1; i<n&&j<n; ){
        int temp;
        if (i == 0) temp = 0;
        else temp = num[i-1];

        if (num[j] - temp == m){
            cnt++;
            i++;
        }
        else if (num[j] - temp > m) i++;
        else if (num[j] - temp < m) j++;
    }

    cout<<cnt;

    return 0;
}