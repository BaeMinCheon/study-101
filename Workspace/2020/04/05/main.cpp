
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
		if (IsValid(Clocks) == false)
		{
			return -1;
		}

		std::vector<int> Switches(10);
		Switches[0] = Clocks[5] + Clocks[8] + Clocks[11] - Clocks[1] - Clocks[7] - Clocks[13];
		Switches[1] = 12 - Clocks[11];
		Switches[2] = Clocks[8] - Clocks[10];
		Switches[3] = Clocks[8] - Clocks[6];
		Switches[4] = 12 - Clocks[8];
		Switches[5] = Clocks[1] - Clocks[2];
		Switches[6] = Clocks[5] + Clocks[8] + (2 * Clocks[11]) - Clocks[3] - Clocks[7] - 24;
		Switches[7] = Clocks[6] + Clocks[11] - Clocks[7] - 12;
		Switches[8] = Clocks[7] + Clocks[13] - Clocks[5] - Clocks[8] - Clocks[11] + 12;
		Switches[9] = 12 - Clocks[13];

		int HourSum = 0;
		for (int& HoursToWind : Switches)
		{
			if (HoursToWind < 0)
			{
				HoursToWind = 12 + HoursToWind;
			}

			HourSum += HoursToWind;
		}

		return HourSum / 3;
	}

	bool IsValid(const std::vector<int>& Clocks)
	{
		bool ReturnValue = true;

		if (Clocks.size() < 16)
		{
			ReturnValue = false;
		}
		else if (Clocks[8] != Clocks[12])
		{
			ReturnValue = false;
		}
		else if ((Clocks[9] - Clocks[11] - Clocks[13]) != -12)
		{
			ReturnValue = false;
		}
		else if (Clocks[14] != Clocks[15])
		{
			ReturnValue = false;
		}
		else if ((Clocks[5] + Clocks[10]) != (Clocks[4] + Clocks[8]))
		{
			ReturnValue = false;
		}
		else if ((Clocks[2] + Clocks[6] + Clocks[7] + Clocks[13] + 12) != (Clocks[0] + Clocks[5] + (2 * Clocks[8]) + Clocks[11]))
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