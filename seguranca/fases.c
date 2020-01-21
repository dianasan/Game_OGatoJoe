#include "fases.h"


SDL_Texture *carregarTextura(SDL_Renderer *render,char *pathImage){

	SDL_Surface *imagem = NULL;
	SDL_Texture *texturaFuncao = NULL;
	imagem = IMG_Load(pathImage);

	
	if(imagem == NULL){
		printf("Erro na imagem da funcao texture %s\n",IMG_GetError());
		printf("O caminho e: %s\n",pathImage);
	}else{
		texturaFuncao = SDL_CreateTextureFromSurface(render,imagem);
		if(texturaFuncao == NULL){
			printf("Erro na textura da funcao %s\n",SDL_GetError());
		}else{	
			SDL_FreeSurface(imagem);//liberar a surface :)
			imagem = NULL;
			return texturaFuncao;
		}
	}	
}

void controlFrameRate(Uint32 inicioGetTick){
	if( (1000 / FPS) > SDL_GetTicks() - inicioGetTick){
		SDL_Delay((1000 / FPS) - (SDL_GetTicks() - inicioGetTick));
	}
}
void sprite(Uint32 inicioGetTick){
	if( (1000 / SPRITEFPS) > SDL_GetTicks() - inicioGetTick){
		SDL_Delay((1000 / SPRITEFPS) - (SDL_GetTicks() - inicioGetTick));
	}
}

void encerrarJogo(SDL_Event event, int* fechar){

	if(event.type == SDL_QUIT){
		*fechar = 1;
	}

	if(event.type == SDL_KEYUP && event.key.keysym.sym == SDLK_ESCAPE){
		*fechar = 1;
	}
}

void renderCopySprites(SDL_Renderer* renderer, Bloco* bl, PosicaoBloco* pb, int qtdLoop){

	for(int i = 0; i < qtdLoop; i++){
		SDL_RenderCopy(renderer,bl[i].loadBloco,NULL,&pb[i].loadRect);
	}
}

int lazyFoo(SDL_Rect a, SDL_Rect b){

	//The sides of the rectangles
    int leftA, leftB;
    int rightA, rightB;
    int topA, topB;
    int bottomA, bottomB;

    //Calculate the sides of rect A
    leftA = a.x + 20;
    a.w = 72;
    rightA = a.x + a.w;
    topA = a.y;
    a.h = 91;
    bottomA = a.y + a.h;

    //Calculate the sides of rect B
    leftB = b.x;
    rightB = b.x + b.w;
    topB = b.y;
    bottomB = b.y + b.h;

    if( bottomA <= topB )
    {
        return 0;
    }

    if( topA >= bottomB )
    {
        return 0;
    }

    if( rightA <= leftB )
    {
        return 0;
    }

    if( leftA >= rightB )
    {
        return 0;
    }

    //If none of the sides from A are outside B
    return 1;	
}

void emma(SDL_Rect* dRectGatoJoe, SDL_Rect* sRectGatoJoe,SDL_Rect a,SDL_Rect b){
	//523
	if(dRectGatoJoe->x >= 529 && dRectGatoJoe->x <= 668 && dRectGatoJoe->y > 90){
		printf("Is HERE!\n");
		//SETAR PARA 0 VARIAVEL BATEU_BL2 PARA FUNCIONAR CORRETAMENTE
			//BATEU_BL2 = 0;

		//INÍCIO DA FUNÇÃO DE JUMP DO BLOCORIGHT2	
		if(dRectGatoJoe->y > b.y){
			if(lazyFoo(a,b)){
				dRectGatoJoe->y += 6;
			}

			if(lazyFoo(a,b) && BATEU_BL != 1){
				BATEU_BL = 1;
				dRectGatoJoe->y += 6;
			}else if(!(lazyFoo(a,b)) && BATEU_BL != 1){
				dRectGatoJoe->y -= 3;
				
			}else if(BATEU_BL != 0){

				if(dRectGatoJoe->y >= 492){
					
					dRectGatoJoe->y = 492;
					BATEU_BL = 0;
					GATOUP = 0;
				}else{
					dRectGatoJoe->y += 6;
				}
			}
		}
		else if(dRectGatoJoe->y < b.y){
			if(dRectGatoJoe->y > 217&& BATEU_BL != 1){
			
				if(dRectGatoJoe->y <= 217)
					BATEU_BL = 1;
				dRectGatoJoe->y -= 3;

				

			}else if(dRectGatoJoe->y <= 217 && BATEU_BL != 1){
				
				BATEU_BL = 1;
			}
					
			else if(BATEU_BL != 0){
				
				dRectGatoJoe->y += 3;

				if(dRectGatoJoe->y > 327){
					dRectGatoJoe->y = 327;
					BATEU_BL = 0;
					GATOUP = 0;
				}
					
			}
		}

		
	}
	
}

void snow(SDL_Rect* dRectGatoJoe, SDL_Rect* sRectGatoJoe,SDL_Rect a,SDL_Rect b){
	
	if(dRectGatoJoe->x >= 449 && dRectGatoJoe->x <= 528){//515

		if(dRectGatoJoe->y > 262 && BATEU_BL2 != 1){
			
				if(dRectGatoJoe->y <= 262)
					BATEU_BL2 = 1;
				dRectGatoJoe->y -= 3;
				if(dRectGatoJoe->x > 516 && dRectGatoJoe->y > 327)
					dRectGatoJoe->x -= 10;				

			}else if(dRectGatoJoe->y <= 262 && BATEU_BL2 != 1){
				
				BATEU_BL2 = 1;

			}
					
			else if(BATEU_BL2 != 0){
				
				dRectGatoJoe->y += 3;
				if(dRectGatoJoe->x > 516 && dRectGatoJoe->y > 327)
					dRectGatoJoe->x -= 10;

				if(dRectGatoJoe->y > 432){
					dRectGatoJoe->y = 432;
					BATEU_BL2 = 0;
					GATOUP = 0;
				}
					
			}

			
		
	}
}



