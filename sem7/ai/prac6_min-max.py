import math

# Define the players
PLAYER = "X"  # Human
AI = "O"  # Computer


# Function to print the Tic-Tac-Toe board
def print_board(board):
    for row in board:
        print(" | ".join(row))
        print("-" * 9)


# Function to check if there are moves left on the board
def is_moves_left(board):
    for row in board:
        if "_" in row:
            return True
    return False


# Function to evaluate the board and return score
def evaluate(board):
    # Check rows for victory
    for row in board:
        if row[0] == row[1] == row[2]:
            if row[0] == AI:
                return 10
            elif row[0] == PLAYER:
                return -10

    # Check columns for victory
    for col in range(3):
        if board[0][col] == board[1][col] == board[2][col]:
            if board[0][col] == AI:
                return 10
            elif board[0][col] == PLAYER:
                return -10

    # Check diagonals for victory
    if board[0][0] == board[1][1] == board[2][2]:
        if board[0][0] == AI:
            return 10
        elif board[0][0] == PLAYER:
            return -10

    if board[0][2] == board[1][1] == board[2][0]:
        if board[0][2] == AI:
            return 10
        elif board[0][2] == PLAYER:
            return -10

    # If no one has won, return 0
    return 0


# Min-Max algorithm function
def minimax(board, depth, is_maximizing):
    score = evaluate(board)

    # If the AI has won, return the score minus depth (to prefer shorter paths)
    if score == 10:
        return score - depth

    # If the player has won, return the score plus depth
    if score == -10:
        return score + depth

    # If there are no moves left, it's a draw
    if not is_moves_left(board):
        return 0

    # Maximizing move for AI
    if is_maximizing:
        best = -math.inf

        for i in range(3):
            for j in range(3):
                if board[i][j] == "_":
                    board[i][j] = AI
                    best = max(best, minimax(board, depth + 1, False))
                    board[i][j] = "_"
        return best

    # Minimizing move for the player
    else:
        best = math.inf

        for i in range(3):
            for j in range(3):
                if board[i][j] == "_":
                    board[i][j] = PLAYER
                    best = min(best, minimax(board, depth + 1, True))
                    board[i][j] = "_"
        return best


# Function to find the best move for AI
def find_best_move(board):
    best_val = -math.inf
    best_move = (-1, -1)

    for i in range(3):
        for j in range(3):
            if board[i][j] == "_":
                board[i][j] = AI
                move_val = minimax(board, 0, False)
                board[i][j] = "_"

                if move_val > best_val:
                    best_move = (i, j)
                    best_val = move_val

    return best_move


# Function to check if the game has a winner or is a draw
def check_winner(board):
    score = evaluate(board)
    if score == 10:
        return "AI wins!"
    elif score == -10:
        return "Player wins!"
    elif not is_moves_left(board):
        return "It's a draw!"
    return None


# Main function to play the game
def play_game():
    board = [["_", "_", "_"], ["_", "_", "_"], ["_", "_", "_"]]
    print("Initial Board:")
    print_board(board)

    while True:
        # Player's turn
        print("Your turn (X): ")
        while True:
            try:
                row, col = map(
                    int, input("Enter row and column (0, 1, or 2): ").split()
                )
                if board[row][col] == "_":
                    board[row][col] = PLAYER
                    break
                else:
                    print("Cell is already occupied! Try again.")
            except (ValueError, IndexError):
                print("Invalid input! Enter two numbers between 0 and 2.")

        print_board(board)

        # Check if player has won or it's a draw
        result = check_winner(board)
        if result:
            print(result)
            break

        # AI's turn
        print("AI's turn (O): ")
        ai_move = find_best_move(board)
        board[ai_move[0]][ai_move[1]] = AI
        print_board(board)

        # Check if AI has won or it's a draw
        result = check_winner(board)
        if result:
            print(result)
            break


# Start the game
play_game()
