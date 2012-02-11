/**
 * $Id: DynamicLibrary.cpp 5 2008-09-07 21:45:28Z kevin $
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

#ifdef WIN32
#include <Windows.h>
#else
#include <dlfcn.h>
#endif

#include "DynamicLibrary.h"
#include <sstream>
#include <iostream>

DynamicLibrary::DynamicLibrary(void * handle) : handle_(handle) {
}

DynamicLibrary::~DynamicLibrary() {
    if (handle_) {
#ifndef WIN32
        ::dlclose(handle_);
#else
        ::FreeLibrary((HMODULE) handle_);
#endif
    }
}

DynamicLibrary * DynamicLibrary::load(const std::string & name,
        std::string & errorString) {
    if (name.empty()) {
        errorString = "Empty path.";
        return NULL;
    }

    void * handle = NULL;

#ifdef WIN32
    handle = ::LoadLibraryA(name.c_str());
    if (handle == NULL) {
        DWORD errorCode = ::GetLastError();
        std::stringstream ss;
        ss << std::string("LoadLibrary(") << name
                << std::string(") Failed. errorCode: ")
                << errorCode;
        errorString = ss.str();
    }
#else
    handle = ::dlopen(name.c_str(), RTLD_NOW);
    if (!handle) {
        std::string dlErrorString;
        const char *zErrorString = ::dlerror();
        if (zErrorString)
            dlErrorString = zErrorString;
        errorString += "Failed to load \"" + name + '"';
        if (dlErrorString.size())
            errorString += ": " + dlErrorString;
        return NULL;
    }

#endif
    return new DynamicLibrary(handle);
}

void * DynamicLibrary::getSymbol(const std::string & symbol) {
    if (!handle_)
        return NULL;

#ifdef WIN32
    return ::GetProcAddress((HMODULE) handle_, symbol.c_str());
#else
    return ::dlsym(handle_, symbol.c_str());
#endif
}
