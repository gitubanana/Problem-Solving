import sys

if __name__ == '__main__':
    EMPTY, RESERVED = 0, 1
    def readline(): return sys.stdin.readline()
    def splitIntoInt(): return map(int, readline().split())

    test_cnt = int(readline())
    while test_cnt:
        attendee_cnt, seat_cnt = splitIntoInt()

        unavailable_cnt = 0
        seat = [EMPTY for _ in range(seat_cnt + 1)]
        while attendee_cnt:
            prefer = int(readline())
            if seat[prefer] == EMPTY:
                seat[prefer] = RESERVED
            else:
                unavailable_cnt += 1
            attendee_cnt -= 1
        print(unavailable_cnt)
        test_cnt -= 1
