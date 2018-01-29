#ifndef ANY_MAP_H_
#define ANY_MAP_H_

#include <any>
#include <initializer_list>
#include <string>
#include <unordered_map>
#include <utility>

namespace nathiss {

template <typename Key>
class AnyMap {
 public:
  AnyMap();
  explicit AnyMap(const AnyMap&);
  explicit AnyMap(AnyMap&&);
  explicit AnyMap(const std::unordered_map<Key, std::any>&);
  explicit AnyMap(std::unordered_map<Key, std::any>&&);
  AnyMap(std::initializer_list<std::pair<const Key, std::any>>);

  AnyMap& operator=(const AnyMap&);
  AnyMap& operator=(AnyMap&&);
  AnyMap& operator=(std::initializer_list<std::pair<const Key, std::any>>);

  template <typename T>
  void set(const Key&, const T&);

  template <typename T>
  void set(const Key&, T&&);

  template <typename T>
  void set(Key&&, const T&);

  template <typename T>
  void set(Key&&, T&&);

  template <typename T>
  T&& get(const Key&);

  template <typename T>
  T&& get(Key&&);

 private:
  std::unordered_map<Key, std::any> map_;
};

template <typename Key>
template <typename T>
void AnyMap<Key>::set(const Key& key, const T& value) {
  this->map_[key] = std::make_any<T>(value);
}

template <typename Key>
template <typename T>
void AnyMap<Key>::set(const Key& key, T&& value) {
  this->map_[key] = std::make_any<T>(std::move(value));
}

template <typename Key>
template <typename T>
void AnyMap<Key>::set(Key&& key, const T& value) {
  this->map_[std::move(key)] = std::make_any<T>(value);
}

template <typename Key>
template <typename T>
void AnyMap<Key>::set(Key&& key, T&& value) {
  this->map_[std::move(key)] = std::make_any<T>(std::move(value));
}

template <typename Key>
template <typename T>
T&& AnyMap<Key>::get(const Key& key) {
  auto tmp = std::any_cast<T>(this->map_[key]);
  return std::move(tmp);
}

template <typename Key>
template <typename T>
T&& AnyMap<Key>::get(Key&& key) {
  auto tmp = std::any_cast<T>(this->map_[std::move(key)]);
  return std::move(tmp);
}

}  // namespace nathiss

#endif  // ANY_MAP_H_
