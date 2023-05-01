#ifndef DATATYPES_SPI_OPTIONS_H
#define DATATYPES_SPI_OPTIONS_H

#include <Arduino.h>

#ifdef ESP32

enum class SPI_Options_e { // Do not change values as this is stored in the settings!
  None        = 0,
#ifndef CONFIG_IDF_TARGET_ESP32C3
  Vspi        = 1,
#endif // #ifndef CONFIG_IDF_TARGET_ESP32C3
  Hspi        = 2,
  UserDefined = 9 // Leave some room for other, possible future, hardware-related options
};

const __FlashStringHelper* getSPI_optionToString(SPI_Options_e option);
const __FlashStringHelper* getSPI_optionToShortString(SPI_Options_e option);

#endif // ifdef ESP32

#endif // ifndef DATATYPES_SPI_OPTIONS_H
