#ifndef MATH_VECTOR_H_
#define MATH_VECTOR_H_

#include <cstdlib>
#include <utility>
#include <vector>

namespace nathiss {

template <typename T>
class MathVector {
 public:
  using const_iterator = const T*;
  using iterator = T*;
  using const_reference = const T&;
  using reference = T&;
  using size_type = std::size_t;

  explicit MathVector(size_type size = 0);
  MathVector(size_type size, const T& value);
  explicit MathVector(const MathVector& fac);
  explicit MathVector(MathVector&& fac);

  MathVector& operator=(const MathVector& fac);
  MathVector& operator=(MathVector&& fac);


  reference at(size_type pos);
  const_reference at(size_type pos) const;

  reference operator[](size_type pos);
  const_reference operator[](size_type pos) const;

  reference front();
  const_reference front() const;

  reference back();
  const_reference back() const;

  T* data() noexcept;
  const T* data() const noexcept;


  iterator begin() noexcept;
  const_iterator begin() const noexcept;
  const_iterator cbegin() const noexcept;

  iterator end() noexcept;
  const_iterator end() const noexcept;
  const_iterator cend() const noexcept;


  bool empty() const noexcept;

  size_type size() const noexcept;


  void clear() noexcept;

  iterator insert(const_iterator pos, const T& value);
  iterator insert(const_iterator pos, T&& value);

  iterator erase(const_iterator pos);
  iterator erase(const_iterator first, const_iterator last);

  void resize(size_type count);
  void resize(size_type count, const T& value);

  void swap(MathVector&) noexcept;

  MathVector<T>& operator+=(const MathVector<T>& vec);
  MathVector<T>& operator+=(MathVector<T>&& vec);

  template <typename Scalar>
  MathVector<T>& operator*=(Scalar scal);

  friend MathVector<T>
  operator+(const MathVector<T>& vec1, const MathVector<T>& vec2);

  template <typename Scalar>
  friend MathVector<T>
  operator*(const MathVector<T>& vec, Scalar scal) noexcept;

  template <typename Scalar>
  friend MathVector<T>
  operator*(Scalar scal, const MathVector<T>& vec) noexcept;

  friend bool
  operator==(const MathVector<T>& vec1, const MathVector<T> vec2) noexcept;

  friend bool
  operator!=(const MathVector<T>& vec1, const MathVector<T> vec2) noexcept;

  friend bool
  operator<=(const MathVector<T>& vec1, const MathVector<T> vec2) noexcept;

  friend bool
  operator<(const MathVector<T>& vec1, const MathVector<T> vec2) noexcept;

  friend bool
  operator>=(const MathVector<T>& vec1, const MathVector<T> vec2) noexcept;

  friend bool
  operator>(const MathVector<T>& vec1, const MathVector<T> vec2) noexcept;

 private:
  std::vector<T> data_;
};

template <typename T>
MathVector<T> operator+(const MathVector<T>& vec1, const MathVector<T>& vec2);

template <typename T, typename Scalar>
MathVector<T> operator*(const MathVector<T> vec, Scalar scal);

template <typename T, typename Scalar>
MathVector<T> operator*(Scalar scal, const MathVector<T>& vec);

template <typename T>
bool operator==(const MathVector<T>& vec1, const MathVector<T>& vec2) noexcept;

template <typename T>
bool operator!=(const MathVector<T>& vec1, const MathVector<T>& vec2) noexcept;

template <typename T>
bool operator<=(const MathVector<T>& vec1, const MathVector<T>& vec2) noexcept;

template <typename T>
bool operator<(const MathVector<T>& vec1, const MathVector<T>& vec2) noexcept;

template <typename T>
bool operator>=(const MathVector<T>& vec1, const MathVector<T>& vec2) noexcept;

template <typename T>
bool operator>(const MathVector<T>& vec1, const MathVector<T>& vec2) noexcept;

} // nathiss

#endif // MATH_VECTOR_H_