void henry(SDL_Rect* dRectGatoJoe){

	if(!((dRectGatoJoe->x >= 449 && dRectGatoJoe->x <= 529) || (dRectGatoJoe->x >= 526 && dRectGatoJoe->x <= 668) || (dRectGatoJoe->x >= 197 && dRectGatoJoe->x <= 330 && PODEDESCER) || (dRectGatoJoe->x >= 0 && dRectGatoJoe->x <= 214 && !PODEDESCER) || (dRectGatoJoe->x >= 0 && dRectGatoJoe->x <= 196 && PODEDESCER) || (dRectGatoJoe->x >= 570 && dRectGatoJoe->y <= 96 && PODEDESCER))){
		printf("BLOQUEIA CAT\n");
		if(BLOQUEIA_CAT){

		}else{

			dRectGatoJoe->y += 3;
			if(dRectGatoJoe->y >= 492){
				dRectGatoJoe->y = 492;
				BATEU_BL3 = 0;
			}



		}

		
	}
}

void regina(SDL_Rect* dRectGatoJoe, SDL_Rect* sRectGatoJoe,SDL_Rect a,SDL_Rect b){
	
	if(dRectGatoJoe->x > 323 && dRectGatoJoe->x < 526){//>=392
		if(lazyFoo(a,b) && dRectGatoJoe->y < 327){
			dRectGatoJoe->y += 3;
		}else if(dRectGatoJoe->y >= 327 && lazyFoo(a,b)){
			dRectGatoJoe->y = 327;
			BLOQUEIA_CAT = 1;
			PODEANDAR = 1;
		}
	}
}

void zangado(SDL_Rect* dRectGatoJoe, SDL_Rect* sRectGatoJoe,SDL_Rect a,SDL_Rect b){

	if(dRectGatoJoe->y <= 432 && dRectGatoJoe->y >= 328 && dRectGatoJoe->x < 590 && lazyFoo(a,b)){
		dRectGatoJoe->x -= 6;
	}
	else if(dRectGatoJoe->y <= 459 && dRectGatoJoe->y >= 328 && dRectGatoJoe->x >= 590 && lazyFoo(a,b)){
		dRectGatoJoe->x += 6;
	}

}

void soneca(SDL_Rect* dRectGatoJoe, SDL_Rect* sRectGatoJoe,SDL_Rect a,SDL_Rect b){
	
	if(lazyFoo(a,b) && dRectGatoJoe->x > 484)
		dRectGatoJoe->x += 6;
	else if(lazyFoo(a,b) && dRectGatoJoe->x < 484)
		dRectGatoJoe->x -= 6;
}

void soneca_Right(SDL_Rect* dRectGatoJoe,SDL_Rect a,SDL_Rect b){
	printf("AQUUUUUUU\n");
	if(lazyFoo(a,b) && dRectGatoJoe->x < 484)
		dRectGatoJoe->x -= 6;
	else if(lazyFoo(a,b) && dRectGatoJoe->x > 484)
		dRectGatoJoe->x += 6;
}

void thor(SDL_Rect* dRectGatoJoe,SDL_Rect a,SDL_Rect b){

	if(lazyFoo(a,b) && dRectGatoJoe->x < 590)
		dRectGatoJoe->x -= 6;
	else if(lazyFoo(a,b) && dRectGatoJoe->x > 590)
		dRectGatoJoe->x += 6;
}

void moveSpriteCatRight(SDL_Rect* sRectGatoJoe){

	//catPosicao

	sRectGatoJoe->y = 100;
	sRectGatoJoe->x += 100;
	if(sRectGatoJoe->x >= 1000){
		sRectGatoJoe->x = 100;
	}
}
void moveSpriteCatLeft(SDL_Rect* sRectGatoJoe){

	if(sRectGatoJoe->y < 900){
		sRectGatoJoe->y = 900;
	}									
	
	if(sRectGatoJoe->x <= 0){
		sRectGatoJoe->x = 1000;
	}
	sRectGatoJoe->x -= 100;
}

void pularMaisAlto_Left(SDL_Rect* dRectGatoJoe){

	if(!((dRectGatoJoe->x >= 449 && dRectGatoJoe->x <= 523) || (dRectGatoJoe->x >= 526 && dRectGatoJoe->x <= 668) || ( dRectGatoJoe->x >= 0 && dRectGatoJoe->x <= 196) || (dRectGatoJoe->x >= 197 && dRectGatoJoe->x <= 330) || (dRectGatoJoe->x >= 668 && PODEDESCER))  && dRectGatoJoe->y < 492){
		dRectGatoJoe->x -= 6;
	}else{

		dRectGatoJoe->x -= 3;
	}
}
void pularMaisAlto_Right(SDL_Rect* dRectGatoJoe){

	if(!((dRectGatoJoe->x >= 449 && dRectGatoJoe->x <= 523) || (dRectGatoJoe->x >= 526 && dRectGatoJoe->x <= 668) || ( dRectGatoJoe->x >= 0 && dRectGatoJoe->x <= 196) || (dRectGatoJoe->x >= 197 && dRectGatoJoe->x <= 330) || (dRectGatoJoe->x >= 668 && PODEDESCER) ) && dRectGatoJoe->y < 492){
		printf("GELAAAAAAAADA!");
		dRectGatoJoe->x += 6;

	}else{

		dRectGatoJoe->x += 3;
	}
}



void wonderWoman(SDL_Rect* dRectGatoJoe,SDL_Rect a,SDL_Rect b){

	if(dRectGatoJoe->y <= 426 && dRectGatoJoe->y >= 291 && dRectGatoJoe->x < 235 && lazyFoo(a,b)){
		//printf("Ne Possivel\n");
		dRectGatoJoe->x += 6;
	}

}

void arrow(SDL_Rect* dRectGatoJoe,SDL_Rect a,SDL_Rect b){

	if(PODEDESCER){
		if(dRectGatoJoe->x >= 197 && dRectGatoJoe->x <= 330){
			if(dRectGatoJoe->y > 217 && BATEU_BL != 1){
				
				if(dRectGatoJoe->y <= 217)
					BATEU_BL = 1;
				dRectGatoJoe->y -= 3;

				

			}else if(dRectGatoJoe->y <= 217 && BATEU_BL != 1){
				
				BATEU_BL = 1;
			}
					
			else if(BATEU_BL != 0){
				
				dRectGatoJoe->y += 3;

				if(dRectGatoJoe->y > 327){
					dRectGatoJoe->y = 327;
					BATEU_BL = 0;
					GATOUP = 0;
				}
					
			}
		}
	}


}

