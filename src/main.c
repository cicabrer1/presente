#include <stdio.h>
#include <raylib.h>
#include <math.h>

#include "level.h"
#include "draw.h"
#include "state.h"
#include "files.h"

int main(int argc, char const *argv[]){

    // Initialization
    const int screen_width = 800;
    const int screen_height = 600;

    InitWindow(screen_width,screen_height,"PrEsEnTe - ThE GaMe");
    
    InitAudioDevice();              // Initialize audio device
    Music music = LoadMusicStream("music/fondo.mp3");
    Music fin = LoadMusicStream("music/GameOver.mp3");
    Music winner = LoadMusicStream("music/winner.mp3");
    Sound sound = LoadSound("music/pium.mp3"); 
    
    SetTargetFPS(60);
    int time = 0;

    // Initialize level and fill randomly
    level *lvl = level_new(50,40);
    level_fill_random(lvl,6);

    // Initialize state (and add enemies)
    state *sta = state_new();
    state_populate_random(lvl,sta,40);
    int  a=0;
    int *puntaje = &a;

    // Main loop
    while(!WindowShouldClose()){
        // Update input depending if keys are pressed or not
        sta->button_state[0] = IsKeyDown(KEY_D);
        sta->button_state[1] = IsKeyDown(KEY_W);
        sta->button_state[2] = IsKeyDown(KEY_A);
        sta->button_state[3] = IsKeyDown(KEY_S);
        sta->button_state[4] = IsMouseButtonDown(MOUSE_LEFT_BUTTON);
        // Compute the angle the player is looking at from the mouse's position relative to the screen's center
        float mouse_y = GetMouseY()-GetScreenHeight()/2;
        float mouse_x = GetMouseX()-GetScreenWidth()/2;
        sta->aim_angle = atan2(-mouse_y,mouse_x);
        if (IsMouseButtonDown(MOUSE_LEFT_BUTTON)) PlaySound(sound);

        // Update the state
        state_update(lvl,sta,puntaje);

        // Drawing
        BeginDrawing();

            ClearBackground(RAYWHITE);

            draw_state(lvl, sta);

            if(sta->n_enemies != 0){
                PlayMusicStream(music);
                UpdateMusicStream(music);
                DrawText(FormatText("LIFETIME: %03i", sta->pla.ent.hp), 20, 40, 20, BLUE);
                DrawText(FormatText("SCORE: %03i", *puntaje), 20, 60, 20, BLUE);
                DrawText(FormatText("TIME: %03i seconds", time/60),20,80,20,BLUE);
                DrawText(FormatText("ENEMIES: %03i", sta->n_enemies), 20, 100, 20, BLUE);
                
                
                time+=1;
            }
            else if(sta->pla.ent.hp == 0){
                PlayMusicStream(fin);
                UpdateMusicStream(fin);
                DrawText(FormatText("GAME OVER! \nTiMe: %03i seconds \nwith\nScore: %03i ", time/60, *puntaje),100,150,56,RED);
                histore(puntaje);
            }
            else{
                PlayMusicStream(winner);
                UpdateMusicStream(winner);
                DrawText(FormatText("WINNER! \nTiMe: %03i seconds \nwith\nScore: %03i ", time/60, *puntaje),100,150,56,RED);
                histore(puntaje);
            }

        EndDrawing();

    }
    UnloadMusicStream(music);
    UnloadMusicStream(winner);   
    UnloadMusicStream(fin);   // Unload music stream buffers from RAM
    UnloadSound(sound);

    CloseAudioDevice();         // Close audio device (music streaming is automatically stopped)
    // Closer window
    CloseWindow();

    // Free memory
    state_free(sta);
    level_free(lvl);

    return 0;
}
