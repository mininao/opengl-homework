#pragma once
#include "Renderer.h"
#include "Camera.h"
#include "Actor.h"
#include "WavefrontParser.h"
#include <GL/freeglut.h>
#include <functional>
#include <msclr\marshal_cppstd.h>

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
private: System::Windows::Forms::Button^  cameraResetButton;
private: System::Windows::Forms::GroupBox^  cameraGroupBox;
private: System::Windows::Forms::Label^  nearClipLabel;

private: System::Windows::Forms::Label^  farClipLabel;
private: System::Windows::Forms::NumericUpDown^  farClipNumericUpDown;
private: System::Windows::Forms::NumericUpDown^  nearClipNumericUpDown;
private: System::Windows::Forms::ColorDialog^  actorColorDialog;
private: System::Windows::Forms::Button^  colorButton;
private: System::Windows::Forms::Panel^  colorButtonChip;
private: System::Windows::Forms::GroupBox^  renderingGroupBox;
private: System::Windows::Forms::RadioButton^  pointRadioButton;
private: System::Windows::Forms::RadioButton^  wireframeRadioButton;
private: System::Windows::Forms::RadioButton^  fillRadioButton;
private: System::Windows::Forms::Button^  loadModelButton;

private: System::Windows::Forms::OpenFileDialog^  modelOpenFileDialog;



private:




public:

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
private: System::ComponentModel::IContainer^  components;


protected:

