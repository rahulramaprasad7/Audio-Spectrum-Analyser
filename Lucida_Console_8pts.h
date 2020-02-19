/*
 * @file Lucida_Console_8pts.h
 * @brief The header file containing struct and array declarations
 *
 * This file contains the declaration of arrays used to
 * hold the font data and the offset table for both
 * Lucida Console 8pt and Lucida Console 8pt narrow version
 *
 * REFERENCE: A software called The Dot Factory
 * was used to generate this data
 * http://www.eran.io/the-dot-factory-an-lcd-font-and-image-generator/
 *
 * @date 03-Dec-2019
 * @author Prayag Milan Desai, Rahul Ramaprasad
 */

#ifndef LUCIDA_CONSOLE_8PTS_H_
#define LUCIDA_CONSOLE_8PTS_H_

#include <stdint.h>
#include "bitmap_db.h"

/* Font data for Lucida Console 8pt */
extern const uint8_t lucidaConsole_8ptBitmaps[];
extern const FONT_INFO lucidaConsole_8ptFontInfo;
extern const FONT_CHAR_INFO lucidaConsole_8ptDescriptors[];

/* Font data for Lucida Console 8pt Narrow */
extern const uint8_t lucidaConsole_8ptBitmaps_narrow[];
extern const FONT_INFO lucidaConsole_8ptFontInfo_narrow;
extern const FONT_CHAR_INFO lucidaConsole_8ptDescriptors_narrow[];

#endif /* LUCIDA_CONSOLE_8PTS_H_ */
