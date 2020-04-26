
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

class Solver
{
public:
	Solver(const std::vector<std::string>& NewContainer)
		: Board(NewContainer)
	{
		Solve();
Print();
	}

	enum class BlockType
	{
		TYPE_1,
		TYPE_2,
		TYPE_3,
		TYPE_4,
	};

private:
	void Solve()
	{
		int EmptyPositionNumber = GetEmptyPositionNumber();
		if ((EmptyPositionNumber % 3) == 0)
		{
			Answer = GetCalculation();
		}
		else
		{
			Answer = 0;
		}
	}

	int GetEmptyPositionNumber()
	{
		int ReturnValue = 0;
		for (int Row = 0; Row < Board.size(); ++Row)
		{
			for (int Col = 0; Col < Board.front().size(); ++Col)
			{
				if (Board[Row][Col] == '.')
				{
					ReturnValue += 1;
				}
			}
		}
		return ReturnValue;
	}

	int GetCalculation()
	{
		int ReturnValue = 0;
		ReturnValue += GetCalculationRecursive();
		return ReturnValue;
	}

	int GetCalculationRecursive()
	{
		int ReturnValue = 0;
		const std::pair<int, int>& EmptyPosition = GetFirstEmptyPosition();
		if ((EmptyPosition.first == -1) && (EmptyPosition.second == -1))
		{
			ReturnValue = 1;
		}
		else
		{
			for (BlockType Type : BlockTypes)
			{
				if (TryToPutBlock(EmptyPosition.first, EmptyPosition.second, Type))
				{
					ReturnValue += GetCalculationRecursive();
					PutBackBlock(EmptyPosition.first, EmptyPosition.second, Type);
				}
			}
		}
		return ReturnValue;
	}

	std::pair<int, int> GetFirstEmptyPosition()
	{
		std::pair<int, int> ReturnValue = { -1, -1 };
		for (int Row = 0; Row < Board.size(); ++Row)
		{
			for (int Col = 0; Col < Board.front().size(); ++Col)
			{
				char Symbol = Board[Row][Col];
				if (Symbol == '#')
				{
					continue;
				}
				else
				{
					ReturnValue.first = Row;
					ReturnValue.second = Col;
					break;
				}
			}

			if ((ReturnValue.first != -1) && (ReturnValue.second != -1))
			{
				break;
			}
		}
		return ReturnValue;
	}

	bool TryToPutBlock(int Row, int Col, BlockType Type)
	{
		bool ReturnValue = true;
		for (const std::pair<int, int>& Pair : BlockDirectionMap.at(Type))
		{
			int NewRow = Row + Pair.first;
			int NewCol = Col + Pair.second;
			if (IsValidPositionToPutBlock(NewRow, NewCol) == false)
			{
				ReturnValue = false;
				break;
			}
		}
		if (ReturnValue)
		{
			for (const std::pair<int, int>& Pair : BlockDirectionMap.at(Type))
			{
				int NewRow = Row + Pair.first;
				int NewCol = Col + Pair.second;
				Board[NewRow][NewCol] = '#';
			}
		}
		return ReturnValue;
	}

	void PutBackBlock(int Row, int Col, BlockType Type)
	{
		for (const std::pair<int, int>& Pair : BlockDirectionMap.at(Type))
		{
			int NewRow = Row + Pair.first;
			int NewCol = Col + Pair.second;
			Board[NewRow][NewCol] = '.';
		}
	}

	bool IsValidPositionToPutBlock(int Row, int Col)
	{
		bool ReturnValue = true;
		if ((Row < 0) || (Board.size() <= Row))
		{
			ReturnValue = false;
		}
		if ((Col < 0) || (Board.front().size() <= Col))
		{
			ReturnValue = false;
		}
		if (ReturnValue)
		{
			if (Board[Row][Col] == '#')
			{
				ReturnValue = false;
			}
		}
		return ReturnValue;
	}

	void Print()
	{
		std::cout << Answer << std::endl;
	}

private:
	const std::vector<BlockType> BlockTypes
	{
		BlockType::TYPE_1,
		BlockType::TYPE_2,
		BlockType::TYPE_3,
		BlockType::TYPE_4
	};
	const std::map<BlockType, std::vector<std::pair</*Row*/ int, /*Col*/ int>>> BlockDirectionMap
	{
		{BlockType::TYPE_1, {{+0, +0}, {+1, +0}, {+0, +1}}},
		{BlockType::TYPE_2, {{+0, +0}, {+0, +1}, {+1, +1}}},
		{BlockType::TYPE_3, {{+0, +0}, {+1, +0}, {+1, +1}}},
		{BlockType::TYPE_4, {{+0, +0}, {+1, +0}, {+1, -1}}}
	};
	std::vector<std::string> Board;
	int Answer;
};

int main()
{
	int NumberOfTestcase;
	std::cin >> NumberOfTestcase;
	for (int Index = 0; Index < NumberOfTestcase; ++Index)
	{
		int RowSize;
		std::cin >> RowSize;
		int ColSize;
		std::cin >> ColSize;
		std::vector<std::string> Container;
		for (int Row = 0; Row < RowSize; ++Row)
		{
			std::string Line;
			std::cin >> Line;
			Container.push_back(Line);
		}
		Solver S(Container);
	}
	return 0;
}