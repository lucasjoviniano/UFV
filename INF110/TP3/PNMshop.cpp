#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>

using namespace std;

const int MAXALTURA  = 2000;							//tamanho maximo aceito
const int MAXLARGURA = 2000;

char intro();

// Funções em comum
void clarear(unsigned char***, int, int, bool);
void escurecer(unsigned char***, int, int, bool);
void negativo(unsigned char***, int, int, bool);
void espelhar(unsigned char***, int, int, bool);
void pretoebranco(unsigned char***, int, int, bool&);

// Imagens em tons de cinza.
void sobel(unsigned char***, int, int);
void nitidez(unsigned char***, int, int);
int gy(unsigned char***, int, int, int, int);
int gx(unsigned char***, int, int, int, int);

// Imagens coloridas.
void coloredtogray(unsigned char***, int, int, bool&);
void sobel(unsigned char***, int, int, bool);
void nitidez(unsigned char***, int, int, bool);
int gy(unsigned char***, int, int, int, int, int);
int gx(unsigned char***, int, int, int, int, int);


int main() {
  string nomeInicial;
  int largura, altura;              // Dimensoes da imagem
  char tipo[4];                     // Tipo da imagem
  ifstream arqentrada;              // Arquivo que contem a imagem original
  ofstream arqsaida;                // Arquivo que contera a imagem gerada
  char comentario[200], c;          // Auxiliares
  int i, j, k, valor;               // Auxiliares
  bool colorida = false;            // Auxiliar

  char option = intro();            // Recebe a opção do efeito que o usuário escolheu


  //*** LEITURA DA IMAGEM ***//
  //inicialmente nao sera necessario entender nem mudar nada nesta parte

  //*** Abertura do arquivo ***//
  cout << "Digite o nome do arquivo pnm: ";
  cin >> nomeInicial;
  arqentrada.open(nomeInicial + ".pnm",ios::in);  //Abre arquivo para leitura
  if (!arqentrada) {
    cout << "Nao consegui abrir " << nomeInicial << ".pnm" << endl;
    return 0;
  }
  //***************************//


  //*** Leitura do cabecalho ***//
  arqentrada >> tipo;                             // Le o tipo de arquivo
  arqentrada.get();                               // Le e descarta o \n do final da 1a. linha

  if (strcmp(tipo,"P2") == 0) {
    cout << "Imagem em tons de cinza" << endl;
  } else if (strcmp(tipo,"P3") == 0) {
      cout << "Imagem colorida" << endl;
      colorida = true;
  } else if (strcmp(tipo,"P5") == 0 || strcmp(tipo,"P6") == 0) {
      cout << "Imagem no formato RAW" << endl;
      cout << "Desculpe, mas nao trabalho com esse tipo de imagem." << endl;
      arqentrada.close();
      return 0;
  }

  while ((c = arqentrada.get()) == '#')             // Enquanto for comentario
  arqentrada.getline(comentario, 200);               // Le e descarta a linha "inteira"

  arqentrada.putback(c);                            // Devolve o caractere lido para a entrada, pois como
                                                    // nao era comentario, era o primeiro digito da largura

  arqentrada >> largura >> altura;	                // Le o numero de pixels da horizontal e vertical
  cout << "Tamanho: " << largura << " x " << altura << endl;
  if (largura > MAXLARGURA) {
    cout << "Desculpe, mas ainda nao trabalho com imagens com mais de " << MAXLARGURA << " pixels de largura." << endl;
    arqentrada.close();
    return 0;
  }
  if (altura > MAXALTURA) {
    cout << "Desculpe, mas ainda nao trabalho com imagens com mais de " << MAXALTURA << " pixels de altura." << endl;
    arqentrada.close();
    return 0;
  }

  arqentrada >> valor;                                // Valor maximo do pixel (temos que ler, mas nao sera usado)
  //****************************//

  //*** Leitura dos pixels da imagem ***//


  // Criação da matriz usando alocação dinâmica
  unsigned char ***imagem = new unsigned char**[altura];
  for (int i = 0; i < altura; i++) {
    imagem[i] = new unsigned char*[largura];
    for (int j = 0; j < largura; j++) {
      imagem[i][j] = new unsigned char[3];
    }
  }

  if (colorida) {
    for(i = 0;i < altura; i++){
      for(j = 0;j < largura; j++){
        for(k = 0; k < 3; k++){
          arqentrada >> valor;
          imagem[i][j][k] = (unsigned char)valor;
        }
      }
    }
  } else {
    for(i = 0; i < altura; i++){
      for(j = 0; j < largura; j++){
        arqentrada >> valor;
        imagem[i][j][0] = (unsigned char)valor;
      }
    }
  }
  //************************************//

  arqentrada.close();

  //*** FIM DA LEITURA DA IMAGEM ***//

  //*** TRATAMENTO DA IMAGEM ***//
  switch (option) {
    case '1':
      clarear(imagem, largura, altura, colorida);
      break;
    case '2':
      escurecer(imagem, largura, altura, colorida);
      break;
    case '3':
      negativo(imagem, largura, altura, colorida);
      break;
    case '4':
      espelhar(imagem, largura, altura, colorida);
      break;
    case '5':
      if (colorida) {
        coloredtogray(imagem, largura, altura, colorida);
      } else {
        cout << "Essa imagem ja esta em tons de cinza" << endl;
        return 0;
      }
      break;
    case '6':
      pretoebranco(imagem, largura, altura, colorida);
      break;
    case '7':
      if (colorida) {
        sobel(imagem, largura, altura, colorida);
      } else {
        sobel(imagem, largura, altura);
      }
      break;
    case '8':
      if (colorida) {
        nitidez(imagem, largura, altura, colorida);
      } else {
        nitidez(imagem, largura, altura);
      }
      break;
  }
  //*************************//

  //*** FIM DO TRATAMENTO DA IMAGEM ***//



  //*** GRAVACAO DA IMAGEM ***//
  //inicialmente nao sera necessario entender nem mudar nada nesta parte

  //*** Grava a nova imagem ***//
  string nomeFinal;

  cout << "Nome para salvar: ";
  cin >> nomeFinal;

  arqsaida.open(nomeFinal + ".pnm",ios::out);	                     //Abre arquivo para escrita
  if (!arqsaida) {
    cout << "Nao consegui criar " << nomeFinal <<  ".pnm" << endl;
    return 0;
  }

  if (colorida) {
    arqsaida << tipo << endl;						                         // Tipo
    arqsaida << "# INF110" << endl;                              // Comentario
    arqsaida << largura << " " << altura << endl;                // Dimensoes
    arqsaida << 255 << endl;						                         // Maior valor possivel para o pixel
    for(i = 0;i < altura; i++){
      for(j = 0; j < largura; j++){
        for(k = 0; k < 3; k++){
          arqsaida << (int)imagem[i][j][k] << endl;               // Pixels
        }
      }
    }
  } else {
    if(strcmp(tipo, "P3") == 0){
      arqsaida << "P2" << endl;                                  // Tipo
    }else{
      arqsaida << tipo << endl;
    }
    arqsaida << "# INF110\n";                                    // Comentario
    arqsaida << largura << " " << altura << endl;	               // Dimensoes
    arqsaida << 255 << endl;						                         // Maior valor possivel para o pixel
    for(i = 0; i < altura; i++){
      for(j = 0; j < largura; j++){
        arqsaida << (int)imagem[i][j][0] << endl;	               // Pixels
      }
    }
  }

  arqsaida.close();		                                           // Fecha o arquivo
  //***************************//

  //*** FIM DA GRAVACAO DA IMAGEM ***//

  for (int i = 0; i < altura; i++) {
    for (int j = 0; j < largura; j++) {
      delete [] imagem[i][j];
    }
    delete [] imagem[i];
  }
  delete [] imagem;

  return 0;
}