void felicity(SDL_Rect* dRectGatoJoe,SDL_Rect a,SDL_Rect b){

	if(dRectGatoJoe->x >= 0 && dRectGatoJoe->x <= 214){

		if(dRectGatoJoe->x >= 0 && dRectGatoJoe->x <= 196){
			
			if(dRectGatoJoe->y < b.y){
				if(dRectGatoJoe->y > 162 && BATEU_BL != 1){
				
					if(dRectGatoJoe->y <= 162)
						BATEU_BL = 1;
					dRectGatoJoe->y -= 3;

					

				}else if(dRectGatoJoe->y <= 162 && BATEU_BL != 1){
					
					BATEU_BL = 1;
				}
						
				else if(BATEU_BL != 0){
					
					dRectGatoJoe->y += 3;

					if(dRectGatoJoe->y >= 291){
						dRectGatoJoe->y = 291;
						BATEU_BL = 0;
						GATOUP = 0;
					}
						
				}
			}

			

		}
		
		if(dRectGatoJoe->y > b.y){
			if(lazyFoo(a,b)){
				dRectGatoJoe->y += 6;
			}

			if(lazyFoo(a,b) && BATEU_BL != 1){
				BATEU_BL = 1;
				dRectGatoJoe->y += 6;
			}else if(!(lazyFoo(a,b)) && BATEU_BL != 1){
				dRectGatoJoe->y -= 3;
				
			}else if(BATEU_BL != 0){

				if(dRectGatoJoe->y >= 492){
					
					dRectGatoJoe->y = 492;
					BATEU_BL = 0;
					GATOUP = 0;
				}else{
					dRectGatoJoe->y += 6;
				}
			}
		}
		
	}
}

void august(SDL_Rect* dRectGatoJoe,SDL_Rect a,SDL_Rect b,Bloco* racaoB){

	if(dRectGatoJoe->x >= 0 && dRectGatoJoe->x <= 196){
		if(dRectGatoJoe->y <= 291 && dRectGatoJoe->y >= 154){
			if(racaoB[1].loadBloco != NULL){

				if(dRectGatoJoe->x > 180){

					dRectGatoJoe->x -= 6;
				}
			}				
		}
		
	}else if(dRectGatoJoe->x >= 197 && dRectGatoJoe->x <= 330 && PODEDESCER && !PODEANDAR){
		if(dRectGatoJoe->y <= 327 && dRectGatoJoe->y >= 211 && dRectGatoJoe->x > 317)
			dRectGatoJoe->x -= 6;
	}
}
void august_left(SDL_Rect* dRectGatoJoe,Bloco* racaoB){

	if(dRectGatoJoe->x <= 570 && dRectGatoJoe->y <= 90 && PODEDESCER && !BLOQUEIA_CAT && racaoB[1].loadBloco == NULL)
		dRectGatoJoe->x += 6;
}

void neal(SDL_Rect* dRectGatoJoe,SDL_Rect* racaoRect,SDL_Rect* racaoRect2,SDL_Rect* racaoRect3,SDL_Rect a,SDL_Rect b,SDL_Rect c,SDL_Rect d,Bloco* racaoB,Bloco* sinalR,Bloco* sinalR2,Bloco* sinalV,SDL_Renderer* renderer){

	if(lazyFoo(a,b)	&& dRectGatoJoe->x >= 575 && dRectGatoJoe->x <= 602){//575 && 588
		racaoRect->x = 8000;
		racaoRect->y = 8000;
		racaoRect->w = 0;
		racaoRect->h = 0;

		if(racaoB[0].loadBloco != NULL){
			SDL_DestroyTexture(racaoB[0].loadBloco);
			racaoB[0].loadBloco = NULL;
		}
		
		if(sinalR->loadBloco != NULL){
			SDL_DestroyTexture(sinalR->loadBloco);
			sinalR->loadBloco = NULL;
			//SDL_Surface* img;
			//img = IMG_Load("../img/99.png");
			//sinalV = img;
			//SDL_FreeSurface(img);
			//img = NULL;
			sinalR->loadBloco = carregarTextura(renderer,"../img/sinalGreen.png");
		}else
			sinalR->loadBloco = carregarTextura(renderer,"../img/sinalGreen.png");

		PODEDESCER = 1;
		BLOQUEIA_CAT = 1;
	}

	if(lazyFoo(a,c)	&& dRectGatoJoe->x > 39 && dRectGatoJoe->x < 90){
		racaoRect2->x = 8000;
		racaoRect2->y = 8000;
		racaoRect2->w = 0;
		racaoRect2->h = 0;
		if(racaoB[1].loadBloco != NULL){
			SDL_DestroyTexture(racaoB[1].loadBloco);
			racaoB[1].loadBloco = NULL;
		}
		
		if(sinalR2->loadBloco != NULL){
			SDL_DestroyTexture(sinalR2->loadBloco);
			sinalR2->loadBloco = NULL;
			sinalR2->loadBloco = carregarTextura(renderer,"../img/moeda2.png");
		}else		
			sinalR2->loadBloco = carregarTextura(renderer,"../img/moeda2.png");
	}

	if(lazyFoo(a,d)){
		

		racaoRect3->x = 8000;
		racaoRect3->y = 8000;
		racaoRect3->w = 0;
		racaoRect3->h = 0;
		if(racaoB[2].loadBloco != NULL){
			SDL_DestroyTexture(racaoB[2].loadBloco);
			racaoB[2].loadBloco = NULL;
		}
	}
}

void turtle(SDL_Rect* dRectGatoJoe){

	if(PODEDESCER){
		if(dRectGatoJoe->x >= 570 && dRectGatoJoe->y <= 90){
			if(dRectGatoJoe->y > 30 && BATEU_BL != 1){
				
				if(dRectGatoJoe->y <= 30)
					BATEU_BL = 1;
				dRectGatoJoe->y -= 3;

				

			}else if(dRectGatoJoe->y <= 30 && BATEU_BL != 1){
				
				BATEU_BL = 1;
			}
					
			else if(BATEU_BL != 0){
				
				dRectGatoJoe->y += 3;

				if(dRectGatoJoe->y > 90){
					dRectGatoJoe->y = 90;
					BATEU_BL = 0;
					GATOUP = 0;
				}
					
			}
		}
	}
}


