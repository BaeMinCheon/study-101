#include <stack>

int solution(std::vector<int>& H)
{
    int ReturnValue = 0;
    std::stack<int> Heights;
    for(const int Height : H)
    {
        if(Heights.empty())
        {
            Heights.push(Height);
            ReturnValue += 1;
        }
        else
        {
            const int Top = Heights.top();
            if(Height == Top)
            {
                // do nothing
            }
            else
            {
                if(Height > Top)
                {
                    Heights.push(Height);
                    ReturnValue += 1;
                }
                else
                {
                    int Top = Heights.top();
                    while(Heights.empty() == false)
                    {
                        Top = Heights.top();
                        if(Height < Top)
                        {
                            Heights.pop();
                        }
                        else
                        {
                            break;
                        }
                    }
                    if(Height != Top)
                    {
                        Heights.push(Height);
                        ReturnValue += 1;
                    }
                }
            }
        }
    }
    return ReturnValue;
}