#!/usr/bin/python3
"""
    Write a method that determines if a given data
    set represents a valid UTF-8 encoding
"""


def validUTF8(data):
    bit_c = 0

    for i in data:
        if bit_c:
            bit_c -= 1
            if (((i & 0xff) >> 6) != 2):
                return False
        elif (i & 0xF0) == 0xF0:
            bit_c = 3
        elif (i & 0xE0) == 0xE0:
            bit_c = 2
        elif (i & 0xC0) == 0xC0:
            bit_c = 1
        elif not (i & 0x80):
            bit_c = 0
        else:
            return False
    return not bit_c
