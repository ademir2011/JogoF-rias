#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>
#include <cstdlib>
#include <ctime>
#include "Estrutura.h"
#include "Eventos.h"

SDL_Window* window          = NULL;
SDL_Surface* surface        = NULL;
SDL_Surface* telaPrimaria   = NULL;

int main(int argc, char *argv[]){

    Estrutura estrutura;
    Eventos eventos;

    srand(time(NULL));

   // estrutura.carregaSom();
    estrutura.carregaVideo(window, surface, telaPrimaria);

    bool close = false;

    //Enquanto a janela estiver executando faz..
    while(!close){

        //Eventos que acontecens no decorrer dos loop's
        eventos.evento(surface, telaPrimaria);

        //--------------------------------------Inicio da funcao principal do jogo-------------------------

        //Atualiza a janela
        SDL_UpdateWindowSurface(window);

        //--------------------------------------Fim da funcao principal do jogo----------------------------
    }

    //Libera a memória, onde a janela está alocada
    SDL_DestroyWindow(window);
    //Fecha o SDL
    SDL_Quit();
    return 0;
}
