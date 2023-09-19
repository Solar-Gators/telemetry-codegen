/*
 * DataModuleInfo.hpp
 *
 *  THIS IS AUTO GENERATED. DO NOT EDIT
 */

#ifndef SOLARGATORSBSP_DATAMODULES_INC_DATAMODULEINFO_HPP_
#define SOLARGATORSBSP_DATAMODULES_INC_DATAMODULEINFO_HPP_


namespace SolarGators::DataModuleInfo
{
// ---- Addresses ---- //

{% for message in canMessages %}
static constexpr uint32_t {{ message["name"] }}_ID = {{ message["id"] }};
{% endfor %}
}


#endif /* SOLARGATORSBSP_DATAMODULES_INC_DATAMODULEINFO_HPP_ */
