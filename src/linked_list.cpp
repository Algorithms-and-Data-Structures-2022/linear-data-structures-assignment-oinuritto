#include "assignment/linked_list.hpp"

namespace assignment {

  LinkedList::~LinkedList() {

    // эквивалентно очистке списка
    LinkedList::Clear();
  }

  void LinkedList::Add(int value) {
    // Write your code here ...
    Node* node = new Node(value, nullptr);
    if (size_ == 0) {
      front_ = node;
      back_ = node;
    } else {
      back_->next = node;
      back_ = node;
    }
    size_++;
  }

  bool LinkedList::Insert(int index, int value) {
    // Write your code here ...
    if (index < 0 || index > size_) {
      return false;
    } else {
      Node* node = new Node(value, nullptr);
      if (size_ == 0 && index == 0) {
        front_ = node;
        back_ = node;
      } else if (index == 0) {
        node->next = front_;
        front_ = node;
      } else if (index == size_) {
        back_->next = node;
        back_ = node;
      } else {
        node->next = FindNode(index-1)->next;
        FindNode(index-1)->next = node;
      }
      size_++;
      return true;

    }
  }

  bool LinkedList::Set(int index, int new_value) {
    if (index >= 0 && index < size_) {
      FindNode(index)->value = new_value;
      return true;
    }
    return false;
  }

  std::optional<int> LinkedList::Remove(int index) {
    // Write your code here ...
    if (index < 0 || index >= size_) {
      return std::nullopt;
    } else {
      int returnValue;
      if (index == 0) {
        returnValue = front_->value;
        front_ = front_->next;
      } else if (index == size_-1) {
        returnValue = back_->value;
        back_ = FindNode(size_-2);
        back_->next = nullptr;
      } else {
        returnValue = FindNode(index)->value;
        FindNode(index-1)->next = FindNode(index+1);
      }
      size_--;
      return returnValue;
    }
  }

  void LinkedList::Clear() {
    // Write your code here ...
    front_ = nullptr;
    back_ = nullptr;
    size_ = 0;
  }

  std::optional<int> LinkedList::Get(int index) const {
    // Write your code here ...
    if (index >= 0 && index < size_) {
      Node* node = front_;
      for (int i = 0; i < index; i++) {
        node = node->next;
      }
      return node->value;
    }
    return std::nullopt;
  }

  std::optional<int> LinkedList::IndexOf(int value) const {
    // Write your code here ...
    Node* node = front_;
    for (int i = 0; i < size_; i++) {
      if (node->value == value) {
        return i;
      }
      node = node->next;
    }
    return std::nullopt;
  }

  bool LinkedList::Contains(int value) const {
    Node* node = front_;
    for (int i = 0; i < size_; i++) {
      if (node->value == value) {
        return true;
      }
      node = node->next;
    }
    return false;
  }

  bool LinkedList::IsEmpty() const {
    return size_ == 0;
  }

  int LinkedList::size() const {
    return size_;
  }

  std::optional<int> LinkedList::front() const {
    // Write your code here ...
    if (front_ != nullptr) {
      return front_->value;
    }
    return std::nullopt;
  }

  std::optional<int> LinkedList::back() const {
    // Write your code here ...
    if (back_ != nullptr) {
      return back_->value;
    }
    return std::nullopt;
  }

  Node* LinkedList::FindNode(int index) const {
    // Write your code here ...
    if (index >= 0 && index < size_) {
      Node* node = front_;
      for (int i = 0; i < index; i++) {
        node = node->next;
      }
      return node;
    }
    return nullptr;
  }

  // ДЛЯ ТЕСТИРОВАНИЯ
  LinkedList::LinkedList(const std::vector<int>& values) {

    if (values.empty()) {
      return;
    }

    auto* curr_node = new Node(values.front());
    front_ = curr_node;

    for (int index = 1; index < values.size() - 1; ++index) {
      curr_node->next = new Node(values[index]);
      curr_node = curr_node->next;
    }

    if (values.size() == 1) {
      back_ = front_;
    } else {
      curr_node->next = new Node(values.back());
      back_ = curr_node->next;
    }

    size_ = static_cast<int>(values.size());
  }

  std::vector<int> LinkedList::toVector() const {

    if (front_ == nullptr || size_ == 0) {
      return {};
    }

    std::vector<int> array;
    array.reserve(size_);

    for (auto* node = front_; node != nullptr; node = node->next) {
      array.push_back(node->value);
    }

    return array;
  }

}  // namespace assignment