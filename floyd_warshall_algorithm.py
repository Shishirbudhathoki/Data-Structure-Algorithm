import math

W = [
    [0, 4, 11],
    [6, 0, 2],
    [3, math.inf, 0]
]

def display(matrix):
    for row in matrix:
        print(row)

def floyd_warshall(weights):
    n = len(W)
    D = {}
    D[0] = [row[:] for row in weights]

    for k in range(1,n+1):
        D[k] = [row[:] for row in D[k-1]]
        for i in range(1, n+1):
            for j in range(1, n+1):
                D[k][i-1][j-1] = min(D[k-1][i-1][j-1],D[k-1][i-1][k-1] + D[k-1][k-1][j-1])
        print(f"\nThe Adjacency matrix when vertex {k} is intermediate vertex.")
        display(D[k])
    return D

ans = floyd_warshall(W)
print(f"\nThe shortest path distances between every pair of vertices which was obtained when vertex {len(W)} is intermediate vertex.")
display(ans[len(W)])

