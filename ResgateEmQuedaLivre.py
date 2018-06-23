import networkx as nx 
import math

'''
    Autor: Gabriella Mara
    Version: 1.0
'''

#Calcula a distância entre dois pontos
def distAB(xA,yA,xB,yB):
    distAB = math.sqrt(((xA-xB)**2) + ((yA-yB)**2))
    return distAB

C = int(input()) #Número de casos de teste
for i in range(0,C):
    n = int(input()) #Quantidade de pessoas/vértices
    g = nx.complete_graph(n) #Gera um Kn

    for j in range(0,n):
        xj,yj = map(int,input().split()) #Coordenadas (x,y) do vértice (j)
        g.node[j]['x'] = xj
        g.node[j]['y'] = yj
    
    for j in range(0,n):
        for k in range(0,n):
            if (((j,k) not in g.edges(data='weight')) & (j != k)):
                xA = g.node[j]['x']
                yA = g.node[j]['y']
                xB = g.node[k]['x']
                yB = g.node[k]['y']
                g[j][k]['weight'] = distAB(xA,yA,xB,yB) #Cria uma aresta entre os vértices (j,k) com peso igual a distância entre os dois pontos
    
    minTree = nx.minimum_spanning_tree(g,'weight') #Árvore geradora mínima do grafo
   
    minPath = 0.0
    #Somar o caminho total da AGM
    for x, y, weight in minTree.edges.data('weight'):
        minPath += weight

    print("%.2f" % (minPath/100))
    