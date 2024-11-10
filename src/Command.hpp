#pragma once

#include "PoseHandler.hpp"

#include <functional>

namespace adas
{
    // class ICommand
    // {
    // public:
    //     virtual ~ICommand() = default;
    //     virtual void DoOperate(PoseHandler &poseHandler) const noexcept = 0;
    // };

    class MoveCommand final // : public ICommand
    {
    public:
        // void DoOperate(PoseHandler &poseHandler) const noexcept override
        // {
        //     if (poseHandler.IsFast())
        //         poseHandler.Move();
        //     poseHandler.Move();
        // }

        // const std ::function<void(PoseHandler &PoseHandler)> operate = [](PoseHandler &poseHandler) noexcept
        // {
        //     if (poseHandler.IsFast())
        //     {
        //         poseHandler.Move();
        //     }
        //     poseHandler.Move();
        // };

        void operator()(PoseHandler &poseHandler) const noexcept
        {
            if (poseHandler.IsFast())
            {
                if (poseHandler.IsReverse())
                {
                    poseHandler.Backward();
                }
                else
                {
                    poseHandler.Forward();
                }
            }
            if (poseHandler.IsReverse())
            {
                poseHandler.Backward();
            }
            else
            {
                poseHandler.Forward();
            }
        }
    };

    class TurnLeftCommand final //: public ICommand
    {
    public:
        // void DoOperate(PoseHandler &poseHandler) const noexcept override
        // {
        //     if (poseHandler.IsFast())
        //         poseHandler.Move();
        //     poseHandler.TurnLeft();
        // }

        // const std ::function<void(PoseHandler &PoseHandler)> operate = [](PoseHandler &poseHandler) noexcept
        // {
        //     if (poseHandler.IsFast())
        //     {
        //         poseHandler.Move();
        //     }
        //     poseHandler.TurnLeft();
        // };

        void operator()(PoseHandler &poseHandler) const noexcept
        {
            if (poseHandler.IsFast())
            {
                if (poseHandler.IsReverse())
                {
                    poseHandler.Backward();
                }
                else
                {
                    poseHandler.Forward();
                }
            }
            if (poseHandler.IsReverse())
            {
                poseHandler.TurnRight();
            }
            else
            {
                poseHandler.TurnLeft();
            }
        }
    };

    class TurnRightCommand final //: public ICommand
    {
    public:
        // void DoOperate(PoseHandler &poseHandler) const noexcept override
        // {
        //     if (poseHandler.IsFast())
        //         poseHandler.Move();
        //     poseHandler.TurnRight();
        // }

        // const std ::function<void(PoseHandler &PoseHandler)> operate = [](PoseHandler &poseHandler) noexcept
        // {
        //     if (poseHandler.IsFast())
        //     {
        //         poseHandler.Move();
        //     }
        //     poseHandler.TurnRight();
        // };

        void operator()(PoseHandler &poseHandler) const noexcept
        {
            if (poseHandler.IsFast())
            {
                if (poseHandler.IsReverse())
                {
                    poseHandler.Backward();
                }
                else
                {
                    poseHandler.Forward();
                }
            }
            if (poseHandler.IsReverse())
            {
                poseHandler.TurnLeft();
            }
            else
            {
                poseHandler.TurnRight();
            }
        }
    };

    class FastCommand final //: public ICommand
    {
    public:
        // void DoOperate(PoseHandler &poseHandler) const noexcept override
        // {
        //     poseHandler.Fast();
        //     poseHandler.IsFast();
        // }

        // const std ::function<void(PoseHandler &PoseHandler)> operate = [](PoseHandler &poseHandler) noexcept
        // {
        //     poseHandler.Fast();
        //     poseHandler.IsFast();
        // };

        void operator()(PoseHandler &poseHandler) const noexcept
        {
            poseHandler.Fast();
            poseHandler.IsFast();
        }
    };

    class ReverseCommand final //: public ICommand
    {
    public:
        void operator()(PoseHandler &posehandler) const noexcept
        {
            posehandler.Reverse();
            posehandler.IsReverse();
        }
    };

} // namespace adas
