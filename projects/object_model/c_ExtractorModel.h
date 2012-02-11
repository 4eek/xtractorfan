/**
 * $Id: c_ExtractorModel.h 5 2008-09-07 21:45:28Z kevin $
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

#ifndef C_EXTRACTOR_MODEL_H
#define C_EXTRACTOR_MODEL_H

#include <apr-1/apr.h>

#define MAX_STR 64 /* max string length of string fields */

typedef struct C_ExtractorInfo_
{
  apr_uint32_t id;
  apr_byte_t   name[MAX_STR];
  apr_byte_t   desc[MAX_STR];
} C_ExtractorInfo;

typedef struct C_ExtractorInfoIteratorHandle_ { char c; } * C_ExtractorInfoIteratorHandle; 
typedef struct C_ExtractorInfoIterator_
{
  void (*reset)(C_ExtractorInfoIteratorHandle handle);
  C_ExtractorInfo * (*next)(C_ExtractorInfoIteratorHandle handle);

  C_ExtractorInfoIteratorHandle handle;
} C_ExtractorInfoIterator;

typedef struct C_SessionHandle_ { char c; } * C_SessionHandle; 
typedef struct C_Session_
{
  C_ExtractorInfo * (*getSelfInfo)(C_SessionHandle handle);

  C_SessionHandle handle;
} C_Session;

typedef struct C_ExtractorHandle_ { char c; } * C_ExtractorHandle; 
typedef struct C_Extractor_
{
  void (*getInitialInfo)(C_ExtractorHandle handle, C_ExtractorInfo * info);
  void (*run)(C_ExtractorHandle handle, C_Session * session); 
  void (*get)(C_ExtractorHandle handle, char * resource); 
  void (*put)(C_ExtractorHandle handle, char * resource); 
  void (*validate)(C_ExtractorHandle handle, char * resource); 
  void (*remove)(C_ExtractorHandle handle, char * resource); 

  C_ExtractorHandle handle;
} C_Extractor;

typedef struct LogParmas
{
  const apr_byte_t * filename;
  apr_uint32_t       line;
  const apr_byte_t * message;
} LogParmas;

typedef struct ReportErrorParmas
{
  const apr_byte_t * filename;
  apr_uint32_t       line;
  const apr_byte_t * message;
} ReportErrorParmas;

#endif
