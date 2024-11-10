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
        std::unordered_map<char, std::function<void(PoseHandler & PoseHandler)>> cmderMap;
        // 前进
        MoveCommand moveCommand;
        cmderMap.emplace('M', moveCommand.operate);
        // 左转
        TurnLeftCommand turnLeftCommand;
        cmderMap.emplace('L', turnLeftCommand.operate);
        // 右转
        TurnRightCommand turnRightCommand;
        cmderMap.emplace('R', turnRightCommand.operate);
        // 快速
        FastCommand fastCommand;
        cmderMap.emplace('F', fastCommand.operate);

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