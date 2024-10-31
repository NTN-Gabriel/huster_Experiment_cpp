#include <gtest/gtest.h>
#include <memory>
#include <tuple>
#include "Executor.hpp"

namespace adas
{
    bool operator==(const Pose &lhs, const Pose &rhs)
    {
        return std::tie(lhs.x, lhs.y, lhs.heading) == std::tie(rhs.x, rhs.y, rhs.heading);
    }

    TEST(ExecutorTest, should_return_init_pose_when_without_command)
    {
        std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}));
        const Pose target({0, 0, 'E'});
        ASSERT_EQ(target, executor->Query());
    }

    TEST(ExecutorTest, should_return_default_pose_when_without_init_and_command)
    {
        std::unique_ptr<Executor> executor(Executor::NewExecutor());
        const Pose target({0, 0, 'N'});
        ASSERT_EQ(target, executor->Query());
    }

    TEST(ExecutorTest, should_return_x_plus_1_given_command_is_M_and_facing_is_E)
    {
        // given给定一个executor
        std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}));

        executor->Execute("M");

        const Pose target({1, 0, 'E'});
        ASSERT_EQ(target, executor->Query());
    }

    TEST(ExecutorTest, should_return_x_minus_1_given_command_is_M_and_facing_is_W)
    {
        // given给定一个executor
        std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'W'}));

        executor->Execute("M");

        const Pose target({-1, 0, 'W'});
        ASSERT_EQ(target, executor->Query());
    }

    TEST(ExecutorTest, should_return_y_plus_1_given_command_is_M_and_facing_is_N)
    {
        // given给定一个executor
        std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'N'}));

        executor->Execute("M");

        const Pose target({0, 1, 'N'});
        ASSERT_EQ(target, executor->Query());
    }

    TEST(ExecutorTest, should_return_y_minus_1_given_command_is_M_and_facing_is_S)
    {
        // given给定一个executor
        std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'S'}));

        executor->Execute("M");

        const Pose target({0, -1, 'S'});
        ASSERT_EQ(target, executor->Query());
    }
}
