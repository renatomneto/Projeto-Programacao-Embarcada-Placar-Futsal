/* ########################################################################

   PICsim - PIC simulator http://sourceforge.net/projects/picsim/

   ########################################################################

   Copyright (c) : 2015  Luis Claudio Gambôa Lopes

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.

   For e-mail suggestions :  lcgamboa@yahoo.com
   ######################################################################## */

#include"rtc.h"
#include"i2c.h"

volatile char date[10];
volatile char time[10];


unsigned char getd(unsigned char nn)
{
 return ((nn & 0xF0)>>4)+0x30;
}

unsigned char getu(unsigned char nn)
{
  return (nn  & 0x0F)+0x30;
}

//--------------------- Reads time and date information from RTC (PCF8563)
void rtc_r(void) 
{
  unsigned char gols;

  i2c_start();
  i2c_wb(0xD0);
  i2c_wb(0);

  i2c_start();
  i2c_wb(0xD1);
  gols= 0x7F & i2c_rb(1); //segundos
  time[5]=':';
  time[6]=getd(gols);
  time[7]=getu(gols);
  time[8]=0;

  gols= 0x7F & i2c_rb(1); //minutos
  time[2]=':';
  time[3]=getd(gols);
  time[4]=getu(gols);

  gols= 0x3F & i2c_rb(1); //horas
  time[0]=getd(gols);
  time[1]=getu(gols);

  i2c_rb(1); //dia semana

  gols= 0x3F & i2c_rb(1); //dia
  date[0]=getd(gols);
  date[1]=getu(gols);


  gols= 0x1F & i2c_rb(1); //mes
  date[2]='/'; 
  date[3]=getd(gols);
  date[4]=getu(gols);

  gols=  i2c_rb(0); //ano
  date[5]='/';
  date[6]=getd(gols);
  date[7]=getu(gols);
  date[8]=0;

  i2c_stop();

}

