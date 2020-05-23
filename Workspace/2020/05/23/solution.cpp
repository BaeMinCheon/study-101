#include <algorithm>
#include <limits>

int solution(std::vector<int>& A)
{
    int ReturnValue = std::numeric_limits<int>::min();
    std::sort(A.begin(), A.end());
    std::vector<int> ElementsToCheck;
    if(A.size() >= 6)
    {
        for(std::size_t Index = 0; Index < 3; ++Index)
        {
            ElementsToCheck.push_back(A[Index]);
        }
        for(std::size_t Index = 0; Index < 3; ++Index)
        {
            const size_t LastIndex = A.size() - 1;
            ElementsToCheck.push_back(A[LastIndex - Index]);
        }
    }
    else
    {
        for(std::size_t Index = 0; Index < A.size(); ++Index)
        {
            ElementsToCheck.push_back(A[Index]);
        }
    }
    for(std::size_t PIndex = 0; PIndex < ElementsToCheck.size(); ++PIndex)
    {
        for(std::size_t QIndex = PIndex + 1; QIndex < ElementsToCheck.size(); ++QIndex)
        {
            for(std::size_t RIndex = QIndex + 1; RIndex < ElementsToCheck.size(); ++RIndex)
            {
                const int Tuple = ElementsToCheck[PIndex] * ElementsToCheck[QIndex] * ElementsToCheck[RIndex];
                if(Tuple > ReturnValue)
                {
                    ReturnValue = Tuple;
                }
            }
        }
    }
    return ReturnValue;
}