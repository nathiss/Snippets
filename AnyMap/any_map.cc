#include "any_map.h"

namespace nathiss {

template <typename Key>
AnyMap<Key>::AnyMap() {}

template <typename Key>
AnyMap<Key>::AnyMap(const AnyMap& fac)
    : map_(fac.map_) {}

template <typename Key>
AnyMap<Key>::AnyMap(AnyMap&& fac)
    : map_(std::move(fac.map_)) {}

template <typename Key>
AnyMap<Key>& AnyMap<Key>::operator=(const AnyMap& fac) {
  this->map_ = fac.map_;
  return *this;
}

template <typename Key>
AnyMap<Key>& AnyMap<Key>::operator=(AnyMap&& fac) {
  this->map_ = std::move(fac.map_);
  return *this;
}

}  // namespace nathiss
