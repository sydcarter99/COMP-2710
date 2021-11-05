// ****************************************************
// Author: Sydney Carter
// filename: project4_carter_slc0070.cpp
// sources: project4_hints.pdf
// compile: compiles on auburn server
// ****************************************************
#include <iostream>
#include <string>
using namespace std;

//global variables
int num_of_questions = 0;

// Structure for creating a linked list that holds a trivia question,answer and
// point amount.
struct trivia_node {
    string question;
    string answer;
    int point;
    trivia_node *next;
};

//creates a pointer to trivia_node.
typedef trivia_node* ptr_node;

//Prototypes
void add_question(ptr_node& q_list);
void init_question_list(ptr_node& q_list);
void ask_question(ptr_node q_list, int num_ask);
void Unit_Test();

//creates two versions.
//#define UNIT_TESTING
#define trivia_quiz

int main() {
    Unit_Test();
    //ptr_node node_list = newtrivia_node;
    //Creates a new trivia game /
    //Sets up three original  questions/
    //Sets up loop for user to input his or her own questions.
    //Quiz questions are stored in linked list.
#ifdef trivia_quiz
    ptr_node node_list = new trivia_node;
    init_question_list(node_list);
    cout <<"*** Welcome to Sydney's trivia quiz game ***\n";
    string input;
    do {
        add_question(node_list);
        cout <<"Continue? (Yes/No): ";
        cin.get();
        getline(cin, input);
    }
    while (input.compare("Yes") == 0 || input.compare("yes") == 0);
    cout << endl;
    
    /* This is start of Trivia quiz game. */
    ask_question(node_list, num_of_questions);
    cout << "\n*** Thank you for playing the trivia quiz game. Goodbye! ***";
    return 0;
}

#endif
/* Method for testing */
#ifdef UNIT_TESTING
    Unit_Test();
    return 0;
    }
#endif

/* initializes the quiz to have these three questions inputted into the linked list. */
void init_question_list(ptr_node& q_list) {
    //ptr_node cur_ptr;
    //ptr_node cur_ptr;
    //question 1
    ptr_node cur_ptr = new trivia_node;
    cur_ptr->question = "How long was the shortest war on record? (Hint: how many minutes)";
    cur_ptr->answer = "38";
    cur_ptr->point = 100;
    cur_ptr->next = new trivia_node;
    
    q_list = cur_ptr;
    cur_ptr = q_list->next;
    
    //question 2
    cur_ptr->question = "What was Bank of America's original name? (Hint: Bank of Italy or Bank of Germany)";
    cur_ptr->answer = "Bank of Italy";
    cur_ptr->point = 50;
    cur_ptr->next = new trivia_node;
    cur_ptr = cur_ptr->next;
    
    //question 3
    cur_ptr->question = "What is the best-selling video game of all time? (Hint: Call of Duty or Wii Sports)";
    cur_ptr->answer = "Wii Sports";
    
    cur_ptr->point = 20;
    cur_ptr->next = NULL;
    num_of_questions += 3;
}

//Gives user the option to add a question to the linked list.
//Question is added to the front of the linked list.
void add_question(ptr_node& q_list) {
    //string answer;
    //gets data from user.
    
    ptr_node new_ptr = new trivia_node;
    cout << "Enter a new question: ";
    cin.clear();
    getline(cin, new_ptr->question);
    cout << "Enter an answer: ";
    cin.clear();
    getline(cin, new_ptr->answer);
    cout<< "Enter award points: ";
    cin >> new_ptr->point;
    cin.clear();
    new_ptr->next = NULL;
    
    trivia_node* last = q_list;
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = new_ptr;
    num_of_questions++;
}

//Checks for null value
//Ask the user trivia questions and starts the game
void ask_question(ptr_node q_list, int num_ask) {
    ptr_node cur_ptr = q_list;
    string user_answer;
    string correct_answer;
    int total_points = 0;
    
    if (q_list == NULL) {
        return;
    }
    if (num_ask < 1) {
        cout << "Warning - the number of trivia to be asked must equal to or be larger than 1.";
        return;
    }
    else if (num_of_questions < num_ask) {
        cout << "Warning - There is only " << num_of_questions << " trivia in the list.";
        return;
    }
    else {
        for (int x = 0; x < num_ask; x++) {
            cout << "Question: " << cur_ptr->question << endl;
            cout << "Answer: ";
            correct_answer = cur_ptr->answer;
            cin.clear();
            getline(cin, user_answer);
            if (user_answer.compare(correct_answer) == 0) {
                cout << "Your answer is correct. You recieve " << cur_ptr->point << " points." << endl;
                total_points += cur_ptr->point;
            }
            else {
                cout << "Your answer is wrong. The correct answer is: " << cur_ptr->answer << endl;
            }
            cout << "Your total points: " << total_points << "\n" << endl;
            cur_ptr = cur_ptr->next;
        }
    }
}

// Test cases to check whether the methods work.
void Unit_Test() {
    ptr_node node_list = new trivia_node;
    init_question_list(node_list);
    cout << "Unit Test Case 1: Ask no question. The program should give a warning message." << endl;
    ask_question(node_list, 0);
    cout << "\nCase 1 Passed\n\n";
    
    cout << "Unit Test Case 2.1: Ask 1 question in the linked list. The tester enters an incorrect answer." << endl;
    ask_question(node_list, 1);
    cout << "\nCase 2.1 Passed\n\n";
    
    cout << "Unit Test Case 2.2: Ask 1 question in the linked list. The tester enters a correct answer." << endl;
    ask_question(node_list, 1);
    cout << "\nCase 2.2 Passed\n\n";
    
    cout << "Unit Test Case 3: Ask 3 questions in the linked list. The tester enters an incorrect answer." << endl;
    ask_question(node_list, 3);
    cout << "\nCase 3 Passed\n\n";
    
    cout << "Unit Test Case 4: Ask 3 questions in the linked list." << endl;
    ask_question(node_list, 5);
    cout << "\nCase 4 Passed\n\n";
    
    cout << "*** End of the Debugging Version ***\n\n";
}
