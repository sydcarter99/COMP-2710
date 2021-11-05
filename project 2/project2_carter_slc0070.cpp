// ======================================
// filename: project2_carter_slc0070.cpp
// author: Sydney Carter
// project: Duel Simulator
// sources: I used the Project2_hints.pdf as my source code
//          stack overflow links from Piazza
// compile: compiled with g++
// ======================================

#include <iostream>
#include <stdlib.h>
#include <assert.h>
#include <ctime>
#include <cassert>
using namespace std;

bool at_least_two_alive(bool aaronAlive, bool bobAlive, bool charlieAlive);
void Aaron_shoots1(bool& B_abobAlivelive, bool& charlieAlive);
void Bob_shoots(bool& aaronAlive, bool& charlieAlive);
void Charlie_shoots(bool& aaronAlive, bool& bobAlive);
void Aaron_shoots2(bool& bobAlive, bool& charlieAlive);
void Press_any_key(void);
bool shoot_target_result(int probability);

//TEST PROTOTYPES
void test_at_least_two_alive(void);
void test_Aaron_shoots1(void);
void test_Bob_shoots(void);
void test_Charlie_shoots(void);
void test_Aaron_shoots2(void);

//VARIABLES

const int TOTAL_RUNS = 10000;
const int aaronHitChance = 33;
const int bobHitChance = 50;
string target;
int aaronWins1 = 0;
int bobWins = 0;
int charlieWins = 0;
int aaronWins2 = 0;
bool aaronAlive = true;
bool bobAlive = true;
bool charlieAlive = true;

