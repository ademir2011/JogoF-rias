#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>
#include <cstdlib>
#include <ctime>
#include "Estrutura.h"
#include "Eventos.h"

int tela = 0;

SDL_Event Event;

void Eventos::evento(SDL_Surface* surface, SDL_Surface* telaPrimaria)
{
    bool close = false;
    //Enquanto não acontece nenhum evento (clique do mouse, teclado etc...) faz..
        while(SDL_PollEvent(&Event) != 0)
        {
            if(Event.type == SDL_QUIT)
                close = true;

            switch(tela)
            {
                case 0:

                    SDL_BlitSurface(telaPrimaria,NULL,surface,NULL);

                    break;

                default:
                    break;
            }
        }
}
