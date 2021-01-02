#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <cstdio>

using namespace std;

char* leLinha(fstream &);
char* buscarDado(char*, int);
void buscaColunas(char*, char*, char*, int&);
void ordena(int, int);
void quickSort(char**, int);
void insertionSort(char**, int);

/* Ordem no argv
 * argv[0]: Nome do Programa
 * argv[1]: Nome do arquivo a ser aberto
 * argv[2]: Tamanho que cabe na memória
 * argv[3]: Coluna referência para a ordenação
 * argv[4]: Coluna para calcular a média
 */

int main(int argc, char** argv) {

  // Se o programa não for chamado corretamente, exibe mensagem de erro.
  if (argc != 5) {
    cerr << "Use " << argv[0] <<" nomedoarquivo tamanhonamem colunachave colunamedia\n";
  return -1;
  }

  int num_linhas;
  
  cout << argv[3] << ", " << argv[4] << endl;
  
  buscaColunas(argv[1], argv[3], argv[4], num_linhas);
  
  ordena(num_linhas, atoi(argv[2])); 
  
  return 0;
}

// Lê uma linha do arquivo
char* leLinha(fstream &file) {
  string line;
  getline(file, line);

  char* linha = new char[line.length() + 1];
  strcpy(linha, line.c_str());
  
  return linha;
}

void buscaColunas(char* file, char* ord, char* media, int &num_linhas) {
  fstream arq(file, ios::in);

  fstream menor("cols.txt", ios::out);

  num_linhas = 0;

  char* linha, *dado;
  int cols[2] = {-1, -1};
  linha = leLinha(arq);
  dado = strtok(linha, ",");
  for (int i = 0; (cols[0] < 0 || cols[1] < 0); i++) {
    if (strcmp(ord, dado) == 0) cols[0] = i;
    if (strcmp(media, dado) == 0) cols[1] = i;
    dado = strtok(NULL, ",");
  }

  delete [] linha;

  while(arq.peek() != EOF) {
    linha = leLinha(arq);
    dado = buscarDado(linha, cols[0]);
    menor << dado << ',';
    delete [] dado;
    dado = buscarDado(linha, cols[1]);
    menor << dado << endl;
    delete [] dado;
    delete [] linha;
    num_linhas++;
  }

  arq.close();
  menor.close();
}

// Acessa o dado necessário da linha
char* buscarDado(char* linha, int col) {

  // Copia a linha, considerando que a strtok modifica a original
  char* line = new char[strlen(linha) + 1];
  strcpy(line, linha);
  // Pega o primeiro elemento da linha
  char* dado = strtok(line, ",");

  // Enquanto não chegar na coluna definida
  for (int i = 0; i < col; i++){
    // Pega o próximo elemento
    dado = strtok(NULL, ",");
  }
  if (strlen(dado)==0) return NULL;

  // Copia o valor encontrado
  char* valor = new char[strlen(dado) + 1];
  strcpy(valor, dado);
  
  delete [] line;
  
  return valor;
}

int buscarMenor(char** v, int n, int col) {
  char* menor;
  int pos;

  // Pega a primeira posição não vazia
  for (int i = 0; i < n; i++) {
    if (strlen(v[i]) != 0) {
      menor = buscarDado(v[i], col);
      pos = i;
      break;
    }
  }

  // Acha a posição do menor valor
  char* val;
  for (int i = 0; i < n; i++) {
    if(strlen(v[i]) == 0 || i == pos) continue;
    val = buscarDado(v[i], col);
    if (strcmp(menor, val) > 0) {
      delete [] menor;
      menor = new char[strlen(val) + 1];
      strcpy(menor, val);
      pos = i;
    }
    delete [] val;
  }

  delete [] menor;

  return pos;
}

void divide(fstream &dados, fstream* v, int num, int mem) {
  // Cria um bloco do tamanho disponível na memória
  char** bloco = new char*[mem];

  // Auxiliares
  int n = 0;
  int k = num;

  // Enquanto não chegar no fim de arquivo
  while (k > 0) {
    // Se n passar do número criado de arquivos, retorna para o primeiro
    if (n == num/mem + 1) n = 0;

    if (k - mem >= 0){
      // Lê a quantidade de linhas que cabe na memória
      for (int i = 0; i < mem; i++) 
        bloco[i] = leLinha(dados);
      quickSort(bloco, mem);
      insertionSort(bloco, mem);
     //cout << "Bloco: \n"; 
      for (int i = 0; i < mem; i++) {
        //cout << bloco[i] << endl;
        v[n] << bloco[i] << endl;
        delete [] bloco[i];
      }
    } else {
      // Lê a quantidade restante de linhas
      for (int i = 0; i < k; i++)
        bloco[i] = leLinha(dados);
      quickSort(bloco, k);
      insertionSort(bloco, k);

      //cout << "Bloco: \n";
      for (int i = 0; i < k; i++) {
        //cout << bloco[i] << endl;
        v[n] << bloco[i] << endl;
        delete [] bloco[i];
      }
    }

    k -= mem;
    n++;
  }
  delete [] bloco;
}