char intro(){
  cout << "Ola', eu sou o PNMshop. O que você deseja fazer? (Digite o número correspondente)" << endl;
  cout << "1 - Clarear" << endl;
  cout << "2 - Escurecer" << endl;
  cout << "3 - Negativo" << endl;
  cout << "4 - Espelhar" << endl;
  cout << "5 - Tons de Cinza" << endl;
  cout << "6 - Preto e Branco" << endl;
  cout << "******************************************" << endl;
  cout << "Filtros" << endl;
  cout << "7 - Sobel" << endl;
  cout << "8 - Nitidez" << endl;

  char n[8] = {'1', '2', '3', '4', '5', '6', '7', '8'};
  char option;
  bool pare = true;
  while (pare) {
    cout << "Opcao: ";
    cin >> option;
    for(int i = 0; i < 8; i++){
      if(option == n[i]){
        pare = false;
        break;
      }
    }
  }
  return option;
}

/******************************************** FUNÇÕES COMUNS ********************************************/

void escurecer(unsigned char*** imagem, int largura, int altura, bool colorida){
  int fator, valor;
  cout << "Qual o fator de escurecimento (1-100)? ";
  cin >> fator;

  if(colorida){
    for (int i = 0; i < altura; i++)
    for (int j = 0; j < largura; j++){
      for(int k = 0; k < 3; k++){
        valor = (int)imagem[i][j][k];				      // Pega o valor do pixel
        valor -= fator;							              // Escurece o pixel
        if (valor < 0){                           // Se der negativo
          valor = 0;							                // Transforma em 0
        }
        imagem[i][j][k] = (unsigned char)valor;	  // Modifica o pixel
      }
    }
  } else {
    for (int i = 0; i < altura; i++) {
      for (int j = 0; j < largura; j++) {
        valor = (int)imagem[i][j][0];				         // Pega o valor do pixel
        valor -= fator;							                 // Escurece o pixel
        if (valor < 0) {                             // Se der negativo
          valor = 0;							                   // Transforma em 0
        }
        imagem[i][j][0] = (unsigned char)valor;	     // Modifica o pixel
      }
    }
  }
}

