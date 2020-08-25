std::vector<int> solution(int N, std::vector<int>& P, std::vector<int>& Q)
{
	std::vector<int> Primes = { 2 };
	for (int Number = 3; Number <= N; ++Number)
	{
		bool IsPrime = true;
		for (const int Prime : Primes)
		{
			if ((Number % Prime) == 0)
			{
				IsPrime = false;
				break;
			}
		}
		if (IsPrime)
		{
			Primes.push_back(Number);
		}
	}

	std::vector<int> NumberOfSemiprimeUpto(N + 1);
	for (const int LeftPrime : Primes)
	{
		for (const int RightPrime : Primes)
		{
			const int Semiprime = LeftPrime * RightPrime;
			if (Semiprime > N)
			{
				break;
			}
			else
			{
				NumberOfSemiprimeUpto[Semiprime] = 1;
			}
		}
	}
	for (std::size_t Index = 1; Index < NumberOfSemiprimeUpto.size(); ++Index)
	{
		NumberOfSemiprimeUpto[Index] += NumberOfSemiprimeUpto[Index - 1];
	}

	const std::size_t ArraySize = P.size();
	std::vector<int> ReturnValue;
	for (std::size_t Index = 0; Index < ArraySize; ++Index)
	{
		const std::size_t From = P[Index] - 1;
		const std::size_t To = Q[Index];
		const int Result = NumberOfSemiprimeUpto[To] - NumberOfSemiprimeUpto[From];
		ReturnValue.push_back(Result);
	}

	return ReturnValue;
}