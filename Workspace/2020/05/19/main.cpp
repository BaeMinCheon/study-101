
int solution(std::vector<int>& A)
{
    std::vector<int> PIndices;
    std::vector<int> QSumUpTo(A.size(), 0);
    for(std::size_t Index = 0; Index < A.size(); ++Index)
    {
        if(Index != 0)
        {
            QSumUpTo[Index] = QSumUpTo[Index - 1];
        }
        if(A[Index] == 0)
        {
            PIndices.push_back(Index);
        }
        else
        {
            QSumUpTo[Index] += 1;
        }
    }
    int ReturnValue = 0;
    const size_t LastIndex = A.size() - 1;
    const int THRESHOLD = 1000000000;
    for(const int Index : PIndices)
    {
        ReturnValue += QSumUpTo[LastIndex] - QSumUpTo[Index];
        if(ReturnValue > THRESHOLD)
        {
            ReturnValue = -1;
            break;
        }
    }
    return ReturnValue;
}