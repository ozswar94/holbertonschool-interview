#!/usr/bin/python3
""" define the function canUnlockAll"""


def canUnlockAll(boxes):
    """function that check if all boxes can unlock another boxes"""

    keys = [0]
    new_key = True

    while new_key:
        new_key = False
        for b in boxes:
            if boxes.index(b) in keys:
                for i in b:
                    if i not in keys:
                        new_key = True
                        keys.append(i)
    if len(boxes) == len(keys):
        return True
    else:
        return False
