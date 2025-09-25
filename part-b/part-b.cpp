#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

/*******************************************************************************
 * Function prototype
*******************************************************************************/

void towerHanoi(int, string, string, string, int&);

/*******************************************************************************
 * Description:
 * Starting point of the program. Calls a function to recursively determine
 * solutions for the first 5 instances of the Tower of Hanoi problem.
 * 
 * Input:
 * N/A
 *
 * Output:
 * An integer to signal to the OS the exit code.
*******************************************************************************/

int main() {
    // solve the first 5 cases of the Tower of Hanoi problem
    for (int i = 1, numMoves = 0; i <= 5; i++, numMoves = 0) {
        cout << setfill('-') << setw(40) << "" << endl;
        cout << "Trying n = " << i << endl << endl;
        towerHanoi(i, "Rod #1", "Rod #2", "Rod #3", numMoves);
        cout << endl << "Number of Moves = " << numMoves << endl;
    }

    // terminate
    return 0;
}

void towerHanoi(int n, string fromRod, string toRod, string auxRod, int& numMoves) {
    if (n == 1) {
        cout << "Move disk 1 from " << fromRod << " to " << toRod << endl;
        numMoves++;
        return;
    }

    towerHanoi(n - 1, fromRod, auxRod, toRod, numMoves);
    cout << "Move disk " << n << " from " << fromRod << " to " << toRod << endl;
    numMoves++;
    towerHanoi(n - 1, auxRod, toRod, fromRod, numMoves);
}