/**
 * $Id: Directory.h 5 2008-09-07 21:45:28Z kevin $
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

#ifndef DIRECTORY_H
#define DIRECTORY_H

//----------------------------------------------------------------------

#include <apr-1/apr.h>
#include <apr-1/apr_file_info.h>
#include <string>
#ifdef PF_PLATFORM_LINUX
#include <dirent.h>
#include <sys/stat.h>
#endif

//----------------------------------------------------------------------

class Path;

namespace Directory {
    // check if a directory exists
    bool exists(const std::string & path);

    // get current working directory
    std::string getCWD();

    // set current working directories
    void setCWD(const std::string & path);

    // Copy directory tree rooted in 'source' to 'destination'
    void copyTree(const std::string & source, const std::string & destination);

    // Remove directory tree rooted in 'path'
    void removeTree(const std::string & path);

    // Create directory 'path' including all parent directories if missing
    void create(const std::string & path);

    struct Entry
#ifndef PF_PLATFORM_LINUX
    : public apr_finfo_t
#endif
    {

        enum Type {
            FILE, DIRECTORY, LINK
        };

        Type type;
        std::string path;
    };

    class Iterator {
    public:

        Iterator(const Path & path);
        Iterator(const std::string & path);
        ~Iterator();

        // Resets directory to start. Subsequent call to next()
        // will retrieve the first entry
        void reset();
        // get next directory entry
        Entry * next(Entry & e);

    private:
        Iterator();
        Iterator(const Iterator &);

        void init(const std::string & path);
    private:
        std::string path_;
#ifdef PF_PLATFORM_LINUX
        DIR * handle_;
#else
        apr_dir_t * handle_;
        apr_pool_t * pool_;
#endif    
    };
}


#endif


