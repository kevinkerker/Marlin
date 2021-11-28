/**
 * Marlin 3D Printer Firmware
 * Copyright (c) 2019 MarlinFirmware [https://github.com/MarlinFirmware/Marlin]
 *
 * Based on Sprinter and grbl.
 * Copyright (c) 2011 Camiel Gubbels / Erik van der Zalm
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

/**
 * RADDS
 */

#if NOT_TARGET(__SAM3X8E__)
#error "Oops! Select 'Arduino Due' in 'Tools > Board.'"
#endif

#define BOARD_INFO_NAME "RADDS_AM8"

//
// EEPROM
//

#define I2C_EEPROM
#define MARLIN_EEPROM_SIZE 0xFFFF

//
// Servos
//
#define SERVO0_PIN 5
#define SERVO1_PIN 6
#define SERVO2_PIN 39
#define SERVO3_PIN 40

//
// Limit Switches
//

// Hardware matching Pins
#define hw_X_MIN_PIN 28
#define hw_X_MAX_PIN 34
#define hw_Y_MIN_PIN 30
#define hw_Y_MAX_PIN 36
#define hw_Z_MIN_PIN 32
#define hw_Z_MAX_PIN 38
// switches Xmin and Ymin with Xmax and Ymax
#define X_MIN_PIN hw_X_MAX_PIN
#define X_MAX_PIN hw_X_MIN_PIN
#define Y_MIN_PIN hw_Y_MAX_PIN
#define Y_MAX_PIN hw_Y_MIN_PIN
#define Z_MIN_PIN hw_Z_MIN_PIN
#define Z_MAX_PIN hw_Z_MAX_PIN

//
// Z Probe (when not Z_MIN_PIN)
//
#ifndef Z_MIN_PROBE_PIN
#define Z_MIN_PROBE_PIN 38
#endif

//
// Steppers
//
#define X_STEP_PIN 24
#define X_DIR_PIN 23
#define X_ENABLE_PIN 26
#define X_CS_PIN 25

#define Y_STEP_PIN 17
#define Y_DIR_PIN 16
#define Y_ENABLE_PIN 22

#define Y_CS_PIN 27

#define Z_STEP_PIN 2
#define Z_DIR_PIN 3
#define Z_ENABLE_PIN 15

#define Z_CS_PIN 29

#define E0_STEP_PIN 61
#define E0_DIR_PIN 60
#define E0_ENABLE_PIN 62

#define E0_CS_PIN 31

#define E1_STEP_PIN 64
#define E1_DIR_PIN 63
#define E1_ENABLE_PIN 65

#define E1_CS_PIN 33

#define E2_STEP_PIN 51
#define E2_DIR_PIN 53
#define E2_ENABLE_PIN 49
#ifndef E2_CS_PIN
#define E2_CS_PIN 35
#endif

/**
 * RADDS Extension Board V2 / V3
 * http://doku.radds.org/dokumentation/extension-board
 */
//#define RADDS_EXTENSION 2
#if RADDS_EXTENSION >= 2
#define E3_DIR_PIN 33
#define E3_STEP_PIN 35
#define E3_ENABLE_PIN 37
#ifndef E3_CS_PIN
#define E3_CS_PIN 6
#endif

#if RADDS_EXTENSION == 3

#define E4_DIR_PIN 27
#define E4_STEP_PIN 29
#define E4_ENABLE_PIN 31
#ifndef E4_CS_PIN
#define E4_CS_PIN 39
#endif

#define E5_DIR_PIN 66
#define E5_STEP_PIN 67
#define E5_ENABLE_PIN 68
#ifndef E5_CS_PIN
#define E5_CS_PIN 6
#endif

#define RADDS_EXT_MSI_PIN 69

#define BOARD_INIT() OUT_WRITE(RADDS_EXT_VDD_PIN, HIGH)

#else

#define E4_DIR_PIN 27
#define E4_STEP_PIN 29
#define E4_ENABLE_PIN 31
#ifndef E4_CS_PIN
#define E4_CS_PIN 39
#endif

// E3 and E4 share the same MSx pins
#define E3_MS1_PIN 67
#define E4_MS1_PIN 67
#define E3_MS2_PIN 68
#define E4_MS2_PIN 68
#define E3_MS3_PIN 69
#define E4_MS3_PIN 69

#define RADDS_EXT_VDD2_PIN 66

#define BOARD_INIT()                     \
  do {                                   \
    OUT_WRITE(RADDS_EXT_VDD_PIN, HIGH);  \
    OUT_WRITE(RADDS_EXT_VDD2_PIN, HIGH); \
  } while (0)

#endif

#define RADDS_EXT_VDD_PIN 25

#endif

//
// Temperature Sensors
//
#define TEMP_0_PIN 0    // Analog Input
#define TEMP_1_PIN 1    // Analog Input
#define TEMP_2_PIN 2    // Analog Input
#define TEMP_3_PIN 3    // Analog Input
#define TEMP_4_PIN 5    // dummy so will compile when PINS_DEBUGGING is enabled
#define TEMP_BED_PIN 4  // Analog Input

// SPI for Max6675 or Max31855 Thermocouple
#if DISABLED(SDSUPPORT)
#define TEMP_0_CS_PIN 53
#else
#define TEMP_0_CS_PIN 49
#endif

//
// Heaters / Fans
//
#define HEATER_0_PIN 9
#define HEATER_1_PIN 8
#define HEATER_2_PIN 11
#define HEATER_BED_PIN 7  // BED

#define FAN_PIN 12
#define FAN1_PIN 13

//
// Misc. Functions
//
#define SD_DETECT_PIN 14
#define PS_ON_PIN 40  // SERVO3_PIN

#ifndef FIL_RUNOUT_PIN
#define FIL_RUNOUT_PIN 39  // SERVO2_PIN
#endif

// I2C EEPROM with 8K of space
#define I2C_EEPROM
#define E2END 0xFFFF

//
// LCD / Controller
//
// The REPRAP_DISCOUNT_FULL_GRAPHIC_SMART_CONTROLLER requires
// an adapter such as https://www.thingiverse.com/thing:1740725

#define LCD_PINS_RS 42
#define LCD_PINS_ENABLE 43
#define LCD_PINS_D4 44

#define BEEPER_PIN 41

#define BTN_EN1 50
#define BTN_EN2 52
#define BTN_ENC 48

#define SDSS 10
#define SD_DETECT_PIN 14