#include "bits.h"
#include "config.h"
#include <pic18f4520.h>
#include "io.h"
#include "delay.h"
#include "ssd.h"
#include "timer.h"
#include "keypad.h"
#include "teclado.h"
#include "lcd.h"
#include "pwm.h"
#include "rtc.h"

void chevrolet(void) {
    unsigned char i, j;

    unsigned char chevrolete_logo[32] = {
        0x00, 0x03, 0x04, 0x08, 0x10, 0x1F, 0x00, 0x00,
        0x0F, 0x18, 0x00, 0x00, 0x00, 0x18, 0x0F, 0x00,
        0x1C, 0x07, 0x00, 0x00, 0x00, 0x07, 0x1C, 0x00,
        0x00, 0x1F, 0x01, 0x02, 0x04, 0x18, 0x00, 0x00
    };
    lcd_cmd(0x40); //Configura para a primeira posição de memória
    for (i = 0; i < 32; i++) {
        lcd_dat(chevrolete_logo[i]);
    }
    lcd_cmd(L_L3 + 3);
    lcd_dat(0);
    lcd_dat(1);
    lcd_dat(2);
    lcd_dat(3);
    lcd_str("Chevrolet");

    for (j = 0; j < 1; j++) {
        for (i = 0; i < 19; i++) {
            atraso_ms(150);
            lcd_cmd(0x18); //move pra direita
        }

        for (i = 0; i < 20; i++) {
            atraso_ms(150);
            lcd_cmd(0x1C); //move pra esquerda
        }
    }
}

void unifeilogo(void) {
    unsigned char i, j;
    lcd_cmd(0x40); //Configura para a primeira posição de memória
    //Cada linha é representada por um caracter
    char logo[48] = {
        0x01, 0x03, 0x03, 0x0E, 0x1C, 0x18, 0x08, 0x08, //0,0
        0x11, 0x1F, 0x00, 0x01, 0x1F, 0x12, 0x14, 0x1F, //0,1
        0x10, 0x18, 0x18, 0x0E, 0x07, 0x03, 0x02, 0x02, //0,2
        0x08, 0x18, 0x1C, 0x0E, 0x03, 0x03, 0x01, 0x00, //1,0
        0x12, 0x14, 0x1F, 0x08, 0x00, 0x1F, 0x11, 0x00, //1,1
        0x02, 0x03, 0x07, 0x0E, 0x18, 0x18, 0x10, 0x00 //1,2
    };

    lcd_cmd(0x40); //Configura para a primeira posição de memória
    //Envia cada uma das linhas em ordem
    for (i = 0; i < 48; i++) {
        lcd_dat(logo[i]);
    }
    lcd_cmd(L_L3 + 13);
    lcd_dat(0);
    lcd_dat(1);
    lcd_dat(2);
    lcd_cmd(L_L4 + 13);
    lcd_dat(3);
    lcd_dat(4);
    lcd_dat(5);

}

void nike_logo() {
    unsigned char i, j;
    char nike_logo[56] = {
        0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x06, 0x0E,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x1E,
        0x00, 0x00, 0x00, 0x02, 0x0C, 0x10, 0x00, 0x00, //linha 2
        0x0F, 0x07, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00,
        0x11, 0x1F, 0x1F, 0x1C, 0x00, 0x00, 0x00, 0x00,
        0x1C, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    };
    lcd_cmd(0x40); //Configura para a primeira posição de memória
    //Envia cada uma das linhas em ordem
    for (i = 0; i < 56; i++) {
        lcd_dat(nike_logo[i]);
    }
    lcd_cmd(L_L3 + 9);
    lcd_dat(0);
    lcd_dat(1);
    lcd_dat(2);
    lcd_dat(3);
    lcd_cmd(L_L4 + 9);
    lcd_dat(4);
    lcd_dat(5);
    lcd_dat(6);
    lcd_str("NIKE");

    for (j = 0; j < 1; j++) {
        for (i = 0; i < 25; i++) {
            atraso_ms(150);
            lcd_cmd(0x18); //move pra direita
        }

        for (i = 0; i < 26; i++) {
            atraso_ms(150);
            lcd_cmd(0x1C); //move pra esquerda
        }
    }
}

