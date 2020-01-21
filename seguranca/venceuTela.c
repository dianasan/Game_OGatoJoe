
int venceuTela(int* reboot){

	SDL_Surface *surfaceFont = NULL;
	
	SDL_Texture *voltarTexto = NULL;
	SDL_Texture *jogarnovamenteTexto = NULL;
	SDL_Texture *patadegato = NULL;

	SDL_Texture *totalTexto = NULL;
	SDL_Texture *pontosTexto = NULL;
	SDL_Surface *totalSurface = NULL;
	SDL_Surface *pontosSurface = NULL;
	SDL_Rect totalRect;
	SDL_Rect pontosRect;


	//parametros botao
	int x,y;


	//Musica de fundo
	//musica = Mix_LoadMUS("../music/violao1-2.mp3");
	//Efeito sonoro botao
	botao = Mix_LoadWAV( "../music/beep.wav" );


				//criando textura da imagem de fundo
				backgroundTextura = carregarTextura(renderer,"../img/venceu.png");

				
				int fechar = 0;
				//inicio do GetTicks
				Uint32 inicioGetTick;
				float flPreviousTime = 0;
				float flCurrentTime = SDL_GetTicks();

				SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);

				const Uint8 *state = SDL_GetKeyboardState(NULL);

				//Inicando ttf para usar texto
			/*if(TTF_Init() < 0){
				printf("Error no TTF %s\n",TTF_GetError());
			}*/

			//Carregando fonte
			TTF_Font *font = TTF_OpenFont("../Merienda/Merienda-Regular.ttf",40);
			//Cor da fonte
			SDL_Color color = {0xFF,0xA5,0x00,0xFF};//aceita hexadecimal desse modo ou rgba  ex{155,155,255,255}
			//cor do mouse quando tem hover
			SDL_Color color2 = {155,155,255,255};
			
			//Códigos para o botão voltar
			//surface com codificacao utf-8 para aceitar acento
			SDL_Surface *voltarSurface = TTF_RenderUTF8_Solid(font,"Menu",color);
			
			voltarTexto = SDL_CreateTextureFromSurface(renderer,voltarSurface);
			
			SDL_Rect voltarRect;
			
			voltarRect.x = (LARGURA_JANELA/12) - (voltarSurface->w/12);
			voltarRect.y = (ALTURA_JANELA/2) + (voltarSurface->h/2) + voltarSurface->w + 60;//- (voltar->h/2);
			voltarRect.w = voltarSurface->w;
			voltarRect.h = voltarSurface->h;

			SDL_QueryTexture(voltarTexto,NULL,NULL,&voltarRect.w,&voltarRect.h);

			 // código para o botão jogar novamente
			//surface com codificacao utf-8 para aceitar acento
			SDL_Surface *jogarnovamenteSurface = TTF_RenderUTF8_Solid(font,"Jogar Novamente",color);
			
			jogarnovamenteTexto = SDL_CreateTextureFromSurface(renderer,jogarnovamenteSurface);
			
			SDL_Rect jogarnovamenteRect;
			
			jogarnovamenteRect.x = (LARGURA_JANELA/2) - (jogarnovamenteSurface->w/2);
			jogarnovamenteRect.y = (ALTURA_JANELA/2) + (voltarSurface->h/2) + voltarSurface->w + 60;//- (voltar->h/2);
			jogarnovamenteRect.w = jogarnovamenteSurface->w - 60;
			jogarnovamenteRect.h = jogarnovamenteSurface->h;

			SDL_QueryTexture(jogarnovamenteTexto,NULL,NULL,&jogarnovamenteRect.w,&jogarnovamenteRect.h);


			//pata de gato
			patadegato = carregarTextura(renderer,"../img/patadegato2.png");
			SDL_Rect pataRect;
			pataRect.w = 25;
			pataRect.h = 25;
			pataRect.x = (LARGURA_JANELA/12) - (voltarSurface->w/12) - 40;
			pataRect.y = (ALTURA_JANELA + 7) - (voltarSurface->w/2 + voltarSurface->h/2);


			SDL_FreeSurface(voltarSurface);
			voltarSurface = NULL;

			//Para música
			//som
			som = carregarTextura(renderer,"../img/som4.png");
			SDL_Rect somRect;
			somRect.w = 30;
			somRect.h = 25;
			somRect.x = LARGURA_JANELA - 100;
			somRect.y = ALTURA_JANELA/12;

			TTF_Font *font2 = TTF_OpenFont("../Merienda/Merienda-Regular.ttf",25);
			totalSurface = TTF_RenderUTF8_Solid(font2,"Total de Moedas: ",color);
			totalTexto = SDL_CreateTextureFromSurface(renderer,totalSurface);
			
			
			totalRect.x = 72;
			totalRect.y = ALTURA_JANELA/12;//- (jogarSurface->h/2);
			totalRect.w = totalSurface->w;
			totalRect.h = totalSurface->h;

			SDL_QueryTexture(totalTexto,NULL,NULL,&totalRect.w,&totalRect.h);
			SDL_FreeSurface(totalSurface);
			totalSurface = NULL;

			char moeda[2];
			sprintf(moeda,"%d",PONTUACAO);
			pontosSurface = TTF_RenderUTF8_Solid(font2,moeda,color);
			pontosTexto = SDL_CreateTextureFromSurface(renderer,pontosSurface);
			
			
			pontosRect.x = 218 + 72;//totalSurface + totalRect.x
			pontosRect.y = ALTURA_JANELA/12;//- (jogarSurface->h/2);
			pontosRect.w = pontosSurface->w;
			pontosRect.h = pontosSurface->h;
			SDL_QueryTexture(pontosTexto,NULL,NULL,&pontosRect.w,&pontosRect.h);
			SDL_FreeSurface(pontosSurface);
			pontosSurface = NULL;
			


			//Tocando música de fundo
			Mix_PlayMusic(musica,-1);

				while(fechar != 1){

					

					inicioGetTick = SDL_GetTicks();//tempo em milisegundos

					while(SDL_PollEvent(&event) != 0){ //Eventos de Teclado e Mouse

							if(event.type == SDL_QUIT){
								fechar = 1;
								
								return 1;
							}
							if(event.type == SDL_KEYUP && event.key.keysym.sym == SDLK_ESCAPE){
								fechar = 1;
								
								return  1;
							}
					

						switch(event.type){
						case SDL_MOUSEMOTION:
							x = event.motion.x;
							y = event.motion.y;

							//Botao Voltar
							if(x >= voltarRect.x && x <= voltarRect.x+voltarRect.w && y >= voltarRect.y && y <= voltarRect.y+voltarRect.h){
									SDL_FreeSurface(voltarSurface);
									SDL_DestroyTexture(voltarTexto);
									voltarSurface = TTF_RenderUTF8_Solid(font,"Menu",color2);
									voltarTexto = SDL_CreateTextureFromSurface(renderer,voltarSurface);
									pataRect.x = (LARGURA_JANELA/12) - (voltarSurface->w/12) - 40;
									pataRect.y = (ALTURA_JANELA + 7) - (voltarSurface->w/2 + voltarSurface->h/2);

									
							}else{
									SDL_FreeSurface(voltarSurface);
									SDL_DestroyTexture(voltarTexto);
									voltarSurface = TTF_RenderUTF8_Solid(font,"Menu",color);
									voltarTexto = SDL_CreateTextureFromSurface(renderer,voltarSurface);
							}	

			
							//botão jogar novamente
							if(x >= jogarnovamenteRect.x && x <= jogarnovamenteRect.x+jogarnovamenteRect.w && y >= jogarnovamenteRect.y && y <= jogarnovamenteRect.y+jogarnovamenteRect.h){
									SDL_FreeSurface(jogarnovamenteSurface);
									SDL_DestroyTexture(jogarnovamenteTexto);
									jogarnovamenteSurface = TTF_RenderUTF8_Solid(font,"Jogar Novamente",color2);
									jogarnovamenteTexto = SDL_CreateTextureFromSurface(renderer,jogarnovamenteSurface);
									pataRect.x = 10 + voltarSurface->w + ((LARGURA_JANELA/2) - (jogarnovamenteSurface->w));
									pataRect.y = (ALTURA_JANELA + 7) - (voltarSurface->w/2 + voltarSurface->h/2);

									
							}else{
									SDL_FreeSurface(jogarnovamenteSurface);
									SDL_DestroyTexture(jogarnovamenteTexto);
									jogarnovamenteSurface = TTF_RenderUTF8_Solid(font,"Jogar Novamente",color);
									jogarnovamenteTexto = SDL_CreateTextureFromSurface(renderer,jogarnovamenteSurface);
							}	


							break;
						case SDL_MOUSEBUTTONUP:
							x = event.motion.x;
							y = event.motion.y;

							if(event.button.button == SDL_BUTTON_LEFT){

								if(x >= voltarRect.x && x <= voltarRect.x+voltarRect.w && y >= voltarRect.y && y <= voltarRect.y+voltarRect.h){
									printf("Clicou menu\n");
									Mix_PlayChannel( -1,botao, 0 );
									backgroundTextura = carregarTextura(renderer,"../img/BG.png");
									SDL_DestroyTexture(patadegato);
									patadegato = NULL;
									SDL_DestroyTexture(voltarTexto);
									voltarTexto = NULL;
									SDL_DestroyTexture(jogarnovamenteTexto);
									jogarnovamenteTexto = NULL;
									SDL_DestroyTexture(totalTexto);
									totalTexto = NULL;
									SDL_DestroyTexture(pontosTexto);
									pontosTexto = NULL;
									fechar = 1;
									return 1;//vai pro menu, mas primeiro dá uma passadinha na fase1
								}

								if(x >= jogarnovamenteRect.x && x <= jogarnovamenteRect.x+jogarnovamenteRect.w && y >= jogarnovamenteRect.y && y <= jogarnovamenteRect.y+jogarnovamenteRect.h){
									printf("Clicou jogar novamente\n");
									Mix_PlayChannel( -1,botao, 0 );
									

									backgroundTextura = carregarTextura(renderer,"../img/BG.png");
									SDL_DestroyTexture(patadegato);
									patadegato = NULL;
									SDL_DestroyTexture(voltarTexto);
									voltarTexto = NULL;
									SDL_DestroyTexture(jogarnovamenteTexto);
									jogarnovamenteTexto = NULL;
									SDL_DestroyTexture(totalTexto);
									totalTexto = NULL;
									SDL_DestroyTexture(pontosTexto);
									pontosTexto = NULL;
									printf("CLIQUEI EM SAIR DO GAMEOVER\n");
									*reboot = 1;
									fechar = 1;
									return 0;
									//jogar = 1;
									//return 1;
								}

								if(x >= somRect.x && x <= somRect.x+somRect.w && y >= somRect.y && y <= somRect.y+somRect.h){
									printf("X%d\n",x);
									printf("X%d\n",y);
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
							}
						break;

						}

				}
					//Limpando tela
					SDL_RenderClear(renderer);
					//background
					SDL_RenderCopy(renderer,backgroundTextura,NULL,NULL);
					//pata de gato
					SDL_RenderCopy(renderer,patadegato,NULL,&pataRect);
					//voltar
					SDL_RenderCopy(renderer,voltarTexto,NULL,&voltarRect);
					//jogar novamente
					SDL_RenderCopy(renderer,jogarnovamenteTexto,NULL,&jogarnovamenteRect);
					//Som
					SDL_RenderCopy(renderer,som,NULL,&somRect);
					//Not som
					SDL_RenderCopy(renderer,notSom,NULL,&somRect);
					//Total de pontos
					SDL_RenderCopy(renderer,totalTexto,NULL,&totalRect);
					SDL_RenderCopy(renderer,pontosTexto,NULL,&pontosRect);
					//Imprimindo na tela
					SDL_RenderPresent(renderer);
					//Frame Rate
					controlFrameRate(inicioGetTick);
					
				
			}


	//encerrando tudo
	
	SDL_DestroyTexture(patadegato);
	patadegato = NULL;
	SDL_DestroyTexture(voltarTexto);
	voltarTexto = NULL;
	SDL_DestroyTexture(jogarnovamenteTexto);
	jogarnovamenteTexto = NULL;
	SDL_DestroyTexture(totalTexto);
	totalTexto = NULL;
	SDL_DestroyTexture(pontosTexto);
	pontosTexto = NULL;


}