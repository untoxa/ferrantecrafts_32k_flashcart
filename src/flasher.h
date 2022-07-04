#ifndef __FLASHER_H_INCLUDE
#define __FLASHER_H_INCLUDE

#include <string.h>
#include <stdint.h>

extern void flash_sector_address;

inline void flash_restore_data(uint8_t * dest, uint16_t size) {
    memcpy(dest, &flash_sector_address, size);
}

uint8_t flash_save_data(uint8_t * source, uint16_t size);

#endif