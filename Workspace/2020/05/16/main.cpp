int solution(std::vector<int>& A)
{
	std::vector<int> SumUpTo(A.size(), 0);
	if (A.size() > 0)
	{
		SumUpTo[0] = A[0];
	}
	for (std::size_t Index = 1; Index < A.size(); ++Index)
	{
		SumUpTo[Index] = SumUpTo[Index - 1] + A[Index];
	}
	const float MAX_VALUE_OF_N = 10000.0f;
	float MinDividedSum = MAX_VALUE_OF_N;
	std::size_t MinIndex = 0;
	std::size_t MaxDistance = (A.size() < 3) ? (A.size() - 1) : 3;
	for (std::size_t Distance = 1; Distance <= MaxDistance; ++Distance)
	{
		for (std::size_t Index = 0; Index < (A.size() - Distance); ++Index)
		{
			const std::size_t StartIndex = Index;
			const std::size_t EndIndex = Index + Distance;
			const float SumFromStartToEnd = SumUpTo[EndIndex] - ((StartIndex == 0) ? 0 : SumUpTo[StartIndex - 1]);
			const float DividedSum = SumFromStartToEnd / (Distance + 1);
			if (DividedSum < MinDividedSum)
			{
				MinDividedSum = DividedSum;
				MinIndex = Index;
			}
		}
	}
	int ReturnValue = MinIndex;
	return ReturnValue;
}