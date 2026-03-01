#include <wx/wx.h>
#include <string>
#include <cmath>
#include "Calculator.h"
using namespace std;

Calculator::Calculator() : wxFrame(NULL, wxID_ANY, "My Calulator", wxPoint(50, 50), wxSize(420, 550)) {
    wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);
    myFont = wxFont(17, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, "Verdana");
    if (myIcon.LoadFile("D:/someJavaCodes/src/apple.png", wxBITMAP_TYPE_PNG)) {
        this->SetIcon(myIcon);
    }

    panel = new wxPanel(this, wxID_ANY);
    panel->SetBackgroundColour(wxColour(0, 0, 0));

    textField = new wxTextCtrl(panel, wxID_ANY, "", wxDefaultPosition, wxSize(300, 50), wxTE_READONLY | wxTE_RIGHT);
    textField->SetFont(myFont);
    textField->SetBackgroundColour(wxColour(0, 0, 0));
    textField->SetForegroundColour(wxColour(249, 248, 246));

    addButton = new wxButton(panel, wxID_ANY, "+");
    subButton = new wxButton(panel, wxID_ANY, "-");
    multiplyButton = new wxButton(panel, wxID_ANY, "*");
    divButton = new wxButton(panel, wxID_ANY, "/");
    negButton = new wxButton(panel, wxID_ANY, "+/-");
    decButton = new wxButton(panel, wxID_ANY, ".");
    eqButton = new wxButton(panel, wxID_ANY, "=");
    powButton = new wxButton(panel, wxID_ANY, "Pow");
    rootButton = new wxButton(panel, wxID_ANY, "Root");
    logButton = new wxButton(panel, wxID_ANY, "Log");
    delButton = new wxButton(panel, wxID_ANY, "Delete");
    clrButton = new wxButton(panel, wxID_ANY, "Clear");

    funcButton[0] = addButton;
    funcButton[1] = subButton;
    funcButton[2] = multiplyButton;
    funcButton[3] = divButton;
    funcButton[4] = eqButton;
    funcButton[5] = decButton;
    funcButton[6] = negButton;
    funcButton[7] = powButton;
    funcButton[8] = rootButton;
    funcButton[9] = logButton;
    funcButton[10] = delButton;
    funcButton[11] = clrButton;

    for (int i = 0; i < 5; i++) {
        funcButton[i]->SetFont(myFont);
        funcButton[i]->SetBackgroundColour(wxColour(250, 129 , 47));
        funcButton[i]->SetForegroundColour(wxColour(0, 0, 0));
        funcButton[i]->SetCanFocus(false);
        funcButton[i]->Bind(wxEVT_BUTTON, wxCommandEventHandler(Calculator::OnButtonClick), this);
        funcButton[i]->SetBitmapMargins(wxSize(0, 0));
    }

    for (int i = 5; i < 10; i++) {
        funcButton[i]->SetFont(myFont);
        funcButton[i]->SetBackgroundColour(wxColour(250, 177 , 47));
        funcButton[i]->SetForegroundColour(wxColour(0, 0, 0));
        funcButton[i]->SetCanFocus(false);
        funcButton[i]->Bind(wxEVT_BUTTON, wxCommandEventHandler(Calculator::OnButtonClick), this);
        funcButton[i]->SetBitmapMargins(wxSize(0, 0));
    }

    for (int i = 10; i < 12; i++) {
        funcButton[i]->SetFont(myFont);
        funcButton[i]->SetBackgroundColour(wxColour(221, 3 , 3));
        funcButton[i]->SetForegroundColour(wxColour(0, 0, 0));
        funcButton[i]->SetCanFocus(false);
        funcButton[i]->Bind(wxEVT_BUTTON, wxCommandEventHandler(Calculator::OnButtonClick), this);
        funcButton[i]->SetBitmapMargins(wxSize(0, 0));
    }

    for (int i = 0; i < 10; i++) {
        numberButtons[i] = new wxButton(panel, wxID_ANY, to_string(i));
        numberButtons[i]->SetFont(myFont);
        numberButtons[i]->SetBackgroundColour(wxColour(0, 0 , 0));
        numberButtons[i]->SetForegroundColour(wxColour(251, 251, 251));
        numberButtons[i]->SetCanFocus(false);
        numberButtons[i]->Bind(wxEVT_BUTTON, wxCommandEventHandler(Calculator::OnButtonClick), this);
    }

    wxGridSizer* gridSizer = new wxGridSizer(4, 5, 10, 10);

    gridSizer->Add(numberButtons[1], 0, wxEXPAND | wxALL, 5);
    gridSizer->Add(numberButtons[2], 0, wxEXPAND | wxALL, 5);
    gridSizer->Add(numberButtons[3], 0, wxEXPAND | wxALL, 5);
    gridSizer->Add(addButton, 0, wxEXPAND | wxALL, 5);
    gridSizer->Add(subButton, 0, wxEXPAND | wxALL, 5);

    gridSizer->Add(numberButtons[4], 0, wxEXPAND | wxALL, 5);
    gridSizer->Add(numberButtons[5], 0, wxEXPAND | wxALL, 5);
    gridSizer->Add(numberButtons[6], 0, wxEXPAND | wxALL, 5);
    gridSizer->Add(multiplyButton, 0, wxEXPAND | wxALL, 5);
    gridSizer->Add(divButton, 0, wxEXPAND | wxALL, 5);

    gridSizer->Add(numberButtons[7], 0, wxEXPAND | wxALL, 5);
    gridSizer->Add(numberButtons[8], 0, wxEXPAND | wxALL, 5);
    gridSizer->Add(numberButtons[9], 0, wxEXPAND | wxALL, 5);
    gridSizer->Add(numberButtons[0], 0, wxEXPAND | wxALL, 5);
    gridSizer->Add(eqButton, 0, wxEXPAND | wxALL, 5);

    gridSizer->Add(decButton, 0, wxEXPAND | wxALL, 5);
    gridSizer->Add(powButton, 0, wxEXPAND | wxALL, 5);
    gridSizer->Add(rootButton, 0, wxEXPAND | wxALL, 5);
    gridSizer->Add(logButton, 0, wxEXPAND | wxALL, 5);
    gridSizer->Add(negButton, 0, wxEXPAND | wxALL, 5);

    panel->SetSizer(gridSizer);
    gridSizer->SetMinSize(300, 300);
    gridSizer->Fit(panel);

    wxBoxSizer* bottomSizer = new wxBoxSizer(wxHORIZONTAL);
    bottomSizer->Add(delButton, 1, wxEXPAND | wxALL, 5);
    bottomSizer->Add(clrButton, 1, wxEXPAND | wxALL, 5);

    mainSizer->Add(textField, 0, wxEXPAND | wxALL, 5);
    mainSizer->Add(panel, 0, wxEXPAND | wxALL, 5);
    mainSizer->Add(bottomSizer, 0, wxEXPAND | wxALL, 5);

    this->SetSizer(mainSizer);
    this->Layout();

    this->SetSize(400, 600);
    this->Centre();
    this->Show(true);
}

