/**
 * $Id: ExtractorModelWrappers.h 5 2008-09-07 21:45:28Z kevin $
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

#ifndef EXTRACTOR_MODEL_WRAPPERS_H
#define EXTRACTOR_MODEL_WRAPPERS_H

#include <string>
#include <vector>
#include <map>

#include "ExtractorModel.h"
#include "c_ExtractorModel.h"

struct ExtractorInfoIteratorWrapper : public IExtractorInfoIterator {

    ExtractorInfoIteratorWrapper(C_ExtractorInfoIterator * iter) : index_(0) {
        iter->reset(iter->handle);

        // Create an internal vector of ExtractorInfo objects
        const ExtractorInfo * ai = NULL;
        while ((ai = iter->next(iter->handle)))
            vec_.push_back(*ai);
    }

    // IExtractorInfoIteraotr methods

    virtual void reset() {
        index_ = 0;
    }

    virtual ExtractorInfo * next() {
        if (index_ == vec_.size())
            return NULL;

        return &vec_[index_++];
    }

private:
    apr_uint32_t index_;
    std::vector<ExtractorInfo> vec_;
};

struct SessionWrapper : public ISession {

    SessionWrapper(C_Session * session) :
            session_(session) {
    }

    // ISession methods

    virtual ExtractorInfo * getSelfInfo() {
        return session_->getSelfInfo(session_->handle);
    }

private:
    C_Session * session_;
};

#endif
