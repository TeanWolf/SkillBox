#include <iostream>
#include <string>
#include <algorithm>
#include <windows.h>
#include <regex>
#include <map>
using namespace std;

map<string, string> database = { 
	{"(hello| привет | hi)", "Привет человек"}, 
{"(how are you | как ты| как дела)", "I wand to destroy you"}, 
{"(what are you doing | что делаешь)", "Answering to you"},
{"(fuck | блять | бля)", "Ne materis,Mudak"}
};

void to_lower(string &text)
{
	transform(text.begin(), text.end(), text.begin(), ::tolower);
}

void botSay(string text)
{
	cout << "[BOT]:" << text << endl;
}

string userAsk()
{
	string que;
	cout << "[USER]:";
	getline(cin, que);
	to_lower(que);
	return que;
}

int main()
{
	setlocale(LC_ALL, "RUS");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	string que;
	regex helloTemplate;
	regex nameTemplate;
	while (que != "пока")
	{
		int answersCount = 0;
		que = userAsk();
		for (auto entry : database)
		{
			regex regularExpression = regex(".*" + entry.first + ".*");
			if (regex_match(que, regularExpression))
			{
				botSay(entry.second);
				answersCount++;
			}
		}
		if (answersCount == 0)
		{
			cout << "Ya ne znay" << endl;
		}
		if (answersCount >= 3)
		{
			cout << "Sorry for the long reply" << endl;
		}
		/*helloTemplate=regex(".*hello.*");
		nameTemplate = regex(".*what.* is.* your.* name");
		if (regex_match(que, helloTemplate))
		{
			cout << "Привет человек"<<"\n";
		}
		else if (regex_match(que, nameTemplate))
		{
			cout << "Меня зовут чат-бот"<<"\n";
		}
		else
		{
			cout << "Я вас не понял"<<"\n";
		}*/
	}
	return 0;
}
