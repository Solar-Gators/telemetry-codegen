/*
 * FrontLights.hpp
 *
 *  THIS IS AUTO GENERATED, DO NOT EDIT
 */

#ifndef SOLARGATORSBSP_STM_DATAMODULES_INC_FRONTLIGHTS_HPP_
#define SOLARGATORSBSP_STM_DATAMODULES_INC_FRONTLIGHTS_HPP_

#include "DataModule.hpp"
#define BUFF_SIZE 50

namespace SolarGators {
namespace DataModules {

class {{ moduleName }}: public DataModule {
public:
  {{ moduleName }}();
  ~{{ moduleName }}();
  {% for attribute in attributes %}
  {{ attribute["type"] }} Get{{ attribute["name"] }}Val() const;
  {% endfor %}

  // CAN Functions
  void ToByteArray(uint8_t* buff) const;
  void FromByteArray(uint8_t* buff);
  #ifdef IS_TELEMETRY
  void PostTelemetry(PythonScripts* scripts);
  #endif

protected:
  {% for attribute in attributes %}
  {{ attribute["type"] }} {{ attribute["name"] }};
  {% endfor %}
};

} /* namespace DataModules */
} /* namespace SolarGators */

#endif /* SOLARGATORSBSP_STM_DATAMODULES_INC_FRONTLIGHTS_HPP_ */
