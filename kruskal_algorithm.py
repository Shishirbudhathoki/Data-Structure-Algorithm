def find_root(graph, node): 
    if graph[node] < 0:
        return node
    else:
        graph[node] = find_root(graph, graph[node])
        return graph[node]

def union(graph, src, dst, answer):
    src_root = find_root(graph, src) 
    dst_root = find_root(graph, dst)
    if src_root != dst_root:                           #check their roots are different
        if graph[src_root] < graph[dst_root]:          # if src_root contains more children
            graph[src_root] += graph[dst_root]
            graph[dst_root] = src_root
        else:
            graph[dst_root] += graph[src_root]
            graph[src_root] = dst_root
        answer.append((src, dst))


edges = [[1,2,1],[1,4,4],[2,3,3],[2,5,3],[3,5,1],[3,6,2],[4,5,1],[5,6,4]]
n=6
MST=[]
sorted_edges = sorted(edges, key=lambda x: x[2])

print("The sorted edges are :n")
for edge in sorted_edges:
    print(edge)
    
graph = []          # to find the root node(-ve) or parent node’s index, of each set in the Disjoint Set Union (DSU) structure.

for i in range(n+1):
    graph.append(-1)      #graph = [-1] * (n + 1) since edges st from 1 so n+1
for src,dst,wt in sorted_edges:
    union(graph,src,dst,MST)
print("\nEdges of the Minimum Spanning Tree:")
for item in MST:
    print(item)