void clarear(unsigned char*** imagem,int largura, int altura, bool colorida){
  int fator, valor;
  cout << "Qual o fator de clareamento (1-100) ? ";
  cin >> fator;

  if (colorida) {
    for (int i = 0; i < altura; i++) {
      for (int j = 0; j < largura; j++) {
        for (int k = 0; k < 3; k++) {
          valor = (int)imagem[i][j][k];				      // Pega o valor do pixel
          valor += fator;							              // clareia o pixel
          if (valor > 255){                         // Se der acima de 255
            valor = 255;							              // Deixa branco
          }
          imagem[i][j][k] = (unsigned char)valor;	  // Modifica o pixel
        }
      }
    }
  } else {
    for (int i = 0; i < altura; i++) {
      for (int j = 0; j < largura; j++) {
        valor = (int)imagem[i][j][0];				    // Pega o valor do pixel
        valor += fator;							            // Clareia o pixel
        if (valor > 255) {                      // Se der acima de 255
          valor = 255;							            // Deixa branco
        }
        imagem[i][j][0] = (unsigned char)valor;	// Modifica o pixel
      }
    }
    colorida = false;
  }
}

void negativo(unsigned char*** imagem, int largura, int altura, bool colorida){
  int valor;

  if (colorida) {
    for (int i = 0; i < altura; i++) {
      for (int j = 0; j < largura; j++) {
        for (int k = 0; k < 3; k++) {
          valor = (int)imagem[i][j][k];				      // Pega o valor do pixel
          valor = 255 - valor;					            // Transforma o pixel no seu equidistante
          imagem[i][j][k] = (unsigned char)valor;	  // Modifica o pixel
        }
      }
    }
  } else {
    for(int i = 0; i < altura; i++){
      for (int j = 0; j < largura; j++) {
        valor = (int)imagem[i][j][0];				    // Pega o valor do pixel
        valor = 255 - valor;					          // Transforma o pixel no seu equidistante
        imagem[i][j][0] = (unsigned char)valor;	// Modifica o pixel
      }
    }
  }
}

