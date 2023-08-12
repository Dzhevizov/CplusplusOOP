#include "Snake.h"
#include <iostream>

static Point getFuturePos(const Direction dir, const Point& pos)
{
	Point futurePos = pos;

	switch (dir)
	{
	case Direction::RIGHT:
		++futurePos.col;
		break;

	case Direction::DOWN:
		++futurePos.row;
		break;

	case Direction::LEFT:
		--futurePos.col;
		break;

	case Direction::UP:
		--futurePos.row;
		break;

	default:
		std::cerr << "Received invalid enum value " << static_cast<int>(dir) << std::endl;
		break;
	}

	return futurePos;
}

static bool isMoveValid(const Point& pos, 
	const int fieldRows, 
	const int fieldCols, 
	const std::vector<Point>& obstacles,
	const std::deque<Point>& snakeNodes)
{
	if (0 > pos.row)
		return false;

	if (0 > pos.col)
		return false;

	if (pos.row >= fieldRows)
		return false;

	if (pos.col >= fieldCols)
		return false;

	for (const Point& obstacle : obstacles)
	{
		if (obstacle == pos)
			return false;
	}

	for (const Point& node : snakeNodes)
	{
		if (node == pos)
			return false;
	}

	return true;
}

static bool shouldPowerup(const Point& pos, 
	std::vector<Point>& powerUps,
	size_t& foundIdx)
{
	size_t Idx = 0;
	for (const Point& powerUp : powerUps)
	{
		if (powerUp == pos)
		{
			foundIdx = Idx;
			return true;
		}
		
		++Idx;
	}

	return false;
}

Snake::Snake(const int fieldRows, const int fieldCols, const Point& startPos)
	: _FIELD_ROWS(fieldRows)
	, _FIELD_COLS(fieldCols)
	, _currPos(startPos)
{
	_snakeNodes.push_back(startPos);
}

Snake::~Snake()
{
}

StatusCode Snake::move(const Direction dir, 
	const std::vector<Point>& obstacles, 
	std::vector<Point>& powerUps)
{
	const Point futurePos = getFuturePos(dir, _currPos);

	const bool isValid = isMoveValid(futurePos, _FIELD_ROWS, _FIELD_COLS, obstacles, _snakeNodes);

	if (!isValid)
		return StatusCode::SNAKE_DEAD;

	StatusCode code = StatusCode::STATUS_UNKNOWN;

	size_t foundIdx = 0;

	const bool powerUp = shouldPowerup(futurePos, powerUps, foundIdx);

	if (powerUp)
	{
		powerUps.erase(powerUps.begin() + foundIdx);
		code = StatusCode::SNAKE_GROWING;
	}
	else
	{
		code = StatusCode::SNAKE_MOVING;
		_snakeNodes.pop_back();
	}

	_snakeNodes.push_front(futurePos);
	_currPos = futurePos;
		
	return code;
}

std::deque<Point>& Snake::getSnakeNodes()
{
	return _snakeNodes;
}