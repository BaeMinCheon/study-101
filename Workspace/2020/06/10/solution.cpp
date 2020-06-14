int solution(std::vector<int>& A)
{
	const std::size_t ArraySize = A.size();
	int ReturnValue = 0;
	if (ArraySize > 3)
	{
		std::vector<int> LeftMaxs(ArraySize, 0);
		for (std::size_t Index = 1; Index < (ArraySize - 1); ++Index)
		{
			const int Candidate1 = LeftMaxs[Index - 1] + A[Index];
			const int Candidate2 = 0;
			LeftMaxs[Index] = Candidate1 > Candidate2 ? Candidate1 : Candidate2;
		}
		std::vector<int> RightMaxs(ArraySize, 0);
		for (std::size_t Index = ArraySize - 2; Index > 0; --Index)
		{
			const int Candidate1 = RightMaxs[Index + 1] + A[Index];
			const int Candidate2 = 0;
			RightMaxs[Index] = Candidate1 > Candidate2 ? Candidate1 : Candidate2;
		}
		for (std::size_t Index = 1; Index < (ArraySize - 1); ++Index)
		{
			const int Candidate1 = LeftMaxs[Index - 1] + RightMaxs[Index + 1];
			const int Candidate2 = ReturnValue;
			ReturnValue = Candidate1 > Candidate2 ? Candidate1 : Candidate2;
		}
	}
	return ReturnValue;
}