void adidas_logo() {
    unsigned char i, j;
    char adidas[48] = {
        0x00, 0x00, 0x00, 0x10, 0x18, 0x1C, 0x1E, 0x0F,
        0x04, 0x04, 0x0E, 0x0E, 0x1F, 0x1F, 0x1F, 0x1F,
        0x00, 0x00, 0x00, 0x01, 0x03, 0x07, 0x0F, 0x1E, //linha dois
        0x07, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x1F, 0x00, 0x1F, 0x00, 0x1F, 0x0E, 0x00, 0x00,
        0x1C, 0x00, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00
    };
    lcd_cmd(0x40); //Configura para a primeira posição de memória
    //Envia cada uma das linhas em ordem
    for (i = 0; i < 48; i++) {
        lcd_dat(adidas[i]);
    }
    lcd_cmd(L_L3 + 7);
    lcd_dat(0);
    lcd_dat(1);
    lcd_dat(2);
    lcd_cmd(L_L4 + 7);
    lcd_dat(3);
    lcd_dat(4);
    lcd_dat(5);
    lcd_str("adidas");
    for (j = 0; j < 1; j++) {
        for (i = 0; i < 23; i++) {
            atraso_ms(150);
            lcd_cmd(0x18); //move pra direita
        }

        for (i = 0; i < 24; i++) {
            atraso_ms(150);
            lcd_cmd(0x1C); //move pra esquerda
        }
    }
}

void partida_andamento(unsigned char gols, unsigned char gols2, unsigned char turno) {
    lcd_cmd(L_CLR);

    lcd_cmd(L_L1);
    lcd_str("  Em Andamento");
    lcd_cmd(L_L2);
    lcd_dat(turno);
    lcd_dat(0xDF); //º
    lcd_str(" Tempo");
    lcd_cmd(L_L3); //linha 3 
    lcd_str("Time A -");
    lcd_cmd(L_L3 + 9);
    lcd_dat(gols);
    lcd_cmd(L_L4); //linha 4 
    lcd_str("Time B -");
    lcd_cmd(L_L4 + 9);
    lcd_dat(gols2);
}

