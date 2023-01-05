#!/usr/bin/python3
""" Task 04 """


def minOperations(n):
    if not n or not isinstance(n, int) or n <= 1:
        return 0
    ch, op = 1, 0
    while ch != n:
        if (n % ch) == 0:
            cp = ch
            op += 1
        ch += cp
        op += 1
    return op