private:
	/// <summary>
	/// Required designer variable.
	/// </summary>


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
		this->cameraResetButton = (gcnew System::Windows::Forms::Button());
		this->cameraGroupBox = (gcnew System::Windows::Forms::GroupBox());
		this->farClipNumericUpDown = (gcnew System::Windows::Forms::NumericUpDown());
		this->nearClipNumericUpDown = (gcnew System::Windows::Forms::NumericUpDown());
		this->farClipLabel = (gcnew System::Windows::Forms::Label());
		this->nearClipLabel = (gcnew System::Windows::Forms::Label());
		this->actorColorDialog = (gcnew System::Windows::Forms::ColorDialog());
		this->colorButton = (gcnew System::Windows::Forms::Button());
		this->colorButtonChip = (gcnew System::Windows::Forms::Panel());
		this->renderingGroupBox = (gcnew System::Windows::Forms::GroupBox());
		this->pointRadioButton = (gcnew System::Windows::Forms::RadioButton());
		this->wireframeRadioButton = (gcnew System::Windows::Forms::RadioButton());
		this->fillRadioButton = (gcnew System::Windows::Forms::RadioButton());
		this->loadModelButton = (gcnew System::Windows::Forms::Button());
		this->modelOpenFileDialog = (gcnew System::Windows::Forms::OpenFileDialog());
		this->topbar->SuspendLayout();
		this->windingOrderGroupBox->SuspendLayout();
		this->cameraGroupBox->SuspendLayout();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->farClipNumericUpDown))->BeginInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nearClipNumericUpDown))->BeginInit();
		this->renderingGroupBox->SuspendLayout();
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
		// cameraResetButton
		// 
		this->cameraResetButton->Location = System::Drawing::Point(45, 104);
		this->cameraResetButton->Name = L"cameraResetButton";
		this->cameraResetButton->Size = System::Drawing::Size(114, 24);
		this->cameraResetButton->TabIndex = 5;
		this->cameraResetButton->Text = L"Reset Camera";
		this->cameraResetButton->UseVisualStyleBackColor = true;
		this->cameraResetButton->Click += gcnew System::EventHandler(this, &MainControls::cameraResetButton_Click);
		// 
		// cameraGroupBox
		// 
		this->cameraGroupBox->Controls->Add(this->farClipNumericUpDown);
		this->cameraGroupBox->Controls->Add(this->nearClipNumericUpDown);
		this->cameraGroupBox->Controls->Add(this->farClipLabel);
		this->cameraGroupBox->Controls->Add(this->nearClipLabel);
		this->cameraGroupBox->Controls->Add(this->cameraResetButton);
		this->cameraGroupBox->Location = System::Drawing::Point(12, 182);
		this->cameraGroupBox->Name = L"cameraGroupBox";
		this->cameraGroupBox->Size = System::Drawing::Size(200, 134);
		this->cameraGroupBox->TabIndex = 6;
		this->cameraGroupBox->TabStop = false;
		this->cameraGroupBox->Text = L"Camera";
		// 
		// farClipNumericUpDown
		// 
		this->farClipNumericUpDown->DecimalPlaces = 2;
		this->farClipNumericUpDown->Location = System::Drawing::Point(10, 81);
		this->farClipNumericUpDown->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 9999, 0, 0, 0 });
		this->farClipNumericUpDown->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, System::Int32::MinValue });
		this->farClipNumericUpDown->Name = L"farClipNumericUpDown";
		this->farClipNumericUpDown->Size = System::Drawing::Size(120, 20);
		this->farClipNumericUpDown->TabIndex = 11;
		this->farClipNumericUpDown->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, System::Int32::MinValue });
		this->farClipNumericUpDown->ValueChanged += gcnew System::EventHandler(this, &MainControls::setRendererValues);
		// 
		// nearClipNumericUpDown
		// 
		this->nearClipNumericUpDown->DecimalPlaces = 2;
		this->nearClipNumericUpDown->Location = System::Drawing::Point(10, 42);
		this->nearClipNumericUpDown->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 9999, 0, 0, 0 });
		this->nearClipNumericUpDown->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, System::Int32::MinValue });
		this->nearClipNumericUpDown->Name = L"nearClipNumericUpDown";
		this->nearClipNumericUpDown->Size = System::Drawing::Size(120, 20);
		this->nearClipNumericUpDown->TabIndex = 10;
		this->nearClipNumericUpDown->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, System::Int32::MinValue });
		this->nearClipNumericUpDown->ValueChanged += gcnew System::EventHandler(this, &MainControls::setRendererValues);
		// 
		// farClipLabel
		// 
		this->farClipLabel->AutoSize = true;
		this->farClipLabel->Location = System::Drawing::Point(7, 65);
		this->farClipLabel->Name = L"farClipLabel";
		this->farClipLabel->Size = System::Drawing::Size(105, 13);
		this->farClipLabel->TabIndex = 9;
		this->farClipLabel->Text = L"Far Clipping distance";
		// 
		// nearClipLabel
		// 
		this->nearClipLabel->AutoSize = true;
		this->nearClipLabel->Location = System::Drawing::Point(7, 26);
		this->nearClipLabel->Name = L"nearClipLabel";
		this->nearClipLabel->Size = System::Drawing::Size(113, 13);
		this->nearClipLabel->TabIndex = 7;
		this->nearClipLabel->Text = L"Near Clipping distance";
		// 
		// actorColorDialog
		// 
		this->actorColorDialog->AnyColor = true;
		this->actorColorDialog->FullOpen = true;
		// 
		// colorButton
		// 
		this->colorButton->Location = System::Drawing::Point(34, 336);
		this->colorButton->Name = L"colorButton";
		this->colorButton->Padding = System::Windows::Forms::Padding(0, 0, 25, 0);
		this->colorButton->Size = System::Drawing::Size(155, 37);
		this->colorButton->TabIndex = 7;
		this->colorButton->Text = L"Change model color";
		this->colorButton->UseVisualStyleBackColor = true;
		this->colorButton->Click += gcnew System::EventHandler(this, &MainControls::colorButton_Click);
		// 
		// colorButtonChip
		// 
		this->colorButtonChip->BackColor = System::Drawing::Color::Red;
		this->colorButtonChip->Location = System::Drawing::Point(156, 345);
		this->colorButtonChip->Name = L"colorButtonChip";
		this->colorButtonChip->Size = System::Drawing::Size(21, 19);
		this->colorButtonChip->TabIndex = 8;
		this->colorButtonChip->Click += gcnew System::EventHandler(this, &MainControls::colorButton_Click);
		// 
		// renderingGroupBox
		// 
		this->renderingGroupBox->Controls->Add(this->pointRadioButton);
		this->renderingGroupBox->Controls->Add(this->wireframeRadioButton);
		this->renderingGroupBox->Controls->Add(this->fillRadioButton);
		this->renderingGroupBox->Location = System::Drawing::Point(218, 83);
		this->renderingGroupBox->Name = L"renderingGroupBox";
		this->renderingGroupBox->Size = System::Drawing::Size(200, 100);
		this->renderingGroupBox->TabIndex = 9;
		this->renderingGroupBox->TabStop = false;
		this->renderingGroupBox->Text = L"Rendering mode";
		// 
		// pointRadioButton
		// 
		this->pointRadioButton->AutoSize = true;
		this->pointRadioButton->Location = System::Drawing::Point(7, 65);
		this->pointRadioButton->Name = L"pointRadioButton";
		this->pointRadioButton->Size = System::Drawing::Size(79, 17);
		this->pointRadioButton->TabIndex = 2;
		this->pointRadioButton->TabStop = true;
		this->pointRadioButton->Text = L"Point Cloud";
		this->pointRadioButton->UseVisualStyleBackColor = true;
		this->pointRadioButton->CheckedChanged += gcnew System::EventHandler(this, &MainControls::renderingModeChanged);
		// 
		// wireframeRadioButton
		// 
		this->wireframeRadioButton->AutoSize = true;
		this->wireframeRadioButton->Location = System::Drawing::Point(7, 42);
		this->wireframeRadioButton->Name = L"wireframeRadioButton";
		this->wireframeRadioButton->Size = System::Drawing::Size(73, 17);
		this->wireframeRadioButton->TabIndex = 1;
		this->wireframeRadioButton->TabStop = true;
		this->wireframeRadioButton->Text = L"Wireframe";
		this->wireframeRadioButton->UseVisualStyleBackColor = true;
		this->wireframeRadioButton->CheckedChanged += gcnew System::EventHandler(this, &MainControls::renderingModeChanged);
		// 
		// fillRadioButton
		// 
		this->fillRadioButton->AutoSize = true;
		this->fillRadioButton->Location = System::Drawing::Point(7, 21);
		this->fillRadioButton->Name = L"fillRadioButton";
		this->fillRadioButton->Size = System::Drawing::Size(37, 17);
		this->fillRadioButton->TabIndex = 0;
		this->fillRadioButton->TabStop = true;
		this->fillRadioButton->Text = L"Fill";
		this->fillRadioButton->UseVisualStyleBackColor = true;
		this->fillRadioButton->CheckedChanged += gcnew System::EventHandler(this, &MainControls::renderingModeChanged);
		// 
		// loadModelButton
		// 
		this->loadModelButton->Location = System::Drawing::Point(240, 336);
		this->loadModelButton->Name = L"loadModelButton";
		this->loadModelButton->Size = System::Drawing::Size(155, 37);
		this->loadModelButton->TabIndex = 10;
		this->loadModelButton->Text = L"Load new model";
		this->loadModelButton->UseVisualStyleBackColor = true;
		this->loadModelButton->Click += gcnew System::EventHandler(this, &MainControls::loadModelButton_Click);
		// 
		// modelOpenFileDialog
		// 
		this->modelOpenFileDialog->FileName = L"simple.obj";
		this->modelOpenFileDialog->InitialDirectory = L"models";
		// 
		// MainControls
		// 
		this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
		this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
		this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(228)), static_cast<System::Int32>(static_cast<System::Byte>(249)),
			static_cast<System::Int32>(static_cast<System::Byte>(245)));
		this->ClientSize = System::Drawing::Size(453, 455);
		this->ControlBox = false;
		this->Controls->Add(this->loadModelButton);
		this->Controls->Add(this->renderingGroupBox);
		this->Controls->Add(this->colorButtonChip);
		this->Controls->Add(this->colorButton);
		this->Controls->Add(this->cameraGroupBox);
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
		this->cameraGroupBox->ResumeLayout(false);
		this->cameraGroupBox->PerformLayout();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->farClipNumericUpDown))->EndInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nearClipNumericUpDown))->EndInit();
		this->renderingGroupBox->ResumeLayout(false);
		this->renderingGroupBox->PerformLayout();
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
private: System::Void renderingModeChanged(System::Object^  sender, System::EventArgs^  e) {
	if(fillRadioButton->Checked) renderer->actors[0].renderingMode = GL_FILL;
	else if(pointRadioButton->Checked) renderer->actors[0].renderingMode = GL_POINT;
	else if(wireframeRadioButton->Checked) renderer->actors[0].renderingMode = GL_LINE;
}

