import time


def print_board(board):
    for row in board:
        print(" ".join("Q" if col else "." for col in row))
    print()


def is_safe(board, row, col, n):
    # Check left side of the row
    for i in range(col):
        if board[row][i] == 1:
            return False

    # Check upper diagonal on left side
    for i, j in zip(range(row, -1, -1), range(col, -1, -1)):
        if board[i][j] == 1:
            return False

    # Check lower diagonal on left side
    for i, j in zip(range(row, n), range(col, -1, -1)):
        if board[i][j] == 1:
            return False

    return True


def solve_n_queens_util(board, col, n):
    # Base case: If all queens are placed, print the final solution and return True
    if col >= n:
        print("Solution found:")
        print_board(board)
        return True

    # Try placing queen in all rows one by one
    for i in range(n):
        if is_safe(board, i, col, n):
            # Place queen and print board
            board[i][col] = 1
            print(f"Placing queen at ({i}, {col}):")
            print_board(board)
            time.sleep(0.5)  # Pause to view each step

            # Recur to place the rest of the queens
            if solve_n_queens_util(board, col + 1, n):
                return True

            # If placing queen in (i, col) doesn't lead to a solution, remove it
            board[i][col] = 0  # Backtrack
            print(f"Removing queen from ({i}, {col}):")
            print_board(board)
            # time.sleep(0.5)  # Pause to view each backtrack step

    return False


def solve_n_queens(n=8):
    board = [[0 for _ in range(n)] for _ in range(n)]
    if not solve_n_queens_util(board, 0, n):
        print("Solution does not exist")


# Run for 8 queens
solve_n_queens(8)
