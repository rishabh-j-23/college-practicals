class State:
    def __init__(self, jug1, jug2):
        self.jug1 = jug1
        self.jug2 = jug2

    def __eq__(self, other):
        return isinstance(other, State) and self.jug1 == other.jug1 and self.jug2 == other.jug2

    def __hash__(self):
        return hash((self.jug1, self.jug2))

    def __repr__(self):
        return f"State(jug1={self.jug1}, jug2={self.jug2})"

def solve_water_jug_problem(jug1_capacity, jug2_capacity, target):
    visited = set()
    stack = [State(0, 0)]

    while stack:
        current = stack.pop()

        # Normal print to show the current state
        print(f"Current State: Jug1 = {current.jug1}, Jug2 = {current.jug2}")

        if current.jug1 == target or current.jug2 == target:
            print(f"Solution found: ({current.jug1}, {current.jug2})")
            return

        if current in visited:
            continue
        visited.add(current)

        # Fill jug1
        stack.append(State(jug1_capacity, current.jug2))

        # Fill jug2
        stack.append(State(current.jug1, jug2_capacity))

        # Empty jug1
        stack.append(State(0, current.jug2))

        # Empty jug2
        stack.append(State(current.jug1, 0))

        # Pour from jug1 to jug2
        pour_amount = min(current.jug1, jug2_capacity - current.jug2)
        stack.append(State(current.jug1 - pour_amount, current.jug2 + pour_amount))

        # Pour from jug2 to jug1
        pour_amount = min(current.jug2, jug1_capacity - current.jug1)
        stack.append(State(current.jug1 + pour_amount, current.jug2 - pour_amount))

    print("No solution found.")

if __name__ == "__main__":
    jug1_capacity = 4
    jug2_capacity = 3
    target = 2
    solve_water_jug_problem(jug1_capacity, jug2_capacity, target)
