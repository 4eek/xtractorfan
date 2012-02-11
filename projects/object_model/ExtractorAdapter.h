/**
 * $Id: ExtractorAdapter.h 5 2008-09-07 21:45:28Z kevin $
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

#ifndef EXTRACTOR_ADAPTER_H
#define EXTRACTOR_ADAPTER_H

#include "object_model/ExtractorModel.h"
#include "c_ExtractorModel.h"

class ExtractorAdapter : public IExtractor {
public:

    ExtractorAdapter(C_Extractor * extractor, PF_DestroyFunc destroyFunc) :
    extractor_(extractor),
    destroyFunc_(destroyFunc) {
    }

    ~ExtractorAdapter() {
        if (destroyFunc_)
            destroyFunc_(extractor_);
    }

    // IExtractor implememntation

    void getInitialInfo(ExtractorInfo * info) {
        extractor_->getInitialInfo(extractor_->handle, info);
    }

    void run(ISession * sessionInfo) {
        extractor_->run(extractor_->handle, static_cast<Session *> (sessionInfo));
    }

    void put(char * resource) {
        extractor_->put(extractor_->handle, resource);
    }

    void get(char * resource) {
        extractor_->get(extractor_->handle, resource);
    }

    void verify(char * resource) {
        extractor_->validate(extractor_->handle, resource);
    }

    void remove(char * resource) {
        extractor_->remove(extractor_->handle, resource);
    }

private:
    C_Extractor * extractor_;
    PF_DestroyFunc destroyFunc_;
};

#endif
