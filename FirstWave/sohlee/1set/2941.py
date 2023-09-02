li = ["c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z="]

word = str(input())
index = 0
ans = 0
for i in range(len(li)):
    index = 0
    while (index < len(word)):
        index = word.find(li[i], index)
        if (index == -1):
            break
        word = word.replace(li[i], " ")
        index += 1
        ans += 1
print(len(word))