#pragma once

#include <memory>

namespace bd {
    template<typename T>
    using SharedPtr = std::shared_ptr<T>;

    template<typename T>
    using UniquePtr = std::unique_ptr<T>;

    template<typename T>
    using WeakPtr = std::weak_ptr<T>;
    
    template<typename T, typename ...Args>
    inline SharedPtr<T> MakeShared(Args... args) {
        return std::make_shared<T>(args...);
    }

    template<typename T, typename ...Args>
    inline UniquePtr<T> MakeUnique(Args... args) {
        return std::make_unique<T>(args...);
    }

    template<typename T>
    inline SharedPtr<T> DynamicCast(SharedPtr<T>& ptr) {
        return std::dynamic_pointer_cast<T>(ptr);
    }
}