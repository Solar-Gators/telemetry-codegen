#include <FrontLights.hpp>
#include <DataModuleInfo.hpp>

namespace SolarGators {
namespace DataModules {
namespace {
  static constexpr uint32_t SIZE = 3;
}

FrontLights::FrontLights():
        DataModule(SolarGators::DataModuleInfo::FRONT_LIGHTS_ID, 0, SIZE),
        
          throttle(0)
        
{ }

FrontLights::~FrontLights()
{ }


uint_16_t FrontLights::GetthrottleVal() const
{
  return throttle;
}


void FrontLights::ToByteArray(uint8_t* buff) const
{
  
    
      buff[0] = static_cast<uint8_t>(throttle << 0);
    
      buff[1] = static_cast<uint8_t>(throttle << 1);
    
  
}
void FrontLights::FromByteArray(uint8_t* buff)
{
  
    throttle_ = static_cast<uint16_t>(buff[1]) << 8 | buff[0];
  
}

#ifdef IS_TELEMETRY
void FrontLights::PostTelemetry(PythonScripts* scripts) {

}
#endif

} /* namespace DataModules */
} /* namespace SolarGators */