import sys
n,k=map(int,sys.stdin.readline().split())
li=list(map(int, sys.stdin.readline().split()))
nums=set()
cnt=0
def find_latest(i) :
  result=0
  max_index=-1
  for num in nums:
    try:
      num_index=li[i:].index(num)
    except:
      num_index=k
    if max_index<num_index:
      result, max_index=num, num_index
  return result
for index, num in enumerate(li):
  nums.add(num)
  if len(nums)>n:
    cnt+=1
    latest_used=find_latest(index)
    nums.discard(latest_used)
print(cnt)