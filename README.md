# BlackJack-cpp
A Command-Line Blackjack game written in C++ using object-oriented programming principles.

How to Compile and Run (macOS):

Install a C++ compiler (one-time setup)
Open Terminal and run:
xcode-select --install
Follow the prompts to install Xcode Command Line Tools.

Download the project

On GitHub, click the green “Code” button

Select “Download ZIP”

Unzip the folder

Open Terminal in the project folder
In Terminal, navigate to the folder where the project is located. Example:
cd ~/Downloads/blackjack-cpp-main

Compile the program:
g++ src/*.cpp -std=c++17 -o blackjack

Run the game:
./blackjack

How to play:

When prompted, type:
h to Hit
s to Stand

Try to get as close to 21 as possible without going over
The dealer hits until their total is at least 17
