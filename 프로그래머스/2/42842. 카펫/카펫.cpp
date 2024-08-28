#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;

    int ySize = 3;
    while (true)
    {
        int xSize = ySize;
        while (true)
        {
            int brownCnt = ySize * 2 + (xSize - 2) * 2;
            if (brownCnt > brown)
                break ;

            int yellowCnt = ySize * xSize - brownCnt;
            if (brown == brownCnt && yellow == yellowCnt)
            {
                answer.push_back(xSize);
                answer.push_back(ySize);
                return (answer);
            }

            ++xSize;
        }

        ++ySize;
    }
    return answer;
}