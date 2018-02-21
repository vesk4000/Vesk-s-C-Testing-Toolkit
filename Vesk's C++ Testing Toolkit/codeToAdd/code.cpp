///Add these libraries
#include <fstream>
#include <sstream>
#include <ctime>

///Add these global variables
ifstream veskinput;ofstream veskoutput;ofstream vesktimes;

///Add this function
string veskaddZeros(int veskx, int veskn){stringstream veskss;veskss << veskn;string veskans = veskss.str();while(veskans.size() < veskx){veskans = '0' + veskans;}return veskans;}

///Add this in the beginning of your main function
vesktimes.open("times.txt");
int vesknumberOfTests;
cin >> vesknumberOfTests;
string veskproblemName;
cin >> veskproblemName;
int vesknDigits;
cin >> vesknDigits;
for(int veski = 0;veski < vesknumberOfTests; ++veski){
string vesknameinput = veskproblemName + "." + veskaddZeros(vesknDigits, veski) + ".in";
veskinput.open(vesknameinput.c_str());
string vesknameoutput = veskproblemName + "." + veskaddZeros(vesknDigits, veski) + ".user.sol";
veskoutput.open(vesknameoutput.c_str());
///Restart the values of all of your global variables here
clock_t begin = clock();

///Put this code at the end of your main function(before "return;")
clock_t end = clock();
double vesktimesecs = double(end - begin) / CLOCKS_PER_SEC;
vesktimes << vesktimesecs << endl;
veskinput.close();
veskoutput.close();
}
vesktimes.close();
