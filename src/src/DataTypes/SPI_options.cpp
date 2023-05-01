#include "../DataTypes/SPI_options.h"

#ifdef ESP32

const __FlashStringHelper* getSPI_optionToString(SPI_Options_e option) {
  switch (option) {
    case SPI_Options_e::None:
      return F("Disabled");
#ifndef CONFIG_IDF_TARGET_ESP32C3
    case SPI_Options_e::Vspi:
#if defined(CONFIG_IDF_TARGET_ESP32S2) || defined(CONFIG_IDF_TARGET_ESP32S3)
      return F("SPI3: CLK=GPIO-36, MISO=GPIO-37, MOSI=GPIO-35");
#else // if defined(CONFIG_IDF_TARGET_ESP32S2) || defined(CONFIG_IDF_TARGET_ESP32S3)
      return F("VSPI: CLK=GPIO-18, MISO=GPIO-19, MOSI=GPIO-23");
#endif // if defined(CONFIG_IDF_TARGET_ESP32S2) || defined(CONFIG_IDF_TARGET_ESP32S3)
#endif // ifndef CONFIG_IDF_TARGET_ESP32C3
    case SPI_Options_e::Hspi:
#if defined(CONFIG_IDF_TARGET_ESP32C3)
      return F("FSPI: CLK=GPIO-6, MISO=GPIO-7, MOSI=GPIO-2");
#elif defined(CONFIG_IDF_TARGET_ESP32S2) || defined(CONFIG_IDF_TARGET_ESP32S3) // if defined(CONFIG_IDF_TARGET_ESP32C3)
      return F("FSPI: CLK=GPIO-12, MISO=GPIO-13, MOSI=GPIO-11");
#else // if defined(CONFIG_IDF_TARGET_ESP32C3)
      return F("HSPI: CLK=GPIO-14, MISO=GPIO-12, MOSI=GPIO-13");
#endif // ifndef CONFIG_IDF_TARGET_ESP32C3
    case SPI_Options_e::UserDefined:
      return F("User-defined: CLK, MISO, MOSI GPIO-pins");
  }
  return F("Unknown");
}

const __FlashStringHelper* getSPI_optionToShortString(SPI_Options_e option) {
  switch (option) {
    case SPI_Options_e::None:
      return F("Disabled");
#ifndef CONFIG_IDF_TARGET_ESP32C3
    case SPI_Options_e::Vspi:
#if defined(CONFIG_IDF_TARGET_ESP32S2) || defined(CONFIG_IDF_TARGET_ESP32S3)
      return F("SPI3");
#else // if defined(CONFIG_IDF_TARGET_ESP32S2) || defined(CONFIG_IDF_TARGET_ESP32S3)
      return F("VSPI");
#endif // if defined(CONFIG_IDF_TARGET_ESP32S2) || defined(CONFIG_IDF_TARGET_ESP32S3)
#endif // ifndef CONFIG_IDF_TARGET_ESP32C3
    case SPI_Options_e::Hspi:
#if defined(CONFIG_IDF_TARGET_ESP32C3) || defined(CONFIG_IDF_TARGET_ESP32S2) || defined(CONFIG_IDF_TARGET_ESP32S3)
      return F("FSPI");
#else // if defined(CONFIG_IDF_TARGET_ESP32C3) || defined(CONFIG_IDF_TARGET_ESP32S2) || defined(CONFIG_IDF_TARGET_ESP32S3)
      return F("HSPI");
#endif // if defined(CONFIG_IDF_TARGET_ESP32C3) || defined(CONFIG_IDF_TARGET_ESP32S2) || defined(CONFIG_IDF_TARGET_ESP32S3)
    case SPI_Options_e::UserDefined:
      return F("User-defined SPI");
  }
  return F("Unknown");
}

#endif // ifdef ESP32
