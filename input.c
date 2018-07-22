#include "input.h"
#include<libtransistor/nx.h>

void PADInit(){
    hid_init();
}

void PADDestroy(){
    hid_finalize();
}

static void readInputInternal(struct PADData* data,hid_controller_state_entry_t ent ){
    data->btns_h |= ((ent.button_state & JOYPAD_A)? 		PAD_BUTTON_A : 0);
    data->btns_h |= ((ent.button_state & JOYPAD_B)? 		PAD_BUTTON_B : 0);
    data->btns_h |= ((ent.button_state & JOYPAD_UP)? 		PAD_BUTTON_UP : 0);
    data->btns_h |= ((ent.button_state & JOYPAD_DOWN)? 		PAD_BUTTON_DOWN : 0);
    data->btns_h |= ((ent.button_state & JOYPAD_LEFT)? 		PAD_BUTTON_LEFT : 0);
    data->btns_h |= ((ent.button_state & JOYPAD_RIGHT)?		PAD_BUTTON_RIGHT : 0);
    data->btns_h |= ((ent.button_state & JOYPAD_START)?		PAD_BUTTON_PLUS : 0);
    data->btns_h |= ((ent.button_state & JOYPAD_SELECT)?	PAD_BUTTON_MINUS : 0);
}

void PADRead(struct PADData* data){
	// reset buttons
	data->btns_h = 0b00000000;

    // scan for controller
    hid_controller_t* num = hid_get_shared_memory()->controllers;
    hid_controller_t* num8 = hid_get_shared_memory()->controllers + 8 ;

    hid_controller_state_entry_t ent = num->main.entries[num->main.latest_idx];
    hid_controller_state_entry_t ent8 = num8->main.entries[num8->main.latest_idx];

    // process inputs
    readInputInternal(data,ent);
    readInputInternal(data,ent8);
}
