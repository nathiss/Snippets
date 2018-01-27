#ifndef _SAME_H
#define _SAME_H

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

#endif // _SAME_H

