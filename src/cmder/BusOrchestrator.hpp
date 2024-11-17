#pragma once

#include "NormalOrchestrator.hpp"

namespace adas
{
    class BusOrchestrator : public NormalOrchestrator
    {
    public:
        ActionGroup TurnLeft(const PoseHandler &poseHandler) const noexcept override
        {
            ActionGroup actionGroup;
            actionGroup += OnFast(poseHandler);
            const auto action = poseHandler.IsReverse() ? ActionType::BACKWARD_1_STEP_ACTION : ActionType::FORWARD_1_STEP_ACTION;
            actionGroup.PushAction(action);
            const auto action1 = poseHandler.IsReverse() ? ActionType::REVERSE_TURNLEFT_ACTION : ActionType::TURNLEFT_ACTION;
            actionGroup.PushAction(action1);
            return actionGroup;
        }

        ActionGroup TurnRight(const PoseHandler &poseHandler) const noexcept override
        {
            ActionGroup actionGroup;
            actionGroup += OnFast(poseHandler);
            const auto action = poseHandler.IsReverse() ? ActionType::BACKWARD_1_STEP_ACTION : ActionType::FORWARD_1_STEP_ACTION;
            actionGroup.PushAction(action);
            const auto action1 = poseHandler.IsReverse() ? ActionType::REVERSE_TURNRIGHT_ACTION : ActionType::TURNRIGHT_ACTION;
            actionGroup.PushAction(action1);
            return actionGroup;
        }
    };
}