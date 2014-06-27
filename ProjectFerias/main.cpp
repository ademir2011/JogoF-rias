#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

using namespace std;

ALLEGRO_DISPLAY *display            = NULL;
ALLEGRO_BITMAP *planoFundo          = NULL;
ALLEGRO_EVENT_QUEUE *fila_eventos   = NULL;

int main()
{
	if (!al_init())                 cout<<"Erro init";
	if (!al_init_image_addon())     cout<<"Erro addon image";
    if (!al_install_mouse())        cout<<"Erro mouse";
    if (!al_install_keyboard())     cout<<"Erro keyboard!";

    display = al_create_display(800, 600);

    if (!display)                   cout<<"Erro display";

    al_clear_to_color(al_map_rgb(0, 0, 0));

    planoFundo                  = al_load_bitmap("images/planoFundo.png");

	if (!planoFundo)                cout << "Erro ao carregar imagens!";

	fila_eventos = al_create_event_queue();
    if (!fila_eventos)
    {
        cout<<"Falha ao criar fila de eventos";
        al_destroy_display(display);
        return -1;
    }

    al_register_event_source(fila_eventos, al_get_display_event_source(display));

	//al_draw_bitmap(planoFundo, 0, 0, 0);

    al_flip_display();

    al_draw_bitmap(planoFundo, 0, 0, 0);

    while(true)
    {
        ALLEGRO_EVENT evento;
        ALLEGRO_TIMEOUT timeout;
        al_init_timeout(&timeout, 0.01);

        int tem_eventos = al_wait_for_event_until(fila_eventos, &evento, &timeout);

        if (tem_eventos && evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
        {
            break;
        }

        al_draw_bitmap(planoFundo, 0, 0, 0);

        al_flip_display();
    }


	al_destroy_bitmap(planoFundo);
	al_destroy_display(display);

    return 0;
}
