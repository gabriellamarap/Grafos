import networkx as nx

'''
    Autor: Gabriella Mara
    Version: 1.0
'''

g = nx.DiGraph() #Cria um dígrafo
while True:
    try:
        names = input().split()         #Nomes das pessoas
        g.add_nodes_from(names)         #Cria nodes com os nomes
        g.add_edge(names[0],names[1])   #Cria edge entre as duas pessoas
    except EOFError:
        break 
print(len(list(nx.simple_cycles(g)))) #Printa a quantidade de ciclos do grafo