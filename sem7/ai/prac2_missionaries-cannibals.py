from collections import deque

class State:
    def __init__(self, missionaries, cannibals, boat, parent=None):
        self.missionaries = missionaries
        self.cannibals = cannibals
        self.boat = boat
        self.parent = parent

    def is_valid(self):
        return (0 <= self.missionaries <= 3 and 0 <= self.cannibals <= 3
                and (self.missionaries == 0 or self.missionaries >= self.cannibals)
                and (self.missionaries == 3 or self.missionaries <= self.cannibals))

    def is_goal(self):
        return self.missionaries == 0 and self.cannibals == 0 and self.boat == 0

    def get_next_states(self):
        next_states = []
        moves = [(1, 0), (2, 0), (0, 1), (0, 2), (1, 1)]
        for m, c in moves:
            new_missionaries = self.missionaries - m * self.boat
            new_cannibals = self.cannibals - c * self.boat
            new_boat = 1 - self.boat
            new_state = State(new_missionaries, new_cannibals, new_boat, self)
            if new_state.is_valid():
                next_states.append(new_state)
        return next_states

    def __eq__(self, other):
        return (self.missionaries == other.missionaries and
                self.cannibals == other.cannibals and
                self.boat == other.boat)

    def __hash__(self):
        return hash((self.missionaries, self.cannibals, self.boat))

def solve(initial_state):
    queue = deque([initial_state])
    visited = set([initial_state])

    while queue:
        current = queue.popleft()

        if current.is_goal():
            print_solution(current)
            return

        for next_state in current.get_next_states():
            if next_state not in visited:
                queue.append(next_state)
                visited.add(next_state)

    print("No solution found.")

def print_solution(state):
    if state is None:
        return
    print_solution(state.parent)
    print(f"Missionaries: {state.missionaries}, Cannibals: {state.cannibals}, Boat: {'Left' if state.boat == 1 else 'Right'}")

if __name__ == "__main__":
    initial_state = State(3, 3, 1)
    solve(initial_state)
