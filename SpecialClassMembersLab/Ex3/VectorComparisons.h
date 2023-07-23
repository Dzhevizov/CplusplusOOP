#pragma once

template <typename T, typename VectorLengthComparer>
struct ReverseComparer
{
    bool operator()(const T& lhs, const T& rhs) const
    {
        VectorLengthComparer oVectorLengthComparer;
        return oVectorLengthComparer(rhs, lhs);
    }
};

struct VectorLengthComparer
{
    bool operator()(const Vector& lhs, const Vector& rhs)
    {
        return lhs.getLength() < rhs.getLength();
    }
};