void espelhar(unsigned char*** imagem, int largura, int altura, bool colorida){
  unsigned char valor;

  if (colorida) {
    for (int i = 0; i < altura; i++) {
      for (int j = 0; j < largura / 2; j++) {
        for (int k = 0; k < 3; k++) {
          valor = imagem[i][j][k];                           // Pega o valor atual
          imagem[i][j][k] = imagem[i][largura - 1 - j][k];   // Transforma no último valor espelhado
          imagem[i][largura - 1 - j][k] = valor;             // Transforma o último valor no atual
        }
      }
    }
  } else {
    for (int i = 0; i < altura; i++) {
      for (int j = 0; j < largura/2; j++) {
        valor = imagem[i][j][0];                          // Pega o valor atual
        imagem[i][j][0] = imagem[i][largura - 1 - j][0];  // Transforma no último valor espelhado
        imagem[i][largura - 1 - j][0] = valor;            // Transforma o último valor no atual
      }
    }
  }
}

void pretoebranco(unsigned char*** imagem, int largura, int altura, bool &colorida){
  int threshold = 0;
  int aux = 0;
  if (colorida) {                                       // Se a imagem for colorida
    coloredtogray(imagem, largura, altura, colorida);   // Converte para tons de cinza
  }

  for(int i = 0; i < altura; i++){
    for(int j = 0; j < largura; j++){
      threshold += imagem[i][j][0];                     // Soma todos os valores da imagem
    }
  }

  threshold /= altura * largura;                        // Faz a média dos valores

  for(int i = 0; i < altura; i++){
    for(int j = 0; j < largura; j++){
      aux = (int)imagem[i][j][0];
      aux = (aux < threshold) ? 0 : 255;                // Se o valor estiver abaixo da média, é preto
      imagem[i][j][0] = (unsigned char)aux;
    }
  }
}

/******************************************** FUNÇÕES TONS DE CINZA ********************************************/

void sobel(unsigned char*** imagem, int largura, int altura){

  int x, y, final, i, j;

  int **imgx = new int*[altura];
  for (int k = 0; k < altura; k++) {
    imgx[k] = new int[largura];
  }

  int **imgy = new int*[altura];
  for (int k = 0; k < altura; k++) {
    imgy[k] = new int[largura];
  }

  for (i = 0; i < altura; i++) {
    for (j = 0; j < largura; j++) {
      imgx[i][j] = gx(imagem, i, j, largura, altura);   // Aplica a matriz x de Sobel para cada pixel da imagem
    }
  }

  for (i = 0; i < altura; i++) {
    for (j = 0; j < largura; j++) {
      imgy[i][j] = gy(imagem, i, j, largura, altura);   // Aplica a matriz y de Sobel para cada pixel da imagem
    }
  }

  for (i = 0; i < altura; i++) {
    for (j = 0; j < largura; j++) {
      x = imgx[i][j];                                 // Pega o pixel de x
      x = ((x > 255) ? 255 : x);                      // Se for maior que 255, tranforma em 255
      x = ((x < 0) ? 0 : x);                          // Se for negativo, transforma em 0
      y = imgy[i][j];                                 // Pega o pixel de y
      y = ((y > 255) ? 255 : y);                      // Se for maior que 255, tranforma em 255
      y = ((y < 0) ? 0 : y);                          // Se for negativo, transforma em 0
      if (i == 0 || i == altura-1) {                  // Se o ponto for superior ou inferior
        final = x;                                    // Só considera o valor de x
      } else if (j == 0 || j == largura-1) {          // Se o ponto for da lateral direita ou esquerda
        final = y;                                    // Só considera o valor de y
      } else {                                        // Nos outros casos
        final = (x + y)/2;                            // Faz a média aritmética de x e y
      }
      // Checa se o ponto é um dos cantos, se for, duplica o ponto ao lado.
      if (i == 0 && j == largura-1) {
        imagem[i][j][0] = imagem[i][j-1][0];
      } else if (i == altura - 1 && j == 0) {
        imagem[i][j][0] = imagem[i][j+1][0];
      } else if (i == altura - 1 && j == largura - 1) {
        imagem[i][j][0] = imagem[i][j-1][0];
      } else {
        imagem[i][j][0] = (unsigned char)final;           // Altera o pixel
      }
    }
    imagem[0][0][0] = imagem[0][1][0];                    // Faz a duplicação dos pontos do canto superior esquerdo
    for (int i = 0; i < altura; i++) {
      delete [] imgx[i];
      delete [] imgy[i];
    }
    delete [] imgx;
    delete [] imgy;
  }
}

