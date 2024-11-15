#pragma once

#include <functional>
#include <list>
#include <unordered_map>

#include "Command.hpp"

namespace adas
{
    class CmderFactory final
    {
    public:
        CmderFactory(void) = default;
        ~CmderFactory(void) = default;

        CmderFactory(const CmderFactory &) = delete;
        CmderFactory &operator=(const CmderFactory &) = delete;

    public:
        std::list<std::function<void(PoseHandler &poseHandler)>> GetCmders(const std::string &commands) const noexcept;

    private:
        const std::unordered_map<char, std::function<void(PoseHandler &poseHanlder)>> cmderMap{
            {'M', MoveCommand()},      // 前进
            {'L', TurnLeftCommand()},  // 左转
            {'R', TurnRightCommand()}, // 右转
            {'F', FastCommand()},      // 快速
            {'B', ReverseCommand()},   // 后退
        };
    };
}