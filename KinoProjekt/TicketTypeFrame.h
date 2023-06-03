#pragma once
#include <wx/wx.h>
class TicketTypeFrame : public wxFrame
{
public:
	TicketTypeFrame(const wxString& title, Screening& screening);
private:
	void OnButton0Clicked(wxCommandEvent& evt);
	void OnSpin(wxSpinEvent& event);
	wxSpinCtrl* spinCtrl0;
	wxSpinCtrl* spinCtrl1;
	wxStaticText* spinText;
	Screening& screening;
};