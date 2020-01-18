#include "fases.c"
#include "pause.c"
#include "gameOver.c"
#include "venceuTela.c"

int main(){

	//SDL_Window *window = NULL;
	//SDL_Texture *backgroundTextura = NULL;
	//SDL_Texture *blocos = NULL;
	//SDL_Renderer *renderer = NULL;
	SDL_Texture *sinal = NULL;
	SDL_Texture *caixa = NULL;
	SDL_Texture *gatoJoe = NULL;
	
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
	
	Bloco sinalR2;
	PosicaoBloco sinalRPos2;

	Bloco racao[3];
	PosicaoBloco racaoPos[3];

	Bloco leite;
	PosicaoBloco leitePos;

	Bloco timerImg;
	PosicaoBloco timerImgPos;
	SDL_Texture *zeroTexto = NULL;
	SDL_Texture *minTexto = NULL;
	SDL_Texture *sepaTexto = NULL;
	SDL_Texture *segTexto = NULL;

	SDL_Surface *minSurface = NULL;
	SDL_Surface *sepaSurface = NULL;
	SDL_Surface *segSurface = NULL;
	SDL_Surface *zeroSurface = NULL;

	SDL_Rect minRect;
	SDL_Rect segRect;
	SDL_Rect sepaRect;
	SDL_Rect zeroRect;

	SDL_Texture* fase;
	SDL_Surface* faseSurface;
	SDL_Rect faseRect;

	Bloco vidaImg;
	PosicaoBloco vidaImgPos;
	SDL_Texture *vidaTextura = NULL;
	SDL_Surface *vidaSurface = NULL;
	SDL_Rect vidaRect;

	Bloco coin[5];
	PosicaoBloco dRectCoin[5];
	PosicaoBloco sRectCoin[5];
	Bloco coinImg;
	PosicaoBloco coinImgPos;
	SDL_Texture *coinTextura = NULL;
	SDL_Surface *coinSurface = NULL;
	SDL_Rect coinRect;

	//Controlar eventos
	//SDL_Event event;
	int reboot = 0;
	
	if(iniciarSDL()){
		window = criarJanela();

		if(window != NULL){
		
			if(iniciarIMG()){

				if(iniciarTTF()){//Inicando ttf para usar texto

					//Inicializa Musica()
					if(Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,2,2048) < 0){
						printf("Erro ao inicializar musica %s",Mix_GetError());
					}
					
					//Musica de fundo
					musica = Mix_LoadMUS("../music/procura.wav");
					//Tocando música de fundo
					Mix_PlayMusic(musica,-1);

					//criando renderer
					renderer = SDL_CreateRenderer(window,-1,0);

					//criando textura da imagem de fundo
					backgroundTextura = carregarTextura(renderer,"../img/BG.png");
					
					criarChao(chao,chaoPosicao);

					criarBlocosEsquerdos(blocosLeft, blocosPosicaoLeft);

					criarBlocosDireitos(blocosRight, blocosPosicaoRight);

					iniciarObstaculos(obstaculos, obstaculosPosicao);
					
					//Gato Joe, herói do jogo
					iniciarGato(&catJoe,&catPosicao,&catJoePosicao);
					
					//GATOMORREU = 1;
					//ALTURA_JANELA - catPosicao.loadRect.h - 28;
					//380-72
					iniciarSinais(&sinalR,&sinalR2,&sinalRPos,&sinalRPos2);
					
					iniciarRacao(racao,racaoPos);
					
					iniciarInimigo(&inimigo,&sRect_inimigoPos,&dRect_inimigoPos);

					iniciarLeite(&leite,&leitePos);

					timerImg.loadBloco = carregarTextura(renderer,"../img/timer8.png");
					timerImgPos.loadRect.w = 25;
					timerImgPos.loadRect.h = 25;
					timerImgPos.loadRect.x = 800;
					timerImgPos.loadRect.y = 10;

					for(int i = 0; i < 5; i++){
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

					
					//int limiteChao = ALTURA_JANELA - catPosicao.loadRect.h - 28;//492

					//Controla GameLoop
					int fechar = 0;
					//parametros botao
					int x,y;
					//inicio do GetTicks
					//Uint32 inicioGetTick;
					//Controlar eventos
					//SDL_Event event;
					
					SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);

					const Uint8 *state = SDL_GetKeyboardState(NULL);

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
					caixaBlocoRacao1.loadRect.x = 610;//605
					caixaBlocoRacao1.loadRect.y = 392;
					caixaBlocoRacao1.loadRect.w = 30;//1
					caixaBlocoRacao1.loadRect.h = 30;

					PosicaoBloco caixaBlocoRacao2;
					caixaBlocoRacao2.loadRect.x = 110;
					caixaBlocoRacao2.loadRect.y = 355;
					caixaBlocoRacao2.loadRect.w = 1;
					caixaBlocoRacao2.loadRect.h = 30;

					PosicaoBloco caixaBlocoRacao3;
					caixaBlocoRacao3.loadRect.x = 898;
					caixaBlocoRacao3.loadRect.y = 400;
					caixaBlocoRacao3.loadRect.w = 3;
					caixaBlocoRacao3.loadRect.h = 30;

					PosicaoBloco caixaInimigo;
					caixaInimigo.loadRect.w = 100;
					caixaInimigo.loadRect.h = 100;


					PosicaoBloco caixaLeite;
					caixaLeite.loadRect.x = 870;
					caixaLeite.loadRect.y = 100;
					caixaLeite.loadRect.w = 16;
					caixaLeite.loadRect.h = 64;

					PosicaoBloco caixaCoin[5];
					caixaCoin[0].loadRect.x = 284;//tam+10, também tem +14
					caixaCoin[0].loadRect.y = 472;
					caixaCoin[0].loadRect.w = 6;//tam-22(10), também 6
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



					/*CRIANDO AS CAIXAS DE COLISÃO*/
					
					int dogVaiVolta = 0;
					int vivo = 1;
					int rotornoVenceu = 0;
					
					//int c2 = 1;
					int venceuFase1 = 0;

					const Uint8* keyState;
				
					int contador = 60;//contador recebe o total de segundos que eu quero que o timer faça; 60 = 1 min, 180 = 3min
					int c2 = 1;//Auxilia o controle de quando vai haver o decremento de contador. Pra ficar no tempo certo :)
					int min;
					int seg;
					char st[2];
					char st2[3];
					char pokemon[3];

					//Carregando fonte
					TTF_Font *font = TTF_OpenFont("../Merienda/Merienda-Regular.ttf",22);
					TTF_Font *faseFont = TTF_OpenFont("../Merienda/Merienda-Regular.ttf",30);
					//cor do mouse quando tem hover
					SDL_Color color = {00,36,220,255};//22,22,248,255-00,36,220,255

					//Para exibir em que fase está
					faseSurface = TTF_RenderUTF8_Solid(faseFont,"Fase 1",color);
					faseRect.x = 500 - 40;
					faseRect.y = 6;
					faseRect.w = 40;
					faseRect.h = 40;
					fase = SDL_CreateTextureFromSurface(renderer,faseSurface);
					SDL_QueryTexture(fase,NULL,NULL,&faseRect.w,&faseRect.h);
					SDL_FreeSurface(faseSurface);
					faseSurface = NULL;

					//imagem da  contagem de vidas
					vidaImg.loadBloco = carregarTextura(renderer,"../img/vida7.png");
					vidaImgPos.loadRect.w = 45;//42
					vidaImgPos.loadRect.h = 42;
					vidaImgPos.loadRect.x = 100;
					vidaImgPos.loadRect.y = 6;

					//indicação de quantas vidas há
					char life[2];
					vidaRect.x = 150;
					vidaRect.y = 6;
					vidaRect.w = 40;
					vidaRect.h = 40;


					//imagem da  contagem de moedas
					coinImg.loadBloco = carregarTextura(renderer,"../img/coinPoint.png");
					coinImgPos.loadRect.w = 42;//42
					coinImgPos.loadRect.h = 39;
					coinImgPos.loadRect.x = 200;
					coinImgPos.loadRect.y = 6;

					//indicação de quantas vidas há
					char moeda[2];
					coinRect.x = 248;
					coinRect.y = 6;
					coinRect.w = 40;
					coinRect.h = 40;
					int frameTime = 0;

					
					while(fechar != 1){
						
						if(PAUSADO){
							if(VIDASGATO > 0){

								sprintf(life,"%d",VIDASGATO);
								vidaSurface = TTF_RenderUTF8_Solid(faseFont,life,color);
								vidaTextura = SDL_CreateTextureFromSurface(renderer,vidaSurface);
								SDL_QueryTexture(vidaTextura,NULL,NULL,&vidaRect.w,&vidaRect.h);
								SDL_FreeSurface(vidaSurface);
								vidaSurface = NULL;
								sprintf(moeda,"%d",PONTUACAO);
								coinSurface = TTF_RenderUTF8_Solid(faseFont,moeda,color);
								coinTextura = SDL_CreateTextureFromSurface(renderer,coinSurface);
								SDL_QueryTexture(coinTextura,NULL,NULL,&coinRect.w,&coinRect.h);
								SDL_FreeSurface(coinSurface);
								coinSurface = NULL;




							/* INÍCIO DO CONTADOR */
							if(contador < 60){
								min = 0;
								seg = contador;
								
							}
							else{
								min = contador / 60;
								seg = contador % 60;
							}

							sprintf(st,"%d",min);
							minSurface = TTF_RenderUTF8_Solid(font,st,color);
							minRect.x = 830;
							minRect.y = 6;
							minRect.w = 40;
							minRect.h = 40;
							minTexto = SDL_CreateTextureFromSurface(renderer,minSurface);
							SDL_QueryTexture(minTexto,NULL,NULL,&minRect.w,&minRect.h);
							SDL_FreeSurface(minSurface);
							minSurface = NULL;

							sepaSurface = TTF_RenderUTF8_Solid(font,":",color);
							sepaRect.x = 850;
							sepaRect.y = 6;
							sepaRect.w = 40;
							sepaRect.h = 40;
							sepaTexto = SDL_CreateTextureFromSurface(renderer,sepaSurface);
							SDL_QueryTexture(sepaTexto,NULL,NULL,&sepaRect.w,&sepaRect.h);
							SDL_FreeSurface(sepaSurface);
							sepaSurface = NULL;

							sprintf(pokemon,"%d",seg);

							if((c2 % 60) == 0)
								contador--;
							c2++;

							segSurface = TTF_RenderUTF8_Solid(font,pokemon,color);
							segRect.x = 860;//230
							segRect.y = 6;//- (jogarSurface->h/2);
							segRect.w = 40;
							segRect.h = 40;
							segTexto = SDL_CreateTextureFromSurface(renderer,segSurface);
							SDL_QueryTexture(segTexto,NULL,NULL,&segRect.w,&segRect.h);
							SDL_FreeSurface(segSurface);
							segSurface = NULL;

							if(seg < 10){
								//pra inserir o '0' quando os segundos for menor que 10
								segRect.x = 875;
								
								zeroSurface = TTF_RenderUTF8_Solid(font,"0",color);
								zeroRect.x = 860;
								zeroRect.y = 6;//- (jogarSurface->h/2);
								zeroRect.w = 40;
								zeroRect.h = 40;
								zeroTexto = SDL_CreateTextureFromSurface(renderer,zeroSurface);
								SDL_QueryTexture(zeroTexto,NULL,NULL,&zeroRect.w,&zeroRect.h);
								SDL_FreeSurface(zeroSurface);
								zeroSurface = NULL;
							}else{
								//remove o '0' da tela
								zeroTexto = NULL;
								
							}

							if(contador < 0){
								printf("\n********** GAME OVER ************** \n");
								catPosicao.loadRect.y = 400;
								catPosicao.loadRect.x = 900;
								fechar = 1;
							}

							/* FIM DO CONTADOR */

							frameTime++;
							if(FPS / frameTime == 6){
								frameTime = 0;
								for(int i = 0;i < 5; i++){
								
									sRectCoin[i].loadRect.x += 32;
									if(sRectCoin[i].loadRect.x > 164)
										sRectCoin[i].loadRect.x = 0;
								}
							}
							pegarMoeda(caixaCoin,coin,catJoePosicao.loadRect,caixaCoin,5);
							
							//moveInimigoRight(&frameTimeDog,&sRect_inimigoPos.loadRect);
							/*if(FPS / frameTimeDog == 10){
								frameTimeDog = 0;
								sRect_inimigoPos.loadRect.x += 100;
								if(sRect_inimigoPos.loadRect.x >= 1000)
									sRect_inimigoPos.loadRect.x = 0;
							}*/
							/*if((SDL_GetTicks() - inicioGetTick)  < ((1000 / 60) - (SDL_GetTicks() - inicioGetTick) ) ){
								printf("%d - %d\n",(SDL_GetTicks() - inicioGetTick),SDL_GetTicks());
								sRectCoin.loadRect.x += 32;
								if(sRectCoin.loadRect.x > 164)
									sRectCoin.loadRect.x = 0;
							}*/

							printf("I'm here x= %d y= %d\n",catJoePosicao.loadRect.x,catJoePosicao.loadRect.y);
							
							inicioGetTick = SDL_GetTicks();//tempo em milisegundos
							
							//dRect_inimigoPos.loadRect.x += 300.0 * (SDL_GetTicks() - inicioGetTick);
							movimentoInimigo(&dRect_inimigoPos.loadRect,&sRect_inimigoPos.loadRect,&dogVaiVolta,vivo);
							
							caixaInimigo.loadRect.x = dRect_inimigoPos.loadRect.x;
							caixaInimigo.loadRect.y = dRect_inimigoPos.loadRect.y;
							gatoMorreu(&catJoePosicao.loadRect,&dRect_inimigoPos.loadRect, catJoePosicao.loadRect,dRect_inimigoPos.loadRect,
								&catPosicao.loadRect,obstaculosPosicao,&caixaBlocoMovel2,&sinalR,racao,&caixaBlocoRacao1,&caixaBlocoRacao3,caixaCoin,coin);
				
							for(int i = 0; i < 5;i++){
								if(lazyFoo(catJoePosicao.loadRect, caixaCoin[i].loadRect))
									printf("Colisão moeda DINDIN %d\n",catJoePosicao.loadRect.x);
							
							}
							
							
							naoPassaDoLimiteDaJanela(&catJoePosicao.loadRect);
							
							if(GATOUP){
								snow(&catJoePosicao.loadRect,&catPosicao.loadRect,catJoePosicao.loadRect,caixaBlocoChao.loadRect);
								emma(&catJoePosicao.loadRect,&catPosicao.loadRect,catJoePosicao.loadRect,caixaBlocoRight2.loadRect);
								
								cair(&catJoePosicao.loadRect);
								arrow(&catJoePosicao.loadRect,catJoePosicao.loadRect,caixaBlocoMovel2.loadRect);
								felicity(&catJoePosicao.loadRect,catJoePosicao.loadRect,caixaBlocoLeft.loadRect);
								turtle(&catJoePosicao.loadRect);
								neal(&catJoePosicao.loadRect,&caixaBlocoRacao1.loadRect,&caixaBlocoRacao2.loadRect,
									&caixaBlocoRacao3.loadRect,catJoePosicao.loadRect,caixaBlocoRacao1.loadRect,
									caixaBlocoRacao2.loadRect,caixaBlocoRacao3.loadRect,racao,&sinalR,&sinalR2,renderer);
							}else{
								if(!BLOQUEIA_CAT){
									cairEntreBlocos(&catJoePosicao,&catPosicao);
								}
								
								henry(&catJoePosicao.loadRect);

								neal(&catJoePosicao.loadRect,&caixaBlocoRacao1.loadRect,&caixaBlocoRacao2.loadRect,
									&caixaBlocoRacao3.loadRect,catJoePosicao.loadRect,caixaBlocoRacao1.loadRect,
									caixaBlocoRacao2.loadRect,caixaBlocoRacao3.loadRect,racao,&sinalR,&sinalR2,renderer);

								venceuFase1 = venceu(&catJoePosicao.loadRect,&caixaLeite.loadRect,catJoePosicao.loadRect,caixaLeite.loadRect,&leite);
								if(venceuFase1 == 6){
									fechar = venceuTela(&reboot);
									
								
									if(reboot){
										printf("REINICIANDO...");
										iniciarObstaculos(obstaculos, obstaculosPosicao);					
										//Gato Joe, herói do jogo
										iniciarGato(&catJoe,&catPosicao,&catJoePosicao);
										
										//GATOMORREU = 1;
										//ALTURA_JANELA - catPosicao.loadRect.h - 28;
										//380-72
										iniciarSinais(&sinalR,&sinalR2,&sinalRPos,&sinalRPos2);
										
										iniciarRacao(racao,racaoPos);
										
										iniciarInimigo(&inimigo,&sRect_inimigoPos,&dRect_inimigoPos);

										iniciarLeite(&leite,&leitePos);
										for(int i = 0; i < 5; i++){
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

										/*CRIANDO AS CAIXAS DE COLISÃO*/
										
										caixaBlocoLeft.loadRect.x = 0;
										caixaBlocoLeft.loadRect.y = 385;//380
										caixaBlocoLeft.loadRect.w = 240;
										caixaBlocoLeft.loadRect.h = 60;

										
										caixaBlocoChao.loadRect.x = 510;//500-510
										caixaBlocoChao.loadRect.y = 525;//520
										caixaBlocoChao.loadRect.w = 42;//60 - 42
										caixaBlocoChao.loadRect.h = 60;

									

										
										caixaBlocoRight2.loadRect.x = 585;//585
										caixaBlocoRight2.loadRect.y = 418;//418
										caixaBlocoRight2.loadRect.w = 100;
										caixaBlocoRight2.loadRect.h = 50;

										
										caixaBlocoRight.loadRect.x = 760;
										caixaBlocoRight.loadRect.y = 180;
										caixaBlocoRight.loadRect.w = 240;
										caixaBlocoRight.loadRect.h = 60;


										
										caixaBlocoMovel2.loadRect.x = 408;//464
										caixaBlocoMovel2.loadRect.y = 155;//155
										caixaBlocoMovel2.loadRect.w = 140;
										caixaBlocoMovel2.loadRect.h = 60;

										
										caixaBlocoRacao1.loadRect.x = 610;//605
										caixaBlocoRacao1.loadRect.y = 392;
										caixaBlocoRacao1.loadRect.w = 30;//1
										caixaBlocoRacao1.loadRect.h = 30;

										
										caixaBlocoRacao2.loadRect.x = 110;
										caixaBlocoRacao2.loadRect.y = 355;
										caixaBlocoRacao2.loadRect.w = 1;
										caixaBlocoRacao2.loadRect.h = 30;

										
										caixaBlocoRacao3.loadRect.x = 898;
										caixaBlocoRacao3.loadRect.y = 400;
										caixaBlocoRacao3.loadRect.w = 3;
										caixaBlocoRacao3.loadRect.h = 30;

									
										caixaInimigo.loadRect.w = 100;
										caixaInimigo.loadRect.h = 100;


										
										caixaLeite.loadRect.x = 870;
										caixaLeite.loadRect.y = 100;
										caixaLeite.loadRect.w = 16;
										caixaLeite.loadRect.h = 64;

										
										caixaCoin[0].loadRect.x = 284;//tam+10, também tem +14
										caixaCoin[0].loadRect.y = 472;
										caixaCoin[0].loadRect.w = 6;//tam-22(10), também 6
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
										/*CRIANDO AS CAIXAS DE COLISÃO*/
										contador = 60;
										c2 = 1;
										min = 0;
										seg = 0;
										GATOUP = 0;
										BATEU_BL = 0;
										BATEU_BL2 = 0;
										BATEU_BL3 = 0;
										PODEDESCER = 0;
										PODEANDAR = 0;
										BLOQUEIA_CAT = 0;
										GATOMORREU = 0;
										PONTUACAO = 0;
										PAUSADO = 1;
										VIDASGATO = 3;
									}
								}
							}

							if(PODEDESCER){
								//obstaculosPosicao[3].loadRect.y += 3;

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

								if(racao[1].loadBloco == NULL){
									
									//obstaculosPosicao[3].loadRect.y -= 1;
									if(catJoePosicao.loadRect.x >= 197 && catJoePosicao.loadRect.x <= 323){
										
										if(catJoePosicao.loadRect.y >= 327){
											catJoePosicao.loadRect.y = 327;
											BLOQUEIA_CAT = 1;

										}else if(BLOQUEIA_CAT == 0){
											catJoePosicao.loadRect.y += 3;
										}
									}
									
									if(BLOQUEIA_CAT){

										if(obstaculosPosicao[3].loadRect.y > 175){
											
											obstaculosPosicao[3].loadRect.y -= 2;
											catJoePosicao.loadRect.y -= 2;
											if(obstaculosPosicao[3].loadRect.y <= 175){
												obstaculosPosicao[3].loadRect.y = 175;
												catJoePosicao.loadRect.y = 90;
											}
											
											
											//BLOQUEIA_CAT = 1;

										}else if(obstaculosPosicao[3].loadRect.y == 175){

											obstaculosPosicao[3].loadRect.x += 2;
											catJoePosicao.loadRect.x += 2;
											if(obstaculosPosicao[3].loadRect.x >= 616){
												obstaculosPosicao[3].loadRect.x = 616;
												///PODEANDAR = 0;
												BLOQUEIA_CAT = 0;
											}
										}
									}
										
								}else{
									if(obstaculosPosicao[3].loadRect.x == 235)
										obstaculosPosicao[3].loadRect.y = 409;
									else
										obstaculosPosicao[3].loadRect.y += 3;
								}
							}

							//para continuar movimento do gato independentemente da tecla
							/*keyState = SDL_GetKeyboardState(NULL);
							if(keyState[SDL_SCANCODE_RIGHT]){
								moveSpriteCatRight(&catPosicao.loadRect);
								catJoePosicao.loadRect.x += 1;
							}
							else if(keyState[SDL_SCANCODE_LEFT]){
								moveSpriteCatLeft(&catPosicao.loadRect);
								catJoePosicao.loadRect.x -= 1;
							}*/

								
								
							while(SDL_PollEvent(&event) != 0){ //Eventos de Teclado e Mouse
								
								encerrarJogo(event, &fechar);

								if(event.type == SDL_KEYDOWN){
								
									if(state[SDL_SCANCODE_UP]){

										if(GATOMORREU || BLOQUEIA_CAT){

										}else{
											GATOUP = 1;

											emma(&catJoePosicao.loadRect,&catPosicao.loadRect,catJoePosicao.loadRect,caixaBlocoRight2.loadRect);
											snow(&catJoePosicao.loadRect,&catPosicao.loadRect,catJoePosicao.loadRect,caixaBlocoChao.loadRect);
											
											cair(&catJoePosicao.loadRect);
											arrow(&catJoePosicao.loadRect,catJoePosicao.loadRect,caixaBlocoMovel2.loadRect);
											felicity(&catJoePosicao.loadRect,catJoePosicao.loadRect,caixaBlocoLeft.loadRect);
											turtle(&catJoePosicao.loadRect);

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


											august(&catJoePosicao.loadRect,catJoePosicao.loadRect,caixaBlocoMovel2.loadRect,racao);
											
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
											
											august_left(&catJoePosicao.loadRect,racao);

											moveSpriteCatLeft(&catPosicao.loadRect);
											
											if(BLOQUEIA_CAT){

											}else

												pularMaisAlto_Left(&catJoePosicao.loadRect);

											wonderWoman(&catJoePosicao.loadRect,catJoePosicao.loadRect,caixaBlocoLeft.loadRect);
										}
										
										

									}if(state[SDL_SCANCODE_P]){//PARA PAUSAR O JOGO

										pausado();
										
										if(PAUSADO == 2){
											//Coloca tudo de destruir dessa fase AQUI
											fechar = 1;
											//return 1; pra fechar o menu
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
			
							//Sinal que muda de vermelho para verde
							renderCopySprites(renderer, &sinalR, &sinalRPos, 1);
							renderCopySprites(renderer, &sinalR2, &sinalRPos2, 1);

							//Racao para pegadinhas e atalhos
							renderCopySprites(renderer, racao, racaoPos, 3);

							//Gato Joe
							SDL_RenderCopy(renderer,catJoe.loadBloco,&catPosicao.loadRect,&catJoePosicao.loadRect);

							//Inimigo (Cachorro)
							SDL_RenderCopy(renderer,inimigo.loadBloco,&sRect_inimigoPos.loadRect,&dRect_inimigoPos.loadRect);
							
							//Objetivo final, pegar o Leite
							renderCopySprites(renderer, &leite, &leitePos, 1);

							//Timer Imagem
							renderCopySprites(renderer, &timerImg, &timerImgPos, 1);			
							SDL_RenderCopy(renderer,minTexto,NULL,&minRect);
							SDL_RenderCopy(renderer,segTexto,NULL,&segRect);
							SDL_RenderCopy(renderer,sepaTexto,NULL,&sepaRect);
							SDL_RenderCopy(renderer,zeroTexto,NULL,&zeroRect);

							//Indicar a fase
							SDL_RenderCopy(renderer,fase,NULL,&faseRect);
							//Vida img do gato
							renderCopySprites(renderer, &vidaImg, &vidaImgPos, 1);
							//vida qtd
							SDL_RenderCopy(renderer,vidaTextura,NULL,&vidaRect);
							//moeda
							for(int i = 0;i < 5;i++)
								SDL_RenderCopy(renderer,coin[i].loadBloco,&sRectCoin[i].loadRect,&dRectCoin[i].loadRect);

							renderCopySprites(renderer, &coinImg, &coinImgPos, 1);
							SDL_RenderCopy(renderer,coinTextura,NULL,&coinRect);

							//Imprimindo na tela
							SDL_RenderPresent(renderer);

							//Frame Rate
							controlFrameRate(inicioGetTick);
						
							}else{//Else do vidasgato
								printf("*********** GAME OVER ***********\n");
								fechar = gameOver(&reboot);
								
								if(reboot){
								printf("REINICIANDO...");
								iniciarObstaculos(obstaculos, obstaculosPosicao);					
								//Gato Joe, herói do jogo
								iniciarGato(&catJoe,&catPosicao,&catJoePosicao);
								
								//GATOMORREU = 1;
								//ALTURA_JANELA - catPosicao.loadRect.h - 28;
								//380-72
								iniciarSinais(&sinalR,&sinalR2,&sinalRPos,&sinalRPos2);
								
								iniciarRacao(racao,racaoPos);
								
								iniciarInimigo(&inimigo,&sRect_inimigoPos,&dRect_inimigoPos);

								iniciarLeite(&leite,&leitePos);
								for(int i = 0; i < 5; i++){
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

								/*CRIANDO AS CAIXAS DE COLISÃO*/
								
								caixaBlocoLeft.loadRect.x = 0;
								caixaBlocoLeft.loadRect.y = 385;//380
								caixaBlocoLeft.loadRect.w = 240;
								caixaBlocoLeft.loadRect.h = 60;

								
								caixaBlocoChao.loadRect.x = 510;//500-510
								caixaBlocoChao.loadRect.y = 525;//520
								caixaBlocoChao.loadRect.w = 42;//60 - 42
								caixaBlocoChao.loadRect.h = 60;

							

								
								caixaBlocoRight2.loadRect.x = 585;//585
								caixaBlocoRight2.loadRect.y = 418;//418
								caixaBlocoRight2.loadRect.w = 100;
								caixaBlocoRight2.loadRect.h = 50;

								
								caixaBlocoRight.loadRect.x = 760;
								caixaBlocoRight.loadRect.y = 180;
								caixaBlocoRight.loadRect.w = 240;
								caixaBlocoRight.loadRect.h = 60;


								
								caixaBlocoMovel2.loadRect.x = 408;//464
								caixaBlocoMovel2.loadRect.y = 155;//155
								caixaBlocoMovel2.loadRect.w = 140;
								caixaBlocoMovel2.loadRect.h = 60;

								
								caixaBlocoRacao1.loadRect.x = 610;//605
								caixaBlocoRacao1.loadRect.y = 392;
								caixaBlocoRacao1.loadRect.w = 30;//1
								caixaBlocoRacao1.loadRect.h = 30;

								
								caixaBlocoRacao2.loadRect.x = 110;
								caixaBlocoRacao2.loadRect.y = 355;
								caixaBlocoRacao2.loadRect.w = 1;
								caixaBlocoRacao2.loadRect.h = 30;

								
								caixaBlocoRacao3.loadRect.x = 898;
								caixaBlocoRacao3.loadRect.y = 400;
								caixaBlocoRacao3.loadRect.w = 3;
								caixaBlocoRacao3.loadRect.h = 30;

							
								caixaInimigo.loadRect.w = 100;
								caixaInimigo.loadRect.h = 100;


								
								caixaLeite.loadRect.x = 870;
								caixaLeite.loadRect.y = 100;
								caixaLeite.loadRect.w = 16;
								caixaLeite.loadRect.h = 64;

								
								caixaCoin[0].loadRect.x = 284;//tam+10, também tem +14
								caixaCoin[0].loadRect.y = 472;
								caixaCoin[0].loadRect.w = 6;//tam-22(10), também 6
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
								/*CRIANDO AS CAIXAS DE COLISÃO*/
								contador = 60;
								c2 = 1;
								min = 0;
								seg = 0;
								GATOUP = 0;
								BATEU_BL = 0;
								BATEU_BL2 = 0;
								BATEU_BL3 = 0;
								PODEDESCER = 0;
								PODEANDAR = 0;
								BLOQUEIA_CAT = 0;
								GATOMORREU = 0;
								PONTUACAO = 0;
								PAUSADO = 1;
								VIDASGATO = 3;
							}
								//fechar = 1;
							}
						}else{

						}
						//do pausado
					
					}

				}//else do TTF

			}//else da IMG

		}//else da Window

	}//else do SDL_Init



	//encerrando tudo
	destruirWRBT();

	destruirFase1(&catJoe,&sinalR,&sinalR2,
	racao,&inimigo,&leite,chao,blocosLeft,blocosRight,obstaculos);

	SDL_DestroyTexture(timerImg.loadBloco);
	timerImg.loadBloco = NULL;
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
	SDL_DestroyTexture(vidaImg.loadBloco);
	vidaImg.loadBloco = NULL;
	SDL_DestroyTexture(vidaTextura);
	vidaTextura = NULL;
	for(int i = 0;i < 5;i++){
		SDL_DestroyTexture(coin[i].loadBloco);
		coin[i].loadBloco = NULL;
	}
	SDL_DestroyTexture(coinImg.loadBloco);
	coinImg.loadBloco = NULL;
	SDL_DestroyTexture(coinTextura);
	coinTextura = NULL;
	


	IMG_Quit();
	SDL_Quit();
	TTF_Quit();


	return 0;
}