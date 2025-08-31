#include<iostream>
#include<fstream>
using std::cin;
using std::cout;
using std::endl;

#define delimiter "\n---------------------------------\n"

#define HUMAN_TAKES_PARAMETERS const std::string& last_name, const std::string first_name, int age
#define HUMAN_GIVE_PARAMETERS last_name, first_name, age


class Human
{
	static const int TYPE_WIDTH = 12;
	static const int NAME_WIDTH = 12;
	static const int AGE_WIDTH = 5;
	static int count; //	 Объявление статической переменной

	std::string last_name;
	std::string first_name;
	int age;

public:
	static int get_count() {
		return count;
	}
	const std::string& get_last_name()const {
		return last_name;
	}
	const std::string& get_first_name()const {
		return first_name;
	}
	int get_age()const {
		return age;
	}

	void set_last_name(const std::string& last_name) {
		this->last_name = last_name;
	}
	void set_first_name(const std::string& first_name) {
		this->first_name = first_name;
	}
	void set_age(int age) {
		this->age = age;
	}

	//			Constructors:

	Human(HUMAN_TAKES_PARAMETERS) {
		set_last_name(last_name);
		set_first_name(first_name);
		set_age(age);
		count++;
		cout << "HConstructor:\t" << this << endl;
	}

	virtual ~Human() {
		count--;
		cout << "HDestructor:\t" << this << endl;
	}

	//				Methods:

	virtual std::ostream& info(std::ostream& os)const	//Base class
	{
		os.width(TYPE_WIDTH);	// Метод width(N) задает размер поля, в которое будет выведено значение
		os << std::left;	//
		os << std::string(strchr(typeid(*this).name(), ' ') + 1) + ":"; //strchr(const char* str, char symbol);
		// в указанной строке (str) находят указанный символ (symbol), и возвращает указатель на найденный
		// символ (symbol), или 'nullptr', если указанный символ отсутствует в указанной строке.
		//return os << last_name << " " << first_name << " " << age;
		os.width(NAME_WIDTH);
		os << last_name;
		os.width(NAME_WIDTH);
		os << first_name;
		os.width(AGE_WIDTH);
		os << age;
		return os;
	}

};

int Human::count = 0;	//Инициализация статической переменной (относится к определению класса - Class definition)



std::ostream& operator<<(std::ostream& os, const Human& obj) {
	return obj.info(os);
}

#define STUDENT_TAKE_PARAMETERS const std::string& speciality, const std::string& group, double rating, double attendance
#define STUDENT_GIVE_PARAMETERS speciality, group, rating, attendance

class Student :public Human {
	
	static const int SPECIALITY_WIDTH = 32;
	static const int GROUP_WIDTH = 8;
	static const int RAT_WIDTH = 8;

	std::string speciality;
	std::string group;
	double rating;			//успеваемость
	double attendance;		//посещаемость
public:
	const std::string& get_speciality()const {
		return speciality;
	}
	const std::string& get_group()const {
		return group;
	}
	double get_rating()const {
		return rating;
	}
	double get_attendance()const {
		return attendance;
	}
	void set_speciality(const std::string& speciality) {
		this->speciality = speciality;
	}
	void set_group(const std::string& group) {
		this->group = group;
	}
	void set_rating(double rating) {
		this->rating = rating;
	}
	void set_attendance(double attendance) {
		this->attendance = attendance;
	}

	//			Constructors:
	Student(HUMAN_TAKES_PARAMETERS, STUDENT_TAKE_PARAMETERS) :Human(HUMAN_GIVE_PARAMETERS) {
		set_speciality(speciality);
		set_group(group);
		set_rating(rating);
		set_attendance(attendance);
		cout << "SConstructor:\t" << this << endl;
	}
	~Student() {
		cout << "SDestructor:\t" << this << endl;
	}

	//			Methods:
	std::ostream& info(std::ostream& os)const override // Derived class
	{
		//return Human::info(os) << " " << speciality << " " << group << " " << rating << " " << attendance;
		Human::info(os);
		os.width(SPECIALITY_WIDTH);
		os << speciality;
		os.width(GROUP_WIDTH);
		os << group;
		os.width(RAT_WIDTH);
		os << rating;
		os.width(RAT_WIDTH);
		os << attendance;
		return os;
	}
};

