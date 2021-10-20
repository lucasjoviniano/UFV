package com.lucasjoviniano.main;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;
import java.util.stream.Collectors;

public class Campeonato {
    public int numTimes;
    List<Time> times;

    public Campeonato(int n) {
        numTimes = n;
        times = new ArrayList<>(numTimes);

        for (int i = 0; i < n; i++) {
            times.add(new Time(i + 1));
        }
    }

    public void updateScores(String partida) {
        List<Integer> values = Arrays.stream(partida.split(" ")).map(Integer::parseInt).collect(Collectors.toList());

        times.get(values.get(0) - 1).pontosMarcados += values.get(1);
        times.get(values.get(0) - 1).pontosRecebidos += values.get(3);

        times.get(values.get(2) - 1).pontosMarcados += values.get(3);
        times.get(values.get(2) - 1).pontosRecebidos += values.get(1);

        if (values.get(1) > values.get(3)) {
            times.get(values.get(0) - 1).pontosTotais += 2;
            times.get(values.get(2) - 1).pontosTotais += 1;
        } else {
            times.get(values.get(0) - 1).pontosTotais += 1;
            times.get(values.get(2) - 1).pontosTotais += 2;
        }
    }

    public String resultado() {
        Collections.sort(times);
        return times.stream().map(time -> Integer.toString(time.id)).collect(Collectors.joining(" "));
    }

}
