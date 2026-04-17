totalCnt, rateCnt = map(int, input().split())

ratedSum = 0
for _ in range(rateCnt):
    ratedSum += int(input())

remainCnt = totalCnt - rateCnt
print((ratedSum + -3*remainCnt) / totalCnt, (ratedSum + 3*remainCnt) / totalCnt)
