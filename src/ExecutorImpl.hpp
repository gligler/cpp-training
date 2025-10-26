#pragma once
#include "Executor.hpp"

namespace adas
{

class ExecutorImpl final : public Executor
{
public:
    explicit ExecutorImpl(const Pose& pose) noexcept;
    ~ExecutorImpl() noexcept = default;

    ExecutorImpl(const ExecutorImpl&) = delete;
    ExecutorImpl& operator=(const ExecutorImpl&) = delete;

public:
    void Execute(const std::string& command) noexcept override;
    Pose Query(void) const noexcept override;

private:
    Pose pose;

    // 这些是真正的实现 - 必须保留！
private:
    void Move(void) noexcept;  // 实际前进的代码
    void TurnLeft(void) noexcept;  // 实际左转的代码
    void TurnRight(void) noexcept;  // 实际右转的代码

private:
    // 命令类调用上面的方法
    class MoveCommand final
    {
    public:
        void DoOperate(ExecutorImpl& executor) const noexcept
        {
            executor.Move();  // ← 这里调用的是上面 实际前进的代码
        }
    };

    class TurnLeftCommand final
    {
    public:
        void DoOperate(ExecutorImpl& executor) const noexcept
        {
            executor.TurnLeft();  // ← 这里调用的是上面 实际左转的代码
        }
    };  

    class TurnRightCommand final
    {
    public:
        void DoOperate(ExecutorImpl& executor) const noexcept
        {
            executor.TurnRight();  // ← 这里调用的是上面 实际右转的代码
        }
    };  
};



}  // namespace adas