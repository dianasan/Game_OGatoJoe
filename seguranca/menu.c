int menu(){
	
	SDL_Surface *surfaceFont = NULL;	
	SDL_Texture *jogarTexto = NULL;
	SDL_Texture *creditoTexto = NULL;
	SDL_Texture *comoJogarTexto = NULL;
	SDL_Texture *rankingTexto = NULL;
	SDL_Texture *sairTexto = NULL;
	SDL_Texture *patadegato = NULL;
	SDL_Texture *logo = NULL;
	


	//Musica de fundo
	m2 = Mix_LoadMUS("../music/violao1-2.mp3");
	//Efeito sonoro botao
	
	//criando renderer
	//renderer = SDL_CreateRenderer(window,-1,0);
	
	//criando textura da imagem de fundo
	if(backgroundTextura != NULL){
		SDL_DestroyTexture(backgroundTextura);
		backgroundTextura = NULL;
		backgroundTextura = carregarTextura(renderer,"../img/BG.png");
	}else
		backgroundTextura = carregarTextura(renderer,"../img/BG.png");

	//logo
	logo = carregarTextura(renderer,"../img/logo7.png");
	SDL_Rect logoRect;
	logoRect.w = 400;
	logoRect.h = 120;
	logoRect.x = (LARGURA_JANELA/2) - 200;
	logoRect.y = (ALTURA_JANELA/2) - 300;

	//som
	if(som != NULL && !Mix_PausedMusic()){
		SDL_DestroyTexture(som);
		som = NULL;
		som = carregarTextura(renderer,"../img/som4.png");	
		printf("Sem 3\n");
		Mix_PlayMusic(m2,-1);
	}
	else if(notSom != NULL && Mix_PausedMusic()){
		SDL_DestroyTexture(notSom);
		notSom = NULL;
		notSom = carregarTextura(renderer,"../img/semsom1.png");
	}
	else if(!Mix_PausedMusic()){
		printf("Sem 2\n");
		SDL_DestroyTexture(som);
		som = NULL;
		som = carregarTextura(renderer,"../img/som4.png");
		Mix_PlayMusic(m2,-1);
	}

	if(som != NULL)
		botao = Mix_LoadWAV( "../music/beep.wav" );


	SDL_Rect somRect;
	somRect.w = 30;
	somRect.h = 25;
	somRect.x = LARGURA_JANELA - 100;
	somRect.y = ALTURA_JANELA/12;

	//criando cor de fundo
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);


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
	
	
	//Tocando música de fundo
	//Mix_PlayMusic(m2,-1);

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
								
								Mix_FreeChunk(botao);
								botao = NULL;
								
							}else{
								som = carregarTextura(renderer,"../img/som4.png");
								SDL_DestroyTexture(notSom);
								notSom = NULL;
								botao = Mix_LoadWAV( "../music/beep.wav" );
							}
							
							
							//It's Work
							if( Mix_PlayingMusic() == 0 ){
							   //Play the music
							   Mix_PlayMusic(m2, -1 );
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
							SDL_DestroyTexture(backgroundTextura);
							backgroundTextura = NULL;
							Mix_FreeMusic(m2);
							m2 = NULL;
							
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
							
							
							
							fechar = 1;
							return 1;
						}if(x >= creditoRect.x && x <= creditoRect.x+creditoRect.w && y >= creditoRect.y && y <= creditoRect.y+creditoRect.h){
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
							SDL_DestroyTexture(backgroundTextura);
							backgroundTextura = NULL;
							Mix_FreeMusic(m2);
							m2 = NULL;

							fechar = 1;
							return 5;
						}if(x >= rankingRect.x && x <= rankingRect.x+rankingRect.w && y >= rankingRect.y && y <= rankingRect.y+rankingRect.h){
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
							SDL_DestroyTexture(backgroundTextura);
							backgroundTextura = NULL;
							Mix_FreeMusic(m2);

							fechar = 1;
							return 4;
						}
					
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











	//encerra tudo
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
	Mix_FreeMusic(m2);
	m2 = NULL;

}