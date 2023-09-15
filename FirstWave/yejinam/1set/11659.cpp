#include <stdio.h>

int arr[100001];

int main(){
    int n,m;

    scanf("%d %d",&n,&m);

    for(int i = 1; i <= n; i++)
    {
        scanf("%d",&arr[i]);
        arr[i] += arr[i - 1];
    }

    for(int i = 0; i < m; i++)
    {
        int a, b;
        scanf("%d %d",&a,&b);
        printf("%d\n",arr[b] - arr[a-1]);
    }

}
