/**
 * $Id: AppManager.cpp 5 2008-09-07 21:45:28Z kevin $
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

#include "AppManager.h"
#include <object_model/Session.h>
#include <object_model/ExtractorFactory.h>
#include <plugin_framework/PluginManager.h>
#include <plugin_framework/Plugin.h>

#include <string>
#include <algorithm>
#include <iterator>
#include <iostream>

AppManager & AppManager::getInstance() {
    static AppManager appMan;

    return appMan;
}

AppManager::AppManager() {

}

AppManager::~AppManager() {
}

void AppManager::go() {
    // Get all Plugin types
    PluginManager & appMan = PluginManager::getInstance();
    const PluginManager::RegistrationMap & rm = appMan.getRegistrationMap();

    for (PluginManager::RegistrationMap::const_iterator i = rm.begin(); i != rm.end(); ++i) {
        pluginTypes_.push_back(i->first);
    }

    // Dump all the Plugins
    std::cout << std::endl << "Dumping the list of available plugins..." << std::endl;
    for (PluginTypeVec::iterator i = pluginTypes_.begin(); i != pluginTypes_.end(); ++i) {
        std::string m = *i;
        std::cout << m.c_str() << std::endl;
    }

    ExtractorInfo * si = new ExtractorInfo;

    IExtractor * extractor = ExtractorFactory::createExtractor("StandardSharedCExample");
    extractor->getInitialInfo(si);
    std::cout << std::endl << "Activated: " << si->name << "(" << si->desc << ")" << std::endl;
}
