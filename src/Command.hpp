#pragma once

#include "PoseHandler.hpp"

#include <functional>

#include "ActionGroup.hpp"

namespace adas
{

    class MoveCommand final // : public ICommand
    {
    public:
        ActionGroup operator()(PoseHandler &poseHandler) const noexcept
        {
            ActionGroup actionGroup;
            const auto action = poseHandler.IsReverse() ? ActionType::BACKWARD_1_STEP_ACTION : ActionType::FORWARD_1_STEP_ACTION;
            if (poseHandler.IsFast())
            {
                actionGroup.PushAction(action);
            }
            actionGroup.PushAction(action);
            return actionGroup;
        }
    };

    class TurnLeftCommand final //: public ICommand
    {
    public:
        ActionGroup operator()(PoseHandler &poseHandler) const noexcept
        {
            ActionGroup actionGroup;

            const auto action2 = poseHandler.IsReverse() ? ActionType::REVERSE_TURNLEFT_ACTION : ActionType::TURNLEFT_ACTION;

            if (poseHandler.IsFast())
            {
                const auto action1 = poseHandler.IsReverse() ? ActionType::BACKWARD_1_STEP_ACTION : ActionType::FORWARD_1_STEP_ACTION;
                actionGroup.PushAction(action1);
            }
            actionGroup.PushAction(action2);
            return actionGroup;
        }
    };

    class TurnRightCommand final //: public ICommand
    {
    public:
        ActionGroup operator()(PoseHandler &poseHandler) const noexcept
        {
            ActionGroup actionGroup;

            const auto action2 = poseHandler.IsReverse() ? ActionType::REVERSE_TURNRIGHT_ACTION : ActionType::TURNRIGHT_ACTION;

            if (poseHandler.IsFast())
            {
                const auto action1 = poseHandler.IsReverse() ? ActionType::BACKWARD_1_STEP_ACTION : ActionType::FORWARD_1_STEP_ACTION;
                actionGroup.PushAction(action1);
            }
            actionGroup.PushAction(action2);
            return actionGroup;
        }
    };

    class FastCommand final //: public ICommand
    {
    public:
        ActionGroup operator()(PoseHandler &poseHandler) const noexcept
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
        ActionGroup operator()(PoseHandler &poseHandler) const noexcept
        {
            ActionGroup actionGroup;
            auto const action = ActionType::BE_REVERSE_ACTION;
            actionGroup.PushAction(action);
            return actionGroup;
        }
    };

} // namespace adas
