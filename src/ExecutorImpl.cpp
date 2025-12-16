#include "ExecutorImpl.hpp"
#include "Command.hpp"
#include <memory>   
#include <unordered_map>
#include "CmderFactory.hpp"
#include "Singleton.hpp"

namespace adas
{
Executor* Executor::NewExecutor(const Pose& pose, VehicleType vehicleType) noexcept
{
    return new (std::nothrow) ExecutorImpl(pose, vehicleType);
}

ExecutorImpl::ExecutorImpl(const Pose& pose, VehicleType vehicleType) noexcept : poseHandler(pose, vehicleType)
{
}
void ExecutorImpl::Execute(const std::string& commands) noexcept
{
    VehicleType type = poseHandler.GetVehicleType();

    const auto cmders = Singleton<CmderFactory>::Instance().GetCmders(commands, type);

    std::for_each(cmders.begin(), cmders.end(), [this](const Cmder& cmder) noexcept {
        cmder(poseHandler);  
    });
}

    Pose ExecutorImpl::Query() const noexcept
{
    return poseHandler.Query();
}
 

 
}  // namespace adas黄色括号