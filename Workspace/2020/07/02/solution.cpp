#include <cmath>

int solution(std::vector<int>& A)
{
    int ReturnValue = 0;
    const std::size_t ArraySize = A.size();
    if(ArraySize < 3)
    {
        return ReturnValue;
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
        return ReturnValue;
    }
    for(std::size_t TargetNumber = ArraySize; TargetNumber > 0; --TargetNumber)
    {
        if((ArraySize % TargetNumber) != 0)
        {
            continue;
        }
        const std::size_t Offset = ArraySize / TargetNumber;
        std::size_t PossibleNumber = 0;
        for(std::size_t PeakIndex : PeakIndices)
        {
            const std::size_t NthBlock = PeakIndex / Offset;
            if(NthBlock == PossibleNumber)
            {
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