void cair(SDL_Rect* dRectGatoJoe){

	if(!((dRectGatoJoe->x >= 449 && dRectGatoJoe->x <= 529) || (dRectGatoJoe->x >= 526 && dRectGatoJoe->x <= 668) || (dRectGatoJoe->x >= 0 && dRectGatoJoe->x <= 214 && !PODEDESCER) ||  (dRectGatoJoe->x >= 197 && dRectGatoJoe->x <= 330 && PODEDESCER) || (dRectGatoJoe->x >= 0 && dRectGatoJoe->x <= 196 && PODEDESCER) || (dRectGatoJoe->x >= 570 && dRectGatoJoe->y <= 96 && PODEDESCER) /* || (dRectGatoJoe->x >= 580 && PODEDESCER) || (dRectGatoJoe->x >= 392 && dRectGatoJoe->x <= 518)*/ )){
		
		BATEU_BL = 0;
		BATEU_BL2 = 0;

		if(dRectGatoJoe->y < 492 && BATEU_BL3 == 0 && GATOUP){
			if(dRectGatoJoe->y >= 492){
				dRectGatoJoe->y = 492;
				
				//BATEU_BL3 = 2;
			}
				GATOUP = 0;
				dRectGatoJoe->y += 3;
		}


		if(dRectGatoJoe->y == 492 && BATEU_BL3 == 0){
			dRectGatoJoe->y -= 3;
			BATEU_BL3 = 1;
		}else if(dRectGatoJoe->y < 492 && BATEU_BL3 == 1){
			
			if(dRectGatoJoe->y <= 322)	
				BATEU_BL3 = 2;
			dRectGatoJoe->y -= 3;
		}else if((dRectGatoJoe->y < 492 && BATEU_BL3 == 2)){
			dRectGatoJoe->y += 3;
			//BATEU_BL3 = 2;
		}else if(dRectGatoJoe->y >= 492 && BATEU_BL3 == 2){
			dRectGatoJoe->y = 492;
			GATOUP = 0;
			BATEU_BL3 = 0;
		}
	}
}

void naoPassaDoLimiteDaJanela(SDL_Rect* dRectGatoJoe){

	if(dRectGatoJoe->x + dRectGatoJoe->w >= LARGURA_JANELA)
		dRectGatoJoe->x -= 6;

	if(dRectGatoJoe->x <= 0)
		dRectGatoJoe->x += 6;

}

int movimentoInimigo(SDL_Rect* dRectDog,SDL_Rect* sRectDog,int* chegou,int vivo){
	
	//faz o 1º bloco que está no ar se mover
	//printf("Valor de chegouFlutua is %d\n",*chegou);

    //...


    

	if(vivo){
		
		if(dRectDog->x <= 895 && *(chegou) != 1){//586 895

			dRectDog->x += 1;
			
			moveSpriteCatRight(sRectDog);
		}else{
			
			moveSpriteCatLeft(sRectDog);

			if(dRectDog->x >= 895){
				*(chegou) = 1;
			}

			if(dRectDog->x <= 586){
				*(chegou) = 0;
			}

			dRectDog->x -= 1;
		}


	}else{
		return 0;
	}

	return 1;

}

void reiniciar(PosicaoBloco* obstaculosPosicao, PosicaoBloco* caixaBlocoMovel2, SDL_Rect* dRectGatoJoe,
	Bloco* sinalR,Bloco* racao, PosicaoBloco* racaoPos1,PosicaoBloco* racaoPos3,PosicaoBloco* coinRect,Bloco* coinB,
	Bloco* sinalV){
	
	obstaculosPosicao[3].loadRect.y = 150;
	caixaBlocoMovel2->loadRect.y = 155;
	
	dRectGatoJoe->x = 10;
	dRectGatoJoe->y = 492;
	
	GATOUP = 0;
	BATEU_BL = 0;
	BATEU_BL2 = 0;
	BATEU_BL3 = 0;
	PODEDESCER = 0;
	PODEANDAR = 0;
	BLOQUEIA_CAT = 0;
	GATOMORREU = 0;
	PONTUACAO = 0;

	if(sinalR->loadBloco != NULL){
		printf("Computador\n");
		SDL_DestroyTexture(sinalR->loadBloco);
		sinalR->loadBloco = NULL;
		sinalR->loadBloco = carregarTextura(renderer,"../img/sinalRed.png");
	}else{
		printf("Smartphone\n");
		sinalR->loadBloco = carregarTextura(renderer,"../img/sinalRed.png");
		SDL_DestroyTexture(sinalV->loadBloco);
		sinalV->loadBloco = NULL;
	}

	//SDL_DestroyTexture(sinalR2->loadBloco);
	//sinalR2->loadBloco = NULL;

	if(racao[0].loadBloco == NULL){
		SDL_DestroyTexture(racao[0].loadBloco);
		racao[0].loadBloco = NULL;
		racao[0].loadBloco = carregarTextura(renderer,"../img/racao.png");			
		racaoPos1->loadRect.w = 30;
		racaoPos1->loadRect.h = 30;
		racaoPos1->loadRect.x = 610;
		racaoPos1->loadRect.y = 392;	
	}
	if(racao[2].loadBloco == NULL){
		SDL_DestroyTexture(racao[2].loadBloco);
		racao[2].loadBloco = NULL;
		racao[2].loadBloco = carregarTextura(renderer,"../img/racao.png");			
		racaoPos3->loadRect.w = 3;
		racaoPos3->loadRect.h = 30;
		racaoPos3->loadRect.x = 898;
		racaoPos3->loadRect.y = 400;	
	}



	for(int i = 0; i < 5; i++){
		SDL_DestroyTexture(coinB[i].loadBloco);
		coinB[i].loadBloco = NULL;
		coinB[i].loadBloco = carregarTextura(renderer,"../img/coin.png");	
	}

	coinRect[0].loadRect.x = 284;//tam+10, também tem +14
	coinRect[0].loadRect.y = 472;
	coinRect[0].loadRect.w = 6;//tam-22(10), também 6
	coinRect[0].loadRect.h = 32;

	coinRect[1].loadRect.x = 316;
	coinRect[1].loadRect.y = 472;
	coinRect[1].loadRect.w = 6;
	coinRect[1].loadRect.h = 32;

	coinRect[2].loadRect.x = 304;
	coinRect[2].loadRect.y = 280;
	coinRect[2].loadRect.w = 6;
	coinRect[2].loadRect.h = 32;

	coinRect[3].loadRect.x = 644;
	coinRect[3].loadRect.y = 492;
	coinRect[3].loadRect.w = 6;
	coinRect[3].loadRect.h = 32;

	coinRect[4].loadRect.x = 514;
	coinRect[4].loadRect.y = 80;
	coinRect[4].loadRect.w = 6;
	coinRect[4].loadRect.h = 32;

}


