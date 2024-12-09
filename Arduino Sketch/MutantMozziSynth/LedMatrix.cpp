/*----------------------------------------------------------------------------------------------------------
 * LedMatrix.cpp
 * 
 * Implements a class for interfacing with a MAX7219-based 8x8 LED matrix over SPI
 * 
 * (C) 2021 Meebleeps
*-----------------------------------------------------------------------------------------------------------
*/

#include "LedMatrix.h"
#include <SPI.h>
#include <mozzi_rand.h>




/*----------------------------------------------------------------------------------------------------------
 * LedMatrix::LedMatrix()
 * initialises the vRAM and sets modified flag to all so that all rows will be updated on first refresh
 *----------------------------------------------------------------------------------------------------------
 */
LedMatrix::LedMatrix()
{
  for (int y = 0; y < 8; y++)
  {
    vRAM[y] = 0;
  }
  rowModified = LEDMATRIX_MODIFIED_ALL;
}


/*----------------------------------------------------------------------------------------------------------
 * LedMatrix::initialise()
 *----------------------------------------------------------------------------------------------------------
 */
void LedMatrix::initialise()
{
  pinMode(PIN_LEDMATRIX_DIN, OUTPUT);
  pinMode(PIN_LEDMATRIX_CS, OUTPUT);
  pinMode(PIN_LEDMATRIX_CLK, OUTPUT);
  pinMode(2, OUTPUT);
  
  SPI.setBitOrder(MSBFIRST);
  SPI.begin();

  setOrientation(LEDMATRIX_ORIENTATION_0);


  writeDisplayData(LED_DISPLAYTEST, 0x01);
  
  delay(250); // todo find out if this is necessary
  
  writeDisplayData(LED_DISPLAYTEST, 0x00);
  writeDisplayData(LED_DECODE_MODE, 0x00);
  writeDisplayData(LED_INTENSITY, 0x00);
  writeDisplayData(LED_SCAN_LIMIT, 0x0f);
  writeDisplayData(LED_SHUTDOWN, 0x01);
  writeDisplayData(LED_INTENSITY, 0x0f);
  
}



/*----------------------------------------------------------------------------------------------------------
 * setPixel
  *----------------------------------------------------------------------------------------------------------
 */
void LedMatrix::setPixel(byte x, byte y, bool value)
{
  if (x < LEDMATRIX_MAXCOLS && y < LEDMATRIX_MAXROWS)
  {
    if (value)
    {
      vRAM[y] = vRAM[y] | displayBit[x];
    }
    else
    {
      vRAM[y] = vRAM[y] & ~displayBit[x];
    }
  
    rowModified |= 1 << y;
  }
  
  
}


/*----------------------------------------------------------------------------------------------------------
 * togglePixel
 * 
 *----------------------------------------------------------------------------------------------------------
 */
void LedMatrix::togglePixel(byte x, byte y)
{
  if (y < LEDMATRIX_MAXROWS && x < LEDMATRIX_MAXCOLS)
  {
    // if pixel is on, switch off
    if (vRAM[y] & displayBit[x])
    {
      vRAM[y] = vRAM[y] & ~displayBit[x];
    }
    else
    {
      vRAM[y] = vRAM[y] | displayBit[x];
    }  
  
    rowModified |= 1 << y;
  }
}



/*----------------------------------------------------------------------------------------------------------
 * setRowPixels
 * 
 *----------------------------------------------------------------------------------------------------------
 */
void LedMatrix::setRowPixels(byte y, byte value)
{
  if (y < LEDMATRIX_MAXROWS)
  {
    vRAM[y] = value;
    rowModified |= 1 << y;
  }

}



/*----------------------------------------------------------------------------------------------------------
 * setColPixels
 * 
 *----------------------------------------------------------------------------------------------------------
 */
void LedMatrix::setColPixels(byte x, byte value)
{
  if (x < LEDMATRIX_MAXCOLS)
  {
    if (value)
    {
      for (int y = 0; y < 7; y++)
      {
        vRAM[y] = vRAM[y] | displayBit[x];
        rowModified |= 1 << y;
      }
    }
    else
    {
      for (int y = 0; y < 7; y++)
      {
        vRAM[y] = vRAM[y] & (~displayBit[x]);
        rowModified |= 1 << y;
      }
    }
  }
}


/*----------------------------------------------------------------------------------------------------------
 * DrawLineV
 * 
 *----------------------------------------------------------------------------------------------------------
 */
void LedMatrix::drawLineV(byte x, byte startY, byte endY, bool on)
{
  if (x < LEDMATRIX_MAXCOLS && startY <= endY)
  {
    for (byte y = startY; y < endY; y++)
    {
      setPixel(x, y, on);
    }
  }
}


