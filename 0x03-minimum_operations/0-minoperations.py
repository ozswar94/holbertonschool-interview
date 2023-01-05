#!/usr/bin/python3
""" Task 04 """


def minOperations(n):
    if not n or not isinstance(n, int) or n <= 1:
        return 0
    ch = 'H'
    op = 0
    cp = ''
    while len(ch) != n:
        if n % len(ch) == 0:
            cp = ch
            ch += cp
            op += 2
        else:
            ch += cp
            op += 1
    return op
