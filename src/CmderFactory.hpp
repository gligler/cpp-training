#pragma once

#include <functional>
#include <list>
#include <string>
#include <unordered_map>

#include "Command.hpp"
#include "VehicleType.hpp"

namespace adas
{
using Cmder = std::function<void(PoseHandler& poseHandler)>;
using CmderList = std::list<Cmder>;

class CmderFactory final
{
public:
    CmderFactory(void)  = default;
    ~CmderFactory(void)  = default;

    CmderFactory(const CmderFactory&)  = delete;
    CmderFactory& operator=(const CmderFactory&)  = delete;

public:
    // 根据车辆类型获取命令列表
    CmderList GetCmders(const std::string& commands, VehicleType vehicleType = VehicleType::NormalCar) const;

private:
    // 普通车命令映射表（放在最前面，作为默认）
    const std::unordered_map<char, Cmder> normalCarMap{
        {'M', NormalMoveCommand()},
        {'L', NormalTurnLeftCommand()},
        {'R', NormalTurnRightCommand()},
        {'F', FastCommand()},
        {'B', ReverseCommand()}};

    // 跑车命令映射表
    const std::unordered_map<char, Cmder> sportsCarMap{
        {'M', MoveCommand()},
        {'L', TurnLeftCommand()},
        {'R', TurnRightCommand()},
        {'F', FastCommand()},
        {'B', ReverseCommand()}};

    // 公交车命令映射表
    const std::unordered_map<char, Cmder> busMap{
        {'M', BusMoveCommand()},
        {'L', BusTurnLeftCommand()},
        {'R', BusTurnRightCommand()},
        {'F', FastCommand()},
        {'B', ReverseCommand()}};

    // 根据车辆类型选择正确的命令映射表
    const std::unordered_map<char, Cmder>& GetMapForVehicleType(VehicleType vehicleType) const
    {
        switch (vehicleType) {
        case VehicleType::NormalCar:
            return normalCarMap;
        case VehicleType::SportsCar:
            return sportsCarMap;
        case VehicleType::Bus:
            return busMap;
        default:
            return normalCarMap;  // 默认返回普通车
        }
    }
};

}  // namespace adas