void nitidez(unsigned char*** imagem, int largura, int altura){
  int imgn[altura][largura];
  int valor;
  int aux = 0;

  for (int i = 0; i < altura; i++) {
    for (int j = 0; j < largura; j++) {
      imgn[i][j] = (int)imagem[i][j][0];
    }
  }

  for (int i = 0; i < altura; i++) {
    for (int j = 0; j < largura; j++) {
      valor = (i - 1 < 0) ? 0 : imgn[i-1][j];               //Checa se os pontos estão fora da imagem. Se estão, transforma em 0.
      aux -= valor;
      valor = (j - 1 < 0) ? 0 : imgn[i][j-1];               //Checa se os pontos estão fora da imagem. Se estão, transforma em 0.
      aux -= valor;
      valor = imgn[i][j];                                   //Checa se os pontos estão fora da imagem. Se estão, transforma em 0.
      aux += (valor * 5);
      valor = (j + 1 >= largura) ? 0 : imgn[i][j+1];        //Checa se os pontos estão fora da imagem. Se estão, transforma em 0.
      aux -= valor;
      valor = (i + 1 >= altura) ? 0 : imgn[i+1][j];         //Checa se os pontos estão fora da imagem. Se estão, transforma em 0.
      aux -= valor;

      aux = (aux > 255) ? 255 : aux;
      aux = (aux < 0) ? 0 : aux;
      imagem[i][j][0] = (unsigned char)aux;
      aux = 0;
    }
  }
}

// Calcula o direcionamento de x na imagem em tons de cinza
int gy(unsigned char*** imagem, int i, int j, int largura, int altura){
  int valor;
  int auy = 0;

  valor = (i - 1 < 0 || j - 1 < 0) ? 0 : (int)imagem[i-1][j-1][0];               //Checa se os pontos estão fora da imagem. Se estão, transforma em 0.
  auy += valor;
  valor = (i - 1 < 0) ? 0 : (int)imagem[i-1][j][0];                              //Checa se os pontos estão fora da imagem. Se estão, transforma em 0.
  auy += valor * 2;
  valor = (i - 1 < 0 || j + 1 >= largura) ? 0 : (int)imagem[i-1][j+1][0];        //Checa se os pontos estão fora da imagem. Se estão, transforma em 0.
  auy += valor;
  valor = (i + 1 >= altura || j - 1 < 0) ? 0 : (int)imagem[i+1][j-1][0];         //Checa se os pontos estão fora da imagem. Se estão, transforma em 0.
  auy -= valor;
  valor = (i + 1 >= altura) ? 0 : (int)imagem[i+1][j][0];                        //Checa se os pontos estão fora da imagem. Se estão, transforma em 0.
  auy -= valor * 2;
  valor = (i + 1 >= altura || j + 1 >= largura) ? 0 : (int)imagem[i+1][j+1][0];  //Checa se os pontos estão fora da imagem. Se estão, transforma em 0.
  auy -= valor;

  return auy;
}

// Calcula o direcionamento de x na imagem em tons de cinza
int gx(unsigned char*** imagem, int i, int j, int largura, int altura){
  int valor;
  int aux = 0;

  valor = (i - 1 < 0 || j - 1 < 0) ? 0 : (int)imagem[i-1][j-1][0];                 //Checa se os pontos estão fora da imagem. Se estão, transforma em 0.
  aux += valor;
  valor = (i - 1 < 0 || j + 1 >= largura) ? 0 : (int)imagem[i-1][j+1][0];          //Checa se os pontos estão fora da imagem. Se estão, transforma em 0.
  aux -= valor;
  valor = (j - 1 < 0) ? 0 : (int)imagem[i][j-1][0];                                //Checa se os pontos estão fora da imagem. Se estão, transforma em 0.
  aux += valor * 2;
  valor = (j + 1 >= largura) ? 0 : (int)imagem[i][j+1][0];                         //Checa se os pontos estão fora da imagem. Se estão, transforma em 0.
  aux -= valor * 2;
  valor = (i + 1 >= altura || j - 1 < 0) ? 0 : (int)imagem[i+1][j-1][0];           //Checa se os pontos estão fora da imagem. Se estão, transforma em 0.
  aux += valor;
  valor = (i + 1 >= altura || j + 1 >= largura) ? 0 : (int)imagem[i+1][j+1][0];    //Checa se os pontos estão fora da imagem. Se estão, transforma em 0.
  aux -= valor;

  return aux;
}

