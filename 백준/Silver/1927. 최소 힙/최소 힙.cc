#include <iostream>
#include <queue>

//priority queue : 기본은 max_heap
//                 min_heap으로 쓸 때는 -를 곱해서 바꿔서 넣고, 뺄 때도 -를 곱해서 사용

int main(void)
{
    std::priority_queue<int>    min_heap;
    int                         cmd, test_cnt;

	std::ios::sync_with_stdio(0);
	std::cin.tie(0);

	std::cin >> test_cnt;
    while (test_cnt--)
    {
		std::cin >> cmd;
        //자연수면 -> 배열에 x라는 값을 추가
        if (cmd > 0)
            min_heap.push(-cmd);
        //0이면 -> 가장 작은 값 출력 후, 제거
        else
		{
			if (!min_heap.empty())
			{
				std::cout << -(min_heap.top());
				min_heap.pop();
			}
			else
				std::cout << 0;
			std::cout << "\n";
		}
    }
    return (0);
}