void gatoMorreu(SDL_Rect* dRectGatoJoe,SDL_Rect* dRectDog, SDL_Rect a,SDL_Rect b,SDL_Rect* sRectGatoJoe,
	PosicaoBloco* obstaculosPosicao, PosicaoBloco* caixaBlocoMovel2,Bloco* sinalR,Bloco* racao,
	PosicaoBloco* racaoPos1,PosicaoBloco* racaoPos3,PosicaoBloco* coinRect,Bloco* coinB,Bloco* sinalV){


	if(GATOMORREU == 0){
		if(lazyFoo(a,b) && !(dRectGatoJoe->x >= 449 && dRectGatoJoe->x <= 528)){

			if(VIDASGATO <= 0){
				sRectGatoJoe->y = 400;
				sRectGatoJoe->x = 900;
				GATOMORREU = 1;
			}else{
				VIDASGATO -= 1;
				if(VIDASGATO > 0)
					reiniciar(obstaculosPosicao,caixaBlocoMovel2,dRectGatoJoe,sinalR,racao,racaoPos1,racaoPos3,coinRect,coinB,sinalV);
			}
			

			

			
		}
	}



}

int venceu(SDL_Rect* dRectGatoJoe,SDL_Rect* leiteRect,SDL_Rect a,SDL_Rect b,Bloco* leiteB){

	if(lazyFoo(a,b)){
		leiteRect->x = 8000;
		leiteRect->y = 8000;
		leiteRect->w = 0;
		leiteRect->h = 0;

		leiteB->loadBloco = NULL;
		printf("Voce ganhou, PARABÉNS!!!!!!!!!!!!\n");


		return 6;

	}


}

int iniciarSDL(){
	
	if(SDL_Init(SDL_INIT_EVERYTHING) < 0){

		printf("Error ao iniciar SDL %s\n",SDL_GetError());
		return 0;

	}else
		return 1;
}

SDL_Window* criarJanela(){

	SDL_Window* janela;

	janela = SDL_CreateWindow("Game - O Gato Joe",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,LARGURA_JANELA,ALTURA_JANELA,SDL_WINDOW_SHOWN);
	
	if(janela == NULL){
		printf("Erro na janela %s\n",SDL_GetError());
		return NULL;
	}else
		return janela;
}

int iniciarIMG(){

	if(IMG_Init(IMG_INIT_PNG) < 0){

		printf("Erro ao iniciar IMG_INIT %s\n",IMG_GetError());
		return 0;
	}else
		return 1;
}

//Códigos da Fase 1

void criarChao(Bloco* chao,PosicaoBloco* chaoPosicao){
	for(int i = 0; i < 8;i++){
		if(chao[i].loadBloco != NULL){
			SDL_DestroyTexture(chao[i].loadBloco);
			chao[i].loadBloco = NULL;	
		}
	
		chao[i].loadBloco = carregarTextura(renderer,"../img/bloco.png");	
		chaoPosicao[i].loadRect.w = 125;
		chaoPosicao[i].loadRect.h = 60;
		
		if(i == 0)
			chaoPosicao[0].loadRect.x = 0;
		else
			chaoPosicao[i].loadRect.x = chaoPosicao[i - 1].loadRect.x + 125;
		
		chaoPosicao[i].loadRect.y = 580;
	}
}

void criarBlocosEsquerdos(Bloco* blocosLeft, PosicaoBloco* blocosPosicaoLeft){
	for(int i = 0; i < 4;i++){
		if(blocosLeft[i].loadBloco != NULL){
			SDL_DestroyTexture(blocosLeft[i].loadBloco);
			blocosLeft[i].loadBloco = NULL;
		}
		blocosLeft[i].loadBloco = carregarTextura(renderer,"../img/bloco.png");	
		blocosPosicaoLeft[i].loadRect.w = 60;
		blocosPosicaoLeft[i].loadRect.h = 60;
		
		if(i == 0)
			blocosPosicaoLeft[0].loadRect.x = 0;
		else
			blocosPosicaoLeft[i].loadRect.x = blocosPosicaoLeft[i - 1].loadRect.x + 60;
		
		blocosPosicaoLeft[i].loadRect.y = 380;
	}
}

void criarBlocosDireitos(Bloco* blocosRight, PosicaoBloco* blocosPosicaoRight){
	for(int i = 0; i < 4;i++){
		if(blocosRight[i].loadBloco != NULL){
			SDL_DestroyTexture(blocosRight[i].loadBloco);
			blocosRight[i].loadBloco = NULL;
		}
		
		blocosRight[i].loadBloco = carregarTextura(renderer,"../img/bloco.png");	
		blocosPosicaoRight[i].loadRect.w = 60;
		blocosPosicaoRight[i].loadRect.h = 60;
		
		if(i == 0)
			blocosPosicaoRight[i].loadRect.x = 940;
		else
			blocosPosicaoRight[i].loadRect.x = blocosPosicaoRight[i - 1].loadRect.x - 60;
		
		blocosPosicaoRight[i].loadRect.y = 180;
	}
}

void iniciarObstaculos(Bloco* obstaculos, PosicaoBloco* obstaculosPosicao){
	
	for(int i = 0; i < 4;i++){
		if(obstaculos[i].loadBloco != NULL){
			SDL_DestroyTexture(obstaculos[i].loadBloco);
			obstaculos[i].loadBloco = NULL;
		}
	}
	
	
	obstaculos[0].loadBloco = carregarTextura(renderer,"../img/bloco.png");
	obstaculosPosicao[0].loadRect.w = 60;
	obstaculosPosicao[0].loadRect.h = 60;
	obstaculosPosicao[0].loadRect.x = 500;
	obstaculosPosicao[0].loadRect.y = 520;

///	SDL_DestroyTexture(obstaculos[1].loadBloco);
	//obstaculos[1].loadBloco = NULL;
	obstaculos[1].loadBloco = carregarTextura(renderer,"../img/bloco.png");
	obstaculosPosicao[1].loadRect.w = 60;
	obstaculosPosicao[1].loadRect.h = 60;
	obstaculosPosicao[1].loadRect.x = 580;
	obstaculosPosicao[1].loadRect.y = 415;

	//SDL_DestroyTexture(obstaculos[2].loadBloco);
	//obstaculos[2].loadBloco = NULL;
	obstaculos[2].loadBloco = carregarTextura(renderer,"../img/bloco.png");
	obstaculosPosicao[2].loadRect.w = 60;
	obstaculosPosicao[2].loadRect.h = 60;
	obstaculosPosicao[2].loadRect.x = obstaculosPosicao[1].loadRect.x + 60;
	obstaculosPosicao[2].loadRect.y = 415;

	//SDL_DestroyTexture(obstaculos[3].loadBloco);
	//obstaculos[3].loadBloco = NULL;
	obstaculos[3].loadBloco = carregarTextura(renderer,"../img/flutua1_1.png");
	obstaculosPosicao[3].loadRect.w = 150;
	obstaculosPosicao[3].loadRect.h = 60;
	obstaculosPosicao[3].loadRect.x = obstaculosPosicao[1].loadRect.x - 145;
	obstaculosPosicao[3].loadRect.y = 150;//150
}

