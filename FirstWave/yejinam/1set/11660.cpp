#include <stdio.h>

int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    long long arr[1026][1026];
    for (int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
        scanf("%lld", &arr[i][j]);
            if (i == 1) {
                arr[i][j] += arr[i][j - 1];
            }
            else if (j == 1){
                arr[i][j] += arr[i - 1][j];
            }
            else {
                arr[i][j] += arr[i - 1][j] + arr[i][j - 1] - arr[i - 1][j - 1];
            }
        }
     }


    while (m--){
        int x, y, X, Y;
        scanf("%d %d %d %d", &x, &y, &X, &Y);
        long long sum = 0;
           
        sum = arr[X][Y] - arr[X][y - 1] - arr[x - 1][Y] + arr[x - 1][y - 1];
        printf("%lld\n", sum);
    }
}
