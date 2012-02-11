/**
 * $Id: xTractorFan.cpp 5 2008-09-07 21:45:28Z kevin $
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
#include "stdafx.h"
#endif

#include "plugin_framework/PluginManager.h"
#include "plugin_framework/Path.h"
#include "AppManager.h"
#include <string>
#include <iostream>
// Static Plugins
#include "../plugins/std_cxx_static_example_plugin/static_plugin.h"

using std::cout;
using std::endl;

apr_int32_t DummyInvokeService(const apr_byte_t * serviceName, void * serviceParams) {
    return 0;
}

#ifdef WIN32
int _tmain(int argc, _TCHAR* argv[])
#else

int main(int argc, char * argv[])
#endif
{
    cout << "Welcome to xTractorFan!" << endl;
    if (argc != 2) {
        cout << "Usage: xTractorFan <plugins dir>" << endl;
        return -1;
    }

    // Initialization
    ::apr_initialize();
    PluginManager & plugMan = PluginManager::getInstance();
    // Get the services we provide to the plugins
    plugMan.getPlatformServices().invokeService = DummyInvokeService;
    // Load all the plugins in the various plugins folders
    plugMan.loadAll(Path::makeAbsolute(argv[1]));
    // Explicitly init static plugins
    PluginManager::initializePlugin(StaticPlugin_InitPlugin);

    // Activate the App Manager
    AppManager::getInstance().go();

    ::apr_terminate();

    return 0;
}
