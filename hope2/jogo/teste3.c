

#define LARGURA_JANELA2 1400
#define ALTURA_JANELA2 820
int fase3(){

	

	
	SDL_Texture *sinal = NULL;
	SDL_Texture *caixa = NULL;
	SDL_Texture *gatoJoe = NULL;
	//SDL_Texture *cao = NULL;
	Bloco chao[8];
	PosicaoBloco chaoPosicao[8];

	Bloco blocosLeft[4];
	PosicaoBloco blocosPosicaoLeft[4];

	Bloco blocosRight[4];
	PosicaoBloco blocosPosicaoRight[4];

	Bloco obstaculos[10];
	PosicaoBloco obstaculosPosicao[10];

	Heroi catJoe;
	PosicaoHeroi catPosicao;
	PosicaoHeroi catJoePosicao;

	Bloco inimigo;
	PosicaoBloco dRect_inimigoPos;
	PosicaoBloco sRect_inimigoPos;

	Bloco sinalR;
	PosicaoBloco sinalRPos;
	Bloco racao[1];
	PosicaoBloco racaoPos[1];


	

	
			//Inicializa IMG_Load()
			/*if(IMG_Init(IMG_INIT_PNG) < 0){

				printf("Erro ao iniciar IMG_INIT %s\n",IMG_GetError());

			}else{*/

				//criando renderer
				

				//criando textura da imagem de fundo
				backgroundTextura = carregarTextura(renderer,"../img/BG.png");
				
				//criar Chão
				for(int i = 0; i < 8;i++){
					chao[i].loadBloco = carregarTextura(renderer,"../img/bloco.png");	
					chaoPosicao[i].loadRect.w = 125;
					chaoPosicao[i].loadRect.h = 60;
					
					if(i == 0)
						chaoPosicao[0].loadRect.x = 0;
					else
						chaoPosicao[i].loadRect.x = chaoPosicao[i - 1].loadRect.x + 125;
					
					chaoPosicao[i].loadRect.y = 580;
				}

				//criar blocos esquerdos
				for(int i = 0; i < 4;i++){
					blocosLeft[i].loadBloco = carregarTextura(renderer,"../img/bloco.png");	
					blocosPosicaoLeft[i].loadRect.w = 60;
					blocosPosicaoLeft[i].loadRect.h = 60;
					
					if(i == 0)
						blocosPosicaoLeft[0].loadRect.x = 0;
					else
						blocosPosicaoLeft[i].loadRect.x = blocosPosicaoLeft[i - 1].loadRect.x + 60;
					
					blocosPosicaoLeft[i].loadRect.y = 380;
				}

				


				//criar blocos direitos
				for(int i = 0; i < 4;i++){
					blocosRight[i].loadBloco = carregarTextura(renderer,"../img/bloco.png");	
					blocosPosicaoRight[i].loadRect.w = 60;
					blocosPosicaoRight[i].loadRect.h = 60;
					
					if(i == 0)
						blocosPosicaoRight[i].loadRect.x = 940;
					else
						blocosPosicaoRight[i].loadRect.x = blocosPosicaoRight[i - 1].loadRect.x - 60;
					
					blocosPosicaoRight[i].loadRect.y = 180;
				}

				//obstáculo terrestre
				obstaculos[0].loadBloco = carregarTextura(renderer,"../img/bloco.png");
				obstaculosPosicao[0].loadRect.w = 60;
				obstaculosPosicao[0].loadRect.h = 60;
				obstaculosPosicao[0].loadRect.x = 500;
				obstaculosPosicao[0].loadRect.y = 520;

				obstaculos[1].loadBloco = carregarTextura(renderer,"../img/bloco.png");
				obstaculosPosicao[1].loadRect.w = 60;
				obstaculosPosicao[1].loadRect.h = 60;
				obstaculosPosicao[1].loadRect.x = 580;
				obstaculosPosicao[1].loadRect.y = 415;
				obstaculos[2].loadBloco = carregarTextura(renderer,"../img/bloco.png");
				obstaculosPosicao[2].loadRect.w = 60;
				obstaculosPosicao[2].loadRect.h = 60;
				obstaculosPosicao[2].loadRect.x = obstaculosPosicao[1].loadRect.x + 60;
				obstaculosPosicao[2].loadRect.y = 415;

				obstaculos[3].loadBloco = carregarTextura(renderer,"../img/flutua1_1.png");
				obstaculosPosicao[3].loadRect.w = 150;
				obstaculosPosicao[3].loadRect.h = 60;
				obstaculosPosicao[3].loadRect.x = obstaculosPosicao[1].loadRect.x - 145;
				obstaculosPosicao[3].loadRect.y = 150;

				


				//Gato Joe, herói do jogo
				catJoe.loadBloco = carregarTextura(renderer,"../img/gato.png");
				catPosicao.loadRect.w = 100;
				catPosicao.loadRect.h = 100;
				catPosicao.loadRect.x = 0;
				catPosicao.loadRect.y = 0;


				catJoePosicao.loadRect.w = 100;
				catJoePosicao.loadRect.h = 100;
				catJoePosicao.loadRect.x = 15;		
				catJoePosicao.loadRect.y = 492;
				//GATOMORREU = 1;
				//ALTURA_JANELA - catPosicao.loadRect.h - 28;
				//380-72

				sinalR.loadBloco = carregarTextura(renderer,"../img/sinalRed.png");
				
				sinalRPos.loadRect.w = 60;
				sinalRPos.loadRect.h = 60;
				sinalRPos.loadRect.x = 650;
				sinalRPos.loadRect.y = 356;

				racao[0].loadBloco = carregarTextura(renderer,"../img/racao.png");
				
				racaoPos[0].loadRect.w = 30;
				racaoPos[0].loadRect.h = 30;
				racaoPos[0].loadRect.x = 620;
				racaoPos[0].loadRect.y = 392;

				inimigo.loadBloco = carregarTextura(renderer,"../img/dogOnly.png");

				sRect_inimigoPos.loadRect.w = 100;
				sRect_inimigoPos.loadRect.h = 100;
				sRect_inimigoPos.loadRect.x = 0;//880
				sRect_inimigoPos.loadRect.y = 100;//990

				dRect_inimigoPos.loadRect.w = 100;
				dRect_inimigoPos.loadRect.h = 100;
				dRect_inimigoPos.loadRect.x = 895;
				dRect_inimigoPos.loadRect.y = 492;
				

				//int limiteChao = ALTURA_JANELA - catPosicao.loadRect.h - 28;//492
				//Controla GameLoop
				//int fechar = 0;
				//parametros botao
				int x,y;
				

				//Controlar eventos
				//SDL_Event event;
				
				float flPreviousTime = 0;
				float flCurrentTime = SDL_GetTicks();

				SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);

				const Uint8 *state = SDL_GetKeyboardState(NULL);

				int bloco1X = 536;
				int bloco1L = 128;
				int blocoH = 538;

				int bigBloco1 = 480;
				/*CRIANDO AS CAIXAS DE COLISÃO*/
				PosicaoBloco caixaBlocoLeft;
				caixaBlocoLeft.loadRect.x = 0;
				caixaBlocoLeft.loadRect.y = 385;//380
				caixaBlocoLeft.loadRect.w = 240;
				caixaBlocoLeft.loadRect.h = 60;

				PosicaoBloco caixaBlocoChao;
				caixaBlocoChao.loadRect.x = 510;//500-510
				caixaBlocoChao.loadRect.y = 525;//520
				caixaBlocoChao.loadRect.w = 42;//60 - 42
				caixaBlocoChao.loadRect.h = 60;

			

				PosicaoBloco caixaBlocoRight2;
				caixaBlocoRight2.loadRect.x = 585;//585
				caixaBlocoRight2.loadRect.y = 418;//418
				caixaBlocoRight2.loadRect.w = 100;
				caixaBlocoRight2.loadRect.h = 50;

				PosicaoBloco caixaBlocoRight;
				caixaBlocoRight.loadRect.x = 760;
				caixaBlocoRight.loadRect.y = 180;
				caixaBlocoRight.loadRect.w = 240;
				caixaBlocoRight.loadRect.h = 60;


				PosicaoBloco caixaBlocoMovel2;
				caixaBlocoMovel2.loadRect.x = 408;//464
				caixaBlocoMovel2.loadRect.y = 155;//155
				caixaBlocoMovel2.loadRect.w = 140;
				caixaBlocoMovel2.loadRect.h = 60;

				PosicaoBloco caixaBlocoRacao1;
				caixaBlocoRacao1.loadRect.x = 605;
				caixaBlocoRacao1.loadRect.y = 392;
				caixaBlocoRacao1.loadRect.w = 1;
				caixaBlocoRacao1.loadRect.h = 30;

				PosicaoBloco caixaInimigo;
				caixaInimigo.loadRect.w = 100;
				caixaInimigo.loadRect.h = 100;

				/*CRIANDO AS CAIXAS DE COLISÃO*/
				
				/*
					do lazy foo

				*/
				
				int dogVaiVolta = 0;
				int vivo = 1;
				int fechar = 0;

				while(fechar != 1){

					
					inicioGetTick = SDL_GetTicks();//tempo em milisegundos
					movimentoInimigo(&dRect_inimigoPos.loadRect,&sRect_inimigoPos.loadRect,&dogVaiVolta,vivo);
					
					caixaInimigo.loadRect.x = dRect_inimigoPos.loadRect.x;
					caixaInimigo.loadRect.y = dRect_inimigoPos.loadRect.y;
					gatoMorreu(&catJoePosicao.loadRect,&dRect_inimigoPos.loadRect, catJoePosicao.loadRect,dRect_inimigoPos.loadRect,&catPosicao.loadRect);
		
					


						
						
						naoPassaDoLimiteDaJanela(&catJoePosicao.loadRect);
						
						if(GATOUP){
							snow(&catJoePosicao.loadRect,&catPosicao.loadRect,catJoePosicao.loadRect,caixaBlocoChao.loadRect);
							emma(&catJoePosicao.loadRect,&catPosicao.loadRect,catJoePosicao.loadRect,caixaBlocoRight2.loadRect);
							
							cair(&catJoePosicao.loadRect);
							arrow(&catJoePosicao.loadRect,catJoePosicao.loadRect,caixaBlocoMovel2.loadRect);
							felicity(&catJoePosicao.loadRect,catJoePosicao.loadRect,caixaBlocoLeft.loadRect);
						}else{
							if(catJoePosicao.loadRect.x >= 449 && catJoePosicao.loadRect.x <= 526 && catJoePosicao.loadRect.y < 432){
								catJoePosicao.loadRect.y += 3;
								if(catPosicao.loadRect.y == 900)
									catJoePosicao.loadRect.x -= 1;

								if(catJoePosicao.loadRect.y >= 432)
									catJoePosicao.loadRect.y = 432;
								
							}
							henry(&catJoePosicao.loadRect);

							neal(&catJoePosicao.loadRect,&caixaBlocoRacao1.loadRect,catJoePosicao.loadRect,caixaBlocoRacao1.loadRect, racao,&sinalR,renderer);
						}

						if(PODEDESCER){
							obstaculosPosicao[3].loadRect.y += 3;

							if(obstaculosPosicao[3].loadRect.y >= 409){
								obstaculosPosicao[3].loadRect.y = 409;
								caixaBlocoMovel2.loadRect.y = 407;
								if(catJoePosicao.loadRect.x >= 526 && catJoePosicao.loadRect.x <= 668){
									BLOQUEIA_CAT = 0;

								}
								
								
							}
							regina(&catJoePosicao.loadRect,&catPosicao.loadRect,catJoePosicao.loadRect,caixaBlocoMovel2.loadRect);

							if(PODEANDAR){
								if(obstaculosPosicao[3].loadRect.x <= 435 && obstaculosPosicao[3].loadRect.y == 409){
									obstaculosPosicao[3].loadRect.x -= 2;
									catJoePosicao.loadRect.x -= 2;
									if(obstaculosPosicao[3].loadRect.x <= 235){
										obstaculosPosicao[3].loadRect.x = 235;
										caixaBlocoMovel2.loadRect.x = 180;
										PODEANDAR = 0;
										BLOQUEIA_CAT = 0;

									
									}
								}
								BATEU_BL2 = 0;
								BATEU_BL3 = 0;

							}
						}

						
						
						while(SDL_PollEvent(&event) != 0){ //Eventos de Teclado e Mouse

							if(event.type == SDL_QUIT){
								return 1;
							}
							if(event.type == SDL_KEYUP && event.key.keysym.sym == SDLK_ESCAPE){
								return  1;
							}

							if(event.type == SDL_KEYDOWN){
							
								if(state[SDL_SCANCODE_UP]){

									if(GATOMORREU){

									}else{
										GATOUP = 1;

										emma(&catJoePosicao.loadRect,&catPosicao.loadRect,catJoePosicao.loadRect,caixaBlocoRight2.loadRect);
										snow(&catJoePosicao.loadRect,&catPosicao.loadRect,catJoePosicao.loadRect,caixaBlocoChao.loadRect);
										
										cair(&catJoePosicao.loadRect);
										arrow(&catJoePosicao.loadRect,catJoePosicao.loadRect,caixaBlocoMovel2.loadRect);
										felicity(&catJoePosicao.loadRect,catJoePosicao.loadRect,caixaBlocoLeft.loadRect);

									}
									

								}
								if(state[SDL_SCANCODE_RIGHT]){

									if(GATOMORREU){

									}else{
										zangado(&catJoePosicao.loadRect,&catPosicao.loadRect,catJoePosicao.loadRect,caixaBlocoRight2.loadRect);

								
									

										thor(&catJoePosicao.loadRect,catJoePosicao.loadRect,caixaBlocoRight2.loadRect);


										soneca_Right(&catJoePosicao.loadRect,catJoePosicao.loadRect,caixaBlocoChao.loadRect);

									

										moveSpriteCatRight(&catPosicao.loadRect);
										

										if(lazyFoo(catJoePosicao.loadRect,caixaBlocoChao.loadRect))
											catJoePosicao.loadRect.y = 432;


										august(&catJoePosicao.loadRect,catJoePosicao.loadRect,caixaBlocoMovel2.loadRect);
										
										if(BLOQUEIA_CAT){

										}else
											pularMaisAlto_Right(&catJoePosicao.loadRect);
											//catJoePosicao.loadRect.x += 3;

										
										
									}
								
										
									


								}if(state[SDL_SCANCODE_LEFT] ){

									if(GATOMORREU){

									}else{
										zangado(&catJoePosicao.loadRect,&catPosicao.loadRect,catJoePosicao.loadRect,caixaBlocoRight2.loadRect);
									
										soneca(&catJoePosicao.loadRect,&catPosicao.loadRect,catJoePosicao.loadRect,caixaBlocoChao.loadRect);
										

										moveSpriteCatLeft(&catPosicao.loadRect);
										
										if(BLOQUEIA_CAT){

										}else

											pularMaisAlto_Left(&catJoePosicao.loadRect);

										wonderWoman(&catJoePosicao.loadRect,catJoePosicao.loadRect,caixaBlocoLeft.loadRect);
									}
									
									

								}
							
							}

						}
					

					//Limpando tela
					SDL_RenderClear(renderer);
					//background
					SDL_RenderCopy(renderer,backgroundTextura,NULL,NULL);
					//Blocos esquerdos
					renderCopySprites(renderer, blocosLeft, blocosPosicaoLeft, 4);
					//Blocos direitos
					renderCopySprites(renderer, blocosRight, blocosPosicaoRight, 4);
					//Chão
					renderCopySprites(renderer, chao, chaoPosicao, 8);
					//obstaculos
					renderCopySprites(renderer, obstaculos, obstaculosPosicao, 4);
	
					renderCopySprites(renderer, &sinalR, &sinalRPos, 1);
					renderCopySprites(renderer, racao, racaoPos, 1);

					//Gato Joe
					SDL_RenderCopy(renderer,catJoe.loadBloco,&catPosicao.loadRect,&catJoePosicao.loadRect);

					//Iniigo (Cachorro)
					SDL_RenderCopy(renderer,inimigo.loadBloco,&sRect_inimigoPos.loadRect,&dRect_inimigoPos.loadRect);

					//Imprimindo na tela
					SDL_RenderPresent(renderer);
					controlFrameRate(inicioGetTick);
					
			

			//}//else da IMG

		}

	





	//encerrando tudo
	


	SDL_DestroyTexture(sinalR.loadBloco);
	sinalR.loadBloco = NULL;

	SDL_DestroyTexture(racao[0].loadBloco);
	racao[0].loadBloco = NULL;

	SDL_DestroyTexture(inimigo.loadBloco);
	inimigo.loadBloco = NULL;


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

	

	SDL_DestroyTexture(catJoe.loadBloco);
	
	

}

