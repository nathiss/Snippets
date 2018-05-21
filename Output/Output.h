#ifndef NATHISS_OUTPUT_OUTPUT_H_
#define NATHISS_OUTPUT_OUTPUT_H_

namespace nathiss::output {

#include <type_traits>

template <class T>
class Output {
  static_assert(std::is_lvalue_reference_v<T>, "output: only non-const references");
  static_assert(!std::is_const_v<T>, "output: only non-const references");

 public:
  explicit Output(T& ref) : _ref(ref) {}

  T& get() { return _ref; }
  const T& get() const { return _ref; }

 private:
  T& _ref;
};

}  // namespace nathiss::output

#endif  // NATHISS_OUTPUT_OUTPUT_H_
