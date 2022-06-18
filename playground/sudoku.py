from typing import List
import sys


class Sudoku:
    def __init__(self, sudoku: List[List[int]] = []):
        self.sudoku = sudoku

    def solveSudoku(self) -> None:
        if not self.sudoku:
            print("NameError: No sudoku exists!")
            sys.exit(1)

        def canBePutAt(y: int, x: int, n: int) -> bool:
            for i in range(9):
                if self.sudoku[y][i] == n or self.sudoku[i][x] == n:
                    return False
            subBoxStartX, subBoxStartY = (x // 3) * 3, (y // 3) * 3
            for i in range(3):
                for j in range(3):
                    if self.sudoku[subBoxStartY + i][subBoxStartX + j] == n:
                        return False
            return True

        for y in range(9):
            for x in range(9):
                if self.sudoku[y][x] == 0:
                    for n in range(1, 10):
                        if canBePutAt(y, x, n):
                            self.sudoku[y][x] = n
                            if self.solveSudoku() == 0:
                                return 0
                            self.sudoku[y][x] = 0
                    return 1
        print("Sudoku solved!")
        return 0

    def printSudoku(self) -> None:
        print(*self.sudoku, sep="\n")


board = [
    [5, 3, 0, 0, 7, 0, 0, 0, 0],
    [6, 0, 0, 1, 9, 5, 0, 0, 0],
    [0, 9, 8, 0, 0, 0, 0, 6, 0],
    [8, 0, 0, 0, 6, 0, 0, 0, 3],
    [4, 0, 0, 8, 0, 3, 0, 0, 1],
    [7, 0, 0, 0, 2, 0, 0, 0, 6],
    [0, 6, 0, 0, 0, 0, 2, 8, 0],
    [0, 0, 0, 4, 1, 9, 0, 0, 5],
    [0, 0, 0, 0, 8, 0, 0, 7, 9],
]
sudoku = Sudoku(board)

sudoku.solveSudoku()
sudoku.printSudoku()
