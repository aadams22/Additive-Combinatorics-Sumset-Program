#include <iostream>

void getUserValues(int& n, int& d);

void allSubsets(int s, int d, int n, int **allCombos, int total);

int totalCombinations(int& k, int& n); // ( n choose k )

void printCombos(int **allCombos, int total, int d);


int main(void) {
	int n;
	int d;
	int h;
	
	getUserValues(n,d);

	int total = totalCombinations(d,n); // ( n choose k ) returns the total number of possible unique combinations

	//INITIALIZE ARRAY TO HOLD ALL UNIQUE COMBINATIONS OF Z_n
	int** allCombos = new int*[total];
	for(int i=0; i<total; ++i) {
		allCombos[i] = new int[d];
	}

	allSubsets(0, d, n, allCombos, total); // finds all unique subsets of Z_n and saves them to allCombo array

	return 0;
}

void getUserValues(int& n, int& d) {
	using namespace std;
	
	cout << "Enter n (Z_n): ";
	cin >> n;
	
	cout << "Enter d (coset size): ";
	cin >> d;

	return;
}


int totalCombinations(int& k, int& n) {
	int	_n = (2 * n) - 1 ; //to include the inverses of the integers
	int	total = 1;

	if(k > _n) {
		return 0;
	}

	for(int i=2; i<=k; i++) {
		total *= (_n+i-1);
		total /= i;
	}

	std::cout << total << std::endl;

	return total;
}


void allSubsets(int s, int d, int n, int **allCombos, int total){

	bool midLoopNotComplete = true;
	int runs = 0;

	do {
		int	count = d-1;
		for(int iterations = n-d+1-s; iterations > 0 && count < n; iterations--) {
			total--;

			for(int i=0; i<d; i++){	

				allCombos[total][i] = i;

				if (i >= 1 && i < d-1) {
					allCombos[total][i] = i+s;
				}

				if (i == d-1) {
					while (count <= allCombos[total][i-1]) {
						count++;
					}
					allCombos[total][i] = count;
				}

//				std::cout  << total << ", " << i << " :" << allCombos[total][i] << std::endl;
			} // SMALL LOOP


			printCombos(allCombos, total, d);
			std::cout << std::endl;

			count++;
		} // BIGGER LOOP

		s++;	

		if (allCombos[total][d-1] == n-1 &&  allCombos[total][d-2] == n-2 ) {
			midLoopNotComplete = false;
		}

	}while( midLoopNotComplete ); //MID LOOP

	allSubsets(s+1, d, n-1, allCombos, total); //MAIN LOOP

	return;
}



void printCombos(int **allCombos, int total, int d) {

	std::cout << "{ ";

	for(int i=0; i<d; i++){	
		std::cout << allCombos[total][i] << " ";
	}

	std::cout << "} ";
}










