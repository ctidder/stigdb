/* <starsha/cc_file.h> 

   TODO

   Copyright 2010-2014 Tagged
   
   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at
   
     http://www.apache.org/licenses/LICENSE-2.0
   
   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License. */

#pragma once

#include <base/no_copy_semantics.h>
#include <starsha/c_family_file.h>

namespace Starsha {

  /* TODO */
  class TCcFile
      : public TCFamilyFile {
    NO_COPY_SEMANTICS(TCcFile);
    public:

    /* TODO */
    virtual const TKind *GetKind() const;

    private:

    /* TODO */
    TCcFile(TCorpus *corpus, const std::string &rel_path)
        : TCFamilyFile(corpus, rel_path, "g++") {}

    /* TODO */
    TCcFile(TCorpus *corpus, const std::string &rel_path, time_t mod_time)
        : TCFamilyFile(corpus, rel_path, mod_time, "g++") {}

    /* TODO */
    virtual ~TCcFile();

    /* TODO */
    static const TSpecificKind<TCcFile> Kind;

    /* TODO */
    friend class TSpecificKind<TCcFile>;

  };  // TCcFile

}  // Starsha

