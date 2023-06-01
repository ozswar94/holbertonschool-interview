#!/usr/bin/python3
"""
Rotate 2D Matrix
"""


def rotate_2d_matrix(matrix):
    for i in range(len(matrix)):
        for j in range(i + 1, len(matrix)):
            tmp = matrix[i][j]
            matrix[i][j] = matrix[j][i]
            matrix[j][i] = tmp

    for rw in matrix:
        rw.reverse()
