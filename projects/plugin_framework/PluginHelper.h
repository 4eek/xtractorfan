/**
 * $Id: PluginHelper.h 5 2008-09-07 21:45:28Z kevin $
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

#ifndef PF_PLUGIN_HELPER_H
#define PF_PLUGIN_HELPER_H

#include "Plugin.h"
#include "base.h"

class PluginHelper {

    struct RegisterParams : public PF_RegisterParams {

        RegisterParams(PF_PluginAPI_Version v,
                PF_CreateFunc cf,
                PF_DestroyFunc df,
                PF_ProgrammingLanguage pl) {
            version = v;
            createFunc = cf;
            destroyFunc = df;
            programmingLanguage = pl;
        }
    };
public:

    PluginHelper(const PF_PlatformServices * params) :
    params_(params),
    result_(exitPlugin) {
    }

    PF_ExitFunc getResult() {
        return result_;
    }

    template <typename T>
    void registerObject(const apr_byte_t * objectType,
            PF_ProgrammingLanguage pl = PF_ProgrammingLanguage_C) {
        PF_PluginAPI_Version v = {1, 0};

        // Version check
        try {
            CHECK(params_->version.major >= v.major)
                    << "Version mismatch. PluginManager version must be "
                    << "at least " << v.major << "." << v.minor;

            RegisterParams rp(v, T::create, T::destroy, pl);
            apr_int32_t rc = params_->registerObject(objectType, &rp);

            CHECK(rc >= 0)
                    << "Registration of object type "
                    << objectType << "failed. "
                    << "Error code=" << rc;
        } catch (...) {
            result_ = NULL;
        }
    }

    static apr_int32_t exitPlugin() {
        return 0;
    }

private:
    const PF_PlatformServices * params_;
    PF_ExitFunc result_;
};

#endif

