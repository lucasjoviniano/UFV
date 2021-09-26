package com.lucasjoviniano.main;

import java.util.List;
import java.util.Scanner;
import java.util.Vector;

public class Main {

    public static void main(String[] args) {
        int numAtacantes;
        int numDefensores;

        Scanner input = new Scanner(System.in);

        while (true) {
            numAtacantes = input.nextInt();
            numDefensores = input.nextInt();

            if (isEndOfInput(numAtacantes, numDefensores)) {
                input.close();
                return;
            }

            List<Integer> atacantes = fillPlayers(numAtacantes, input);
            List<Integer> defensores = fillPlayers(numDefensores, input);

            Avaliador avaliador = new Avaliador(numAtacantes, numDefensores, atacantes, defensores);

            System.out.println(avaliador.avalia());
        }
    }

    private static boolean isEndOfInput(int A, int B) {
        return A == 0 && B == 0;
    }

    private static List<Integer> fillPlayers(int numberOfPlayers, Scanner input) {
        List<Integer> players = new Vector<>();

        for (int i = 0; i < numberOfPlayers; i++) {
            players.add(input.nextInt());
        }

        return players;
    }
}
