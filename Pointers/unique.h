#pragma once

template<typename T>
class UnqPtr {
    private: 
        T* ptr;

    public:
        UnqPtr(T* ptr) : ptr(ptr) {}

        // same as move() in unique_ptr
        UnqPtr(UnqPtr&& otherPtr) {
            ptr = otherPtr.ptr;
            otherPtr.ptr = nullptr;
        }

        // copy ban
        UnqPtr(const UnqPtr& otherPtr) = delete;
        UnqPtr& operator=(const UnqPtr& otherPtr) = delete;

        ~UnqPtr() {delete ptr;}

        T* operator->() {
            return ptr;
        }

        const T* operator->() const {
            return ptr;
        }

        T& operator*() {
            return *ptr;
        }

        const T& operator*() const {
            return *ptr;
        }

        void swap(T*& otherPtr) {
            T* tmpPtr = ptr;
            ptr = otherPtr;
            otherPtr = tmpPtr;
        }

        void reset(T* newPtr = nullptr) {
            if (ptr) {
                delete ptr;
                ptr = nullptr;
            }
            ptr = newPtr;
        }

        T* release() {
            T* tmpPtr = ptr;
            ptr = nullptr;
            return tmpPtr;
        }
        
        T* get() {
            return ptr;
        }

        const T* get() const {
            return ptr;
        }

};