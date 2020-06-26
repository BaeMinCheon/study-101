#include <cmath>

int solution(std::vector<int>& A)
{
    const std::size_t ArraySize = A.size();
    if(ArraySize < 3)
    {
        return 0;
    }
    std::vector<std::size_t> PeakIndices;
    for(std::size_t Index = 1; Index < (ArraySize - 1); ++Index)
    {
        const int Prev = A[Index - 1];
        const int Curr = A[Index + 0];
        const int Next = A[Index + 1];
        if((Prev < Curr) && (Curr > Next))
        {
            PeakIndices.push_back(Index);
        }
    }
    if(PeakIndices.empty())
    {
        return 0;
    }
    const std::size_t Distance = PeakIndices.back() - PeakIndices.front();
    const std::size_t FlagNumberMax = std::sqrt(Distance) + 1;
    int ReturnValue = 0;
    for(std::size_t TargetNumber = FlagNumberMax; TargetNumber > 0; --TargetNumber)
    {
        std::size_t PossibleNumber = 1;
        std::size_t PeakIndex = PeakIndices.front();
        for(std::size_t Index = 1; Index < PeakIndices.size(); ++Index)
        {
            if((PeakIndices[Index] - PeakIndex) >= TargetNumber)
            {
                PeakIndex = PeakIndices[Index];
                PossibleNumber += 1;
            }
        }
        if(PossibleNumber >= TargetNumber)
        {
            ReturnValue = TargetNumber;
            break;
        }
    }
    return ReturnValue;
}