#!/usr/bin/python3
"""
lockboxes
"""


def canUnlockAll(boxes):
    if not boxes:
        return False
    keys = [0]
    for key in keys:
        for box in boxes[key]:
            if box not in keys and box < len(boxes):
                keys.append(box)

    return len(keys) == len(boxes)
