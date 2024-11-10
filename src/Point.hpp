#pragma once

namespace adas
{

    class Point final
    {
    public:
        Point(const int x, const int y) noexcept;

        Point(const Point &rhs) noexcept;            // 拷贝构造
        Point &operator=(const Point &rhs) noexcept; // 拷贝复制

        Point &operator+=(const Point &rhs) noexcept; // 前进
        Point &operator-=(const Point &rhs) noexcept; // 后退

    public:
        int GetX(void) const noexcept; // 获取X坐标
        int GetY(void) const noexcept; // 获取Y坐标

    private:
        int x; // X坐标
        int y; // X坐标
    };

}