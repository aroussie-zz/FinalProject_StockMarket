#pragma once
#include "BuyingForm.h"
#include "SellingForm.h"

namespace final_aroussie {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace final_aroussie;

	public ref class Home : public System::Windows::Forms::Form
	{
	public:
		Home()
		{
			InitializeComponent();

		}

	protected:

		~Home()
		{
			if (components)
			{
				delete components;
			}
		}
	//Exit the app if the user close the window
	protected: virtual void OnClosed(EventArgs^ e) override
	{
		Application::Exit();
	}

	/*The design*/
	private: System::Windows::Forms::Label^  label_home;
	private: System::Windows::Forms::Label^  label_question;
	private: System::Windows::Forms::Button^  btn_buying;
	private: System::Windows::Forms::Button^  btn_selling;
	private: System::Windows::Forms::Button^  btn_exit;
	private: System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code

			 /*Initialize all the design*/
			 void InitializeComponent(void)
			 {
				 this->label_home = (gcnew System::Windows::Forms::Label());
				 this->label_question = (gcnew System::Windows::Forms::Label());
				 this->btn_buying = (gcnew System::Windows::Forms::Button());
				 this->btn_selling = (gcnew System::Windows::Forms::Button());
				 this->btn_exit = (gcnew System::Windows::Forms::Button());
				 this->SuspendLayout();
				 // 
				 // label_home
				 // 
				 this->label_home->AutoSize = true;
				 this->label_home->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 35, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->label_home->Location = System::Drawing::Point(146, 54);
				 this->label_home->Name = L"label_home";
				 this->label_home->Size = System::Drawing::Size(148, 54);
				 this->label_home->TabIndex = 0;
				 this->label_home->Text = L"Home";
				 // 
				 // label_question
				 // 
				 this->label_question->AutoSize = true;
				 this->label_question->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->label_question->Location = System::Drawing::Point(109, 151);
				 this->label_question->Name = L"label_question";
				 this->label_question->Size = System::Drawing::Size(222, 24);
				 this->label_question->TabIndex = 1;
				 this->label_question->Text = L"What do you want to do \?";
				 // 
				 // btn_buying
				 // 
				 this->btn_buying->BackColor = System::Drawing::Color::Lime;
				 this->btn_buying->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->btn_buying->Location = System::Drawing::Point(62, 243);
				 this->btn_buying->Name = L"btn_buying";
				 this->btn_buying->Size = System::Drawing::Size(144, 84);
				 this->btn_buying->TabIndex = 2;
				 this->btn_buying->Text = L"buying";
				 this->btn_buying->UseVisualStyleBackColor = false;
				 this->btn_buying->Click += gcnew System::EventHandler(this, &Home::btn_buying_Click);
				 // 
				 // btn_selling
				 // 
				 this->btn_selling->BackColor = System::Drawing::Color::Yellow;
				 this->btn_selling->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->btn_selling->Location = System::Drawing::Point(233, 243);
				 this->btn_selling->Name = L"btn_selling";
				 this->btn_selling->Size = System::Drawing::Size(150, 84);
				 this->btn_selling->TabIndex = 3;
				 this->btn_selling->Text = L"selling";
				 this->btn_selling->UseVisualStyleBackColor = false;
				 this->btn_selling->Click += gcnew System::EventHandler(this, &Home::btn_selling_Click);
				 // 
				 // btn_exit
				 // 
				 this->btn_exit->BackColor = System::Drawing::Color::Red;
				 this->btn_exit->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->btn_exit->Location = System::Drawing::Point(173, 368);
				 this->btn_exit->Name = L"btn_exit";
				 this->btn_exit->Size = System::Drawing::Size(95, 43);
				 this->btn_exit->TabIndex = 4;
				 this->btn_exit->Text = L"Exit";
				 this->btn_exit->UseVisualStyleBackColor = false;
				 this->btn_exit->Click += gcnew System::EventHandler(this, &Home::btn_exit_Click);
				 // 
				 // Home
				 // 
				 this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
				 this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
				 this->BackColor = System::Drawing::SystemColors::AppWorkspace;
				 this->ClientSize = System::Drawing::Size(458, 448);
				 this->Controls->Add(this->btn_exit);
				 this->Controls->Add(this->btn_selling);
				 this->Controls->Add(this->btn_buying);
				 this->Controls->Add(this->label_question);
				 this->Controls->Add(this->label_home);
				 this->Name = L"Home";
				 this->Text = L"Home";
				 this->ResumeLayout(false);
				 this->PerformLayout();

			 }
#pragma endregion
	//When the user clicks on buying
	private: System::Void btn_buying_Click(System::Object^  sender, System::EventArgs^  e) {

		BuyingForm^ buyingform = gcnew BuyingForm(this);
		this->Hide();
		buyingform->Show();

	}
	//When the user clicks on selling 
	private: System::Void btn_selling_Click(System::Object^  sender, System::EventArgs^  e) {
		SellingForm^ sellingform = gcnew SellingForm(this);
		this->Hide();
		sellingform->Show();

	}
	//When the user clicks on Exit
	private: System::Void btn_exit_Click(System::Object^  sender, System::EventArgs^  e) {
		Application::Exit();
	}
	};
}
