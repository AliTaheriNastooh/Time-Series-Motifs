#include <iostream>
#include <ctime>
#include <cstdlib>
#include <fstream>
using namespace std;

int main()
{
  freopen("input1.txt","w",stdout);
  srand(time(NULL));
  for(int i=0; i<1000; i++)
  {
    for(int j=0; j<100; j++)
      cout<<rand()%10<<" ";
    cout<<endl;
  }
  return 0;
}