void Calculator::OnButtonClick(wxCommandEvent& event) {
    wxObject* src = event.GetEventObject();

    for (int i = 0; i < 10; ++i) {
        if (src == numberButtons[i]) {
            textField->AppendText(wxString::Format("%d", i));
            return;
        }
    }

    if (src == decButton) {
        wxString str = textField->GetValue();
        if (!str.Contains('.')) {
            textField->AppendText(".");
        }
        return;
    }

    if (src == addButton || src == subButton || src == multiplyButton || src == divButton || src == powButton || src == rootButton) {
        wxString str = textField->GetValue();
        if (str.IsEmpty()) return;

        double temp;
        if (!str.ToDouble(&temp)) return;
        num1 = temp;
        textField->Clear();

        if      (src == addButton)     op = '+';
        else if (src == subButton)     op = '-';
        else if (src == multiplyButton) op = '*';
        else if (src == divButton)     op = '/';
        else if (src == powButton)     op = '^';
        else if (src == rootButton)    op = 'r';

        return;
    }

    if (src == eqButton) {
        wxString str = textField->GetValue();
        if (str.IsEmpty() || op == 0) return;

        double temp;
        if (!str.ToDouble(&temp)) {
            textField->SetValue("Error");
            return;
        }
        num2 = temp;

        switch (op) {
            case '+': result = num1 + num2; break;
            case '-': result = num1 - num2; break;
            case '*': result = num1 * num2; break;
            case '/':
                if (num2 == 0.0) {
                    textField->SetValue("Error");
                    op = 0;
                    return;
                }
                result = num1 / num2; break;
            case '^': result = pow(num1, num2); break;
            case 'r':
                if (num2 == 0.0) {
                    textField->SetValue("Error");
                    op = 0;
                    return;
                }
                result = pow(num1, 1.0 / num2); break;
            default: return;
        }
        textField->SetValue(wxString::Format("%g", result));
        num1 = result;
        op = 0;
        return;
    }

    if (src == clrButton) {
        textField->Clear();
        op = 0;
        num1 = num2 = result = 0.0;
        return;
    }

    if (src == delButton) {
        wxString str = textField->GetValue();
        if (str.Len() > 0) {
           str.RemoveLast();
            textField->SetValue(str);
        }
        return;
    }

    if (src == negButton) {
        wxString str = textField->GetValue();
        if (str.IsEmpty()) return;

        double temp;
        if (str.ToDouble(&temp)) {
            textField->SetValue(wxString::Format("%g", -temp));
        }
        return;
    }

    if (src == logButton) {
        wxString str = textField->GetValue();
        if (str.IsEmpty()) return;

        double temp;
        if (str.ToDouble(&temp)) {
            if (temp <= 0) {
                textField->SetValue("Error");
                return;
            }
            textField->SetValue(wxString::Format("%g", log10(temp)));
        }
        return;
    }
}
