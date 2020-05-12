#include <unordered_map>

std::vector<int> solution(std::string& S, std::vector<int>& P, std::vector<int>& Q)
{
	std::unordered_map<char, int> ImpactFactorMap
	{
		{'A', 0},
		{'C', 1},
		{'G', 2},
		{'T', 3}
	};
	std::vector<int> ImpactFactors(S.size());
	for (std::size_t Index = 0; Index < S.size(); ++Index)
	{
		ImpactFactors[Index] = ImpactFactorMap[S[Index]];
	}
	std::vector<std::vector<int>> ImpactFactorCounts(ImpactFactorMap.size(), std::vector<int>(S.size(), 0));
	if (ImpactFactors.size() > 0)
	{
		const int ImpactFactor = ImpactFactors[0];
		ImpactFactorCounts[ImpactFactor][0] = 1;
	}
	for (std::size_t Index = 1; Index < S.size(); ++Index)
	{
		const int ImpactFactor = ImpactFactors[Index];
		for(std::vector<int>& ImpactFactorCount : ImpactFactorCounts)
		{
			ImpactFactorCount[Index] = ImpactFactorCount[Index - 1];
		}
		ImpactFactorCounts[ImpactFactor][Index] += 1;
	}
	std::vector<int> ReturnValue(P.size());
	for (std::size_t Index = 0; Index < P.size(); ++Index)
	{
		const std::size_t StartIndex = P[Index];
		const std::size_t EndIndex = Q[Index];
		for (std::size_t ImpactFactor = 0; ImpactFactor < ImpactFactorMap.size(); ++ImpactFactor)
		{
			const int FormerCount = (StartIndex > 0) ? ImpactFactorCounts[ImpactFactor][StartIndex - 1] : 0;
			const int LaterCount = ImpactFactorCounts[ImpactFactor][EndIndex];
			const int ImpactFactorCount = LaterCount - FormerCount;
			if (ImpactFactorCount > 0)
			{
				ReturnValue[Index] = ImpactFactor + 1;
				break;
			}
		}
	}
	return ReturnValue;
}