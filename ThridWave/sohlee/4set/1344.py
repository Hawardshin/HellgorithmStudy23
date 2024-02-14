# 18 -> 2,3,5,7,11,13,17
import math
prime=[2,3,5,7,11,13,17]
def percentage(win_rate):
    ans=0
    for i in prime:
        ans+=math.comb(18,i)*(win_rate**i)*((1-win_rate)**(18-i))
    return ans
a=int(input())
b=int(input())

a_per=percentage(a/100)
b_per=percentage(b/100)

print(a_per+b_per-a_per*b_per)
