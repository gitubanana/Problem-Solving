import sys

start = int(sys.stdin.readline())
end = int(sys.stdin.readline())
sum_ = 0
min_ = 0
start_sqrt, end_sqrt = int(start**0.5), int(end**0.5)
if start_sqrt**2 == start:
    sum_ += start
    min_ = start
for i in range(start_sqrt + 1, end_sqrt + 1):
    sum_ += i**2
    if min_ == 0:
        min_ = i**2

if sum_ == 0:
    print(-1)
else:
    print(sum_, min_, sep='\n')
