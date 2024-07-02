#pragma once

#include "webgpu/webgpu_cpp.h"
#include <memory>

namespace jsi = facebook::jsi;

namespace rnwgpu {
class GPURequestAdapterOptions {
public:
  wgpu::RequestAdapterOptions *getInstance() { return &_instance; }

  wgpu::RequestAdapterOptions _instance;
};
} // namespace rnwgpu

namespace margelo {

template <>
struct JSIConverter<std::shared_ptr<rnwgpu::GPURequestAdapterOptions>> {
  static std::shared_ptr<rnwgpu::GPURequestAdapterOptions>
  fromJSI(jsi::Runtime &runtime, const jsi::Value &arg) {
    auto result = std::make_unique<rnwgpu::GPURequestAdapterOptions>();
    if (&arg != nullptr && arg.isObject()) {
      auto value = arg.getObject(runtime);
      if (value.hasProperty(runtime, "powerPreference")) {
        auto powerPreference = value.getProperty(runtime, "powerPreference");
      }
      if (value.hasProperty(runtime, "forceFallbackAdapter")) {
        auto forceFallbackAdapter =
            value.getProperty(runtime, "forceFallbackAdapter");
        if (value.hasProperty(runtime, "forceFallbackAdapter")) {
          result->_instance.forceFallbackAdapter =
              forceFallbackAdapter.getBool();
        }
      }
    }
    return result;
  }
  static jsi::Value
  toJSI(jsi::Runtime &runtime,
        std::shared_ptr<rnwgpu::GPURequestAdapterOptions> arg) {
    // No conversions here
    return jsi::Value::null();
  }
};
} // namespace margelo
