#ifndef CALCULATOR_GUI_CALCULATOR_H
#define CALCULATOR_GUI_CALCULATOR_H

#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <wx/wx.h>

class Calculator : public wxFrame {
private:
    wxTextCtrl* textField;
    wxButton* numberButtons[10];
    wxButton* funcButton[12];
    wxButton *addButton, *subButton, *multiplyButton, *divButton, *negButton, *powButton, *rootButton, *logButton;
    wxButton *decButton, *eqButton, *delButton, *clrButton;
    wxPanel* panel;

    wxFont myFont;
    wxIcon myIcon;

    double num1 = 0.0;
    double num2 = 0.0;
    double result = 0.0;
    char op = 0;

public:
    Calculator();
    void OnButtonClick(wxCommandEvent& event);
};

#endif

#endif //CALCULATOR_GUI_CALCULATOR_H