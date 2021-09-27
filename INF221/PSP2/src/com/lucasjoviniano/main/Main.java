package com.lucasjoviniano.main;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader input = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(input.readLine());

        Campeonato campeonato = new Campeonato(n);

        for (int i = 0; i < (n * (n - 1) / 2); i++) {
            campeonato.updateScores(input.readLine());
        }

        System.out.println(campeonato.resultado());
    }
}
