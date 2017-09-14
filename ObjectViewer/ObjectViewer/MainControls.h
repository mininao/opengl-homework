#pragma once
#include "Renderer.h"
#include "Camera.h"
#include "Actor.h"
#include <GL/freeglut.h>
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
	MainControls(Renderer* renderer)
	{
		this->renderer = renderer;
		InitializeComponent();
		//
		//TODO: Add the constructor code here
		//
	}

private:
	Renderer* renderer;

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
private: System::Windows::Forms::RadioButton^  ccwRadioButton;

private: System::Windows::Forms::RadioButton^  cwRadioButton;
private: System::Windows::Forms::GroupBox^  windingOrderGroupBox;


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
		this->ccwRadioButton = (gcnew System::Windows::Forms::RadioButton());
		this->cwRadioButton = (gcnew System::Windows::Forms::RadioButton());
		this->windingOrderGroupBox = (gcnew System::Windows::Forms::GroupBox());
		this->topbar->SuspendLayout();
		this->windingOrderGroupBox->SuspendLayout();
		this->SuspendLayout();
		// 
		// title
		// 
		this->title->AutoSize = true;
		this->title->Font = (gcnew System::Drawing::Font(L"Proxima Nova Rg", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		this->title->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(48)), static_cast<System::Int32>(static_cast<System::Byte>(227)),
			static_cast<System::Int32>(static_cast<System::Byte>(202)));
		this->title->Location = System::Drawing::Point(124, 15);
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
		this->topbar->Size = System::Drawing::Size(453, 54);
		this->topbar->TabIndex = 1;
		// 
		// ccwRadioButton
		// 
		this->ccwRadioButton->AutoSize = true;
		this->ccwRadioButton->Location = System::Drawing::Point(13, 21);
		this->ccwRadioButton->Name = L"ccwRadioButton";
		this->ccwRadioButton->Size = System::Drawing::Size(122, 16);
		this->ccwRadioButton->TabIndex = 2;
		this->ccwRadioButton->TabStop = true;
		this->ccwRadioButton->Text = L"CounterClockwise";
		this->ccwRadioButton->UseVisualStyleBackColor = true;
		this->ccwRadioButton->CheckedChanged += gcnew System::EventHandler(this, &MainControls::ccwRadioButton_CheckedChanged);
		// 
		// cwRadioButton
		// 
		this->cwRadioButton->AutoSize = true;
		this->cwRadioButton->Location = System::Drawing::Point(13, 44);
		this->cwRadioButton->Name = L"cwRadioButton";
		this->cwRadioButton->Size = System::Drawing::Size(78, 16);
		this->cwRadioButton->TabIndex = 3;
		this->cwRadioButton->TabStop = true;
		this->cwRadioButton->Text = L"Clockwise";
		this->cwRadioButton->UseVisualStyleBackColor = true;
		// 
		// windingOrderGroupBox
		// 
		this->windingOrderGroupBox->Controls->Add(this->cwRadioButton);
		this->windingOrderGroupBox->Controls->Add(this->ccwRadioButton);
		this->windingOrderGroupBox->Font = (gcnew System::Drawing::Font(L"Proxima Nova Rg", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		this->windingOrderGroupBox->Location = System::Drawing::Point(12, 83);
		this->windingOrderGroupBox->Name = L"windingOrderGroupBox";
		this->windingOrderGroupBox->Size = System::Drawing::Size(159, 73);
		this->windingOrderGroupBox->TabIndex = 4;
		this->windingOrderGroupBox->TabStop = false;
		this->windingOrderGroupBox->Text = L"Polygons winding order";
		// 
		// MainControls
		// 
		this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
		this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
		this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(228)), static_cast<System::Int32>(static_cast<System::Byte>(249)),
			static_cast<System::Int32>(static_cast<System::Byte>(245)));
		this->ClientSize = System::Drawing::Size(453, 455);
		this->ControlBox = false;
		this->Controls->Add(this->windingOrderGroupBox);
		this->Controls->Add(this->topbar);
		this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
		this->Name = L"MainControls";
		this->ShowIcon = false;
		this->Text = L"MainControls";
		this->Load += gcnew System::EventHandler(this, &MainControls::MainControls_Load);
		this->topbar->ResumeLayout(false);
		this->topbar->PerformLayout();
		this->windingOrderGroupBox->ResumeLayout(false);
		this->windingOrderGroupBox->PerformLayout();
		this->ResumeLayout(false);

	}
#pragma endregion
private: System::Void MainControls_Load(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void ccwRadioButton_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
	if(ccwRadioButton->Checked)
	{
		renderer->windingOrder = GL_CCW;
	} else
	{
		renderer->windingOrder = GL_CW;
	}

}
};
