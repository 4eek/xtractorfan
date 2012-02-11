/**
 * $Id: StandardStaticExample.cpp 5 2008-09-07 21:45:28Z kevin $
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

#include "StandardStaticExample.h"
#include <string.h>
#include <utils/utils.h>

void * StandardStaticExample::create(PF_ObjectParams *) {
    return new StandardStaticExample();
}

apr_int32_t StandardStaticExample::destroy(void * p) {
    if (!p)
        return -1;
    delete (StandardStaticExample *) p;
    return 0;
}

StandardStaticExample::StandardStaticExample() {
}

StandardStaticExample::~StandardStaticExample() {
}

void StandardStaticExample::getInitialInfo(ExtractorInfo * info) {
    ::strcpy((char *) info->name, "StandardStaticExample");
    ::strcpy((char *) info->desc, "Standard Extractor Static Example Plugin");
}

void StandardStaticExample::run(ISession * sessionInfo) {
    // Get self
    const ExtractorInfo * self = sessionInfo->getSelfInfo();

}

void StandardStaticExample::put(char * resource) {
    // Do stuff
}

void StandardStaticExample::get(char * resource) {
    // Do stuff
}

void StandardStaticExample::verify(char * resource) {
    // Do stuff
}

void StandardStaticExample::remove(char * resource) {
    // Do stuff
}

