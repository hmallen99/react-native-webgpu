#pragma once

#include <memory>
#include <string>

#include "webgpu/webgpu_cpp.h"

#include "Logger.h"
#include "RNFJSIConverter.h"
#include <RNFHybridObject.h>

namespace jsi = facebook::jsi;
namespace m = margelo;

namespace rnwgpu {

class GPUSamplerDescriptor {
public:
  wgpu::SamplerDescriptor *getInstance() { return &_instance; }

  wgpu::SamplerDescriptor _instance;

  std::string label;
};
} // namespace rnwgpu

namespace margelo {

template <> struct JSIConverter<std::shared_ptr<rnwgpu::GPUSamplerDescriptor>> {
  static std::shared_ptr<rnwgpu::GPUSamplerDescriptor>
  fromJSI(jsi::Runtime &runtime, const jsi::Value &arg, bool outOfBounds) {
    auto result = std::make_unique<rnwgpu::GPUSamplerDescriptor>();
    if (!outOfBounds && arg.isObject()) {
      auto value = arg.getObject(runtime);
      if (value.hasProperty(runtime, "addressModeU")) {
        auto addressModeU = value.getProperty(runtime, "addressModeU");

        if (addressModeU.isString()) {
          auto str = addressModeU.asString(runtime).utf8(runtime);
          wgpu::AddressMode enumValue;
          m::EnumMapper::convertJSUnionToEnum(str, &enumValue);
          result->_instance.addressModeU = enumValue;
        }
      }
      if (value.hasProperty(runtime, "addressModeV")) {
        auto addressModeV = value.getProperty(runtime, "addressModeV");

        if (addressModeV.isString()) {
          auto str = addressModeV.asString(runtime).utf8(runtime);
          wgpu::AddressMode enumValue;
          m::EnumMapper::convertJSUnionToEnum(str, &enumValue);
          result->_instance.addressModeV = enumValue;
        }
      }
      if (value.hasProperty(runtime, "addressModeW")) {
        auto addressModeW = value.getProperty(runtime, "addressModeW");

        if (addressModeW.isString()) {
          auto str = addressModeW.asString(runtime).utf8(runtime);
          wgpu::AddressMode enumValue;
          m::EnumMapper::convertJSUnionToEnum(str, &enumValue);
          result->_instance.addressModeW = enumValue;
        }
      }
      if (value.hasProperty(runtime, "magFilter")) {
        auto magFilter = value.getProperty(runtime, "magFilter");

        if (magFilter.isString()) {
          auto str = magFilter.asString(runtime).utf8(runtime);
          wgpu::FilterMode enumValue;
          m::EnumMapper::convertJSUnionToEnum(str, &enumValue);
          result->_instance.magFilter = enumValue;
        }
      }
      if (value.hasProperty(runtime, "minFilter")) {
        auto minFilter = value.getProperty(runtime, "minFilter");

        if (minFilter.isString()) {
          auto str = minFilter.asString(runtime).utf8(runtime);
          wgpu::FilterMode enumValue;
          m::EnumMapper::convertJSUnionToEnum(str, &enumValue);
          result->_instance.minFilter = enumValue;
        }
      }
      if (value.hasProperty(runtime, "mipmapFilter")) {
        auto mipmapFilter = value.getProperty(runtime, "mipmapFilter");

        if (mipmapFilter.isString()) {
          auto str = mipmapFilter.asString(runtime).utf8(runtime);
          wgpu::MipmapFilterMode enumValue;
          m::EnumMapper::convertJSUnionToEnum(str, &enumValue);
          result->_instance.mipmapFilter = enumValue;
        }
      }
      if (value.hasProperty(runtime, "lodMinClamp")) {
        auto lodMinClamp = value.getProperty(runtime, "lodMinClamp");

        if (lodMinClamp.isNumber()) {
          result->_instance.lodMinClamp = lodMinClamp.getNumber();
        }
      }
      if (value.hasProperty(runtime, "lodMaxClamp")) {
        auto lodMaxClamp = value.getProperty(runtime, "lodMaxClamp");

        if (lodMaxClamp.isNumber()) {
          result->_instance.lodMaxClamp = lodMaxClamp.getNumber();
        }
      }
      if (value.hasProperty(runtime, "compare")) {
        auto compare = value.getProperty(runtime, "compare");

        if (compare.isString()) {
          auto str = compare.asString(runtime).utf8(runtime);
          wgpu::CompareFunction enumValue;
          m::EnumMapper::convertJSUnionToEnum(str, &enumValue);
          result->_instance.compare = enumValue;
        }
      }
      if (value.hasProperty(runtime, "maxAnisotropy")) {
        auto maxAnisotropy = value.getProperty(runtime, "maxAnisotropy");

        if (maxAnisotropy.isNumber()) {
          result->_instance.maxAnisotropy = maxAnisotropy.getNumber();
        }
      }
      if (value.hasProperty(runtime, "label")) {
        auto label = value.getProperty(runtime, "label");

        if (label.isString()) {
          auto str = label.asString(runtime).utf8(runtime);
          result->label = str;
          result->_instance.label = result->label.c_str();
        }
      }
    }

    return result;
  }
  static jsi::Value toJSI(jsi::Runtime &runtime,
                          std::shared_ptr<rnwgpu::GPUSamplerDescriptor> arg) {
    // No conversions here
    return jsi::Value::null();
  }
};
} // namespace margelo
