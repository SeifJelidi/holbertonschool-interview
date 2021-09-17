#!/usr/bin/python3
""" a script that reads stdin line by line and computes metrics
"""
import sys

if __name__ == '__main__':

    status_codes = {'200': 0, '301': 0, '400': 0, '401': 0,
                    '403': 0, '404': 0, '405': 0, '500': 0}
    filesize = 0
    count = 0

    def print_status(stats: dict, file_size: int) -> None:
        print("File size: {:d}".format(filesize))
        for k, v in sorted(stats.items()):
            if v:
                print("{}: {}".format(k, v))

    try:
        for line in sys.stdin:
            count += 1
            data = line.split()
            try:
                code = data[-2]
                if code in status_codes:
                    status_codes[code] += 1
            except BaseException:
                pass
            try:
                filesize += int(data[-1])
            except BaseException:
                pass
            if count % 10 == 0:
                print_status(status_codes, filesize)
        print_status(status_codes, filesize)
    except KeyboardInterrupt:
        print_status(status_codes, filesize)
        raise
