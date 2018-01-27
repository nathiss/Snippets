#include "singleton.h"

namespace nathiss {

template <typename T>
std::unique_ptr<T> Singleton<T>::instance_ = nullptr;

template <typename T>
T& Singleton<T>::Instance() {
  if (instance_ == nullptr)
    instance_ = std::make_unique<T>();
  return *instance_;
}

}  // namespace nathiss
