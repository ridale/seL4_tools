/*
 * Copyright 2019, Data61
 * Commonwealth Scientific and Industrial Research Organisation (CSIRO)
 * ABN 41 687 119 230.
 *
 * This software may be distributed and modified according to the terms of
 * the GNU General Public License version 2. Note that NO WARRANTY is provided.
 * See "LICENSE_GPLv2.txt" for details.
 *
 * @TAG(DATA61_GPL)
 */

#include <autoconf.h>
#include <elfloader/gen_config.h>
#include <assembler.h>
#include <armv/assembler.h>

#if CONFIG_MAX_NUM_NODES > 1

.text

.extern core_entry

BEGIN_FUNC(core_entry_head)
    mov sp, x0
    mrs x1, mpidr_el1
    msr tpidr_el1, x1
    b   core_entry
END_FUNC(core_entry_head)

#endif