void iniciarGato(Heroi* catJoe, PosicaoHeroi* catPosicao, PosicaoHeroi* catJoePosicao){
	
	if(catJoe->loadBloco != NULL){
		SDL_DestroyTexture(catJoe->loadBloco);
		catJoe->loadBloco = NULL;
	}
	catJoe->loadBloco = carregarTextura(renderer,"../img/gato.png");
	catPosicao->loadRect.w = 100;//catPosicao.loadRect.w = 100;
	catPosicao->loadRect.h = 100;
	catPosicao->loadRect.x = 0;
	catPosicao->loadRect.y = 0;


	catJoePosicao->loadRect.w = 100;
	catJoePosicao->loadRect.h = 100;
	catJoePosicao->loadRect.x = 10;		
	catJoePosicao->loadRect.y = 492;
}

void iniciarSinais(Bloco* sinalR,Bloco* sinalR2,PosicaoBloco* sinalRPos,PosicaoBloco* sinalRPos2){
	
	if(sinalR->loadBloco != NULL){
		printf("Logtr\n");
		SDL_DestroyTexture(sinalR->loadBloco);
		sinalR->loadBloco = NULL;
	}else{
		sinalR->loadBloco = carregarTextura(renderer,"../img/sinalRed.png");
	}
				
	sinalRPos->loadRect.w = 60;
	sinalRPos->loadRect.h = 60;
	sinalRPos->loadRect.x = 650;
	sinalRPos->loadRect.y = 356;

	
	if(sinalR2->loadBloco != NULL){
		SDL_DestroyTexture(sinalR2->loadBloco);
		sinalR2->loadBloco = NULL;
	}
	sinalR2->loadBloco = carregarTextura(renderer,"../img/sinalRed.png");
	
	sinalRPos2->loadRect.w = 60;
	sinalRPos2->loadRect.h = 60;
	sinalRPos2->loadRect.x = 40;
	sinalRPos2->loadRect.y = 320;
}

void iniciarRacao(Bloco* racao,PosicaoBloco* racaoPos){
	

	for(int i = 0; i < 3;i++){
		if(racao[i].loadBloco != NULL){
			SDL_DestroyTexture(racao[i].loadBloco);
			racao[i].loadBloco = NULL;
		}
	}

	racao[0].loadBloco = carregarTextura(renderer,"../img/racao.png");			
	racaoPos[0].loadRect.w = 30;
	racaoPos[0].loadRect.h = 30;
	racaoPos[0].loadRect.x = 620;
	racaoPos[0].loadRect.y = 392;

	//SDL_DestroyTexture(racao[1].loadBloco);
	//racao[1].loadBloco = NULL;
	racao[1].loadBloco = carregarTextura(renderer,"../img/racao.png");
	racaoPos[1].loadRect.w = 30;
	racaoPos[1].loadRect.h = 30;
	racaoPos[1].loadRect.x = 100;
	racaoPos[1].loadRect.y = 355;

	//SDL_DestroyTexture(racao[2].loadBloco);
	//racao[2].loadBloco = NULL;
	racao[2].loadBloco = carregarTextura(renderer,"../img/racao.png");
	racaoPos[2].loadRect.w = 30;
	racaoPos[2].loadRect.h = 30;
	racaoPos[2].loadRect.x = 880;
	racaoPos[2].loadRect.y = 400;
}

void iniciarInimigo(Bloco* inimigo,PosicaoBloco* sRect_inimigoPos,PosicaoBloco* dRect_inimigoPos){

	
	if(inimigo->loadBloco != NULL){
		SDL_DestroyTexture(inimigo->loadBloco);
		inimigo->loadBloco = NULL;
	}
	inimigo->loadBloco = carregarTextura(renderer,"../img/dogOnly.png");

	sRect_inimigoPos->loadRect.w = 100;
	sRect_inimigoPos->loadRect.h = 100;
	sRect_inimigoPos->loadRect.x = 100;//880
	sRect_inimigoPos->loadRect.y = 100;//990

	dRect_inimigoPos->loadRect.w = 100;
	dRect_inimigoPos->loadRect.h = 100;
	dRect_inimigoPos->loadRect.x = 895;
	dRect_inimigoPos->loadRect.y = 492;
}

void iniciarLeite(Bloco* leite,PosicaoBloco* leitePos){
	

	if(leite->loadBloco != NULL){
		SDL_DestroyTexture(leite->loadBloco);
		leite->loadBloco = NULL;
	}

	leite->loadBloco = carregarTextura(renderer,"../img/leite.png");
	leitePos->loadRect.w = 80;
	leitePos->loadRect.h = 64;
	leitePos->loadRect.y = 100;
	leitePos->loadRect.x = 850;
}

void cairEntreBlocos(PosicaoHeroi* catJoePosicao,PosicaoHeroi* catPosicao){
	if(catJoePosicao->loadRect.x >= 449 && catJoePosicao->loadRect.x <= 526 && catJoePosicao->loadRect.y < 432){
		catJoePosicao->loadRect.y += 3;
		if(catPosicao->loadRect.y == 900)
			catJoePosicao->loadRect.x -= 1;

		if(catJoePosicao->loadRect.y >= 432)
			catJoePosicao->loadRect.y = 432;
		
	}
}

void destruirWRBTS(){
	
	SDL_DestroyWindow(window);
	window = NULL;
	
	SDL_DestroyRenderer(renderer);
	renderer = NULL;
	
	SDL_DestroyTexture(backgroundTextura);
	backgroundTextura = NULL;

	SDL_DestroyTexture(som);
	som = NULL;

	SDL_DestroyTexture(notSom);
	notSom = NULL;

	Mix_FreeMusic(musica);
	musica = NULL;

	Mix_FreeChunk(botao);
	botao = NULL;
}

