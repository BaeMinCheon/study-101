#include <set>

int solution(vector<int>& Numbers)
{
    int ReturnValue = 0;
    std::set<int> NumberSet;
    for(int Number : Numbers)
    {
        NumberSet.insert(Number);
    }
    for(std::size_t Index = 0; Index < Numbers.size(); ++Index)
    {
        int Integer = Numbers[Index];
        std::set<int>::iterator Iterator = NumberSet.find(Integer);
        if(Iterator != NumberSet.end())
        {
            NumberSet.erase(Integer);
        }
        
        if(NumberSet.size() == 0)
        {
            ReturnValue = Index;
            break;
        }
    }
    return ReturnValue;
}