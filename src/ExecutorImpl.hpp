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


public:
    void Move(void) noexcept;  // 实际前进的代码
    void TurnLeft(void) noexcept;  // 实际左转的代码
    void TurnRight(void) noexcept;  // 实际右转的代码
    void Fast(void) noexcept;
    bool IsFast(void) const noexcept;

private:
    Pose pose;
    bool fast{false};


    
       
    };  // 尾巴确保为紫色

}  // namespace adas