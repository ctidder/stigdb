/* <tools/nycr/symbol/for_each_known_kind.h> 

   Yields each kind reachable from a given kind, in an order appropriate
   for class definitions.  (That is, superclasses before subclasses.)

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

#include <functional>

#include <tools/nycr/symbol/kind.h>

namespace Tools {

  namespace Nycr {

    namespace Symbol {

      /* TODO */
      void ForEachKnownKind(
          const TKind *kind, const std::function<void (const TKind *)> &cb);

    }  // Symbol

  }  // Nycr

}  // Tools

