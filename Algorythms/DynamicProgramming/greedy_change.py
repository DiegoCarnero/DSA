den = [10000, 5000, 1000, 500, 100, 50, 25, 10, 5, 1]

def get_change(N):
    i = 0
    change = []
    while i < len(den):
        if den[i] > N:
            i += 1
            continue
        
        change.append(den[i])
        N -= den[i]

    return change

print(get_change(4224))