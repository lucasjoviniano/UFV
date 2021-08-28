from Posicao import Posicao
from AEstrela import AEstrela
from QuebraCabeca import QuebraCabeca
from QuebraCabecaImp import QuebraCabecaImp
import copy
from operator import itemgetter


class AEstrelaImp(AEstrela):
    # Pega os vizinhos do Quebra Cabeça atual, movendo o espaço vazio para todas as direções possíveis
    # Retorna uma lista de tuplas no formato (QuebraCabeça, Movimentos)
    def get_neighbors(self, qc, pos):
        movements = qc.getMovePossiveis()
        blank = qc.getPosVazio()
        options = []
        for i in movements:
            shallow = copy.deepcopy(qc)
            positions = pos.copy()
            shallow.move(blank.linha, blank.coluna, i.linha, i.coluna)
            positions.append(Posicao(i.linha, i.coluna))
            options.append((shallow, positions))
        return options

    def getSolucao(self, qc):
        # Insere o elemento inicial na lista
        todo = [(qc.getValor(), 0, qc, qc.hashCode(), [])]
        closed = []

        file = open("qc.txt", "w")
        while True:
            valor, cost, quebracabeca, hash, positions = todo[0]
            file.write("({}, {}, {})\n".format(valor, cost, hash))
            if quebracabeca.isOrdenado():
                return positions
            for i, j in self.get_neighbors(quebracabeca, positions):
                iHash = i.hashCode()
                if not iHash in closed:
                    todo.append((i.getValor(), cost + 1, i, iHash, j))
            closed.append(hash)
            todo.pop(0)

            # Ordena a lista por valor da heurística
            todo = sorted(todo, key=itemgetter(0, 1))