/******************************************** FUNÇÕES COLORIDAS ********************************************/

void coloredtogray(unsigned char*** imagem, int largura, int altura, bool &colorida){
  int rgb, valor;
  for (int i = 0; i < altura; i++) {
    for (int j = 0; j < largura; j++) {
      rgb = 0;
      for (int k = 0; k < 3; k++) {
        rgb += (int)imagem[i][j][k];          // Pega os valores RGB do pixel
      }
      valor = rgb / 3;                        // Faz a média aritmética deles
      imagem[i][j][0] = (unsigned char)valor;	// Modifica o pixel
    }
  }
  colorida = false;                           // Diz para a main que a imagem é em tons de cinza
}

void sobel(unsigned char*** imagem, int largura, int altura, bool colorida){

  int x, y, final, i, j, k;

  int imgx[altura][largura][3];                                 // Cria a matriz que vai abrigar o gx
  int imgy[altura][largura][3];                                 // Cria a matriz que vai abrigar o gy

  for (k = 0; k < 3; k++) {
    for (i = 0; i < altura; i++) {
      for (j = 0; j < largura; j++) {
        imgx[i][j][k] = gx(imagem, i, j, k, largura, altura);  // Aplica a matriz x de Sobel para cada pixel da imagem e seus canais
      }
    }
  }

  for (k = 0; k < 3; k++) {
    for (i = 0; i < altura; i++) {
      for (j = 1; j < largura; j++) {
        imgy[i][j][k] = gy(imagem, i, j, k, largura, altura);  // Aplica a matriz y de Sobel para cada pixel da imagem e seus canais
      }
    }
  }

  for (k = 0; k < 3; k++) {
    for (i = 0; i < altura; i++) {
      for (j = 0; j < largura; j++) {
        x = imgx[i][j][k];                                    // Pega o pixel de x
        x = ((x > 255) ? 255 : x);                            // Se for maior que 255, tranforma em 255
        x = ((x < 0) ? 0 : x);                                // Se for negativo, transforma em 0
        y = imgy[i][j][k];                                    // Pega o pixel de y
        y = ((y > 255) ? 255 : y);                            // Se for maior que 255, tranforma em 255
        y = ((y < 0) ? 0 : y);                                // Se for negativo, transforma em 0
        if(i == 0 || i == altura-1){                          // Se o ponto for superior ou inferior
          final = x;                                          // Só considera o valor de x
        }else if(j == 0 || j == largura-1){                   // Se o ponto for da lateral direita ou esquerda
          final = y;                                          // Só considera o valor de y
        }else{                                                // Nos outros casos
          final = (x + y)/2;                                  // Faz a média aritmética de x e y
        }
        // Checa se o ponto é uma das bordas, se for, duplica o ponto ao lado.
        if (i == 0 && j == largura-1) {
          imagem[i][j][k] = imagem[i][j-1][k];
        } else if(i == altura - 1 && j == 0) {
          imagem[i][j][k] = imagem[i][j+1][k];
        } else if (i == altura - 1 && j == largura - 1) {
          imagem[i][j][k] == imagem[i][j-1][k];
        } else {
          imagem[i][j][k] = (unsigned char)final;         // Altera o pixel
        }
      }
    }
    imagem[0][0][k] = imagem[0][1][k];                    // Faz a duplicação dos pontos do canto superior esquerdo
  }
}

