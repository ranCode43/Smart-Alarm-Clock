#ifndef ENCODER_H
#define ENCODER_H

void encoderInit();
void IRAM_ATTR onEncoderChange();
void IRAM_ATTR onEncoderBtn();

#endif
