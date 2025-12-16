#include <gtest/gtest.h>

#include "Executor.hpp"
#include "PoseEq.hpp"
#include "VehicleType.hpp"

namespace adas
{
// =============================
// 跑车测试套件 (12个测试用例)
// =============================
class SportsCarTest : public ::testing::Test
{
protected:
    void SetUp() override
    {
        executor.reset(Executor::NewExecutor({0, 0, 'N'}, VehicleType::SportsCar));
    }
    std::unique_ptr<Executor> executor;
};

// 正常状态 - M指令
TEST_F(SportsCarTest, normal_M_command_forward_2_cells)
{
    executor->Execute("M");
    const Pose target{0, 2, 'N'};
    ASSERT_EQ(target, executor->Query());
}

// 正常状态 - L指令
TEST_F(SportsCarTest, normal_L_command_turn_left_and_forward_1_cell)
{
    executor->Execute("L");
    const Pose target{-1, 0, 'W'};
    ASSERT_EQ(target, executor->Query());
}

// 正常状态 - R指令
TEST_F(SportsCarTest, normal_R_command_turn_right_and_forward_1_cell)
{
    executor->Execute("R");
    const Pose target{1, 0, 'E'};
    ASSERT_EQ(target, executor->Query());
}

// 快速状态 - M指令
TEST_F(SportsCarTest, fast_M_command_forward_4_cells)
{
    executor->Execute("F");
    executor->Execute("M");
    const Pose target{0, 4, 'N'};
    ASSERT_EQ(target, executor->Query());
}

// 快速状态 - L指令
TEST_F(SportsCarTest, fast_L_command_forward_1_turn_left_forward_1)
{
    executor->Execute("F");
    executor->Execute("L");
    const Pose target{-1, 1, 'W'};
    ASSERT_EQ(target, executor->Query());
}

// 快速状态 - R指令
TEST_F(SportsCarTest, fast_R_command_forward_1_turn_right_forward_1)
{
    executor->Execute("F");
    executor->Execute("R");
    const Pose target{1, 1, 'E'};
    ASSERT_EQ(target, executor->Query());
}

// 倒车状态 - M指令
TEST_F(SportsCarTest, reverse_M_command_backward_2_cells)
{
    executor->Execute("B");
    executor->Execute("M");
    const Pose target{0, -2, 'N'};
    ASSERT_EQ(target, executor->Query());
}

// 倒车状态 - L指令
TEST_F(SportsCarTest, reverse_L_command_turn_right)
{
    executor->Execute("B");
    executor->Execute("L");
    const Pose target{0, 0, 'E'};
    ASSERT_EQ(target, executor->Query());
}

// 倒车状态 - R指令
TEST_F(SportsCarTest, reverse_R_command_turn_left)
{
    executor->Execute("B");
    executor->Execute("R");
    const Pose target{0, 0, 'W'};
    ASSERT_EQ(target, executor->Query());
}

// 快速倒车状态 - M指令
TEST_F(SportsCarTest, fast_reverse_M_command_backward_4_cells)
{
    executor->Execute("F");
    executor->Execute("B");
    executor->Execute("M");
    const Pose target{0, -4, 'N'};
    ASSERT_EQ(target, executor->Query());
}

// 快速倒车状态 - L指令
TEST_F(SportsCarTest, fast_reverse_L_command_backward_1_turn_right_backward_1)
{
    executor->Execute("F");
    executor->Execute("B");
    executor->Execute("L");
    const Pose target{-1, -1, 'E'};
    ASSERT_EQ(target, executor->Query());
}

// 快速倒车状态 - R指令
TEST_F(SportsCarTest, fast_reverse_R_command_backward_1_turn_left_backward_1)
{
    executor->Execute("F");
    executor->Execute("B");
    executor->Execute("R");
    const Pose target{1, -1, 'W'};
    ASSERT_EQ(target, executor->Query());
}

// =============================
// 公交车测试套件 (12个测试用例)
// =============================
class BusTest : public ::testing::Test
{
protected:
    void SetUp() override
    {
        executor.reset(Executor::NewExecutor({0, 0, 'N'}, VehicleType::Bus));
    }
    std::unique_ptr<Executor> executor;
};

// 正常状态 - M指令
TEST_F(BusTest, normal_M_command_forward_1_cell)
{
    executor->Execute("M");
    const Pose target{0, 1, 'N'};
    ASSERT_EQ(target, executor->Query());
}

// 正常状态 - L指令
TEST_F(BusTest, normal_L_command_forward_1_turn_left)
{
    executor->Execute("L");
    const Pose target{0, 1, 'W'};
    ASSERT_EQ(target, executor->Query());
}

// 正常状态 - R指令
TEST_F(BusTest, normal_R_command_forward_1_turn_right)
{
    executor->Execute("R");
    const Pose target{0, 1, 'E'};
    ASSERT_EQ(target, executor->Query());
}

// 快速状态 - M指令
TEST_F(BusTest, fast_M_command_forward_2_cells)
{
    executor->Execute("F");
    executor->Execute("M");
    const Pose target{0, 2, 'N'};
    ASSERT_EQ(target, executor->Query());
}

// 快速状态 - L指令
TEST_F(BusTest, fast_L_command_forward_2_turn_left)
{
    executor->Execute("F");
    executor->Execute("L");
    const Pose target{0, 2, 'W'};
    ASSERT_EQ(target, executor->Query());
}

// 快速状态 - R指令
TEST_F(BusTest, fast_R_command_forward_2_turn_right)
{
    executor->Execute("F");
    executor->Execute("R");
    const Pose target{0, 2, 'E'};
    ASSERT_EQ(target, executor->Query());
}

// 倒车状态 - M指令
TEST_F(BusTest, reverse_M_command_backward_1_cell)
{
    executor->Execute("B");
    executor->Execute("M");
    const Pose target{0, -1, 'N'};
    ASSERT_EQ(target, executor->Query());
}

// 倒车状态 - L指令
TEST_F(BusTest, reverse_L_command_backward_1_turn_right)
{
    executor->Execute("B");
    executor->Execute("L");
    const Pose target{0, -1, 'E'};
    ASSERT_EQ(target, executor->Query());
}

// 倒车状态 - R指令
TEST_F(BusTest, reverse_R_command_backward_1_turn_left)
{
    executor->Execute("B");
    executor->Execute("R");
    const Pose target{0, -1, 'W'};
    ASSERT_EQ(target, executor->Query());
}

// 快速倒车状态 - M指令
TEST_F(BusTest, fast_reverse_M_command_backward_2_cells)
{
    executor->Execute("F");
    executor->Execute("B");
    executor->Execute("M");
    const Pose target{0, -2, 'N'};
    ASSERT_EQ(target, executor->Query());
}

// 快速倒车状态 - L指令
TEST_F(BusTest, fast_reverse_L_command_backward_2_turn_right)
{
    executor->Execute("F");
    executor->Execute("B");
    executor->Execute("L");
    const Pose target{0, -2, 'E'};
    ASSERT_EQ(target, executor->Query());
}

// 快速倒车状态 - R指令
TEST_F(BusTest, fast_reverse_R_command_backward_2_turn_left)
{
    executor->Execute("F");
    executor->Execute("B");
    executor->Execute("R");
    const Pose target{0, -2, 'W'};
    ASSERT_EQ(target, executor->Query());
}

}  // namespace adas