/*----------------------------------------------------------------------------------------------------------
 * DrawLineH
 * 
 *----------------------------------------------------------------------------------------------------------
 */
void LedMatrix::drawLineH(byte y, byte startX, byte endX, bool on)
{
  if (y < LEDMATRIX_MAXROWS && startX <= endX)
  {
    for (byte x = startX; x < endX; x++)
    {
      setPixel(x, y, on);
    }
  }
}


/*----------------------------------------------------------------------------------------------------------
 * displayIcon
 * takes a pointer to a 8-byte array and displays an icon
 * TODO: no validation that bitmap array is the right size
 *----------------------------------------------------------------------------------------------------------
 */
void LedMatrix::displayIcon(const byte* bitmap)
{
  for (int y = 0; y < LEDMATRIX_MAXROWS; y++)
  {
    setRowPixels(y, bitmap[y]);
  }
  
  refresh();  
}


/*----------------------------------------------------------------------------------------------------------
 * sparkle
 *----------------------------------------------------------------------------------------------------------
 */
void LedMatrix::sparkle(int amount)
{
  int x, y;
  
  for (int i = 0; i < amount; i++)
  {
    x = rand(LEDMATRIX_MAXCOLS);
    y = rand(LEDMATRIX_MAXROWS);
    togglePixel(x,y);
    refresh();
    delay(10);
    togglePixel(x,y);
  }
  
  refresh();  
}
    


/*----------------------------------------------------------------------------------------------------------
 * refresh
 * updates the matrix with the current vram contents
 *----------------------------------------------------------------------------------------------------------
 */
void LedMatrix::refresh()
{
  //Serial.println(F("--------"));
  for (int y = 0; y < 8; y++)
  {
    if (rowModified & (1 << y))
    {
      writeDisplayData(y+1, vRAM[y]);
    }
    else
    {
      
    }
  }

  rowModified = LEDMATRIX_MODIFIED_NONE;

}



/*----------------------------------------------------------------------------------------------------------
 * clearScreen
 * clears the VRAM and updates the matrix
 *----------------------------------------------------------------------------------------------------------
 */
void LedMatrix::clearScreen()
{
  for (int y = 0; y < 8; y++)
  {
    vRAM[y] = 0;
  }

  rowModified = LEDMATRIX_MODIFIED_ALL;

  refresh();
}


/*----------------------------------------------------------------------------------------------------------
 * setIntensity
 * 
 *----------------------------------------------------------------------------------------------------------
 */
void LedMatrix::setIntensity(int intensity)
{
  if (intensity > 15) 
  {
    intensity = 15;
  }
  else if (intensity < 0)
  {
    intensity = 0;
  }
  
  writeDisplayData(LED_INTENSITY, intensity);
}



/*----------------------------------------------------------------------------------------------------------
 * setOrientation
 * sets the orientation of the matrix depending on installation
 *----------------------------------------------------------------------------------------------------------
 */
void LedMatrix::setOrientation(int newOrientate)
{
  orientation = newOrientate;
  //Serial.print(orientation);
  
  switch (orientation)
  {
    case LEDMATRIX_ORIENTATION_0:
      
      displayBit[0] = 128;
      displayBit[1] = 64;
      displayBit[2] = 32;
      displayBit[3] = 16;
      displayBit[4] = 8;
      displayBit[5] = 4;
      displayBit[6] = 2;
      displayBit[7] = 1;
      break;
      
    case LEDMATRIX_ORIENTATION_90:

      //?
      break;
    
    case LEDMATRIX_ORIENTATION_180:

      displayBit[0] = 1;
      displayBit[1] = 2;
      displayBit[2] = 4;
      displayBit[3] = 8;
      displayBit[4] = 16;
      displayBit[5] = 32;
      displayBit[6] = 64;
      displayBit[7] = 128;
      break;

    case LEDMATRIX_ORIENTATION_270:

      //?
      break;
    
    default:
      displayBit[0] = 1;
      displayBit[1] = 2;
      displayBit[2] = 4;
      displayBit[3] = 8;
      displayBit[4] = 16;
      displayBit[5] = 32;
      displayBit[6] = 64;
      displayBit[7] = 128;
      break;
  
  }
}


/*----------------------------------------------------------------------------------------------------------
 * writeDisplayData
 * writes a single line of data to the LED matrix
 *----------------------------------------------------------------------------------------------------------
 */
void LedMatrix::writeDisplayData(uint8_t address, uint8_t value)
{
  digitalWrite(PIN_LEDMATRIX_CS, LOW);
  SPI.transfer(address);
  SPI.transfer(value);
  digitalWrite(PIN_LEDMATRIX_CS, HIGH);
}
