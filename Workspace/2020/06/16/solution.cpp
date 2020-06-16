
#include <algorithm>

int solution(std::vector<int>& A)
{
    const std::size_t ArraySize = A.size();
    int ReturnValue = 0;
    if(ArraySize > 0)
    {
        std::vector<int> DiffA(ArraySize - 1);
        for(std::size_t Index = 1; Index < ArraySize; ++Index)
        {
            const int Prev = A[Index - 1];
            const int Curr = A[Index];
            const int Diff = Curr - Prev;
            DiffA[Index - 1] = Diff;
        }
        int MaxEnding = 0;
        int MaxSlice = 0;
        for(const int Diff : DiffA)
        {
            MaxEnding = std::max(0, MaxEnding + Diff);
            MaxSlice = std::max(MaxSlice, MaxEnding);
        }
        ReturnValue = MaxSlice;
    }
    return ReturnValue;
}