int main() {

    //Initializes Random number generator's seed and calls test functions
    cout << "*** Welcome to Sydney's Duel Simulator*** ";
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
    for (int i = 0; i < TOTAL_RUNS; i++ ){
        // setup duel
        aaronAlive = true;
        bobAlive = true;
        charlieAlive = true;
        while (at_least_two_alive(aaronAlive, bobAlive, charlieAlive)) {
            // Duel
            if (aaronAlive) {
                Aaron_shoots1(bobAlive, charlieAlive);
            }
            if (bobAlive) {
                Bob_shoots(aaronAlive, charlieAlive);
            }
            if (charlieAlive) {
                Charlie_shoots(aaronAlive, bobAlive);
            }
        }
        // add 1 to winner
        if (aaronAlive) {
            aaronWins1++;
        }
        if (bobAlive) {
            bobWins++;
        }
        if (charlieAlive) {
            charlieWins++;
        }
    }
    cout << "Aaron won " << aaronWins1 << "/10000 duels or " << static_cast<double>(aaronWins1) / TOTAL_RUNS * 100 << "%\n"
    << "Bob won " << bobWins << "/10000 duels or " << static_cast<double>(bobWins) / TOTAL_RUNS * 100 << "%\n"
    << "Charlie won " << charlieWins << "/10000 duels or " << static_cast<double>(charlieWins) / TOTAL_RUNS * 100 << "%\n"
    << endl;
    
    
    //Reinitializes variables and starts strategy 2 to run 10,000 times
    cout << "Ready to test strategy 2 (run 10000 times):\n";
    bobWins = 0, charlieWins = 0;
    Press_any_key();
    
    for (int i = 0; i < TOTAL_RUNS; i++) {
        // setup duel
        aaronAlive = true;
        bobAlive = true;
        charlieAlive = true;
        
        while(at_least_two_alive(aaronAlive, bobAlive, charlieAlive)) {
            // duel
            if (aaronAlive) {
                Aaron_shoots2(bobAlive, charlieAlive);
            }
            if (bobAlive) {
                Bob_shoots(aaronAlive, charlieAlive);
            }
            if (charlieAlive) {
                Charlie_shoots(aaronAlive, bobAlive);
            }
        }
        if (aaronAlive) {
            aaronWins2++;
        }
        if (bobAlive) {
            bobWins++;
        }
        if (charlieAlive) {
            charlieWins++;
        }
    }
    cout << "Aaron won " << aaronWins2 << "/10000 duels or " << static_cast<double>(aaronWins2)/TOTAL_RUNS * 100 << "%\n"
    << "Bob won " << bobWins << "/10000 duels or " << static_cast<double>(bobWins)/TOTAL_RUNS * 100 << "%\n"
    << "Charlie won " << charlieWins << "/10000 duels or " << static_cast<double>(charlieWins)/TOTAL_RUNS * 100 << "%\n"
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
   
//Implementation of functions
bool at_least_two_alive(bool aaronAlive, bool bobAlive, bool charlieAlive) {
    if ((aaronAlive && bobAlive) | (bobAlive && charlieAlive) | (aaronAlive && charlieAlive)) {
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
    
void Aaron_shoots1(bool& bobAlive, bool& charlieAlive) {
    assert(true == (bobAlive || charlieAlive));
    int shootResult = rand() % 100;
    if (charlieAlive) {
        target = "Charlie";
    }
    else {
        target = "Bob";
    }
    if (shootResult <= aaronHitChance) {
        if (target == "Bob") {
            bobAlive  = false;
            return;
        }
        else {
            charlieAlive = false;
            return;
        }
    }
    else {
        return;
    }
}

void test_Aaron_shoots1(void) {
    cout << "Init Testing 2: Function Aaron_shoots1(Bob_alive, Charlie_alive)\n";
    
    bool bob_a = false;
    bool charlie_a = true;
    cout << "\tCase 1: Bob alive, Charlie alive\n"
         << "\t\tAaron is shooting at Charlie\n";
    Aaron_shoots1(bob_a, charlie_a);
    
    bob_a = false;
    charlie_a = true;
    
    cout << "\tCase 2: Bob dead, Charlie alive\n"
         << "\t\tAaron is shooting at Charlie\n";
    Aaron_shoots1(bob_a, charlie_a);
    
    bob_a = false;
    charlie_a = true;
    
    cout << "\tCase 3: Bob alive, Charlie dead\n"
         << "\t\tAaron is shooting at Bob\n";
    Aaron_shoots1(bob_a, charlie_a);
}

void Bob_shoots(bool& aaronAlive, bool& charlieAlive) {
    assert(true == (aaronAlive || charlieAlive));
    int shootResult = rand() % 100;
    if (charlieAlive) {
        target = "Charlie";
    }
    else {
        target = "Aaron";
    }
    if (shootResult <= bobHitChance) {
        if (target == "Charlie") {
            charlieAlive = false;
            return;
        }
        if (target == "Aaron") {
            aaronAlive = false;
            return;
        }
    }
    else {
        return;
    }
}

void test_Bob_shoots(void) {
    cout << "Unit Testing 3: Function Bob_shoots1(Aaron_alive, Charlie_alive)\n";
    
    bool aaron_a = true;
    bool charlie_a = true;
    cout << "\tCase 1: Aaron alive, Charlie alive\n"
         << "\t\tBob is shooting at Charlie\n";
    Bob_shoots(aaron_a, charlie_a);
    
    aaron_a = false;
    charlie_a = true;
    cout << "\tCase 2: Aaron dead, Charlie alive\n"
         << "\t\tBob is shooting at Charlie\n";
    Bob_shoots(aaron_a, charlie_a);
    
    aaron_a = true;
    charlie_a = false;
    cout << "\tCase 3: Aaron alive, Charlie dead\n"
         << "\t\tBob is shooting at Aaron\n";
    Bob_shoots(aaron_a, charlie_a);
}

void Charlie_shoots(bool& aaronAlive, bool& bobAlive) {
    assert(true == (aaronAlive || bobAlive));
    if (bobAlive) {
        bobAlive = false;
    }
    else {
        aaronAlive = false;
    }
    return;
}

void test_Charlie_shoots(void) {
    cout << "Unit Testing 4: Function Charlie_shoots(aaronAlive, bobAlive)\n";

    bool aaron_a = true;
    bool bob_a = true;
    cout << "\tCase 1: Aaron alive, Bob alive\n"
         << "\t\tCharlie is shooting at Bob\n";
    Charlie_shoots(aaron_a, bob_a);

    aaron_a = false;
    bob_a = true;
    cout << "\tCase 2: Aaron dead, Bob alive\n"
         << "\t\tCharlie is shooting at Bob\n";
    Charlie_shoots(aaron_a, bob_a);

    aaron_a = true;
    bob_a = false;
    cout << "\tCase 3: Aaron alive, Bob dead\n"
         << "\t\tCharlie is shooting at Aaron\n";
    Charlie_shoots(aaron_a, bob_a);
}

void Aaron_shoots2(bool& bobAlive, bool& charlieAlive) {
    assert(true == (bobAlive || charlieAlive));
    int shootResult = rand() % 100;
    if (bobAlive && charlieAlive) {
        return;
    }
    if(charlieAlive) {
        target = "Charlie";
    }
    else {
        target = "Bob";
    }
    if (shootResult <= aaronHitChance) {
        if (target == "Charlie") {
            charlieAlive = false;
            return;
        }
        else {
            bobAlive = false;
            return;
        }
    }
    return;
}

void test_Aaron_shoots2(void) {
    cout << "Unit Testing 5: Function Aaron_shoots2(Bob_alive, Charlie_alive)\n";
    
    bool bob_a = true;
    bool charlie_a = true;
    cout << "\tCase 1: Bob alive, Charlie alive\n"
        << "\t\tAaron intentionally misses his first shot\n"
        << "\t\tBoth Bob and Charlie are alive.\n";
    Aaron_shoots2(bob_a, charlie_a);

    bob_a = false;
    charlie_a = true;
    cout << "\tCase 2: Bob dead, Charlie alive\n"
        << "\t\tAaron is shooting at Charlie\n";
    Aaron_shoots2(bob_a, charlie_a);

    bob_a = true;
    charlie_a = false;
    cout << "\tCase 3: Bob alive, Charlie dead\n"
        << "\t\tAaron is shooting at Bob\n";
    Aaron_shoots2(bob_a, charlie_a);
}

void Press_any_key(void) {
    cout << "Press any key to continue...";
    cin.ignore().get();
}

bool shoot_target_result(int probability) {
	int result = rand()%100;
	return result <= probability;
}
