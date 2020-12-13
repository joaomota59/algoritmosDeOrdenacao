#Algoritmo responsável por fazer as médias dos testes feitos em C
#Alunos: Francisco Guilherme e João Lucas
import matplotlib.pyplot as plt
def media(lista):
    return sum(lista)/len(lista)
try:
    pergt=int(input("Qual gráfico mostrar? [1-Tempo médio de cada algoritmo 2-Número de comparações]\n->"))
    if pergt!=1 and pergt!=2:
        raise ValueError
except:
    print("Entrada inválida!")
    exit(1)
comprimentos = [100, 500, 1000, 5000, 30000, 80000, 100000, 150000, 200000]
if pergt==1:
    try:
        arq = open('testes.txt', "r")
    except:
        print("Faça primeiro os 3 testes para cada algoritmo em AlgoritmosDeOrdenacao.c !")
        exit(1)
    lines = arq.readlines()
    k=[]
    for i in range(len(lines)):
        if i%2!=0:
            k.append([float(i) for i in lines[i].split(";")[:-1]])
        else:
            k.append(lines[i][:-1])
    arq.close()
    try:
        ask=int(input("Exibir em gráfico em qual condição?[1-Crescente 2-Decrescente 3-Aleatório]\n->"))
        if ask!=1 and ask!=2 and ask!=3:
            raise  ValueError
    except:
        print("Entrada Inválida!")
        exit(1)
    if len([i for i, x in enumerate(k) if x == "BUBBLESORT"])>0:
        indices = [i for i, x in enumerate(k) if x == "BUBBLESORT"]
        auxiliar = []
        for i in range(len(indices)):
            auxiliar.append(k[indices[i] + 1])  # Guarda todos os teste realizados pelo bubble
        w=list(map(media,zip(*[i for i in auxiliar]))) # Faz a média de todos os testes do bubble
        if ask == 1:
            plt.plot(comprimentos, w[:9], label='BUBBLESORT')
        elif ask == 2:
            plt.plot(comprimentos, w[9:18], label='BUBBLESORT')
        elif ask == 3:
            plt.plot(comprimentos, w[18:], label='BUBBLESORT')
    if len([i for i, x in enumerate(k) if x == "INSERTIONSORT"])>0:
        indices = [i for i, x in enumerate(k) if x == "INSERTIONSORT"]
        auxiliar = []
        for i in range(len(indices)):
            auxiliar.append(k[indices[i] + 1])  # Guarda todos os teste realizados pelo Insertion
        w=list(map(media,zip(*[i for i in auxiliar])))  # Faz a média de todos os testes do Insertion
        if ask == 1:
            plt.plot(comprimentos, w[:9], label='INSERTIONSORT')
        elif ask == 2:
            plt.plot(comprimentos, w[9:18], label='INSERTIONSORT')
        elif ask == 3:
            plt.plot(comprimentos, w[18:], label='INSERTIONSORT')
    if len([i for i, x in enumerate(k) if x == "MERGESORT"])>0:
        indices = [i for i, x in enumerate(k) if x == "MERGESORT"]
        auxiliar = []
        for i in range(len(indices)):
            auxiliar.append(k[indices[i] + 1])  # Guarda todos os teste realizados pelo Merge
        w=list(map(media,zip(*[i for i in auxiliar])))  # Faz a média de todos os testes do Merge
        if ask == 1:
            plt.plot(comprimentos, w[:9], label='MERGESORT')
        elif ask == 2:
            plt.plot(comprimentos, w[9:18], label='MERGESORT')
        elif ask == 3:
            plt.plot(comprimentos, w[18:], label='MERGESORT')
    if len([i for i, x in enumerate(k) if x == "HEAPSORT"])>0:
        indices = [i for i, x in enumerate(k) if x == "HEAPSORT"]
        auxiliar = []
        for i in range(len(indices)):
            auxiliar.append(k[indices[i] + 1])  # Guarda todos os teste realizados pelo Heap
        w=list(map(media,zip(*[i for i in auxiliar]))) # Faz a média de todos os testes do Heap
        if ask == 1:
            plt.plot(comprimentos, w[:9], label='HEAPSORT')
        elif ask == 2:
            plt.plot(comprimentos, w[9:18], label='HEAPSORT')
        elif ask == 3:
            plt.plot(comprimentos, w[18:], label='HEAPSORT')
    if len([i for i, x in enumerate(k) if x == "QUICKSORT"])>0:
        indices=[i for i, x in enumerate(k) if x == "QUICKSORT"]
        auxiliar=[]
        for i in range(len(indices)):
            auxiliar.append(k[indices[i]+1])#Guarda todos os teste realizados pelo QuickSort
        w=list(map(media,zip(*[i for i in auxiliar])))#Faz a média de todos os testes do quick
        if ask==1:
            plt.plot(comprimentos,w[:9], label='QUICKSORT')
        elif ask==2:
            plt.plot(comprimentos,w[9:18], label='QUICKSORT')
        elif ask==3:
            plt.plot(comprimentos,w[18:], label='QUICKSORT')


    plt.xlabel('Comprimentos dos vetores')
    plt.ylabel('Tempo médio das execuções (s)')
    if ask==1:
        plt.title("Algortimos de Ordenação em Ordem Crescente")
    elif ask==2:
        plt.title("Algortimos de Ordenação em Ordem Decrescente")
    elif ask==3:
        plt.title("Algortimos de Ordenação em Ordem Aleatória")
    plt.legend()
    plt.show()
