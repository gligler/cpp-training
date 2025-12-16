#include "CmderFactory.hpp"

namespace adas
{
CmderList CmderFactory::GetCmders(const std::string& commands, VehicleType vehicleType) const 
{
    CmderList cmders;

    const auto& cmdMap = GetMapForVehicleType(vehicleType);

    for (const auto cmd : commands) {
        const auto it = cmdMap.find(cmd);
        if (it != cmdMap.end()) {
            cmders.push_back(it->second);
        }
    }

    return cmders;
}

}  // namespace adas