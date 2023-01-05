#!/usr/bin/python3
"""
In a text file, there is a single character H.
Your text editor can execute only two operations
in this file: Copy All and Paste
"""


def minOperations(n):
    if not n or not isinstance(n, int) or n <= 1:
        return 0
    ch = 'H'
    op = 0
    cp = ''
    while len(ch) != n:
        if len(ch) % 2 or len(ch) == n // 2:
            cp = ch
            ch += cp
            op += 2
        else:
            ch += cp
            op += 1
    return op
