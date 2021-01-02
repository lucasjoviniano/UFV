#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
using namespace std;

#define CIMA MAPA[posy-1][posx] != '0'
#define BAIXO MAPA[posy+1][posx] != '0'
#define ESQUERDA MAPA[posy][posx-1] !='0'
#define DIREITA MAPA[posy][posx+1] != '0'

// 0 - Paredes
// 1 - Células vazias
// 2 - Pílulas
char MAPA[20][48] =
{
 "33333333333333333303033333030333333333333333333",
 "30000000000000000002011111020000000000000000003",
 "30110222222222222202011111020222222222222201103",
 "30000200000000000202000000020200000000000200003",
 "30222222222022222222222222222222222022222222203",
 "00200000002020000002000200020000002020000000203",
 "30222222202220222222222222222222202220222222203",
 "00000000202020200002000100020000202020200000000",
 "32222222222022222222011111022222222022222222223",
 "00000000202020200002011111020000202020200000000",
 "32222222222022222222011111022222222022222222223",
 "00000000202020200002000000020000202020200000000",
 "30222222202220222222222222222222202220222222203",
 "30200000002020000002000200020000002020000000200",
 "30222222222022222222222122222222222022222222203",
 "30000200000000000202000000020200000000000200003",
 "30110222222222222202011111020222222222222201103",
 "30000000000000000002011111020000000000000000003",
 "33333333333333333303033333030333333333333333333",
};

// Constantes
const int MAP_W = 49;
const int MAP_H = 20;
const int DISPLAY_W = (MAP_W - 2) * 20;
const int DISPLAY_H = (MAP_H - 1) * 20;
const int BOX_H = 8 + 3;
const int BOX_W = 21 + 5;
const int CELL_SIZE = 20;
const double FPS = 1.7/10.0;
const int TEXT_POS[2] = {23, 0};
const int LOGO_POS[2] = {1, 18};

// Funções
int begin();
void drawEntities();
void drawMap();
void drawPills();
void end();
void lost();
void swap(int &, int &);
bool validState(int, int, int);

// Enumerações
enum DRAW {REDRAW, NOT_REDRAW};
enum MOVEMENT {UP, DOWN, LEFT, RIGHT, NONE};

// Base do Pacman
class PACMAN {
  public:
  ALLEGRO_BITMAP *entity;
  int posx;
  int posy;
  int points;
  MOVEMENT state;
  MOVEMENT intention;

  bool checkPosition(int x, int y) {
    return (posx == x && posy == y);
  }

  // Olha se o objeto está dentro da caixa central
  bool checkBox() {
    for (int i = 8; i < 11; i++) {
      for (int j = 21; j < 26; j++) {
        if (posy == i && posx == j) {
          return true;
        }
      }
    }

    return false;
  }

};

// Base dos Fantasmas
class GHOST {
public:
  ALLEGRO_BITMAP *entity;
  int posx;
  int posy;
  int state;

  void move() {
    // Confere o lado que ele está indo e se há outro lado disponível
    if (state == UP && (CIMA || ESQUERDA || DIREITA)) {
      // Sorteia um lado (pode ser o mesmo)
      state = rand() % 4;
      // Se for o lado oposto ou tem parede, sorteia de novo
      while (state == DOWN || !validState(state, posx, posy)) {
        state = rand() % 4;
      }
      // Confere o lado que ele está indo e se há outro lado disponível
    } else if (state == DOWN && (BAIXO || ESQUERDA || DIREITA)) {
      // Sorteia um lado (pode ser o mesmo)
      state = rand() % 4;
      // Se for o lado oposto ou tem parede, sorteia de novo
      while (state == UP || !validState(state, posx, posy)) {
        state = rand() % 4;
      }
      // Confere o lado que ele está indo e se há outro lado disponível
    } else if (state == LEFT && (CIMA || BAIXO || ESQUERDA)) {
      // Sorteia um lado (pode ser o mesmo)
      state = rand() % 4;
      // Se for o lado oposto ou tem parede, sorteia de novo
      while (state == RIGHT || !validState(state, posx, posy)) {
        state = rand() % 4;
      }
      // Confere o lado que ele está indo e se há outro lado disponível
    } else if (state == RIGHT && (CIMA || BAIXO || DIREITA)) {
      // Sorteia um lado (pode ser o mesmo)
      state = rand() % 4;
      // Se for o lado oposto ou tem parede, sorteia de novo
      while (state == LEFT || !validState(state, posx, posy)) {
        state = rand() % 4;
      }
    }

    // Altera a posição do fantasma
    switch (state) {
      case 0:
        posy--;
        break;
      case 1:
        posy++;
        break;
      case 2:
        posx--;
        break;
      case 3:
        posx++;
        break;
    }
  }

