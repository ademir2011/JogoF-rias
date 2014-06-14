#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>
#include <cstdlib>
#include <ctime>
#include "Estrutura.h"
#include "Eventos.h"

int vol = 64;

using namespace std;

void Estrutura::carregaVideo(SDL_Window* window, SDL_Surface* surface, SDL_Surface* telaPrimaria){
    //Inicia e Verifica se o vídeo é criado
    if(SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        SDL_Init(SDL_INIT_VIDEO);
        cout << "Erro ao iniciar video! Codigo de erro: " << SDL_GetError();
    }
    else
    {   //Inicia a janela
        window = SDL_CreateWindow("Joinha", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
        //SDL_WINDOW_RESIZABLE redimenciona a janela, (maximiza, aumenta, diminui a tela...)

        //Verifica se da erro ao criar janela
        if(window == NULL)
            cout << "Erro ao criar janela! Codigo de erro: " << SDL_GetError();
        else
        {
            //Passa a janela para dentro da surface
            surface = SDL_GetWindowSurface(window);

        //CARREGA IMAGENS
        telaPrimaria = IMG_Load("image/telas/background.jpg");

            //Verifica se a imagem foi encontrada
            if(telaPrimaria == NULL)
            {
                cout<<"Alguma imagem não foi carregada corretamente, código do erro: " << SDL_GetError();
            }
        }
    }
}

//void Estrutura::carregaSom(){
//    if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 4096) == -1)
//    {
//        cout << "MIX_Init: " << Mix_GetError ;
//    }
//
//    Mix_Music *music = Mix_LoadMUS("music/sound1_sax.mp3");
//    Mix_PlayMusic(music, -1);
//    Mix_Volume(-1, vol);
//    Mix_VolumeMusic(vol);
//}
