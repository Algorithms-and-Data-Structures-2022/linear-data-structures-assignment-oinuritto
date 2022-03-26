#include "assignment/array_stack.hpp"

#include <algorithm>  // copy, fill
#include <stdexcept>  // invalid_argument (НЕЛЬЗЯ ИСПОЛЬЗОВАТЬ)

namespace assignment {

  ArrayStack::ArrayStack(int capacity) {

    // выбрасываем ошибку, если указана неположительная емкость стека
    if (capacity <= 0) {
      throw std::invalid_argument("capacity is not positive");
    }

    // Write your code here ...
    size_ = 0;
    capacity_ = capacity;
    data_ = new int[capacity_];
    std::fill(&data_[0], &data_[capacity_], 0);
  }

  ArrayStack::~ArrayStack() {
    // Write your code here ...
    size_ = 0;
    capacity_ = 0;
    delete[] data_;
    data_ = nullptr;
  }

  void ArrayStack::Push(int value) {
    // Write your code here ...
    if (size_ == capacity_) {
      Resize(capacity_+kCapacityGrowthCoefficient);
    }
    data_[size_] = value;
    size_++;
  }

  bool ArrayStack::Pop() {
    // Write your code here ...
    if (size_ != 0) {
      data_[size_-1] = 0;
      size_--;
      return true;
    }
    return false;
  }

  void ArrayStack::Clear() {
    // Write your code here ...
    size_ = 0;
    delete[] data_;
    data_ = nullptr;
  }

  std::optional<int> ArrayStack::Peek() const {
    // Write your code here ...
    if (size_ != 0) {
      return data_[size_-1];
    }
    return std::nullopt;
  }

  bool ArrayStack::IsEmpty() const {
    // Write your code here ...
    return size_ == 0;
  }

  int ArrayStack::size() const {
    // Write your code here ...
    return size_;
  }

  int ArrayStack::capacity() const {
    // Write your code here ...
    return capacity_;
  }

  bool ArrayStack::Resize(int new_capacity) {
    // Write your code here ...
    if (new_capacity > capacity_) {
      int* new_data = new int[new_capacity];
      std::copy(&data_[0], &data_[size_], new_data);\
      delete[] data_;
      data_ = new_data;
      capacity_ = new_capacity;
      return true;
    }
    return false;
  }

  // ДЛЯ ТЕСТИРОВАНИЯ
  ArrayStack::ArrayStack(const std::vector<int>& values, int capacity) {

    size_ = static_cast<int>(values.size());
    capacity_ = capacity;

    data_ = new int[capacity]{};

    std::copy(values.data(), values.data() + size_, data_);
  }

  std::vector<int> ArrayStack::toVector(std::optional<int> size) const {

    if (capacity_ == 0 || data_ == nullptr) {
      return {};
    }

    if (size.has_value()) {
      return {data_, data_ + size.value()};
    }

    return {data_, data_ + capacity_};
  }

}  // namespace assignment
