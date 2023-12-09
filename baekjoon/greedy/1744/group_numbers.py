import sys

def get_cnt():
    minus, plus = 0, 0
    for cur in arr:
        minus += (cur < 0)
        plus += (cur > 0)
    return (minus, size - (minus + plus), plus)

inputToInt = lambda: int(sys.stdin.readline())
size = inputToInt()
arr = [inputToInt() for _ in range(size)]
arr.sort()

i, result = 0, 0
minus, zero, plus = get_cnt()
while i < minus - 1:
    result += arr[i] * arr[i + 1]
    i += 2
if minus & 1 and zero == 0:
    result += arr[minus - 1]

i = size - 1
size -= plus
while i > size:
    addition = arr[i] + arr[i - 1]
    multiply = arr[i] * arr[i - 1]
    if addition > multiply:
        result += addition
    else:
        result += multiply
    i -= 2
if plus & 1:
    result += arr[i]

print(result)