void nitidez(unsigned char*** imagem, int largura, int altura, bool colorida){
  int imgn[altura][largura][3];
  int valor;
  int aux = 0;

  for (int k = 0; k < 3; k++) {
    for (int i = 0; i < altura; i++) {
      for (int j = 0; j < largura; j++) {
        imgn[i][j][k] = (int)imagem[i][j][k];
      }
    }
  }

  for (int k = 0; k < 3; k++) {
    for (int i = 0; i < altura; i++) {
      for (int j = 0; j < largura; j++) {
        valor = (i - 1 < 0) ? 0 : imgn[i-1][j][k];               //Checa se os pontos estão fora da imagem. Se estão, transforma em 0.
        aux -= valor;
        valor = (j - 1 < 0) ? 0 : imgn[i][j-1][k];               //Checa se os pontos estão fora da imagem. Se estão, transforma em 0.
        aux -= valor;
        valor = imgn[i][j][k];                                   //Checa se os pontos estão fora da imagem. Se estão, transforma em 0.
        aux += (valor * 5);
        valor = (j + 1 >= largura) ? 0 : imgn[i][j+1][k];        //Checa se os pontos estão fora da imagem. Se estão, transforma em 0.
        aux -= valor;
        valor = (i + 1 >= altura) ? 0 : imgn[i+1][j][k];         //Checa se os pontos estão fora da imagem. Se estão, transforma em 0.
        aux -= valor;

        aux = (aux > 255) ? 255 : aux;
        aux = (aux < 0) ? 0 : aux;
        imagem[i][j][k] = (unsigned char)aux;
        aux = 0;
      }
    }
  }
}

// calcula o direcionamento de y na imagem colorida
int gy(unsigned char*** imagem, int i, int j, int k, int largura, int altura){
  int valor;
  int auy = 0;

  valor = (i - 1 < 0 || j - 1 < 0) ? 0 : (int)imagem[i-1][j-1][k];                //Checa se os pontos estão fora da imagem. Se estão, transforma em 0.
  auy += valor;
  valor = (i - 1 < 0) ? 0 : (int)imagem[i-1][j][k];                               //Checa se os pontos estão fora da imagem. Se estão, transforma em 0.
  auy += valor * 2;
  valor = (i - 1 < 0 || j + 1 >= largura) ? 0 : (int)imagem[i-1][j+1][k];         //Checa se os pontos estão fora da imagem. Se estão, transforma em 0.
  auy += valor;
  valor = (i + 1 >= altura || j - 1 < 0) ? 0 : (int)imagem[i+1][j-1][k];          //Checa se os pontos estão fora da imagem. Se estão, transforma em 0.
  auy -= valor;
  valor = (i + 1 >= altura) ? 0 : (int)imagem[i+1][j][k];                         //Checa se os pontos estão fora da imagem. Se estão, transforma em 0.
  auy -= valor * 2;
  valor = (i + 1 >= altura || j + 1 >= largura) ? 0 : (int)imagem[i+1][j+1][k];   //Checa se os pontos estão fora da imagem. Se estão, transforma em 0.
  auy -= valor;

  return auy;
}


//Calcula o direcionamento x de sobel na imagem colorida.
int gx(unsigned char*** imagem, int i, int j, int k, int largura, int altura){
  int valor;
  int aux = 0;

  valor = (i - 1 < 0 || j - 1 < 0) ? 0 : (int)imagem[i-1][j-1][k];              //Checa se os pontos estão fora da imagem. Se estão, transforma em 0.
  aux += valor;
  valor = (i - 1 < 0 || j + 1 >= largura) ? 0 : (int)imagem[i-1][j+1][k];       //Checa se os pontos estão fora da imagem. Se estão, transforma em 0.
  aux -= valor;
  valor = (j - 1 < 0) ? 0 : (int)imagem[i][j-1][k];                             //Checa se os pontos estão fora da imagem. Se estão, transforma em 0.
  aux += valor * 2;
  valor = (j + 1 >= largura) ? 0 : (int)imagem[i][j+1][k];                      //Checa se os pontos estão fora da imagem. Se estão, transforma em 0.
  aux -= valor * 2;
  valor = (i + 1 >= altura || j - 1 < 0) ? 0 : (int)imagem[i+1][j-1][k];        //Checa se os pontos estão fora da imagem. Se estão, transforma em 0.
  aux += valor;
  valor = (i + 1 >= altura || j + 1 >= largura) ? 0 : (int)imagem[i+1][j+1][k]; //Checa se os pontos estão fora da imagem. Se estão, transforma em 0.
  aux -= valor;

  return aux;
}
