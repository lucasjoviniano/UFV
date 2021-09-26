package com.lucasjoviniano.main;

import java.util.List;
import java.util.Vector;
import java.util.Collections;

public class Avaliador {
    Integer numAtacantes;
    Integer numDefensores;

    List<Integer> atacantes;
    List<Integer> defensores;

    public Avaliador(Integer numAtacantes, Integer numDefensores, List<Integer> atacantes, List<Integer> defensores) {
        this.numAtacantes = numAtacantes;
        this.numDefensores = numDefensores;
        this.atacantes = new Vector<>(atacantes);
        this.defensores = new Vector<>(defensores);

        Collections.sort(atacantes);
        Collections.sort(defensores);
    }

    public char avalia() {

        if (atacantes.get(0) < defensores.get(1)) {
            return 'Y';
        }

        return 'N';
    }
}
