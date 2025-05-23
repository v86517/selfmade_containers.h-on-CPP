#ifndef S21_SET_H_
#define S21_SET_H_

#include <algorithm>
#include <initializer_list>
#include <utility>

namespace s21 {

template <typename Key> class set {
public:
  class SetIterator;
  class ConstSetIterator;

  using key = const Key;
  using iter = typename set<Key>::SetIterator;
  using c_iter = typename set<Key>::ConstSetIterator;

  set() noexcept;
  set(const set &other);
  set(std::initializer_list<key> init);
  set(set &&other);
  ~set() noexcept;

  set &operator=(const set &other);
  set &operator=(set &&other) noexcept;
  set &operator=(std::initializer_list<key> ilist);

  iter begin() noexcept;
  iter end() noexcept;
  c_iter cbegin() const noexcept;
  c_iter cend() const noexcept;

  bool empty() const noexcept;
  size_t size() const noexcept;
  size_t max_size() const noexcept;

  void clear() noexcept;
  std::pair<iter, bool> insert(const key &value);
  std::pair<iter, bool> insert(key &&value);
  iter erase(iter pos);
  iter erase(c_iter pos);
  iter erase(c_iter first, c_iter last);
  size_t erase(const Key &key);
  void swap(set &other) noexcept;
  void merge(set &source);

  size_t count(const Key &key) const;
  iter find(const Key &key);
  c_iter find(const Key &key) const;
  bool contains(const Key &key) const;

  template <typename... Args>
  std::vector<std::pair<iter, bool>> insert_many(Args &&...args);

private:
  struct BaseNode;
  struct Node;

  BaseNode *fake_node;
  BaseNode *leftmost;
  size_t size_;

  int get_height(BaseNode *node);
  int get_balance_factor(BaseNode *node);
  void delete_node(Node *node);
  BaseNode *rebalance_node(BaseNode *node);
  BaseNode *min_value_node(BaseNode *node);
  BaseNode *rotate_right(BaseNode *node);
  BaseNode *rotate_left(BaseNode *node);
  iter erase_private(iter pos, bool del);
  std::pair<BaseNode *, bool> insert_private(BaseNode *node, const key &value);
  std::pair<BaseNode *, bool> insert_private(BaseNode *node, key &&value);
  BaseNode *merge_insert(BaseNode *node, BaseNode *src, set &source);
};

} // namespace s21

#include "../iterators/s21_set_iterators.h"
#include "../iterators/s21_set_iterators.tpp"
#include "s21_set.tpp"

#endif // S21_SET_H_
