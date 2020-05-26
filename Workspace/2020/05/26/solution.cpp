#include <algorithm>

bool IsTriplet(const long long A, const long long B, const long long C)
{
    bool ReturnValue = true;
    if((A + B) <= C)
    {
        ReturnValue = false;
    }
    if((B + C) <= A)
    {
        ReturnValue = false;
    }
    if((A + C) <= B)
    {
        ReturnValue = false;
    }
    return ReturnValue;
}

int solution(std::vector<int>& A)
{
    std::sort(A.begin(), A.end());
    int ReturnValue = 0;
    if(A.size() >= 3)
    {
        for(std::size_t Index = 0; Index < (A.size() - 2); ++Index)
        {
            if(IsTriplet(A[Index], A[Index + 1], A[Index + 2]))
            {
                ReturnValue = 1;
                break;
            }
        }
    }
    return ReturnValue;
}