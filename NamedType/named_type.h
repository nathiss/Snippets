#ifndef NATHISS_NAMED_H_
#define NATHISS_NAMED_H_

#include <utility>

namespace nathiss {

template <typename T, typename Parameter>
class NamedType {
 public:
  explicit NamedType(const T& value) : value_(value) {}
  explicit NamedType(T&& value) : value_(std::move(value)) {}

  T& get() noexcept { return value_; }
  const T& get() const noexcept { return value_; }

  T& operator()() noexcept { return value_; }
  const T& operator()() const noexcept { return value_; }

  T& operator*() noexcept { return value_; }
  const T& operator*() const noexcept { return value_; }

 private:
  T value_;
};

}  // namespace nathiss

#endif  // NATHISS_NAMED_H
