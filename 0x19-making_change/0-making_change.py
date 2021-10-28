#!/usr/bin/python3
"""
determine the fewest number of coins needed to meet a given amount total.
"""


def makeChange(coins, total):
    """determine the fewest number of coins needed to meet a given amount total.
    """
    if total <= 0:
        return 0
    coins.sort()
    coins.reverse()
    numB = 0
    for c in coins:
        if total <= 0:
            break
        rest = total // c
        numB += total // c
        total -= (total // c) * c
    if total != 0:
        return -1
    return numB
