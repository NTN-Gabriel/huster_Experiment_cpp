#include "CmderFactory.hpp"

namespace adas
{
    CmderList CmderFactory::GetCmders(const std::string &commands) const noexcept
    {
        CmderList commandList;
        for (const auto &cmdmap : commands)
        {
            auto cmdermap = cmderMap.find(cmdmap);
            if (cmdermap != cmderMap.end())
                commandList.push_back(cmdermap->second);
        }
        return commandList;
    };
}