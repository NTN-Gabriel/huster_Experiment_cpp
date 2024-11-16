#include "CmderFactory.hpp"

namespace adas
{
    CmderList CmderFactory::GetCmders(const std::string &commands) const noexcept
    {
        CmderList commandList;
        for (const auto &cmdmap : ParseCommandString(commands))
        {
            auto cmdermap = cmderMap.find(cmdmap);
            if (cmdermap != cmderMap.end())
                commandList.push_back(cmdermap->second);
        }
        return commandList;
    };

    std::string CmderFactory::ParseCommandString(std::string_view commands) const noexcept
    {
        std::string result(commands);
        ReplaceAll(result, "TR", "Z");
        return result;
    }

    void CmderFactory::ReplaceAll(std::string &inout, std::string_view what, std::string_view with) const noexcept
    {
        for (
            std::string::size_type pos{};
            inout.npos != (pos = inout.find(what.data(), pos, what.length()));
            pos += with.length())
        {
            inout.replace(pos, what.length(), with.data(), with.length());
        }
    }
}