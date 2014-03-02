/* <mpl/or.h> 

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

#include <c14/type_traits.h>

#include <mpl/conditional.h>

namespace Mpl {

  template <typename... Preds>
  struct Or;

  template <>
  struct Or<> : public std::false_type {};

  template <typename Pred, typename... MorePreds>
  struct Or<Pred, MorePreds...> : public Conditional<Pred, std::true_type, Or<MorePreds...>> {};

}  // Mpl
