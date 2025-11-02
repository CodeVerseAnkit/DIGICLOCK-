🕒 Digiclock

Digiclock is a console-based digital clock built in C++.
It’s not just a clock — it’s a mini time-management toolkit that includes Time & Date, Alarm, Stopwatch, and Timer, all inside your terminal.


---

📖 Overview

Digiclock displays real-time date and time, lets you set alarms, run a stopwatch, and countdown timers — all with colorful animations and smooth text effects.
It’s designed for learning, fun, and everyday utility, showcasing the power of C++ chrono, threading, and file handling.


---

⚙️ Features

🕰️ Time & Date Display – Choose between 12-hour or 24-hour format in real-time.

⏰ Alarm System – Set custom alarms with personal messages.

⏱️ Stopwatch – Start, pause, and stop timing events easily.

⏳ Timer – Countdown from any time duration with visual updates.

📜 User History – Automatically logs all your activities to a file.

💬 Smooth UI Animations – Text effects, loading bars, and colorful output using ANSI escape codes.



---

🧠 Concepts Used

chrono library for time and clock handling

thread and sleep_for() for real-time updates

fstream for user history logging

conio.h for instant keyboard input detection

ANSI color codes for console styling



---

🚀 How to Run

1. Clone or download the repository:

git clone https://github.com/<your-username>/Digiclock.git


2. Open the project folder and compile:

g++ digiclock.cpp -o digiclock


3. Run the executable:

./digiclock


---

Screenshort :-

https://github.com/CodeVerseAnkit/DIGICLOCK-/blob/main/Screenshort2.jpg



> 💡 Note:
• This project uses <conio.h>, which works best on Windows terminals.
For Linux/macOS, minor input-handling changes may be needed.
• You need to change storage path of fstream. 



---

🧾 Project Details

Property	Description

Project Name	Digiclock
Version	1.0
Author	Ankit
Language	C++
Date Created	1 November 2025
Type	Console Application
Purpose	Practice project using chrono, threading, and file handling



---

🙏 Acknowledgment

Created by Ankit with 📱, ☕, and a bit of obsession for precision timekeeping.
Feel free to fork, modify, or enhance the project — learning never stops!


---
