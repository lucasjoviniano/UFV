package com.lucasjoviniano.test;

import com.lucasjoviniano.main.Campeonato;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.assertEquals;

public class CampeonatoTest {
    static Campeonato campeonato;
    static int n = 5;
    static String[] partidas = {"1 102 2 62",
            "1 128 3 127",
            "1 144 4 80",
            "1 102 5 101",
            "2 62 3 61",
            "2 100 4 80",
            "2 88 5 82",
            "3 79 4 90",
            "3 87 5 100",
            "4 110 5 99"};
    @Test
    public void testResultado() {
        campeonato = new Campeonato(5);

        for (int i = 0; i < partidas.length; i++) {
            campeonato.updateScores(partidas[i]);
        }

        assertEquals("1 2 4 5 3", campeonato.resultado());
    }
}
