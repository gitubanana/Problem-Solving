import sys

size = int(input())
arr = list(map(int, input().split()))
for i in range(size):
    for j in range(size):
        if i == j:
            continue

        for k in range(size):
            if i == k or j == k:
                continue

            if (arr[i] - arr[j]) % arr[k] != 0:
                print('no')
                sys.exit()

print('yes')
