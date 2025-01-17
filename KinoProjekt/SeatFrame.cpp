﻿#include "SeatFrame.h"

SeatFrame::SeatFrame(const wxString& title, const wxString& movie, const wxString& date, const wxString& time, const wxString& type, const wxString& language, const wxString& message)
    : wxFrame(nullptr, wxID_ANY, title), movie(movie), date(date), time(time), type(type), language(language), message(message)
{
    mainPanel = new wxPanel(this, wxID_ANY);
    mainSizer = new wxBoxSizer(wxVERTICAL);
    mainPanel->SetSizer(mainSizer);

    panel0 = new wxPanel(mainPanel, wxID_ANY, wxDefaultPosition, wxSize(1280, 100));
    panel0->SetBackgroundColour(wxColor(0, 0, 0));
    mainSizer->Add(panel0, 0, wxEXPAND);

    staticText0 = new wxStaticText(panel0, wxID_ANY, "Wybierz Miejsca", wxPoint(80, 5), wxDefaultSize, wxALIGN_CENTER_HORIZONTAL);
    staticText0->SetFont(wxFont(60, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));
    staticText0->SetForegroundColour(wxColor(40, 126, 75));

    panel1 = new wxPanel(mainPanel, wxID_ANY, wxDefaultPosition, wxSize(1280, 520));
    panel1->SetBackgroundColour(wxColor(65, 65, 65));
    mainSizer->Add(panel1, 1, wxEXPAND);

    panel2 = new wxPanel(mainPanel, wxID_ANY, wxDefaultPosition, wxSize(1280, 100));
    panel2->SetBackgroundColour(wxColor(0, 0, 0));
    mainSizer->Add(panel2, 0, wxEXPAND);

    panel2Sizer = new wxBoxSizer(wxHORIZONTAL);
    panel2->SetSizer(panel2Sizer);

    staticText1 = new wxStaticText(panel2, wxID_ANY, "Twoje miejsca:", wxPoint(500,0), wxDefaultSize, wxALIGN_CENTER);
    staticText1->SetFont(wxFont(20, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));
    staticText1->SetForegroundColour(wxColor(255, 255, 255));

    button0 = new wxButton(panel2, wxID_ANY, L"Płatność", wxDefaultPosition, wxSize(200, 60));
    button0->Bind(wxEVT_BUTTON, &SeatFrame::OnButton0Clicked, this, wxID_ANY);
    button0->SetFont(wxFont(15, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));

    panel2Sizer->AddStretchSpacer(1);
    panel2Sizer->Add(button0, 0, wxALIGN_CENTER_VERTICAL | wxRIGHT, 20); // Zwiêksz prawy margines przycisku

}

void SeatFrame::OnButton0Clicked(wxCommandEvent& evt)
{
    PaymentFrame* paymentFrame = new PaymentFrame(L"Płatność", movie, date, time, type, language, message);
    paymentFrame->Show();
    paymentFrame->SetClientSize(1280, 720);
    paymentFrame->SetMinClientSize(wxSize(1280, 720));
    paymentFrame->SetMaxClientSize(wxSize(1280, 720));
    paymentFrame->Center();
    Close();
}
