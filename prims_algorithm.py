from heapq import *

edges = {
    1: {2: 1, 4: 4},
    2: {1: 1, 3: 3, 5: 3},
    3: {2: 3, 5: 1, 6: 2},
    4: {1: 4, 5: 1},
    5: {2: 3, 3: 1, 4: 1, 6: 4},
    6: {3: 2, 5: 4}
}

def prims_algorithm(graph):
    mst = []
    visited = set()
    min_heap = [(0, 1)]  # (weight, node)

    while min_heap:
        weight, node = heappop(min_heap)
        if node not in visited:
            visited.add(node)
            mst.append((weight, node))
        neighbors = graph.get(node, {})  # Get neighbor_nodes, weights of the edges from the current node
        for neighbor_node in neighbors:
            if neighbor_node not in visited:
                heappush(min_heap, (neighbors[neighbor_node], neighbor_node))
    return mst


mst = prims_algorithm(edges)
print("Edges of the Minimum Spanning Tree using Prim's Algorithm:")
for item in mst:
    print(item)

