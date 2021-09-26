package com.lucasjoviniano.main;

import java.util.List;
import java.util.Vector;
import java.util.Collections;

public class Avaliador {
    Integer numAtacantes;
    Integer numDefensores;

    List<Integer> atacantes;
    List<Integer> defensores;

    public Avaliador(Integer A, Integer B, List<Integer> vA, List<Integer> vB) {
        numAtacantes = A;
        numDefensores = B;
        atacantes = new Vector<>(vA);
        defensores = new Vector<>(vB);
    }

    public char avalia() {

        Collections.sort(atacantes);
        Collections.sort(defensores);

        if (atacantes.get(0) < defensores.get(1)) {
            return 'Y';
        }

        return 'N';
    }
}
