#include <iostream>
#include <iomanip>
#include <conio.h>
#include <fstream>
#include <thread>
#include <chrono>
#include <ctime>
using namespace std;
using namespace std::chrono;
/*
  Project: Digiclock
  Coder: Ankit
  Date : 1/11/2025
  Description: It is a simple console based digital clock with some useful features. 
*/

// * * * * * * * * * * * * * * * * *             // helper functions
// ---> back button
void back_button()
{
    char ch;
    do
    {
        cout << "  Do you want to back(y): ";
        cin >> ch;
    } while (tolower(ch) != 'y');
}
// ---> loading animation
void loading_animation()
{
    const int barWidth = 10; // no. of character in bracket
    cout << "\t\t "
         << "\033[31;1m"
         << "LOADING... "
         << "\033[0m" << endl;
    cout << "\033[36;1m";
    cout << right << setfill(' ');
    for (int percent = 0; percent <= 100; ++percent)
    {
        int filled = (percent * barWidth) / 100;

        cout << "\r\t\t[";
        for (int i = 0; i < filled; ++i)
            cout << ':';
        for (int i = filled; i < barWidth; ++i)
            cout << ' ';
        cout << "] " << setw(3) << percent << "%"; // percent aligned

        cout.flush();
        std::this_thread::sleep_for(std::chrono::milliseconds(50)); // speed
    }
    cout << "\033[0m";
    cout << "\n"
         << endl; // newline
}
// ---> loading animation 2
void loading_animation_2(string text)
{
    int dotCount = 0;

    for (int i = 0; i < 20; i++)
    {                                  // loop count adjust karo
        dotCount = (dotCount + 1) % 4; // 0,1,2,3 → cycle

        cout << "\r" << text;

        // dots print
        for (int j = 0; j < dotCount; j++)
        {
            cout << ".";
        }

        // purane dots erase karne ke liye extra spaces print karo
        cout << "   ";

        cout.flush();
        this_thread::sleep_for(200ms); // speed control
    }

    cout << endl;
}
// ---> Text animation
void text_with_animation(string text, int speed)
{
    for (char c : text)
    {
        cout << c << flush;
        this_thread::sleep_for(speed * 1ms);
    }
    cout << endl;
}

// ---> welcome message
void welcome_message()
{
    cout << "\t   ❤ \033[32;1;4mWELCOME TO DIGICLOCK\033[0m❤\n"
         << endl;
}
// * * * * * * * * * * * * * * * * *
// ---> UI
void menu()
{
    cout << "\n " << string(45, '-') << "\n"
         << endl;
    cout << "\033[31;1m\t\t   DIGICLOCK\033[0m\n\t\t   \033[33;1m~~~~~~~~~\033[0m\n"
         << endl;
    cout << "\t\033[33;1m1•Time and Date\t\t2•Alarm\n\t3•Stopwatch\t\t4•Timer\n\t5•Info\t\t\t6•Exit\033[0m\n"
         << endl;
    cout << "\n " << string(45, '-') << "\n"
         << endl;
}
// ---> 1. Time and Date
void time_and_date()
{
    welcome_message();
    cout << "  \033[1mChoose Clock format:-\n\t1) 24 hours\t\t2) 12hours\033[0m\n"
         << endl;

    // user input
    int time_format = 0;
    while (time_format != 1 && time_format != 2)
    {
        cout << "  Enter format: ";
        cin >> time_format;
    }
    while (true)
    {
        // clear screen
        cout << "\033[2J\033[1;1H";
        // current time
        auto sys_time = system_clock::now();
        time_t sys_time_t = system_clock::to_time_t(sys_time);
        tm *lt = localtime(&sys_time_t);
        // formatting time
        char curr_time[100];
        if (time_format == 1)
        {
            strftime(curr_time, sizeof(curr_time), "%H:%M:%S %p", lt);
        }
        else
        {
            strftime(curr_time, sizeof(curr_time), "%I:%M:%S %p", lt);
        }
        // display time
        cout << "\n\n\t\t\033[36;1m---------------\n";
        cout << "\t\t| " << curr_time << " |" << endl;
        cout << "\t\t---------------\033[0m\n";
        strftime(curr_time, sizeof(curr_time), "%A,%d,%B,%Y", lt);
        cout << "\t   \033[1;4m";
        cout << curr_time << endl;
        cout << "\033[0m\n"
             << endl;
        cout << "Press 'b' to go back: ";
        // real time input check
        if (_kbhit())
        {
            char c = _getch();
            if (tolower(c) == 'b')
                break;
        }
        cout.flush(); // buffer clear
        // sleep for 1s
        this_thread::sleep_for(1s);
    }
}