  void persegue(PACMAN pacman) {
    if (state == UP && (CIMA || ESQUERDA || DIREITA)) {
      if (pacman.posx > posx  && validState(RIGHT, posx, posy)) {
        state = RIGHT;
        } else if (pacman.posx < posx && validState(LEFT, posx, posy)) {
          state = LEFT;
        } else if (validState(UP, posx, posy)){
          state = UP;
        } else {
          state = DOWN;
        }
    } else if (state == DOWN && (BAIXO || ESQUERDA || DIREITA)) {
        if (pacman.posx > posx && validState(RIGHT, posx, posy)) {
          state = RIGHT;
          } else if (pacman.posx < posx && validState(LEFT, posx, posy)) {
              state = LEFT;
          } else if (validState(DOWN, posx, posy)){
              state = DOWN;
          } else {
              state = UP;
          }
    } else if (state == LEFT && (CIMA || BAIXO || ESQUERDA)) {
        if (pacman.posy > posy && validState(DOWN, posx, posy)) {
          state = DOWN;
        } else if (pacman.posy < posy && validState(UP, posx, posy)) {
            state = UP;
        } else if (validState(LEFT, posx, posy)) {
            state = LEFT;
        } else {
            state = RIGHT;
        }
    } else if (state == RIGHT && (CIMA || BAIXO || DIREITA)) {
        if (pacman.posy > posy && validState(DOWN, posx, posy)) {
          state = DOWN;
        } else if (pacman.posy < posy && validState(UP, posx, posy)) {
            state = UP;
        } else if (validState(RIGHT, posx, posy)){
            state = RIGHT;
        } else {
            state = LEFT;
          }
      }
      // Altera a posição do fantasma
    switch (state) {
      case 0:
        posy--;
        break;
      case 1:
        posy++;
        break;
      case 2:
        posx--;
        break;
      case 3:
        posx++;
        break;
    }
}

  // Olha se o objeto está dentro da caixa central
  bool checkBox() {
    for (int i = 8; i < 11; i++) {
      for (int j = 21; j < 26; j++) {
        if (posy == i && posx == j) {
          return true;
        }
      }
    }

    return false;
  }

};

//Elementos comuns
ALLEGRO_DISPLAY *display = nullptr;
ALLEGRO_BITMAP *tile = nullptr;
ALLEGRO_BITMAP *wall = nullptr;
ALLEGRO_BITMAP *pill = nullptr;
ALLEGRO_BITMAP *logo = nullptr;
ALLEGRO_AUDIO_STREAM *musica = nullptr;
ALLEGRO_SAMPLE *sample = nullptr;
ALLEGRO_SAMPLE *sample2 = nullptr;
ALLEGRO_SAMPLE *sample3 = nullptr;
ALLEGRO_SAMPLE *sample4 = nullptr;
ALLEGRO_SAMPLE *sample5 = nullptr;
ALLEGRO_FONT *font = nullptr;
ALLEGRO_TIMER *timer = nullptr;
ALLEGRO_EVENT_QUEUE *queue = nullptr;
ALLEGRO_EVENT event;

//Fantasmas
GHOST blue = {nullptr, 24, 9, 0};
GHOST pink = {nullptr, 21, 9, 0};
GHOST orange = {nullptr, 25, 9, 0};
GHOST red = {nullptr, 22, 9, 0};

//Pacman
PACMAN pacman = {nullptr, 23, 14, 0, NONE, NONE};

// Auxiliares
char buffer[100];
int pills = 0;

