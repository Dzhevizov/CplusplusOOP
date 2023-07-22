#pragma once

#include "Song.h"

template <typename T, typename LessThan>
struct Reverse
{
    bool operator()(const T& lhs, const T& rhs) const
    {
        LessThan lessThan;
        return lessThan(rhs, lhs);
    }
};

template <typename T>
struct LessThan
{
    bool operator()(const T& lhs, const T& rhs) const
    {
        return lhs < rhs;
    }
};

template<>
struct LessThan<Song>
{
    bool operator()(const Song& lhs, const Song& rhs)
    {
        return lhs.getLengthSeconds() < rhs.getLengthSeconds();
    }
};
