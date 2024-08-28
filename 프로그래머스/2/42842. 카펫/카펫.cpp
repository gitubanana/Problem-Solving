#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;

    int totalCnt = brown + yellow;
    for (int ySize = 3; ; ++ySize)
    {
        int xSize = totalCnt / ySize;
        if (xSize * ySize == totalCnt)
        {
            int brownCnt = ySize * 2 + (xSize - 2) * 2;

            if (brownCnt == brown)
            {
                answer.push_back(xSize);
                answer.push_back(ySize);
                return (answer);
            }
        }        
    }
    return answer;
}