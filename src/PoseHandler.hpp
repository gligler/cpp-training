#pragma once
#include "Executor.hpp"
#include "VehicleType.hpp"

namespace adas
{
class PoseHandler final
{
public:
    PoseHandler(const Pose& pose, VehicleType type = VehicleType::NormalCar) noexcept;
    PoseHandler(const PoseHandler&) = delete;
    PoseHandler& operator=(const PoseHandler&) = delete;

public:
    void Forward(void) noexcept;
    void Backward(void) noexcept;
    void TurnLeft(void) noexcept;
    void TurnRight(void) noexcept;

    void Fast(void) noexcept;
    bool IsFast(void) const noexcept;
    void Reverse(void) noexcept;
    bool IsReverse(void) const noexcept;

    // 新增：车辆特有移动方法
    void MoveSportsCar(void) noexcept;       // 跑车特有移动
    void MoveBus(void) noexcept;             // 公交车特有移动
    void TurnLeftSportsCar(void) noexcept;   // 跑车特有左转
    void TurnLeftBus(void) noexcept;         // 公交车特有左转
    void TurnRightSportsCar(void) noexcept;  // 跑车特有右转
    void TurnRightBus(void) noexcept;        // 公交车特有右转

    Pose Query(void) const noexcept;

    VehicleType GetVehicleType(void) const noexcept;  // 新增：获取车辆类型

private:
    Pose pose;
    bool fast{false};
    bool reverse{false};
    VehicleType vehicleType;  // 车辆类型
};
}  // namespace adas