/**
 * $Id: Exception.h 5 2008-09-07 21:45:28Z kevin $
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

#ifndef STREAMING_EXCEPTION
#define STREAMING_EXCEPTION

#include <iostream>
#include <sstream>
#include <memory>
#include <stdexcept>

class StreamingException : public std::runtime_error {
public:

    StreamingException() :
    std::runtime_error(""),
    ss_(std::auto_ptr<std::stringstream>
            (new std::stringstream())) {
    }

    ~StreamingException() throw () {
    }

    template <typename T>
    StreamingException & operator <<(const T & t) {
        (*ss_) << t;
        return *this;
    }

    virtual const char * what() const throw () {
        s_ = ss_->str();
        return s_.c_str();
    }

private:
    mutable std::auto_ptr<std::stringstream> ss_;
    mutable std::string s_;
};
#endif
