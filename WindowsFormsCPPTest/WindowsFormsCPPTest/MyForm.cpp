#include "MyForm.h"

// Initial setup guide: https://www.youtube.com/watch?v=AP8Tz9RfbxE
// Number generator tutorial: http://www.bogotobogo.com/cplusplus/application_visual_studio_2013.php

using namespace System;
using namespace System::Windows::Forms;
[STAThread]

void main(array<String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	WindowsFormsCPPTest::MyForm form;
	Application::Run(%form);
}