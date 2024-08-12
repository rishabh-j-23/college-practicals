import random

class PuzzleState:
    def __init__(self, board, goal, empty_tile_pos=None, moves=0):
        self.board = board
        self.goal = goal
        self.size = len(board)
        self.empty_tile_pos = empty_tile_pos if empty_tile_pos else self.find_empty_tile()
        self.moves = moves

    def find_empty_tile(self):
        for i in range(self.size):
            for j in range(self.size):
                if self.board[i][j] == 0:
                    return (i, j)
        return None

    def is_goal(self):
        return self.board == self.goal

    def get_neighbors(self):
        neighbors = []
        x, y = self.empty_tile_pos
        for dx, dy in [(-1, 0), (1, 0), (0, -1), (0, 1)]:
            nx, ny = x + dx, y + dy
            if 0 <= nx < self.size and 0 <= ny < self.size:
                new_board = [row[:] for row in self.board]
                new_board[x][y], new_board[nx][ny] = new_board[nx][ny], new_board[x][y]
                neighbors.append(PuzzleState(new_board, self.goal, (nx, ny), self.moves + 1))
        return neighbors

    def heuristic(self):
        # Use the misplaced tile heuristic
        misplaced_tiles = 0
        for i in range(self.size):
            for j in range(self.size):
                if self.board[i][j] != self.goal[i][j]:
                    misplaced_tiles += 1
        return misplaced_tiles

    def __str__(self):
        return '\n'.join([' '.join(map(str, row)) for row in self.board])

def hill_climbing(initial_state):
    current_state = initial_state
    while not current_state.is_goal():
        neighbors = current_state.get_neighbors()
        if not neighbors:
            break

        next_state = min(neighbors, key=lambda state: state.heuristic())

        # If no better neighbors, stop
        if next_state.heuristic() >= current_state.heuristic():
            break

        current_state = next_state
        print(f"Move {current_state.moves}:\n{current_state}\nh={current_state.heuristic()}\n")
        
    return current_state

# Define the initial and goal states
initial_board = [
    [1, 2, 3],
    [0, 4, 5],
    [7, 8, 6]
]

goal_board = [
    [1, 2, 3],
    [4, 5, 6],
    [7, 8, 0]
]

initial_state = PuzzleState(initial_board, goal_board)

solution = hill_climbing(initial_state)

if solution.is_goal():
    print(f"Solved in {solution.moves} moves:")
    print(solution)
else:
    print("No solution found.")
