def not_gate(a):
    return int(not a)

def and_gate(a, b):
    return a & b

def or_gate(a, b):
    return a | b

def logic_circuit(x, y):
    # NOT gates
    not_x = not_gate(x)
    not_y = not_gate(y)
    
    # AND gates
    a = and_gate(not_x, y)
    b = and_gate(x, not_y)
    
    # OR gate
    z = or_gate(a, b)
    
    return z

def print_truth_table():
    print("X Y | Z")
    print("-------")
    for x in [0, 1]:
        for y in [0, 1]:
            z = logic_circuit(x, y)
            print(f"{x} {y} | {z}")

if __name__ == "__main__":
    print("Truth Table for the Circuit (Q42):")
    print_truth_table()
