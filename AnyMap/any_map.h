#ifndef ANY_MAP_H_
#define ANY_MAP_H_

#include <any>
#include <string>
#include <unordered_map>
#include <utility>

namespace nathiss {

class AnyMap {
 public:
  using Key = std::string;

  AnyMap();
  explicit AnyMap(const AnyMap&);
  explicit AnyMap(AnyMap&&);

  AnyMap& operator=(const AnyMap&);
  AnyMap& operator=(AnyMap&&);

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

template <typename T>
void AnyMap::set(const AnyMap::Key& key, const T& value) {
  this->map_[key] = std::make_any<T>(value);
}

template <typename T>
void AnyMap::set(const AnyMap::Key& key, T&& value) {
  this->map_[key] = std::make_any<T>(std::move(value));
}

template <typename T>
void AnyMap::set(AnyMap::Key&& key, const T& value) {
  this->map_[std::move(key)] = std::make_any<T>(value);
}

template <typename T>
void AnyMap::set(AnyMap::Key&& key, T&& value) {
  this->map_[std::move(key)] = std::make_any<T>(std::move(value));
}

template <typename T>
T&& AnyMap::get(const AnyMap::Key& key) {
  auto tmp = std::any_cast<T>(this->map_[key]);
  return std::move(tmp);
}

template <typename T>
T&& AnyMap::get(AnyMap::Key&& key) {
  auto tmp = std::any_cast<T>(this->map_[std::move(key)]);
  return std::move(tmp);
}

}  // namespace nathiss

#endif  // ANY_MAP_H_
