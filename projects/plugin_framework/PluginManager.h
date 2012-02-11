/**
 * $Id: PluginManager.h 5 2008-09-07 21:45:28Z kevin $
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

#ifndef PLUGIN_MANAGER_H
#define PLUGIN_MANAGER_H

#include <vector>
#include <map>
#include <apr-1/apr.h>
#include <boost/shared_ptr.hpp>
#include "plugin_framework/Plugin.h"

class DynamicLibrary;
struct IObjectAdapter;

class PluginManager {
    typedef std::map<std::string, boost::shared_ptr<DynamicLibrary> > DynamicLibraryMap;
    typedef std::vector<PF_ExitFunc> ExitFuncVec;
    typedef std::vector<PF_RegisterParams> RegistrationVec;

public:
    typedef std::map<std::string, PF_RegisterParams> RegistrationMap;

    static PluginManager & getInstance();
    static apr_int32_t initializePlugin(PF_InitFunc initFunc);
    apr_int32_t loadAll(const std::string & pluginDirectory, PF_InvokeServiceFunc func = NULL);
    apr_int32_t loadByPath(const std::string & path);

    void * createObject(const std::string & objectType, IObjectAdapter & adapter);

    apr_int32_t shutdown();
    static apr_int32_t registerObject(const apr_byte_t * nodeType,
            const PF_RegisterParams * params);
    const RegistrationMap & getRegistrationMap();
    PF_PlatformServices & getPlatformServices();

private:
    ~PluginManager();
    PluginManager();
    PluginManager(const PluginManager &);

    DynamicLibrary * loadLibrary(const std::string & path, std::string & errorString);
private:
    bool inInitializePlugin_;
    PF_PlatformServices platformServices_;
    DynamicLibraryMap dynamicLibraryMap_;
    ExitFuncVec exitFuncVec_;

    RegistrationMap tempExactMatchMap_; // register exact-match object types
    RegistrationVec tempWildCardVec_; // wild card ('*') object types

    RegistrationMap exactMatchMap_; // register exact-match object types
    RegistrationVec wildCardVec_; // wild card ('*') object types
};


#endif
