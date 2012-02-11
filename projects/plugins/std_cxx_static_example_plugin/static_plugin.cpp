/**
 * $Id: static_plugin.cpp 5 2008-09-07 21:45:28Z kevin $
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

#include "plugin_framework/Plugin.h"
#include "plugin_framework/PluginRegistrar.h"
#include "StandardStaticExample.h"

extern "C" apr_int32_t StaticPlugin_ExitFunc() {
    return 0;
}

extern "C" PF_ExitFunc StaticPlugin_InitPlugin(const PF_PlatformServices * params) {
    int res = 0;

    PF_RegisterParams rp;
    rp.version.major = 1;
    rp.version.minor = 0;
    rp.programmingLanguage = PF_ProgrammingLanguage_CPP;

    // Register StandardStaticExample
    rp.createFunc = StandardStaticExample::create;
    rp.destroyFunc = StandardStaticExample::destroy;
    res = params->registerObject((const apr_byte_t *) "StandardStaticExample", &rp);
    if (res < 0)
        return NULL;

    return StaticPlugin_ExitFunc;
}

PluginRegistrar StaticPlugin_registrar(PluginRegistrar);
