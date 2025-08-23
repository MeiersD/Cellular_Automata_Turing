from tkinter import *
import RulesBook
import Cells

def create_gui(rules, max_rows: int, max_cols: int, cell_dim: int):
    """Create and run the GUI application"""
    master = Tk()
    master.geometry("600x600")
    master.title("Main Window")

    # Top frame (menu bar area)
    top_frame = Frame(master)
    top_frame.pack(side="top", fill="x")

    # Place your grid inside the top_frame
    for i in range(4):
        for j in range(33):
            if is_part_of_rules(i, j):
                if i == 1:
                    square_color = determine_square_color(j)
                    control_square = Frame(top_frame, bg=square_color, width=18, height=18)
                    control_square.grid(row=i, column=j, sticky="nsew")
                if i == 2:
                    button = Button(top_frame, text="", bg="white", width=2, height=1)
                    button.config(command=lambda b=button: change_color_of_rules_square(b, rules))
                    button.grid(row=i, column=j, sticky="nsew")
            else:
                label = Label(top_frame, text=f"", bg="grey", width=2, height=1)
                label.grid(row=i, column=j, sticky="nsew")

    # Add a row for the start button
    start_button = Button(top_frame, text="Start!", bg="green")
    start_button.grid(row=4, column=0, columnspan=30, sticky="nsew")
    reset_button = Button(top_frame, text="Reset", bg="red")
    reset_button.grid(row=4, column=30, columnspan=3, sticky="nsew")

    # Make cells expand with window
    for i in range(5):
        top_frame.rowconfigure(i, weight=1)
    for j in range(33):
        top_frame.columnconfigure(j, weight=1)

    # Bottom frame for grid
    bottom_frame = Frame(master)
    bottom_frame.pack(side="top", fill="both", expand=True)

    # Store references to squares in a 2D list
    bottom_squares = []
    for i in range(max_rows):
        row = []
        for j in range(max_cols):
            square = Frame(bottom_frame, bg="white", width=cell_dim, height=cell_dim, borderwidth=1, relief="solid")
            square.grid(row=i, column=j, sticky="nsew")
            # Bind click event for first row
            if i == 0:
                square.bind("<Button-1>", lambda event, b=square: change_color_of_cell(b))
            row.append(square)
        bottom_squares.append(row)

    cells = Cells.Cells(bottom_squares, max_cols, max_rows)
    start_button.config(command=lambda: cells.start_simulation(rules.get_rules()))
    reset_button.config(command=lambda: cells.reset_simulation())

    master.mainloop()

# Init the rules for the cellular automata
# The rules can be customized when the user clicks on the corresponding button in the grid
def determine_square_color(col: int) -> str:
    """Determine the color of the square based on its position."""
    list_of_black_squares = [5, 10, 13, 14, 19, 21, 23, 25, 26, 29, 30, 31] #DONT TOUCH
    if col in list_of_black_squares:
        return "black"
    return "white"

# Check if the cell needs to be a button or part of the rule squares
def is_part_of_rules(row: int, col: int) -> bool:
    if row == 0 or row == 3:
        return False
    if row == 1 and col % 4 != 0:
        return True
    if row == 2 and (col-2) % 4 == 0:
        return True
    return False

def change_color_of_rules_square(button: Button, rules: RulesBook.RulesBook):
    """Change the color of the button when clicked."""
    current_color = button.cget("bg")
    new_color = "black" if current_color == "white" else "white"
    button.config(bg=new_color)
    col = (int) ((button.grid_info()["column"]-2)/4)
    #set rules to be 1 if black or 0 if white
    rules.set_rules(1 if new_color == "black" else 0, col)  # Update rules with the new color

def change_color_of_cell(button: Button):
    """Change the color of the cell when clicked."""
    current_color = button.cget("bg")
    new_color = "black" if current_color == "white" else "white"
    button.config(bg=new_color)
    col = button.grid_info()["column"]
    Cells.set_cell(0, col, 1 if new_color == "black" else 0)

def main():
    rules = RulesBook.RulesBook()
    max_rows = 100  # Define the maximum number of rows
    max_cols = 80
    cell_dim = 5  # Define the cell dimension
    create_gui(rules, max_rows, max_cols, cell_dim)  # Start the GUI after other setup

main()




# new_window = Toplevel()  # Create new independent window
# new_window.title("New Window")
# new_window.geometry("250x150")
# Label(new_window, text="This is a new window").pack(pady=20)