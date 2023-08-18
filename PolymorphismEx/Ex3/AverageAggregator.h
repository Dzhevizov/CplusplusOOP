#pragma once

class AverageAggregator : public StreamAggregator
{
public:
	AverageAggregator(std::istream& stream)
		: StreamAggregator(stream)
	{
		aggregationResult = 0;
	}

	virtual void aggregate(int next) override
	{
		StreamAggregator::aggregate(next);

		aggregationResult = (aggregationResult * (getNumAggregated() - 1) + next) / getNumAggregated();
	}
};