// ---> 2. Alarm
void alarm()
{
    welcome_message();
    text_with_animation("  \033[31;1;4mALARM\033[0m⏰\n", 50);
    char user;
    do
    {
        // get time and message from user
        int hour, minute, second;
        string alarm_message;
        cout << "   To set alarm, Enter Time in 12 hours\n    format(H:M:S):-" << endl;
        while (true)
        {
            cout << "  Enter hour: ";
            cin >> hour;
            if (hour >= 0 && hour <= 12)
                break;
        }
        while (true)
        {
            cout << "  Enter Minute: ";
            cin >> minute;
            if (minute >= 0 && minute <= 60)
                break;
        }
        while (true)
        {
            cout << "  Enter Second: ";
            cin >> second;
            if (second >= 0 && second <= 60)
                break;
        }
        cout << "  Enter message to print after alaram: ";
        cin.ignore();
        getline(cin, alarm_message);

        loading_animation_2("setting alarm");
        cout << "  Alarm set successfully ⏰ \n"
             << endl;
        while (true)

        {
            // current time using system_clock
            auto curr_sys_time = system_clock::now();
            time_t t = system_clock::to_time_t(curr_sys_time);
            tm *lt = localtime(&t);
            int currh = lt->tm_hour;
            if (currh > 12)
                currh -= 12;
            int currm = lt->tm_min;
            int currs = lt->tm_sec;
            string am_pm = (currh >= 12) ? "PM" : "AM";
            string curr_time = to_string(currh) + ":" + to_string(currm) + ":" + to_string(currs) + " " + am_pm;
            // \r clear screen
            cout << "\r  Current Time:  \033[1m[ " << curr_time << " ]\033[0m";
            cout << " ";
            // flush buffer
            cout.flush();

            if (currh == hour && currm == minute && currs == second)
            {
                cout << "\n\t" << alarm_message;
                break;
            }
            // printing delay
            this_thread::sleep_for(1s);
        }
        while (true)
        {
            cout << "\n  Do you want to set alarm again(y/n): ";
            cin >> user;
            if (tolower(user) == 'y' || tolower(user) == 'n')
                break;
        }
    } while (tolower(user) != 'n');
    back_button();
}
// ---> 3. stopwatch
void stopwatch()
{
    welcome_message();
    text_with_animation("  \033[31;1;4mSTOPWATCH\033[0m⏰\n", 50);
    char user;
    do
    {
        char start = 'n';
        while (tolower(start) != 'y')
        {
            cout << "  Enter Y to start stopwatch: ";
            cin >> start;
        }
        int hours = 0, minutes = 0, seconds = 0;

        while (true)
        {
            string time = (hours < 10) ? "0" + to_string(hours) : to_string(hours);
            time += ":";
            time += (minutes < 10) ? "0" + to_string(minutes) : to_string(minutes);
            time += ":";
            time += (seconds < 10) ? "0" + to_string(seconds) : to_string(seconds);
            // clear screen
            cout << "\033[2J\033[1;1H";
            // display time
            cout << "\n\n\t\t\033[33;1m------------\n";
            cout << "\t\t| " << time << " |" << endl;
            cout << "\t\t------------\033[0m\n";
            // update time
            seconds++;
            if (seconds >= 60)
            {
                seconds = 0;
                minutes++;
            }

            if (minutes >= 60)
            {
                minutes = 0;
                hours++;
            }

            if (hours >= 12)
            {
                break;
            }
            cout << "\n\n  Enter 's'to stop and 'p'to pause: ";
            if (_kbhit())
            {
                char c = _getch();
                if (tolower(c) == 's')
                {
                    break;
                }
                if (tolower(c) == 'p')
                {
                    cout << "\n  Press 'r' to resume: ";
                    char resume = _getch();
                }
            }
            cout.flush();
            this_thread::sleep_for(1s);
        }
        cout << "\n  Final time: " << hours << ":" << minutes << ":" << seconds << endl;
        while (true)
        {
            cout << "  Do you want to start again(y/n): ";
            cin >> user;
            if (tolower(user) == 'y' || tolower(user) == 'n')
                break;
        }
    } while (tolower(user) != 'n');
    back_button();
}
// ---> 4.Timer
void timer()
{
    welcome_message();
    text_with_animation("  \033[31;1;4mTIMER\033[0m⏰\n", 50);
    char user;
    do
    {
        // get time from user
        int min, sec;
        cout << "  To set timer,Enter minutes and seconds:-" << endl;
        while (true)
        {
            cout << "  Enter minute: ";
            cin >> min;
            if (min >= 0 && min <= 60)
                break;
        }
        while (true)
        {
            cout << "  Enter second: ";
            cin >> sec;
            if (sec >= 0 && sec <= 60)
                break;
        }
        int total_time = (min != 0) ? min * 60 : 0;
        total_time += sec;
        // show timer
        for (int i = total_time; i >= 0; i--)
        {
            cout << "\r\t\033[1mTIMER: [ 0:" << min << ":" << sec << " ]\033[0m";
            cout << " ";
            cout.flush();
            min = (i % 60 == 0) ? --min : min;
            sec = (sec == 0) ? 59 : --sec;
            this_thread::sleep_for(1s);
        }

        text_with_animation("\n   \033[33;1mTIME UP \033[0m 📍", 50);
        while (true)
        {
            cout << "\n  Do you want to use timer again(y/n): ";
            cin >> user;
            if (tolower(user) == 'y' || tolower(user) == 'n')
                break;
        }
    } while (tolower(user) != 'n');
    back_button();
}
void info();                     //only declaration
void user_history(string track); // history
int main()
{
    cout << "\n\n\n\n\n"
         << endl;
    loading_animation();
    cout << "\033[2J\033[H";

    char input;
    do
    {
        menu();
        // input
        while (true)
        {
            cout << "  INPUT: ";
            cin >> input;
            if (input >= '1' && input <= '6')
                break;
        }
        // switch cases
        switch (input)
        {
        case '1':
            user_history(" use of time and date");
            time_and_date();
            break;
        case '2':
            user_history(" use of alarm");
            alarm();
            break;
        case '3':
            user_history(" use of stopwatch");
            stopwatch();
            break;
        case '4':
            user_history(" use of timer");
            timer();
            break;
        case '5':
            user_history(" visit info feature");
            info();
            break;
        case '6':
            cout << "\t     😁  \033[36;1;4mTHANKS FOR VISIT\033[0m 😁\n"
                 << endl;
            loading_animation_2("  Exiting");
            break;
        default:
            cout << "  Invalid Input" << endl;
        }
        if (input != '6')
            cout << "\033[2J\033[H";
    } while (input != '6');
    return 0;
}

