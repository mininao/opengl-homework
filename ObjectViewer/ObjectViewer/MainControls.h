#pragma once
using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

/// <summary>
/// Summary for MainControls
/// </summary>
public ref class MainControls : public System::Windows::Forms::Form
{
public:
	MainControls(void)
	{
		InitializeComponent();
		//
		//TODO: Add the constructor code here
		//
	}

protected:
	/// <summary>
	/// Clean up any resources being used.
	/// </summary>
	~MainControls()
	{
		if (components)
		{
			delete components;
		}
	}
private: System::Windows::Forms::Label^  title;
private: System::Windows::Forms::Panel^  topbar;

protected:

private:
	/// <summary>
	/// Required designer variable.
	/// </summary>
	System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
	/// <summary>
	/// Required method for Designer support - do not modify
	/// the contents of this method with the code editor.
	/// </summary>
	void InitializeComponent(void)
	{
		this->title = (gcnew System::Windows::Forms::Label());
		this->topbar = (gcnew System::Windows::Forms::Panel());
		this->topbar->SuspendLayout();
		this->SuspendLayout();
		// 
		// title
		// 
		this->title->AutoSize = true;
		this->title->Font = (gcnew System::Drawing::Font(L"Proxima Nova Rg", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		this->title->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(48)), static_cast<System::Int32>(static_cast<System::Byte>(227)),
			static_cast<System::Int32>(static_cast<System::Byte>(202)));
		this->title->Location = System::Drawing::Point(56, 15);
		this->title->Name = L"title";
		this->title->Size = System::Drawing::Size(203, 24);
		this->title->TabIndex = 0;
		this->title->Text = L"Wavefront Viewer";
		// 
		// topbar
		// 
		this->topbar->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(81)),
			static_cast<System::Int32>(static_cast<System::Byte>(78)));
		this->topbar->Controls->Add(this->title);
		this->topbar->Location = System::Drawing::Point(0, 0);
		this->topbar->Name = L"topbar";
		this->topbar->Size = System::Drawing::Size(321, 54);
		this->topbar->TabIndex = 1;
		// 
		// MainControls
		// 
		this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
		this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
		this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(228)), static_cast<System::Int32>(static_cast<System::Byte>(249)),
			static_cast<System::Int32>(static_cast<System::Byte>(245)));
		this->ClientSize = System::Drawing::Size(321, 335);
		this->ControlBox = false;
		this->Controls->Add(this->topbar);
		this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
		this->Name = L"MainControls";
		this->ShowIcon = false;
		this->Text = L"MainControls";
		this->Load += gcnew System::EventHandler(this, &MainControls::MainControls_Load);
		this->topbar->ResumeLayout(false);
		this->topbar->PerformLayout();
		this->ResumeLayout(false);

	}
#pragma endregion
private: System::Void MainControls_Load(System::Object^  sender, System::EventArgs^  e) {
}
};
