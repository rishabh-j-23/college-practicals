import heapq

class AStar:
    def __init__(self, initial_state):
        self.initial_state = initial_state
        self.goal_state = [[1, 2, 3], [4, 5, 6], [7, 8, 0]]
        self.open_list = []
        self.closed_list = set()
        self.parent_dict = {}

    def heuristic(self, state):
<<<<<<< HEAD
        # Manhattan distance heuristic
        distance = 0
        for i in range(3):
            for j in range(3):
                if state[i][j] != 0:
                    goal_i, goal_j = divmod(state[i][j] - 1, 3)
                    distance += abs(i - goal_i) + abs(j - goal_j)
        return distance
=======
        misplace = 0
        for i in range(3):
            for j in range(3):
                if state[i][j] != self.goal_state[i][j]:
                    misplace += 1
        return misplace
>>>>>>> b698fc2c8362dc1e927f7a025cc541752b0953ea

    def is_goal(self, state):
        return state == self.goal_state

    def get_neighbors(self, state):
        neighbors = []
        for i in range(3):
            for j in range(3):
                if state[i][j] == 0:
                    # Up
                    if i > 0:
                        new_state = [row[:] for row in state]
                        new_state[i][j] = new_state[i-1][j]
                        new_state[i-1][j] = 0
                        neighbors.append(new_state)
                    # Down
                    if i < 2:
                        new_state = [row[:] for row in state]
                        new_state[i][j] = new_state[i+1][j]
                        new_state[i+1][j] = 0
                        neighbors.append(new_state)
                    # Left
                    if j > 0:
                        new_state = [row[:] for row in state]
                        new_state[i][j] = new_state[i][j-1]
                        new_state[i][j-1] = 0
                        neighbors.append(new_state)
                    # Right
                    if j < 2:
                        new_state = [row[:] for row in state]
                        new_state[i][j] = new_state[i][j+1]
                        new_state[i][j+1] = 0
                        neighbors.append(new_state)
        return neighbors

    def solve(self):
        self.open_list.append((0, self.initial_state, None))
        while self.open_list:
<<<<<<< HEAD
            f_score, current_state, parent = heapq.heappop(self.open_list)
=======
            _, current_state, parent = heapq.heappop(self.open_list)
>>>>>>> b698fc2c8362dc1e927f7a025cc541752b0953ea
            if self.is_goal(current_state):
                solution_path = []
                while parent is not None:
                    solution_path.append(current_state)
                    current_state, parent = self.parent_dict[parent]
                solution_path.append(self.initial_state)
                solution_path.reverse()
                for i, state in enumerate(solution_path):
                    print(f"Step {i}:")
                    for row in state:
                        print(row)
                    print()
                return
            self.closed_list.add(tuple(map(tuple, current_state)))
            for neighbor in self.get_neighbors(current_state):
                if tuple(map(tuple, neighbor)) not in self.closed_list:
<<<<<<< HEAD
                    g_score = f_score + 1
                    h_score = self.heuristic(neighbor)
                    f_score = g_score + h_score
                    self.parent_dict[tuple(map(tuple, neighbor))] = (current_state, parent)
                    heapq.heappush(self.open_list, (f_score, neighbor, tuple(map(tuple, neighbor))))
        print("No solution found")

=======
                    self.parent_dict[tuple(map(tuple, neighbor))] = (current_state, parent)
                    heapq.heappush(self.open_list, (self.heuristic(neighbor) + len(self.open_list), neighbor, tuple(map(tuple, neighbor))))
        print("No solution found")

# Example usage:
>>>>>>> b698fc2c8362dc1e927f7a025cc541752b0953ea
initial_state = [[1, 2, 3], [4, 0, 6], [7, 5, 8]]
astar = AStar(initial_state)
astar.solve()