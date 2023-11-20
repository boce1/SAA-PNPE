def sequence(n):
    if n == 1:
        return 2
    if n == 2:
        return 4
    if n == 3:
        return 6
    
    return 3 * sequence(n - 3) + 4 * sequence(n - 2) - 7 * sequence(n - 1)

print(sequence(5))