int menu(){




	//SDL_Window *window = NULL;
	SDL_Surface *surfaceFont = NULL;
	
	SDL_Texture *backgroundTextura = NULL;
	SDL_Texture *jogarTexto = NULL;
	SDL_Texture *creditoTexto = NULL;
	SDL_Texture *comoJogarTexto = NULL;
	SDL_Texture *rankingTexto = NULL;
	SDL_Texture *sairTexto = NULL;
	SDL_Texture *patadegato = NULL;
	SDL_Texture *logo = NULL;
	SDL_Texture *som = NULL;
	SDL_Texture *notSom = NULL;
	Mix_Music *musica = NULL;
	Mix_Chunk *botao = NULL;


	

			//Inicializa Musica()
			if(Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,2,2048) < 0){
				printf("Erro ao inicializar musica %s",Mix_GetError());
			}
			//Musica de fundo
			musica = Mix_LoadMUS("../music/violao1.mp3");
			//Efeito sonoro botao
			botao = Mix_LoadWAV( "../music/beep.wav" );

			//criando renderer
			//renderer = SDL_CreateRenderer(window,-1,0);
			
			//criando textura da imagem de fundo
			backgroundTextura = carregarTextura(renderer,"../img/BG.png");

			//logo
			logo = carregarTextura(renderer,"../img/logo7.png");
			SDL_Rect logoRect;
			logoRect.w = 400;
			logoRect.h = 120;
			logoRect.x = (LARGURA_JANELA/2) - 200;
			logoRect.y = (ALTURA_JANELA/2) - 300;

			//som
			som = carregarTextura(renderer,"../img/som4.png");
			SDL_Rect somRect;
			somRect.w = 30;
			somRect.h = 25;
			somRect.x = LARGURA_JANELA - 200;
			somRect.y = ALTURA_JANELA - 800;

			//criando cor de fundo
			SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);

			//Inicando ttf para usar texto
			if(TTF_Init() < 0){
				printf("Error no TTF %s\n",TTF_GetError());
			}

			//Carregando fonte
			TTF_Font *font = TTF_OpenFont("../Merienda/Merienda-Regular.ttf",40);
			//Cor da fonte
			SDL_Color color = {0xFF,0xA5,0x00,0xFF};//aceita hexadecimal desse modo ou rgba  ex{155,155,255,255}
			//cor do mouse quando tem hover
			SDL_Color color2 = {155,155,255,255};
			
			//Códigos para o botão jogar
			//surface com codificacao utf-8 para aceitar acento
			SDL_Surface *jogarSurface = TTF_RenderUTF8_Solid(font,"Jogar",color);
			
			jogarTexto = SDL_CreateTextureFromSurface(renderer,jogarSurface);
			
			SDL_Rect jogarRect;
			
			jogarRect.x = (LARGURA_JANELA/2) - (jogarSurface->w/2);
			jogarRect.y = (ALTURA_JANELA/2) -100;//- (jogarSurface->h/2);
			jogarRect.w = jogarSurface->w;
			jogarRect.h = jogarSurface->h;

			SDL_QueryTexture(jogarTexto,NULL,NULL,&jogarRect.w,&jogarRect.h);

			//pata de gato
			patadegato = carregarTextura(renderer,"../img/patadegato2.png");
			SDL_Rect pataRect;
			pataRect.w = 25;
			pataRect.h = 25;
			pataRect.x = (LARGURA_JANELA/2) - (jogarSurface->w/2) - 40;
			pataRect.y = (ALTURA_JANELA/2) - (jogarSurface->w/2 + jogarSurface->h/2);

			SDL_FreeSurface(jogarSurface);
			jogarSurface = NULL;



			//Códigos para o botão como jogar

			//surface com codificacao utf-8 para aceitar acento
			SDL_Surface *comoJogarSurface = TTF_RenderUTF8_Solid(font,"Como Jogar",color);

			comoJogarTexto = SDL_CreateTextureFromSurface(renderer,comoJogarSurface);

			SDL_Rect comoJogarRect;

			comoJogarRect.x = (LARGURA_JANELA/2) - (comoJogarSurface->w/2);
			comoJogarRect.y = jogarRect.y + 60; //(600/2) - (comoJogarSurface->h/2) + (jogarRect.w%2); //+ jogarRect.h;//-30
			comoJogarRect.w = comoJogarSurface->w;
			comoJogarRect.h = comoJogarSurface->h;

			SDL_QueryTexture(creditoTexto,NULL,NULL,&comoJogarRect.w,&comoJogarRect.h);

			SDL_FreeSurface(comoJogarSurface);
			comoJogarSurface = NULL;

			//Códigos para o ranking

			//surface com codificacao utf-8 para aceitar acento
			SDL_Surface *rankingSurface = TTF_RenderUTF8_Solid(font,"Ranking",color);

			rankingTexto = SDL_CreateTextureFromSurface(renderer,rankingSurface);

			SDL_Rect rankingRect;

			rankingRect.x = (LARGURA_JANELA/2) - (rankingSurface->w/2);
			rankingRect.y = comoJogarRect.y + 60; //(600/2) - (creditoSurface->h/2) + (comoJogarRect.w);// + jogarRect.h;//+30
			rankingRect.w = rankingSurface->w;
			rankingRect.h = rankingSurface->h;

			SDL_QueryTexture(rankingTexto,NULL,NULL,&rankingRect.w,&rankingRect.h);

			SDL_FreeSurface(rankingSurface);
			rankingSurface = NULL;

			//Códigos para o botão crédito

			//surface com codificacao utf-8 para aceitar acento
			SDL_Surface *creditoSurface = TTF_RenderUTF8_Solid(font,"Créditos",color);

			creditoTexto = SDL_CreateTextureFromSurface(renderer,creditoSurface);

			SDL_Rect creditoRect;

			creditoRect.x = (LARGURA_JANELA/2) - (creditoSurface->w/2);
			creditoRect.y = rankingRect.y + 60; //(600/2) - (creditoSurface->h/2) + (comoJogarRect.w);// + jogarRect.h;//+30
			creditoRect.w = creditoSurface->w;
			creditoRect.h = creditoSurface->h;

			SDL_QueryTexture(creditoTexto,NULL,NULL,&creditoRect.w,&creditoRect.h);

			SDL_FreeSurface(creditoSurface);
			creditoSurface = NULL;

			//Códigos para sair

			//surface com codificacao utf-8 para aceitar acento
			SDL_Surface *sairSurface = TTF_RenderUTF8_Solid(font,"Sair",color);

			sairTexto = SDL_CreateTextureFromSurface(renderer,sairSurface);

			SDL_Rect sairRect;

			sairRect.x = (LARGURA_JANELA/2) - (sairSurface->w/2);
			sairRect.y = creditoRect.y + 60; //(600/2) - (creditoSurface->h/2) + (comoJogarRect.w);// + jogarRect.h;//+30
			sairRect.w = sairSurface->w;
			sairRect.h = sairSurface->h;

			SDL_QueryTexture(sairTexto,NULL,NULL,&sairRect.w,&sairRect.h);

			SDL_FreeSurface(sairSurface);
			sairSurface = NULL;

			//Controla GameLoop
			int fechar = 0;
			//parametros botao
			int x,y;
			//inicio do GetTicks
			Uint32 inicioGetTick;
			//Controlar eventos
			SDL_Event event;
			
			//Tocando música de fundo
			Mix_PlayMusic(musica,-1);

			while(fechar != 1){

				inicioGetTick = SDL_GetTicks();

				while(SDL_PollEvent(&event) != 0){
					if(event.type == SDL_QUIT){
						return 1;
					}

					if(event.type == SDL_KEYUP && event.key.keysym.sym == SDLK_ESCAPE){
						return 1;
					}

					switch(event.type){
						case SDL_MOUSEMOTION:
							x = event.motion.x;
							y = event.motion.y;
							
							//Botao Jogar
							if(x >= jogarRect.x && x <= jogarRect.x+jogarRect.w && y >= jogarRect.y && y <= jogarRect.y+jogarRect.h){
									SDL_FreeSurface(jogarSurface);
									SDL_DestroyTexture(jogarTexto);
									jogarSurface = TTF_RenderUTF8_Solid(font,"Jogar",color2);
									jogarTexto = SDL_CreateTextureFromSurface(renderer,jogarSurface);
									pataRect.x = (LARGURA_JANELA/2) - (jogarSurface->w/2) - 40;
									pataRect.y = (ALTURA_JANELA/2) - (jogarSurface->w/2 + jogarSurface->h/2);
								
								/*if(jogarSelecionado != 1){
									jogarSelecionado = 1;
									
									
								}else{
									jogarSelecionado = 0;
									
								}*/
							}else{
									SDL_FreeSurface(jogarSurface);
									SDL_DestroyTexture(jogarTexto);
									jogarSurface = TTF_RenderUTF8_Solid(font,"Jogar",color);
									jogarTexto = SDL_CreateTextureFromSurface(renderer,jogarSurface);
							}	

							//Botao Como Jogar
							if(x >= comoJogarRect.x && x <= comoJogarRect.x+comoJogarRect.w && y >= comoJogarRect.y && y <= comoJogarRect.y+comoJogarRect.h){
									
								SDL_FreeSurface(comoJogarSurface);
								SDL_DestroyTexture(comoJogarTexto);
								comoJogarSurface = TTF_RenderUTF8_Solid(font,"Como Jogar",color2);
								comoJogarTexto = SDL_CreateTextureFromSurface(renderer,comoJogarSurface);
								pataRect.x = (LARGURA_JANELA/2) - (comoJogarSurface->w/2) - 40;
								pataRect.y = (ALTURA_JANELA/2) - 25;
								//comoJogarRect.y = jogarRect.y + 65;
									

							}else{
								
								SDL_FreeSurface(comoJogarSurface);
								SDL_DestroyTexture(comoJogarTexto);
								comoJogarSurface = TTF_RenderUTF8_Solid(font,"Como Jogar",color);
								comoJogarTexto = SDL_CreateTextureFromSurface(renderer,comoJogarSurface);
								
								//comoJogarRect.y = jogarRect.y + 60;
							}	

							//Botao ranking
							if(x >= rankingRect.x && x <= rankingRect.x+rankingRect.w && y >= rankingRect.y && y <= rankingRect.y+rankingRect.h){
									
								SDL_FreeSurface(rankingSurface);
								SDL_DestroyTexture(rankingTexto);
								rankingSurface = TTF_RenderUTF8_Solid(font,"Ranking",color2);
								rankingTexto = SDL_CreateTextureFromSurface(renderer,rankingSurface);
								pataRect.x = (LARGURA_JANELA/2) - (rankingSurface->w/2) - 40;
								pataRect.y = (ALTURA_JANELA/2) + 33;
							}else{
								
								SDL_FreeSurface(rankingSurface);
								SDL_DestroyTexture(rankingTexto);
								rankingSurface = TTF_RenderUTF8_Solid(font,"Ranking",color);
								rankingTexto = SDL_CreateTextureFromSurface(renderer,rankingSurface);
							}

							//Botao créditos
							if(x >= creditoRect.x && x <= creditoRect.x+creditoRect.w && y >= creditoRect.y && y <= creditoRect.y+creditoRect.h){
									
								SDL_FreeSurface(creditoSurface);
								SDL_DestroyTexture(creditoTexto);
								creditoSurface = TTF_RenderUTF8_Solid(font,"Créditos",color2);
								creditoTexto = SDL_CreateTextureFromSurface(renderer,creditoSurface);
								pataRect.x = (LARGURA_JANELA/2) - (creditoSurface->w/2) - 40;
								pataRect.y = (ALTURA_JANELA/2) + 94;
							}else{
								
								SDL_FreeSurface(creditoSurface);
								SDL_DestroyTexture(creditoTexto);
								creditoSurface = TTF_RenderUTF8_Solid(font,"Créditos",color);
								creditoTexto = SDL_CreateTextureFromSurface(renderer,creditoSurface);
							}

							//Botao sair
							if(x >= sairRect.x && x <= sairRect.x+sairRect.w && y >= sairRect.y && y <= sairRect.y+sairRect.h){
									
								SDL_FreeSurface(sairSurface);
								SDL_DestroyTexture(sairTexto);
								sairSurface = TTF_RenderUTF8_Solid(font,"Sair",color2);
								sairTexto = SDL_CreateTextureFromSurface(renderer,sairSurface);
								pataRect.x = (LARGURA_JANELA/2) - (sairSurface->w/2) - 40;
								pataRect.y = (ALTURA_JANELA/2) + 155;
							}else{
								
								SDL_FreeSurface(sairSurface);
								SDL_DestroyTexture(sairTexto);
								sairSurface = TTF_RenderUTF8_Solid(font,"Sair",color);
								sairTexto = SDL_CreateTextureFromSurface(renderer,sairSurface);
							}
						break;	
						case SDL_MOUSEBUTTONUP:
							x = event.motion.x;
							y = event.motion.y;
							printf("X%d\n",x);
							if(event.button.button == SDL_BUTTON_LEFT){
								if(x >= somRect.x && x <= somRect.x+somRect.w && y >= somRect.y && y <= somRect.y+somRect.h){
									
									//Trocar ícone do som
									if(som != NULL){
										SDL_DestroyTexture(som);
										som = NULL;
										notSom = carregarTextura(renderer,"../img/semsom1.png");
									}else{
										som = carregarTextura(renderer,"../img/som4.png");
										SDL_DestroyTexture(notSom);
										notSom = NULL;
									}
									
									
									//It's Work
									if( Mix_PlayingMusic() == 0 ){
									   //Play the music
									   Mix_PlayMusic(musica, -1 );
									}
									//If music is being played
									else{
									   //If the music is paused
									   if( Mix_PausedMusic() == 1 ){
									      //Resume the music
									      Mix_ResumeMusic();
									   }
									   //If the music is playing
									   else{
									      //Pause the music
									      Mix_PauseMusic();
									   }
									}
								}

								if(x >= jogarRect.x && x <= jogarRect.x+jogarRect.w && y >= jogarRect.y && y <= jogarRect.y+jogarRect.h){
									Mix_PlayChannel( -1,botao, 0 );
									SDL_DestroyTexture(patadegato);

									//Seria bom uma função, né?
									patadegato = NULL;
									SDL_DestroyTexture(logo);
									logo = NULL;
									SDL_DestroyTexture(jogarTexto);
									jogarTexto = NULL;
									SDL_DestroyTexture(creditoTexto);
									creditoTexto = NULL;
									SDL_DestroyTexture(comoJogarTexto);
									comoJogarTexto = NULL;
									SDL_DestroyTexture(rankingTexto);
									rankingTexto = NULL;
									SDL_DestroyTexture(sairTexto);
									sairTexto = NULL;
									SDL_DestroyTexture(som);
									som = NULL;
									SDL_DestroyTexture(notSom);
									notSom = NULL;
									Mix_FreeMusic(musica);
									musica = NULL;
									Mix_FreeChunk(botao);
									botao = NULL;
									return 2;
								}
								if(x >= sairRect.x && x <= sairRect.x+jogarRect.w && y >= sairRect.y && y <= sairRect.y+sairRect.h){
									Mix_PlayChannel( -1,botao, 0 );

									patadegato = NULL;
									SDL_DestroyTexture(logo);
									logo = NULL;
									SDL_DestroyTexture(jogarTexto);
									jogarTexto = NULL;
									SDL_DestroyTexture(creditoTexto);
									creditoTexto = NULL;
									SDL_DestroyTexture(comoJogarTexto);
									comoJogarTexto = NULL;
									SDL_DestroyTexture(rankingTexto);
									rankingTexto = NULL;
									SDL_DestroyTexture(sairTexto);
									sairTexto = NULL;
									SDL_DestroyTexture(som);
									som = NULL;
									SDL_DestroyTexture(notSom);
									notSom = NULL;
									Mix_FreeMusic(musica);
									musica = NULL;
									Mix_FreeChunk(botao);
									botao = NULL;
									
									fechar = 1;
									return 1;
								}
							//if(event.button.button == SDL_BUTTON_RIGHT){
							//	Mix_HaltMusic();
							//}
							break;
						}
					}//fim switch

					
				}//fim while event



				//Limpando tela
				SDL_RenderClear(renderer);
				//background
				SDL_RenderCopy(renderer,backgroundTextura,NULL,NULL);
				//pata de gato
				SDL_RenderCopy(renderer,patadegato,NULL,&pataRect);
				//Logo
				SDL_RenderCopy(renderer,logo,NULL,&logoRect);
				//Som
				SDL_RenderCopy(renderer,som,NULL,&somRect);
				//Not som
				SDL_RenderCopy(renderer,notSom,NULL,&somRect);
				//botoes
				SDL_RenderCopy(renderer,jogarTexto,NULL,&jogarRect);
				SDL_RenderCopy(renderer,comoJogarTexto,NULL,&comoJogarRect);
				SDL_RenderCopy(renderer,rankingTexto,NULL,&rankingRect);
				SDL_RenderCopy(renderer,creditoTexto,NULL,&creditoRect);
				SDL_RenderCopy(renderer,sairTexto,NULL,&sairRect);
				//Imprimindo na tela
				SDL_RenderPresent(renderer);

				//Frame Rate
				controlFrameRate(inicioGetTick);

			}//fim while gameLoop












		//}
	




	//encerrando tudo
	//SDL_DestroyWindow(window);
	//window = NULL;
	
	//SDL_DestroyTexture(backgroundTextura);
	//backgroundTextura = NULL;
	SDL_DestroyTexture(patadegato);
	patadegato = NULL;
	SDL_DestroyTexture(logo);
	logo = NULL;
	SDL_DestroyTexture(jogarTexto);
	jogarTexto = NULL;
	SDL_DestroyTexture(creditoTexto);
	creditoTexto = NULL;
	SDL_DestroyTexture(comoJogarTexto);
	comoJogarTexto = NULL;
	SDL_DestroyTexture(rankingTexto);
	rankingTexto = NULL;
	SDL_DestroyTexture(sairTexto);
	sairTexto = NULL;
	SDL_DestroyTexture(som);
	som = NULL;
	SDL_DestroyTexture(notSom);
	notSom = NULL;
	Mix_FreeMusic(musica);
	musica = NULL;
	Mix_FreeChunk(botao);
	botao = NULL;
	
	



}