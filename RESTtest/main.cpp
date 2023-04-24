#include "MainForm.h"
//#include "RESTClient.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThread]
void main()
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	RESTtest::MainForm form;
	Application::Run(% form);
}
