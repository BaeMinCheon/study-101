
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

class Solver
{
public:
	Solver(const std::vector<int>& NewCoinValues, const int NewMoneySum)
		: CoinValues(NewCoinValues), MoneySum(NewMoneySum)
	{
		Solve();
		Print();
	}

private:
	void Solve()
	{
		Answer = GetCalculation();
	}

	/**
	 *	example: {MoneySum: 110}, {Coin: 10, 50, 100, 500}
	 *	Coin:  10 -> MoneyToCases[ 10] = 1, MoneyToCases[ 20] = 1, MoneyToCases[ 30] = 1, ...,
	 *				 MoneyToCases[ 90] = 1, MoneyToCases[100] = 1, MoneyToCases[110] = 1
	 *	Coin:  50 -> MoneyToCases[ 50] = 2, MoneyToCases[ 60] = 2, MoneyToCases[ 70] = 2, ...,
	 *				 MoneyToCases[ 90] = 2, MoneyToCases[100] = 3, MoneyToCases[110] = 3
	 *	Coin: 100 -> MoneyToCases[100] = 4, MoneyToCases[110] = 4
	 */
	int GetCalculation()
	{
		int ReturnValue = 0;
		// we need the range of [1, MoneySum] not the range of [0, MoneySum)
		std::vector<long long> MoneyToCases(MoneySum + 1, 0);
		for (int CoinIndex = 0; CoinIndex < CoinValues.size(); ++CoinIndex)
		{
			const int CoinValue = CoinValues[CoinIndex];
			if (CoinValue >= MoneyToCases.size())
			{
				break;
			}
			else
			{
				// each coin can make one case at least by it self
				MoneyToCases[CoinValue + 0] += 1;
				for (int MoneyIndex = 1; (CoinValue + MoneyIndex) <= MoneySum; ++MoneyIndex)
				{
					MoneyToCases[CoinValue + MoneyIndex] += MoneyToCases[MoneyIndex];
				}
			}
		}
		ReturnValue = MoneyToCases[MoneySum] % 1000000007;
		return ReturnValue;
	}

	void Print()
	{
		std::cout << Answer << std::endl;
	}

private:
	std::vector<int> CoinValues;
	int MoneySum;
	int Answer;
};

int main()
{
	int NumberOfTestcase;
	std::cin >> NumberOfTestcase;
	for (int Index = 0; Index < NumberOfTestcase; ++Index)
	{
		int MoneySum;
		std::cin >> MoneySum;
		int NumberOfCoins;
		std::cin >> NumberOfCoins;
		std::vector<int> CoinValues;
		for (int Index = 0; Index < NumberOfCoins; ++Index)
		{
			int CoinValue;
			std::cin >> CoinValue;
			CoinValues.push_back(CoinValue);
		}
		Solver S(CoinValues, MoneySum);
	}
	return 0;
}