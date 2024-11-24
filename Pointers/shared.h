#pragma once
#include <stdexcept>

template<typename T>
class SharedPtr {
    private:
        T* ptr;
        size_t* count;

        void release() {
            if (count && --*count == 0) {
                delete ptr;
                delete count;
            }
        }

    public:
        SharedPtr() : ptr(nullptr), count(nullptr) {}

        explicit SharedPtr(T* ptr) : ptr(ptr), count(ptr ? new size_t(1) : nullptr) {}

        SharedPtr(const SharedPtr& otherPtr) : ptr(otherPtr.ptr), count(otherPtr.count) {
            ++*count; 
        }

        // same as move()
        SharedPtr(SharedPtr&& otherPtr) noexcept : ptr(otherPtr.ptr), count(otherPtr.count) {
            otherPtr.ptr = nullptr;
            otherPtr.count = nullptr;
        }

        ~SharedPtr() {
            release();
        }

        T* get() const {
            return ptr;
        }

        T& operator*() {
            if (!ptr) throw std::runtime_error("Empty pointer");
            return *ptr;
        }

        const T& operator*() const {
            if (!ptr) throw std::runtime_error("Empty pointer");
            return *ptr;
        }

        T* operator->() {
            if (!ptr) throw std::runtime_error("Empty pointer");
            return ptr;
        }

        const T* operator->() const {
            if (!ptr) throw std::runtime_error("Empty pointer");
            return ptr;
        }

        // copy
        SharedPtr& operator=(SharedPtr&& other) {
            if (this != &other) {
                release();
                ptr = other.ptr;
                count = other.count;
                other.ptr = nullptr;
                other.count = nullptr;
            }
            return *this;
        }

        // move
        SharedPtr& operator=(const SharedPtr& other) {
            if (this != &other) {
                release();
                ptr = other.ptr;
                count = other.count;
                ++*count;
            }
            return *this;
        }

        void swap(SharedPtr& other) noexcept {
            std::swap(ptr, other.ptr);
            std::swap(count, other.count);
        }

        void reset(T* newPtr = nullptr) {
            release();
            ptr = newPtr;
            count = newPtr ? new size_t(1) : nullptr;
        }

        size_t countsSize() const {
            return count ? *count : 0;
        }
};