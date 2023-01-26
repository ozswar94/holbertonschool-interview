#!/usr/bin/python3
""" Print some informations """
import sys


counter = 0
total = 0
code = {200: 0, 301: 0, 400: 0, 401: 0, 403: 0, 404: 0, 405: 0, 500: 0}


def getline():
    print("File size: {}".format(total))
    for c in sorted(code.keys()):
        if code[c] > 0:
            print("{}: {}".format(c, code[c]))


if __name__ == '__main__':
    try:
        for line in sys.stdin:
            counter += 1
            try:
                split_line = line.split()
                size = int(split_line[-1])
                total += size
                status = int(split_line[-2])
                code[status] += 1
            except ValueError:
                pass

            if counter % 10 == 0:
                getline()
    except KeyboardInterrupt:
        getline()
        raise
    getline()