int main(int argc, char **argv) {
  // Auxiliares
  int animation = 0;
  int screen = REDRAW;

  // Se der algum erro de inicialização, fecha o programa.
  if (begin() == -1) {
      return -1;
  }

  // Loop do jogo
  while (true) {
    // Espera por um evento
    al_wait_for_event(queue, &event);

    srand(time(NULL));


    if(pacman.checkPosition(blue.posx, blue.posy) || pacman.checkPosition(orange.posx, orange.posy) ||
      pacman.checkPosition(pink.posx, pink.posy) || pacman.checkPosition(red.posx, red.posy))  {
      cout << "Perdeu!" << endl;
      lost();
      break;
    }

    /*if(pacman.checkPosition(blue.posx, blue.posy) || pacman.checkPosition(orange.posx, orange.posy) ||
      pacman.checkPosition(pink.posx, pink.posy) || pacman.checkPosition(red.posx, red.posy) ||
      pacman.checkPosition(blue.posx + 1, blue.posy) || pacman.checkPosition(blue.posx, blue.posy + 1) ||
      pacman.checkPosition(orange.posx + 1, orange.posy) || pacman.checkPosition(orange.posx, orange.posx + 1) ||
      pacman.checkPosition(pink.posx + 1, pink.posx) || pacman.checkPosition(pink.posx, pink.posy + 1) ||
      pacman.checkPosition(red.posx + 1, red.posy) || pacman.checkPosition(red.posx, red.posy + 1))  {
      cout << "Perdeu!" << endl;
      lost();
      break;
    }*/

    al_attach_audio_stream_to_mixer(musica, al_get_default_mixer());
    al_set_audio_stream_playing(musica, true);

    // Se apertou o x da janela ou o botão ESC, fecha o jogo
    if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE || (event.type == ALLEGRO_EVENT_KEY_UP && event.keyboard.keycode == ALLEGRO_KEY_ESCAPE)) {
      break;
    } else if (event.type == ALLEGRO_EVENT_TIMER) {

            // Se a intenção de movimento do Pacman puder acontecer, muda a direção para ela
      if (pacman.intention == UP && validState(UP, pacman.posx, pacman.posy)) {
        pacman.state = UP;
      } else if (pacman.intention == DOWN && validState(DOWN, pacman.posx, pacman.posy)) {
        pacman.state = DOWN;
      } else if (pacman.intention == LEFT && validState(LEFT, pacman.posx, pacman.posy)) {
        pacman.state = LEFT;
      } else if (pacman.intention == RIGHT && validState(RIGHT, pacman.posx, pacman.posy)) {
        pacman.state = RIGHT;
      }

      // Se o Pacman não puder se mover para o lado pretendido, para.
      if (MAPA[pacman.posy-1][pacman.posx] == '0' && pacman.state == UP) {
        pacman.state = NONE;
      } else if (MAPA[pacman.posy+1][pacman.posx] == '0' && pacman.state == DOWN) {
        pacman.state = NONE;
      } else if (MAPA[pacman.posy][pacman.posx-1] =='0' && pacman.state == LEFT) {
        pacman.state = NONE;
      } else if (MAPA[pacman.posy][pacman.posx+1] == '0' && pacman.state == RIGHT) {
        pacman.state = NONE;
      }

      // Muda a posição se estiver nos túneis
      swap(blue.posx, blue.posy);
      swap(pacman.posx, pacman.posy);
      swap(pink.posx, pink.posy);
      swap(red.posx, red.posy);
      swap(orange.posx, orange.posy);

      // Move os Fantasmas
      blue.move();
      orange.persegue(pacman);
      pink.move();
      red.move();

    if(pacman.checkPosition(blue.posx, blue.posy) || pacman.checkPosition(orange.posx, orange.posy) ||
      pacman.checkPosition(pink.posx, pink.posy) || pacman.checkPosition(red.posx, red.posy))  {
      cout << "Perdeu!" << endl;
      lost();
      break;
    }
      // Confere se a posição que o pacman está é uma pílula
      if (MAPA[pacman.posy][pacman.posx] == '2') {
        MAPA[pacman.posy][pacman.posx] = '1';
        pacman.points++;
      }

      // Altera a posição do Pacman e contabiliza os pontos
      if (pacman.state == UP) {
        if (MAPA[pacman.posy-1][pacman.posx] == '2') {
          MAPA[pacman.posy-1][pacman.posx] = '1';
          pacman.points++;
        }
        pacman.entity = al_load_bitmap("resources/pacs/pacman_up.png");
        pacman.posy -= 1;
      } else if (pacman.state == DOWN) {
        if (MAPA[pacman.posy+1][pacman.posx] == '2') {
          MAPA[pacman.posy+1][pacman.posx] = '1';
          pacman.points++;
        }
        pacman.entity = al_load_bitmap("resources/pacs/pacman_down.png");
        pacman.posy += 1;
      } else if (pacman.state == LEFT) {
        if (MAPA[pacman.posy][pacman.posx-1] == '2') {
          MAPA[pacman.posy][pacman.posx-1] = '1';
          pacman.points++;
        }
        pacman.entity = al_load_bitmap("resources/pacs/pacman_left.png");
        pacman.posx -= 1;
      } else if (pacman.state == RIGHT) {
        if (MAPA[pacman.posy][pacman.posx+1] == '2') {
          MAPA[pacman.posy][pacman.posx+1] = '1';
          pacman.points++;
        }
        pacman.entity = al_load_bitmap("resources/pacs/pacman_right.png");
        pacman.posx += 1;
      }

      screen = REDRAW;

      // Salva os pontos do pacman como string na variável buffer
      sprintf(buffer, "Pontos: %d", pacman.points);

      // Se ele recolher todas as pílulas, o jogo acaba
      if (pacman.points == pills) {
        al_destroy_audio_stream(musica);
  	al_play_sample(sample2, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
  	end();
  	break;
      }
    } else if (event.type == ALLEGRO_EVENT_KEY_DOWN) {
      // Muda a intenção de movimento do Pacman
      switch (event.keyboard.keycode) {
        case ALLEGRO_KEY_UP:
          pacman.intention = UP;
          break;
        case ALLEGRO_KEY_DOWN:
          pacman.intention = DOWN;
          break;
        case ALLEGRO_KEY_LEFT:
          pacman.intention = LEFT;
          break;
        case ALLEGRO_KEY_RIGHT:
          pacman.intention = RIGHT;
          break;
      }
    }

    // Se não houver nenhum objeto na caixa central, fecha ela
    if (!pacman.checkBox() && !blue.checkBox() && !orange.checkBox() && !pink.checkBox() && !red.checkBox()) {
      MAPA[7][23] = '0';
    }

    // Redesenha a tela
    if (screen == REDRAW && al_is_event_queue_empty(queue)) {

      screen = NOT_REDRAW;

      if (animation >= 4) {
        pacman.entity = al_load_bitmap("resources/pacs/pacman_full.png");
        animation = 0;
      }

      al_clear_to_color(al_map_rgb(0, 0, 0));

      drawPills();
      drawEntities();
      drawMap();

      al_draw_text(font, al_map_rgb(0,0,0), TEXT_POS[0] * CELL_SIZE, TEXT_POS[1] * CELL_SIZE, ALLEGRO_ALIGN_CENTRE, buffer);
      al_draw_bitmap(logo, LOGO_POS[0] * CELL_SIZE, LOGO_POS[1] * CELL_SIZE, 0);

      al_flip_display();

      animation++;
    }
  }

  // Destrói os elementos criados
  al_destroy_display(display);
  al_destroy_event_queue(queue);
  al_destroy_timer(timer);
  al_destroy_font(font);
  al_destroy_bitmap(tile);
  al_destroy_bitmap(pill);
  al_destroy_bitmap(logo);
  al_destroy_bitmap(pacman.entity);
  al_destroy_bitmap(red.entity);
  al_destroy_bitmap(blue.entity);
  al_destroy_bitmap(pink.entity);
  al_destroy_bitmap(orange.entity);
  al_destroy_sample(sample);
  al_destroy_sample(sample2);
  al_destroy_sample(sample3);
  al_destroy_sample(sample4);
  al_destroy_sample(sample5);

  return 0;
}

