#include "ExecutorImpl.hpp"
#include <memory>   

namespace adas
{
Executor* Executor::NewExecutor(const Pose& pose) noexcept
{
    return new (std::nothrow) ExecutorImpl(pose);
}

ExecutorImpl::ExecutorImpl(const Pose& pose) noexcept:pose(pose)
{
}

void ExecutorImpl::Execute(const std::string& commands) noexcept
{
    for (const auto cmd : commands)
    {
        if (cmd == 'M') // 前进
        {
           // Move();
           std::unique_ptr<MoveCommand> cmder = std::make_unique<MoveCommand>();
           cmder->DoOperate(*this);
        }
        else if (cmd == 'L')  // 左转
        {
            TurnLeft();
        }

        else if (cmd == 'R')  // 右转
        {
            TurnRight();
        }
    }
 }

 void ExecutorImpl::Move() noexcept
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

 void ExecutorImpl::TurnLeft() noexcept
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

 void ExecutorImpl::TurnRight() noexcept
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
 
Pose ExecutorImpl::Query() const noexcept
{
    return pose;
}
}  // namespace adas