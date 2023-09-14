#include <{{ moduleName }}.hpp>
#include <DataModuleInfo.hpp>

namespace SolarGators {
namespace DataModules {
namespace {
  static constexpr uint32_t SIZE = 3;
}

{{ moduleName }}::{{ moduleName }}():
        DataModule(SolarGators::DataModuleInfo::FRONT_LIGHTS_ID, 0, SIZE),
        {% for attribute in attributes %}
          {{ attribute["name"] }}({{ attribute["default"] }})
        {% endfor %}
{ }

{{ moduleName }}::~{{ moduleName }}()
{ }

{% for attribute in attributes %}
  {{ attribute["type"] }} {{ moduleName }}::Get{{ attribute["name"] }}Val() const
  {
    return {{ attribute["name"] }};
  }
{% endfor %}

void {{ moduleName }}::ToByteArray(uint8_t* buff) const
{
  buff[0] = static_cast<uint8_t>(throttle_);
  buff[1] = static_cast<uint8_t>(throttle_ >> 8);
  buff[2] = static_cast<uint8_t>(breaks_);
}
void {{ moduleName }}::FromByteArray(uint8_t* buff)
{
  throttle_ = static_cast<uint16_t>(buff[1]) << 8 | buff[0];
  breaks_ = static_cast<bool>(buff[2] & 0x1);
}

#ifdef IS_TELEMETRY
void {{ moduleName }}::PostTelemetry(PythonScripts* scripts) {

}
#endif

} /* namespace DataModules */
} /* namespace SolarGators */
