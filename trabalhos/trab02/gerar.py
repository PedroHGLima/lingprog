import random as rd

def main():
    f = open('arestas.csv', 'w')
    f.write('origem,destino,peso\n')
    ids = 'ABCDEFGHIJKLMNOPQRSTUVXWYZ'
    n_arestas = 100
    arestas = set()

    origem = destino = 'A'
    
    for i in range(n_arestas):
        origem = rd.choice(ids)
        destino = rd.choice(ids)
        while (origem == destino) or ((origem, destino) in arestas):
            origem = rd.choice(ids)
            destino = rd.choice(ids)
        peso = rd.randint(1, 20)
        f.write(f'{origem},{destino},{peso}\n')
        arestas.add((origem, destino))

    f.close()


if __name__ == '__main__':
    main()