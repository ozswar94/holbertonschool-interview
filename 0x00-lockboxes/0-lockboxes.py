#!/usr/bin/python3
""" define the function canUnlockAll"""


def canUnlockAll(boxes):
    """function that check if all boxes can unlock another boxes"""
    ptr1 = 0
    ptr2 = len(boxes) - 1
    size = len(boxes) - 1

    while ptr1 <= ptr2:
        if (
            (len(boxes[ptr1]) == 0 and ptr1 != size) or
            (len(boxes[ptr2]) == 0 and ptr2 != size)
        ):
            return False

        for i in boxes[ptr1]:
            print(i, size)
            if i > size and ptr1 != size:
                return False
        for i in boxes[ptr2]:
            print(i, size)
            if i > size and ptr2 != size:
                return False

        ptr1 += 1
        ptr2 -= 1

    return True
