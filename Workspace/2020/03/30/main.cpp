
#include <iostream>
#include <string>
#include <vector>
#include <map>

void Initialize(std::vector<std::string>& /*Out*/ Container)
{
    int NumberOfTestcases;
    std::cin >> NumberOfTestcases;

    for(int Index = 0; Index < NumberOfTestcases; ++Index)
    {
        std::string Testcase;
        std::cin >> Testcase;
        Container.push_back(Testcase);
    }
}

void GetSolution(std::vector<std::string>& /*Out*/ Container)
{
    std::map<std::string, char> LookupTable
    {
        {"%20", ' '},
        {"%21", '!'},
        {"%24", '$'},
        {"%25", '%'},
        {"%28", '('},
        {"%29", ')'},
        {"%2a", '*'}
    };

    for(int Row = 0; Row < Container.size(); ++Row)
    {
        const std::string& OldString = Container[Row];
        std::string NewString;

        for(int Col = 0; Col < OldString.size(); ++Col)
        {
            std::map<std::string, char>::iterator Iterator = LookupTable.end();
            std::string SubString;

            if((Col + 2) < OldString.size())
            {
                SubString = OldString.substr(Col, 3);
                Iterator = LookupTable.find(SubString);
            }

            if(Iterator == LookupTable.end())
            {
                NewString.push_back(OldString[Col]);
            }
            else
            {
                NewString.push_back(LookupTable[SubString]);
                Col += 2;
            }
        }

        Container[Row] = NewString;
    }
}

void PrintSolution(const std::vector<std::string>& Container)
{
    for(const std::string& String : Container)
    {
        std::cout << String << std::endl;
    }
}

int main()
{
    std::vector<std::string> Container;
    Initialize(Container);
    GetSolution(Container);
    PrintSolution(Container);

    return 0;
}