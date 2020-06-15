#pragma once

#include "hal.h"

#define MBI5042_PIXELS_PER_CHIP                                               16

typedef struct {
    ioline_t clk;
    ioline_t le;
    ioline_t data;
} mbi5042_t;

void mbi5042_init(mbi5042_t* pDevice, ioline_t clk, ioline_t le, ioline_t data);
void mbi5042_flush_data(mbi5042_t* pDevice, uint16_t* pixel);
void mbi5042_configure(mbi5042_t* pDevice, uint16_t configuration);
