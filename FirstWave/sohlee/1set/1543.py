script = str(input())
word = str(input())
ans = 0
index = 0
while (index < len(script)):
    index = script.find(word, index)
    if (index == -1):
        break
    ans += 1
    index += len(word)
print(ans)