void destruirFase1(Heroi* catJoe,Bloco* sinalR,Bloco* sinalR2,
	Bloco* racao,Bloco* inimigo, Bloco* leite,Bloco* chao,
	Bloco* blocosLeft,Bloco* blocosRight, Bloco* obstaculos,
	Bloco* timerImg,SDL_Texture* minTexto,SDL_Texture* segTexto,
	SDL_Texture* sepaTexto,SDL_Texture* zeroTexto,SDL_Texture* fase,
	Bloco* vidaImg,SDL_Texture* vidaTextura,Bloco* coin,Bloco* coinImg,
	SDL_Texture* coinTextura){
	
	SDL_DestroyTexture(catJoe->loadBloco);
	catJoe->loadBloco = NULL;

	if(sinalR->loadBloco != NULL){
		printf("Bela & JOE\n");
			SDL_DestroyTexture(sinalR->loadBloco);
		sinalR->loadBloco = NULL;
	}


	SDL_DestroyTexture(sinalR2->loadBloco);
	sinalR2->loadBloco = NULL;

	for(int i = 0; i < 3;i++){
		SDL_DestroyTexture(racao[i].loadBloco);
		racao[i].loadBloco = NULL;
	}

	SDL_DestroyTexture(inimigo->loadBloco);
	inimigo->loadBloco = NULL;
	
	SDL_DestroyTexture(leite->loadBloco);
	leite->loadBloco = NULL;

	for(int i = 0;i < 8; i++){
		SDL_DestroyTexture(chao[i].loadBloco);
		chao[i].loadBloco = NULL;
	}

	for(int i = 0; i < 4; i++){
		SDL_DestroyTexture(blocosLeft[i].loadBloco);
		blocosLeft[i].loadBloco = NULL;
		SDL_DestroyTexture(blocosRight[i].loadBloco);
		blocosRight[i].loadBloco = NULL;
		
	}
	

	for(int i = 0; i < 4; i++){
		SDL_DestroyTexture(obstaculos[i].loadBloco);
		obstaculos[i].loadBloco = NULL;
	}

	SDL_DestroyTexture(timerImg->loadBloco);
	timerImg->loadBloco = NULL;
	SDL_DestroyTexture(minTexto);
	minTexto = NULL;
	SDL_DestroyTexture(segTexto);
	segTexto = NULL;
	SDL_DestroyTexture(sepaTexto);
	sepaTexto = NULL;
	SDL_DestroyTexture(zeroTexto);
	zeroTexto = NULL;
	SDL_DestroyTexture(fase);
	fase = NULL;
	SDL_DestroyTexture(vidaImg->loadBloco);
	vidaImg->loadBloco = NULL;
	SDL_DestroyTexture(vidaTextura);
	vidaTextura = NULL;
	for(int i = 0;i < 5;i++){
		SDL_DestroyTexture(coin[i].loadBloco);
		coin[i].loadBloco = NULL;
	}
	SDL_DestroyTexture(coinImg->loadBloco);
	coinImg->loadBloco = NULL;
	SDL_DestroyTexture(coinTextura);
	coinTextura = NULL;

	//Reiniciando variáveis globais
	GATOUP = 0;
	BATEU_BL = 0;
	BATEU_BL2 = 0;
	BATEU_BL3 = 0;
	PODEDESCER = 0;
	PODEANDAR = 0;
	BLOQUEIA_CAT = 0;
	GATOMORREU = 0;
	//PONTUACAO = 0;
	//PAUSADO = 1;
	VIDASGATO = 3;


}
//FIM DOS CÓDIGOS PARA A FASE 1

int iniciarTTF(){
	//Inicando ttf para usar texto
	if(TTF_Init() < 0){
		printf("Erro no TTF %s\n",TTF_GetError());
		return 0;
	}else
		return 1;
}

void pegarMoeda(PosicaoBloco* coinRect,Bloco* coinB,SDL_Rect a,PosicaoBloco* b,int max){
	
	for(int i = 0; i < max; i++){
		if(lazyFoo(a,b[i].loadRect)){
			coinRect[i].loadRect.x = 8000;
			coinRect[i].loadRect.y = 8000;
			coinRect[i].loadRect.w = 0;
			coinRect[i].loadRect.h = 0;

			coinB[i].loadBloco = NULL;

			PONTUACAO++;
			
		}
	}
	
	
}

void iniciarTimer(Bloco* timerImg, PosicaoBloco* timerImgPos){
	
	if(timerImg->loadBloco != NULL){
		SDL_DestroyTexture(timerImg->loadBloco);
		timerImg->loadBloco = NULL;
	}
	
	timerImg->loadBloco = carregarTextura(renderer,"../img/timer8.png");
	timerImgPos->loadRect.w = 25;
	timerImgPos->loadRect.h = 25;
	timerImgPos->loadRect.x = 800;
	timerImgPos->loadRect.y = 14;
}

void iniciarCoins(Bloco* coin,PosicaoBloco* dRectCoin,PosicaoBloco* sRectCoin){
	for(int i = 0; i < 5; i++){
		if(coin[i].loadBloco != NULL){
			SDL_DestroyTexture(coin[i].loadBloco);
			coin[i].loadBloco = NULL;
		}
		
		coin[i].loadBloco = carregarTextura(renderer,"../img/coin.png");
		dRectCoin[i].loadRect.w = 32;
		dRectCoin[i].loadRect.h = 32;
		sRectCoin[i].loadRect.w = 32;
		sRectCoin[i].loadRect.h = 32;
		sRectCoin[i].loadRect.x = 0;
		sRectCoin[i].loadRect.y = 0;
	}

	dRectCoin[0].loadRect.x = 270;
	dRectCoin[0].loadRect.y = 472;

	dRectCoin[1].loadRect.x = 302;
	dRectCoin[1].loadRect.y = 472;

	dRectCoin[2].loadRect.x = 290;
	dRectCoin[2].loadRect.y = 280;

	dRectCoin[3].loadRect.x = 630;
	dRectCoin[3].loadRect.y = 492;

	dRectCoin[4].loadRect.x = 500;
	dRectCoin[4].loadRect.y = 80;
}

void iniciarVidaImg(Bloco* vidaImg,PosicaoBloco* vidaImgPos,SDL_Rect* vidaRect){

	if(vidaImg->loadBloco != NULL){
		SDL_DestroyTexture(vidaImg->loadBloco);
		vidaImg->loadBloco = NULL;
	}
	
	vidaImg->loadBloco = carregarTextura(renderer,"../img/vida7.png");
	
	vidaImgPos->loadRect.w = 45;//42
	vidaImgPos->loadRect.h = 42;
	vidaImgPos->loadRect.x = 100;
	vidaImgPos->loadRect.y = 6;

	vidaRect->x = 150;
	vidaRect->y = 6;
	vidaRect->w = 40;
	vidaRect->h = 40;

}

