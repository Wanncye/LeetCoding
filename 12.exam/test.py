n,m = input().split(' ')
n, m = int(n), int(m)
timeList = []
valueList = []
for i in range(n):
    time, value = input().split(' ')
    timeList.append(int(time))
    valueList.append(int(value))

ansValue=0
for i in range(n):
    for j in range(i+1, n):
        if timeList[i] + timeList[j] <= m:
            ansValue = max(ansValue, valueList[i] + valueList[j])

print(ansValue)