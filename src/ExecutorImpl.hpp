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
    // 抽象基类定义在 private 区域
    class ICommand
    {
    public:
        virtual ~ICommand() = default;
        virtual void DoOperate(ExecutorImpl& executor) const noexcept = 0;
    };

    // 具体命令类也定义在 private 区域，继承自 ICommand
    class MoveCommand final : public ICommand
    {  
    public:
        void DoOperate(ExecutorImpl& executor) const noexcept override
        {
            executor.Move();
        }
    };

    class TurnLeftCommand final : public ICommand
    {
    public:
        void DoOperate(ExecutorImpl& executor) const noexcept override
        {
            executor.TurnLeft();
        }
    };

    class TurnRightCommand final : public ICommand
    {
    public:
        void DoOperate(ExecutorImpl& executor) const noexcept override
        {
            executor.TurnRight();
        }

    };

       
    };  // 尾巴确保为紫色

}  // namespace adas