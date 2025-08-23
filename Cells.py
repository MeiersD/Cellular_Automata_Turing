from tkinter import *


class Cells:
    def __init__(self, bottom_squares, columns, rows):
        global max_columns, max_rows, active_row, grid
        active_row = 1
        max_columns = columns
        max_rows = rows
        grid = [[0 for _ in range(columns)] for _ in range(rows)]
        self.bottom_squares = bottom_squares

    def get_cell(self, x: int, y: int) -> int:
        global grid
        return grid[x][y]

    def set_square_color(self, row: int, col: int, color: str):
        self.bottom_squares[row][col].config(bg=color)

    #recursivly starts the simulation for the next row and breaks once all 35 rows are processed
    #active row starts as 1 because the 0th row is used for the initial state
    def start_simulation(self, rules: list[int]):
        global active_row, max_rows,max_columns
        #base case:
        if active_row >= max_rows:
            return
        next_row = []
        for col in range(max_columns):
            next_cell = self.do_switch_statement(col, rules)
            if next_cell == 1:
                self.set_square_color(active_row, col, "black")
            next_row.append(next_cell)
        #append next_row to the grid
        grid[active_row] = next_row
        active_row += 1
        self.start_simulation(rules)

    def do_switch_statement(self, col: int, rules) -> int:
        global active_row, max_columns
        #do bounds checking
        if col == 0:
            left_progenitor = 100*self.get_cell(active_row-1, -1)
        else:
            left_progenitor = 100*self.get_cell(active_row-1, col-1)
        if col == max_columns - 1:
            right_progenitor = self.get_cell(active_row-1, 0)
        else:
            right_progenitor = self.get_cell(active_row-1, col+1)
        center_progenitor = 10*self.get_cell(active_row-1, col)
        rule_case = left_progenitor + center_progenitor + right_progenitor
        match rule_case:
            case 0:
                return rules[0]
            case 1:
                return rules[1]
            case 10:
                return rules[2]
            case 11:
                return rules[3]
            case 100:
                return rules[4]
            case 101:
                return rules[5]
            case 110:
                return rules[6]
            case 111:
                return rules[7]
        return "this will throw an error"
    
    def reset_simulation(self):
        global active_row, grid
        active_row = 1
        grid = [[0 for _ in range(max_columns)] for _ in range(max_rows)]
        for row in self.bottom_squares:
            for square in row:
                square.config(bg="white")

def set_cell(x: int, y: int, state: int):
    global grid
    grid[x][y] = state