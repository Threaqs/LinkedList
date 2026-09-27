#pragma once

#include <cstddef>
#include <ostream>

class LinkedList {
private:
    struct Node {
        int value;
        Node* next;
    };

    Node* head_ = nullptr;
    Node* tail_ = nullptr;
    std::size_t size_ = 0;

public:
    LinkedList() = default;

    ~LinkedList() { clear(); }

    // Each list owns its nodes. Prevent accidental shallow copies.
    LinkedList(const LinkedList&) = delete;
    LinkedList& operator=(const LinkedList&) = delete;

    void push_front(int value) {
        head_ = new Node{value, head_};
        if (tail_ == nullptr) {
            tail_ = head_;
        }
        ++size_;
    }

    void push_back(int value) {
        Node* node = new Node{value, nullptr};
        if (tail_ != nullptr) {
            tail_->next = node;
        } else {
            head_ = node;
        }
        tail_ = node;
        ++size_;
    }

    // Remove the first matching value; return false if it is absent.
    bool remove(int value) {
        Node* previous = nullptr;
        Node* current = head_;

        while (current != nullptr && current->value != value) {
            previous = current;
            current = current->next;
        }
        if (current == nullptr) {
            return false;
        }

        if (previous != nullptr) {
            previous->next = current->next;
        } else {
            head_ = current->next;
        }
        if (current == tail_) {
            tail_ = previous;
        }
        delete current;
        --size_;
        return true;
    }

    bool contains(int value) const {
        for (const Node* node = head_; node != nullptr; node = node->next) {
            if (node->value == value) {
                return true;
            }
        }
        return false;
    }

    std::size_t size() const { return size_; }
    bool empty() const { return head_ == nullptr; }

    void clear() {
        while (head_ != nullptr) {
            Node* next = head_->next;
            delete head_;
            head_ = next;
        }
        tail_ = nullptr;
        size_ = 0;
    }

    void print(std::ostream& out) const {
        for (const Node* node = head_; node != nullptr; node = node->next) {
            out << node->value << " -> ";
        }
        out << "nullptr\n";
    }
};
