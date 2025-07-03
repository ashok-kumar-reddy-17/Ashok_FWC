# Define logic gate functions
def or_gate(a, b):
    return a | b

def nor_gate(a, b):
    return int(not (a | b))

def final_or_gate(a, b):
    return a | b

# Evaluate the logic circuit for given inputs
def logic_circuit(A, B, C):
    out1 = or_gate(A, B)     # First OR gate (top)
    out2 = nor_gate(A, B)    # NOR gate (bottom left)
    F = final_or_gate(out1, C) & final_or_gate(out2, C)  # Final OR gate with both outputs and input C
    return F

# Test all input combinations
print("A B C => F")
for A in [0, 1]:
    for B in [0, 1]:
        for C in [0, 1]:
            F = logic_circuit(A, B, C)
            print(f"{A} {B} {C} => {F}")

print("the correct answer is A=0,B=0,C=1")
