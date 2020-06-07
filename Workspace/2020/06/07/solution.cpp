#include <unordered_map>
#include <limits>

int solution(std::vector<int>& A)
{
    std::unordered_map<int, int> Counts;
    for(const int Integer : A)
    {
        if(Counts.find(Integer) == Counts.end())
        {
            Counts[Integer] = 0;
        }
        else
        {
            Counts[Integer] += 1;
        }
    }
    int MaxCount = 0;
    int MaxCountInteger = std::numeric_limits<int>::min();
    for(const std::pair<int, int>& Pair : Counts)
    {
        if(Pair.second > MaxCount)
        {
            MaxCount = Pair.second;
            MaxCountInteger = Pair.first;
        }
    }
    int ReturnValue = 0;
    if(A.empty() == false)
    {
        std::vector<int> LeaderCounts(A.size(), 0);
        if(A[0] == MaxCountInteger)
        {
            LeaderCounts[0] = 1;
        }
        for(std::size_t Index = 1; Index < A.size(); ++Index)
        {
            int LastCount = LeaderCounts[Index - 1];
            int NewCount = LastCount;
            if(A[Index] == MaxCountInteger)
            {
                NewCount += 1;
            }
            LeaderCounts[Index] = NewCount;
        }
        const int MaxCount = LeaderCounts.back();
        for(std::size_t Index = 0; Index < LeaderCounts.size(); ++Index)
        {
            const std::size_t LeftCount = LeaderCounts[Index];
            const std::size_t LeftSize = Index + 1;
            const bool IsLeftSatisfy = LeftCount > (LeftSize / 2);
            const std::size_t RightCount = MaxCount - LeftCount;
            const std::size_t RightSize = LeaderCounts.size() - LeftSize;
            const bool IsRightSatisfy = RightCount > (RightSize / 2);
            if(IsLeftSatisfy && IsRightSatisfy)
            {
                ReturnValue += 1;
            }
        }
    }
    return ReturnValue;
}