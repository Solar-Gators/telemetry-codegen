/*
 * {{ moduleName }}.cpp
 *
 *  THIS IS AUTO GENERATED, DO NOT EDIT.
 */

#include "{{ moduleName }}.hpp"
#include "DataModuleInfo.hpp"
#include <cstring>

namespace SolarGators {
namespace DataModules {
namespace {
  static constexpr uint32_t SIZE = 3;
}

{{ moduleName }}::{{ moduleName }}():
        DataModule(SolarGators::DataModuleInfo::{{ moduleName }}_ID, 0, SIZE),
        {% for attribute in attributes %}
          {{ attribute["name"] }}({{ attribute["default"] }})
          {% if not loop.last %}
              ,
          {% endif %}
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
  size_t index = 0;
  {% for attribute in attributes %}
    memcpy(buff + index, &{{ attribute["name"] }}, sizeof({{ attribute["name"] }}));
    index += sizeof({{ attribute["name"] }});
  {% endfor %}
}

void {{ moduleName }}::FromByteArray(uint8_t* buff)
{
  size_t index = 0;
  {% for attribute in attributes %}
    memcpy(&{{ attribute["name"] }}, buff + index,sizeof({{ attribute["name"] }}));
    index += sizeof({{ attribute["name"] }});
  {% endfor %}
}

#ifdef IS_TELEMETRY
void {{ moduleName }}::PostTelemetry(PythonScripts* scripts) {

}
#endif

} /* namespace DataModules */
} /* namespace SolarGators */
