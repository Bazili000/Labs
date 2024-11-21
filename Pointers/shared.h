#pragma once

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
        SharedPtr() : ptr(nullptr), count(new size_t(0)) {}

        explicit SharedPtr(T* ptr) : ptr(ptr), count(new size_t(1)) {}

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
            return *ptr;
        }

        const T& operator*() const {
            return *ptr;
        }

        T* operator->() {
            return ptr;
        }

        const T* operator->() const {
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

        void reset(T* ptr = nullptr) {
            release();
            this -> ptr = ptr;
            if (ptr) {
                this -> count = new size_t(1);
            } else {
                this -> count = new size_t(0);
            }
        }

        size_t countsSize() {
            return *count;
        }
};