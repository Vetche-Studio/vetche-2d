#pragma once 

#include <memory>
#include <vector>

#include "bd/memory/smartptr.h"
#include "modules.h"
#include "bd/layer/layerstack.h"

namespace bd {
    struct Core : LayerStack {
        Core() = default;

        template<typename T>
        void CreateModule() {
            auto mod_ptr = std::make_shared<T>();
            Modules.push_back(mod_ptr);
        }

        /// @brief Find a module matching the given type and get its shared pointer.
        template<typename T>
        SharedPtr<T> GetModule() {
            SharedPtr<T> out_ptr;
            for (auto& shared_mod_ptr : Modules) {
                auto attempted_cast_ptr = std::dynamic_pointer_cast<T>(shared_mod_ptr);
                if (attempted_cast_ptr != nullptr) {
                    attempted_cast_ptr;
                    return attempted_cast_ptr;
                }
            }
            return nullptr;
        }

        /// @brief Invokes the Init method of all modules.
        void Init();

        void Run();

        /// @brief Collection of shared pointers referring to the module instances. 
        std::vector<SharedPtr<bd::modules::IModule>> Modules;
    };
}