#!/usr/bin/python3
""" define the function canUnlockAll"""


def canUnlockAll(boxes):
    """function that check if all boxes can unlock another boxes"""
    keys = [0]
    keys_v = list(range(0, len(boxes)))

    for i in keys:
        try:
            for j in boxes[i]:
                if j not in keys and j < len(boxes):
                    keys.append(j)
        except IndexError:
            return False

    return len(keys) == len(keys_v)
