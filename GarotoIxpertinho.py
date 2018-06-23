import networkx as nx

'''
    Autor: Gabriella Mara
    Version: 1.0
'''

QCT = input().split()
while not (QCT.count('0') == 3):    
    Q = int(QCT[0])     #Quantidade de quarteirões/vértices
    C = int(QCT[1])     #Quantidade de arestas
    T = float(QCT[2])   #Fôlego
    g = nx.Graph()

    for i in range(0,C):
        XYZ = input().split()
        X = int(XYZ[0])     #Vértice de origem
        Y = int(XYZ[1])     #Vértice de destino
        Z = float(XYZ[2])   #Tempo para ir de um ao outro
        g.add_nodes_from([X, Y])
        g.add_edge(X, Y, time = Z) 

    minTree = nx.minimum_spanning_tree(g,'time')    #Árvore geradora mínima do grafo

    timeTotal = 0 
    nSum = 0
    for x, y, time in minTree.edges.data('time'):
        if(time > T):       #Se o tempo entre os dois vértices for maior que o tempo que ele tem de fôlego
            time += 2.0     #Somar os 2 minutos
            nSum += 1       #Acrescentar uma pausa
        timeTotal += time   #Acrescentar, ao tempo total, o tempo de caminhada entre os dois vértices
    print("%.2f" %timeTotal, nSum)

    QCT = input().split()