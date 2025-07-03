def NOT(a):
    return 1-a
    
#first logic gate
def first(a, b):
    return NOT(a | b)
    
#second
def second(a, b):
    return NOT(a & b)
    
#third
def third(a, b):
    return a ^ b

#fourth
def fourth(a, b):
    return NOT((a^ b))
    
#fifth
def fifth(a, b):
    return (a ^ NOT(b))
    
#sixth
def sixth(a,b):
    return NOT(a) | NOT(b)
    
    
#seventh
def seventh(a,b):
    return (NOT (NOT(a) ^ b))


#eighth
def eighth(a, b):
    return (NOT(a) & NOT(b))

# Dictionary of gates
gates = {
    '1st': first,
    '2nd': second,
    '3rd': third,
    '4th': fourth,
    '5th': fifth,
    '6th': sixth,
    '7th': seventh,
    '8th': eighth
}

# Generate all input combinations
inputs = [(0, 0), (0, 1), (1, 0), (1, 1)]

# Store truth tables
truth_tables = {}

print("Truth Tables for Logic Gates:\n")

for name, func in gates.items():
    table = []
    print(f"{name} Gate")
    print("A B | OUT")
    for a, b in inputs:
        out = func(a, b)
        table.append(out)
        print(f"{a} {b} |  {out}")
    truth_tables[name] = table
    print()

# Compare truth tables
print("Matching Gate Outputs:\n")

matched = set()
for g1 in truth_tables:
    for g2 in truth_tables:
        if g1 != g2 and truth_tables[g1] == truth_tables[g2]:
            pair = tuple(sorted((g1, g2)))
            if pair not in matched:
                print(f"{g1} == {g2}")
                matched.add(pair)
