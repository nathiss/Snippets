#ifndef SETTINGS_BAG_H_
#define SETTINGS_BAG_H_

#include <any>
#include <string>
#include <unordered_map>
#include <utility>

namespace nathiss {

class SettingsBag {
 public:
  using Key = std::string;

  SettingsBag();
  SettingsBag(const SettingsBag&);
  SettingsBag(SettingsBag&&);

  SettingsBag& operator=(const SettingsBag&);
  SettingsBag& operator=(SettingsBag&&);

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
void SettingsBag::set(const SettingsBag::Key& key, const T& value) {
  this->map_[key] = std::make_any<T>(value);
}

template <typename T>
void SettingsBag::set(const SettingsBag::Key& key, T&& value) {
  this->map_[key] = std::make_any<T>(std::move(value));
}

template <typename T>
void SettingsBag::set(SettingsBag::Key&& key, const T& value) {
  this->map_[std::move(key)] = std::make_any<T>(value);
}

template <typename T>
void SettingsBag::set(SettingsBag::Key&& key, T&& value) {
  this->map_[std::move(key)] = std::make_any<T>(std::move(value));
}

template <typename T>
T&& SettingsBag::get(const SettingsBag::Key& key) {
  auto tmp = std::any_cast<T>(this->map_[key]);
  return std::move(tmp);
}

template <typename T>
T&& SettingsBag::get(SettingsBag::Key&& key) {
  auto tmp = std::any_cast<T>(this->map_[std::move(key)]);
  return std::move(tmp);
}

}  // namespace nathiss

#endif  // SETTINGS_BAG_H_
