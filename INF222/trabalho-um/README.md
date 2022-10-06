# Trabalho 1

Código referente ao Trbalho Prático 1 da disciplina Computação Experimental.

## Instalação

Os arquivos compilados estão disponíveis em https://github.com/lucasjoviniano/UFV/releases.

## Usage

1. **Duelo**: O duelo recebe 5 argumentos: 
    - Quantidade de vezes para repetir
    - Numerador da mira do primeiro duelista
    - Denominador da mira do primeiro duelista
    - Numerador da mira do segundo duelista
    - Denominador da mira do segundo duelista

    ```bash
    java -jar trabalho-um-0.1.0-standalone.jar 1000 4 6 5 6
    ```
    
    A saída é um arquivo csv no seguinte formato:
    ```csv
    player-one, 893
    player-two, 107
    ```
    
    Onde os números indicam quantas vezes cada jogador ganhou
2. **Truelo**: TODO

3. **Azar**: O jogo de azar recebe 3 argumentos
    - Quantidade de vezes para repetir
    - Dinheiro do jogador A
    - Dinheiro do jogador B
    
    ```bash
    java -jar trabalho-um-0.1.0-standalone.jar 1000 3 7
    ```
    
     A saída é um arquivo csv no seguinte formato:
    ```csv
    winner,rounds,one-swaps,two-swaps
    segundo,12,0,0
    primeiro,60,4,3
    segundo,14,0,1
    segundo,14,0,0
    ```
    
    Onde:
        - winner: Quem ganhou
        - rounds: Quantas tiros até alguém ganhar
        - one-swaps: Quantas vezes o jogador um passou a estar na frente
        - two-swaps: Quantas vezes o jogador dois passou a estar na frente
