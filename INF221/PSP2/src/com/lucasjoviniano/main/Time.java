package com.lucasjoviniano.main;

import java.util.Arrays;
import java.util.List;
import java.util.Objects;

public class Time implements Comparable<Time> {
    public int id;
    public int pontosMarcados;
    public int pontosRecebidos;
    public int pontosTotais;

    public Time(int id) {
        this.id = id;
        pontosMarcados = 0;
        pontosRecebidos = 0;
        pontosTotais = 0;
    }

    @Override
    public int compareTo(Time obj) {
        if (this.pontosTotais > obj.pontosTotais) {
            return -1;
        }

        if (this.pontosTotais == obj.pontosTotais) {
            List<Double> cestaAverages = calculateCestaAverage(obj);

            if (cestaAverages.get(0) > cestaAverages.get(1)) {
                return -1;
            }

            if (Objects.equals(cestaAverages.get(0), cestaAverages.get(1))) {
                return -1;
            }
        }

        return 1;
    }

    private List<Double> calculateCestaAverage(Time obj) {
        int p1, p2;

        p1 = pontosRecebidos == 0 ? 1 : pontosRecebidos;
        p2 = obj.pontosRecebidos == 0 ? 1 : obj.pontosRecebidos;

        double avg1 = (double)pontosMarcados / p1;
        double avg2 = (double)obj.pontosMarcados / p2;

        return Arrays.asList(avg1, avg2);
    }
}