inline void drawPills() {
  for (int i = 0; i < MAP_H; i++) {
    for (int j = 0; j < MAP_W; j++) {
      if (MAPA[i][j] == '2') {
        al_draw_bitmap(pill, j * CELL_SIZE, i * CELL_SIZE, 0);
      }
    }
  }
}

inline void drawMap() {
  for (int i = 0; i < MAP_H; i++) {
    for (int j = 0; j < MAP_W; j++) {
      if (MAPA[i][j] == '3' || MAPA[i][j] == '0') {
        al_draw_bitmap(wall, j * CELL_SIZE, i * CELL_SIZE, 0);
      }
    }
  }

  for (int i = 1; i < MAP_H - 2; i++) {
    for (int j = 1; j < MAP_W - 3; j++) {
      if (MAPA[i][j] == '0') {
        al_draw_bitmap(tile, j * CELL_SIZE, i * CELL_SIZE, 0);
      }
    }
  }
}

inline void drawEntities() {
  al_draw_bitmap(pacman.entity, pacman.posx * CELL_SIZE, pacman.posy * CELL_SIZE, 0);
  al_draw_bitmap(blue.entity, blue.posx * CELL_SIZE, blue.posy * CELL_SIZE, 0);
  al_draw_bitmap(orange.entity, orange.posx * CELL_SIZE, orange.posy * CELL_SIZE, 0);
  al_draw_bitmap(pink.entity, pink.posx * CELL_SIZE, pink.posy * CELL_SIZE, 0);
  al_draw_bitmap(red.entity, red.posx * CELL_SIZE, red.posy * CELL_SIZE, 0);
}

