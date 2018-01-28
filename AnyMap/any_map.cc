#include "any_map.h"

namespace nathiss {

AnyMap::AnyMap() {}

AnyMap::AnyMap(const AnyMap& fac)
    : map_(fac.map_) {}

AnyMap::AnyMap(AnyMap&& fac)
    : map_(std::move(fac.map_)) {}

AnyMap& AnyMap::operator=(const AnyMap& fac) {
  this->map_ = fac.map_;
  return *this;
}

AnyMap& AnyMap::operator=(AnyMap&& fac) {
  this->map_ = std::move(fac.map_);
  return *this;
}

}  // namespace nathiss
