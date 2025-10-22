#include "ExecutorImpl.hpp"

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
    for (char command : commands) {
        if (command == 'M') {
            switch (pose.heading) {
            case 'E':
                pose.x += 1;
                break;
            case 'W':
                pose.x -= 1;
                break;
            case 'N':
                pose.y += 1;
                break;
            case 'S':
                pose.y -= 1;
                break;
            }
        }
    }
}

Pose ExecutorImpl::Query() const noexcept
{
    return pose;
}
}  // namespace adas