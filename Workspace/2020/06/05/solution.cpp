#include <algorithm>

struct Number
{
    Number(int NewInteger, std::size_t NewIndex)
    : Integer(NewInteger)
    , Index(NewIndex)
    {
    }
    int Integer;
    std::size_t Index;
};

int solution(std::vector<int>& A)
{
    std::vector<struct Number> Numbers;
    for(std::size_t Index = 0; Index < A.size(); ++Index)
    {
        const int Integer = A[Index];
        const struct Number NewOne(Integer, Index);
        Numbers.push_back(NewOne);
    }
    std::sort(Numbers.begin(), Numbers.end(), [](const struct Number& LHS, const struct Number& RHS)
    {
        return LHS.Integer < RHS.Integer;
    });
    const int Threshold = Numbers.size() / 2 + 1;
    int ReturnValue = -1;
    int CurrentInteger = 0;
    int CurrentCounter = 0;
    for(std::size_t Index = 0; Index < Numbers.size(); ++Index)
    {
        const struct Number& CurrentNumber = Numbers[Index];
        if(CurrentNumber.Integer == CurrentInteger)
        {
            CurrentCounter += 1;
        }
        else
        {
            CurrentCounter = 1;
            CurrentInteger = CurrentNumber.Integer;
        }
        if(CurrentCounter >= Threshold)
        {
            ReturnValue = CurrentNumber.Index;
            break;
        }
    }
    return ReturnValue;
}