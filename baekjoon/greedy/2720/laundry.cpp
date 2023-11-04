#include <iostream>

int main()
{
   int testCnt;
   int divisor[] = {25, 10, 5, 1};

   std::cin >> testCnt;
   while (testCnt--) {
       int change;
       std::cin >> change;
       for (int i = 0; i < 4; ++i) {
           std::cout << (change / divisor[i]) << '\n';
           change %= divisor[i];
       }
   }
   return 0; 
}
