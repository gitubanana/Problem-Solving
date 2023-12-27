import sys


def get_max():
    max_ = -1000
    dp = [0 for _ in range(size)]
    tmp = [0 for _ in range(size)]

    dp[0] = arr[0]
    tmp[0] = arr[0]
    for i in range(1, size):
        next_dp = dp[i - 1] + arr[i]
        if next_dp < arr[i]:
            dp[i] = arr[i]
        else:
            dp[i] = next_dp

        next_tmp = tmp[i - 1] + arr[i]
        if (arr[i] < 0
                and dp[i - 1] > next_tmp):
            tmp[i] = dp[i - 1]
        else:
            tmp[i] = next_tmp

    max_ = max(dp)
    max_ = max(max_, *tmp)
    return max_


if __name__ == '__main__':
    def readline(): return sys.stdin.readline()
    def splitIntoInt(): return map(int, readline().split())

    size = int(readline())
    arr = list(splitIntoInt())

    print(get_max())
