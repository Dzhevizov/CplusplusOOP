#pragma once

class MinAggregator : public StreamAggregator
{
public:
	MinAggregator(std::istream& stream)
		: StreamAggregator(stream)
	{
		aggregationResult = 0;
	}

	virtual void aggregate(int next) override
	{
		StreamAggregator::aggregate(next);
		if (aggregationResult > next)
			aggregationResult = next;

		if (getNumAggregated() == 1)
			aggregationResult = next;
	}
};