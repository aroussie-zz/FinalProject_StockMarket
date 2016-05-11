#pragma once
#include "BuyingForm.h"
#include "SellingForm.h"
#include "Home.h"
#include <iostream>
#include <fstream>
#include <string>
#include <msclr/marshal_cppstd.h>


namespace final_aroussie {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;

	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:

		MyForm(void)
		{
			InitializeComponent();

			//Disable the focus on an error
			this->AutoValidate = System::Windows::Forms::AutoValidate::Disable;
			/*Input Validator listeners*/
			this->input_pin->Validating += gcnew System::ComponentModel::CancelEventHandler(this, &MyForm::input_pin_Validating);
		}

	protected:

		~MyForm()
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

	 /* the design*/
	private: System::Windows::Forms::TextBox^  input_pin;
	private: System::Windows::Forms::Button^  btn_connect;
	private: System::Windows::Forms::Label^  label_welcome;
	private: System::Windows::Forms::Button^  btn_buying;
	private: System::Windows::Forms::Button^  btn_selling;
	private: System::Windows::Forms::Label^  label_question;
	private: System::Windows::Forms::ErrorProvider^  errorProvider1;
	private: System::ComponentModel::IContainer^  components;

	//Check the pin Number is correct
	private: System::Void input_pin_Validating(System::Object ^  sender,
		System::ComponentModel::CancelEventArgs ^  e)
	{

		int number = -1;
		bool cancel = false;
		//Check if it's an integer
		if (Int32::TryParse(input_pin->Text, number)) {
			
			//This is a right PIN number
			 if (number > 6 && number < 7001) {
				cancel = false;
				errorProvider1->SetError(input_pin, "");
			}
		}
		else {
			//If we are here, the PIN entered is not an integer
			cancel = true;
			errorProvider1->SetError(input_pin, "You must put an integer !");
		}
		e->Cancel = cancel;

	}

#pragma region Windows Form Designer generated code

