#include "fases.c"
/*

	ESTÁ COM BUG A TROCA DE IMAGEM DO SOM

*/
int main(){

	SDL_Surface *surfaceFont = NULL;
	SDL_Window *window = NULL;
	SDL_Texture *backgroundTextura = NULL;
	SDL_Renderer *renderer = NULL;
	SDL_Texture *retomarTexto = NULL;
	SSL_Texture *reiniciarTexto = NULL;
	SDL_Texture *patadegato = NULL;
	SDL_Texture *som = NULL;
	SDL_Texture *notSom = NULL;
	Mix_Music *musica = NULL;
	Mix_Chunk *botao = NULL;

	//parametros botao
	int x,y;

	

	if(SDL_Init(SDL_INIT_EVERYTHING) < 0){

		printf("Error ao iniciar SDL %s\n",SDL_GetError());

	}else{
		//Criando janela
		window = SDL_CreateWindow("Menu",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,LARGURA_JANELA,ALTURA_JANELA,SDL_WINDOW_SHOWN);

		if(window == NULL){

			printf("Error na janela %s\n",SDL_GetError());

		}else{
			//Inicializa IMG_Load()
			if(IMG_Init(IMG_INIT_PNG) < 0){

				printf("Erro ao iniciar IMG_INIT %s\n",IMG_GetError());

			}else{
				//Inicializa Musica()
				if(Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,2,2048) < 0){
					printf("Erro ao inicializar musica %s",Mix_GetError());
				}
				//Musica de fundo
				musica = Mix_LoadMUS("../music/violao1.mp3");
				//Efeito sonoro botao
				botao = Mix_LoadWAV( "../music/beep.wav" );

				//criando renderer
				renderer = SDL_CreateRenderer(window,-1,0);

				//criando textura da imagem de fundo
				backgroundTextura = carregarTextura(renderer,"../img/pause.png");

				
				int fechar = 0;
				//inicio do GetTicks
				Uint32 inicioGetTick;
				float flPreviousTime = 0;
				float flCurrentTime = SDL_GetTicks();

				SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);

				const Uint8 *state = SDL_GetKeyboardState(NULL);

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
			
			//Códigos para o botão retomar
			//surface com codificacao utf-8 para aceitar acento
			SDL_Surface *retomarSurface = TTF_RenderUTF8_Solid(font,"Retomar",color);
			
			retomarTexto = SDL_CreateTextureFromSurface(renderer,retomarSurface);
			
			SDL_Rect retomarRect;
			
			retomarRect.x = (LARGURA_JANELA/2) - (retomarSurface->w/2);
			retomarRect.y = (ALTURA_JANELA/2);//- (retomar->h/2);
			retomarRect.w = retomarSurface->w;
			retomarRect.h = retomarSurface->h;

			SDL_QueryTexture(retomarTexto,NULL,NULL,&retomarRect.w,&retomarRect.h);

			 // código para o botão jogar novamente
			//surface com codificacao utf-8 para aceitar acento
			SDL_Surface *reiniciarSurface = TTF_RenderUTF8_Solid(font,"Reiniciar",color);
			
			reiniciarTexto = SDL_CreateTextureFromSurface(renderer,reiniciarSurface);
			
			SDL_Rect reiniciarRect;
			
			reiniciarRect.x = (LARGURA_JANELA/4) - (retomarSurface->w/4);
			reiniciarRect.y = (ALTURA_JANELA/4);//- (retomar->h/2);
			reiniciarRect.w = reiniciarSurface->w;
			reiniciarRect.h = reiniciarSurface->h;

			SDL_QueryTexture(reiniciarTexto,NULL,NULL,&reiniciarRect.w,&reiniciarRect.h);


			//pata de gato
			patadegato = carregarTextura(renderer,"../img/patadegato2.png");
			SDL_Rect pataRect;
			pataRect.w = 25;
			pataRect.h = 25;
			pataRect.x = (LARGURA_JANELA/2) - (retomarSurface->w/2) - 40;
			pataRect.y = (ALTURA_JANELA/2) - (retomarSurface->w/2 + retomarSurface->h/2);


			SDL_FreeSurface(retomarSurface);
			retomarSurface = NULL;

			//Para música
			//som
			som = carregarTextura(renderer,"../img/som4.png");
			SDL_Rect somRect;
			somRect.w = 30;
			somRect.h = 25;
			somRect.x = LARGURA_JANELA - 100;
			somRect.y = ALTURA_JANELA/12;

			//Tocando música de fundo
			Mix_PlayMusic(musica,-1);

				while(fechar != 1){

					

					inicioGetTick = SDL_GetTicks();//tempo em milisegundos

					while(SDL_PollEvent(&event) != 0){ //Eventos de Teclado e Mouse

							encerrarJogo(event, &fechar);
					}

						switch(event.type){
						case SDL_MOUSEMOTION:
							x = event.motion.x;
							y = event.motion.y;

							//Botao retomar
							if(x >= retomarRect.x && x <= retomarRect.x+retomarRect.w && y >= retomarRect.y && y <= retomarRect.y+retomarRect.h){
									SDL_FreeSurface(retomarSurface);
									SDL_DestroyTexture(retomarTexto);
									retomarSurface = TTF_RenderUTF8_Solid(font,"Retomar",color2);
									retomarTexto = SDL_CreateTextureFromSurface(renderer,retomarSurface);
									pataRect.x = (LARGURA_JANELA/2) - (retomarSurface->w/2) - 40;
									pataRect.y = (ALTURA_JANELA/2) - (retomarSurface->w/2 + retomarSurface->h/2);

									
							}else{
									SDL_FreeSurface(retomarSurface);
									SDL_DestroyTexture(retomarTexto);
									retomarSurface = TTF_RenderUTF8_Solid(font,"Retomar",color);
									retomarTexto = SDL_CreateTextureFromSurface(renderer,retomarSurface);
							}	

							//botão jogar novamente
							if(x >= reiniciarRect.x && x <= reiniciarRect.x+reiniciarRect.w && y >= reiniciarRect.y && y <= reiniciarRect.y+reiniciarRect.h){
									SDL_FreeSurface(reiniciarSurface);
									SDL_DestroyTexture(reiniciarTexto);
									reiniciarSurface = TTF_RenderUTF8_Solid(font,"Reiniciar",color2);
									reiniciarTexto = SDL_CreateTextureFromSurface(renderer,reiniciarSurface);
									pataRect.x = (LARGURA_JANELA/4) - (reiniciarSurface->w/4) - 40;
									pataRect.y = (ALTURA_JANELA/4) - (reiniciarSurface->w/2 + reiniciarSurface->h/2);

									
							}else{
									SDL_FreeSurface(reiniciarSurface);
									SDL_DestroyTexture(reiniciarTexto);
									reiniciarSurface = TTF_RenderUTF8_Solid(font,"Reiniciar",color);
									reiniciarTexto = SDL_CreateTextureFromSurface(renderer,reiniciarSurface);
							}	


							break;
						case SDL_MOUSEBUTTONUP:
							x = event.motion.x;
							y = event.motion.y;

							if(event.button.button == SDL_BUTTON_LEFT){

								if(x >= retomarRect.x && x <= retomarRect.x+retomarRect.w && y >= retomarRect.y && y <= retomarRect.y+retomarRect.h){
									printf("Clicou retomar\n");
									//Mix_PlayChannel( -1,botao, 0 );

									//fechar = 1;
									//return 1;
								}

								if(x >= reiniciarRect.x && x <= reiniciarRect.x+reiniciarRect.w && y >= reiniciarRect.y && y <= reiniciarRect.y+reiniciarRect.h){
									printf("Clicou reiniciar\n");
									//Mix_PlayChannel( -1,botao, 0 );

									//fechar = 0;
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
					//retomar
					SDL_RenderCopy(renderer,retomarTexto,NULL,&retomarRect);
					//jogar novamente
					SDL_RenderCopy(renderer,reiniciarTexto,NULL,&reiniciarRect);
					//Som
					SDL_RenderCopy(renderer,som,NULL,&somRect);
					//Not som
					SDL_RenderCopy(renderer,notSom,NULL,&somRect);
					//Imprimindo na tela
					SDL_RenderPresent(renderer);
					//Frame Rate
					controlFrameRate(inicioGetTick);
					
				}
			}
		}
	}


	//encerrando tudo
	SDL_DestroyWindow(window);
	window = NULL;
	SDL_DestroyRenderer(renderer);
	renderer = NULL;
	SDL_DestroyTexture(backgroundTextura);
	backgroundTextura = NULL;
	SDL_DestroyTexture(patadegato);
	patadegato = NULL;
	SDL_DestroyTexture(retomarTexto);
	retomarTexto = NULL;
	SDL_DestroyTexture(reiniciarTexto);
	reiniciarTexto = NULL;
	SDL_DestroyTexture(som);
	som = NULL;
	SDL_DestroyTexture(notSom);
	notSom = NULL;
	Mix_FreeMusic(musica);
	musica = NULL;
	Mix_FreeChunk(botao);
	botao = NULL;

	IMG_Quit();
	TTF_Quit();
	Mix_Quit();
	SDL_Quit();


	return 0;
}