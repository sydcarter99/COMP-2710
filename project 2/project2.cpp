/* FILE NAME: ……….
* AUTHOR: Solution Briefing
* See our syllabus for a good comment
*/
#include <iostream>
#include <stdlib.h>
#include <assert.h>
#include <cassert>
#include <ctime>
using namespace std;

/*
* Input: aaron_a indicates Aaron is alive true for alive, false for dead
* bob_a indicates Bob is alive
* charlie_a indicates Charlie is alive
* Return: true if at least two are alive otherwise return false
*/
bool at_least_two_alive(bool aaron_a, bool bob_a, bool charlie_a);
	
/*
* Call by reference
* Strategy 1: Everyone shoots to kill the highest accuracy player alive
* Input: bob_a indicates Bob is alive or dead
* charlie_a indicates Aaron is alive or dead
* Return: Change bob_a into false if Bob is killed
* Change charlie_a into false if Charlie is killed
*/
void Aaron_shoots1(bool& bob_a, bool& charlie_a);
/*
* Call by reference
* Input: aaron_a indicates Aaron is alive or dead
* charlie_a indicates Charlie is alive or dead
* Return: Change aaron_a into false if Aaron is killed
* Change charlie_a into false if Charlie is killed
*/
void Bob_shoots(bool& aaron_a, bool& charlie_a);
/*
* Call by reference
* Input: aaron_a indicates Aaron is alive or dead
* bob_a indicates Bob is alive or dead
* Return: Change aaron_a into false if Aaron is killed
* Change bob_a into false if Bob is killed
*/
void Charlie_shoots(bool& aaron_a, bool& bob_a);
/*
* Call by reference
* Strategy 2: Aaron intentionally misses if both are alive
* Input: bob_a indicates Bob is alive or dead
* charlie_a indicates Aaron is alive or dead
* Return: Change bob_a into false if Bob is killed
* Change charlie_a into false if Charlie is killed
*/
void Aaron_shoots2(bool& bob_a, bool& charlie_a);
//Simple method to implement pause function in linux
void Press_any_key(void);
//Simple method to reset the lives of everyone after a simulation
void resetLives(void);
//TEST PROTOTYPES
void test_at_least_two_alive(void);
void test_Aaron_shoots1(void);
void test_Bob_shoots(void);
void test_Charlie_shoots(void);
void test_Aaron_shoots2(void);


//VARIABLES
bool aaron_a;
bool bob_a;
bool charlie_a;
string target;
int aaronWins1 = 0;
int aaronWins2 = 0;
int bobWins = 0;
int charlieWins = 0;

//CONSTANTS
const int aProb = 33;
const int bProb = 50;
const int TOTAL_RUNS = 10000;

int main() {
	//Initializes Random number generator's seed and calls test functions
	cout << "*** Welcome to Evan's Duel Simulator ***\n";
	srand(time(0));
	test_at_least_two_alive();
	Press_any_key();
	test_Aaron_shoots1();
	Press_any_key();
	test_Bob_shoots();
	Press_any_key();
	test_Charlie_shoots();
	Press_any_key();
	test_Aaron_shoots2();
	Press_any_key();

	//Starts strategy 1 and runs 10,000 times
	cout << "Ready to test strategy 1 (run 10000 times):\n";
	Press_any_key();
	for (int i = 0; i < TOTAL_RUNS; i++) {
		aaron_a = true;
		bob_a = true;
		charlie_a = true;
		do {
			if (aaron_a) {
				Aaron_shoots1(bob_a, charlie_a);
			}
			if (bob_a) {
				Bob_shoots(aaron_a, charlie_a);
			}
			if (charlie_a) {
				Charlie_shoots(aaron_a, bob_a);
			}
		} while (at_least_two_alive(aaron_a, bob_a, charlie_a));
		if (aaron_a) {
			aaronWins1++;
		}
		if (bob_a) {
			bobWins++;
		}
		if (charlie_a) {
			charlieWins++;
		}
	}
cout << "Aaron won " << aaronWins1 << "/10000 duels or " << static_cast<double>(aaronWins1) / TOTAL_RUNS * 100 << "%\n"
<< "Bob won " << bobWins << "/10000 duels or " << static_cast<double>(bobWins) / TOTAL_RUNS * 100 << "%\n"
<< "Charlie won " << charlieWins << "/10000 duels or " << static_cast<double>(charlieWins) / TOTAL_RUNS * 100 << "%\n"
<< endl;


//Reinitializes variables and starts strategy 2 to run 10,000 times
cout << "Ready to test strategy 2 (run 10000 times):\n";
bobWins = 0; charlieWins = 0;
Press_any_key();
for (int i = 0; i < TOTAL_RUNS; i++) {
	aaron_a = true;
	bob_a = true;
	charlie_a = true;
	do {
		if (aaron_a) {
			Aaron_shoots2(bob_a, charlie_a);
		}
		if (bob_a) {
			Bob_shoots(aaron_a, charlie_a);
		}
		if (charlie_a) {
			Charlie_shoots(aaron_a, bob_a);
		}
	} while (at_least_two_alive(aaron_a, bob_a, charlie_a));
	if (aaron_a) {
		aaronWins2++;
	}
	if (bob_a) {
		bobWins++;
	}
	if (charlie_a) {
		charlieWins++;
	}
}
cout << "Aaron won " << aaronWins2 << "/10000 duels or " << static_cast<double>(aaronWins2) / TOTAL_RUNS * 100 << "%\n"
<< "Bob won " << bobWins << "/10000 duels or " << static_cast<double>(bobWins) / TOTAL_RUNS * 100 << "%\n"
<< "Charlie won " << charlieWins << "/10000 duels or " << static_cast<double>(charlieWins) / TOTAL_RUNS * 100 << "%\n"
<< endl;
if (aaronWins1 > aaronWins2) {
	cout << "Strategy 1 is better than strategy 2.\n";
}
else {
	cout << "Strategy 2 is better than strategy 1.\n";
}
Press_any_key();
return 0;
}

