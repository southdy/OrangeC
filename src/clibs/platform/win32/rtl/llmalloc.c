/* Software License Agreement
 *
 *     Copyright(C) 1994-2018 David Lindauer, (LADSoft)
 *
 *     This file is part of the Orange C Compiler package.
 *
 *     The Orange C Compiler package is free software: you can redistribute it and/or modify
 *     it under the terms of the GNU General Public License as published by
 *     the Free Software Foundation, either version 3 of the License, or
 *     (at your option) any later version, with the addition of the
 *     Orange C "Target Code" exception.
 *
 *     The Orange C Compiler package is distributed in the hope that it will be useful,
 *     but WITHOUT ANY WARRANTY; without even the implied warranty of
 *     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *     GNU General Public License for more details.
 *
 *     You should have received a copy of the GNU General Public License
 *     along with Orange C.  If not, see <http://www.gnu.org/licenses/>.
 *
 *     contact information:
 *         email: TouchStone222@runbox.com <David Lindauer>
 *
 */

#include <errno.h>
#include <windows.h>
#include <stdio.h>
#include <time.h>
#include <wchar.h>
#include <locale.h>
#include "libp.h"

void* __ll_malloc(size_t size)
{
    void* address;
    if ((address = VirtualAlloc(0, size, MEM_COMMIT, PAGE_READWRITE)) == 0)
    {
        errno = _dos_errno = ENOMEM;
        return 0;
    }
    return address;
}

void __ll_free(void* block) { VirtualFree(block, 0, MEM_RELEASE); }