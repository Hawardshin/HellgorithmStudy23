#include <stdio.h> 

long long arr[100005]; 

int main()
{ 

  long long n,m; 
  scanf("%d %d",&n,&m); 
  for(int i=1;i<=n;i++)
  { 
    scanf("%d",&arr[i]); 
    arr[i] += arr[i-1]; 
  } 

  long long min = n + 1;
  long long i, j;
  i=0;
  j=0;
  while(i < n || j < n)
  {
      if (i == n)
          j++;
      else {
        if(arr[i] - arr[j - 1] < m)
            i++;
        else
            j++;
      }
      if (arr[i] - arr[j - 1] >= m && i + 1 - j < min)
          min = i + 1 - j;
   }
  if(min==n+1)
      min = 0;
  printf("%d",min);

  return 0; 

}
