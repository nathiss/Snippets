#ifndef SINGLETON_H_
#define SINGLETON_H_

#include <memory>

namespace nathiss {

template <typename T>
class Singleton {
 public:
  static T& Instance();

 protected:
  Singleton() {};

 private:
  static std::unique_ptr<T> instance_;
};

}  // namespace nathiss

#endif  // SINGLETON_H_
