#pragma once

#include <iostream>
#include <regex>
#include <string>
#include <msclr\marshal_cppstd.h>
#include <algorithm>
#include "RESTClient.h"
#include "jsoncpp/json/json.h"

namespace RESTtest {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
		{
			InitializeComponent();
            FillUsersPage(true);
		}

	protected:

		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}
    private: System::Windows::Forms::TabControl^ tabs;
    private: System::Windows::Forms::TabPage^ usersPage;
    private: System::Windows::Forms::Button^ showMore;
    private: System::Windows::Forms::Panel^ userPanel6;
    private: System::Windows::Forms::Label^ userPhone6;
    private: System::Windows::Forms::Label^ userEmail6;
    private: System::Windows::Forms::Label^ userPosition6;
    private: System::Windows::Forms::Label^ userName6;
    private: System::Windows::Forms::PictureBox^ userPhoto6;
    private: System::Windows::Forms::Panel^ userPanel5;
    private: System::Windows::Forms::Label^ userPhone5;
    private: System::Windows::Forms::Label^ userEmail5;
    private: System::Windows::Forms::Label^ userPosition5;
    private: System::Windows::Forms::Label^ userName5;
    private: System::Windows::Forms::PictureBox^ userPhoto5;
    private: System::Windows::Forms::Panel^ userPanel4;
    private: System::Windows::Forms::Label^ userPhone4;
    private: System::Windows::Forms::Label^ userEmail4;
    private: System::Windows::Forms::Label^ userPosition4;
    private: System::Windows::Forms::Label^ userName4;
    private: System::Windows::Forms::PictureBox^ userPhoto4;
    private: System::Windows::Forms::Panel^ userPanel3;
    private: System::Windows::Forms::Label^ userPhone3;
    private: System::Windows::Forms::Label^ userEmail3;
    private: System::Windows::Forms::Label^ userPosition3;
    private: System::Windows::Forms::Label^ userName3;
    private: System::Windows::Forms::PictureBox^ userPhoto3;
    private: System::Windows::Forms::Panel^ userPanel2;
    private: System::Windows::Forms::Label^ userPhone2;
    private: System::Windows::Forms::Label^ userEmail2;
    private: System::Windows::Forms::Label^ userPosition2;
    private: System::Windows::Forms::Label^ userName2;
    private: System::Windows::Forms::PictureBox^ userPhoto2;
    private: System::Windows::Forms::Panel^ userPanel1;
    private: System::Windows::Forms::Label^ userPhone1;
    private: System::Windows::Forms::Label^ userEmail1;
    private: System::Windows::Forms::Label^ userPosition1;
    private: System::Windows::Forms::Label^ userName1;
    private: System::Windows::Forms::PictureBox^ userPhoto1;
    private: System::Windows::Forms::Label^ headerLaber;
    private: System::Windows::Forms::TabPage^ addUserPage;
    private: System::Windows::Forms::Panel^ addUserPanel;
    private: System::Windows::Forms::TextBox^ photoTextBox;
    private: System::Windows::Forms::TextBox^ phoneTextBox;
    private: System::Windows::Forms::TextBox^ emailTextBox;
    private: System::Windows::Forms::Label^ nameLabel;
    private: System::Windows::Forms::TextBox^ nameTextBox;
    private: System::Windows::Forms::Label^ nameErrorLabel;
    private: System::Windows::Forms::RadioButton^ position8;
    private: System::Windows::Forms::RadioButton^ position7;
    private: System::Windows::Forms::RadioButton^ position6;
    private: System::Windows::Forms::RadioButton^ position5;
    private: System::Windows::Forms::RadioButton^ position4;
    private: System::Windows::Forms::RadioButton^ position3;
    private: System::Windows::Forms::RadioButton^ position2;
    private: System::Windows::Forms::RadioButton^ position1;
    private: System::Windows::Forms::Button^ addUserButton;
    private: System::Windows::Forms::Button^ uploadPhotoButton;
    private: System::Windows::Forms::Label^ photoLabel;
    private: System::Windows::Forms::Label^ positionsLabel;
    private: System::Windows::Forms::Label^ headerLabel;
    private: System::Windows::Forms::Label^ phoneExampleLabel;
    private: System::Windows::Forms::Label^ emailErrorLabel;
    private: System::Windows::Forms::Label^ Phone;
    private: System::Windows::Forms::Panel^ successPanel;
    private: System::Windows::Forms::Button^ addOneMoreButton;
    private: System::Windows::Forms::Button^ usersListButton;
    private: System::Windows::Forms::Label^ successLabel;
    private: System::Windows::Forms::Label^ emailLabel;

    private:
        void HideAllPositions();
        void FillPosition(RadioButton^ position, Json::Value& value, int index);
        void HideAllUsersPanels();
        void FillUserPanel(Panel^ panel, Label^ name, Label^ position,
                Label^ email, Label^ phone, PictureBox^ photo,
                Json::Value& json_users, Json::Value::ArrayIndex id);
        void FillUsersPage(bool from_first);
        bool IsValidName();
        bool IsValidEmail();
        bool IsValidPhone();
        bool IsVisiablePositionSelected();
        bool IsValidPhotoChoosed();
        void FormatText(std::string& str, int index, char c);
        static bool ifNotDigit(const char& c);
        bool EnteredDataChecks();
        size_t GetSelectedPositionId();

	private:
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
            this->tabs = (gcnew System::Windows::Forms::TabControl());
            this->usersPage = (gcnew System::Windows::Forms::TabPage());
            this->showMore = (gcnew System::Windows::Forms::Button());
            this->userPanel6 = (gcnew System::Windows::Forms::Panel());
            this->userPhone6 = (gcnew System::Windows::Forms::Label());
            this->userEmail6 = (gcnew System::Windows::Forms::Label());
            this->userPosition6 = (gcnew System::Windows::Forms::Label());
            this->userName6 = (gcnew System::Windows::Forms::Label());
            this->userPhoto6 = (gcnew System::Windows::Forms::PictureBox());
            this->userPanel5 = (gcnew System::Windows::Forms::Panel());
            this->userPhone5 = (gcnew System::Windows::Forms::Label());
            this->userEmail5 = (gcnew System::Windows::Forms::Label());
            this->userPosition5 = (gcnew System::Windows::Forms::Label());
            this->userName5 = (gcnew System::Windows::Forms::Label());
            this->userPhoto5 = (gcnew System::Windows::Forms::PictureBox());
            this->userPanel4 = (gcnew System::Windows::Forms::Panel());
            this->userPhone4 = (gcnew System::Windows::Forms::Label());
            this->userEmail4 = (gcnew System::Windows::Forms::Label());
            this->userPosition4 = (gcnew System::Windows::Forms::Label());
            this->userName4 = (gcnew System::Windows::Forms::Label());
            this->userPhoto4 = (gcnew System::Windows::Forms::PictureBox());
            this->userPanel3 = (gcnew System::Windows::Forms::Panel());
            this->userPhone3 = (gcnew System::Windows::Forms::Label());
            this->userEmail3 = (gcnew System::Windows::Forms::Label());
            this->userPosition3 = (gcnew System::Windows::Forms::Label());
            this->userName3 = (gcnew System::Windows::Forms::Label());
            this->userPhoto3 = (gcnew System::Windows::Forms::PictureBox());
            this->userPanel2 = (gcnew System::Windows::Forms::Panel());
            this->userPhone2 = (gcnew System::Windows::Forms::Label());
            this->userEmail2 = (gcnew System::Windows::Forms::Label());
            this->userPosition2 = (gcnew System::Windows::Forms::Label());
            this->userName2 = (gcnew System::Windows::Forms::Label());
            this->userPhoto2 = (gcnew System::Windows::Forms::PictureBox());
            this->userPanel1 = (gcnew System::Windows::Forms::Panel());
            this->userPhone1 = (gcnew System::Windows::Forms::Label());
            this->userEmail1 = (gcnew System::Windows::Forms::Label());
            this->userPosition1 = (gcnew System::Windows::Forms::Label());
            this->userName1 = (gcnew System::Windows::Forms::Label());
            this->userPhoto1 = (gcnew System::Windows::Forms::PictureBox());
            this->headerLaber = (gcnew System::Windows::Forms::Label());
            this->addUserPage = (gcnew System::Windows::Forms::TabPage());
            this->successPanel = (gcnew System::Windows::Forms::Panel());
            this->addOneMoreButton = (gcnew System::Windows::Forms::Button());
            this->usersListButton = (gcnew System::Windows::Forms::Button());
            this->successLabel = (gcnew System::Windows::Forms::Label());
            this->addUserPanel = (gcnew System::Windows::Forms::Panel());
            this->photoTextBox = (gcnew System::Windows::Forms::TextBox());
            this->phoneTextBox = (gcnew System::Windows::Forms::TextBox());
            this->emailTextBox = (gcnew System::Windows::Forms::TextBox());
            this->nameLabel = (gcnew System::Windows::Forms::Label());
            this->nameTextBox = (gcnew System::Windows::Forms::TextBox());
            this->nameErrorLabel = (gcnew System::Windows::Forms::Label());
            this->position8 = (gcnew System::Windows::Forms::RadioButton());
            this->position7 = (gcnew System::Windows::Forms::RadioButton());
            this->position6 = (gcnew System::Windows::Forms::RadioButton());
            this->position5 = (gcnew System::Windows::Forms::RadioButton());
            this->position4 = (gcnew System::Windows::Forms::RadioButton());
            this->position3 = (gcnew System::Windows::Forms::RadioButton());
            this->position2 = (gcnew System::Windows::Forms::RadioButton());
            this->position1 = (gcnew System::Windows::Forms::RadioButton());
            this->addUserButton = (gcnew System::Windows::Forms::Button());
            this->uploadPhotoButton = (gcnew System::Windows::Forms::Button());
            this->photoLabel = (gcnew System::Windows::Forms::Label());
            this->positionsLabel = (gcnew System::Windows::Forms::Label());
            this->headerLabel = (gcnew System::Windows::Forms::Label());
            this->phoneExampleLabel = (gcnew System::Windows::Forms::Label());
            this->emailErrorLabel = (gcnew System::Windows::Forms::Label());
            this->Phone = (gcnew System::Windows::Forms::Label());
            this->emailLabel = (gcnew System::Windows::Forms::Label());
            this->tabs->SuspendLayout();
            this->usersPage->SuspendLayout();
            this->userPanel6->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->userPhoto6))->BeginInit();
            this->userPanel5->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->userPhoto5))->BeginInit();
            this->userPanel4->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->userPhoto4))->BeginInit();
            this->userPanel3->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->userPhoto3))->BeginInit();
            this->userPanel2->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->userPhoto2))->BeginInit();
            this->userPanel1->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->userPhoto1))->BeginInit();
            this->addUserPage->SuspendLayout();
            this->successPanel->SuspendLayout();
            this->addUserPanel->SuspendLayout();
            this->SuspendLayout();
            // 
            // tabs
            // 
            this->tabs->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->tabs->Controls->Add(this->usersPage);
            this->tabs->Controls->Add(this->addUserPage);
            this->tabs->ItemSize = System::Drawing::Size(223, 50);
            this->tabs->Location = System::Drawing::Point(100, 20);
            this->tabs->Name = L"tabs";
            this->tabs->RightToLeft = System::Windows::Forms::RightToLeft::No;
            this->tabs->SelectedIndex = 0;
            this->tabs->Size = System::Drawing::Size(600, 810);
            this->tabs->SizeMode = System::Windows::Forms::TabSizeMode::Fixed;
            this->tabs->TabIndex = 1;
            this->tabs->SelectedIndexChanged += gcnew System::EventHandler(this, &MainForm::tabs_SelectedIndexChanged);
            // 
            // usersPage
            // 
            this->usersPage->Controls->Add(this->showMore);
            this->usersPage->Controls->Add(this->userPanel6);
            this->usersPage->Controls->Add(this->userPanel5);
            this->usersPage->Controls->Add(this->userPanel4);
            this->usersPage->Controls->Add(this->userPanel3);
            this->usersPage->Controls->Add(this->userPanel2);
            this->usersPage->Controls->Add(this->userPanel1);
            this->usersPage->Controls->Add(this->headerLaber);
            this->usersPage->Location = System::Drawing::Point(4, 54);
            this->usersPage->Name = L"usersPage";
            this->usersPage->Padding = System::Windows::Forms::Padding(3);
            this->usersPage->Size = System::Drawing::Size(592, 752);
            this->usersPage->TabIndex = 0;
            this->usersPage->Text = L"Users";
            this->usersPage->UseVisualStyleBackColor = true;
            // 
            // showMore
            // 
            this->showMore->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->showMore->Location = System::Drawing::Point(241, 699);
            this->showMore->Name = L"showMore";
            this->showMore->Size = System::Drawing::Size(110, 35);
            this->showMore->TabIndex = 13;
            this->showMore->Text = L"Show more";
            this->showMore->UseVisualStyleBackColor = true;
            this->showMore->Click += gcnew System::EventHandler(this, &MainForm::showMore_Click);
            // 
            // userPanel6
            // 
            this->userPanel6->Controls->Add(this->userPhone6);
            this->userPanel6->Controls->Add(this->userEmail6);
            this->userPanel6->Controls->Add(this->userPosition6);
            this->userPanel6->Controls->Add(this->userName6);
            this->userPanel6->Controls->Add(this->userPhoto6);
            this->userPanel6->Location = System::Drawing::Point(20, 589);
            this->userPanel6->Name = L"userPanel6";
            this->userPanel6->Size = System::Drawing::Size(552, 104);
            this->userPanel6->TabIndex = 12;
            // 
            // userPhone6
            // 
            this->userPhone6->AutoSize = true;
            this->userPhone6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->userPhone6->Location = System::Drawing::Point(111, 78);
            this->userPhone6->Name = L"userPhone6";
            this->userPhone6->Size = System::Drawing::Size(139, 18);
            this->userPhone6->TabIndex = 4;
            this->userPhone6->Text = L"+38 (098) 198 44 24";
            // 
            // userEmail6
            // 
            this->userEmail6->AutoSize = true;
            this->userEmail6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->userEmail6->Location = System::Drawing::Point(111, 56);
            this->userEmail6->Name = L"userEmail6";
            this->userEmail6->Size = System::Drawing::Size(214, 18);
            this->userEmail6->TabIndex = 3;
            this->userEmail6->Text = L"alexander_develop@gmail.com";
            // 
            // userPosition6
            // 
            this->userPosition6->AutoSize = true;
            this->userPosition6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->userPosition6->Location = System::Drawing::Point(111, 34);
            this->userPosition6->Name = L"userPosition6";
            this->userPosition6->Size = System::Drawing::Size(194, 18);
            this->userPosition6->TabIndex = 2;
            this->userPosition6->Text = L"Lead Independent Developer";
            // 
            // userName6
            // 
            this->userName6->AutoSize = true;
            this->userName6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->userName6->Location = System::Drawing::Point(111, 10);
            this->userName6->Name = L"userName6";
            this->userName6->Size = System::Drawing::Size(92, 20);
            this->userName6->TabIndex = 1;
            this->userName6->Text = L"Alexander";
            // 
            // userPhoto6
            // 
            this->userPhoto6->Location = System::Drawing::Point(21, 10);
            this->userPhoto6->Name = L"userPhoto6";
            this->userPhoto6->Size = System::Drawing::Size(84, 84);
            this->userPhoto6->TabIndex = 0;
            this->userPhoto6->TabStop = false;
            // 
            // userPanel5
            // 
            this->userPanel5->Controls->Add(this->userPhone5);
            this->userPanel5->Controls->Add(this->userEmail5);
            this->userPanel5->Controls->Add(this->userPosition5);
            this->userPanel5->Controls->Add(this->userName5);
            this->userPanel5->Controls->Add(this->userPhoto5);
            this->userPanel5->Location = System::Drawing::Point(20, 479);
            this->userPanel5->Name = L"userPanel5";
            this->userPanel5->Size = System::Drawing::Size(552, 104);
            this->userPanel5->TabIndex = 11;
            // 
            // userPhone5
            // 
            this->userPhone5->AutoSize = true;
            this->userPhone5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->userPhone5->Location = System::Drawing::Point(111, 78);
            this->userPhone5->Name = L"userPhone5";
            this->userPhone5->Size = System::Drawing::Size(139, 18);
            this->userPhone5->TabIndex = 4;
            this->userPhone5->Text = L"+38 (098) 198 44 24";
            // 
            // userEmail5
            // 
            this->userEmail5->AutoSize = true;
            this->userEmail5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->userEmail5->Location = System::Drawing::Point(111, 56);
            this->userEmail5->Name = L"userEmail5";
            this->userEmail5->Size = System::Drawing::Size(214, 18);
            this->userEmail5->TabIndex = 3;
            this->userEmail5->Text = L"alexander_develop@gmail.com";
            // 
            // userPosition5
            // 
            this->userPosition5->AutoSize = true;
            this->userPosition5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->userPosition5->Location = System::Drawing::Point(111, 34);
            this->userPosition5->Name = L"userPosition5";
            this->userPosition5->Size = System::Drawing::Size(194, 18);
            this->userPosition5->TabIndex = 2;
            this->userPosition5->Text = L"Lead Independent Developer";
            // 
            // userName5
            // 
            this->userName5->AutoSize = true;
            this->userName5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->userName5->Location = System::Drawing::Point(111, 10);
            this->userName5->Name = L"userName5";
            this->userName5->Size = System::Drawing::Size(92, 20);
            this->userName5->TabIndex = 1;
            this->userName5->Text = L"Alexander";
            // 
            // userPhoto5
            // 
            this->userPhoto5->Location = System::Drawing::Point(21, 10);
            this->userPhoto5->Name = L"userPhoto5";
            this->userPhoto5->Size = System::Drawing::Size(84, 84);
            this->userPhoto5->TabIndex = 0;
            this->userPhoto5->TabStop = false;
            // 
            // userPanel4
            // 
            this->userPanel4->Controls->Add(this->userPhone4);
            this->userPanel4->Controls->Add(this->userEmail4);
            this->userPanel4->Controls->Add(this->userPosition4);
            this->userPanel4->Controls->Add(this->userName4);
            this->userPanel4->Controls->Add(this->userPhoto4);
            this->userPanel4->Location = System::Drawing::Point(20, 369);
            this->userPanel4->Name = L"userPanel4";
            this->userPanel4->Size = System::Drawing::Size(552, 104);
            this->userPanel4->TabIndex = 11;
            // 
            // userPhone4
            // 
            this->userPhone4->AutoSize = true;
            this->userPhone4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->userPhone4->Location = System::Drawing::Point(111, 78);
            this->userPhone4->Name = L"userPhone4";
            this->userPhone4->Size = System::Drawing::Size(139, 18);
            this->userPhone4->TabIndex = 4;
            this->userPhone4->Text = L"+38 (098) 198 44 24";
            // 
            // userEmail4
            // 
            this->userEmail4->AutoSize = true;
            this->userEmail4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->userEmail4->Location = System::Drawing::Point(111, 56);
            this->userEmail4->Name = L"userEmail4";
            this->userEmail4->Size = System::Drawing::Size(214, 18);
            this->userEmail4->TabIndex = 3;
            this->userEmail4->Text = L"alexander_develop@gmail.com";
            // 
            // userPosition4
            // 
            this->userPosition4->AutoSize = true;
            this->userPosition4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->userPosition4->Location = System::Drawing::Point(111, 34);
            this->userPosition4->Name = L"userPosition4";
            this->userPosition4->Size = System::Drawing::Size(194, 18);
            this->userPosition4->TabIndex = 2;
            this->userPosition4->Text = L"Lead Independent Developer";
            // 
            // userName4
            // 
            this->userName4->AutoSize = true;
            this->userName4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->userName4->Location = System::Drawing::Point(111, 10);
            this->userName4->Name = L"userName4";
            this->userName4->Size = System::Drawing::Size(92, 20);
            this->userName4->TabIndex = 1;
            this->userName4->Text = L"Alexander";
            // 
            // userPhoto4
            // 
            this->userPhoto4->Location = System::Drawing::Point(21, 10);
            this->userPhoto4->Name = L"userPhoto4";
            this->userPhoto4->Size = System::Drawing::Size(84, 84);
            this->userPhoto4->TabIndex = 0;
            this->userPhoto4->TabStop = false;
            // 
            // userPanel3
            // 
            this->userPanel3->Controls->Add(this->userPhone3);
            this->userPanel3->Controls->Add(this->userEmail3);
            this->userPanel3->Controls->Add(this->userPosition3);
            this->userPanel3->Controls->Add(this->userName3);
            this->userPanel3->Controls->Add(this->userPhoto3);
            this->userPanel3->Location = System::Drawing::Point(20, 259);
            this->userPanel3->Name = L"userPanel3";
            this->userPanel3->Size = System::Drawing::Size(552, 104);
            this->userPanel3->TabIndex = 11;
            // 
            // userPhone3
            // 
            this->userPhone3->AutoSize = true;
            this->userPhone3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->userPhone3->Location = System::Drawing::Point(111, 78);
            this->userPhone3->Name = L"userPhone3";
            this->userPhone3->Size = System::Drawing::Size(139, 18);
            this->userPhone3->TabIndex = 4;
            this->userPhone3->Text = L"+38 (098) 198 44 24";
            // 
            // userEmail3
            // 
            this->userEmail3->AutoSize = true;
            this->userEmail3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->userEmail3->Location = System::Drawing::Point(111, 56);
            this->userEmail3->Name = L"userEmail3";
            this->userEmail3->Size = System::Drawing::Size(214, 18);
            this->userEmail3->TabIndex = 3;
            this->userEmail3->Text = L"alexander_develop@gmail.com";
            // 
            // userPosition3
            // 
            this->userPosition3->AutoSize = true;
            this->userPosition3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->userPosition3->Location = System::Drawing::Point(111, 34);
            this->userPosition3->Name = L"userPosition3";
            this->userPosition3->Size = System::Drawing::Size(194, 18);
            this->userPosition3->TabIndex = 2;
            this->userPosition3->Text = L"Lead Independent Developer";
            // 
            // userName3
            // 
            this->userName3->AutoSize = true;
            this->userName3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->userName3->Location = System::Drawing::Point(111, 10);
            this->userName3->Name = L"userName3";
            this->userName3->Size = System::Drawing::Size(92, 20);
            this->userName3->TabIndex = 1;
            this->userName3->Text = L"Alexander";
            // 
            // userPhoto3
            // 
            this->userPhoto3->Location = System::Drawing::Point(21, 10);
            this->userPhoto3->Name = L"userPhoto3";
            this->userPhoto3->Size = System::Drawing::Size(84, 84);
            this->userPhoto3->TabIndex = 0;
            this->userPhoto3->TabStop = false;
            // 
            // userPanel2
            // 
            this->userPanel2->Controls->Add(this->userPhone2);
            this->userPanel2->Controls->Add(this->userEmail2);
            this->userPanel2->Controls->Add(this->userPosition2);
            this->userPanel2->Controls->Add(this->userName2);
            this->userPanel2->Controls->Add(this->userPhoto2);
            this->userPanel2->Location = System::Drawing::Point(20, 149);
            this->userPanel2->Name = L"userPanel2";
            this->userPanel2->Size = System::Drawing::Size(552, 104);
            this->userPanel2->TabIndex = 11;
            // 
            // userPhone2
            // 
            this->userPhone2->AutoSize = true;
            this->userPhone2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->userPhone2->Location = System::Drawing::Point(111, 78);
            this->userPhone2->Name = L"userPhone2";
            this->userPhone2->Size = System::Drawing::Size(139, 18);
            this->userPhone2->TabIndex = 4;
            this->userPhone2->Text = L"+38 (098) 198 44 24";
            // 
            // userEmail2
            // 
            this->userEmail2->AutoSize = true;
            this->userEmail2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->userEmail2->Location = System::Drawing::Point(111, 56);
            this->userEmail2->Name = L"userEmail2";
            this->userEmail2->Size = System::Drawing::Size(214, 18);
            this->userEmail2->TabIndex = 3;
            this->userEmail2->Text = L"alexander_develop@gmail.com";
            // 
            // userPosition2
            // 
            this->userPosition2->AutoSize = true;
            this->userPosition2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->userPosition2->Location = System::Drawing::Point(111, 34);
            this->userPosition2->Name = L"userPosition2";
            this->userPosition2->Size = System::Drawing::Size(194, 18);
            this->userPosition2->TabIndex = 2;
            this->userPosition2->Text = L"Lead Independent Developer";
            // 
            // userName2
            // 
            this->userName2->AutoSize = true;
            this->userName2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->userName2->Location = System::Drawing::Point(111, 10);
            this->userName2->Name = L"userName2";
            this->userName2->Size = System::Drawing::Size(92, 20);
            this->userName2->TabIndex = 1;
            this->userName2->Text = L"Alexander";
            // 
            // userPhoto2
            // 
            this->userPhoto2->Location = System::Drawing::Point(21, 10);
            this->userPhoto2->Name = L"userPhoto2";
            this->userPhoto2->Size = System::Drawing::Size(84, 84);
            this->userPhoto2->TabIndex = 0;
            this->userPhoto2->TabStop = false;
            // 
            // userPanel1
            // 
            this->userPanel1->Controls->Add(this->userPhone1);
            this->userPanel1->Controls->Add(this->userEmail1);
            this->userPanel1->Controls->Add(this->userPosition1);
            this->userPanel1->Controls->Add(this->userName1);
            this->userPanel1->Controls->Add(this->userPhoto1);
            this->userPanel1->Location = System::Drawing::Point(20, 39);
            this->userPanel1->Name = L"userPanel1";
            this->userPanel1->Size = System::Drawing::Size(552, 104);
            this->userPanel1->TabIndex = 10;
            // 
            // userPhone1
            // 
            this->userPhone1->AutoSize = true;
            this->userPhone1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->userPhone1->Location = System::Drawing::Point(111, 78);
            this->userPhone1->Name = L"userPhone1";
            this->userPhone1->Size = System::Drawing::Size(139, 18);
            this->userPhone1->TabIndex = 4;
            this->userPhone1->Text = L"+38 (098) 198 44 24";
            // 
            // userEmail1
            // 
            this->userEmail1->AutoSize = true;
            this->userEmail1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->userEmail1->Location = System::Drawing::Point(111, 56);
            this->userEmail1->Name = L"userEmail1";
            this->userEmail1->Size = System::Drawing::Size(214, 18);
            this->userEmail1->TabIndex = 3;
            this->userEmail1->Text = L"alexander_develop@gmail.com";
            // 
            // userPosition1
            // 
            this->userPosition1->AutoSize = true;
            this->userPosition1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->userPosition1->Location = System::Drawing::Point(111, 34);
            this->userPosition1->Name = L"userPosition1";
            this->userPosition1->Size = System::Drawing::Size(194, 18);
            this->userPosition1->TabIndex = 2;
            this->userPosition1->Text = L"Lead Independent Developer";
            // 
            // userName1
            // 
            this->userName1->AutoSize = true;
            this->userName1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->userName1->Location = System::Drawing::Point(111, 10);
            this->userName1->Name = L"userName1";
            this->userName1->Size = System::Drawing::Size(92, 20);
            this->userName1->TabIndex = 1;
            this->userName1->Text = L"Alexander";
            // 
            // userPhoto1
            // 
            this->userPhoto1->Location = System::Drawing::Point(21, 10);
            this->userPhoto1->Name = L"userPhoto1";
            this->userPhoto1->Size = System::Drawing::Size(84, 84);
            this->userPhoto1->TabIndex = 0;
            this->userPhoto1->TabStop = false;
            // 
            // headerLaber
            // 
            this->headerLaber->AutoSize = true;
            this->headerLaber->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->headerLaber->Location = System::Drawing::Point(255, 14);
            this->headerLaber->Name = L"headerLaber";
            this->headerLaber->Size = System::Drawing::Size(84, 22);
            this->headerLaber->TabIndex = 9;
            this->headerLaber->Text = L"Users list";
            // 
            // addUserPage
            // 
            this->addUserPage->Controls->Add(this->successPanel);
            this->addUserPage->Controls->Add(this->addUserPanel);
            this->addUserPage->Location = System::Drawing::Point(4, 54);
            this->addUserPage->Name = L"addUserPage";
            this->addUserPage->Padding = System::Windows::Forms::Padding(3);
            this->addUserPage->Size = System::Drawing::Size(592, 752);
            this->addUserPage->TabIndex = 1;
            this->addUserPage->Text = L"Add user";
            this->addUserPage->UseVisualStyleBackColor = true;
            // 
            // successPanel
            // 
            this->successPanel->Controls->Add(this->addOneMoreButton);
            this->successPanel->Controls->Add(this->usersListButton);
            this->successPanel->Controls->Add(this->successLabel);
            this->successPanel->Location = System::Drawing::Point(0, 0);
            this->successPanel->Name = L"successPanel";
            this->successPanel->Size = System::Drawing::Size(580, 397);
            this->successPanel->TabIndex = 92;
            this->successPanel->Visible = false;
            // 
            // addOneMoreButton
            // 
            this->addOneMoreButton->Location = System::Drawing::Point(300, 250);
            this->addOneMoreButton->Name = L"addOneMoreButton";
            this->addOneMoreButton->Size = System::Drawing::Size(131, 42);
            this->addOneMoreButton->TabIndex = 2;
            this->addOneMoreButton->Text = L"Add one more";
            this->addOneMoreButton->UseVisualStyleBackColor = true;
            this->addOneMoreButton->Click += gcnew System::EventHandler(this, &MainForm::addOneMoreButton_Click);
            // 
            // usersListButton
            // 
            this->usersListButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->usersListButton->Location = System::Drawing::Point(149, 250);
            this->usersListButton->Name = L"usersListButton";
            this->usersListButton->Size = System::Drawing::Size(131, 42);
            this->usersListButton->TabIndex = 1;
            this->usersListButton->Text = L"Users list";
            this->usersListButton->UseVisualStyleBackColor = true;
            this->usersListButton->Click += gcnew System::EventHandler(this, &MainForm::usersListButton_Click);
            // 
            // successLabel
            // 
            this->successLabel->AutoSize = true;
            this->successLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->successLabel->Location = System::Drawing::Point(165, 160);
            this->successLabel->Name = L"successLabel";
            this->successLabel->Size = System::Drawing::Size(255, 25);
            this->successLabel->TabIndex = 0;
            this->successLabel->Text = L"New user succesfully added";
            // 
            // addUserPanel
            // 
            this->addUserPanel->Controls->Add(this->photoTextBox);
            this->addUserPanel->Controls->Add(this->phoneTextBox);
            this->addUserPanel->Controls->Add(this->emailTextBox);
            this->addUserPanel->Controls->Add(this->nameLabel);
            this->addUserPanel->Controls->Add(this->nameTextBox);
            this->addUserPanel->Controls->Add(this->nameErrorLabel);
            this->addUserPanel->Controls->Add(this->position8);
            this->addUserPanel->Controls->Add(this->position7);
            this->addUserPanel->Controls->Add(this->position6);
            this->addUserPanel->Controls->Add(this->position5);
            this->addUserPanel->Controls->Add(this->position4);
            this->addUserPanel->Controls->Add(this->position3);
            this->addUserPanel->Controls->Add(this->position2);
            this->addUserPanel->Controls->Add(this->position1);
            this->addUserPanel->Controls->Add(this->addUserButton);
            this->addUserPanel->Controls->Add(this->uploadPhotoButton);
            this->addUserPanel->Controls->Add(this->photoLabel);
            this->addUserPanel->Controls->Add(this->positionsLabel);
            this->addUserPanel->Controls->Add(this->headerLabel);
            this->addUserPanel->Controls->Add(this->phoneExampleLabel);
            this->addUserPanel->Controls->Add(this->emailErrorLabel);
            this->addUserPanel->Controls->Add(this->Phone);
            this->addUserPanel->Controls->Add(this->emailLabel);
            this->addUserPanel->Location = System::Drawing::Point(6, 6);
            this->addUserPanel->Name = L"addUserPanel";
            this->addUserPanel->Size = System::Drawing::Size(583, 743);
            this->addUserPanel->TabIndex = 0;
            // 
            // photoTextBox
            // 
            this->photoTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->photoTextBox->Location = System::Drawing::Point(63, 661);
            this->photoTextBox->Name = L"photoTextBox";
            this->photoTextBox->Size = System::Drawing::Size(379, 24);
            this->photoTextBox->TabIndex = 80;
            // 
            // phoneTextBox
            // 
            this->phoneTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->phoneTextBox->Location = System::Drawing::Point(63, 260);
            this->phoneTextBox->Name = L"phoneTextBox";
            this->phoneTextBox->Size = System::Drawing::Size(432, 24);
            this->phoneTextBox->TabIndex = 73;
            this->phoneTextBox->TextChanged += gcnew System::EventHandler(this, &MainForm::phoneTextBox_TextChanged);
            // 
            // emailTextBox
            // 
            this->emailTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->emailTextBox->ForeColor = System::Drawing::SystemColors::WindowText;
            this->emailTextBox->Location = System::Drawing::Point(63, 170);
            this->emailTextBox->Name = L"emailTextBox";
            this->emailTextBox->Size = System::Drawing::Size(432, 24);
            this->emailTextBox->TabIndex = 71;
            this->emailTextBox->TextChanged += gcnew System::EventHandler(this, &MainForm::emailTextBox_TextChanged);
            // 
            // nameLabel
            // 
            this->nameLabel->AutoSize = true;
            this->nameLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->nameLabel->Location = System::Drawing::Point(60, 58);
            this->nameLabel->Name = L"nameLabel";
            this->nameLabel->Size = System::Drawing::Size(48, 18);
            this->nameLabel->TabIndex = 70;
            this->nameLabel->Text = L"Name";
            // 
            // nameTextBox
            // 
            this->nameTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->nameTextBox->Location = System::Drawing::Point(63, 81);
            this->nameTextBox->Name = L"nameTextBox";
            this->nameTextBox->Size = System::Drawing::Size(432, 24);
            this->nameTextBox->TabIndex = 69;
            this->nameTextBox->TextChanged += gcnew System::EventHandler(this, &MainForm::nameTextBox_TextChanged);
            // 
            // nameErrorLabel
            // 
            this->nameErrorLabel->AutoSize = true;
            this->nameErrorLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->nameErrorLabel->Location = System::Drawing::Point(60, 109);
            this->nameErrorLabel->Name = L"nameErrorLabel";
            this->nameErrorLabel->Size = System::Drawing::Size(160, 18);
            this->nameErrorLabel->TabIndex = 91;
            this->nameErrorLabel->Text = L"min 2, max 60 symbols";
            // 
            // position8
            // 
            this->position8->AutoSize = true;
            this->position8->Location = System::Drawing::Point(63, 559);
            this->position8->Name = L"position8";
            this->position8->Size = System::Drawing::Size(82, 20);
            this->position8->TabIndex = 90;
            this->position8->TabStop = true;
            this->position8->Text = L"position8";
            this->position8->UseVisualStyleBackColor = true;
            // 
            // position7
            // 
            this->position7->AutoSize = true;
            this->position7->Location = System::Drawing::Point(63, 533);
            this->position7->Name = L"position7";
            this->position7->Size = System::Drawing::Size(82, 20);
            this->position7->TabIndex = 89;
            this->position7->TabStop = true;
            this->position7->Text = L"position7";
            this->position7->UseVisualStyleBackColor = true;
            // 
            // position6
            // 
            this->position6->AutoSize = true;
            this->position6->Location = System::Drawing::Point(63, 507);
            this->position6->Name = L"position6";
            this->position6->Size = System::Drawing::Size(82, 20);
            this->position6->TabIndex = 88;
            this->position6->TabStop = true;
            this->position6->Text = L"position6";
            this->position6->UseVisualStyleBackColor = true;
            // 
            // position5
            // 
            this->position5->AutoSize = true;
            this->position5->Location = System::Drawing::Point(63, 481);
            this->position5->Name = L"position5";
            this->position5->Size = System::Drawing::Size(82, 20);
            this->position5->TabIndex = 87;
            this->position5->TabStop = true;
            this->position5->Text = L"position5";
            this->position5->UseVisualStyleBackColor = true;
            // 
            // position4
            // 
            this->position4->AutoSize = true;
            this->position4->Location = System::Drawing::Point(63, 455);
            this->position4->Name = L"position4";
            this->position4->Size = System::Drawing::Size(82, 20);
            this->position4->TabIndex = 86;
            this->position4->TabStop = true;
            this->position4->Text = L"position4";
            this->position4->UseVisualStyleBackColor = true;
            // 
            // position3
            // 
            this->position3->AutoSize = true;
            this->position3->Location = System::Drawing::Point(63, 429);
            this->position3->Name = L"position3";
            this->position3->Size = System::Drawing::Size(82, 20);
            this->position3->TabIndex = 85;
            this->position3->TabStop = true;
            this->position3->Text = L"position3";
            this->position3->UseVisualStyleBackColor = true;
            // 
            // position2
            // 
            this->position2->AutoSize = true;
            this->position2->Location = System::Drawing::Point(63, 403);
            this->position2->Name = L"position2";
            this->position2->Size = System::Drawing::Size(82, 20);
            this->position2->TabIndex = 84;
            this->position2->TabStop = true;
            this->position2->Text = L"position2";
            this->position2->UseVisualStyleBackColor = true;
            // 
            // position1
            // 
            this->position1->AutoSize = true;
            this->position1->Location = System::Drawing::Point(63, 377);
            this->position1->Name = L"position1";
            this->position1->Size = System::Drawing::Size(82, 20);
            this->position1->TabIndex = 83;
            this->position1->TabStop = true;
            this->position1->Text = L"position1";
            this->position1->UseVisualStyleBackColor = true;
            // 
            // addUserButton
            // 
            this->addUserButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->addUserButton->Location = System::Drawing::Point(223, 691);
            this->addUserButton->Name = L"addUserButton";
            this->addUserButton->Size = System::Drawing::Size(120, 35);
            this->addUserButton->TabIndex = 82;
            this->addUserButton->Text = L"Add user";
            this->addUserButton->UseVisualStyleBackColor = true;
            this->addUserButton->Click += gcnew System::EventHandler(this, &MainForm::addUserButton_Click);
            // 
            // uploadPhotoButton
            // 
            this->uploadPhotoButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->uploadPhotoButton->Location = System::Drawing::Point(448, 659);
            this->uploadPhotoButton->Name = L"uploadPhotoButton";
            this->uploadPhotoButton->Size = System::Drawing::Size(77, 28);
            this->uploadPhotoButton->TabIndex = 81;
            this->uploadPhotoButton->Text = L"Upload";
            this->uploadPhotoButton->UseVisualStyleBackColor = true;
            this->uploadPhotoButton->Click += gcnew System::EventHandler(this, &MainForm::uploadPhotoButton_Click);
            // 
            // photoLabel
            // 
            this->photoLabel->AutoSize = true;
            this->photoLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->photoLabel->Location = System::Drawing::Point(57, 625);
            this->photoLabel->Name = L"photoLabel";
            this->photoLabel->Size = System::Drawing::Size(48, 18);
            this->photoLabel->TabIndex = 79;
            this->photoLabel->Text = L"Photo";
            // 
            // positionsLabel
            // 
            this->positionsLabel->AutoSize = true;
            this->positionsLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->positionsLabel->Location = System::Drawing::Point(60, 327);
            this->positionsLabel->Name = L"positionsLabel";
            this->positionsLabel->Size = System::Drawing::Size(70, 18);
            this->positionsLabel->TabIndex = 78;
            this->positionsLabel->Text = L"Positions";
            // 
            // headerLabel
            // 
            this->headerLabel->AutoSize = true;
            this->headerLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->headerLabel->Location = System::Drawing::Point(243, 16);
            this->headerLabel->Name = L"headerLabel";
            this->headerLabel->Size = System::Drawing::Size(82, 22);
            this->headerLabel->TabIndex = 77;
            this->headerLabel->Text = L"Add user";
            // 
            // phoneExampleLabel
            // 
            this->phoneExampleLabel->AutoSize = true;
            this->phoneExampleLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->phoneExampleLabel->Location = System::Drawing::Point(60, 289);
            this->phoneExampleLabel->Name = L"phoneExampleLabel";
            this->phoneExampleLabel->Size = System::Drawing::Size(147, 18);
            this->phoneExampleLabel->TabIndex = 76;
            this->phoneExampleLabel->Text = L"+38 (xxx) xxx - xx - xx";
            // 
            // emailErrorLabel
            // 
            this->emailErrorLabel->AutoSize = true;
            this->emailErrorLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->emailErrorLabel->Location = System::Drawing::Point(60, 199);
            this->emailErrorLabel->Name = L"emailErrorLabel";
            this->emailErrorLabel->Size = System::Drawing::Size(79, 18);
            this->emailErrorLabel->TabIndex = 75;
            this->emailErrorLabel->Text = L"error email";
            // 
            // Phone
            // 
            this->Phone->AutoSize = true;
            this->Phone->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->Phone->Location = System::Drawing::Point(60, 237);
            this->Phone->Name = L"Phone";
            this->Phone->Size = System::Drawing::Size(51, 18);
            this->Phone->TabIndex = 74;
            this->Phone->Text = L"Phone";
            // 
            // emailLabel
            // 
            this->emailLabel->AutoSize = true;
            this->emailLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->emailLabel->Location = System::Drawing::Point(60, 147);
            this->emailLabel->Name = L"emailLabel";
            this->emailLabel->Size = System::Drawing::Size(45, 18);
            this->emailLabel->TabIndex = 72;
            this->emailLabel->Text = L"Email";
            // 
            // MainForm
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(800, 1000);
            this->Controls->Add(this->tabs);
            this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
            this->Name = L"MainForm";
            this->Text = L"MainForm";
            this->tabs->ResumeLayout(false);
            this->usersPage->ResumeLayout(false);
            this->usersPage->PerformLayout();
            this->userPanel6->ResumeLayout(false);
            this->userPanel6->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->userPhoto6))->EndInit();
            this->userPanel5->ResumeLayout(false);
            this->userPanel5->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->userPhoto5))->EndInit();
            this->userPanel4->ResumeLayout(false);
            this->userPanel4->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->userPhoto4))->EndInit();
            this->userPanel3->ResumeLayout(false);
            this->userPanel3->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->userPhoto3))->EndInit();
            this->userPanel2->ResumeLayout(false);
            this->userPanel2->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->userPhoto2))->EndInit();
            this->userPanel1->ResumeLayout(false);
            this->userPanel1->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->userPhoto1))->EndInit();
            this->addUserPage->ResumeLayout(false);
            this->successPanel->ResumeLayout(false);
            this->successPanel->PerformLayout();
            this->addUserPanel->ResumeLayout(false);
            this->addUserPanel->PerformLayout();
            this->ResumeLayout(false);

        }
