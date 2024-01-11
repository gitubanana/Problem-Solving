import sys

def readline(): return sys.stdin.readline()
def splitIntoInt(): return map(int, readline().split())

arr_size, slide_size = splitIntoInt()
arr = tuple(splitIntoInt())

sum_ = sum(arr[:slide_size])
max_ = sum_
for i in range(slide_size, arr_size):
    sum_ = sum_ - arr[i - slide_size] + arr[i]
    max_ = max(max_, sum_)

print(max_)
