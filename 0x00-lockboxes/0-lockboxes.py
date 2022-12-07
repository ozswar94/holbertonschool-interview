#!/usr/bin/python3
""" define the function canUnlockAll"""


def canUnlockAll(boxes):
    """function that check if all boxes can unlock another boxes"""
    keys = range(len(boxes))
    index = 0
    for box in boxes:
        if box == [] and index < len(boxes) - 1:
            return False
        for i in box:
            if i not in keys:
                return False
        index += 1
    return True