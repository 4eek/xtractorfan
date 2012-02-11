/**
 * $Id: Path.h 5 2008-09-07 21:45:28Z kevin $
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

#ifndef PATH_H
#define PATH_H

//----------------------------------------------------------------------

#include <apr-1/apr.h>
#include <string>
#include <vector>

//----------------------------------------------------------------------

/**
 * @b Responsibility:
 *  1. Represent a cross-platform path to a filesystem object 
 *     (file, directory, symlink)
 *  
 *  2. Provide a slew of of path manipulation operations
 *
 * @b Rationale:
 *  File system paths are used a lot. It makes sense to have 
 *  a cross-platform class with a nice interface tailored to our needs. 
 *  In particular operations throw NTA::Exception on failure and 
 *  don't return error codes, which is alligned nicely with the
 *  way we handle errors.
 *
 *  Operations are both static and instance methods (use single implementation).
 *  Using Path objects is never required but it conveys the intention better than
 *  a string used as a path and some people prefer object-oriented interfaces 
 * (operator +=, anyone?).
 *  It is also a little shorter to call methods on a Path object.
 *  Suppose you have a Path object called p, then you can just do 'p.exists()'. 
 *  With a string p you need to do 'Path::exists(p)'. 
 *
 *  Path p("/");
 *  p.exists();
 *
 *
 * @b Resource/Ownerships:
 *  1. A path string for the instance.
 *  
 * @b Notes:
 *  The Path() constructors don't try to validate the path string
 *  for efficiency reasons (it's complicated too). If you pass
 *  an invalid path string it will fail when you actually try to use
 *  the resulting path.
 *
 *  The error handling strategy is to return error NULLs and not to throw exceptions.
 *  The reason is that it is a very generic low-level class that should not be aware
 *  and depend on the runtime's error handling policy. It may be used in different 
 *  contexts like tools and utilities that may utilize a different error handling 
 *  strategy. It is also a common idiom to return NULL from a failed factory method.
 *
 * @b Performance:
 *  The emphasis is on code readability and ease of use. Performance takes second
 *  place, because the critical path of our codebase doesn't involve a lot of 
 *  path manipulation. In particular, simple ANSI C or POSIX cross-platform implementation
 *  is often preffered to calling specific platform APIs. Whenever possible APR is 
 *  used under the covers.
 *
 *  Note, that constructing a Path object (or calling the Path instance methods)
 * involve an extra copy of the path string into the new Path instance. Again, this 
 * is not prohibitive in most cases. If you are concerned use plain strings and 
 * the static methods.  
 * 
 */
class Path {
public:
    typedef std::vector<std::string> StringVec;

    static const char * sep;

    static bool exists(const std::string & path);
    static std::string getParent(const std::string & path);
    static std::string getBasename(const std::string & path);
    static std::string getExtension(const std::string & path);
    static apr_size_t getFileSize(const std::string & path);
    static std::string normalize(const std::string & path);
    static std::string makeAbsolute(const std::string & path);
    static void split(const std::string & path, StringVec & parts);
    static std::string join(StringVec::iterator begin, StringVec::iterator end);
    static void copy(const std::string & source, const std::string & destination);
    static void remove(const std::string & path);
    static void rename(const std::string & oldPath, const std::string & newPath);
    static bool isDirectory(const std::string & path);
    static bool isFile(const std::string & path);
    static bool isSymbolicLink(const std::string & path);
    static bool isAbsolute(const std::string & path);
    static bool areEquivalent(const std::string & path1, const std::string & path2);

    Path(const std::string & path);
    operator const char*() const;

    Path & operator +=(const Path & path);
    bool exists() const;
    Path getParent() const;
    Path getBasename() const;
    Path getExtension() const;
    apr_size_t getFileSize() const;

    Path & normalize();
    Path & makeAbsolute();
    void split(StringVec & parts) const;

    void remove() const;
    void copy(const std::string & destination) const;
    void rename(const std::string & newPath);

    bool isDirectory() const;
    bool isFile() const;
    bool isAbsolute() const;
    bool isSymbolicLink() const;
    bool isEmpty() const;

private:
    Path();

private:
    std::string path_;
};

// Global operator  
Path operator+(const Path & p1, const Path & p2);

#endif


