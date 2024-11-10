#include "ExecutorImpl.hpp"
#include "Command.hpp"

#include <unordered_map>

#include <new>

#include <memory>

namespace adas
{
    ExecutorImpl::ExecutorImpl(const Pose &pose) noexcept : poseHandler(pose) {}

    Pose ExecutorImpl::Query() const noexcept
    {
        return poseHandler.Query();
    }

    Executor *Executor::NewExecutor(const Pose &pose) noexcept
    {
        return new (std::nothrow) ExecutorImpl(pose);
    }

    void ExecutorImpl::Execute(const std::string &commands) noexcept
    {
        // 表驱动
        std::unordered_map<char, std::function<void(PoseHandler & PoseHandler)>> cmderMap{
            {'M', MoveCommand()},      // 前进
            {'L', TurnLeftCommand()},  // 左转
            {'R', TurnRightCommand()}, // 右转
            {'F', FastCommand()},      // 快速
        };
        // // 前进
        // cmderMap.emplace('M', MoveCommand());
        // // 左转
        // cmderMap.emplace('L', TurnLeftCommand());
        // // 右转
        // cmderMap.emplace('R', TurnRightCommand());
        // // 快速
        // cmderMap.emplace('F', FastCommand());

        for (const auto cmd : commands)
        {
            // 根据操作查找表驱动
            const auto it = cmderMap.find(cmd);
            // 如果找到表驱动，执行操作对应的指令
            if (it != cmderMap.end())
            {
                it->second(poseHandler);
            }
        }
    }
}