private: System::Void cameraResetButton_Click(System::Object^  sender, System::EventArgs^  e) {
	renderer->camera.reset();
}

	public:
	System::Void getRendererValues()
	{
		// Clipping distances
		nearClipNumericUpDown->Value = System::Convert::ToDecimal(renderer->camera.nearDistance);
		farClipNumericUpDown->Value = System::Convert::ToDecimal(renderer->camera.farDistance);

		// Rendering mode
		fillRadioButton->Checked = renderer->actors[0].renderingMode == GL_FILL;
		pointRadioButton->Checked = renderer->actors[0].renderingMode == GL_POINT;
		wireframeRadioButton->Checked = renderer->actors[0].renderingMode == GL_LINE;

		// Actor Color
		GLubyte* color = renderer->actors[0].color;
		System::Drawing::Color winColor = System::Drawing::Color::FromArgb(color[0], color[1], color[2]);
		colorButtonChip->BackColor = winColor;
		actorColorDialog->Color = winColor;
	}
private: System::Void setRendererValues(System::Object^  sender, System::EventArgs^  e) {
	if(nearClipNumericUpDown->Value >= 0)
		renderer->camera.nearDistance = System::Convert::ToSingle(nearClipNumericUpDown->Value);
	if (farClipNumericUpDown->Value >= 0)
		renderer->camera.farDistance = System::Convert::ToSingle(farClipNumericUpDown->Value);

}
private: System::Void colorButton_Click(System::Object^  sender, System::EventArgs^  e) {
	// Show dialog & check validation
	System::Windows::Forms::DialogResult result = actorColorDialog->ShowDialog();
	if (result == System::Windows::Forms::DialogResult::OK)
	{
		System::Drawing::Color newColor = actorColorDialog->Color;
		renderer->actors[0].color[0] = newColor.R;
		renderer->actors[0].color[1] = newColor.G;
		renderer->actors[0].color[2] = newColor.B;
	}
}
private: System::Void loadModelButton_Click(System::Object^  sender, System::EventArgs^  e) {
	if (modelOpenFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		Actor mainActor = WavefrontParser::wavefrontToActor(msclr::interop::marshal_as<string>(modelOpenFileDialog->FileName));
		renderer->actors[0] = mainActor;
	}
}
};
