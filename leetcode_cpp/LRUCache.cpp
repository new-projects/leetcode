/*
 * LRU Cache
 *
 * Design and implement a data structure for Least Recently Used (LRU) cache. It
 * should support the following operations: get and set.
 *
 * get(key) - Get the value (will always be positive) of the key if the key
 * exists in the cache, otherwise return -1.
 * set(key, value) - Set or insert the value if the key is not already present.
 * When the cache reached its capacity, it should invalidate the least recently
 * used item before inserting a new item.
 */
class LRUCache {
public:
  LRUCache(int capacity)
      : head_(nullptr), tail_(nullptr), capacity_(capacity) {}

  int get(int key) {
    ListNode *node = getHelper(key);
    return !node ? -1 : node->val;
  }

  void set(int key, int value) {
    ListNode *node = getHelper(key);
    if (node) {
      node->val = value;
      return;
    }
    if (h_.size() == capacity_) {
      ListNode *d = tail_;
      h_.erase(d->key);
      tail_ = tail_->prev;
      if (!tail_) {
        head_ = nullptr;
      } else {
        tail_->next = nullptr;
      }
      delete d;
    }
    ListNode *newNode = new ListNode(key, value);
    h_[key] = newNode;
    if (!head_) {
      head_ = tail_ = newNode;
    } else {
      newNode->next = head_;
      head_->prev = newNode;
      head_ = newNode;
    }
  }

private:
  struct ListNode {
    int key, val;
    ListNode *next;
    ListNode *prev;
    ListNode(int k, int v) : key(k), val(v), next(nullptr), prev(nullptr) {}
  };

  ListNode *getHelper(int key) {
    if (!h_.count(key)) {
      return nullptr;
    }
    ListNode *node = h_[key];
    if (head_ != node) {
      node->prev->next = node->next;
      if (node->next) {
        node->next->prev = node->prev;
      } else {
        tail_ = node->prev;
      }
      node->next = head_;
      head_->prev = node;
      head_ = node;
    }
    return head_;
  }

  ListNode *head_, *tail_;
  unordered_map<int, ListNode *> h_;
  int capacity_;
};
