# Define logic gate functions
def not_gate(x):
    return int(not x)

def and_gate(x, y):
    return x & y

# Define the 4x1 MUX logic based on inputs A, B and inputs C, D
def mux_4x1(A, B, C, D):
    # I0 = C
    # I1 = D
    # I2 = NOT C
    # I3 = C AND D
    I0 = C
    I1 = D
    I2 = not_gate(C)
    I3 = and_gate(not_gate(C), not_gate(D))
    
    # Select line value (0 to 3)
    select = (A << 1) | B

    # MUX output
    inputs = [I0, I1, I2, I3]
    return inputs[select]

# Collect and display minterms where output is 1
minterms = []

print("A B C D => F")
for A in [0, 1]:
    for B in [0, 1]:
        for C in [0, 1]:
            for D in [0, 1]:
                F = mux_4x1(A, B, C, D)
                # Calculate the minterm number as ABCD binary to decimal
                index = (A << 3) | (B << 2) | (C << 1) | D
                print(f"{A} {B} {C} {D} => {F}")
                if F == 1:
                    minterms.append(index)

# Print final result
print("\nMinterms where F = 1:")
print(f"F = Σm{tuple(minterms)}")