void merge(fstream* v, int num, int mem) {

  char** bloco = new char*[num/mem + 1];

  // Cursores para os arquivos
  int* curs = new int[num/mem + 1];

  // Inicializa os cursores com 0
  memset(curs, 0, (num/mem + 1) * sizeof(int));

  // Auxiliar
  int menor;
  char* chave, *a;
  char* anterior; 
  long double media = 0;
  int cont = 0;

  // Lê o primeiro registro de cada arquivo
  for (int i = 0; i <= num/mem; i++) {
    v[i].seekg(0, v[i].beg);
    bloco[i] = leLinha(v[i]);
  }

  menor = buscarMenor(bloco, num/mem + 1, 0);
  anterior = buscarDado(bloco[menor], 0);
  // Coloca o menor registro no arquivo final e pega o próximo
  for (int i = 0; i < num; i++) {
    menor = buscarMenor(bloco, num/mem + 1, 0);
    chave = buscarDado(bloco[menor], 0);
    if (strcmp(chave, anterior) != 0) {
      cout << fixed << setprecision(15) << anterior << ", " << media/cont << endl;
      if (anterior) delete [] anterior;
      anterior = new char[strlen(chave) + 1];
      strcpy(anterior, chave);
      media = 0;
      cont = 0;
    }
      delete [] chave;
      chave = buscarDado(bloco[menor], 1);
      media += strtod(chave, &a);
      delete [] chave;
      cont++;

    // Incrementa o cursor do arquivo
    curs[menor]++;
    delete [] bloco[menor];
    if (!v[menor].eof()) bloco[menor] = leLinha(v[menor]);
  }
   cout << fixed << setprecision(15) << anterior << ", " << media/cont << endl;
  
  for (int i = 0; i <= num/mem; i++)
    if (bloco[i]) delete [] bloco[i];
  delete [] bloco;
  delete [] curs;
  delete [] anterior;
}

void ordena(int num, int mem) {
  fstream dados("cols.txt", ios::in);

  // Cria arquivos auxiliares
  fstream* aux = new fstream[num/mem+1];

  // String auxiliar para os nomes dos arquivos
  char* disp = new char[50];

  for (int i = 0; i <= num/mem; i++) {
    // "Imprime" dentro da string o texto formatado
    sprintf(disp, "disp%d.txt", i+1);
    aux[i].open(disp, ios::in | ios::out | ios::trunc);
  }

  // Quebra o arquivo original em arquivos ordenados
  divide(dados, aux, num, mem);

  // Fecha o fluxo de entrada
  dados.close();

  // Junta os arquivos no original
  merge(aux, num, mem);

  // Fecha todos os arquivos
  for (int i = 0; i <= num/mem; i++) aux[i].close();

  delete [] aux;
  delete [] disp;
}

void insertionSort(char** v, int n) {
  for (int i = 1; i < n; i++) {
    char* elemInserir = v[i];
    int j = i - 1;
    while (j >= 0 && strcmp(v[j], elemInserir) > 0) {
      swap(v[j + 1], v[j]);
      j--;
    }
    v[j + 1] = elemInserir;
  }
}

// Função particiona do QuickSort
int particiona(char** v, int beg, int end, int pivo) {
  // Pega o dado da linha pivô, que será usado para comparação
  char* valorPivo = buscarDado(v[pivo], 0);
  // Transforma em minúsculas para comparação
  swap(v[pivo], v[end - 1]);
  int pos = beg;
  for (int i = beg; i < end - 1; i++) {
    // Pega o dado da linha atual
    char* chave = buscarDado(v[i], 0);

    // Compara o dado do pivô com o dado da linha atual
    if (strcmp(chave, valorPivo) < 0) {
      swap(v[pos], v[i]);
      pos++;
    }
    if(chave) delete [] chave;
  }
  swap(v[pos], v[end - 1]);
  delete [] valorPivo;
  return pos;
}

void quickSort(char** v, int beg, int end) {
  if (end - beg <= 25)
    return;
  int pos = particiona(v, beg, end, beg);
  quickSort(v, beg, pos);
  quickSort(v, pos + 1, end);
}

void quickSort(char** v, int n) {
  quickSort(v, 0, n);
}
