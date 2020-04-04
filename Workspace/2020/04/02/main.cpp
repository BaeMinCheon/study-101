
#include <iostream>
#include <vector>

class Solver
{
public:
	Solver(const std::vector<int>& NewContainer)
		: TestcaseContainer(NewContainer)
	{
		Solve();
		Print();
	}

private:
	void Solve()
	{
		AnswerContainer.clear();

		for (int Testcase : TestcaseContainer)
		{
			int Answer = GetAnswer(Testcase);
			AnswerContainer.push_back(Answer);
		}
	}

	int GetAnswer(int BoardSize)
	{
		std::vector<std::vector<int>> Board(BoardSize, std::vector<int>(BoardSize, 0));
		int ReturnValue = 0;

		if (BoardSize > 0)
		{
			ReturnValue = GetPossibleDeployments(Board, 0);
		}

		return ReturnValue;
	}

	int GetPossibleDeployments(std::vector<std::vector<int>>& Board, int Row)
	{
		int ReturnValue = 0;
		int BoardSize = Board.size();
		bool IsLastRow = Row >= (BoardSize - 1);

		for (int Col = 0; Col < BoardSize; ++Col)
		{
			if (IsValidToDeploy(Board, Row, Col))
			{
				Board[Row][Col] = 1;
			}
			else
			{
				continue;
			}

			if (IsLastRow)
			{
				ReturnValue += 1;
			}
			else
			{
				ReturnValue += GetPossibleDeployments(Board, Row + 1);
			}

			Board[Row][Col] = 0;
		}

		return ReturnValue;
	}

	bool IsValidToDeploy(const std::vector<std::vector<int>>& Board, int Row, int Col)
	{
		int BoardSize = Board.size();
		bool ReturnValue = true;

		for (const Direction2D& Direction : DirectionContainer)
		{
			int NewRow = Row;
			int NewCol = Col;

			for (int Index = 0; Index < BoardSize; ++Index)
			{
				NewRow += Direction.RowDiff;
				NewCol += Direction.ColDiff;

				if (IsInBoard(BoardSize, NewRow, NewCol) == false)
				{
					break;
				}

				if (Board[NewRow][NewCol] == 1)
				{
					ReturnValue = false;
					break;
				}
			}

			if (ReturnValue == false)
			{
				break;
			}
		}

		return ReturnValue;
	}

	bool IsInBoard(int BoardSize, int Row, int Col)
	{
		bool ReturnValue = true;

		if ((Row < 0) || (Col < 0) || (Row >= BoardSize) || (Col >= BoardSize))
		{
			ReturnValue = false;
		}

		return ReturnValue;
	}

	void Print()
	{
		for (int Answer : AnswerContainer)
		{
			std::cout << Answer << std::endl;
		}
	}

private:
	std::vector<int> TestcaseContainer;
	std::vector<int> AnswerContainer;

	struct Direction2D
	{
		Direction2D(int NewRowDiff, int NewColDiff)
			: RowDiff(NewRowDiff), ColDiff(NewColDiff)
		{
		}

		int RowDiff;
		int ColDiff;
	};
	const std::vector<Direction2D> DirectionContainer
	{
		Direction2D(0, -1),     // left
		Direction2D(-1, -1),    // left-up
		Direction2D(-1, 0),     // up
		Direction2D(-1, +1),    // right-up
		Direction2D(0, +1),     // right
		Direction2D(+1, +1),    // right-down
		Direction2D(+1, 0),     // down
		Direction2D(+1, -1)     // left-down
	};
};

int main()
{
	std::vector<int> Container;
	int NumberOfTestcase;
	std::cin >> NumberOfTestcase;
	for (int Index = 0; Index < NumberOfTestcase; ++Index)
	{
		int Testcase;
		std::cin >> Testcase;
		Container.push_back(Testcase);
	}

	Solver S(Container);

	return 0;
}