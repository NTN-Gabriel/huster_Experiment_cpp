#include "CmderFactory.hpp"

namespace adas
{
    std::list<std::function<void(PoseHandler &poseHandler)>> CmderFactory::GetCmders(const std::string &commands) const noexcept
    {
        std::list<std::function<void(PoseHandler & poseHandler)>> commandList;
        for (const auto &cmdmap : commands)
        {
            auto cmdermap = cmderMap.find(cmdmap);
            if (cmdermap != cmderMap.end())
                commandList.push_back(cmdermap->second);
        }
        return commandList;
    };
}