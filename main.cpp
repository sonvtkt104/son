
#include "CommonFunc.h"
#include "BaseObject.h"
#include "MainObject.h"
#include "ImpTimer.h"
#include "Barrier.h"
 
BaseObject g_background;

MainObject human_object;

bool InitData()
{
    bool success = true;
    int ret = SDL_Init(SDL_INIT_VIDEO);
    if (ret < 0)
        return false;

    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");

    g_window = SDL_CreateWindow("Game Control The Car",
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        SCREEN_WIDTH,
        SCREEN_HEIGHT,
        SDL_WINDOW_SHOWN);
       
    if (g_window == NULL)
    {
        success = false;
    }
    else
    {
        g_screen = SDL_CreateRenderer(g_window, -1, SDL_RENDERER_ACCELERATED);
        if (g_screen == NULL)
        {
            success = false;
        }
        else 
        {
            SDL_SetRenderDrawColor(g_screen, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR);
            int imgFlags = IMG_INIT_PNG;
            if (!(IMG_Init(imgFlags) && imgFlags))
            {
                success = false;
            } 

        }
    }
    return success;
}

bool LoadBackground()
{
    bool ret = g_background.LoadImg("img//Background.png", g_screen);
    if (ret == false)
        return false;

    return true;
}

void close()
{
    g_background.Free();
    SDL_DestroyRenderer(g_screen);
    g_screen = NULL;
    SDL_DestroyWindow(g_window);
    g_window = NULL;
    human_object.Free();
    IMG_Quit();
    SDL_Quit();

}

#undef main

int main(int argc, char* argv[])
{
    ImpTimer fps_timer;

    if (InitData() == false) 
        return -1;
    if (LoadBackground() == false)
        return -1;

    //MainObject
    human_object.SetRect(0, 320);
    bool ret = human_object.LoadImg("img//lsond.png", g_screen);
    if (ret == false)
        return -1;



    //Barrier
    Barrier* p_threat = new Barrier[NUM_BARRIER];
    for (int i = 0; i < NUM_BARRIER; i++)
    {
        Barrier* p_barrier = (p_threat + i);
        if (p_barrier)
        {
            ret = p_barrier->LoadImg("img//barrier.png", g_screen);
            if (ret == false)
            {
                return -1;
            }

            //int rand_y = rand() % 500;
            p_barrier->SetRect(SCREEN_WIDTH + i*300, /*rand_y*/300);
            p_barrier->set_x_xal(10);
        }
    }


    bool is_quit = false;
    while (!is_quit)
    {
        fps_timer.start();

        while (SDL_PollEvent(&g_event) != 0)
        {
            if (g_event.type == SDL_QUIT)
            {
                is_quit = true;
                break;
            }
            human_object.HandleInputAction(g_event);
            
        }

        SDL_SetRenderDrawColor(g_screen, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR);
        SDL_RenderClear(g_screen);


        g_background.Render(g_screen, NULL);

        human_object.HandleMove();
        human_object.Render(g_screen, NULL);
        


        //run barrier
        for (int j = 0; j < NUM_BARRIER; j++)
        {
            Barrier* p_barrier = (p_threat + j);
            if (p_barrier)
            {
                p_barrier->HandleMove(SCREEN_WIDTH, SCREEN_HEIGHT);
                p_barrier->Render(g_screen, NULL);
                
                SDL_RenderPresent(g_screen);

                //check va cham
                bool is_col = SDLCommonFunc::CheckCollision(human_object.GetRect(), p_barrier->GetRect());
                if (is_col)
                {
                    if (MessageBox(NULL, L"Yasuo 15p_GG_GAME OVER!", L"GG", MB_OK) == IDOK)
                    {
                        delete[] p_threat;
                        close();
                        return -1;
                    }
                }
            }
        }


        SDL_RenderPresent(g_screen);
        
        int real_imp_time = fps_timer.get_ticks();
        int time_one_frame = 1000 / FRAME_PER_SECOND;//ms

        if (real_imp_time < time_one_frame)
        {
            int delay_time = time_one_frame - real_imp_time;
            if (delay_time >= 0)
            {
                SDL_Delay(delay_time);
            }
        }
        
    }
    delete [] p_threat;
      
    close();

    return 0;
}