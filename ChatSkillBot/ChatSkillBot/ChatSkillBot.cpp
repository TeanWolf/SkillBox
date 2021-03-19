#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <string>
#include <Windows.h>
#include <regex>
using namespace std;

map<string, string> dataBase =
{
	{"(привет|hello|hi)", "Привет, человек!"},
{"(как ты?|как дела?|how are you?)", "Отлично!"},
{"(что делаешь?|what are you doing?)", "Отвечаю на глупые вопросы"},
{"(что ты умеешь?|что ты можешь?|what can you do?)", "Список того, что я умею:\n1.Рассказываю о своих делах\n2.Рассказываю, что я делаю сейчас\n3.Не даю тебе чувствовать себя одиноко!"},
{"(пока|goodbye)", "Пока, человек! Скоро увидимся!"},
{"(блять|бля|fuck)", "Ne materis, Mudak"}
};

void toLower(string &que)
{
	transform(que.begin(), que.end(), que.begin(), ::tolower);
}

void userAsk(string &que)
{
	cout << "[USER]:";
	getline(cin, que);
	toLower(que);
}

void botSay(string text)
{
	cout << "[BOT]:"<<text << endl;
	cout << endl;
}

int main()
{
	setlocale(LC_ALL, "RUS");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	string que;
	do
	{
		userAsk(que);
		int answerCount = 0;
		for (auto enter : dataBase)
		{
			regex regexExpression = regex(".*" + enter.first + ".*");
			{
				if (regex_match(que, regexExpression))
				{
					botSay(enter.second);
					answerCount++;
                }
			}
		}
		if (answerCount == 0 && que != "пока")
		{
			botSay("Я вас не понимаю!");
		}
		else if (answerCount >= 3)
		{
			botSay("Прости, что долго отвечаю! Слишком много запросов");
		}
	} while (que != "пока");
	return 0;
}
