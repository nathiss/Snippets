#include "math_vector.h"

namespace nathiss {

template <typename T>
MathVector<T>::MathVector(size_type s)
    : data_(s) {}

template <typename T>
MathVector<T>::MathVector(size_type s, const T& value)
    : data_(s, value) {}

template <typename T>
MathVector<T>::MathVector(const MathVector& fac)
    : data_(fac.data_) {}

template <typename T>
MathVector<T>::MathVector(MathVector&& fac)
    : data_(std::move(fac.data_)) {}

template <typename T>
MathVector<T>& MathVector<T>::operator=(const MathVector& fac) {
  this->data_ = fac.data_;
  this->size_ = fac.size_;
  return *this;
}

template <typename T>
MathVector<T>& MathVector<T>::operator=(MathVector&& fac) {
  this->data_ = std::move(fac.data_);
  this->size_ = std::move(fac.size_);
  return *this;
}

template <typename T>
typename MathVector<T>::reference MathVector<T>::at(size_type pos) {
  return this->data_.at(pos);
}

template <typename T>
typename MathVector<T>::const_reference MathVector<T>::at(size_type pos) const {
  return this->data_.at(pos);
}

template <typename T>
typename MathVector<T>::reference MathVector<T>::operator[](size_type pos) {
  return this->at(pos);
}

template <typename T>
typename MathVector<T>::const_reference
MathVector<T>::operator[](size_type pos) const {
  return this->at(pos);
}

template <typename T>
typename MathVector<T>::reference MathVector<T>::front() {
  return *this->begin();
}

template <typename T>
typename MathVector<T>::const_reference MathVector<T>::front() const {
  return *this->begin();
}

template <typename T>
typename MathVector<T>::reference MathVector<T>::back() {
  return *this->end();
}

template <typename T>
typename MathVector<T>::const_reference MathVector<T>::back() const {
  return *this->end();
}

template <typename T>
T* MathVector<T>::data() noexcept {
  return this->data_.data();
}

template <typename T>
const T* MathVector<T>::data() const noexcept {
  return this->data_.data();
}

template <typename T>
typename MathVector<T>::iterator MathVector<T>::begin() noexcept {
  return this->data_.begin();
}

template <typename T>
typename MathVector<T>::const_iterator MathVector<T>::begin() const noexcept {
  return this->data_.begin();
}

template <typename T>
typename MathVector<T>::const_iterator MathVector<T>::cbegin() const noexcept {
  return this->data_.begin();
}

template <typename T>
typename MathVector<T>::iterator MathVector<T>::end() noexcept {
  return this->data_.end();
}

template <typename T>
typename MathVector<T>::const_iterator MathVector<T>::end() const noexcept {
  return this->data_.end();
}

template <typename T>
typename MathVector<T>::const_iterator MathVector<T>::cend() const noexcept {
  return this->data_.end();
}

template <typename T>
bool MathVector<T>::empty() const noexcept {
  return this->begin() == this->end();
}

template <typename T>
typename MathVector<T>::size_type MathVector<T>::size() const noexcept {
  return this->data_.size();
}

template <typename T>
void MathVector<T>::clear() noexcept {
  this->data_.clear();
}

template <typename T>
typename MathVector<T>::iterator
MathVector<T>::insert(const_iterator pos, const T& value) {
  return this->data_.insert(pos, value);
}

template <typename T>
typename MathVector<T>::iterator
MathVector<T>::insert(const_iterator pos, T&& value) {
  return this->data_.insert(pos, std::move(value));
}

template <typename T>
typename MathVector<T>::iterator MathVector<T>::erase(const_iterator pos) {
  return this->data_.erase(pos);
}

template <typename T>
typename MathVector<T>::iterator
MathVector<T>::erase(const_iterator first, const_iterator last) {
  return this->data_.erase(first, last);
}

template <typename T>
void MathVector<T>::resize(size_type count) {
  this->data_.resize(count);
}

template <typename T>
void MathVector<T>::resize(size_type count, const T& value) {
  this->data_.resize(count, value);
}

template <typename T>
void MathVector<T>::swap(MathVector<T>& vec) noexcept {
  this->data_.swap(vec.data_);
}

template <typename T>
MathVector<T>& MathVector<T>::operator+=(const MathVector<T>& vec) {
  if(this->size() != vec.size())
    throw;
  for(size_type i = 0; i < this->size(); ++i)
    this->at(i) += vec.at(i);
  return *this;
}

template <typename T>
MathVector<T>& MathVector<T>::operator+=(MathVector&& vec) {
  return *this += vec;
}

template <typename T>
template <typename Scalar>
MathVector<T>& MathVector<T>::operator*=(Scalar scal) {
  for(auto& elm : this->data_)
    elm *= scal;
  return *this;
}

template <typename T>
MathVector<T> operator+(const MathVector<T>& vec1, const MathVector<T>& vec2) {
  if (vec1.size() != vec2.size())
    throw;
  MathVector<T> tmp{vec1.size()};
  for(decltype(vec1.size()) i = 0; i < vec1.size(); ++i)
    tmp[i] = vec1[i] + vec2[i];
  return tmp;
}

template <typename T, typename Scalar>
MathVector<T> operator*(const MathVector<T> vec, Scalar scal) {
  MathVector<T> tmp{vec.size()};
  for(decltype(vec.size()) i = 0; i < vec.size(); ++i)
    tmp[i] = vec[i] = scal;
  return tmp;
}

template <typename T, typename Scalar>
MathVector<T> operator*(Scalar scal, const MathVector<T>& vec) {
  return vec * scal;
}

template <typename T>
bool operator==(const MathVector<T>& vec1, const MathVector<T>& vec2) noexcept {
  return vec1.data_ == vec2.data_;
}

template <typename T>
bool operator!=(const MathVector<T>& vec1, const MathVector<T>& vec2) noexcept {
  return vec1.data_ != vec2.data_;
}

template <typename T>
bool operator<=(const MathVector<T>& vec1, const MathVector<T>& vec2) noexcept {
  return vec1.data_ <= vec2.data_;
}

template <typename T>
bool operator<(const MathVector<T>& vec1, const MathVector<T>& vec2) noexcept {
  return vec1.data_ < vec2.data_;
}

template <typename T>
bool operator>=(const MathVector<T>& vec1, const MathVector<T>& vec2) noexcept {
  return vec1.data_ >= vec2.data_;
}

template <typename T>
bool operator>(const MathVector<T>& vec1, const MathVector<T>& vec2) noexcept {
  return vec1.data_ > vec2.data_;
}

} // namespace nathiss
