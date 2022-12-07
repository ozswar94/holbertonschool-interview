#!/usr/bin/python3
""" define the function canUnlockAll"""


def canUnlockAll(boxes):
    """function that check if all boxes can unlock another boxes"""
    keys = [0]
    keys_v = list(range(0, len(boxes)))

    for box in boxes:
        if box == []:
            break
        for i in box:
            if i not in keys:
                keys.append(i)
    return len(keys) == len(keys_v)
