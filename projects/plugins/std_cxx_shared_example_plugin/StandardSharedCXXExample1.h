/**
 * $Id: StandardSharedCXXExample1.h 5 2008-09-07 21:45:28Z kevin $
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

#ifndef STANDARD_SHARED_CXX_EXAMPLE1_H
#define STANDARD_SHARED_CXX_EXAMPLE1_H

#include <vector>
#include <map>
#include <boost/shared_ptr.hpp>
#include <object_model/ExtractorModel.h>

struct PF_ObjectParams;

class StandardSharedCXXExample1 : public IExtractor {
public:

    // static plugin interface
    static void * create(PF_ObjectParams *);
    static apr_int32_t destroy(void *);
    ~StandardSharedCXXExample1();

    // IExtractor methods
    virtual void getInitialInfo(ExtractorInfo * info);
    virtual void run(ISession * sessionInfo);
    // TODO: resouce below needs to be a string or more complex object
    virtual void put(char * resource);
    virtual void get(char * resource);
    virtual void verify(char * resource);
    virtual void remove(char * resource);

private:
    StandardSharedCXXExample1();
};

#endif
