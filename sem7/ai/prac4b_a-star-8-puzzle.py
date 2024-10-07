import heapq

class PuzzleState:
    def __init__(self, board, goal, moves=0, previous=None):
        self.board = board
        self.goal = goal
        self.moves = moves
        self.previous = previous  # Store the previous state to reconstruct the path
        self.heuristic = self.calculate_misplaced_tiles() + moves  # h(n) + g(n)

    def __lt__(self, other):
        # Priority for the priority queue (heapq), using heuristic (f(n) = g(n) + h(n))
        return self.heuristic < other.heuristic

    def calculate_misplaced_tiles(self):
        # Count the number of misplaced tiles as the heuristic
        misplaced = 0
        for i in range(3):
            for j in range(3):
                if self.board[i][j] != 0 and self.board[i][j] != self.goal[i][j]:
                    misplaced += 1
        return misplaced

    def get_neighbors(self):
        # Generate the next possible states (neighbors)
        neighbors = []
        x, y = next((i, j) for i, row in enumerate(self.board) for j, val in enumerate(row) if val == 0)
        directions = [(-1, 0), (1, 0), (0, -1), (0, 1)]  # Up, down, left, right

        for dx, dy in directions:
            nx, ny = x + dx, y + dy
            if 0 <= nx < 3 and 0 <= ny < 3:
                new_board = [row[:] for row in self.board]
                new_board[x][y], new_board[nx][ny] = new_board[nx][ny], new_board[x][y]
                neighbors.append(PuzzleState(new_board, self.goal, self.moves + 1, self))
        
        return neighbors

    def is_goal(self):
        return self.board == self.goal

    def __str__(self):
        return '\n'.join([' '.join(map(str, row)) for row in self.board])

    def print_path(self):
        # Recursively print the path from the start state to the current state
        if self.previous:
            self.previous.print_path()
        print(f"Move {self.moves}:\n{self}\n")

def a_star_search(start, goal):
    open_set = []
    heapq.heappush(open_set, PuzzleState(start, goal))
    visited = set()
    visited.add(str(start))

    while open_set:
        current_state = heapq.heappop(open_set)

        # If the goal state is reached, print the solution path
        if current_state.is_goal():
            print(f"Solution found in {current_state.moves} moves:\n")
            current_state.print_path()
            return current_state.moves

        # Explore neighbors
        for neighbor in current_state.get_neighbors():
            board_str = str(neighbor.board)
            if board_str not in visited:
                heapq.heappush(open_set, neighbor)
                visited.add(board_str)

    print("No solution found.")
    return -1

# Example usage:
start_state = [
    [2, 8, 3],
    [1, 6, 4],
    [7, 0, 5]
]

goal_state = [
    [3, 2, 1],
    [8, 0, 4],
    [7, 5, 6]
]

a_star_search(start_state, goal_state)
