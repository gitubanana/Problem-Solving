import sys

print(len({line[11:] for line in sys.stdin}))