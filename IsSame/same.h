#ifndef SAME_H_
#define SAME_H_

namespace nathiss {

template <bool C>
struct bool_type {
  static constexpr bool value = C;
};

using true_type = bool_type<true>;

using false_type = bool_type<false>;

template <typename T, typename U>
struct is_same : false_type {};

template <typename T>
struct is_same<T, T> : true_type {};

template <typename T, typename U>
inline constexpr bool is_same_v = is_same<T, U>::value;

}  // namespace nathiss

#endif  // x_SAME_H_
