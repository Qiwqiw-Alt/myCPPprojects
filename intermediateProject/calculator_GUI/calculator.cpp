#include <wx/wx.h>
#include <string>
using namespace std;

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
public:
    Calculator() : wxFrame(NULL, wxID_ANY, "My Calulator", wxPoint(50, 50), wxSize(420, 550)) {
        myFont = wxFont(17, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, "Verdana");
        myIcon.LoadFile("D:/someJavaCodes/src/apple.png", wxBITMAP_TYPE_PNG);
        this->SetIcon(myIcon);

        panel = new wxPanel(this, wxID_ANY);

        textField = new wxTextCtrl(panel, wxID_ANY, "", wxDefaultPosition, wxSize(300, 50), wxTE_READONLY | wxTE_RIGHT);
        textField->SetFont(myFont);
        textField->SetBackgroundColour(wxColour(0, 0, 0));
        textField->SetForegroundColour(wxColour(249, 248, 246));

        addButton = new wxButton(panel, wxID_ANY, "+");
        subButton = new wxButton(panel, wxID_ANY, "-");
        multiplyButton = new wxButton(panel, wxID_ANY, "*");
        divButton = new wxButton(panel, wxID_ANY, "/");
        negButton = new wxButton(panel, wxID_ANY, "-");
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
            funcButton[i]->Bind(wxEVT_BUTTON, wxCommandEventHandler(Calculator::OnButtonClick), this, funcButton[i]->GetId());
            funcButton[i]->SetBitmapMargins(wxSize(0, 0));
        }

        for (int i = 5; i < 10; i++) {
            funcButton[i]->SetFont(myFont);
            funcButton[i]->SetBackgroundColour(wxColour(221, 3 , 3));
            funcButton[i]->SetForegroundColour(wxColour(0, 0, 0));
            funcButton[i]->SetCanFocus(false);
            funcButton[i]->Bind(wxEVT_BUTTON, wxCommandEventHandler(Calculator::OnButtonClick), this, funcButton[i]->GetId());
            funcButton[i]->SetBitmapMargins(wxSize(0, 0));
        }

        for (int i = 10; i < 12; i++) {
            funcButton[i]->SetFont(myFont);
            funcButton[i]->SetBackgroundColour(wxColour(221, 3 , 3));
            funcButton[i]->SetForegroundColour(wxColour(0, 0, 0));
            funcButton[i]->SetCanFocus(false);
            funcButton[i]->Bind(wxEVT_BUTTON, wxCommandEventHandler(Calculator::OnButtonClick), this, funcButton[i]->GetId());
            funcButton[i]->SetBitmapMargins(wxSize(0, 0));
        }

        for (int i = 0; i < 10; i++) {
            numberButtons[i] = new wxButton(panel, wxID_ANY, to_string(i));
            numberButtons[i]->SetFont(myFont);
            numberButtons[i]->SetBackgroundColour(wxColour(0, 0 , 0));
            numberButtons[i]->SetForegroundColour(wxColour(251, 251, 251));
            numberButtons[i]->SetCanFocus(false);
            numberButtons[i]->Bind(wxEVT_BUTTON, wxCommandEventHandler(Calculator::OnButtonClick), this, numberButtons[i]->GetId());
        }

        
    }

    void Calculator::OnButtonClick(wxCommandEvent& event) {

    }
};