def checkConsistency(arr):
    if arr[0] == 0 and arr[1] == 0 and arr[2] == 0 and arr[3] == 0:
        raise Exception

    return  max(0, arr[1]-0.5)*9 + max(0, arr[2]-0.5)*4 + max(0, arr[3]-0.5)*4 \
        <= arr[0] \
         < (arr[1]+0.5)*9 + (arr[2]+0.5)*4 + (arr[3]+0.5)*4

try:
    while True:
        print('yes' if checkConsistency(list(map(float, input().split()))) else 'no')
except Exception:
    pass

# 숫자가 A라면
# A-0.5 ~ A+0.4