#define TEACHER_TAKES_PARAMETERS const std::string& speciality, int experiance
#define TEACHER_GIVE_PARAMETERS speciality, experiance

class Teacher :public Human
{
	static const int SPECIALITY_WIDTH = 32;
	static const int EXPERIANCE_WIDTH = 5;
	std::string speciality;
	int experiance;
public:
	const std::string& get_speciality()const {
		return speciality;
	}
	int get_experiance()const {
		return experiance;
	}
	void set_speciality(const std::string& speciality) {
		this->speciality = speciality;
	}
	void set_experience(int experiance) {
		this->experiance = experiance;
	}

	//			Constructors:


	Teacher(HUMAN_TAKES_PARAMETERS, TEACHER_TAKES_PARAMETERS) :Human(HUMAN_GIVE_PARAMETERS) {
		set_speciality(speciality);
		set_experience(experiance);
		cout << "TConstructor:\t" << this << endl;
	}
	~Teacher() {
		cout << "TDestructor:\t" << this << endl;
	}

	std::ostream& info(std::ostream& os)const override {
		//return Human::info(os) << " " << speciality << " " << experiance;
		Human::info(os);
		os.width(SPECIALITY_WIDTH);
		os << speciality;
		os.width(EXPERIANCE_WIDTH);
		os << experiance;
		return os;
	}
};

#define GRADUATE_TAKES_PARAMETERS const std::string& subject
#define GRADUATE_GIVE_PARAMETERS subject

class Graduate :public Student {
	std::string subject;
public:
	const std::string& get_subject()const {
		return subject;
	}
	void set_subject(const std::string& subject) {
		this->subject = subject;
	}

	//			Constructors:
	Graduate(HUMAN_TAKES_PARAMETERS, STUDENT_TAKE_PARAMETERS, GRADUATE_TAKES_PARAMETERS)
		:Student(HUMAN_GIVE_PARAMETERS, STUDENT_GIVE_PARAMETERS) {
		set_subject(subject);
		cout << "GConstructor:\t" << this << endl;
	}
	~Graduate() {
		cout << "GDestructor:\t" << this << endl;
	}

	//			Methods:
	std::ostream& info(std::ostream& os)const override {
		return Student::info(os) << " " << get_subject();
	}
};

//#define INHERITANCE
#define POLYMORPHISM

void main() {
	setlocale(LC_ALL, "");

#ifdef INHERITANCE
	Human human("Montana", "Antonio", 25);
	human.info();

	Student student("Pinkman", "Jessie", 22, "Chemistry", "WW_220", 95, 98);
	student.info();

	Teacher teacher("White", "Walter", 50, "Chemistry", 25);
	teacher.info();

	Graduate graduate("Schreder", "Hank", 40, "Criminalistic", "OBN", 40, 50, "How to catch Heisenberg");
	graduate.info();
#endif INHERITANCE

#ifdef POLYMORPHISM
	Human* group[] = {
new Student("Pinkman", "Jessie", 22, "Chemistry", "WW_220", 95, 98),
new Teacher("White", "Walter", 50, "Chemistry", 25),
new Graduate("Schreder", "Hank", 40, "Criminalistic", "OBN", 40, 50, "How to catch Heisenberg"),
new Student("Vercetty", "Tommy", 30, "Theft", "Vice", 98, 99),
new Teacher("Diaz", "Ricardo", 50, "Weapons distribution", 20)
	};

	std::ofstream fout("group.txt");

	for (int i = 0; i < sizeof(group) / sizeof(group[0]); i++) {
		group[i]->info(cout);
		fout << *group[i] << endl;
		cout << delimiter << endl;
	}
	cout << "Количество объектов: " << group[0]->get_count() << endl;
	cout << "Количество объектов: " << Human::get_count() << endl;

	fout.close();
	system("notepad group.txt");

	for (int i = 0; i < sizeof(group) / sizeof(group[0]); i++) {
		delete group[i];
		cout << delimiter << endl;
	}
#endif POLYMORPHISM


}



