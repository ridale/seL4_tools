/*
 * Copyright 2018, Data61
 * Commonwealth Scientific and Industrial Research Organisation (CSIRO)
 * ABN 41 687 119 230.
 *
 * This software may be distributed and modified according to the terms of
 * the GNU General Public License version 2. Note that NO WARRANTY is provided.
 * See "LICENSE_GPLv2.txt" for details.
 *
 * @TAG(DATA61_GPL)
 */

#include <printf.h>
#include <types.h>
#include <platform.h>

#define UTHR        0x0
#define ULSR        0x14
#define ULSR_THRE   (1 << 5)

#define UART_REG(x) ((volatile uint32_t *)(UART_PPTR + (x)))

int __fputc(int c, FILE *stream)
{
    /* Send '\r' (CR) before every '\n' (LF). */
    if (c == '\n') {
        (void)__fputc('\r', stream);
    }

    /* Wait until UART ready for the next character. */
    while ((*UART_REG(ULSR) & ULSR_THRE) == 0);

    /* Add character to the buffer. */
    *UART_REG(UTHR) = (c & 0xff);

    return 0;
}
