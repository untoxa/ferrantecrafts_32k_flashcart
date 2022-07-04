#include <gbdk/platform.h>

#include <stdint.h>
#include <string.h>

#include "flasher.h"

extern const unsigned char font_data[];
extern void font_len();

const unsigned char textA[] = "LAST BUTTON: A ";
const unsigned char textB[] = "LAST BUTTON: B ";

const unsigned char error[] = "          !ERROR!          ";
const unsigned char success[] = "            !SUCCESS!            ";

uint8_t buffer[32*32];

void main() {
    SHOW_BKG;

    if (_cpu == CGB_TYPE) {
        cgb_compatibility();
        cpu_fast();
    }

    // load some font
    set_bkg_1bpp_data(0x20, (uint8_t)&font_len, font_data);

    flash_restore_data(buffer, sizeof(buffer));
    
    uint8_t redraw = 1;

    while (TRUE) {
        uint8_t joy = joypad();
        if (joy & J_A) {
            memcpy(buffer, textA, sizeof(textA) - 1);
            redraw = 1;
            waitpadup();
        } else if (joy & J_B) {
            memcpy(buffer, textB, sizeof(textB) - 1);
            redraw = 1;
            waitpadup();
        } else if (joy & J_START) {
            waitpadup();
            if (!flash_save_data(buffer, sizeof(buffer))) set_bkg_tiles(5, 6, 9, 3, error); else set_bkg_tiles(4, 6, 11, 3, success);
        } else if (joy & J_SELECT) {
            waitpadup();
            flash_restore_data(buffer, sizeof(buffer));
            redraw = 1;
        }

        if (redraw) {
            set_bkg_tiles(0, 0, 32, 32, buffer);
            redraw = 0;
        }

        wait_vbl_done();
    } 

}