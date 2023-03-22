#!/usr/bin/python3

import sys


def nqueens(queens, xy_diff, xy_sum):
    """
        Finds all valid queen column positions that don't attack each other
    """
    p = len(queens)
    if p == n:
        queen_column.append(queens)
        return None
    for q in range(n):
        if q not in queens and p - q not in xy_diff and p + q not in xy_sum:
            nqueens(queens + [q], xy_diff + [p - q], xy_sum + [p + q])


def parse_argv():
    """Checks for usage errors"""
    if len(sys.argv) != 2:
        print("Usage: nqueens N")
        sys.exit(1)
    if not sys.argv[1].isdigit():
        print("N must be a number")
        sys.exit(1)
    n = int(sys.argv[1])
    if n < 4:
        print("N must be at least 4")
        sys.exit(1)
    return n


if __name__ == "__main__":
    n = parse_argv()
    queen_column = []
    nqueens([], [], [])
    for r in range(len(queen_column)):
        queen_posistion = []
        for c in range(len(queen_column[r])):
            queen_posistion.append([c, queen_column[r][c]])
        print(queen_posistion)
