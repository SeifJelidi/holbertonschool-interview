#!/usr/bin/python3
"""UTF 8 validaion"""



def validUTF8(data):
    try:
        for i in range(0, 256):
            for i in data:
                bytes(data).decode(encoding="UTF-8", errors="strict")
                return True
    except Exception:
        return False