void main(void) {

    TRISD = 0x00;
    TRISE = 0x00;
    PORTD = 0x00;

    TRISE = 0x00;
    TRISA = 0xC3;
    TRISB = 0x03;
    TRISC = 0x01;

    unsigned char i, j, k;
    unsigned int t;
    int cont = 2000, flagcontrole = 0, flagfalta = 0;
    unsigned int temp1, temp2, tempflag = 0;
    unsigned char gols = '0', gols2 = '0', turno = '1';
    unsigned char cvA = '0', cvB = '0', caA = '0', caB = '0';
    lcd_init();
    lcd_cmd(0x0C); //desliga o cursor
    lcd_str("Inicializando");
    lcd_cmd(L_L2);
    lcd_str("Placar Futsal");
    atraso_s(2);
    lcd_cmd(L_CLR);
    unifeilogo();

    for (j = 0; j < 1; j++) {
        for (i = 0; i < 29; i++) {
            atraso_ms(100);
            lcd_cmd(0x18); //move pra direita
        }

        for (i = 0; i < 29; i++) {
            atraso_ms(100);
            lcd_cmd(0x1C); //move pra esquerda
        }
    }
    
    lcd_cmd(0x40);
    lcd_cmd(L_L1);
    lcd_str("Local: Unifei");
    lcd_cmd(L_L2);
    rtc_r();
    lcd_str((const char *) date);
    lcd_cmd(L_L3); //linha 3
    lcd_str("Time A");
    lcd_cmd(L_L4); //linha 4
    lcd_str("Time B");
    pwmInit();
    ssdInit();
    kpInit();
    timerInit();

    for (;;) {

        kpDebounce();
        
        //INICIO DO FUNCIONAMENTO DO PLACAR
        if (bitTst(kpRead(), 8)) {//Botao # = Inicia o funcionamento do placar
            ssdDigit(((cont / 1000) % 10), 0);
            for (i = 1; i > 0; i = i * 2) {
                PORTB = i;
                PORTD = i;
                atraso_ms(100);
            }
            PORTB = 0;
            PORTD = 0;
            for (i = 0; i < 2; i++) {
                PORTB ^= 0xFF;
                PORTD ^= 0xFF;
                atraso_ms(200);
            }
            
            timerInit();
            tempflag = 1;
            
            //INICIO DA CONTAGEM DO TEMPO
            for (;;) {

                timerReset(5000);

                if (tempflag == 1) {
                    t++;
                    if (t >= 200) {
                        cont--;
                        if (cont <= 0)
                            flagcontrole = 1;
                        if (cont / 10 % 10 == 9)
                            cont -= 40;
                        ssdDigit(((cont / 1000) % 10), 0);
                        ssdDigit(((cont / 100) % 10), 1);
                        ssdDigit(((cont / 10) % 10), 2);
                        ssdDigit((cont % 10), 3);
                        t = 0;
                    }
                }

                kpDebounce();
                if (kpRead() != temp1) {

                    temp1 = kpRead();

                    if (bitTst(kpRead(), 8)) {//Tecla #
                        partida_andamento(gols, gols2, turno);
                        tempflag = 1;
                        flagfalta = 1;
                    }

                    //GOL TIME A (time da linha 3)
                    if ((bitTst(kpRead(), 3)) && tempflag == 1) {//Botao 1
                        tempflag = 0;
                        lcd_cmd(L_L1);
                        lcd_str("Gooool Time A!!!");
                        lcd_cmd(L_L3 + 9);
                        gols++;
                        lcd_dat(gols);
                        pwmSet1(32);
                        pwmFrequency(10000);

                        for (k = 0; k < 3; k++) {
                            for (i = 1; i > 0; i = i * 2) {
                                bitSet(TRISC, 1);
                                PORTB = i;
                                PORTD = i;
                                atraso_ms(100);
                            }
                            bitClr(TRISC, 1);
                        }

                        PORTB = 0;
                        PORTD = 0;
                        for (i = 0; i < 2; i++) {
                            PORTB ^= 0xFF;
                            PORTD ^= 0xFF;
                            atraso_ms(200);
                        }
                        pwmSet1(0);
                    }//end GOL A

                    //GOL TIME B (time da linha 4)
                    if ((bitTst(kpRead(), 7)) && tempflag == 1) {//Botao 2
                        tempflag = 0;
                        lcd_cmd(L_L1);
                        lcd_str("Gooool Time B!!!");
                        lcd_cmd(L_L4 + 9);
                        gols2++;
                        lcd_dat(gols2);
                        pwmSet1(32);
                        pwmFrequency(10000);
                        for (k = 0; k < 3; k++) {
                            for (i = 1; i > 0; i = i * 2) {
                                bitSet(TRISC, 1);
                                PORTB = i;
                                PORTD = i;
                                atraso_ms(100);
                            }
                            bitClr(TRISC, 1);
                        }
                        PORTB = 0;
                        PORTD = 0;
                        for (i = 0; i < 2; i++) {
                            PORTB ^= 0xFF;
                            PORTD ^= 0xFF;
                            atraso_ms(200);
                        }
                        pwmSet1(0);
                    }//end GOL B

                    //BOLA FORA
                    if ((bitTst(kpRead(), 2)) && tempflag == 1) {//Botao 4
                        tempflag = 0;
                        lcd_cmd(L_L1);
                        lcd_str("   Bola Fora  ");
                    }//end BOLA FORA

                    //FALTA
                    if ((bitTst(kpRead(), 6)) && tempflag == 1) {//Botao 5
                        tempflag = 0;
                        flagfalta = 0;
                        lcd_cmd(L_L1);
                        lcd_str("     Falta     ");
                        lcd_cmd(L_L2);
                        lcd_str("Numeros Cartoes");
                        lcd_cmd(L_L3 + 7);
                        lcd_str(" A:");
                        lcd_dat(caA);
                        lcd_str(" V:");
                        lcd_dat(cvA);
                        lcd_cmd(L_L4 + 7);
                        lcd_str(" A:");
                        lcd_dat(caB);
                        lcd_str(" V:");
                        lcd_dat(cvB);
                        
                         }//end FALTA
                    
                         //MENU DE FALTAS
                        if (flagfalta == 0) {
                            
                            //AÇÕES MENU DE FALTA
                                if (bitTst(kpRead(), 3)) {
                                    lcd_cmd(L_L1);
                                    lcd_str("Cartao Am Time A");
                                    caA++;
                                    lcd_cmd(L_L3 + 10);
                                    lcd_dat(caA);
                                    pwmSet1(10);
                                    atraso_s(1);
                                    pwmSet1(0);
                                }
                                if (bitTst(kpRead(), 11)) {
                                    TRISEbits.TRISE0 = 0;
                                    lcd_cmd(L_L1);
                                    lcd_str("Cartao V Time A ");
                                    cvA++;
                                    lcd_cmd(L_L3 + 14);
                                    lcd_dat(cvA);
                                    pwmSet1(10);
                                    PORTEbits.RE0 ^= 1;
                                    atraso_s(1);
                                    PORTEbits.RE0 = 0;
                                    pwmSet1(0);

                                }
                                if (bitTst(kpRead(), 2)) {
                                    TRISEbits.TRISE0 = 0;
                                    lcd_cmd(L_L1);
                                    lcd_str("Cartao Am Time B");
                                    caB++;
                                    lcd_cmd(L_L4 + 10);
                                    lcd_dat(caB);
                                    PORTEbits.RE0 ^= 1;
                                    atraso_s(1);
                                    PORTEbits.RE0 = 0;
                                }
                                if (bitTst(kpRead(), 10)) {
                                    TRISEbits.TRISE0 = 0;
                                    lcd_cmd(L_L1);
                                    lcd_str("Cartao V Time B ");
                                    cvB++;
                                    lcd_cmd(L_L4 + 14);
                                    lcd_dat(cvB);
                                    pwmSet1(10);
                                    PORTEbits.RE0 ^= 1;
                                    atraso_s(1);
                                    PORTEbits.RE0 = 0;
                                    pwmSet1(0);
                                }  
                                
              
                        }//end MENU DE FALTAS

                   //CONDIÇÕES DE EXECUÇÃO DAS PROPAGANDAS
                    if ((tempflag == 1)&& (cont > 10) && ((bitTst(kpRead(), 1)) || (bitTst(kpRead(), 5)) || (bitTst(kpRead(), 9)))) {
                        lcd_cmd(L_CLR);

                        //PROPAGANDA 1
                        if ((bitTst(kpRead(), 1))) { //Botao 7 
                            chevrolet();
                        }//end PROPAGANDA 1

                        //PROPAGANDA 2
                        if ((bitTst(kpRead(), 5))) { //Botao 8
                            nike_logo();
                        }//end PROPAGANDA 2

                        //PROPAGANDA 3
                        if (bitTst(kpRead(), 9)) { //Botao 8
                            adidas_logo();
                        }//end PROPAGANDA 3

                        lcd_cmd(L_CLR);
                        cont -= 6;
                        ssdDigit(((cont / 1000) % 10), 0);
                        ssdDigit(((cont / 100) % 10), 1);
                        ssdDigit(((cont / 10) % 10), 2);
                        ssdDigit((cont % 10), 3);
                        partida_andamento(gols, gols2, turno);
                    
                    }//end CONDIÇÕES
                }//end kpRead() != temp1


                //INTERVALO E SEGUNDO TEMPO NO PLACAR
                if (flagcontrole && turno == '1') {
                    
                    tempflag = 0;

                    lcd_cmd(L_CLR);
                    lcd_cmd(L_L1);
                    lcd_str("Fim do 1");
                    lcd_dat(0xDF); //º
                    lcd_str(" Tempo");
                    lcd_cmd(L_L2);
                    lcd_str("Intervalo");
                    lcd_cmd(L_L3); //linha 3 
                    lcd_str("Time A");
                    lcd_cmd(L_L3 + 7);
                    lcd_dat(gols);
                    lcd_cmd(L_L4); //linha 4 
                    lcd_str("Time B");
                    lcd_cmd(L_L4 + 7);
                    lcd_dat(gols2);

                    turno = '2';
                    cont = 2000;
                    flagcontrole = 0;
                }

                //FIM DO JOGO
                if (flagcontrole && turno == '2') {
                    tempflag = 0;

                    lcd_cmd(L_CLR);
                    lcd_cmd(L_L1);
                    lcd_str("  Fim do Jogo   ");
                    lcd_cmd(L_L2);
                    lcd_str("Placar Final");
                    lcd_cmd(L_L3); //linha 3 
                    lcd_str("Time A");
                    lcd_cmd(L_L3 + 7);
                    lcd_dat(gols);
                    lcd_cmd(L_L4); //linha 4 
                    lcd_str("Time B");
                    lcd_cmd(L_L4 + 7);
                    lcd_dat(gols2);

                    flagcontrole = 0;
                    atraso_s(5);
                    lcd_cmd(L_CLR);
                    lcd_cmd(L_L1);
                    lcd_str("Pressione RESET");
                    lcd_cmd(L_L2);
                    lcd_str("Para reiniciar");
                }
                ssdUpdate();
                timerWait();
            }//end segundo for(;;)
        }//end INICIO DO PLACAR
    }//end primeiro for(;;)
}//end main