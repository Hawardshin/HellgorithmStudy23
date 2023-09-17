import sys
import itertools
N,K=map(int,sys.stdin.readline().split())
word=[]
total=set([])
teach=[0]*30
origin=set(['a','n','t','i','c'])
for i in range(N):
    tmp=set(str(input()))-origin
    word.append(tmp)
    total.update(tmp)

if K-5<0:
    print(0)
elif K>=26:
    print(len(word))
else:
    if K-5>=len(total):
        print(len(word))
    else:
        combi=list(itertools.combinations(total,K-5))
        ans=0
        for i in range(len(combi)):
            total=0
            for j in combi[i]:
                teach[ord(j)-97]=1
            for j in range(len(word)):
                cnt=0
                for k in word[j]:
                    if teach[ord(k)-97]==1:
                        cnt+=1
                if cnt==len(word[j]):
                    total+=1
            for j in combi[i]:
                teach[ord(j)-97]=0
            
            ans=max(ans,total)
        print(ans)
