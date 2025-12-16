#pragma once

#include "PoseHandler.hpp"

namespace adas
{
// ================ 普通车命令类 ================
class NormalMoveCommand final
{
public:
    void operator()(PoseHandler& poseHandler) const noexcept
    {
        if (poseHandler.IsReverse()) {
            // 倒车状态
            if (poseHandler.IsFast()) {
                poseHandler.Backward();
                poseHandler.Backward();  // 快速倒车后退2格
            } else {
                poseHandler.Backward();  // 普通倒车后退1格
            }
        } else {
            // 正常状态
            if (poseHandler.IsFast()) {
                poseHandler.Forward();
                poseHandler.Forward();  // 快速前进2格
            } else {
                poseHandler.Forward();  // 普通前进1格
            }
        }
    }
};

class NormalTurnLeftCommand final
{
public:
    void operator()(PoseHandler& poseHandler) const noexcept
    {
        if (poseHandler.IsReverse()) {
            // 倒车状态：右转90度
            if (poseHandler.IsFast()) {
                poseHandler.Backward();
                poseHandler.TurnRight();
                 // 快速倒车：后退1格，右转
            } else {
                poseHandler.TurnRight();  // 普通倒车：右转90度
            }
        } else {
            // 正常状态：左转90度
            if (poseHandler.IsFast()) {
                poseHandler.Forward();
                poseHandler.TurnLeft();
                 // 快速状态：前进1格，左转
            } else {
                poseHandler.TurnLeft();  // 普通状态：左转90度
            }
        }
    }
};

class NormalTurnRightCommand final
{
public:
    void operator()(PoseHandler& poseHandler) const noexcept
    {
        if (poseHandler.IsReverse()) {
            // 倒车状态：左转90度
            if (poseHandler.IsFast()) {
                poseHandler.Backward();
                poseHandler.TurnLeft();
                // 快速倒车：后退1格，左转
            } else {
                poseHandler.TurnLeft();  // 普通倒车：左转90度
            }
        } else {
            // 正常状态：右转90度
            if (poseHandler.IsFast()) {
                poseHandler.Forward();
                poseHandler.TurnRight();
                 // 快速状态：前进1格，右转
            } else {
                poseHandler.TurnRight();  // 普通状态：右转90度
            }
        }
    }
};

// ================ 跑车命令类 ================

class MoveCommand final
{
public:
    void operator()(PoseHandler& poseHandler) const noexcept
    {
        if (poseHandler.IsReverse()) {
            // 倒车状态：后退
            if (poseHandler.IsFast()) {
                // 快速倒车：后退4格
                poseHandler.Backward();
                poseHandler.Backward();
                poseHandler.Backward();
                poseHandler.Backward();
            } else {
                // 普通倒车：后退2格
                poseHandler.Backward();
                poseHandler.Backward();
            }
        } else {
            // 正常状态：前进
            if (poseHandler.IsFast()) {
                // 快速前进：前进4格
                poseHandler.Forward();
                poseHandler.Forward();
                poseHandler.Forward();
                poseHandler.Forward();
            } else {
                // 普通前进：前进2格
                poseHandler.Forward();
                poseHandler.Forward();
            }
        }
    }
};

class TurnLeftCommand final
{
public:
    void operator()(PoseHandler& poseHandler) const noexcept
    {
        if (poseHandler.IsReverse()) {
            // 倒车状态
            if (poseHandler.IsFast()) {
                // 快速倒车：后退1格，再右转90度，而后再后退1格
                poseHandler.Backward();
                poseHandler.TurnRight();
                poseHandler.Backward();
            } else {
                // 普通倒车：右转90度
                poseHandler.TurnRight();
            }
        } else {
            // 正常状态
            if (poseHandler.IsFast()) {
                // 快速状态：前进1格，再左转90度，而后再前进1格
                poseHandler.Forward();
                poseHandler.TurnLeft();
                poseHandler.Forward();
            } else {
                // 普通状态：左转90度，前进1格
                poseHandler.TurnLeft();
                poseHandler.Forward();
            }
        }
    }
};

class TurnRightCommand final
{
public:
    void operator()(PoseHandler& poseHandler) const noexcept
    {
        if (poseHandler.IsReverse()) {
            // 倒车状态
            if (poseHandler.IsFast()) {
                // 快速倒车：后退1格，再左转90度，而后再后退1格
                poseHandler.Backward();
                poseHandler.TurnLeft();
                poseHandler.Backward();
            } else {
                // 普通倒车：左转90度
                poseHandler.TurnLeft();
            }
        } else {
            // 正常状态
            if (poseHandler.IsFast()) {
                // 快速状态：前进1格，再右转90度，而后再前进1格
                poseHandler.Forward();
                poseHandler.TurnRight();
                poseHandler.Forward();
            } else {
                // 普通状态：右转90度，前进1格
                poseHandler.TurnRight();
                poseHandler.Forward();
            }
        }
    }
};

// ================ 公交车命令类 ================

class BusMoveCommand final
{
public:
    void operator()(PoseHandler& poseHandler) const noexcept
    {
        if (poseHandler.IsReverse()) {
            // 倒车状态：后退
            if (poseHandler.IsFast()) {
                // 快速倒车：后退1格，再后退1格（共2格）
                poseHandler.Backward();
                poseHandler.Backward();
            } else {
                // 普通倒车：后退1格
                poseHandler.Backward();
            }
        } else {
            // 正常状态：前进
            if (poseHandler.IsFast()) {
                // 快速前进：前进1格，再前进1格（共2格）
                poseHandler.Forward();
                poseHandler.Forward();
            } else {
                // 普通前进：前进1格
                poseHandler.Forward();
            }
        }
    }
};

class BusTurnLeftCommand final
{
public:
    void operator()(PoseHandler& poseHandler) const noexcept
    {
        if (poseHandler.IsReverse()) {
            // 倒车状态
            if (poseHandler.IsFast()) {
                // 快速倒车：后退1格，再后退1格，而后右转90度
                poseHandler.Backward();
                poseHandler.Backward();
                poseHandler.TurnRight();
            } else {
                // 普通倒车：后退1格，右转90度
                poseHandler.Backward();
                poseHandler.TurnRight();
            }
        } else {
            // 正常状态
            if (poseHandler.IsFast()) {
                // 快速状态：前进1格，再前进1格，而后左转90度
                poseHandler.Forward();
                poseHandler.Forward();
                poseHandler.TurnLeft();
            } else {
                // 普通状态：前进1格，左转90度
                poseHandler.Forward();
                poseHandler.TurnLeft();
            }
        }
    }
};

class BusTurnRightCommand final
{
public:
    void operator()(PoseHandler& poseHandler) const noexcept
    {
        if (poseHandler.IsReverse()) {
            // 倒车状态
            if (poseHandler.IsFast()) {
                // 快速倒车：后退1格，再后退1格，而后左转90度
                poseHandler.Backward();
                poseHandler.Backward();
                poseHandler.TurnLeft();
            } else {
                // 普通倒车：后退1格，左转90度
                poseHandler.Backward();
                poseHandler.TurnLeft();
            }
        } else {
            // 正常状态
            if (poseHandler.IsFast()) {
                // 快速状态：前进1格，再前进1格，而后右转90度
                poseHandler.Forward();
                poseHandler.Forward();
                poseHandler.TurnRight();
            } else {
                // 普通状态：前进1格，右转90度
                poseHandler.Forward();
                poseHandler.TurnRight();
            }
        }
    }
};

// ================ 通用状态命令类（所有车辆共享） ================

class FastCommand final
{
public:
    void operator()(PoseHandler& poseHandler) const noexcept
    {
        poseHandler.Fast();  // 切换快速状态
    }
};

class ReverseCommand final
{
public:
    void operator()(PoseHandler& poseHandler) const noexcept
    {
        poseHandler.Reverse();  // 切换倒车状态
    }
};

}  // namespace adas