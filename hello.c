#include "draw.h"
#include "input.h"
#include <stdio.h>

#define IDLE        0
#define IN_GAME     1
#define RESULT      2

int main(){
	// initialize and get graphics context
	Graphics* g = init();

    struct PADData pad_data;

    PADInit();
    int x = 10;
    int y = 8;

    int game_state = IDLE;

    int frame_counter = 0;
    int round_duration = 60 * 10; //10 seconds;
    int button_count = 0;
    int last_buttons = 0;
    int buttons_r = 0;
    int score = 0;
    int highscore = 0;
    int isHighscore = 0;

	while(1){
        // draw backgroung
        background(g, 0x00, 0x00, 0x00);

        //Read input data
        PADRead(&pad_data);

        buttons_r = (last_buttons & (~pad_data.btns_h));

        /*if(pad_data.btns_h & BUTTON_LEFT){
            x--;
        }
        if(pad_data.btns_h & BUTTON_RIGHT){
            x++;
        }
        if(pad_data.btns_h & BUTTON_DOWN){
            y++;
        }
        if(pad_data.btns_h & BUTTON_UP){
            y--;
        }*/

        drawStringf(g, 20, 0, "Highscore: %d", highscore);
        drawStringf(g, 30, 28, "PUSH A by Maschell", highscore);
        drawStringf(g, 0, 28, "Press PLUS to exit");

        printf(" pad: %08X %08X\n", pad_data.btns_h,buttons_r);

        if(game_state == IDLE){
            drawStringf(g, x, y, "Press MINUS to start!");
            if(pad_data.btns_h & BUTTON_MINUS){
                game_state = IN_GAME;
            }
        }else if(game_state == IN_GAME){
            frame_counter++;
            if(buttons_r & BUTTON_A){
                button_count++;
            }
            float secLeft = (round_duration - frame_counter) /60.0f;
            drawStringf(g, x, y, "Press A as fast as you can!");
            drawStringf(g, x, y+2, "Time left: %0.2f seconds!",secLeft);
            drawStringf(g, x, y+4, "Current score: %d", button_count);
            if(frame_counter > round_duration){
                score = button_count;
                button_count = 0;
                frame_counter = 0;
                if(score > highscore){
                    highscore = score;
                    isHighscore = 1;
                }
                game_state = RESULT;
            }
        }else if(game_state == RESULT){
            drawStringf(g, x, y, "Score: %d", button_count);
            drawStringf(g, x, y+2,"Press MINUS to try again.");
            if(isHighscore){
                drawStringf(g, x, y+4,"NEW HIGHSCORE!");
            }
            if(pad_data.btns_h & BUTTON_MINUS){
                game_state = IN_GAME;
                isHighscore = 0;
            }
        }

        if(pad_data.btns_h & BUTTON_PLUS){
            break;
        }
        update(g);
        usleep(16);
        last_buttons = pad_data.btns_h;
    }

	// clean up graphics
	deinit(g);
	PADDestroy();

	return 0;
}