void renderMoeda(Bloco* coin,PosicaoBloco* sRectCoin,PosicaoBloco* dRectCoin){
	for(int i = 0;i < 5;i++)
		SDL_RenderCopy(renderer,coin[i].loadBloco,&sRectCoin[i].loadRect,&dRectCoin[i].loadRect);

}

void reiniciar2(Bloco* coin,PosicaoBloco* dRectCoin,PosicaoBloco* sRectCoin,PosicaoBloco* caixaBlocoLeft,
				PosicaoBloco* caixaBlocoChao,PosicaoBloco* caixaBlocoRight2,PosicaoBloco* caixaBlocoRight,
				PosicaoBloco* caixaBlocoMovel2,PosicaoBloco* caixaBlocoRacao1,PosicaoBloco* caixaBlocoRacao2,
				PosicaoBloco* caixaBlocoRacao3,PosicaoBloco* caixaInimigo,PosicaoBloco* caixaLeite,
				PosicaoBloco* caixaCoin,int* contador,int* c2,int* min,int*seg){

	//Reiniciando moedas
	for(int i = 0; i < 5; i++){
		SDL_DestroyTexture(coin[i].loadBloco);
		coin[i].loadBloco = NULL;
		coin[i].loadBloco = carregarTextura(renderer,"../img/coin.png");
		dRectCoin[i].loadRect.w = 32;
		dRectCoin[i].loadRect.h = 32;
		sRectCoin[i].loadRect.w = 32;
		sRectCoin[i].loadRect.h = 32;
		sRectCoin[i].loadRect.x = 0;
		sRectCoin[i].loadRect.y = 0;
	}

	dRectCoin[0].loadRect.x = 270;
	dRectCoin[0].loadRect.y = 472;

	dRectCoin[1].loadRect.x = 302;
	dRectCoin[1].loadRect.y = 472;

	dRectCoin[2].loadRect.x = 290;
	dRectCoin[2].loadRect.y = 280;

	dRectCoin[3].loadRect.x = 630;
	dRectCoin[3].loadRect.y = 492;

	dRectCoin[4].loadRect.x = 500;
	dRectCoin[4].loadRect.y = 80;

	/*Reiniciando AS CAIXAS DE COLISÃO*/
	caixaBlocoLeft->loadRect.x = 0;
	caixaBlocoLeft->loadRect.y = 385;
	caixaBlocoLeft->loadRect.w = 240;
	caixaBlocoLeft->loadRect.h = 60;

	caixaBlocoChao->loadRect.x = 510;
	caixaBlocoChao->loadRect.y = 525;
	caixaBlocoChao->loadRect.w = 42;
	caixaBlocoChao->loadRect.h = 60;

	caixaBlocoRight2->loadRect.x = 585;
	caixaBlocoRight2->loadRect.y = 418;
	caixaBlocoRight2->loadRect.w = 100;
	caixaBlocoRight2->loadRect.h = 50;

	caixaBlocoRight->loadRect.x = 760;
	caixaBlocoRight->loadRect.y = 180;
	caixaBlocoRight->loadRect.w = 240;
	caixaBlocoRight->loadRect.h = 60;

	caixaBlocoMovel2->loadRect.x = 408;
	caixaBlocoMovel2->loadRect.y = 155;
	caixaBlocoMovel2->loadRect.w = 140;
	caixaBlocoMovel2->loadRect.h = 60;

	caixaBlocoRacao1->loadRect.x = 610;
	caixaBlocoRacao1->loadRect.y = 392;
	caixaBlocoRacao1->loadRect.w = 30;
	caixaBlocoRacao1->loadRect.h = 30;

	caixaBlocoRacao2->loadRect.x = 110;
	caixaBlocoRacao2->loadRect.y = 355;
	caixaBlocoRacao2->loadRect.w = 1;
	caixaBlocoRacao2->loadRect.h = 30;

	caixaBlocoRacao3->loadRect.x = 898;
	caixaBlocoRacao3->loadRect.y = 400;
	caixaBlocoRacao3->loadRect.w = 3;
	caixaBlocoRacao3->loadRect.h = 30;

	caixaInimigo->loadRect.w = 100;
	caixaInimigo->loadRect.h = 100;

	caixaLeite->loadRect.x = 870;
	caixaLeite->loadRect.y = 100;
	caixaLeite->loadRect.w = 16;
	caixaLeite->loadRect.h = 64;

	caixaCoin[0].loadRect.x = 284;
	caixaCoin[0].loadRect.y = 472;
	caixaCoin[0].loadRect.w = 6;
	caixaCoin[0].loadRect.h = 32;

	caixaCoin[1].loadRect.x = 316;
	caixaCoin[1].loadRect.y = 472;
	caixaCoin[1].loadRect.w = 6;
	caixaCoin[1].loadRect.h = 32;

	caixaCoin[2].loadRect.x = 304;
	caixaCoin[2].loadRect.y = 280;
	caixaCoin[2].loadRect.w = 6;
	caixaCoin[2].loadRect.h = 32;

	caixaCoin[3].loadRect.x = 644;
	caixaCoin[3].loadRect.y = 492;
	caixaCoin[3].loadRect.w = 6;
	caixaCoin[3].loadRect.h = 32;

	caixaCoin[4].loadRect.x = 514;
	caixaCoin[4].loadRect.y = 80;
	caixaCoin[4].loadRect.w = 6;
	caixaCoin[4].loadRect.h = 32;


	//Reiniciando variáveis globais
	GATOUP = 0;
	BATEU_BL = 0;
	BATEU_BL2 = 0;
	BATEU_BL3 = 0;
	PODEDESCER = 0;
	PODEANDAR = 0;
	BLOQUEIA_CAT = 0;
	GATOMORREU = 0;
	PONTUACAO = 0;
	//PAUSADO = 1;
	VIDASGATO = 3;

	//Reiniciando Timer
	*contador = 60;
	*c2 = 1;
	*min = 0;
	*seg = 0;
}

int iniciarMusica(){
	
	if(Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,2,2048) < 0){
		printf("Erro ao inicializar musica %s",Mix_GetError());
		return 0;
	}
	return 1;
}


