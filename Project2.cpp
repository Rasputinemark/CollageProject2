#include"Project2.h"


int main(int argc, char* args[])
{
	initVacant();
	 
	SDL_Rect goBoardRect;
	goBoardRect.x = 0;
	goBoardRect.y = 0;
	goBoardRect.w = SCREEN_WIDTH;
	goBoardRect.h = SCREEN_HEIGHT;

	SDL_Rect goRect;
	goRect.x = 240;
	goRect.y = 240;
	goRect.w = 32;
	goRect.h = 32;

	SDL_Rect wgoRect;
	wgoRect.x = 240;
	wgoRect.y = 240;
	wgoRect.w = 32;
	wgoRect.h = 32;

	//initialize the 
	for (int i = 0; i < 15; i++)
		for (int j = 0; j < 15; j++) {
			vacant[i][j] = true;
			black[i][j] = false;
			white[i][j] = false;
		}

	if (!init())
		cout << "Failed to initialize!" << endl;
	else
	{	
		//load the go, white go and board image
		if (!loadMedia())
			cout << "Failed to load Media" << endl;
		else {
			//blit the image onto screen surface and control the go's position by using keyboard
			SDL_BlitScaled(genImageBoard, NULL, genScreenSurface, &goBoardRect);

			while (GetAsyncKeyState(VK_ESCAPE) == false) {

				srand(time(NULL));
				int random = rand() % 4;

				SDL_UpdateWindowSurface(genWindow);

				if (GetAsyncKeyState(VK_DOWN) && goRect.y < SCREEN_HEIGHT - 2 * goRect.h)
					goRect.y += goRect.h;

				else if (GetAsyncKeyState(VK_RIGHT) && goRect.x < SCREEN_WIDTH - 2 * goRect.w)
					goRect.x += goRect.w;
				else if (GetAsyncKeyState(VK_LEFT) && goRect.x > 16)
					goRect.x -= goRect.w;
				else if (GetAsyncKeyState(VK_UP) && goRect.y > 16)
					goRect.y -= goRect.h;



				//press space key to settle the position of black go and then computer will settle the white go randomly
				if (GetAsyncKeyState(VK_SPACE) && vacant[(goRect.x - 16) / 32][(goRect.y - 16) / 32] == true) {
					SDL_BlitScaled(genImageGo, NULL, genScreenSurface, &goRect);

					Sleep(100);
					switch (random) {
					case 0:
						wgoRect.x = goRect.x + wgoRect.w; // white go at the right side of black go 
						break;
					case 1:
						wgoRect.x = goRect.x - wgoRect.w;
						break;
					case 2:
						wgoRect.y = goRect.y + wgoRect.h;
						break;
					case 3:
						wgoRect.y = goRect.y - wgoRect.h;
					}

					if (vacant[(wgoRect.x - 16) / 32][(wgoRect.y - 16) / 32] == true) // there have a vacant, then put the white go
						SDL_BlitScaled(genImageWGo, NULL, genScreenSurface, &wgoRect);
					else { // no vacant, find another available place
						int i = 0;
						int j = 0;
						while (vacant[i][j] == true) {
							wgoRect.x = 16 + 32 * i;
							wgoRect.y = 16 + 32 * j;
							i++;
							j++;
						}
						SDL_BlitScaled(genImageWGo, NULL, genScreenSurface, &wgoRect);

						cout << "not vacant" << endl;
					}
					//check the position taken by the go
					black[(goRect.x - 16) / 32][(goRect.y - 16) / 32] = true;
					white[(wgoRect.x - 16) / 32][(wgoRect.y - 16) / 32] = true;
					//check vacant
					vacant[(wgoRect.x - 16) / 32][(wgoRect.y - 16) / 32] = false;
					vacant[(goRect.x - 16) / 32][(goRect.y - 16) / 32] = false;
					step++;
					if (step == 225) {
						cout << "No more vacant, Game is fair!"<<endl;
						close();
					}

					// determine whether the player is win
					int goNumLongi = 0; // longitudinal go counter
					int goNumLateral = 0;//lateral go counter
					int goNumRObliq = 0;//right oblique go counter
					int goNumLObliq = 0;//left oblique go counter

					for (int i = 0; i < 15; i++) {
						for (int j = 0; j < 15; j++) {
							if (black[i][j] == true) {
								if (black[i][j] == black[i][j + 1]) {
									goNumLongi++;
									if (goNumLongi >= 5) {

										cout << "You Win" << endl;
										cout << "End Game, press esc to quit" << endl;

										Sleep(1000);
										close();
									}
								}
								else if (black[i][j] == black[i+1][j]) {
									goNumLateral++;
									if (goNumLateral >= 5) {

										cout << "You Win" << endl;
										cout << "End Game, press esc to quit" << endl;

										Sleep(1000);
										close();
									}
								}
								if (black[i][j] == black[i+1][j+1]) {
									goNumRObliq++;
									if (goNumRObliq >= 5) {

										cout << "You Win" << endl;
										cout << "End Game, press esc to quit" << endl;

										Sleep(1000);
										close();
									}
								}
								if (black[i][j] == black[i+1][j -1]) {
									goNumLObliq++;
									if (goNumLObliq >= 5) {

										cout << "You Win" << endl;
										cout << "End Game, press esc to quit" << endl;

										Sleep(1000);
										close();
									}
								}

							}
						}
					}
				}

				Sleep(100);
			}
		}
	}
	close();
	return 0;
}