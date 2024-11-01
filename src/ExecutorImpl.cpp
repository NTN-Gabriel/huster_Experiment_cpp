#include "ExecutorImpl.hpp"

#include <new>

#include <memory>

namespace adas
{
    ExecutorImpl::ExecutorImpl(const Pose &pose) noexcept : pose(pose), isFast(false) {}

    Pose ExecutorImpl::Query(void) const noexcept
    {
        return pose;
    }

    Executor *Executor::NewExecutor(const Pose &pose) noexcept
    {
        return new (std::nothrow) ExecutorImpl(pose);
    }

    void ExecutorImpl::Execute(const std::string &commands) noexcept
    {
        for (const auto cmd : commands)
        {
            std::unique_ptr<ICommand> cmder;

            if (cmd == 'M')
            {
                cmder = std::make_unique<MoveCommand>();
            }

            else if (cmd == 'L')
            { // 如果是L指令
                cmder = std::make_unique<TurnLeftCommand>();
            }

            else if (cmd == 'R')
            { // 如果是R指令
                cmder = std::make_unique<TurnRightCommand>();
            }

            else if (cmd == 'F')
            { // 如果是F指令
                cmder = std::make_unique<FastCommand>();
            }

            if (cmder)
            {
                cmder->DoOperate(*this);
            }
        }
    }

    void ExecutorImpl::Move() noexcept
    {
        if (pose.heading == 'E')
        {
            ++pose.x;
        }
        else if (pose.heading == 'W')
        {
            --pose.x;
        }
        else if (pose.heading == 'N')
        {
            ++pose.y;
        }
        else if (pose.heading == 'S')
        {
            --pose.y;
        }
    }

    void ExecutorImpl::TurnLeft() noexcept
    {
        if (pose.heading == 'E')
        {
            pose.heading = 'N';
        }
        else if (pose.heading == 'W')
        {
            pose.heading = 'S';
        }
        else if (pose.heading == 'N')
        {
            pose.heading = 'W';
        }
        else if (pose.heading == 'S')
        {
            pose.heading = 'E';
        }
    }

    void ExecutorImpl::TurnRight() noexcept
    {
        if (pose.heading == 'E')
        {
            pose.heading = 'S';
        }
        else if (pose.heading == 'W')
        {
            pose.heading = 'N';
        }
        else if (pose.heading == 'N')
        {
            pose.heading = 'E';
        }
        else if (pose.heading == 'S')
        {
            pose.heading = 'W';
        }
    }

    void ExecutorImpl::Fast() noexcept
    {
        isFast = !isFast;
    }

    bool ExecutorImpl::IsFast() const noexcept
    {
        if (isFast)
            return true;
        else
            return false;
    }
}