// Checa se a posição recebida não é parede
bool validState(int state, int posx, int posy) {
  switch (state) {
    case UP:
      return MAPA[posy-1][posx] != '0';
    case DOWN:
      return MAPA[posy+1][posx] != '0';
    case LEFT:
      return MAPA[posy][posx-1] != '0';
    case RIGHT:
      return MAPA[posy][posx+1] != '0';
    default:
      return false;
  }
  return false;
}

// Muda a posição dos personagens que chegarem nos túneis
void swap(int &x, int &y) {
    if (y == 0 && x == 19) {
      y = 18;
      x = 19;
      return;
    }
    if (y == 18 && x == 19) {
      y = 0;
      x = 19;
      return;
    }
    if (y == 0 && x == 27) {
      y = 18;
      x = 27;
      return;
    }
    if (y == 18 && x == 27) {
      y = 0;
      x = 27;
      return;
    }
    if (y == 8 && x == 0) {
      y = 8;
      x = 46;
      return;
    }
    if (y == 8 && x == 46) {
      y = 8;
      x = 0;
      return;
    }
    if (y == 10 && x == 46) {
      y = 10;
      x = 0;
      return;
    }
    if (y == 10 && x == 0) {
      y = 10;
      x = 46;
    }
}

void end() {

  for (int i = 0; i < 3; i++) {
    al_clear_to_color(al_map_rgb(0, 0, 0));

    al_set_target_bitmap(tile);
    al_clear_to_color(al_map_rgb(255, 255, 255));
    al_set_target_bitmap(al_get_backbuffer(display));

    drawEntities();
    drawMap();

    al_draw_text(font, al_map_rgb(0,0,0), 22 * CELL_SIZE, 0 * CELL_SIZE, ALLEGRO_ALIGN_CENTRE, buffer);

    al_flip_display();

    al_rest(1);

    al_clear_to_color(al_map_rgb(0, 0, 0));

    al_set_target_bitmap(tile);
    al_clear_to_color(al_map_rgb(52, 99, 16));
    al_set_target_bitmap(al_get_backbuffer(display));

    drawEntities();
    drawMap();

    al_draw_text(font, al_map_rgb(0,0,0), 22 * CELL_SIZE, 0 * CELL_SIZE, ALLEGRO_ALIGN_CENTRE, buffer);

    al_flip_display();

    al_rest(1);
  }
}

