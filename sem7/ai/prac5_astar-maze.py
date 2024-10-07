import heapq

class MazeSolver:
    def __init__(self, maze, start, end):
        self.maze = maze
        self.start = start
        self.end = end
        self.rows = len(maze)
        self.cols = len(maze[0])
        self.open_list = []
        self.closed_list = set()
        self.parent_dict = {}

    def heuristic(self, curr_pos):
        # Manhattan distance heuristic
        return abs(curr_pos[0] - self.end[0]) + abs(curr_pos[1] - self.end[1])

    def is_goal(self, position):
        # Check if the current position is the goal
        return position == self.end

    def get_neighbors(self, position):
        # Get possible neighbors (up, down, left, right)
        neighbors = []
        directions = [(-1, 0), (1, 0), (0, -1), (0, 1)]  # Up, down, left, right
        x, y = position

        for dx, dy in directions:
            nx, ny = x + dx, y + dy
            if 0 <= nx < self.rows and 0 <= ny < self.cols:
                if self.maze[nx][ny] == 0:  # Only add walkable positions (0)
                    neighbors.append((nx, ny))
        
        return neighbors

    def solve(self):
        # Initialize the open list with the start position
        start_heuristic = self.heuristic(self.start)
        heapq.heappush(self.open_list, (start_heuristic, self.start, 0))  # (f_score, position, g_score)
        self.parent_dict[self.start] = None

        while self.open_list:
            f_score, current_position, g_score = heapq.heappop(self.open_list)

            # If we reach the goal, reconstruct and print the path
            if self.is_goal(current_position):
                solution_path = []
                while current_position is not None:
                    solution_path.append(current_position)
                    current_position = self.parent_dict[current_position]
                solution_path.reverse()

                for i, position in enumerate(solution_path):
                    print(f"Step {i}: Position {position}")
                return

            # Add the current position to the closed list
            self.closed_list.add(current_position)

            # Explore the neighbors
            for neighbor in self.get_neighbors(current_position):
                if neighbor in self.closed_list:
                    continue

                # Calculate new g_score and f_score for the neighbor
                tentative_g_score = g_score + 1
                h_score = self.heuristic(neighbor)
                tentative_f_score = tentative_g_score + h_score

                # Add the neighbor to the open list if not already visited
                if neighbor not in self.parent_dict or tentative_g_score < self.parent_dict[neighbor][1]:
                    self.parent_dict[neighbor] = current_position
                    heapq.heappush(self.open_list, (tentative_f_score, neighbor, tentative_g_score))

        print("No solution found.")

# Example usage:
start = (0, 0)
end = (4, 4)

maze = [
    [0, 1, 1, 1, 0],
    [0, 0, 0, 1, 0],
    [1, 1, 0, 1, 0],
    [0, 0, 0, 0, 0],
    [1, 1, 1, 1, 0]
]

solver = MazeSolver(maze, start, end)
solver.solve()
