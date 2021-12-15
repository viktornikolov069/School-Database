#ifndef UNIVERSITY_UI_H
#define UNIVERSITY_UI_H

class UniversityUI {
public:
	UniversityUI() = default;
	void start();

	static void stop();  // Should this be static ?

private:
	void handleInput(char choice);
	void printMenu();
	static bool _running; // Should this be static?
};


#endif // !UNIVERSITY_UI_H
