#include <stdio.h> 

int arr[100001]; 

int main()

{ 

  int n,m; 

  scanf("%d %d",&n,&m); 

  for(int i=1;i<=n;i++)

  { 

    scanf("%d",&arr[i]); 

    arr[i] += arr[i-1]; 

  } 

  int cnt = 0;

  for(int i = 1; i <= n; i++)

    {

      for(int j = i; j <= n; j++)

        {

          if (arr[j] - arr[i - 1] == m)

            cnt++;

        }

    }

  printf("%d",cnt);

  return 0; 

}
