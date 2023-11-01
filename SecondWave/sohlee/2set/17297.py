import sys
n=int(sys.stdin.readline())
dp=[5,13]
ans = '	'
def fibo(index,n,dp):
	global ans
	if index<=1:
		ans="Messi Gimossi"[n-1]
		return ans
	elif n>dp[index-1]+1:
		ans=fibo(index-2,n-dp[index-1]-1, dp)
	elif n<dp[index-1]:
		ans=fibo(index-1,n,dp)
	else:
		ans=" "
	return ans

while dp[-1]<n:
	dp.append(dp[-2]+1+dp[-1])
ans = fibo(len(dp)-1,n,dp)
if ans==" ":
	print("Messi Messi Gimossi")
else:
	print(ans)