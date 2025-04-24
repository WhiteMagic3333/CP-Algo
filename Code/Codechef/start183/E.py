N = 3
M = 2
def solve():
    results = []
    for N, M in test_cases:
        K = N - 1
        T = N * (N - 1) // 2
        Z = T - M
        min_W = max(0, K - Z)
        max_W = min(K, M)
        if min_W > max_W:
            results.append(0)
        else:
            count = max_W - min_W + 1
            total = (min_W + max_W) * count // 2
            results.append(total)
    return results

# Reading input
T = int(input())
test_cases = [tuple(map(int, input().split())) for _ in range(T)]
for res in solve(test_cases):
    print(res)
