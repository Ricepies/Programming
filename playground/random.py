from time import time


def randInt(start: int, stop: int) -> int:
    seed = int(time() * 1000000)
    m, a, c = 2**32, 1664525, 1013904223
    seed = (a * seed + c) % m
    return start + seed % (stop - start)
