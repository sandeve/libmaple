/******************************************************************************
 * The MIT License
 *
 * Copyright (c) 2011 LeafLabs, LLC.
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use, copy,
 * modify, merge, publish, distribute, sublicense, and/or sell copies
 * of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
 * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
 * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *****************************************************************************/

/**
 * @file bitband.h
 *
 * @brief Bit-banding utility functions
 */

#define BB_SRAM_REF      0x20000000
#define BB_SRAM_BASE     0x22000000
#define BB_PERI_REF      0x40000000
#define BB_PERI_BASE     0x42000000

static inline __io uint32* __bb_addr(__io void*, uint32, uint32, uint32);

/**
 * @brief Obtain a pointer to the bit-band address corresponding to a
 * bit in a volatile SRAM address.
 * @param address Address in the bit-banded SRAM region
 * @param bit     Bit in address to bit-band
 */
static inline __io uint32* bb_sramp(__io void *address, uint32 bit) {
    return __bb_addr(address, bit, BB_SRAM_BASE, BB_SRAM_REF);
}

/**
 * @brief Obtain a pointer to the bit-band address corresponding to a
 * bit in a peripheral address.
 * @param address Address in the bit-banded peripheral region
 * @param bit     Bit in address to bit-band
 */
static inline __io uint32* bb_perip(__io void *address, uint32 bit) {
    return __bb_addr(address, bit, BB_PERI_BASE, BB_PERI_REF);
}

static inline __io uint32* __bb_addr(__io void *address,
                                     uint32 bit,
                                     uint32 bb_base,
                                     uint32 bb_ref) {
    return (__io uint32*)(bb_base + ((uint32)address - bb_ref) * 32 + bit * 4);
}