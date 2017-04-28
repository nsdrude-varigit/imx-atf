/*
 * Copyright (c) 2017, ARM Limited and Contributors. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * Redistributions of source code must retain the above copyright notice, this
 * list of conditions and the following disclaimer.
 *
 * Redistributions in binary form must reproduce the above copyright notice,
 * this list of conditions and the following disclaimer in the documentation
 * and/or other materials provided with the distribution.
 *
 * Neither the name of ARM nor the names of its contributors may be used
 * to endorse or promote products derived from this software without specific
 * prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef __MM_SHIM_H__
#define __MM_SHIM_H__

#include <xlat_tables_v2.h>

/* Assembly source */
extern uintptr_t mm_shim_exceptions;

/* Linker symbols */
extern uintptr_t __MM_SHIM_EXCEPTIONS_START__;
extern uintptr_t __MM_SHIM_EXCEPTIONS_END__;

extern uintptr_t __MM_SHIM_XLAT_TABLES_START__;
extern uintptr_t __MM_SHIM_XLAT_TABLES_END__;

/* Definitions */
#define MM_SHIM_EXCEPTIONS_BASE_PTR		(uintptr_t)(&mm_shim_exceptions)

#define MM_SHIM_EXCEPTIONS_BASE		(uintptr_t)(&__MM_SHIM_EXCEPTIONS_START__)
#define MM_SHIM_EXCEPTIONS_END		(uintptr_t)(&__MM_SHIM_EXCEPTIONS_END__)
#define MM_SHIM_EXCEPTIONS_SIZE		(MM_SHIM_EXCEPTIONS_END - MM_SHIM_EXCEPTIONS_BASE)

#define MM_SHIM_XLAT_TABLES_BASE	(uintptr_t)(&__MM_SHIM_XLAT_TABLES_START__)
#define MM_SHIM_XLAT_TABLES_END		(uintptr_t)(&__MM_SHIM_XLAT_TABLES_END__)
#define MM_SHIM_XLAT_TABLES_SIZE	(MM_SHIM_XLAT_TABLES_END - MM_SHIM_XLAT_TABLES_BASE)

/* Setup functions for the translation tables and MMU. */

void mm_shim_prepare_mmu_context_el1(uint64_t *mair, uint64_t *tcr,
				     uint64_t *ttbr, uint64_t *sctlr);

/* Handle on the MM shim translation context */
extern xlat_ctx_handle_t mm_shim_xlat_ctx_handle;

#endif /* __MM_SHIM_H__ */
