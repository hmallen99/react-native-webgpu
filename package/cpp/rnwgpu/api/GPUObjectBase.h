#pragma once

#include "webgpu/webgpu_cpp.h"
#include <memory>

namespace jsi = facebook::jsi;

namespace rnwgpu {
class GPUObjectBase {
public:
  wgpu::ObjectBase *getInstance() { return &_instance; }

  wgpu::ObjectBase _instance;
};
} // namespace rnwgpu

namespace margelo {

template <> struct JSIConverter<std::shared_ptr<rnwgpu::GPUObjectBase>> {
  static std::shared_ptr<rnwgpu::GPUObjectBase> fromJSI(jsi::Runtime &runtime,
                                                        const jsi::Value &arg) {
    auto result = std::make_unique<rnwgpu::GPUObjectBase>();
    if (&arg != nullptr && arg.isObject()) {
      auto value = arg.getObject(runtime);
      if (value.hasProperty(runtime, "label")) {
        auto label = value.getProperty(runtime, "label");

        if (label.isUndefined()) {
          throw std::runtime_error("Property GPUObjectBase::label is required");
        }
      }
    }
    return result;
  }
  static jsi::Value toJSI(jsi::Runtime &runtime,
                          std::shared_ptr<rnwgpu::GPUObjectBase> arg) {
    // No conversions here
    return jsi::Value::null();
  }
};
} // namespace margelo
