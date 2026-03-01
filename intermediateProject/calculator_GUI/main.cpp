#include <wx/wx.h>
#include "Calculator.h"
using namespace std;

// Use mingw not visual studio
class MyApp : public wxApp {
public:
    bool OnInit() override {
        Calculator* calc = new Calculator();
        calc->Show(true);
        return true;
    }
};