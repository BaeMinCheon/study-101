
#include <vector>
#include <algorithm>

int solution(vector<int> &Circles)
{
    int ReturnValue = 0;
    const int THRESHOLD = 10000000;
    std::vector<long long> LeftPoints;
    for(std::size_t Index = 0; Index < Circles.size(); ++Index)
    {
        long long Point = Index - Circles[Index];
        LeftPoints.push_back(Point);
    }
    std::sort(LeftPoints.begin(), LeftPoints.end());
    std::vector<long long> RightPoints;
    for(std::size_t Index = 0; Index < Circles.size(); ++Index)
    {
        long long Point = Index + Circles[Index];
        RightPoints.push_back(Point);
    }
    std::sort(RightPoints.begin(), RightPoints.end());
    std::size_t LeftIndex = 0;
    for(std::size_t RightIndex = 0; RightIndex < Circles.size(); ++RightIndex)
    {
        while((LeftIndex < Circles.size()) && (LeftPoints[LeftIndex] <= RightPoints[RightIndex]))
        {
            ReturnValue += LeftIndex;
            ReturnValue -= RightIndex;
            if(ReturnValue > THRESHOLD)
            {
                ReturnValue = -1;
                // break all iteration
                LeftIndex = Circles.size();
                RightIndex = Circles.size();
            }
            LeftIndex += 1;
        }
    }
    return ReturnValue;
}

O(N*log(N)) or O(N)