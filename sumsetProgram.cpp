#include <iostream>
#include <math.h>

void getUserValues(int& n, int& d, int& h);

void allSubsets(int runs, int s, int d, int n, int **allCombos, int total);

int totalCombinations(int n, int k); // ( n choose k )

void printCombos(int **allCombos, int total, int d);

void hFoldSumsets(int h, int d, int n, int **allCombos, int **allHFold, int total, int hFoldTotal);


int main(void) {
    int n = 0;
    int d = 0;
    int h = 0;

    getUserValues(n,d,h); //gets user values for calculations

    int total = totalCombinations(n,d); // ( n choose k ) returns the total number of possible unique combinations

    //INITIALIZE ARRAY TO HOLD ALL UNIQUE COMBINATIONS OF Z_n: 2d: nxd 
    int** allCombos = new int*[total];
    for(int i=0; i<total; ++i) {
        allCombos[i] = new int[d];
    }

    allSubsets(0, 0, d, n, allCombos, total); // finds all unique subsets of Z_n and saves them to allCombo array

	//int r = 2*d; //to include repetitions (( r choose k )) 
	int hFoldTotal = pow(d,h);
	std::cout << hFoldTotal;
//	hFoldSumsets(h,d,n,allCombos,allHFold,total,hFoldTotal);

    return 0;
}

void getUserValues(int& n, int& d, int& h) {
    using namespace std;
	
    cout << "Enter n (Z_n): ";
    cin >> n;

    cout << "Enter d (coset size): ";
    cin >> d;
	
	cout << "Enter h (h-fold sumset): ";
	cin >> h;	
    return;
}


int totalCombinations(int n, int k) {
	int total = 1;

    if(k > n) {
        return 0;
    }

    for(int i=1; i<=k; i++) {
        total *= (n+1-i);
		total /= i;
    }

	std::cout << "total: " << total;

	return total;

}


void allSubsets(int runs, int s, int d, int n, int **allCombos, int total){

    bool midLoopNotComplete = true; //triggered when the iteraitons through the midloop are complete

	if (total == 0) { //base case when total number of combinations have been found, function returns
		return;
	}

	do {
        int count = d-1; //for last line increments, it will always begin at d-1
        for(int iterations = n-d+1-s; iterations > 0 && count < n; iterations--) {
		    total--; //decrements the total number of combinations

        for(int i=0; i<d; i++){	

            allCombos[total][i] = runs; // LINE 1 

		    if (i >= 1 && i < d-1) { // ALL LINES in range [2,d-1]
                allCombos[total][i] = i+s;
            }

            if (i == d-1) { // LAST LINE

				//removes all possible duplicates. ex: { 1 2 2 } will not be printed
                while (count <= allCombos[total][i-1]) {
                    count++;
                }
                allCombos[total][i] = count;
            }

        } // SMALL LOOP

            printCombos(allCombos, total, d); //prints all combinations found
            std::cout << std::endl;

            count++;
        } // BIGGER LOOP

	    s++; //increments addition element for midloop increments	

		
        if (allCombos[total][d-1] == n-1 &&  allCombos[total][d-2] == n-2 ) {
            midLoopNotComplete = false; //When the final two elements in any combination of length d are n-1 and n-2, the mid loop is now complete
        }

    }while( midLoopNotComplete ); //MID LOOP

    runs++;
    allSubsets(runs, runs, d, n, allCombos, total); //MAIN LOOP

    return;
}


//PRINTS COMBINATIONS: { a b .... z }
void printCombos(int **allCombos, int total, int d) {

    std::cout << "{ ";

    for(int i=0; i<d; i++){	
	    std::cout << allCombos[total][i] << " ";
    }

    std::cout << "} ";
}


void hFoldSumsets(int h, int d, int n, int **allCombos, int **allHFold, int total, int hFoldTotal) {

	if(total == 0) {
		return;
	}
	
	for(int i=0; i<=hFoldTotal; i++) {
				
	}

	//hFoldSumsets(h,d,n,allCombos,allHFold,total--,hFoldTotal);

}








