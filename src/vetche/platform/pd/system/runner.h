#pragma once

#include "vetche/core/modules.h"
#include "vetche/def/types.h"

namespace vtc::pd {
    struct PDRunner : vtc::modules::IRunner {
        virtual void Init(Core& core) override;
        virtual bool IsRunning() override;
        virtual void SetPaused(bool flag) override;
        virtual vtc::Float32 GetDelta() override;
    };
}