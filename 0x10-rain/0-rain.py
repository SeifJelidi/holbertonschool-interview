#!/usr/bin/python3
"""
Rain
"""


def rain(walls):
    """
    Return: Integer indicating total
    amount of rainwater retained
    """
    i, j = 0, len(walls) - 1
    amount = 0
    n = 0
    while i < j:
        if walls[i] < walls[j]:
            current = walls[i]
            i += 1
        else:
            current = walls[j]
            j -= 1
        n = max(n, current)
        amount += n - current
    return amount
