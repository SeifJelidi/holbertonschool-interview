#!/usr/bin/python3
'''
calculates the fewest number of operations
needed to result in exactly n H characters in the file
'''


def minOperations(n):

    if n <= 1:
        return 0

    op = 2
    nb = 0
    while op <= n:
        while n % op == 0:
            nb += op
            n /= op
        op += 1
    return nb
