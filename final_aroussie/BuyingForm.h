#pragma once
#include "BuyingReceipt.h"
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

	public ref class BuyingForm : public System::Windows::Forms::Form
	{
	public:

		BuyingForm(Form^ form)
		{
			InitializeComponent();

			//Disable the focus on an error
			this->AutoValidate = System::Windows::Forms::AutoValidate::Disable;
			/*Input Validator listeners*/
			this->input_balance->Validating += gcnew System::ComponentModel::CancelEventHandler(this, &BuyingForm::input_balance_Validating);
			this->input_symbol->Validating += gcnew System::ComponentModel::CancelEventHandler(this, &BuyingForm::input_symbol_Validating);
			this->input_number->Validating += gcnew System::ComponentModel::CancelEventHandler(this, &BuyingForm::input_number_Validating);
			this->input_price->Validating += gcnew System::ComponentModel::CancelEventHandler(this, &BuyingForm::input_price_Validating);

			home = form;
		}

	protected:

		~BuyingForm()
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
	private: System::Windows::Forms::Form^   home;
	private: System::Windows::Forms::Label^  label_title;
	private: System::Windows::Forms::Label^  label_balance;
	private: System::Windows::Forms::Label^  label_symbol;
	private: System::Windows::Forms::Label^  label_number;
	private: System::Windows::Forms::Label^  label_date;
	private: System::Windows::Forms::Label^  label_price;
	private: System::Windows::Forms::TextBox^  input_balance;
	private: System::Windows::Forms::TextBox^  input_symbol;
	private: System::Windows::Forms::TextBox^  input_number;
	private: System::Windows::Forms::TextBox^  input_price;
	private: System::Windows::Forms::MonthCalendar^  input_date;
	private: System::Windows::Forms::ErrorProvider^  errorProvider1;
	private: System::Windows::Forms::Button^  cancel_btn;
	private: System::Windows::Forms::Button^  btn_calculate;

	private:
		//Calculate the total price of the purchase
		float CalculateTotalPrice() {
			//Get the number of shares to purchase
			int nbShares = Int32::Parse(input_number->Text);
			//Get the price of one share
			float priceByUnit = float::Parse(input_price->Text);
			//Calculate the fee of the transaction
			float brokerageFee = nbShares * priceByUnit * 0.10;
			//Calculate the total price
			float totalPrice = nbShares * priceByUnit + brokerageFee;

			return totalPrice;
		}

	//Save the information into the file
	private: void saveTransaction(float totalPrice) {
		//Open the file in append mode
		ofstream file("Log.txt", ios::app);
		/*Get the information to save*/
		string date = msclr::interop::marshal_as<string>(input_date->SelectionStart.ToString("ddd dd MMM yyyy"));
		float balance = float::Parse(input_balance->Text);
		int numberShares = Int32::Parse(input_number->Text);
		string symbol = msclr::interop::marshal_as<string>(input_symbol->Text);
		float priceByUnit = float::Parse(input_price->Text);
		string str = "Type of transaction: Buying";

		/*Save data into the file*/
		file << str << endl;
		file << "Balance: " << balance << " $" << endl;
		file << "Date of the purchase: " + date << endl;
		file << "Stock symbol: " + symbol << endl;
		file << "Number of shares purchased: " << numberShares << endl;
		file << "Price by unit: " << priceByUnit << " $" << endl;
		file << "Total price of the purchase: " << totalPrice << " $" << endl;
		file << "-----------------------------------------" << endl;
		file.close();
	}

	private: System::ComponentModel::IContainer^  components;


	//Check that the balance field is right
	private: System::Void input_balance_Validating(System::Object ^  sender,
		System::ComponentModel::CancelEventArgs ^  e)
	{

		bool cancel = false;
		float number = -1;
		//First we check that it's a float
		if (float::TryParse(input_balance->Text, number)) {
			//Check the balance is enough
			if (number > 4999) {
				//This control passes the validation
				cancel = false;
				errorProvider1->SetError(input_balance, "");
			}
			else {
				cancel = true;
				errorProvider1->SetError(input_balance, "Your balance is under 5000$. Please add money into your account");
			}
		}
		else {
			//If we are here the input is not a float number(or is empty)
			cancel = true;
			errorProvider1->SetError(input_balance, "You must put a number !");
		}

		e->Cancel = cancel;

	}
	//Check that the stock symbol is correctly fulfilled
	private: System::Void input_symbol_Validating(System::Object ^  sender,
		System::ComponentModel::CancelEventArgs ^  e)
	{
		bool cancel = false;
		//If the field is empty, we display the error
		if (input_symbol->Text->Trim() == "") {
			cancel = true;
			errorProvider1->SetError(input_symbol, "You must put a stock symbol !");
		}
		else {
			cancel = false;
			errorProvider1->SetError(input_symbol, "");
		}

		e->Cancel = cancel;

	}
	//Check the number of shares field
	private: System::Void input_number_Validating(System::Object ^  sender,
		System::ComponentModel::CancelEventArgs ^  e)
	{
		bool cancel = false;
		int number = -1;
		//Check that it's a integer
		if (Int32::TryParse(input_number->Text, number)) {
			cancel = false;
			errorProvider1->SetError(input_number, "");
		}
		else {
			cancel = true;
			errorProvider1->SetError(input_number, "You must put an integer !");
		}

		e->Cancel = cancel;

	}
	//Check the price field
	private: System::Void input_price_Validating(System::Object ^  sender,
		System::ComponentModel::CancelEventArgs ^  e)
	{
		bool cancel = false;
		float number = -1;
		//Check that it's a integer
		if (float::TryParse(input_price->Text, number)) {
			cancel = false;
			errorProvider1->SetError(input_price, "");
		}
		else {
			cancel = true;
			errorProvider1->SetError(input_price, "You must put a number !");
		}

		e->Cancel = cancel;

	}

#pragma region Windows Form Designer generated code

			 /*Initialize the design*/
			 void InitializeComponent(void)
			 {
				 this->components = (gcnew System::ComponentModel::Container());
				 this->label_title = (gcnew System::Windows::Forms::Label());
				 this->label_balance = (gcnew System::Windows::Forms::Label());
				 this->label_symbol = (gcnew System::Windows::Forms::Label());
				 this->label_number = (gcnew System::Windows::Forms::Label());
				 this->label_date = (gcnew System::Windows::Forms::Label());
				 this->label_price = (gcnew System::Windows::Forms::Label());
				 this->input_balance = (gcnew System::Windows::Forms::TextBox());
				 this->input_symbol = (gcnew System::Windows::Forms::TextBox());
				 this->input_number = (gcnew System::Windows::Forms::TextBox());
				 this->input_price = (gcnew System::Windows::Forms::TextBox());
				 this->input_date = (gcnew System::Windows::Forms::MonthCalendar());
				 this->btn_calculate = (gcnew System::Windows::Forms::Button());
				 this->errorProvider1 = (gcnew System::Windows::Forms::ErrorProvider(this->components));
				 this->cancel_btn = (gcnew System::Windows::Forms::Button());
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->errorProvider1))->BeginInit();
				 this->SuspendLayout();
				 // 
				 // label_title
				 // 
				 this->label_title->AutoSize = true;
				 this->label_title->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->label_title->Location = System::Drawing::Point(13, 13);
				 this->label_title->Name = L"label_title";
				 this->label_title->Size = System::Drawing::Size(142, 24);
				 this->label_title->TabIndex = 0;
				 this->label_title->Text = L"Buying shares";
				 // 
				 // label_balance
				 // 
				 this->label_balance->AutoSize = true;
				 this->label_balance->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->label_balance->Location = System::Drawing::Point(13, 100);
				 this->label_balance->Name = L"label_balance";
				 this->label_balance->Size = System::Drawing::Size(53, 13);
				 this->label_balance->TabIndex = 1;
				 this->label_balance->Text = L"Balance";
				 // 
				 // label_symbol
				 // 
				 this->label_symbol->AutoSize = true;
				 this->label_symbol->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->label_symbol->Location = System::Drawing::Point(13, 145);
				 this->label_symbol->Name = L"label_symbol";
				 this->label_symbol->Size = System::Drawing::Size(82, 13);
				 this->label_symbol->TabIndex = 2;
				 this->label_symbol->Text = L"Stock symbol";
				 // 
				 // label_number
				 // 
				 this->label_number->AutoSize = true;
				 this->label_number->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->label_number->Location = System::Drawing::Point(13, 188);
				 this->label_number->Name = L"label_number";
				 this->label_number->Size = System::Drawing::Size(145, 13);
				 this->label_number->TabIndex = 3;
				 this->label_number->Text = L"Number of shares to buy";
				 // 
				 // label_date
				 // 
				 this->label_date->AutoSize = true;
				 this->label_date->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->label_date->Location = System::Drawing::Point(13, 300);
				 this->label_date->Name = L"label_date";
				 this->label_date->Size = System::Drawing::Size(127, 13);
				 this->label_date->TabIndex = 4;
				 this->label_date->Text = L"Date of the purchase";
				 // 
				 // label_price
				 // 
				 this->label_price->AutoSize = true;
				 this->label_price->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->label_price->Location = System::Drawing::Point(22, 419);
				 this->label_price->Name = L"label_price";
				 this->label_price->Size = System::Drawing::Size(116, 13);
				 this->label_price->TabIndex = 5;
				 this->label_price->Text = L"Price of ONE share";
				 // 
				 // input_balance
				 // 
				 this->input_balance->Location = System::Drawing::Point(191, 100);
				 this->input_balance->Name = L"input_balance";
				 this->input_balance->Size = System::Drawing::Size(227, 20);
				 this->input_balance->TabIndex = 6;
				 // 
				 // input_symbol
				 // 
				 this->input_symbol->Location = System::Drawing::Point(191, 145);
				 this->input_symbol->Name = L"input_symbol";
				 this->input_symbol->Size = System::Drawing::Size(227, 20);
				 this->input_symbol->TabIndex = 7;
				 // 
				 // input_number
				 // 
				 this->input_number->Location = System::Drawing::Point(191, 180);
				 this->input_number->Name = L"input_number";
				 this->input_number->Size = System::Drawing::Size(227, 20);
				 this->input_number->TabIndex = 8;
				 // 
				 // input_price
				 // 
				 this->input_price->Location = System::Drawing::Point(191, 416);
				 this->input_price->Name = L"input_price";
				 this->input_price->Size = System::Drawing::Size(227, 20);
				 this->input_price->TabIndex = 9;
				 // 
				 // input_date
				 // 
				 this->input_date->Location = System::Drawing::Point(191, 223);
				 this->input_date->MaxSelectionCount = 1;
				 this->input_date->Name = L"input_date";
				 this->input_date->TabIndex = 10;
				 this->input_date->MinDate = System::DateTime::Now;
				 // 
				 // btn_calculate
				 // 
				 this->btn_calculate->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->btn_calculate->ForeColor = System::Drawing::Color::Black;
				 this->btn_calculate->Location = System::Drawing::Point(191, 466);
				 this->btn_calculate->Name = L"btn_calculate";
				 this->btn_calculate->Size = System::Drawing::Size(75, 23);
				 this->btn_calculate->TabIndex = 11;
				 this->btn_calculate->Text = L"Calculate";
				 this->btn_calculate->UseVisualStyleBackColor = true;
				 this->btn_calculate->Click += gcnew System::EventHandler(this, &BuyingForm::btn_calculate_Click);
				 // 
				 // errorProvider1
				 // 
				 this->errorProvider1->ContainerControl = this;
				 // 
				 // cancel_btn
				 // 
				 this->cancel_btn->BackColor = System::Drawing::Color::Red;
				 this->cancel_btn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->cancel_btn->ForeColor = System::Drawing::Color::Black;
				 this->cancel_btn->Location = System::Drawing::Point(335, 466);
				 this->cancel_btn->Name = L"cancel_btn";
				 this->cancel_btn->Size = System::Drawing::Size(75, 23);
				 this->cancel_btn->TabIndex = 12;
				 this->cancel_btn->Text = L"Cancel";
				 this->cancel_btn->UseVisualStyleBackColor = false;
				 this->cancel_btn->Click += gcnew System::EventHandler(this, &BuyingForm::cancel_btn_Click);
				 // 
				 // BuyingForm
				 // 
				 this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
				 this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
				 this->BackColor = System::Drawing::SystemColors::AppWorkspace;
				 this->ClientSize = System::Drawing::Size(540, 519);
				 this->Controls->Add(this->cancel_btn);
				 this->Controls->Add(this->btn_calculate);
				 this->Controls->Add(this->input_date);
				 this->Controls->Add(this->input_price);
				 this->Controls->Add(this->input_number);
				 this->Controls->Add(this->input_symbol);
				 this->Controls->Add(this->input_balance);
				 this->Controls->Add(this->label_price);
				 this->Controls->Add(this->label_date);
				 this->Controls->Add(this->label_number);
				 this->Controls->Add(this->label_symbol);
				 this->Controls->Add(this->label_balance);
				 this->Controls->Add(this->label_title);
				 this->Name = L"BuyingForm";
				 this->Text = L"BuyingForm";
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->errorProvider1))->EndInit();
				 this->ResumeLayout(false);
				 this->PerformLayout();

			 }
#pragma endregion

	//When the user clicks on calculate
	private: System::Void btn_calculate_Click(System::Object^  sender, System::EventArgs^  e) {

		BuyingReceipt^ receipt = gcnew BuyingReceipt(home);

		//If all the fiels are OK
		if (this->ValidateChildren(ValidationConstraints::Enabled)) {
			//Get the total price of the buying
			float totalPrice = CalculateTotalPrice();
			//Save the data into the file
			saveTransaction(totalPrice);
			// Set all the fields of the receipt
			receipt->setStock(input_symbol->Text);
			receipt->setNbShares(Int32::Parse(input_number->Text));
			receipt->setPrice(totalPrice);
			receipt->setDate(input_date->SelectionStart.ToString("ddd dd MMM yyyy"));

			this->Hide();
			receipt->Show();
		}
	}

	//If the user cliks on cancel
	private: System::Void cancel_btn_Click(System::Object^  sender, System::EventArgs^  e) {
		this->Hide();
		home->Show();
	}
	};
}
