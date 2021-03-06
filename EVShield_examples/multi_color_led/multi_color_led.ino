/*
  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/
/*
For beginners tutorial (and user guide) visit:
http://www.openelectrons.com/docs/viewdoc/25
*/

#include <Wire.h>
#include <EVShield.h>
#define GLOBAL_DELAY 50

/**
  This is a simple example of blinking
	the EVShield LED with multiple colors.
*/
EVShield evshield(0x34,0x36);

void setup()
{
  Serial.begin(115200);

  evshield.init(SH_HardwareI2C);

  Serial.println ("Watch the LED on EVShield ...");
}

void loop()
{
      multi_color_blink();
}

void multi_color_blink(){
 for (int i=8; i>=0; i--){
   if (i<=4) evshield.ledSetRGB(i,4-i,0);
   else    evshield.ledSetRGB(i,0,0);
   delay(GLOBAL_DELAY);
 }
 
 for (int i=5; i<=8; i++){
   evshield.ledSetRGB(0,i,0);
   delay(GLOBAL_DELAY/2);
 }

 for (int i=8; i>=0; i--){
   if (i<=4) evshield.ledSetRGB(0,i,4-i);
   else    evshield.ledSetRGB(0,i,0);
   delay(GLOBAL_DELAY);
 }

 for (int i=5; i<=8; i++){
   evshield.ledSetRGB(0,0,i);
   delay(GLOBAL_DELAY/2);
 }

 for (int i=8; i>=0; i--){
   if (i<=4) evshield.ledSetRGB(4-i,0,i);
   else    evshield.ledSetRGB(0,0,i);
   delay(GLOBAL_DELAY);
 }

 for (int i=5; i<=8; i++){
   evshield.ledSetRGB(i,0,0);
   delay(GLOBAL_DELAY/2);
 } 
}
