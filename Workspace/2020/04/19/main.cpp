
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

class Solver
{
public:
	Solver(const std::vector<std::vector<double>>& NewContainer)
		: Testcase(NewContainer)
	{
		Solve();
		Print();
	}

private:
	void Solve()
	{
		Answer = GetAnswer();
	}

	double GetAnswer()
	{
		double ReturnValue = std::numeric_limits<double>::max();
		std::vector<bool> VisitTable(Testcase.size(), false);
		for (int Index = 0; Index < Testcase.size(); ++Index)
		{
			double Value = GetAnswerRecursive(VisitTable, Index);
			ReturnValue = std::min(Value, ReturnValue);
		}
		return ReturnValue;
	}

	double GetAnswerRecursive(std::vector<bool>& VisitTable, int CityFrom)
	{
		double ReturnValue = std::numeric_limits<double>::max();
		VisitTable[CityFrom] = true;
		if (IsComplete(VisitTable))
		{
			ReturnValue = 0.0;
		}
		else
		{
			for (int CityTo = 0; CityTo < Testcase.size(); ++CityTo)
			{
				if (VisitTable[CityTo])
				{
					continue;
				}
				else
				{
					double Value = Testcase[CityFrom][CityTo] + GetAnswerRecursive(VisitTable, CityTo);
					ReturnValue = std::min(Value, ReturnValue);
				}
			}
		}
		VisitTable[CityFrom] = false;
		return ReturnValue;
	}

	bool IsComplete(const std::vector<bool>& VisitTable)
	{
		bool ReturnValue = true;
		for (bool Visited : VisitTable)
		{
			if (Visited == false)
			{
				ReturnValue = false;
				break;
			}
		}
		return ReturnValue;
	}

	void Print()
	{
		std::cout << std::setprecision(10) << Answer << std::endl;
	}

private:
	const std::vector<std::vector<double>> Testcase;
	double Answer;
};

int main()
{
	int NumberOfTestcase;
	std::cin >> NumberOfTestcase;
	for (int Index = 0; Index < NumberOfTestcase; ++Index)
	{
		std::vector<std::vector<double>> Container;
		int TestcaseSizeSQRT;
		std::cin >> TestcaseSizeSQRT;
		for (int Row = 0; Row < TestcaseSizeSQRT; ++Row)
		{
			Container.push_back(std::vector<double>());
			for (int Col = 0; Col < TestcaseSizeSQRT; ++Col)
			{
				double Value;
				std::cin >> Value;
				Container.back().push_back(Value);
			}
		}
		Solver S(Container);
	}
	return 0;
}