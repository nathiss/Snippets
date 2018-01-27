#include "settings_bag.h"

namespace nathiss {

SettingsBag::SettingsBag() {}

SettingsBag::SettingsBag(const SettingsBag& fac)
    : map_(fac.map_) {}

SettingsBag::SettingsBag(SettingsBag&& fac)
    : map_(std::move(fac.map_)) {}

SettingsBag& SettingsBag::operator=(const SettingsBag& fac) {
  this->map_ = fac.map_;
  return *this;
}

SettingsBag& SettingsBag::operator=(SettingsBag&& fac) {
  this->map_ = std::move(fac.map_);
  return *this;
}

}  // namespace nathiss
