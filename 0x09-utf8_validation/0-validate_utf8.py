#!/usr/bin/python3
"""
    Write a method that determines if a given data
    set represents a valid UTF-8 encoding
"""


def validUTF8(data):
    size = len(data)
    i = 0

    while i < len(data):
        bit = 7
        valid_bit = 0

        if data[i] < (1 << 7):
            size -= 1
            i += 1
            continue

        while (bit >= 4) and (data[i] & (1 << bit)):
            valid_bit += 1
            bit -= 1
        size -= valid_bit
        if size < 0:
            return False
        i += valid_bit

    return True
