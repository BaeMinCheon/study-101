
bool IsPalindrome(const std::string& String, std::size_t Start, std::size_t End)
{
    bool ReturnValue = true;
    if(Start < End)
    {
        std::size_t IndexToStop = (Start + End) / 2 + 1;
        for(std::size_t LeftIndex = Start, RightIndex = End; LeftIndex < IndexToStop; ++LeftIndex, --RightIndex)
        {
            if(String[LeftIndex] != String[RightIndex])
            {
                ReturnValue = false;
                break;
            }
        }
    }
    else
    {
        ReturnValue = false;
    }
    return ReturnValue;
}

int solution(std::string& String)
{
    int ReturnValue = 0;
    for(std::size_t OuterIndex = 0; OuterIndex < String.size(); ++OuterIndex)
    {
        for(std::size_t InnerIndex = 0; InnerIndex < OuterIndex; ++InnerIndex)
        {
            if(IsPalindrome(String, InnerIndex, OuterIndex))
            {
                ReturnValue += 1;
            }
        }
    }
    return ReturnValue;
}