else:
    try:
        arq2 = open('comparacoes.txt', "r")
    except:
        print("Faça primeiro os testes para as comparações de cada algoritmo em AlgoritmosDeOrdenacao.c !")
        exit(1)
    lines = arq2.readlines()
    k = []
    for i in range(len(lines)):
        if i % 2 != 0:
            k.append([float(i) for i in lines[i].split(";")[:-1]])
        else:
            k.append(lines[i][:-1])
    arq2.close()
    try:
        ask=int(input("Exibir em gráfico em qual condição?[1-Crescente 2-Decrescente 3-Aleatório]\n->"))
        if ask!=1 and ask!=2 and ask!=3:
            raise  ValueError
    except:
        print("Entrada Inválida!")
        exit(1)
    if len([i for i, x in enumerate(k) if x == "BUBBLESORT"])>0:
        indices = [i for i, x in enumerate(k) if x == "BUBBLESORT"]
        auxiliar = []
        for i in range(len(indices)):
            auxiliar.append(k[indices[i] + 1])  # Guarda todos os teste realizados pelo bubble
        w = auxiliar[0]   # pega os elementos do bubble
        if ask == 1:
            plt.plot(comprimentos, w[:9], label='BUBBLESORT')
        elif ask == 2:
            plt.plot(comprimentos, w[9:18], label='BUBBLESORT')
        elif ask == 3:
            plt.plot(comprimentos, w[18:], label='BUBBLESORT')
    if len([i for i, x in enumerate(k) if x == "INSERTIONSORT"])>0:
        indices = [i for i, x in enumerate(k) if x == "INSERTIONSORT"]
        auxiliar = []
        for i in range(len(indices)):
            auxiliar.append(k[indices[i] + 1])  # Guarda todos os teste realizados pelo insertion
        w = auxiliar[0]   # pega os elementos do insertion
        if ask == 1:
            plt.plot(comprimentos, w[:9], label='INSERTIONSORT')
        elif ask == 2:
            plt.plot(comprimentos, w[9:18], label='INSERTIONSORT')
        elif ask == 3:
            plt.plot(comprimentos, w[18:], label='INSERTIONSORT')
    if len([i for i, x in enumerate(k) if x == "MERGESORT"])>0:
        indices = [i for i, x in enumerate(k) if x == "MERGESORT"]
        auxiliar = []
        for i in range(len(indices)):
            auxiliar.append(k[indices[i] + 1])  # Guarda todos os teste realizados pelo merge
        w = auxiliar[0]   # pega os elementos do merge
        if ask == 1:
            plt.plot(comprimentos, w[:9], label='MERGESORT')
        elif ask == 2:
            plt.plot(comprimentos, w[9:18], label='MERGESORT')
        elif ask == 3:
            plt.plot(comprimentos, w[18:], label='MERGESORT')
    if len([i for i, x in enumerate(k) if x == "HEAPSORT"])>0:
        indices = [i for i, x in enumerate(k) if x == "HEAPSORT"]
        auxiliar = []
        for i in range(len(indices)):
            auxiliar.append(k[indices[i] + 1])  # Guarda todos os teste realizados pelo heap
        w = auxiliar[0]  # pega os elementos do heap
        if ask == 1:
            plt.plot(comprimentos, w[:9], label='HEAPSORT')
        elif ask == 2:
            plt.plot(comprimentos, w[9:18], label='HEAPSORT')
        elif ask == 3:
            plt.plot(comprimentos, w[18:], label='HEAPSORT')
    if len([i for i, x in enumerate(k) if x == "QUICKSORT"])>0:
        indices=[i for i, x in enumerate(k) if x == "QUICKSORT"]
        auxiliar=[]
        for i in range(len(indices)):
            auxiliar.append(k[indices[i]+1])#Guarda todos os teste realizados pelo QuickSort
        w = auxiliar[0] #pega os elementos do quick
        if ask==1:
            plt.plot(comprimentos,w[:9], label='QUICKSORT')
        elif ask==2:
            plt.plot(comprimentos,w[9:18], label='QUICKSORT')
        elif ask==3:
            plt.plot(comprimentos,w[18:], label='QUICKSORT')


    plt.xlabel('Comprimentos dos vetores')
    plt.ylabel('Número de comparações')
    if ask==1:
        plt.title("Algortimos de Ordenação em Ordem Crescente")
    elif ask==2:
        plt.title("Algortimos de Ordenação em Ordem Decrescente")
    elif ask==3:
        plt.title("Algortimos de Ordenação em Ordem Aleatória")
    plt.legend()
    plt.show()
