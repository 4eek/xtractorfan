/**
 * $Id: ExtractorBaseTemplate.h 5 2008-09-07 21:45:28Z kevin $
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

#ifndef EXTRACTOR_BASE_TEMPLATE_H
#define EXTRACTOR_BASE_TEMPLATE_H

#include "plugin_framework/Plugin.h"
#include "plugin_framework/StreamingException.h"
#include "ExtractorModel.h"
#include "Services.h"
#include "ExtractorModelWrappers.h"

template <typename T, typename Interface = C_Extractor>
        class ExtractorBaseTemplate :
        public C_Extractor,
        public IExtractor {
public:

    ExtractorBaseTemplate() : invokeService_(NULL) {
        // Initialize the function pointers of the C_Extractor base class
        C_Extractor::getInitialInfo = staticGetInitialInfo;
        C_Extractor::run = staticRun;
        C_Extractor * handle = this;
        C_Extractor::handle = (C_ExtractorHandle) handle;
    }

    virtual ~ExtractorBaseTemplate() {
    }

    // PF_CreateFunc from Plugin.h

    static void * create(PF_ObjectParams * params) {
        T * extractor = new T(params);
        // Set the error reporting function pointer
        extractor->invokeService_ = params->platformServices->invokeService;

        // return the extractor with the correct interface
        return static_cast<Interface *> (extractor);
    }

    // PF_DestroyFunc from Plugin.h

    static apr_int32_t destroy(void * extractor) {
        if (!extractor)
            return -1;
        delete ExtractorBaseTemplate<T, Interface>::getSelf(reinterpret_cast<Interface *> (extractor));
        return 0;
    }

    // Helper method to convert the C_Extractor * argument
    // in every method to a ExtractorBaseTemplate<T, Interface> instance pointer

    static ExtractorBaseTemplate<T, Interface> * getSelf(C_Extractor * extractor) {
        return static_cast<ExtractorBaseTemplate<T, Interface> *> (extractor);
    }

    static ExtractorBaseTemplate<T, Interface> * getSelf(IExtractor * extractor) {
        return static_cast<ExtractorBaseTemplate<T, Interface> *> (extractor);
    }

    static ExtractorBaseTemplate<T, Interface> * getSelf(C_ExtractorHandle handle) {
        return static_cast<ExtractorBaseTemplate<T, Interface> *> ((C_Extractor *) handle);
    }

    // Helper method to report errors from a static function

    static void reportError(C_ExtractorHandle handle,
            const apr_byte_t * filename,
            apr_uint32_t line,
            const apr_byte_t * message) {
        ExtractorBaseTemplate<T, Interface> * self = ExtractorBaseTemplate<T, Interface>::getSelf(handle);
        ReportErrorParams rep;
        rep.filename = filename;
        rep.line = line;
        rep.message = message;
        self->invokeService_((const apr_byte_t *) "reportError", &rep);
    }

    // C_Extractor functions

    static void staticGetInitialInfo(C_ExtractorHandle handle, C_ExtractorInfo * info) {

        ExtractorBaseTemplate<T, Interface> * self = ExtractorBaseTemplate<T, Interface>::getSelf(handle);
        try {
            self->getInitialInfo(info);
        } catch (const StreamingException & e) {
            ExtractorBaseTemplate<T, Interface>::reportError(handle, (const apr_byte_t *) e.filename_.c_str(), e.line_, (const apr_byte_t *) e.what());
        } catch (const std::runtime_error & e) {
            ExtractorBaseTemplate<T, Interface>::reportError(handle, (const apr_byte_t *) __FILE__, __LINE__, (const apr_byte_t *) e.what());
        } catch (...) {
            ExtractorBaseTemplate<T, Interface>::reportError(handle, (const apr_byte_t *) __FILE__, __LINE__, (const apr_byte_t *) "ExtractorBaseTemplate<T, Interface>::staticGetInitialInfo() failed");
        }
    }

    static void staticRun(C_ExtractorHandle handle, C_Session * session) {
        try {
            SessionWrapper tw(session);
            getSelf((C_Extractor *) handle)->run(&tw);
        } catch (const StreamingException & e) {
            ExtractorBaseTemplate<T, Interface>::reportError(handle, (const apr_byte_t *) e.filename_.c_str(), e.line_, (const apr_byte_t *) e.what());
        } catch (const std::runtime_error & e) {
            ExtractorBaseTemplate<T, Interface>::reportError(handle, (const apr_byte_t *) __FILE__, __LINE__, (const apr_byte_t *) e.what());
        } catch (...) {
            ExtractorBaseTemplate<T, Interface>::reportError(handle, (const apr_byte_t *) __FILE__, __LINE__, (const apr_byte_t *) "ExtractorBaseTemplate<T, Interface>::staticRun() failed");
        }
    }

    // Empty implementation of IExtractor

    virtual void getInitialInfo(ExtractorInfo * info) {
    }

    virtual void run(ISession * sessionInfo) {
    }

private:
    PF_InvokeServiceFunc invokeService_;
};

#endif
