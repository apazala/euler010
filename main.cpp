#include <iostream>
#include <cstdint>
#include <cmath>

using namespace std;

#define TARGET 2000000


int64_t iscompound[1 + (TARGET >> 6)];

#define baisset(ba, i) ((ba)[(i)>>6] & (1ull << ((i) & 63))) != 0
#define baisclear(ba, i) ((ba)[(i)>>6] & (1ull << ((i) & 63))) == 0
#define baset(ba, i) (ba)[(i)>>6] |= (1ull << ((i) & 63))

void fillprimes(int upperBound) {
	int i, j;

	baset(iscompound, 0);
	baset(iscompound, 1);
	int sqrtUb = sqrt(upperBound);
	for (i = 2; i <= sqrtUb; i++) {
		if (baisclear(iscompound, i)) {
			for (j = i*i; j <= upperBound; j += i) {
				baset(iscompound, j);
			}
		}
	}
}
int main(int argc, char **argv)
{
	fillprimes(TARGET);
	int64_t res = 0;
	
	for(int i = 0; i < TARGET; i++){
		if(baisclear(iscompound, i)){
			res += i;
		}
	}
	
	cout << res << endl;
	
    return 0;
}


