#include "PoseHandler.hpp"

namespace adas
{
PoseHandler::PoseHandler(const Pose& pose, VehicleType vehicleType) noexcept : pose(pose), vehicleType(vehicleType)
{
}


void PoseHandler::Forward() noexcept
{
    switch (pose.heading) {
    case 'N':
        ++pose.y;
        break;
    case 'W':
        --pose.x;
        break;
    case 'S':
        --pose.y;
        break;
    case 'E':
        ++pose.x;
        break;
    }
}

void PoseHandler::Backward() noexcept
{
    switch (pose.heading) {
    case 'N':
        --pose.y;
        break;
    case 'W':
        ++pose.x;
        break;
    case 'S':
        ++pose.y;
        break;
    case 'E':
        --pose.x;
        break;
    }
}

void PoseHandler::TurnLeft() noexcept
{
    switch (pose.heading) {
    case 'N':
        pose.heading = 'W';
        break;
    case 'W':
        pose.heading = 'S';
        break;
    case 'S':
        pose.heading = 'E';
        break;
    case 'E':
        pose.heading = 'N';
        break;
    }
}

void PoseHandler::TurnRight() noexcept
{
    switch (pose.heading) {
    case 'N':
        pose.heading = 'E';
        break;
    case 'W':
        pose.heading = 'N';
        break;
    case 'S':
        pose.heading = 'W';
        break;
    case 'E':
        pose.heading = 'S';
        break;
    }
}

void PoseHandler::Fast() noexcept
{
    fast = !fast;
}

bool PoseHandler::IsFast() const noexcept
{
    return fast;
}

bool PoseHandler::IsReverse() const noexcept
{
    return reverse;
}

void PoseHandler::Reverse() noexcept
{
    reverse = !reverse;
}



Pose PoseHandler::Query() const noexcept
{
    return pose;
}
VehicleType PoseHandler::GetVehicleType() const noexcept
{
    return vehicleType;
}
}  // namespace adas