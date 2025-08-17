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
print("All vertex are : ",end=" ")
for vertex in G.keys():
    print(vertex,end=' ')
print("\n")
print(G['A'])

for key, value in G.items():
    print(key, ":", value)