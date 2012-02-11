/**
 * $Id: ObjectAdapter.h 5 2008-09-07 21:45:28Z kevin $
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

#ifndef OBJECT_ADAPTER_H
#define OBJECT_ADAPTER_H

#include "plugin_framework/Plugin.h"

// This interface is used to adapt C plugin objects to C++ plugin objects.
// It must be passed to the PluginManager::createObject() function.

struct IObjectAdapter {

    virtual ~IObjectAdapter() {
    }
    virtual void * adapt(void * object, PF_DestroyFunc df) = 0;
};

// This template should be used if the object model implements the
// dual C/C++ object design pattern. Otherwise you need to provide
// your own object adapter class that implements IObjectAdapter

template<typename T, typename U>
struct ObjectAdapter : public IObjectAdapter {

    virtual void * adapt(void * object, PF_DestroyFunc df) {
        return new T((U *) object, df);
    }
};

#endif
