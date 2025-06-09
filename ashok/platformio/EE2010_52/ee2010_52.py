def get_kmap_input():
    print("Enter values for the 2x4 K-map (0 or 1 only):")
    print("Follow this minterm order: m0 m1 m3 m2 m4 m5 m7 m6")
    minterm_order = [0, 1, 3, 2, 4, 5, 7, 6]
    kmap = [0] * 8
    for idx in minterm_order:
        val = int(input(f"Enter value for m{idx}: "))
        kmap[idx] = val
    return kmap

def print_kmap(kmap):
    print("\nK-map (X vs YZ):")
    print("        YZ")
    print("       00  01  11  10")
    print("X=0:  {}   {}   {}   {}".format(kmap[0], kmap[1], kmap[3], kmap[2]))
    print("X=1:  {}   {}   {}   {}".format(kmap[4], kmap[5], kmap[7], kmap[6]))

def get_expression(kmap):
    terms = []
    labels = [
        "X'Y'Z'", "X'Y'Z", "X'YZ'", "X'YZ", 
        "XY'Z'", "XY'Z", "XYZ'", "XYZ"
    ]
    for i in range(8):
        if kmap[i] == 1:
            terms.append(labels[i])
    
    if not terms:
        return "0"
    elif len(terms) == 8:
        return "1"
    else:
        return " + ".join(terms)

def main():
    kmap = get_kmap_input()
    print_kmap(kmap)
    expression = get_expression(kmap)
    print("\nSimplified Boolean Expression (Sum of Minterms):")
    print("F(X, Y, Z) =", expression)

if __name__ == "__main__":
    main()

