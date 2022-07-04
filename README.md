# Batteryless save example
Saving and loading of up to 1KB of WRAM into and from the "Ferrante Crafts 32KB V2" FLASH ROM cart.

GBDK-2020 required, but assembly code may be used by itself.

Location of flash sector is determined by the _flash_sector_address constant, must be a multiple of 1024.
By default it points to the last kilobyte: 0x7C00. The whole sector is erased at once, you can not patch 
individual bytes in it.

Demo rom usage:
# flash the example ROM onto the "Ferrante Crafts 32KB V2" FLASH ROM cart
# switch on the Game Boy, press A or B
# press START
# recycle Game Boy power, it should say "LAST BUTTON: A " or "LAST BUTTON: B "

This code was also used in the "GB-Wordyl" game by @bbbbbr: https://github.com/bbbbbr/gb-wordle

Enjoy.