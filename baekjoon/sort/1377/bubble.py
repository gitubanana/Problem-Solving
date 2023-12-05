import sys

if __name__ == '__main__':
    readline = sys.stdin.readline
    size = int(readline())
    arr = []
    for i in range(size):
        arr.append([int(readline()), i])

    arr.sort(key=lambda x: x[0])

    answer = arr[0][1]
    for i in range(1, size):
        answer = max(answer, arr[i][1] - i)

    print(answer + 1)
