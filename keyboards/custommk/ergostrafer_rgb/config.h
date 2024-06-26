// Copyright 2024 customMK
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

// FRAM configuration
#define EXTERNAL_EEPROM_SPI_SLAVE_SELECT_PIN B7
#define EXTERNAL_EEPROM_SPI_CLOCK_DIVISOR 4 // 48MHz / 4 = 12MHz; max supported by MB85R64 is 20MHz

// SPI configuration
#define SPI_DRIVER SPID1
#define SPI_SCK_PIN B3
#define SPI_MOSI_PIN B5
#define SPI_MISO_PIN B4

// Audio configuration
#define AUDIO_PIN B8
#define AUDIO_PWM_DRIVER PWMD4
#define AUDIO_PWM_CHANNEL 3 
#define AUDIO_PWM_PAL_MODE 2
#define AUDIO_STATE_TIMER GPTD5
#define AUDIO_INIT_DELAY

#define WS2812_PWM_DRIVER PWMD1
#define WS2812_PWM_CHANNEL 3
#define WS2812_PWM_PAL_MODE 1
#define WS2812_DMA_STREAM STM32_DMA2_STREAM5
#define WS2812_DMA_CHANNEL 6
