#ifndef _FASES_H_
#define _FASES_H_

#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>


#define LARGURA_JANELA 1000
#define ALTURA_JANELA 620
#define FPS 60
#define SPRITEFPS 30

typedef struct bloco{
	SDL_Texture* loadBloco;
	//struct listaB* prox;
}Bloco;
typedef struct heroi{
	SDL_Texture* loadBloco;
	//struct listaB* prox;
}Heroi;

typedef struct posicaoBloco{
	SDL_Rect loadRect;
}PosicaoBloco;

typedef struct posicaoHeroi{
	SDL_Rect loadRect;
}PosicaoHeroi;


int GATODOWN = 0;
int GATOUP = 0;
int LEFTBLOCK = 0;
int GATOJUMPRIGHT = 0;
int BIGBLOCO1AR = 0;
int LIMITD;
//int CONT = 0;

	SDL_Texture *carregarTextura(SDL_Renderer *render,char *pathImage);
	void controlFrameRate(Uint32 inicioGetTick);
	void sprite(Uint32 inicioGetTick);
	//void continuarMovimentoCatJoe(SDL_Rect* catJoePosicao, SDL_Rect* catPosicao, int* chegouTetoBlocoLeft);
	//void teclaUP(SDL_Rect* catJoePosicao, SDL_Rect* catPosicao, int* chegouTetoBlocoLeft);
	void teclaRight_DontUP(SDL_Rect* catJoePosicao, SDL_Rect* catPosicao,int* bloco1X);
	void movimentoBlocoNoAr(SDL_Rect* obstaculosPosicao, int* chegouFlutua);
	void encerrarJogo(SDL_Event event, int* fechar);
	void renderCopySprites(SDL_Renderer* renderer, Bloco* bl, PosicaoBloco* pb, int qtdLoop);

#endif