#include "mbi5042.h"
#include "wait.h"
#include <string.h>

void mbi5042_init(mbi5042_t* pDevice, ioline_t clk, ioline_t le, ioline_t data)
{
    if (pDevice) {
        pDevice->clk = clk;
        pDevice->le = le;
        pDevice->data = data;
        palSetLine(clk);
        palSetLine(le);
        palSetLine(data);
    }
}

// 16 15 14 13 12 11 10 09 08 07 06 05 04 03 02 01
// 00 01 02 03 04 05 06 07 08 09 10 11 12 13 14 15
// 0b1_000_0_1_101011_0000
// 0x86B0 // Our setting
void mbi5042_configure(mbi5042_t* pDevice, uint16_t configuration) {
    /* --------------- Enable Write Configuration ------------------ */
    // CL(1) -> RAISE LE -> CL(2-16) LowerLE
    palSetLine(pDevice->clk); __NOP(); __NOP(); __NOP();
    palClearLine(pDevice->clk); __NOP(); __NOP(); __NOP(); // CL1
    palSetLine(pDevice->le); __NOP(); __NOP(); __NOP(); // Raise LE
    palSetLine(pDevice->clk); // CL2
    for (size_t i = 0; i < 16; i++)
    {
        __NOP(); __NOP(); __NOP();
        palClearLine(pDevice->clk); // CL2,3,4,5,6,7,8,9,10,11,12,13,14,15
        __NOP(); __NOP(); __NOP();
        palSetLine(pDevice->clk); // CL  3,4,5,6,7,8,9,10,11,12,13,14,15,16
    }
    palClearLine(pDevice->le);
    __NOP(); __NOP();
    palClearLine(pDevice->clk);
    /* -------------- Write Configuration ---------------------------- */
    size_t i = 16;
    while (i-- > 0) {
        if ((configuration >> i) & 0x1) {
            palSetLine(pDevice->data);
        } else {
            palClearLine(pDevice->data);
        }
        __NOP(); __NOP(); __NOP();
        palSetLine(pDevice->clk);
        __NOP(); __NOP(); __NOP();
        if (i == 0) {
            palClearLine(pDevice->le);
        }
        __NOP(); __NOP(); __NOP();
        palClearLine(pDevice->clk);
        if (i == 10) {
            palSetLine(pDevice->le);
        }
        __NOP(); __NOP(); __NOP();
    }
}

/*
 * @brief Flush data to MBI5042 chip. This only works in mode F=1.
 *
 * @param[in] pDevice pointer to a mbi5042_t device handle.
 */
void mbi5042_flush_data(mbi5042_t* pDevice, uint16_t* pixel) {
    palClearLine(pDevice->clk);
    palClearLine(pDevice->le);
    __NOP();
    __NOP();
    __NOP();
    size_t i = MBI5042_PIXELS_PER_CHIP;
    while (i-- > 0) {
        size_t j = 16;
        while (j-- > 0) {
            uint8_t bit = ((pixel[i]) >> j) & 0x1;
            if (bit) {
                palSetLine(pDevice->data);
            } else {
                palClearLine(pDevice->data);
            }
            __NOP();
            palSetLine(pDevice->clk);
            __NOP();
            if (j == 0) {
                palClearLine(pDevice->le);
            }
            palClearLine(pDevice->clk);
            __NOP();
            if (j == 1) {
                palSetLine(pDevice->le); __NOP();
            }
        }
    }
    for (i = 0; i < 4; i++)
    {
        palSetLine(pDevice->clk);
        __NOP();
        palClearLine(pDevice->clk);
        __NOP();
    }
    palSetLine(pDevice->clk); // T4 Rising Edge
    palSetLine(pDevice->le);
    __NOP(); __NOP(); __NOP();
    palClearLine(pDevice->clk); // T4 Falling Edge
    __NOP(); __NOP(); __NOP();
    palSetLine(pDevice->clk); __NOP(); __NOP(); palClearLine(pDevice->clk); __NOP(); __NOP(); // 5
    palSetLine(pDevice->clk); __NOP(); __NOP(); palClearLine(pDevice->clk); __NOP(); __NOP(); // 6
    palClearLine(pDevice->le); __NOP(); __NOP();
    palSetLine(pDevice->clk);
}

