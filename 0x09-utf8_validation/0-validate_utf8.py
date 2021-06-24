#!/usr/bin/python3
"""UTF 8 validaion"""
import codecs


def validUTF8(data):
    try:
        s = bytes(data).decode(encoding="UTF-8", errors="strict")
        return True
    except Exception:
        return False
