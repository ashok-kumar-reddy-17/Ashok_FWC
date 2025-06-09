print("For any set of inputs, A and B ,the given circuit give same output.Q,expect one.Which one is it?")


print("(A)");
def XOR(a, b):
    return a ^ b
def NOT(z):
    return 1 - z
def AND(x, y):
    return x & y
def OR(p,q):
    return p or q;
print("A B | A⊕B | B' | (A⊕B)∧B'")
print("--------------------------")
for a in [0, 1]:
    for b in [0, 1]:
        xor = XOR(a, b)
        b_bar = NOT(b)
        result = AND(xor, b_bar)
        print(f"{a} {b} |  {xor}  |  {b_bar} |     {result}")

print("(B)");
print("A B| B'| A^B'");
print("-----------------------");
for a in [0,1]:
    for b in [0,1]:
        b_bar=NOT(b);
        result=AND(a,b_bar)
        print(f"{a} {b} |{b_bar} | {result}")


print("(C)")
print("A B| B'|A^b'|B'^A|B'^A^B | A^B'+B'^A^B")
print("-------------------------")
for a in [0,1]:
    for b in [0,1]:
        b_bar=NOT(b);
        ans=AND(a,b_bar);
        ans1=AND(ans,b);
        result=OR(ans,ans1);
        print(f"{a} {b} | {b_bar}| {ans}|{ans1}| {result}");



print("D");
print("A B|A'|A'+B");
print("---------------------");
for a in [0,1]:
    for b in [0,1]:
        a_bar=NOT(a);
        result=OR(a_bar,b);
        print(f"{a} {b} | {a_bar}| {result}");
