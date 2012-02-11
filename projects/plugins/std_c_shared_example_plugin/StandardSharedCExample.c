/**
 * $Id: StandardSharedCExample.c 5 2008-09-07 21:45:28Z kevin $
 *
 * xTractorFan Community Edition
 * Copyright (C) 2008 Kevin Fourie.
 *
 * This program is free software; you can redistribute it and/or modify it under
 * the terms of the GNU General Public License version 3 as published by the
 * Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more
 * details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * The interactive user interfaces in modified source and object code versions
 * of this program must display Appropriate Legal Notices, as required under
 * Section 5 of the GNU General Public License version 3.
 *
 * In accordance with Section 7(b) of the GNU General Public License version 3,
 * these Appropriate Legal Notices must retain the display of the "Powered by
 * xTractorFan" logo and retain the original copyright notice. If the display of the
 * logo is not reasonably feasible for technical reasons, the Appropriate Legal
 * Notices must display the words "Powered by xTractorFan" and retain the original
 * copyright notice.
 *
 * Contributor(s): ______________________________________
 *
 */

#include <object_model/c_ExtractorModel.h>
#include <stdlib.h>
#include "StandardSharedCExample.h"

typedef struct StandardSharedCExample_ {
    C_Extractor extractor;

    /* additional extractor-specific data */
    apr_uint32_t dummy;

} StandardSharedCExample;

void StandardSharedCExample_getInitialInfo(C_ExtractorHandle handle, C_ExtractorInfo * info) {
    StandardSharedCExample * mm = (StandardSharedCExample *) handle;
    strcpy((char *) info->name, "StandardSharedCExample");
    strcpy((char *) info->desc, "Standard Extractor Shared C Example Plugin");
}

void StandardSharedCExample_run(C_ExtractorHandle handle, C_Session * session) {
    StandardSharedCExample * mm = (StandardSharedCExample *) handle;
}

void * StandardSharedCExample_create(PF_ObjectParams * params) {
    StandardSharedCExample * mm = (StandardSharedCExample *) malloc(sizeof (StandardSharedCExample));
    mm->extractor.handle = (C_ExtractorHandle) mm;
    mm->extractor.getInitialInfo = StandardSharedCExample_getInitialInfo;
    mm->extractor.run = StandardSharedCExample_run;

    return mm;
}

apr_int32_t StandardSharedCExample_destroy(void * p) {
    if (!p)
        return -1;
    free((StandardSharedCExample *) p);
    return 0;
}

StandardSharedCExample_init() {
}
