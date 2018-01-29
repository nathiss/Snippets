#include "any_map.h"

namespace nathiss {

template <typename Key>
AnyMap<Key>::AnyMap() {}

template <typename Key>
AnyMap<Key>::AnyMap(const AnyMap& fac)
    : map_(fac.map_) {}

template <typename Key>
AnyMap<Key>::AnyMap(const std::unordered_map<Key, std::any>& map)
    : map_(map) {}

template <typename Key>
AnyMap<Key>::AnyMap(std::unordered_map<Key, std::any>&& map)
    : map_(std::move(map)) {}

template <typename Key>
AnyMap<Key>::AnyMap(AnyMap&& fac)
    : map_(std::move(fac.map_)) {}

template <typename Key>
AnyMap<Key>::AnyMap(std::initializer_list<std::pair<const Key, std::any>> l)
    : map_{l} {}

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

template <typename Key>
AnyMap<Key>& AnyMap<Key>::operator=(
  std::initializer_list<std::pair<const Key, std::any>> l) {
  this->map_ = l;
  return *this;
}

}  // namespace nathiss
