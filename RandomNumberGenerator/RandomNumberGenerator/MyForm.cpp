#include "MyForm.h"

// Initial setup guide: https://www.youtube.com/watch?v=AP8Tz9RfbxE
// Number generator tutorial: http://www.bogotobogo.com/cplusplus/application_visual_studio_2013.php
// NOTE on above tutorial - DEPLOYMENT SECTION
// Setup and Deployment (InstallShield) is not supported in VS2015 Community edition
// Suggestion to try from http://stackoverflow.com/questions/31888465/visual-studio-2015-community-isle-setup-and-deployment-doesnt-appear:
// Microsoft Visual Studio 2015 Installer Projects https://visualstudiogallery.msdn.microsoft.com/f1cc3f3e-c300-40a7-8797-c509fb8933b9

using namespace System;
using namespace System::Windows::Forms;
[STAThread]

void main(array<String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	RandomNumberGenerator::MyForm form;
	Application::Run(%form);
}