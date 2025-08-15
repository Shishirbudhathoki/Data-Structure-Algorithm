import math
from queue import PriorityQueue
G = {
    # 's':{'t':10,'y':5},
    # 't':{'x':1,'y':2},
    # 'x':{'z':4},
    # 'y':{'x':9,'t':3,'z':2},
    # 'z':{'s':7,'x':6}
    'A':{'B':3,'C':1},
    'B':{'A':3,'C':7,'D':5,'E':1},
    'C':{'A':1,'D':2,'B':7},
    'D':{'B':5,'C':2,'E':7},
    'E':{'B':1,'D':7}
}
def DJ(G,s):
    cost = {}
    prev = {}
    for vertex in G.keys():
        cost[vertex]=math.inf
        prev[vertex]=" "
    cost[s]=0
    visited = list()
    PQ = PriorityQueue()
    for vertex in G.keys():
        PQ.put((cost[vertex],vertex))
    while(len(visited)!= len(G.keys())):
        _,currentVertex = PQ.get()
        visited.append(currentVertex)
        for chimeki in G[currentVertex].keys():
            if chimeki not in visited:
                if cost[chimeki] > cost[currentVertex]+G[currentVertex][chimeki]:
                    cost[chimeki]=cost[currentVertex]+G[currentVertex][chimeki]
                    prev[chimeki]=currentVertex
                    PQ.put((cost[chimeki],chimeki))
    return cost,prev
def reconstruct_path(prev,vertex):
    path=vertex
    while prev[vertex]!=" ":
        path=prev[vertex]+'->'+path
        vertex = prev[vertex]
    return path
source='C'
cost,prev=DJ(G,source)
for vertex in G.keys():
    print(f"From {source} to {vertex},path is {reconstruct_path(prev,vertex)} with cost {cost[vertex]}.")
print(cost)
print(prev)

