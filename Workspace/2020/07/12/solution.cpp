
#include <limits>
#include <unordered_map>

std::vector<int> solution(std::vector<int>& A)
{
    int MaxElement = std::numeric_limits<int>::min();
    for(const int Number : A)
    {
        if(Number > MaxElement)
        {
            MaxElement = Number;
        }
    }
    
    std::unordered_map<int, int> Counts;
    for(const int Number : A)
    {
        if(Counts.find(Number) == Counts.end())
        {
            Counts[Number] = 1;
        }
        else
        {
            Counts[Number] += 1;
        }
    }
    
    std::vector<int> ReturnValue;
    for(std::size_t Index = 0; Index < A.size(); ++Index)
    {
        const int Number = A[Index];
        int DivisorCount = 0;
        int Divisor = 1;
        for(; (Divisor * Divisor) < Number; ++Divisor)
        {
            if((Number % Divisor) == 0)
            {
                DivisorCount += Counts[Divisor];
                DivisorCount += Counts[Number / Divisor];
            }
        }
        if((Divisor * Divisor) == Number)
        {
            DivisorCount += Counts[Divisor];
        }
        ReturnValue.push_back(A.size() - DivisorCount);
    }
    return ReturnValue;
}