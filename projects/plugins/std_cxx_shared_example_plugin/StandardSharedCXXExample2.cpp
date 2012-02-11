/**
 * $Id: StandardSharedCXXExample2.cpp 5 2008-09-07 21:45:28Z kevin $
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

#include "StandardSharedCXXExample2.h"
#include <string.h>

void * StandardSharedCXXExample2::create(PF_ObjectParams *) {
    return new StandardSharedCXXExample2();
}

apr_int32_t StandardSharedCXXExample2::destroy(void * p) {
    if (!p)
        return -1;
    delete (StandardSharedCXXExample2 *) p;
    return 0;
}

StandardSharedCXXExample2::StandardSharedCXXExample2() {
}

StandardSharedCXXExample2::~StandardSharedCXXExample2() {
}

void StandardSharedCXXExample2::getInitialInfo(ExtractorInfo * info) {
    ::strcpy((char *) info->name, "StandardSharedCXXExample2");
    ::strcpy((char *) info->desc, "Standard Extractor Shared C++ Example2 Plugin");
}

void StandardSharedCXXExample2::run(ISession * sessionInfo) {
    // Do stuff
}

void StandardSharedCXXExample2::put(char * resource) {
    // Do stuff
}

void StandardSharedCXXExample2::get(char * resource) {
    // Do stuff
}

void StandardSharedCXXExample2::verify(char * resource) {
    // Do stuff
}

void StandardSharedCXXExample2::remove(char * resource) {
    // Do stuff
}
