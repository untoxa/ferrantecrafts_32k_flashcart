#include <gbdk/platform.h>

#include <stdint.h>

#include "flasher.h"

extern uint8_t erase_flash() OLDCALL;                                 // erase FLASH sector
extern uint8_t write_flash(uint8_t * source, uint16_t size) OLDCALL;  // write data to FLASH

uint8_t flash_save_data(uint8_t * source, uint16_t size) {
    if (!erase_flash()) return 0;
    return write_flash(source, size);
}