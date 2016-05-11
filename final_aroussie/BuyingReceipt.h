#pragma once


namespace final_aroussie {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;


	public ref class BuyingReceipt : public System::Windows::Forms::Form
	{
	public:

		/*Setters of the outputs(called in BuyingForm.h)*/
		void setNbShares(int nb) { this->output_number->Text = nb.ToString(); }
		void setStock(String^ str) { this->output_stock->Text = str; }
		void setPrice(float nb) { this->output_price->Text = nb.ToString() + " $"; }
		void setDate(String^date) { this->output_date->Text = date; }

		BuyingReceipt(Form^ form)
		{
			InitializeComponent();

			home = form;
		}

	protected:

		~BuyingReceipt()
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
	private: System::Windows::Forms::Form^  home;
	private: System::Windows::Forms::Label^  label_title;
	private: System::Windows::Forms::Label^  label_stock;
	private: System::Windows::Forms::Label^  label_number;
	private: System::Windows::Forms::Label^  label_price;
	private: System::Windows::Forms::Label^  output_stock;
	private: System::Windows::Forms::Label^  output_number;
	private: System::Windows::Forms::Label^  output_price;
	private: System::Windows::Forms::Label^  label_date;
	private: System::Windows::Forms::Label^  output_date;
	private: System::Windows::Forms::Label^  label_question;
	private: System::Windows::Forms::Button^  btn_home;
	private: System::Windows::Forms::Button^  btn_exit;


			 System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code

			 /*Initialize all the design*/
			 void InitializeComponent(void)
			 {
				 this->label_title = (gcnew System::Windows::Forms::Label());
				 this->label_stock = (gcnew System::Windows::Forms::Label());
				 this->label_number = (gcnew System::Windows::Forms::Label());
				 this->label_price = (gcnew System::Windows::Forms::Label());
				 this->output_stock = (gcnew System::Windows::Forms::Label());
				 this->output_number = (gcnew System::Windows::Forms::Label());
				 this->output_price = (gcnew System::Windows::Forms::Label());
				 this->label_date = (gcnew System::Windows::Forms::Label());
				 this->output_date = (gcnew System::Windows::Forms::Label());
				 this->label_question = (gcnew System::Windows::Forms::Label());
				 this->btn_home = (gcnew System::Windows::Forms::Button());
				 this->btn_exit = (gcnew System::Windows::Forms::Button());
				 this->SuspendLayout();
				 // 
				 // label_title
				 // 
				 this->label_title->AutoSize = true;
				 this->label_title->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->label_title->Location = System::Drawing::Point(12, 9);
				 this->label_title->Name = L"label_title";
				 this->label_title->Size = System::Drawing::Size(208, 24);
				 this->label_title->TabIndex = 0;
				 this->label_title->Text = L"Receipt of the buying";
				 // 
				 // label_stock
				 // 
				 this->label_stock->AutoSize = true;
				 this->label_stock->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->label_stock->Location = System::Drawing::Point(13, 135);
				 this->label_stock->Name = L"label_stock";
				 this->label_stock->Size = System::Drawing::Size(103, 13);
				 this->label_stock->TabIndex = 1;
				 this->label_stock->Text = L"Stock purchased";
				 // 
				 // label_number
				 // 
				 this->label_number->AutoSize = true;
				 this->label_number->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->label_number->Location = System::Drawing::Point(13, 181);
				 this->label_number->Name = L"label_number";
				 this->label_number->Size = System::Drawing::Size(169, 13);
				 this->label_number->TabIndex = 2;
				 this->label_number->Text = L"Number of shares purchased";
				 // 
				 // label_price
				 // 
				 this->label_price->AutoSize = true;
				 this->label_price->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->label_price->Location = System::Drawing::Point(13, 220);
				 this->label_price->Name = L"label_price";
				 this->label_price->Size = System::Drawing::Size(131, 13);
				 this->label_price->TabIndex = 3;
				 this->label_price->Text = L"Total purchased price";
				 // 
				 // output_stock
				 // 
				 this->output_stock->AutoSize = true;
				 this->output_stock->Location = System::Drawing::Point(205, 135);
				 this->output_stock->Name = L"output_stock";
				 this->output_stock->Size = System::Drawing::Size(35, 13);
				 this->output_stock->TabIndex = 4;
				 this->output_stock->Text = L"label1";
				 // 
				 // output_number
				 // 
				 this->output_number->AutoSize = true;
				 this->output_number->Location = System::Drawing::Point(205, 181);
				 this->output_number->Name = L"output_number";
				 this->output_number->Size = System::Drawing::Size(35, 13);
				 this->output_number->TabIndex = 5;
				 this->output_number->Text = L"label2";
				 // 
				 // output_price
				 // 
				 this->output_price->AutoSize = true;
				 this->output_price->Location = System::Drawing::Point(205, 220);
				 this->output_price->Name = L"output_price";
				 this->output_price->Size = System::Drawing::Size(35, 13);
				 this->output_price->TabIndex = 6;
				 this->output_price->Text = L"label3";
				 // 
				 // label_date
				 // 
				 this->label_date->AutoSize = true;
				 this->label_date->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->label_date->Location = System::Drawing::Point(13, 83);
				 this->label_date->Name = L"label_date";
				 this->label_date->Size = System::Drawing::Size(116, 13);
				 this->label_date->TabIndex = 7;
				 this->label_date->Text = L"Date of transaction";
				 // 
				 // output_date
				 // 
				 this->output_date->AutoSize = true;
				 this->output_date->Location = System::Drawing::Point(205, 83);
				 this->output_date->Name = L"output_date";
				 this->output_date->Size = System::Drawing::Size(35, 13);
				 this->output_date->TabIndex = 8;
				 this->output_date->Text = L"label2";
				 // 
				 // label_question
				 // 
				 this->label_question->AutoSize = true;
				 this->label_question->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.5F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->label_question->Location = System::Drawing::Point(13, 275);
				 this->label_question->Name = L"label_question";
				 this->label_question->Size = System::Drawing::Size(398, 16);
				 this->label_question->TabIndex = 9;
				 this->label_question->Text = L"Do you want to exit or to come back at the home window\?";
				 // 
				 // btn_home
				 // 
				 this->btn_home->BackColor = System::Drawing::Color::Lime;
				 this->btn_home->FlatAppearance->BorderColor = System::Drawing::Color::White;
				 this->btn_home->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->btn_home->Location = System::Drawing::Point(69, 322);
				 this->btn_home->Name = L"btn_home";
				 this->btn_home->Size = System::Drawing::Size(75, 23);
				 this->btn_home->TabIndex = 10;
				 this->btn_home->Text = L"Home";
				 this->btn_home->UseVisualStyleBackColor = false;
				 this->btn_home->Click += gcnew System::EventHandler(this, &BuyingReceipt::btn_home_Click);
				 // 
				 // btn_exit
				 // 
				 this->btn_exit->BackColor = System::Drawing::Color::Red;
				 this->btn_exit->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->btn_exit->Location = System::Drawing::Point(261, 322);
				 this->btn_exit->Name = L"btn_exit";
				 this->btn_exit->Size = System::Drawing::Size(75, 23);
				 this->btn_exit->TabIndex = 11;
				 this->btn_exit->Text = L"Exit";
				 this->btn_exit->UseVisualStyleBackColor = false;
				 this->btn_exit->Click += gcnew System::EventHandler(this, &BuyingReceipt::btn_exit_Click);
				 // 
				 // BuyingReceipt
				 // 
				 this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
				 this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
				 this->BackColor = System::Drawing::SystemColors::AppWorkspace;
				 this->ClientSize = System::Drawing::Size(427, 369);
				 this->Controls->Add(this->btn_exit);
				 this->Controls->Add(this->btn_home);
				 this->Controls->Add(this->label_question);
				 this->Controls->Add(this->output_date);
				 this->Controls->Add(this->label_date);
				 this->Controls->Add(this->output_price);
				 this->Controls->Add(this->output_number);
				 this->Controls->Add(this->output_stock);
				 this->Controls->Add(this->label_price);
				 this->Controls->Add(this->label_number);
				 this->Controls->Add(this->label_stock);
				 this->Controls->Add(this->label_title);
				 this->Name = L"BuyingReceipt";
				 this->Text = L"BuyingReceipt";
				 this->ResumeLayout(false);
				 this->PerformLayout();

			 }
#pragma endregion
	//When the user clicks on Exit
	private: System::Void btn_exit_Click(System::Object^  sender, System::EventArgs^  e) {
		Application::Exit();
	}

	//When the user clicks on Home
	private: System::Void btn_home_Click(System::Object^  sender, System::EventArgs^  e) {
		this->Hide();
		home->Show();
	}
	};
}
