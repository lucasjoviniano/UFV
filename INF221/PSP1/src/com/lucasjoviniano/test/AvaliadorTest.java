package com.lucasjoviniano.test;

import com.lucasjoviniano.main.Avaliador;
import org.junit.jupiter.api.Test;

import java.util.Arrays;
import java.util.List;
import java.util.Vector;

import static org.junit.jupiter.api.Assertions.assertEquals;

public class AvaliadorTest {
    private Avaliador avaliador;

    @Test
    void testAvaliaNaoImpedido() {
        int numAtacantes = 2;
        int numDefensores = 3;
        List<Integer> atacantes = new Vector<>(Arrays.asList(500, 700));
        List<Integer> defensores = new Vector<>(Arrays.asList(700, 500, 500));

        avaliador = new Avaliador(numAtacantes, numDefensores, atacantes, defensores);

        assertEquals('N', avaliador.avalia());
    }

    @Test
    void testAvaliaNaoImpedido2() {
        int numAtacantes = 3;
        int numDefensores = 4;
        List<Integer> atacantes = new Vector<>(Arrays.asList(530, 510, 490));
        List<Integer> defensores = new Vector<>(Arrays.asList(480, 470, 50, 310));

        avaliador = new Avaliador(numAtacantes, numDefensores, atacantes, defensores);

        assertEquals('N', avaliador.avalia());
    }

    @Test
    void testAvaliaImpedido() {
        int numAtacantes = 2;
        int numDefensores = 2;
        List<Integer> atacantes = new Vector<>(Arrays.asList(200, 400));
        List<Integer> defensores = new Vector<>(Arrays.asList(200, 1000));

        avaliador = new Avaliador(numAtacantes, numDefensores, atacantes, defensores);

        assertEquals('Y', avaliador.avalia());
    }
}
