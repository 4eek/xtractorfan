/**
 * $Id: AppManager.h 5 2008-09-07 21:45:28Z kevin $
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

#ifndef APP_MANAGER_H
#define APP_MANAGER_H

#include <list>
#include <map>
#include <boost/shared_ptr.hpp>
#include <plugin_framework/PluginManager.h>
#include "Dummy.h"

class AppManager {
    typedef std::pair<apr_int32_t, apr_int32_t> Location;
    typedef std::vector<std::string> PluginTypeVec;
    typedef std::vector<std::string> ExtractorTypeVec;
    typedef std::map<IExtractor *, ExtractorInfo> ExtractorMap;

public:
    static AppManager & getInstance();
    void go();

private:
    AppManager();
    ~AppManager();

private:
    // Vector of pluginTypes
    PluginTypeVec pluginTypes_;

    // Map of actual extractors
    ExtractorMap extractors_;
    // Vector of extractorTypes
    ExtractorTypeVec extractorTypes_;
};

#endif