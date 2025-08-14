G = {
    'A':['B', 'C'],
    'B':['A', 'D', 'E'],
    'C':['A', 'F'],
    'D':['B', 'G'],
    'E':['B', 'H'],
    'F':['C'],
    'G':['D'],
    'H':['E']
}
def BFT(G,start):
    queue=[]
    visited=[]
    queue.append(start)
    while(queue):
        out_vertex = queue.pop(0)
        visited.append(out_vertex)
        for adjacent in G[out_vertex]:
            if adjacent not in queue and adjacent not in visited:
                queue.append(adjacent)
    return visited
start = 'A'
Breadth_first_traverse_sequence = BFT(G,start)
print(Breadth_first_traverse_sequence)

