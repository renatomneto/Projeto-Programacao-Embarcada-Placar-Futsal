# 1 "delay.c"
# 1 "<built-in>" 1
# 1 "<built-in>" 3
# 288 "<built-in>" 3
# 1 "<command line>" 1
# 1 "<built-in>" 2
# 1 "C:/Program Files (x86)/Microchip/MPLABX/v5.40/packs/Microchip/PIC18Fxxxx_DFP/1.2.26/xc8\\pic\\include\\language_support.h" 1 3
# 2 "<built-in>" 2
# 1 "delay.c" 2
# 1 "./delay.h" 1



void atraso_ms(unsigned int);
void atraso_s(unsigned int);
# 1 "delay.c" 2


void atraso_ms(unsigned int t) {
    volatile unsigned char j, k;
    volatile unsigned int i;
    for (i = 0; i < t; i++) {
        for (j = 0; j < 41; j++) {
            for (k = 0; k < 3; k++);
        }
    }
}


void atraso_s(unsigned int t) {
    volatile unsigned char j, k;
    volatile unsigned int i;
    for (i = 0; i < (t * 1000); i++) {
        for (j = 0; j < 41; j++) {
            for (k = 0; k < 3; k++);
        }
    }
}
