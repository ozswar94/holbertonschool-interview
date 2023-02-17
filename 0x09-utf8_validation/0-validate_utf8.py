#!/usr/bin/python3
"""
    Write a method that determines if a given data
    set represents a valid UTF-8 encoding
"""


def validUTF8(data):
    i = 0

    while i < len(data):
        bit = 7
        valid_bit = 0

        if data[i] < (1 << 7):
            i += 1
            continue

        if data[i] & (1 << 7) and not data[i] & (1 << 6):
            return False

        while bit >= 4 and (data[i] & (1 << bit)):
            valid_bit += 1
            bit -= 1

        if i + valid_bit < len(data) or valid_bit == 0:
            return False
        i += valid_bit

    return True