			 /*Initialize all the design*/
			 void InitializeComponent(void)
			 {
				 this->components = (gcnew System::ComponentModel::Container());
				 this->input_pin = (gcnew System::Windows::Forms::TextBox());
				 this->btn_connect = (gcnew System::Windows::Forms::Button());
				 this->label_welcome = (gcnew System::Windows::Forms::Label());
				 this->btn_buying = (gcnew System::Windows::Forms::Button());
				 this->btn_selling = (gcnew System::Windows::Forms::Button());
				 this->label_question = (gcnew System::Windows::Forms::Label());
				 this->errorProvider1 = (gcnew System::Windows::Forms::ErrorProvider(this->components));
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->errorProvider1))->BeginInit();
				 this->SuspendLayout();
				 // 
				 // textBox1
				 // 
				 this->input_pin->Location = System::Drawing::Point(108, 75);
				 this->input_pin->MaxLength = 4;
				 this->input_pin->Name = L"textBox1";
				 this->input_pin->Size = System::Drawing::Size(100, 20);
				 this->input_pin->TabIndex = 0;
				 // 
				 // btn_connect
				 // 
				 this->btn_connect->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->btn_connect->Location = System::Drawing::Point(264, 75);
				 this->btn_connect->Name = L"button1";
				 this->btn_connect->Size = System::Drawing::Size(75, 23);
				 this->btn_connect->TabIndex = 1;
				 this->btn_connect->Text = L"Connect";
				 this->btn_connect->UseVisualStyleBackColor = true;
				 this->btn_connect->Click += gcnew System::EventHandler(this, &MyForm::btn_connect_Click);
				 // 
				 // label1
				 // 
				 this->label_welcome->AutoSize = true;
				 this->label_welcome->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->label_welcome->Location = System::Drawing::Point(60, 28);
				 this->label_welcome->Name = L"label1";
				 this->label_welcome->Size = System::Drawing::Size(331, 24);
				 this->label_welcome->TabIndex = 3;
				 this->label_welcome->Text = L"Enter your PIN Number to connect";
				 // 
				 // btn_buying
				 // 
				 this->btn_buying->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->btn_buying->Location = System::Drawing::Point(121, 207);
				 this->btn_buying->Name = L"button2";
				 this->btn_buying->Size = System::Drawing::Size(75, 23);
				 this->btn_buying->TabIndex = 5;
				 this->btn_buying->Text = L"buying shares";
				 this->btn_buying->UseVisualStyleBackColor = true;
				 this->btn_buying->Click += gcnew System::EventHandler(this, &MyForm::btn_buying_Click);
				 // 
				 // btn_selling
				 // 
				 this->btn_selling->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->btn_selling->Location = System::Drawing::Point(264, 207);
				 this->btn_selling->Name = L"button3";
				 this->btn_selling->Size = System::Drawing::Size(75, 23);
				 this->btn_selling->TabIndex = 6;
				 this->btn_selling->Text = L"selling shares";
				 this->btn_selling->UseVisualStyleBackColor = true;
				 this->btn_selling->Click += gcnew System::EventHandler(this, &MyForm::btn_selling_Click);
				 // 
				 // label2
				 // 
				 this->label_question->AutoSize = true;
				 this->label_question->Font = (gcnew System::Drawing::Font(L"Arial", 14));
				 this->label_question->Location = System::Drawing::Point(117, 145);
				 this->label_question->Name = L"label2";
				 this->label_question->Size = System::Drawing::Size(223, 22);
				 this->label_question->TabIndex = 7;
				 this->label_question->Text = L"What do you want to do \?";
				 // 
				 // errorProvider1
				 // 
				 this->errorProvider1->ContainerControl = this;
				 // 
				 // MyForm
				 // 
				 this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
				 this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
				 this->BackColor = System::Drawing::SystemColors::AppWorkspace;
				 this->ClientSize = System::Drawing::Size(456, 406);
				 this->Controls->Add(this->btn_selling);
				 this->Controls->Add(this->btn_buying);
				 this->Controls->Add(this->label_welcome);
				 this->Controls->Add(this->label_question);
				 this->Controls->Add(this->btn_connect);
				 this->Controls->Add(this->input_pin);
				 this->btn_buying->Hide();
				 this->btn_selling->Hide();
				 this->label_question->Hide();
				 this->Name = L"MyForm";
				 this->Text = L"MyForm";
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->errorProvider1))->EndInit();
				 this->ResumeLayout(false);
				 this->PerformLayout();

			 }
#pragma endregion
	//When the user click on the connect button
	private: System::Void btn_connect_Click(System::Object^  sender, System::EventArgs^  e) {

		//If the pin number is right, we allow the user to continue
		if (this->ValidateChildren(ValidationConstraints::Enabled)) {

			//Erase the content of the log file
			createLog();

			this->label_question->Show();
			this->btn_buying->Show();
			this->btn_selling->Show();
		}
	}

	//When he user click on buying
	private: System::Void btn_buying_Click(System::Object^  sender, System::EventArgs^  e) {

		Home^ home = gcnew Home();
		this->Hide();
		BuyingForm^ buyingForm = gcnew BuyingForm(home);
		buyingForm->Show();
	}
	 //When the user click on selling
	private: System::Void btn_selling_Click(System::Object^  sender, System::EventArgs^  e) {

		Home^ home = gcnew Home();
		this->Hide();
		SellingForm^ sellingForm = gcnew SellingForm(home);
		sellingForm->Show();
	}
	//Erase the content of the previous log file and initiate a new one
	private: void createLog() {
		//Open the file in trunc mode to delete previous information
		ofstream file("Log.txt", ios::trunc);
		//Convert the input into a string
		int pin = Int32::Parse(input_pin->Text);
		string date = msclr::interop::marshal_as<string>(DateTime::Now.ToString());
		file << "Program launched with the PIN number " << pin << " on " << date << endl;
		file << endl;
		file.close();
		
	}
	};
}
