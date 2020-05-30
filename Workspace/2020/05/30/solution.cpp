#include <deque>
#include <stack>

struct Fish
{
    Fish(int NewSize, int NewDirection)
    : Size(NewSize)
    , Direction(NewDirection)
    {
    }
    
    int Size;
    int Direction;
};

int solution(std::vector<int>& A, std::vector<int>& B)
{
    const std::size_t ArraySize = A.size();
    std::deque<struct Fish> Fishes;
    for(std::size_t Index = 0; Index < ArraySize; ++Index)
    {
        struct Fish Input(A[Index], B[Index]);
        Fishes.push_back(Input);
    }
    int ReturnValue = 0;
    std::stack<struct Fish> PendingFishes;
    while(Fishes.empty() == false)
    {
        const Fish& Current = Fishes.front();
        Fishes.pop_front();
        if(Current.Direction == 0)
        {
            if(PendingFishes.empty())
            {
                ReturnValue += 1;
            }
            else
            {
                const Fish& Pending = PendingFishes.top();
                PendingFishes.pop();
                if(Pending.Size > Current.Size)
                {
                    PendingFishes.push(Pending);
                }
                else
                {
                    Fishes.push_front(Current);
                }
            }
        }
        else
        {
            if(Fishes.empty())
            {
                ReturnValue += 1;
            }
            else
            {
                const Fish& Next = Fishes.front();
                Fishes.pop_front();
                if(Next.Direction == 0)
                {
                    if(Current.Size > Next.Size)
                    {
                        Fishes.push_front(Current);
                    }
                    else
                    {
                        Fishes.push_front(Next);
                    }
                }
                else
                {
                    PendingFishes.push(Current);
                    Fishes.push_front(Next);
                }
            }
        }
    }
    ReturnValue += PendingFishes.size();
    return ReturnValue;
}