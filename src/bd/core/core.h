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
            auto mod_ptr = MakeShared<T>();
            Modules.push_back(mod_ptr);
        }

        /// @brief Mandatory module which keeps track of running the system.
        /// @tparam T Runner type which implements modules::IRunner.
        template<typename T>
        void SetRunner() {
            auto mod_ptr = MakeShared<T>();
            Modules.insert(Modules.begin(), mod_ptr);
            Runner = mod_ptr;
        }

        /// @brief Find a module matching the given type and get its shared pointer.
        template<typename T>
        SharedPtr<T> GetModule() {
            SharedPtr<T> out_ptr;
            for (auto& shared_mod_ptr : Modules) {
                auto attempted_cast_ptr = DynamicCast<T>(shared_mod_ptr);
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

        void Process();

        /// @brief Collection of shared pointers referring to the module instances. 
        std::vector<SharedPtr<bd::modules::IModule>> Modules;
        SharedPtr<modules::IRunner> Runner;
    };
}