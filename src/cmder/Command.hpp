#pragma once

#include "core\PoseHandler.hpp"

#include <functional>

#include "CmderOrchestrator.hpp"

namespace adas
{

    class MoveCommand final // : public ICommand
    {
    public:
        ActionGroup operator()(const PoseHandler &poseHandler, const CmderOrchestrator &orchestrator) const noexcept
        {
            return orchestrator.Move(poseHandler);
        }
    };

    class TurnLeftCommand final //: public ICommand
    {
    public:
        ActionGroup operator()(const PoseHandler &poseHandler, const CmderOrchestrator &orchestrator) const noexcept
        {

            return orchestrator.TurnLeft(poseHandler);
        }
    };

    class TurnRightCommand final //: public ICommand
    {
    public:
        ActionGroup operator()(const PoseHandler &poseHandler, const CmderOrchestrator &orchestrator) const noexcept
        {
            return orchestrator.TurnRight(poseHandler);
        }
    };

    class FastCommand final //: public ICommand
    {
    public:
        ActionGroup operator()(const PoseHandler &poseHandler, const CmderOrchestrator &orchestrator) const noexcept
        {
            ActionGroup actionGroup;
            auto const action = ActionType::BE_FAST_ACTION;
            actionGroup.PushAction(action);
            return actionGroup;
        }
    };

    class ReverseCommand final //: public ICommand
    {
    public:
        ActionGroup operator()(const PoseHandler &poseHandler, const CmderOrchestrator &orchestrator) const noexcept
        {
            ActionGroup actionGroup;
            auto const action = ActionType::BE_REVERSE_ACTION;
            actionGroup.PushAction(action);
            return actionGroup;
        }
    };

    class TurnRoundCommand final //: public ICommand
    {
    public:
        ActionGroup operator()(const PoseHandler &poseHandler, const CmderOrchestrator &orchestrator) const noexcept
        {
            return orchestrator.TurnRound(poseHandler);
        }
    };

} // namespace adas
