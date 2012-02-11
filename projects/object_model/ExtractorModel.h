/**
 * $Id: ExtractorModel.h 5 2008-09-07 21:45:28Z kevin $
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

/**
 * This is the Extractor Model Interface
 * It provides an interface that a plugin can implement to manage and perform
 * all storage related actions in xTractorFan.
 *
 * The interface provides generic methods like put(resource). It's up to the
 * plugin to decide what that means to it. The standard extractor is a disk extractor
 * that will implement that method by writing(putting) a file(resource) to disk.
 *
 * Another extractor plugin may decide that put(resource) means copying(putting) a
 * file(resource) to Amazon S3 or an FTP site or doing an rsync on the resource,
 * etc.
 *
 * It's important these methods are as generic as possible so they are
 * applicable to the widest range of future extractor types.
 *
 */

#ifndef EXTRACTOR_MODEL_H
#define EXTRACTOR_MODEL_H

#include <string.h>
#include "c_ExtractorModel.h"

typedef C_ExtractorInfo ExtractorInfo;

struct IExtractorInfoIterator {
    virtual void reset() = 0;
    virtual ExtractorInfo * next() = 0;
};

struct ISession {
    virtual ExtractorInfo * getSelfInfo() = 0;
};

struct IExtractor {
    virtual void getInitialInfo(ExtractorInfo * info) = 0;
    virtual void run(ISession * sessionInfo) = 0;
    // TODO: resouce below needs to be a string or more complex object
    virtual void put(char * resource) = 0;
    virtual void get(char * resource) = 0;
    virtual void verify(char * resource) = 0;
    virtual void remove(char * resource) = 0;

};

#endif
