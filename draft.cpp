//#include <iostream>
//#include <string>
//#include <thread>
//#include <chrono>
//#include <random>
//#include <vector>
//#include <set>
//#include <ctime>
//#include <conio.h>
//#include <cstdlib>
//#include <fstream>
//#include <iomanip>
//
////#include <algorithm>
//
//#define RESET "\033[0m"
//#define RED "\033[31m" 
//#define GREEN "\033[32m"
//#define YELLOW "\033[33m"
//#define BLUE "\033[34m"
//#define MAGENTA "\033[35m"
//#define CYAN "\033[36m"
//#define WHITE "\033[37m"
//
//
//using namespace std;
//
//class Game
//{
//public:
//	virtual void show_statistics() = NULL;
//	virtual void play() = NULL;
//	virtual void welcome() = NULL;
//	virtual void init() = NULL;
//	virtual void reset() = NULL;
//};
//
//class MathChallenge : public Game
//{
//private:
//	string operators[3] = { "+", "-", "*" };
//	int min_value, max_value;
//	int wrong_answers = 0;
//	int correct = 0;
//	int numbers = 0;
//	int skipped = 0;
//	bool running = true;
//	int points = 0;
//	double total_time = 0;
//	bool time_up = false;
//	set<int> errors;
//
//	void welcome()
//	{
//		system("cls");
//		cout << "Welcome to the mathematical challenges game!\n";
//		this_thread::sleep_for(chrono::milliseconds(400));
//		cout << "You will be presented with a series of math problems.\n";
//		this_thread::sleep_for(chrono::milliseconds(400));
//		cout << "Enter 'n' to skip a problem at a penalty of 10 points.\n";
//		this_thread::sleep_for(chrono::milliseconds(400));
//		cout << "Enter 'q' to quit the game.\n";
//		this_thread::sleep_for(chrono::milliseconds(400));
//		cout << "Let's get started!\n";
//		this_thread::sleep_for(chrono::milliseconds(650));
//	}
//
//	void set_difficulty()
//	{
//		string mode;
//		while (true)
//		{
//			cout << "Do you want to set a difficulty for the math game? (y/n): ";
//			cin >> mode;
//			if (mode == "y")
//			{
//				cout << "Input the minimum limit: ";
//				cin >> min_value;
//				cout << "Input the maximum limit: ";
//				cin >> max_value;
//				break;
//			}
//			else if (mode == "n")
//			{
//				cout << "Default minimum and maximum range: -10 and 21\n";
//				min_value = rand() % 21 - 10;
//				max_value = rand() % 26 + min_value;
//				break;
//			}
//			else
//			{
//				cout << "Invalid input. Please enter 'y' or 'n'.\n";
//			}
//		}
//	}
//
//	void init() override
//	{
//		set_difficulty();
//	}
//
//	pair<string, int> generate_problem()
//	{
//		int left_digit = rand() % (max_value - min_value + 1) + min_value;
//		int right_digit = rand() % (max_value - min_value + 1) + min_value;
//		string op = operators[rand() % 3];
//
//		int answer;
//		if (op == "-")
//		{
//			if (right_digit < 0)
//			{
//				op = '+';
//				right_digit = abs(right_digit);
//				answer = left_digit + right_digit;
//			}
//			else
//			{
//				op = '-';
//				answer = left_digit - right_digit;
//			}
//		}
//		else if (op == "+")
//		{
//			if (right_digit < 0)
//			{
//				op = '-';
//				right_digit = abs(right_digit);
//				answer = left_digit - right_digit;
//			}
//			else
//			{
//				op = '+';
//				answer = left_digit + right_digit;
//			}
//		}
//		else
//		{
//			answer = left_digit * right_digit;
//		}
//
//		string problem = to_string(left_digit) + " " + op + " " + to_string(right_digit);
//		return make_pair(problem, answer);
//	}
//
//
//
//
//public:
//	void play()
//	{
//
//		this_thread::sleep_for(chrono::milliseconds(750));
//		auto start_time = (chrono::system_clock::now());
//
//		while (running)
//		{
//			pair<string, int> problem_answer = generate_problem();
//			numbers++;
//			while (true)
//			{
//				string user_answer;
//				cout << "Problem #" << numbers << ": " << problem_answer.first << ": ";
//				cin >> user_answer;
//				if (user_answer == "n") {
//					skipped++;
//					points -= 10;
//					break;
//				}
//				else if (user_answer == "q")
//				{
//					if (wrong_answers == 0)
//					{
//						--numbers;
//					}
//					running = false;
//					break;
//				}
//				try {
//					int user_answer_int = stoi(user_answer);
//					if (problem_answer.second == user_answer_int) {
//						cout << "\033[32mCorrect! " << "\033[0m" << " \033[33m+10\033[0m" << " points\n";
//						correct++;
//						points += 10;
//						break;
//					}
//					else
//					{
//						cout << "\033[31mOoops!\033[0m Try again! \033[33m-5\033[0m points\n";
//						points -= 5;
//						wrong_answers++;
//						errors.insert(numbers);
//					}
//				}
//				catch (invalid_argument& e)
//				{
//					cout << "Invalid output. Enter an integer. -3 points\n";
//					points -= 3;
//				}
//			}
//		}
//		auto end_time = chrono::system_clock::now();
//		chrono::duration<double> elapsed_seconds = end_time - start_time;
//		total_time = elapsed_seconds.count();
//		cout << "\nGame over!\n";
//	}
//
//	void show_statistics()
//	{
//		cout << "You have:" << endl
//			<< ' ' << correct << " correct answers" << endl
//			<< ' ' << wrong_answers << " wrong answers" << endl
//			<< ' ' << skipped << " skipped questions" << endl
//			<< ' ' << numbers << " total questions" << endl
//			<< ' ' << "in total " << total_time << " seconds." << endl;
//		if (!errors.empty()) {
//			cout << "You have errors in ";
//			for (int i : errors) {
//				cout << i << " ";
//			}
//			cout << "'s problem\n";
//		}
//		cout << "Your total game points: " << "\033[34m" << points << "\033[0m" << endl;
//		if (points < 0) {
//			cout << RED << "You lose the game :( " << RESET << endl;
//		}
//	}
//
//	void reset() override
//	{
//		correct = 0;
//		wrong_answers = 0;
//		skipped = 0;
//		numbers = 0;
//		total_time = 0;
//		errors.clear();
//		points = 0;
//		running = true;
//	}
//
//};
//
//
//class SpeedTypingTest : public Game
//{
//public:
//	int wpm = 0;
//
//
//	void welcome() override
//	{
//		system("cls");
//		cout << "Welcome to Speed Typing Test!!!" << endl;
//		cout << "Press any key to continue..." << endl;
//		cin.get();
//		system("cls");
//	}
//
//	void init() override
//	{
//		start_time = (time(0));
//	}
//
//
//	string truncateTextToConsoleWidth(const string& text, int consoleWidth)
//	{
//		return text.substr(0, consoleWidth); // Truncate text to console width
//	}
//
//	void print_text()
//	{
//		int consoleWidth = 120;
//		string truncated_text = truncateTextToConsoleWidth(target_text, consoleWidth);
//		cout << "\r";
//		cout << truncated_text << endl;
//		cout << "WPM: " << wpm << endl;
//		// Move cursor up the number of lines equal to the length of the target text
//		cout << "\x1b[" << truncated_text.length() + 1 << "A";
//		for (int i = 0; i < current_text.size(); ++i) {
//			if (current_text[i] != truncated_text[i]) {
//				cout << RED << current_text[i] << RESET;
//			}
//			else {
//				cout << GREEN << current_text[i] << RESET;
//			}
//		}
//	}
//
//	string load()
//	{
//		try {
//			ifstream file("database.txt");
//			if (!file) {
//				return "";
//			}
//
//			vector<string> sentences;
//			string line;
//			string sentence;
//
//			while (getline(file, line))
//			{
//				for (char c : line) {
//					if (c == '.') {
//						sentences.push_back(sentence);
//						sentence.clear();
//					}
//					else {
//						sentence += c;
//					}
//				}
//			}
//			if (!sentence.empty()) {
//				sentences.push_back(sentence);
//			}
//			if (sentences.empty()) {
//				return "";
//			}
//			int index = rand() % sentences.size();
//			return sentences[index];
//		}
//		catch (exception& e)
//		{
//			cout << "Error: " << e.what() << endl;
//			return "";
//		}
//	}
//	void calculate_wpm()
//	{
//		double elapsed_time = max(difftime(time(0), start_time), 1.0);
//		int correct_chars = total_chars - mistakes;
//		wpm = static_cast<int>((correct_chars / (elapsed_time / 60)) / 5);
//
//	}
//	double calculate_accuracy()
//	{
//		double accuracy = (1.0 - static_cast<double>(mistakes_for_accuracy) / total_chars) * 100;
//		return accuracy;
//	}
//	void play() override
//	{
//		print_text(); // Print text initially
//		while (true) {
//			calculate_wpm();
//			if (total_chars - mistakes == truncated_text.size()) {
//				break;
//			}
//			if (_kbhit()) {
//				char key = _getch();
//
//				if (key == 27) {
//					break;
//				}
//				if (key == '\b') {
//					if (!current_text.empty()) {
//						if (current_text.back() != truncated_text[current_text.size() - 1]) {
//							--mistakes;
//							++mistakes_for_accuracy;
//						}
//						current_text.pop_back();
//						--total_chars;
//					}
//				}
//				else if (current_text.size() < truncated_text.size()) {
//					current_text.push_back(key);
//					++total_chars;
//					if (key != truncated_text[current_text.size() - 1]) {
//						++mistakes;
//					}
//				}
//				print_text(); // Print text after key press
//			}
//			else {
//				this_thread::sleep_for(chrono::milliseconds(40));
//			}
//		}
//	}
//
//	void show_statistics() override
//	{
//		cout << "\nYour total Words Per Minute score is: " << wpm << endl;
//		cout << "Your accuracy percentage is: " << setprecision(3) << "\033[34m" << calculate_accuracy() << "%" << "\033[0m" << endl;
//	}
//
//	void reset() override
//	{
//		mistakes = 0;
//		mistakes_for_accuracy = 0;
//		total_chars = 0;
//		current_text.clear();
//		start_time = time(0);
//		target_text = load();
//		truncated_text = truncateTextToConsoleWidth(target_text, consoleWidth);
//	}
//
//private:
//	string target_text = load();
//	int consoleWidth = 120;
//	string truncated_text = truncateTextToConsoleWidth(target_text, consoleWidth);
//	string current_text;
//	int total_chars = 0;
//	int mistakes = 0;
//	int mistakes_for_accuracy = 0;
//	time_t start_time;
//	double accuracy;
//};
//
//class Quiz : public Game
//{
//	char category;
//	string rubric;
//	int score = 0;
//	int mistakes = 0;
//	int skipped = 0;
//	int corrects = 0;
//	int num_questions = 0;
//	double total_time;
//	set<int> errors;
//
//	struct Question
//	{
//		string question;
//		string options[4];
//		string answer;
//	};
//
//	vector<Question> questions;
//
//	string load_questions_category()
//	{
//		if (category == 'g')
//		{
//			rubric = "geography.txt";
//		}
//		else if (category == 'h')
//		{
//			rubric = "history.txt";
//		}
//		else if (category == 'a')
//		{
//			rubric = "arts.txt";
//		}
//		else if (category == 's')
//		{
//			rubric = "sports.txt";
//		}
//		else
//		{
//			rubric = "";
//		}
//		return rubric;
//
//
//	}
//public:
//
//	void welcome() override
//	{
//		system("cls");
//		cout << "Welcome to the Quiz!" << endl;
//		this_thread::sleep_for(chrono::milliseconds(400));
//		cout << "You wiil be presented with a series of questions with 4 options." << endl;
//		this_thread::sleep_for(chrono::milliseconds(400));
//		cout << "Let's get started!" << endl;
//	}
//
//	void init() override
//	{
//		cout << "Please select a rubric for your quiz: " << endl
//			<< "g for geography, s for sports, h for history, a for arts and culture: ";
//		cin >> category;
//		try
//		{
//			ifstream file(load_questions_category());
//			string line;
//			while (getline(file, line))
//			{
//				Question q;
//				q.question = line;
//
//				for (int i = 0; i < 4; ++i)
//				{
//					getline(file, line);
//					q.options[i] = line;
//				}
//				getline(file, line);
//				q.answer = line;
//				questions.push_back(q);
//			}
//		}
//		catch (const ifstream::failure& e)
//		{
//			cout << "Error: " << e.what() << endl;
//		}
//	}
//
//	void play() override
//	{
//		auto start_time = chrono::system_clock::now();
//		int j = 0;
//		char user_answer;
//
//		for (auto i : questions)
//		{
//			++num_questions;
//			cout << YELLOW << "Question #" << ++j << ": " << RESET << i.question << endl;
//			cout << "A) " << i.options[0] << endl;
//			cout << "B) " << i.options[1] << endl;
//			cout << "C) " << i.options[2] << endl;
//			cout << "D) " << i.options[3] << endl;
//
//			cin >> user_answer;
//			user_answer = toupper(user_answer);
//
//			if (user_answer == 'N')
//			{
//				++skipped;
//				cout << "Skipped!" << " \033[31m-3" << "\033[0m" << " points" << endl;
//				continue;
//
//			}
//
//			if (user_answer == 'Q')
//			{
//				break;
//			}
//			string user_option;
//			string correct_answers = i.answer;
//
//			switch (user_answer)
//			{
//			case 'A':
//				user_option = i.options[0];
//				break;
//			case 'B':
//				user_option = i.options[1];
//				break;
//			case 'C':
//				user_option = i.options[2];
//				break;
//			case 'D':
//				user_option = i.options[3];
//				break;
//			default:
//				user_option = " ";
//				break;
//			}
//
//
//			user_option.erase(user_option.find_last_not_of(" \n\r\t") + 1);
//
//			if (user_option == i.answer)
//			{
//				//cout << "User option: '" << user_option << "', Correct answer: '" << i.answer << "'" << endl;
//				cout << "\033[32mCorrect!" << "\033[0m";
//				cout << "\033[33m +5" << "\033[0m" << " points" << endl;
//				++corrects;
//				score += 5;
//			}
//			else
//			{
//				//cout << "User option: '" << user_option << "', Correct answer: '" << i.answer << "'" << endl;
//				cout << "\033[31mIncorrect! " << "\033[0m";
//				cout << "\033[33m-5" << "\033[0m" << " points,  ";
//				cout << "the correct answer is: " << "\033[36m" << correct_answers << "\033[0m" << endl;
//				++mistakes;
//				score -= 5;
//				errors.insert(j);
//			}
//		}
//		auto end_time = chrono::system_clock::now();
//		chrono::duration<double> duration = end_time - start_time;
//		total_time = duration.count();
//	}
//
//	void show_statistics() override
//	{
//		cout << "Your total score for quiz is: " << "\033[34m" << score << "\033[0m" << " points" << endl;
//		cout << "You got:" << endl
//			<< ' ' << corrects << " correct answers" << endl
//			<< ' ' << mistakes << " mistakes" << endl
//			<< ' ' << skipped << " skipped questions" << endl
//			<< ' ' << num_questions << " total questions" << endl
//			<< "in " << total_time << setprecision(4) << " seconds" << endl;
//
//		if (!errors.empty())
//		{
//			cout << "You have errors in: ";
//			for (int k : errors)
//			{
//				cout << k << " ";
//			}
//			cout << "questions." << endl;
//		}
//		else
//		{
//			cout << "You have" << GREEN << " no " << RESET << "errors in quiz." << endl;
//		}
//
//		if (score < 0)
//		{
//			cout << RED << "You lose the game :(" << RESET << endl;
//		}
//	}
//	void reset() override
//	{
//		questions.clear();
//		score = 0;
//		corrects = 0;
//		mistakes = 0;
//		skipped = 0;
//		num_questions = 0;
//		total_time = 0;
//	}
//};
//
//class FindNextNumber : public Game
//{
//public:
//	void welcome() override
//	{
//		system("cls");
//		cout << "Welcome to Find Next Number Game!" << endl;
//		//cout << "Which category would you choose (a for arithmetic, g for geometric): ";
//		//cin >> category;
//		cout << "How many questions would you like to play?: ";
//		cin >> num_of_questions;
//		cout << "What is the next term in the sequence?: " << endl;
//	}
//	void init() override
//	{
//		first_term_ar = rand() % 40 + 1;
//		first_term_geo = rand() % 7 + 3;
//		difference = rand() % 30 + 10;
//		ratio = rand() % 7 + 3;
//		category = rand() % 2;
//	}
//
//	void play() override
//	{
//		auto start_time = chrono::system_clock::now();
//		for (int i = 0; i < num_of_questions; i++)
//		{
//			sequence.clear();
//			init();
//			if (category == 0)
//			{
//				sequence.push_back(first_term_ar);
//			}
//			else {
//				sequence.push_back(first_term_geo);
//			}
//
//			for (int j = 0; j < 3; j++)
//			{
//				nextTerm();
//			}
//			printSequence();
//			cout << "";
//
//			string userGuess;
//			int userGuessInt;
//			cin >> userGuess;
//
//			if (userGuess == "q" or userGuess == "Q")
//			{
//				break;
//			}
//			if (userGuess == "n" or userGuess == "N")
//			{
//				cout << "Skipped. " << RED << "-3 points" << RESET << endl;
//				++skipped;
//				continue;
//			}
//
//			try
//			{
//				userGuessInt = stoi(userGuess);
//
//			}
//			catch (const exception&)
//			{
//				cout << "Error occured while converting string to int." << endl;
//
//				continue;
//			}
//
//			if (userGuessInt == getNextTerm())
//			{
//				cout << GREEN << "Correct!" << RESET << YELLOW << " +5 points. " << RESET << "The next term was " << BLUE << userGuess << RESET << "." << endl;
//				score += 5;
//				++corrects;
//			}
//			else
//			{
//				cout << RED << "Incorrect." << RESET << YELLOW << " -4 points. " << RESET << "The next term was " << BLUE << getNextTerm() << RESET << "." << endl;
//				++mistakes;
//				score -= 4;
//			}
//		}
//		auto end_time = chrono::system_clock::now();
//		chrono::duration<double> duration = end_time - start_time;
//		total_time = duration.count();
//	}
//	void show_statistics() override
//	{
//		cout << "Your total score for quiz is: " << "\033[34m" << score << "\033[0m" << " points" << endl;
//		cout << "You got:" << endl
//			<< ' ' << corrects << " correct answers" << endl
//			<< ' ' << mistakes << " mistakes" << endl
//			<< ' ' << skipped << " skipped questions" << endl
//			<< ' ' << num_of_questions << " total questions" << endl
//			<< "in " << total_time << setprecision(4) << " seconds" << endl;
//		if (score < 0)
//		{
//			cout << RED << "You lose the game :( " << RESET << endl;
//		}
//	}
//	void reset() override
//	{
//		sequence.clear();
//		score = 0;
//		corrects = 0;
//		mistakes = 0;
//		skipped = 0;
//		num_of_questions = 0;
//		total_time = 0;
//
//	}
//private:
//	void nextTerm()
//	{
//		if (category == 0)
//		{
//			sequence.push_back(sequence.back() + difference);
//		}
//		else
//		{
//			sequence.push_back(sequence.back() * ratio);
//		}
//
//	}
//
//	int getNextTerm()
//	{
//		if (category == 0)
//		{
//			return sequence.back() + difference;
//		}
//		else
//		{
//			return sequence.back() * ratio;
//		}
//
//	}
//
//	void printSequence()
//	{
//		for (int i = 0; i < sequence.size(); ++i)
//		{
//			cout << sequence[i] << " ";
//		}
//	}
//
//
//	int first_term_ar = 0;
//	int first_term_geo = 0;
//	int difference = 0;
//	int ratio = 0;
//	int num_of_questions;
//	int score = 0;
//	int corrects = 0;
//	int mistakes = 0;
//	int skipped = 0;
//	double total_time = 0;
//	int category;
//	vector<int> sequence;
//};
//
//class Player
//{
//public:
//	void play(Game* game)
//	{
//		game->welcome();
//		game->init();
//		game->play();
//		game->show_statistics();
//		game->reset();
//	}
//};
//
//void menu()
//{
//	cout << "Welcome to the Quiz Game Center! Please select a quiz game to play:\n";
//	cout << "1." << "\033[1;3;35m" << " Math Challenge" << RESET << endl;
//	cout << "2." << "\033[1;3;35m" << " Find Next Number Game" << RESET << endl;
//	cout << "3." << "\033[1;3;35m" << " Quiz" << RESET << endl;
//	cout << "4." << "\033[1;3;35m" << " Speed Typing Test" << RESET << endl;
//	cout << "5." << "\033[1;3;5;35m" << " About our team" << RESET << endl;
//	cout << "6." << "\033[1;3;35m" << " Clear the console" << RESET << endl;
//	cout << "7." << "\033[1;3;35m" << " Exit" << RESET << endl;
//}
//
//void team_members()
//{
//	cout << "\nThe members of quiz game are:" << endl
//		<< "1. Valijonov Bahodirjon" << endl
//		<< "2. Valitov Azat" << endl
//		<< "3. Yusupov Azizbek" << endl
//		<< "4. Umarov Samin" << endl
//		<< "5. Yurov Yuriy" << endl;
//}
//
//int main()
//{
//	srand(time(0));
//
//	SpeedTypingTest spt;
//	MathChallenge math;
//	Quiz quiz;
//	FindNextNumber fnn;
//
//	Player player;
//
//	bool running = true;
//	while (running)
//	{
//		menu();
//		int choice;
//		if (!(cin >> choice))
//		{
//			cin.clear();
//			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ignore the bad input
//			cout << "Invalid choice. Please try again." << endl;
//			continue;
//		}
//		switch (choice)
//		{
//		case 1:
//			player.play(&math);
//			break;
//		case 2:
//			player.play(&fnn);
//			break;
//
//		case 3:
//			player.play(&quiz);
//			break;
//		case 4:
//			player.play(&spt);
//			break;
//		case 5:
//			team_members();
//			break;
//		case 6:
//			system("cls");
//			continue;
//			break;
//		case 7:
//			cout << "Thank you for playing! Goodbye.\n";
//			running = false;
//			break;
//		default:
//			cout << "Invalid choice. Please try again.\n";
//			break;
//		}
//
//		cout << endl;
//	}
//
//
//	system("pause");
//	return 0;
//}
//
//
//