void lost() {
  if (pacman.checkPosition(blue.posx, blue.posy) || pacman.checkPosition(blue.posx + 1, blue.posy) || pacman.checkPosition(blue.posx, blue.posy + 1)) {
    al_destroy_audio_stream(musica);
    al_play_sample(sample5, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
    al_rest(2.6);
  } else if (pacman.checkPosition(orange.posx, orange.posy) || pacman.checkPosition(orange.posx + 1, orange.posy) || pacman.checkPosition(orange.posx, orange.posx + 1)) {
    al_destroy_audio_stream(musica);
    al_play_sample(sample, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
    al_rest(2.3);
  } else if (pacman.checkPosition(pink.posx, pink.posy) || pacman.checkPosition(pink.posx + 1, pink.posx) || pacman.checkPosition(pink.posx, pink.posy + 1)) {
    al_destroy_audio_stream(musica);
    al_play_sample(sample4, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
    al_rest(8.7);
  } else if (pacman.checkPosition(red.posx, red.posy) || pacman.checkPosition(red.posx + 1, red.posy) || pacman.checkPosition(red.posx, red.posy + 1)) {
    al_destroy_audio_stream(musica);
    al_play_sample(sample3, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
    al_rest(3.2);
  }
}

int begin() {
  if (!al_init()) {
    cout << "Falha ao iniciar Allegro" << endl;
    return -1;
  }

  if (!al_install_keyboard()) {
    cout << "Falha ao iniciar teclado" << endl;
    return -1;
  }

  if (!al_init_image_addon()) {
    cout << "Falha ao iniciar al_init_image_addon!" << endl;
    return -1;
  }

  if (!al_init_font_addon()) {
    cout << "Falha ao iniciar al_init_font_addon" << endl;
    return -1;
  }

  if (!al_init_ttf_addon()) {
    cout << "Falha ao iniciar al_init_ttf_addon" << endl;
    return -1;
  }

  if (!al_install_audio()) {
		cout << "Falha ao carregar o audio" << endl;
		return -1;
	}

	if (!al_init_acodec_addon()) {
		cout << "Falha ao carregar codecs de audio" << endl;
		return -1;
	}

	if (!al_reserve_samples(1)) {
		cout << "Falha ao carregar canais de audio" << endl;
		return -1;
}

  queue = al_create_event_queue();
  if (!queue) {
    cout << "Falha ao criar fila de eventos" << endl;
    al_destroy_event_queue(queue);
    return -1;
  }

  timer = al_create_timer(FPS);
  if (!timer) {
    cout << "Falha ao criar temporizador" << endl;
    al_destroy_event_queue(queue);
    al_destroy_timer(timer);
    return -1;
  }

  font = al_load_ttf_font("resources/misc/VCR_OSD_MONO_1.001.ttf", 20, 0);
  if(!font) {
    cout << "Falha ao carregar a fonte" << endl;
    al_destroy_event_queue(queue);
    al_destroy_timer(timer);
    al_destroy_font(font);
    return -1;
  }

  display = al_create_display(DISPLAY_W, DISPLAY_H);
  if (!display) {
    cout << "Falha ao criar a tela" << endl;
    al_destroy_event_queue(queue);
    al_destroy_timer(timer);
    al_destroy_font(font);
    al_destroy_display(display);
    return -1;
  }
  al_set_window_title(display, "PACMAN");

  tile = al_create_bitmap(20, 20);
  if (!tile) {
    cout << "Falha ao carregar parede" << endl;
    al_destroy_event_queue(queue);
    al_destroy_timer(timer);
    al_destroy_font(font);
    al_destroy_display(display);
    al_destroy_bitmap(tile);
    return -1;
  }

  al_set_target_bitmap(tile);
  al_clear_to_color(al_map_rgb(52, 99, 16));
  al_set_target_bitmap(al_get_backbuffer(display));
  wall = al_create_bitmap(20, 20);
  if (!wall) {
    cout << "Falha ao carregar borda" << endl;
    al_destroy_event_queue(queue);
    al_destroy_timer(timer);
    al_destroy_font(font);
    al_destroy_display(display);
    al_destroy_bitmap(tile);
    al_destroy_bitmap(wall);
    return -1;
  }

  al_set_target_bitmap(wall);
  al_clear_to_color(al_map_rgb(255, 255, 255));
  al_set_target_bitmap(al_get_backbuffer(display));

  pill = al_load_bitmap("resources/misc/pill.png");
  if (!pill) {
    cout << "Falha ao carregar pílulas" << endl;
    al_destroy_event_queue(queue);
    al_destroy_timer(timer);
    al_destroy_font(font);
    al_destroy_display(display);
    al_destroy_bitmap(tile);
    al_destroy_bitmap(wall);
    al_destroy_bitmap(pill);
    return -1;
  }

  logo = al_load_bitmap("resources/misc/logo.png");
  if (!logo) {
    cout << "Falha ao carregar logo" << endl;
    al_destroy_event_queue(queue);
    al_destroy_timer(timer);
    al_destroy_font(font);
    al_destroy_display(display);
    al_destroy_bitmap(tile);
    al_destroy_bitmap(wall);
    al_destroy_bitmap(pill);
    al_destroy_bitmap(logo);
    return -1;
  }

  pacman.entity = al_load_bitmap("resources/pacs/pacman_full.png");
  if (!pacman.entity) {
    cout << "Falha ao carregar o pacman" << endl;
    al_destroy_display(display);
    al_destroy_event_queue(queue);
    al_destroy_timer(timer);
    al_destroy_font(font);
    al_destroy_display(display);
    al_destroy_bitmap(tile);
    al_destroy_bitmap(pill);
    al_destroy_bitmap(wall);
    al_destroy_bitmap(logo);
    al_destroy_bitmap(pacman.entity);
    return -1;
  }

  red.entity = al_load_bitmap("resources/ghosts/red.png");
  if (!red.entity) {
    cout << "Falha ao carregar fantasma vermelho" << endl;
    al_destroy_display(display);
    al_destroy_event_queue(queue);
    al_destroy_timer(timer);
    al_destroy_font(font);
    al_destroy_display(display);
    al_destroy_bitmap(tile);
    al_destroy_bitmap(wall);
    al_destroy_bitmap(pill);
    al_destroy_bitmap(logo);
    al_destroy_bitmap(pacman.entity);
    al_destroy_bitmap(red.entity);
    return -1;
  }

  blue.entity = al_load_bitmap("resources/ghosts/blue.png");
  if (!blue.entity) {
    cout << "Falha ao carregar fantasma azul" << endl;
    al_destroy_display(display);
    al_destroy_event_queue(queue);
    al_destroy_timer(timer);
    al_destroy_font(font);
    al_destroy_display(display);
    al_destroy_bitmap(tile);
    al_destroy_bitmap(wall);
    al_destroy_bitmap(pill);
    al_destroy_bitmap(logo);
    al_destroy_bitmap(pacman.entity);
    al_destroy_bitmap(red.entity);
    al_destroy_bitmap(blue.entity);
    return -1;
  }

  pink.entity = al_load_bitmap("resources/ghosts/pink.png");
  if (!pink.entity) {
    cout << "Falha ao carregar fanstasma rosa" << endl;
    al_destroy_display(display);
    al_destroy_event_queue(queue);
    al_destroy_timer(timer);
    al_destroy_font(font);
    al_destroy_display(display);
    al_destroy_bitmap(tile);
    al_destroy_bitmap(wall);
    al_destroy_bitmap(pill);
    al_destroy_bitmap(logo);
    al_destroy_bitmap(pacman.entity);
    al_destroy_bitmap(red.entity);
    al_destroy_bitmap(blue.entity);
    al_destroy_bitmap(pink.entity);
    return -1;
  }

  orange.entity = al_load_bitmap("resources/ghosts/orange.png");
  if (!orange.entity) {
    cout << "Falha ao carregar fantasma laranja" << endl;
    al_destroy_display(display);
    al_destroy_event_queue(queue);
    al_destroy_timer(timer);
    al_destroy_font(font);
    al_destroy_display(display);
    al_destroy_bitmap(tile);
    al_destroy_bitmap(wall);
    al_destroy_bitmap(pill);
    al_destroy_bitmap(logo);
    al_destroy_bitmap(pacman.entity);
    al_destroy_bitmap(red.entity);
    al_destroy_bitmap(blue.entity);
    al_destroy_bitmap(pink.entity);
    al_destroy_bitmap(orange.entity);
    return -1;
  }

  sample = al_load_sample("resources/sounds/queima1.wav");
	if (!sample) {
		cout << "Falha ao carregar o sample" << endl;
		al_destroy_display(display);
		al_destroy_event_queue(queue);
		al_destroy_timer(timer);
		al_destroy_font(font);
		al_destroy_display(display);
		al_destroy_bitmap(tile);
		al_destroy_bitmap(pill);
    al_destroy_bitmap(logo);
		al_destroy_bitmap(pacman.entity);
		al_destroy_bitmap(red.entity);
		al_destroy_bitmap(blue.entity);
		al_destroy_bitmap(pink.entity);
		al_destroy_bitmap(orange.entity);
		al_destroy_sample(sample);
		return -1;
	}

	sample2 = al_load_sample("resources/sounds/winner.wav");
	if (!sample2) {
		cout << "Falha ao carregar o sample" << endl;
		al_destroy_display(display);
		al_destroy_event_queue(queue);
		al_destroy_timer(timer);
		al_destroy_font(font);
		al_destroy_display(display);
		al_destroy_bitmap(tile);
		al_destroy_bitmap(pill);
    al_destroy_bitmap(logo);
		al_destroy_bitmap(pacman.entity);
		al_destroy_bitmap(red.entity);
		al_destroy_bitmap(blue.entity);
		al_destroy_bitmap(pink.entity);
		al_destroy_bitmap(orange.entity);
		al_destroy_sample(sample);
		al_destroy_sample(sample2);
		return -1;
	}

	sample3 = al_load_sample("resources/sounds/cotada.wav");
	if (!sample3) {
		cout << "Falha ao carregar o sample" << endl;
		al_destroy_display(display);
		al_destroy_event_queue(queue);
		al_destroy_timer(timer);
		al_destroy_font(font);
		al_destroy_display(display);
		al_destroy_bitmap(tile);
		al_destroy_bitmap(pill);
    al_destroy_bitmap(logo);
		al_destroy_bitmap(pacman.entity);
		al_destroy_bitmap(red.entity);
		al_destroy_bitmap(blue.entity);
		al_destroy_bitmap(pink.entity);
		al_destroy_bitmap(orange.entity);
		al_destroy_sample(sample);
		al_destroy_sample(sample2);
		al_destroy_sample(sample3);
		return -1;
	}

	sample4 = al_load_sample("resources/sounds/inimigo.wav");
	if (!sample4) {
		cout << "Falha ao carregar o sample" << endl;
		al_destroy_display(display);
		al_destroy_event_queue(queue);
		al_destroy_timer(timer);
		al_destroy_font(font);
		al_destroy_display(display);
		al_destroy_bitmap(tile);
		al_destroy_bitmap(pill);
    al_destroy_bitmap(logo);
		al_destroy_bitmap(pacman.entity);
		al_destroy_bitmap(red.entity);
		al_destroy_bitmap(blue.entity);
		al_destroy_bitmap(pink.entity);
		al_destroy_bitmap(orange.entity);
		al_destroy_sample(sample);
		al_destroy_sample(sample2);
		al_destroy_sample(sample3);
		al_destroy_sample(sample4);
		return -1;
	}

	sample5 = al_load_sample("resources/sounds/pepita.wav");
	if (!sample5) {
		cout << "Falha ao carregar o sample" << endl;
		al_destroy_display(display);
		al_destroy_event_queue(queue);
		al_destroy_timer(timer);
		al_destroy_font(font);
		al_destroy_display(display);
		al_destroy_bitmap(tile);
		al_destroy_bitmap(pill);
    al_destroy_bitmap(logo);
		al_destroy_bitmap(pacman.entity);
		al_destroy_bitmap(red.entity);
		al_destroy_bitmap(blue.entity);
		al_destroy_bitmap(pink.entity);
		al_destroy_bitmap(orange.entity);
		al_destroy_sample(sample);
		al_destroy_sample(sample2);
		al_destroy_sample(sample3);
		al_destroy_sample(sample4);
		al_destroy_sample(sample5);
		return -1;
	}

	musica = al_load_audio_stream("resources/sounds/musica.ogg", 4, 1024);
	if (!musica) {
		cout << "Falha ao carregar o audio" << endl;
		al_destroy_display(display);
		al_destroy_event_queue(queue);
		al_destroy_timer(timer);
		al_destroy_font(font);
		al_destroy_display(display);
		al_destroy_bitmap(tile);
		al_destroy_bitmap(pill);
    al_destroy_bitmap(logo);
		al_destroy_bitmap(pacman.entity);
		al_destroy_bitmap(red.entity);
		al_destroy_bitmap(blue.entity);
		al_destroy_bitmap(pink.entity);
		al_destroy_bitmap(orange.entity);
		al_destroy_sample(sample);
		al_destroy_sample(sample2);
		al_destroy_sample(sample3);
		al_destroy_sample(sample4);
		al_destroy_sample(sample5);
		al_destroy_audio_stream(musica);
		return -1;
}

  al_register_event_source(queue, al_get_keyboard_event_source());
  al_register_event_source(queue, al_get_display_event_source(display));
  al_register_event_source(queue, al_get_timer_event_source(timer));

  al_start_timer(timer);

  for (int i = 0; i < MAP_H; i++) {
    for (int j = 0; j < MAP_W; j++) {
      if (MAPA[i][j] == '2') {
        pills++;
      }
    }
  }

  drawPills();
  drawEntities();
  drawMap();

  al_draw_text(font, al_map_rgb(0,0,0), TEXT_POS[0] * CELL_SIZE, TEXT_POS[1] * CELL_SIZE, ALLEGRO_ALIGN_CENTRE, buffer);
  al_draw_bitmap(logo, LOGO_POS[0] * CELL_SIZE, LOGO_POS[1] * CELL_SIZE, 0);

  al_flip_display();

  return 0;
}
