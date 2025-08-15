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
def DFT(G,start):
    stack=[]
    visited=[]
    stack.append(start)
    while(stack):
        popped_vertex = stack.pop()
        visited.append(popped_vertex)
        for adjacent in G[popped_vertex]:
            if adjacent not in stack and adjacent not in visited:
                stack.append(adjacent)
    return visited
start = 'A'
Depth_first_traverse_sequence = DFT(G,start)
print(Depth_first_traverse_sequence)

