// Jubatus: Online machine learning framework for distributed environment
// Copyright (C) 2014 Preferred Infrastructure and Nippon Telegraph and Telephone Corporation.
//
// This library is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public
// License version 2.1 as published by the Free Software Foundation.
//
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public
// License along with this library; if not, write to the Free Software
// Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA

#ifndef JUBATUS_CORE_DRIVER_BANDIT_HPP_
#define JUBATUS_CORE_DRIVER_BANDIT_HPP_

#include <map>
#include <string>
#include <vector>
#include "jubatus/util/lang/shared_ptr.h"
#include "../bandit/bandit_base.hpp"
#include "../common/jsonconfig.hpp"
#include "../framework/mixable.hpp"
#include "../framework/mixable_helper.hpp"
#include "driver.hpp"

namespace jubatus {
namespace core {
namespace driver {

class bandit : public driver_base {
 public:
  typedef core::bandit::bandit_base bandit_base;
  typedef core::bandit::storage bandit_storage;

  bandit(const std::string& method_name,
         const common::jsonconfig::config& param);

  void clear();
  void pack(framework::packer& pk) const;
  void unpack(msgpack::object o);

 private:
  jubatus::util::lang::shared_ptr<bandit_base> bandit_;
  framework::linear_mixable_helper<bandit_storage,
      bandit_storage::table_t> mixable_storage_;
};

}  // namespace driver
}  // namespace core
}  // namespace jubatus

#endif  // JUBATUS_CORE_DRIVER_BANDIT_HPP_
