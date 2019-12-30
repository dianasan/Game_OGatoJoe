#include "fases.h"
printf("Testando envio compartilhado");

SDL_Texture *carregarTextura(SDL_Renderer *render,char *pathImage){

	SDL_Surface *imagem = NULL;
	SDL_Texture *texturaFuncao = NULL;
	imagem = IMG_Load(pathImage);

	
	if(imagem == NULL){
		printf("Erro na imagem da funcao texture %s\n",IMG_GetError());
	}else{
		texturaFuncao = SDL_CreateTextureFromSurface(render,imagem);
		if(texturaFuncao == NULL){
			printf("Erro na textura da funcao %s\n",SDL_GetError());
		}else{			
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

void continuarMovimentoCatJoe(SDL_Rect* dRectGatoJoe, SDL_Rect* sRectGatoJoe, int* chegouTeto){
	//Quando o usuário soltar a tecla de pulo ele continua o movimento do estado final do personagem
	//avalia as variáveis globais GATODOWN e GATOJUMPRIGHT->se V então cai para a direita

	if(GATODOWN == 1){
		
		if(dRectGatoJoe->y > 400 && *chegouTeto != 1){
			

			if(dRectGatoJoe->y <= 445){
				dRectGatoJoe->y -= 2;	
				if(GATOJUMPRIGHT == 1){
					dRectGatoJoe->x += 1;
				}							
			}else{
				if(BIGBLOCO1AR == 1){
					dRectGatoJoe->y += 3;
				}else{
					dRectGatoJoe->y -= 3;
					if((dRectGatoJoe->x >= 0 && dRectGatoJoe->x <= 240) && dRectGatoJoe->y <= 440){
						printf("AJHDK\n");
						BIGBLOCO1AR = 1;
					
					}
				}

				sRectGatoJoe->y = 292;
				sRectGatoJoe->x += 100;
				if(sRectGatoJoe->x >= 200){
					sRectGatoJoe->x = 100;
				}

				if(GATOJUMPRIGHT == 1){
					if((dRectGatoJoe->x >= 536 && dRectGatoJoe->x <= 572) && dRectGatoJoe->y > 492){
						dRectGatoJoe->x -= 20;
						GATOJUMPRIGHT = 0;
					}
					dRectGatoJoe->x += 1;
				}
			}

		}else{
			if((dRectGatoJoe->x >= 570 && dRectGatoJoe->x <= 682) && dRectGatoJoe->y >= 492){
				dRectGatoJoe->y = 530;
					if(GATOJUMPRIGHT == 1){
						GATOJUMPRIGHT = 0;
					}
					sRectGatoJoe->y = 0;
					sRectGatoJoe->x = 100;
				}else{

					dRectGatoJoe->y += 3;
					*chegouTeto = 1;
					if(GATOJUMPRIGHT == 1){
						dRectGatoJoe->x += 1;
					}
				}
		
		}
		
		if(dRectGatoJoe->y >= 492){
			dRectGatoJoe->y = 492;
			GATODOWN = 0;
			*chegouTeto = 0;
			sRectGatoJoe->y = 0;
			sRectGatoJoe->x = 100;
			if(GATOJUMPRIGHT == 1){
				GATOJUMPRIGHT = 0;
			}	
			
			BIGBLOCO1AR = 0;
			
		}
	}



}

void pular(SDL_Rect* catImg,SDL_Rect* catJoe,SDL_Rect* limiteTop,int limiteChao){

	int chegou = 0;

	
	if(catJoe->x >= 0 && catJoe->x <= 240){
		printf("limiteTop %d\n",limiteTop->y);
		printf("catJ %d\n",catJoe->y);
		
		if(catJoe->y <= 380+60){
			catJoe->y += 4;
			if(catJoe->y >= 380+60){
				catJoe->y -= 4;
			}
			printf("Entrei :|\n");
		}
		
	}
	
	//if(catJoe->y >= limiteTop->y){
	//	catJoe->y -= 3;
	//}
}

void d(SDL_Rect* dRectGatoJoe, SDL_Rect* sRectGatoJoe, int* chegouTeto,Uint32 inicioGetTick){

	/*
		400 é o limite que o gato pode alcançar no pulo, chegou teto é para saber se o gato já chegou no chão (rsrs).
		(dRectGatoJoe->x >= 0 && dRectGatoJoe->x <= 240) isso serve para se o gato estiver somente embaixo desse bloco.
		dRectGatoJoe->y <= 492 do chão pra cima, LEFTBLOCK variável global para saber se já bateu a cabeça no bloco.
		GATOUP variável global para saber se o gato já pulou e está no ar.
		if(dRectGatoJoe->y <= 440) LEFTBLOCK = 1; condição para: o gato já bateu a cabeça no bloco? LEFTBLOCK recebe 1
		para não entrar mais no IF.

		(dRectGatoJoe->x >= 0 && dRectGatoJoe->x <= 240) && LEFTBLOCK != 0 já bati a cabeça no bloco, posso descer.
		if(dRectGatoJoe->y >= 492) se chegou no chão ou passou, LEFTBLOCK recebe 0 para não entrar mais na condição
		e chegouTeto recebe 1 para parar de pular.
	*/

	//sprite(inicioGetTick);
	if(dRectGatoJoe->y > 400 && *chegouTeto != 1){ //200(400)

		if((dRectGatoJoe->x >= 0 && dRectGatoJoe->x <= 240) && dRectGatoJoe->y <= 492 && LEFTBLOCK != 1){
			/*INÍCIO*/
			//Para fazer um efeito de pulo mais convincente!!!
			if(dRectGatoJoe->y <= 456){
				dRectGatoJoe->y -= (100 / 40) % inicioGetTick;
				
			}
			else {
				dRectGatoJoe->y -= (100 / SPRITEFPS) % inicioGetTick;
				
			}
			/*FIM*/
			GATOUP = 1;
			if(dRectGatoJoe->y <= 440) LEFTBLOCK = 1;//350(440)

		}else if((dRectGatoJoe->x >= 0 && dRectGatoJoe->x <= 240) && LEFTBLOCK != 0){
			
			//if(CONT > 1)
				//dRectGatoJoe->y += (100 / 40) % inicioGetTick;
				
			//else
				dRectGatoJoe->y += (100 / SPRITEFPS) % inicioGetTick;
			
			if(dRectGatoJoe->y >= 492){
				dRectGatoJoe->y = 492;
				LEFTBLOCK = 0;
				*chegouTeto = 1;	
				//CONT = 0;
			} 
		}

	}

}

void teclaUP(SDL_Rect* dRectGatoJoe, SDL_Rect* sRectGatoJoe, int* chegouTeto){//chegouTetoBlocoLeft

	if(dRectGatoJoe->y > 400 && *chegouTeto != 1){
								printf("Entrei aqui 1\n");
								if(dRectGatoJoe->y <= 425){
									printf("Entrei aqui 2\n");
									dRectGatoJoe->y -= 4;
									if(GATOJUMPRIGHT == 1){
										printf("Entrei aqui 3\n");
										dRectGatoJoe->x += 1;
									}
								}else{
									printf("Entrei aqui 4\n");
									if(BIGBLOCO1AR == 0){
										printf("Entrei aqui 5\n");
										dRectGatoJoe->y -= 6;
									}
									if((dRectGatoJoe->x >= 0 && dRectGatoJoe->x <= 240) && dRectGatoJoe->y <= 440){
										printf("Entrei aqui 6\n");
										BIGBLOCO1AR = 1;
										GATODOWN = 1;
									}
									if(GATOJUMPRIGHT == 1){
										printf("Entrei aqui 7\n");
										if((dRectGatoJoe->x >= 536 && dRectGatoJoe->x <= 572) && dRectGatoJoe->y > 492){
											printf("Entrei aqui 8\n");
											dRectGatoJoe->x -= 20;
											GATOJUMPRIGHT = 0;
										}
										dRectGatoJoe->x += 1;
									}
									if(dRectGatoJoe->y <= 492){
										printf("Entrei aqui 9\n");
										sRectGatoJoe->x = 100;
										sRectGatoJoe->y = 292;
									}else{
										printf("Entrei aqui 10\n");
										sRectGatoJoe->x = 0;
									}
								}

							}else{
									printf("Entrei aqui 11\n");
								dRectGatoJoe->y += 6;
								if((dRectGatoJoe->x >= 570 && dRectGatoJoe->x <= 682) && dRectGatoJoe->y >= 492){
									dRectGatoJoe->y = 492;
									GATOJUMPRIGHT = 0;
										printf("Entrei aqui 12\n");
								}
								*chegouTeto = 1;
								if(GATOJUMPRIGHT == 1){
										printf("Entrei aqui 13\n");
									if((dRectGatoJoe->x >= 536 && dRectGatoJoe->x <= 572) && dRectGatoJoe->y > 492){
										dRectGatoJoe->x -= 20;
										GATOJUMPRIGHT = 0;
										printf("Entrei aqui 14\n");
									}
										dRectGatoJoe->x += 1;
																
								}
							}

							if((dRectGatoJoe->x >= 570 && dRectGatoJoe->x <= 682) && dRectGatoJoe->y >= 492){
									printf("Entrei aqui 15\n");
								*chegouTeto = 0;
								if(dRectGatoJoe->y > 300 && *chegouTeto != 1){
										printf("Entrei aqui 16\n");
									if(dRectGatoJoe->y <= 325){
											printf("Entrei aqui 17\n");
										dRectGatoJoe->y -= 4;
										if(GATOJUMPRIGHT == 1){
												printf("Entrei aqui 18\n");
											dRectGatoJoe->x += 1;
										}
									}else{
											printf("Entrei aqui 19\n");
										dRectGatoJoe->y -= 6;
										if(GATOJUMPRIGHT == 1){
												printf("Entrei aqui 20\n");
											dRectGatoJoe->x += 1;
										}
									}
								}else{
										printf("Entrei aqui 21\n");
									dRectGatoJoe->y += 6;
									if((dRectGatoJoe->x >= 570 && dRectGatoJoe->x <= 682) && dRectGatoJoe->y >= 492){
										dRectGatoJoe->y = 530;
										GATOJUMPRIGHT = 0;
											printf("Entrei aqui 22\n");
									}
									*chegouTeto = 1;
									if(GATOJUMPRIGHT == 1){
											printf("Entrei aqui 23\n");
										dRectGatoJoe->x += 1;
									}
									//colisao left
								}
							}

							if(dRectGatoJoe->y >= 617){
									printf("Entrei aqui 24\n");
								dRectGatoJoe->y = 617;
								*chegouTeto = 0;
								if(GATOJUMPRIGHT == 1){
										printf("Entrei aqui 25\n");
									GATOJUMPRIGHT = 0;
								}
								
							}	
}

void teclaRight_DontUP(SDL_Rect* catJoePosicao, SDL_Rect* catPosicao,int* bloco1X){

	//Se o personagem estiver no ar e a tecla pulo não estiver mais pressionada e o usuário pressionar a tecla direita então o personagem cai para a direita
	if(catJoePosicao->y < 617){
		//catJoePosicao->x += 1;	
		GATOJUMPRIGHT = 1;
	}else{
		//Verifica se o personagem está no chão e se V então poderá andar para a direita
		catPosicao->y = 100;
		catPosicao->x += 100;
	
		catJoePosicao->x += 3;
	
		if(catPosicao->x >= 1000){
			catPosicao->x = 100;
		}

		//colisão com o bloco1 pequeno estático no chão
		if(catJoePosicao->x >= *(bloco1X) && catJoePosicao->x <= 572){
			catJoePosicao->x-= 20;

		}
	}
}

void movimentoBlocoNoAr(SDL_Rect* obstaculosPosicao, int* chegouFlutua){

	//faz o 1º bloco que está no ar se mover
	if(obstaculosPosicao->x <= 588 && *(chegouFlutua) != 1){

		obstaculosPosicao->x += 1;
		
	}else{
		
		obstaculosPosicao->x -= 1;
		if(obstaculosPosicao->x == 588){
			*(chegouFlutua) = 1;
		}

		if(obstaculosPosicao->x <= 260){
			*(chegouFlutua) = 0;
		}
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
//teclaUP(&catJoePosicao.loadRect,&catPosicao.loadRect,&chegouTetoBlocoLeft);
