#ifndef SINGLETON_H_
#define SINGLETON_H_

#include <memory>

namespace nathiss {

template <typename T>
class Singleton {
 public:
  Singleton() = delete;
  Singleton(const Singleton&) = delete;
  Singleton(Singleton&&) = delete;
  Singleton& operator=(const Singleton&) = delete;
  Singleton& operator=(Singleton&&) = delete;

  [[nodiscard]] static T& Instance() noexcept;

 private:
  static std::unique_ptr<T> instance_;
};

}  // namespace nathiss

#endif  // SINGLETON_H_
