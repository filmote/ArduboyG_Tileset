#define ABG_IMPLEMENTATION
#define ABG_SYNC_PARK_ROW
#define SPRITESU_IMPLEMENTATION

#define SPRITESU_OVERWRITE
#define SPRITESU_PLUSMASK
#define SPRITESU_FX

#include <ArduboyFX.h>  
#include "src/ArduboyG.h"
#include "src/SpritesU.hpp"

#include "fxdata/fxdata.h"

ArduboyGBase_Config<ABG_Mode::L4_Triplane> arduboy;

uint16_t frameCount = 0;
uint8_t i = 0;

void update() {

    frameCount++;

    if (frameCount % 8 == 0) {

        i++;
        if (i >= 4) i = 0;

    }
    
}

void loop() {

    FX::enableOLED();
    arduboy.waitForNextPlane(BLACK);
    FX::disableOLED();


    if (arduboy.needsUpdate()) update();

    uint16_t currentPlane = arduboy.currentPlane();

    SpritesU::drawOverwriteFX(0, 0, PPOT, (i * 3) + currentPlane);    

}

void setup() {      

    arduboy.boot();
    arduboy.startGray();

    FX::begin(FX_DATA_PAGE, FX_SAVE_PAGE);

}
