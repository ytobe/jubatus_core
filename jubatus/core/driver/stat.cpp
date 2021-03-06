// Jubatus: Online machine learning framework for distributed environment
// Copyright (C) 2011,2012 Preferred Networks and Nippon Telegraph and Telephone Corporation.
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

#include "stat.hpp"

#include <algorithm>
#include <string>

#include "../framework/mixable.hpp"


namespace jubatus {
namespace core {
namespace driver {

stat::stat(jubatus::core::stat::stat* stat_method)
    : stat_(stat_method),
      mixable_stat_(stat_) {
  register_mixable(&mixable_stat_);
}

stat::~stat() {
}

void stat::push(const std::string& key, double value) {
  stat_->push(key, value);
}

double stat::sum(const std::string& key) const {
  return stat_->sum(key);
}

double stat::stddev(const std::string& key) const {
  return stat_->stddev(key);
}

double stat::max(const std::string& key) const {
  return stat_->max(key);
}

double stat::min(const std::string& key) const {
  return stat_->min(key);
}

double stat::entropy() const {
  return stat_->entropy();
}

double stat::moment(const std::string& key, int n, double c) const {
  return stat_->moment(key, n, c);
}

void stat::pack(framework::packer& pk) const {
  stat_->pack(pk);
}

void stat::unpack(msgpack::object o) {
  stat_->unpack(o);
}

void stat::clear() {
  stat_->clear();
}

}  // namespace driver
}  // namespace core
}  // namespace jubatus
