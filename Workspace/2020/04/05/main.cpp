
#include <iostream>
#include <vector>

class Solver
{
public:
	Solver(const std::vector<std::vector<int>>& NewContainer)
		: TestcaseContainer(NewContainer)
	{
		Solve();
		Print();
	}

private:
	void Solve()
	{
		AnswerContainer.clear();

		for (const std::vector<int>& Testcase : TestcaseContainer)
		{
			int Answer = GetAnswer(Testcase);
			AnswerContainer.push_back(Answer);
		}
	}

	int GetAnswer(const std::vector<int>& Clocks)
	{
		;
	}

	void Print()
	{
		for (int Answer : AnswerContainer)
		{
			std::cout << Answer << std::endl;
		}
		std::cout << std::endl;
	}

private:
	std::vector<std::vector<int>> TestcaseContainer;
	std::vector<int> AnswerContainer;
	std::vector<std::vector<int>> SwitchContainer
	{
		{	0,	1,	2			},
		{	3,	7,	9,	11		},
		{	4,	10,	14,	15		},
		{	0,	4,	5,	6,	7	},
		{	6,	7,	8,	10,	12	},
		{	0,	2,	14,	15		},
		{	3,	14,	15			},
		{	4,	5,	7,	14,	15	},
		{	1,	2,	3,	4,	5	},
		{	3,	4,	5,	9,	13	}
	};
};

class Simulator
{
public:
	Simulator(const std::vector<int>& NewBoard)
		: IsPendingQuit(false)
	{
		for (const int Number : NewBoard)
		{
			Board.push_back(Number);
		}
	}

	void Loop()
	{
		for (;;)
		{
			if (IsPendingQuit)
			{
				break;
			}

			Print();
			Input();
		}
	}

private:
	void Input()
	{
		int SwitchIndex;
		std::cout << "enter the switch (value that is out of range [0, 9] quits the program) : ";
		std::cin >> SwitchIndex;

		if ((0 <= SwitchIndex) && (SwitchIndex < SwitchContainer.size()))
		{
			const std::vector<int>& Clocks = SwitchContainer[SwitchIndex];
			for (const int Clock : Clocks)
			{
				Board[Clock] += 3;
				
				if (Board[Clock] >= 13)
				{
					Board[Clock] = 3;
				}
			}
		}
		else
		{
			std::cout << "quit the simulator..." << std::endl;
			IsPendingQuit = true;
		}

		std::cout << std::endl;
	}

	void Print()
	{
		std::cout << "[ current clocks ]" << std::endl;
		for (int Row = 0; Row < 4; ++Row)
		{
			for (int Col = 0; Col < 4; ++Col)
			{
				int Index = 4 * Row + Col;
				int DisplayValue = Board[Index];
				std::cout << DisplayValue << "\t";
			}

			std::cout << std::endl;
		}
		std::cout << std::endl;
	}

private:
	std::vector<int> Board;
	const std::vector<std::vector<int>> SwitchContainer
	{
		{	0,	1,	2			},
		{	3,	7,	9,	11		},
		{	4,	10,	14,	15		},
		{	0,	4,	5,	6,	7	},
		{	6,	7,	8,	10,	12	},
		{	0,	2,	14,	15		},
		{	3,	14,	15			},
		{	4,	5,	7,	14,	15	},
		{	1,	2,	3,	4,	5	},
		{	3,	4,	5,	9,	13	}
	};
	bool IsPendingQuit;
};

int main()
{
	std::vector<std::vector<int>> Container;
	int NumberOfTestcase;
	std::cin >> NumberOfTestcase;
	for (int Index = 0; Index < NumberOfTestcase; ++Index)
	{
		std::vector<int> Testcase;
		for (int Index = 0; Index < 16; ++Index)
		{
			int Clock;
			std::cin >> Clock;
			Testcase.push_back(Clock);
		}
		Container.push_back(Testcase);
	}

	Solver S(Container);

	//std::vector<int> Board
	//{
	//	{
	//		12,	6,	6,	6,
	//		6,	6,	12, 12,
	//		12, 12, 12, 12,
	//		12, 12, 12, 12
	//	}
	//};
	///*{
	//	{
	//		12, 9,	3,	12,
	//		6,	6,	9,	3,
	//		12, 9,	12, 9,
	//		12, 12, 6,	6
	//	}
	//};*/
	//Simulator S(Board);
	//S.Loop();

	return 0;
}