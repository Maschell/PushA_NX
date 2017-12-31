#include "input.h"
#include<libtransistor/nx.h>

void PADInit(){
    hid_init();
}

void PADDestroy(){
    hid_finalize();
}

static void readInputInternal(struct PADData* data,hid_controller_state_entry_t ent ){
    data->btns_h |= ((ent.button_state & JOYPAD_A)? 		BUTTON_A : 0);
    data->btns_h |= ((ent.button_state & JOYPAD_B)? 		BUTTON_B : 0);
    data->btns_h |= ((ent.button_state & JOYPAD_UP)? 		BUTTON_UP : 0);
    data->btns_h |= ((ent.button_state & JOYPAD_DOWN)? 		BUTTON_DOWN : 0);
    data->btns_h |= ((ent.button_state & JOYPAD_LEFT)? 		BUTTON_LEFT : 0);
    data->btns_h |= ((ent.button_state & JOYPAD_RIGHT)?		BUTTON_RIGHT : 0);
    data->btns_h |= ((ent.button_state & JOYPAD_START)?		BUTTON_PLUS : 0);
    data->btns_h |= ((ent.button_state & JOYPAD_SELECT)?	BUTTON_MINUS : 0);
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