//Implementation of functions. Look above for documentation of them.
bool at_least_two_alive(bool aaron_a, bool bob_a, bool charlie_a) {
	if ((aaron_a && bob_a) | (bob_a && charlie_a) | (aaron_a && charlie_a)) {
		return true;
	}
	else {
		return false;
	}
}
void test_at_least_two_alive(void) {
	cout << "Unit Testing 1: Function - at_least_two_alive()\n";

	cout << "\tCase 1: Aaron alive, Bob alive, Charlie alive\n";
	assert(true == at_least_two_alive(true, true, true));
	cout << "\tCase passed ...\n";

	cout << "\tCase 2: Aaron dead, Bob alive, Charlie alive\n";
	assert(true == at_least_two_alive(false, true, true));
	cout << "\tCase passed ...\n";

	cout << "\tCase 3: Aaron alive, Bob dead, Charlie alive\n";
	assert(true == at_least_two_alive(true, false, true));
	cout << "\tCase passed ...\n";

	cout << "\tCase 4: Aaron alive, Bob alive, Charlie dead\n";
	assert(true == at_least_two_alive(true, true, false));
	cout << "\tCase passed ...\n";

	cout << "\tCase 5: Aaron dead, Bob dead, Charlie alive\n";
	assert(false == at_least_two_alive(false, false, true));
	cout << "\tCase passed ...\n";

	cout << "\tCase 6: Aaron dead, Bob alive, Charlie dead\n";
	assert(false == at_least_two_alive(false, true, false));
	cout << "\tCase passed ...\n";

	cout << "\tCase 7: Aaron alive, Bob dead, Charlie dead\n";
	assert(false == at_least_two_alive(true, false, false));
	cout << "\tCase passed ...\n";

	cout << "\tCase 8: Aaron dead, Bob dead, Charlie dead\n";
	assert(false == at_least_two_alive(false, false, false));
	cout << "\tCase passed ...\n";
}
void Aaron_shoots1(bool& bob_a, bool& charlie_a) {
	assert(true == (bob_a || charlie_a));
	int shootResult = rand() % 100;
	if (charlie_a) {
		target = "Charlie";
	}
	else {
		target = "Bob";
	}
	if (shootResult <= aProb) {
		if (target == "Bob") {
			bob_a = false;
			return;
		} else {
			charlie_a = false;
			return;
		}
	} else {
		return;
	}
}
void test_Aaron_shoots1(void) {
	cout << "Unit Testing 2: Function Aaron_shoots1(Bob_alive, Charlie_alive)\n";

	cout << "\tCase 1: Bob alive, Charlie alive\n"
		<< "\t\tAaron is shooting at Charlie\n";
	bob_a = true; charlie_a = true;
	Aaron_shoots1(bob_a, charlie_a);

	cout << "\tCase 2: Bob dead, Charlie alive\n"
		<< "\t\tAaron is shooting at Charlie\n";
	bob_a = false; charlie_a = true;
	Aaron_shoots1(bob_a, charlie_a);

	cout << "\tCase 3: Bob alive, Charlie dead\n"
		<< "\t\tAaron is shooting at Bob\n";
	bob_a = true; charlie_a = false;
	Aaron_shoots1(bob_a, charlie_a);
}
void Bob_shoots(bool& aaron_a, bool& charlie_a) {
	assert(true == (aaron_a || charlie_a));
	int shootResult = rand() % 100;
	if (charlie_a) {
		target = "Charlie";
	} else {
		target = "Aaron";
	}
	if (shootResult <= bProb) {
		if (target == "Charlie") {
			charlie_a = false;
			return;
		}
		if (target == "Aaron") {
			aaron_a = false;
			return;
		}
	} else {
		return;
	}
}
void test_Bob_shoots(void) {
	cout << "Unit Testing 3: Function Bob_shoots1(Aaron_alive, Charlie_alive)\n";

	cout << "\tCase 1: Aaron alive, Charlie alive\n"
		<< "\t\tBob is shooting at Charlie\n";
	aaron_a = true; charlie_a = true;
	Bob_shoots(aaron_a, charlie_a);

	cout << "\tCase 2: Aaron dead, Charlie alive\n"
		<< "\t\tBob is shooting at Charlie\n";
	aaron_a = false; charlie_a = true;
	Bob_shoots(aaron_a, charlie_a);

	cout << "\tCase 3: Aaron alive, Charlie dead\n"
		<< "\t\tBob is shooting at Aaron\n";
	aaron_a = true; charlie_a = false;
	Bob_shoots(aaron_a, charlie_a);
}
void Charlie_shoots(bool& aaron_a, bool& bob_a) {
	assert(true == (aaron_a || bob_a));
	if (bob_a) {
		bob_a = false;
	} else {
		aaron_a = false;
	}
	return;
}
void test_Charlie_shoots(void) {
	cout << "Unit Testing 4: Function Charlie_shoots(Aaron_alive, Bob_alive)\n";

	cout << "\tCase 1: Aaron alive, Bob alive\n"
		<< "\t\tCharlie is shooting at Bob\n";
	aaron_a = true; bob_a = true;
	Charlie_shoots(aaron_a, bob_a);

	cout << "\tCase 2: Aaron dead, Bob alive\n"
		<< "\t\tCharlie is shooting at Bob\n";
	aaron_a = false; bob_a = true;
	Charlie_shoots(aaron_a, bob_a);

	cout << "\tCase 3: Aaron alive, Bob dead\n"
		<< "\t\tCharlie is shooting at Aaron\n";
	aaron_a = true; bob_a = false;
	Charlie_shoots(aaron_a, bob_a);
}
void Aaron_shoots2(bool& bob_a, bool& charlie_a) {
	assert(true == (bob_a || charlie_a));
	int shootResult = rand() % 100;
	if (bob_a && charlie_a) {
		return;
	}
	if (charlie_a) {
		target = "Charlie";
	} else {
		target = "Bob";
	}
	if (shootResult <= aProb) {
		if (target == "Charlie") {
			charlie_a = false;
			return;
		} else {
			bob_a = false;
			return;
		}
	} else {
		return;
	}
}
void test_Aaron_shoots2(void) {
	cout << "Unit Testing 5: Function Aaron_shoots2(Bob_alive, Charlie_alive)\n";

	cout << "\tCase 1: Bob alive, Charlie alive\n"
		<< "\t\tAaron intentionally misses his first shot\n"
		<< "\t\tBoth Bob and Charlie are alive.\n";
	bob_a = true; charlie_a = true;
	Aaron_shoots2(bob_a, charlie_a);

	cout << "\tCase 2: Bob dead, Charlie alive\n"
		<< "\t\tAaron is shooting at Charlie\n";
	bob_a = false; charlie_a = true;
	Aaron_shoots2(bob_a, charlie_a);

	cout << "\tCase 3: Bob alive, Charlie dead\n"
		<< "\t\tAaron is shooting at Bob\n";
	bob_a = true; charlie_a = false;
	Aaron_shoots2(bob_a, charlie_a);
}
void Press_any_key(void) {
	cout << "Press any key to continue...";
	cin.ignore().get();
}
void resetLives(void) {
	aaron_a = true;
	bob_a = true;
	charlie_a = true;
	return;
}
