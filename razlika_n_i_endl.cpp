#include <iostream>
#include <unistd.h> // Za sleep() na Unix sistemima (Linux, Mac)

using namespace std;

int main() {
	sleep(2);  // Čekamo 2 sekunde
    cout << "Prvi red bez endl\n";  // Samo novi red, bez flush-a
    sleep(2);  // Čekamo 2 sekunde
    cout << "Drugi red s endl" << endl;  // Novi red + flush
    sleep(2);
    return 0;
}