#pragma endregion
        private: System::Void showMore_Click(System::Object^ sender, System::EventArgs^ e) {
            showMore->Visible = false;
            FillUsersPage(false);
            showMore->Visible = true;
        }

        private: System::Void tabs_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
            if (tabs->SelectedIndex != 1) //Add user tab
                return;

            /// Positions filling
            std::string positions_responce;
            Json::Reader reader;
            Json::Value json_positions;

            try {
                positions_responce = RESTClient::get_positions();
            }
            catch (std::string e) {
                String^ message = gcnew String(e.c_str());
                MessageBox::Show(message);
                exit(0);
            }

            reader.parse(positions_responce, json_positions);

            HideAllPositions();

            FillPosition(position1, json_positions, 1);
            FillPosition(position2, json_positions, 2);
            FillPosition(position3, json_positions, 3);
            FillPosition(position4, json_positions, 4);
            FillPosition(position5, json_positions, 5);
            FillPosition(position6, json_positions, 6);
            FillPosition(position7, json_positions, 7);
            FillPosition(position8, json_positions, 8);

            // Errors messages hiding
            nameErrorLabel->Visible = false;
            emailErrorLabel->Visible = false;
        }

        private: System::Void nameTextBox_TextChanged(System::Object^ sender, System::EventArgs^ e) {
            if (IsValidName()) {
                nameErrorLabel->Visible = false;
            }
            else {
                nameErrorLabel->Visible = true;
            }
        }
        private: System::Void emailTextBox_TextChanged(System::Object^ sender, System::EventArgs^ e) {
            if (IsValidEmail()) {
                emailErrorLabel->Visible = false;
            }
            else {
                emailErrorLabel->Visible = true;
            }
        }
        
        private: System::Void phoneTextBox_TextChanged(System::Object^ sender, System::EventArgs^ e) {
            std::string text = msclr::interop::marshal_as<std::string>(phoneTextBox->Text);

            if (!(text.length() == 1 && text[0] == '+'))
                text.erase(std::remove_if(text.begin(), text.end(), ifNotDigit), text.end());

            FormatText(text, 0, '+');
            FormatText(text, 1, '3');
            FormatText(text, 2, '8');
            FormatText(text, 3, ' ');
            FormatText(text, 4, '(');
            FormatText(text, 5, '0');
            FormatText(text, 8, ')');
            FormatText(text, 9, ' ');
            FormatText(text, 13, ' ');
            FormatText(text, 14, '-');
            FormatText(text, 15, ' ');
            FormatText(text, 18, ' ');
            FormatText(text, 19, '-');
            FormatText(text, 20, ' ');

            if (text.length() > 23) {
                text.resize(23);
            }

            phoneTextBox->Text = gcnew String(text.c_str());
            phoneTextBox->SelectionStart = (int)text.size();
        }
        private: System::Void uploadPhotoButton_Click(System::Object^ sender, System::EventArgs^ e) {
            OpenFileDialog^ fileDialog = gcnew OpenFileDialog();

            fileDialog->InitialDirectory = "c:\\";
            fileDialog->Filter = "Image Files(*.jpg;*.jpeg) | *.jpg;.jpeg";

            if (fileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
                photoTextBox->Text = fileDialog->FileName;
            }
        }
        private: System::Void addUserButton_Click(System::Object^ sender, System::EventArgs^ e) {
            if (!EnteredDataChecks())
                return;

            std::string name = msclr::interop::marshal_as<std::string>(nameTextBox->Text);
            std::string email = msclr::interop::marshal_as<std::string>(emailTextBox->Text);
            std::string photo = msclr::interop::marshal_as<std::string>(photoTextBox->Text);
            size_t position_id = GetSelectedPositionId();
            std::string phone = msclr::interop::marshal_as<std::string>(phoneTextBox->Text);
            std::pair<size_t, std::string> responce;

            phone.erase(std::remove_if(phone.begin(), phone.end(), ifNotDigit), phone.end());
            phone = "+" + phone;

            try {
                responce = RESTClient::post_user(name, email, phone, position_id, photo);
            }
            catch (std::string e) {
                String^ message = gcnew String(e.c_str());
                MessageBox::Show(message);
                exit(0);
            }

            if (responce.first == 409) {
                MessageBox::Show("User with this phone or email already exist");
                return;
            }

            if (responce.first == 422) {
                Json::Reader reader;
                Json::Value json_responce;
                reader.parse(responce.second, json_responce);

                if (json_responce["fails"]["photo"].is<Json::String>()) {
                    String^ message = gcnew String(std::string(json_responce["fails"]["photo"][0].asCString()).c_str());
                    MessageBox::Show(message);
                    return;
                }
            }

            addUserPanel->Visible = false;
            successPanel->Visible = true;
            FillUsersPage(true);
        }

        private: System::Void usersListButton_Click(System::Object^ sender, System::EventArgs^ e) {
            tabs->SelectedTab = usersPage;
        }

        private: System::Void addOneMoreButton_Click(System::Object^ sender, System::EventArgs^ e) {
            nameTextBox->Text = "";
            emailTextBox->Text = "";
            phoneTextBox->Text = "";
            photoTextBox->Text = "";

            tabs_SelectedIndexChanged(nullptr, nullptr);
            
            addUserPanel->Visible = true;
            successPanel->Visible = false;
        }
    };
}