// ---> 5. information about project
void info()
{
    welcome_message();
    text_with_animation("  \033[36;1;4mInformation about this project \033[0m👨‍💻\n", 50);
    cout << left << setw(14) << "  Project"
         << ": Digiclock\n"
         << setw(14) << "  Version"
         << ": 1.0\n"
         << left << setw(14) << "  Coder"
         << ": Ankit\n"
         << setw(14) << "  Date"
         << ": 1/11/2025\n"
         << setw(14) << "  Features"
         << ": Time, Date, Alarm, Timer,\n\t\tand Stopwatch.\n"
         << setw(14) << "  Description"
         << ": It is a simple console based\n\t\tdigital clock with some\n\t\tuseful features.\n"
         << endl;
    text_with_animation("\t🙏 \033[35;1mThanks for visit\033[0m🙏\n", 50);
    back_button();
}
// ---> track user activities
void user_history(string track)
{
    // log file for store user history for future use
    ofstream ofs("/sdcard/Coding.cpp/PROJECT/digiclock/user_history.txt", ios::app); //cout<<ofs.is_open();
    auto curr_sys_time = system_clock::now();
    time_t t = system_clock::to_time_t(curr_sys_time);
    tm *lt = localtime(&t);
    char time[10];
    char date[50];
    strftime(time, sizeof(time), "%H:%M:%S", lt);

    strftime(date, sizeof(date), "%A,%d,%B,%Y", lt);
    ofs << track << ":\n"
        << date << "  " << time << "\n"
        << endl;
    ofs.close();
}