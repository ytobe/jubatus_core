// Jubatus: Online machine learning framework for distributed environment
// Copyright (C) 2016 Preferred Networks and Nippon Telegraph and Telephone Corporation.
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

#ifndef JUBATUS_CORE_CLASSIFIER_EUCLIDEAN_DISTANCE_CLASSIFIER_HPP_
#define JUBATUS_CORE_CLASSIFIER_EUCLIDEAN_DISTANCE_CLASSIFIER_HPP_

#include <string>
#include "inverted_index_classifier.hpp"

namespace jubatus {
namespace core {
namespace classifier {

class euclidean_distance_classifier : public inverted_index_classifier {
 public:
  euclidean_distance_classifier(
    size_t k,
    float alpha);
  void classify_with_scores(
      const common::sfv_t& fv, classify_result& scores) const;

  std::string name() const;
};

}  // namespace classifier
}  // namespace core
}  // namespace jubatus

#endif  // JUBATUS_CORE_CLASSIFIER_EUCLIDEAN_DISTANCE_CLASSIFEIR_HPP_
