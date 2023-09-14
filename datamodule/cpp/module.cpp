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
  {% for attribute in attributes %}
    {%- for byte in range(attribute["bytes"]) %}
      buff[{{ byte }}] = static_cast<uint8_t>({{ attribute["name"] }} >> {{ byte }});
    {% endfor %}
  {% endfor %}
}
void {{ moduleName }}::FromByteArray(uint8_t* buff)
{
  {% for attribute in attributes %}
    // TODO: This one is much harder and prone to error
    throttle_ = static_cast<uint16_t>(buff[1]) << 8 | buff[0];
  {% endfor %}
}

#ifdef IS_TELEMETRY
void {{ moduleName }}::PostTelemetry(PythonScripts* scripts) {

}
#endif

} /* namespace DataModules */
} /* namespace SolarGators */
