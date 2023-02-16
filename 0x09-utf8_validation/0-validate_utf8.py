#!/usr/bin/python3
"""
    Write a method that determines if a given data
    set represents a valid UTF-8 encoding
"""


def validUTF8(data):
    size = len(data)

    for i in data:
        bit = 7
        valid_bit = 0
        if i < 128:
            size -= 1
            continue
        elif i >= 256:
            return False

        while (bit > 4) and (i & (1 << bit)):
            valid_bit += 1
            bit -= 1

        size -= valid_bit
        if size < 0:
            return False

    return True
