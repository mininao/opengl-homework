#pragma once
#include "Renderer.h"
#include "Camera.h"
#include "Actor.h"
#include "WavefrontParser.h"
#include <GL/glew.h>
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
private: System::Windows::Forms::CheckBox^  boundingBoxCheckBox;
private: System::Windows::Forms::GroupBox^  lightGroupBox;
private: System::Windows::Forms::CheckBox^  lightEnabledCheckBox;
private: System::Windows::Forms::CheckBox^  drawTestSpheresCheckBox;
private: System::Windows::Forms::CheckBox^  lightDrawCheckBox;
private: System::Windows::Forms::GroupBox^  shadingModeGroupBox;
private: System::Windows::Forms::RadioButton^  flatShadingRadioButton;
private: System::Windows::Forms::RadioButton^  gouraudShadingRadioButton;
private: System::Windows::Forms::Panel^  lightAmbientColorPanel;

private: System::Windows::Forms::Button^  lightAmbientColorButton;
private: System::Windows::Forms::Panel^  lightSpecularColorPanel;
private: System::Windows::Forms::Button^  lightSpecularColorButton;
private: System::Windows::Forms::Panel^  lightDiffuseColorPanel;

private: System::Windows::Forms::Button^  lightDiffuseColorButton;
private: System::Windows::Forms::ColorDialog^  lightAmbientColorDialog;
private: System::Windows::Forms::ColorDialog^  lightDiffuseColorDialog;
private: System::Windows::Forms::ColorDialog^  lightSpecularColorDialog;
private: System::Windows::Forms::Panel^  globalAmbientColorPanel;

private: System::Windows::Forms::Button^  globalAmbientColorButton;
private: System::Windows::Forms::ColorDialog^  globalAmbientColorDialog;
private: System::Windows::Forms::CheckBox^  lightRotateCheckBox;






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
		this->boundingBoxCheckBox = (gcnew System::Windows::Forms::CheckBox());
		this->lightGroupBox = (gcnew System::Windows::Forms::GroupBox());
		this->lightSpecularColorPanel = (gcnew System::Windows::Forms::Panel());
		this->lightSpecularColorButton = (gcnew System::Windows::Forms::Button());
		this->lightDiffuseColorPanel = (gcnew System::Windows::Forms::Panel());
		this->lightDiffuseColorButton = (gcnew System::Windows::Forms::Button());
		this->lightAmbientColorPanel = (gcnew System::Windows::Forms::Panel());
		this->drawTestSpheresCheckBox = (gcnew System::Windows::Forms::CheckBox());
		this->lightAmbientColorButton = (gcnew System::Windows::Forms::Button());
		this->lightDrawCheckBox = (gcnew System::Windows::Forms::CheckBox());
		this->lightEnabledCheckBox = (gcnew System::Windows::Forms::CheckBox());
		this->shadingModeGroupBox = (gcnew System::Windows::Forms::GroupBox());
		this->flatShadingRadioButton = (gcnew System::Windows::Forms::RadioButton());
		this->gouraudShadingRadioButton = (gcnew System::Windows::Forms::RadioButton());
		this->lightAmbientColorDialog = (gcnew System::Windows::Forms::ColorDialog());
		this->lightDiffuseColorDialog = (gcnew System::Windows::Forms::ColorDialog());
		this->lightSpecularColorDialog = (gcnew System::Windows::Forms::ColorDialog());
		this->globalAmbientColorPanel = (gcnew System::Windows::Forms::Panel());
		this->globalAmbientColorButton = (gcnew System::Windows::Forms::Button());
		this->globalAmbientColorDialog = (gcnew System::Windows::Forms::ColorDialog());
		this->lightRotateCheckBox = (gcnew System::Windows::Forms::CheckBox());
		this->topbar->SuspendLayout();
		this->windingOrderGroupBox->SuspendLayout();
		this->cameraGroupBox->SuspendLayout();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->farClipNumericUpDown))->BeginInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nearClipNumericUpDown))->BeginInit();
		this->renderingGroupBox->SuspendLayout();
		this->lightGroupBox->SuspendLayout();
		this->shadingModeGroupBox->SuspendLayout();
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
		this->topbar->Size = System::Drawing::Size(440, 54);
		this->topbar->TabIndex = 1;
		// 
		// ccwRadioButton
		// 
		this->ccwRadioButton->AutoSize = true;
		this->ccwRadioButton->Location = System::Drawing::Point(13, 21);
		this->ccwRadioButton->Name = L"ccwRadioButton";
		this->ccwRadioButton->Size = System::Drawing::Size(110, 17);
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
		this->cwRadioButton->Size = System::Drawing::Size(73, 17);
		this->cwRadioButton->TabIndex = 3;
		this->cwRadioButton->TabStop = true;
		this->cwRadioButton->Text = L"Clockwise";
		this->cwRadioButton->UseVisualStyleBackColor = true;
		// 
		// windingOrderGroupBox
		// 
		this->windingOrderGroupBox->Controls->Add(this->cwRadioButton);
		this->windingOrderGroupBox->Controls->Add(this->ccwRadioButton);
		this->windingOrderGroupBox->Location = System::Drawing::Point(12, 83);
		this->windingOrderGroupBox->Name = L"windingOrderGroupBox";
		this->windingOrderGroupBox->Size = System::Drawing::Size(200, 73);
		this->windingOrderGroupBox->TabIndex = 4;
		this->windingOrderGroupBox->TabStop = false;
		this->windingOrderGroupBox->Text = L"Polygons winding order";
		// 
		// cameraResetButton
		// 
		this->cameraResetButton->Location = System::Drawing::Point(45, 97);
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
		this->cameraGroupBox->Location = System::Drawing::Point(225, 83);
		this->cameraGroupBox->Name = L"cameraGroupBox";
		this->cameraGroupBox->Size = System::Drawing::Size(200, 134);
		this->cameraGroupBox->TabIndex = 6;
		this->cameraGroupBox->TabStop = false;
		this->cameraGroupBox->Text = L"Camera";
		// 
		// farClipNumericUpDown
		// 
		this->farClipNumericUpDown->DecimalPlaces = 2;
		this->farClipNumericUpDown->Location = System::Drawing::Point(11, 71);
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
		this->nearClipNumericUpDown->Location = System::Drawing::Point(11, 32);
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
		this->farClipLabel->Location = System::Drawing::Point(8, 55);
		this->farClipLabel->Name = L"farClipLabel";
		this->farClipLabel->Size = System::Drawing::Size(105, 13);
		this->farClipLabel->TabIndex = 9;
		this->farClipLabel->Text = L"Far Clipping distance";
		// 
		// nearClipLabel
		// 
		this->nearClipLabel->AutoSize = true;
		this->nearClipLabel->Location = System::Drawing::Point(8, 16);
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
		this->colorButton->Location = System::Drawing::Point(19, 409);
		this->colorButton->Name = L"colorButton";
		this->colorButton->Padding = System::Windows::Forms::Padding(0, 0, 25, 0);
		this->colorButton->Size = System::Drawing::Size(177, 37);
		this->colorButton->TabIndex = 7;
		this->colorButton->Text = L"Change model color";
		this->colorButton->UseVisualStyleBackColor = true;
		this->colorButton->Click += gcnew System::EventHandler(this, &MainControls::colorButton_Click);
		// 
		// colorButtonChip
		// 
		this->colorButtonChip->BackColor = System::Drawing::Color::Red;
		this->colorButtonChip->Location = System::Drawing::Point(168, 418);
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
		this->renderingGroupBox->Location = System::Drawing::Point(12, 242);
		this->renderingGroupBox->Name = L"renderingGroupBox";
		this->renderingGroupBox->Size = System::Drawing::Size(200, 92);
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
		this->loadModelButton->Location = System::Drawing::Point(236, 409);
		this->loadModelButton->Name = L"loadModelButton";
		this->loadModelButton->Size = System::Drawing::Size(177, 37);
		this->loadModelButton->TabIndex = 10;
		this->loadModelButton->Text = L"Load new model";
		this->loadModelButton->UseVisualStyleBackColor = true;
		this->loadModelButton->Click += gcnew System::EventHandler(this, &MainControls::loadModelButton_Click);
		// 
		// modelOpenFileDialog
		// 
		this->modelOpenFileDialog->FileName = L"simple.obj";
		this->modelOpenFileDialog->InitialDirectory = L"E:\\E5\\CS412-CG\\opengl-homework\\ObjectViewer\\ObjectViewer\\models";
		// 
		// boundingBoxCheckBox
		// 
		this->boundingBoxCheckBox->AutoSize = true;
		this->boundingBoxCheckBox->Location = System::Drawing::Point(19, 340);
		this->boundingBoxCheckBox->Name = L"boundingBoxCheckBox";
		this->boundingBoxCheckBox->Size = System::Drawing::Size(122, 17);
		this->boundingBoxCheckBox->TabIndex = 11;
		this->boundingBoxCheckBox->Text = L"Show Bounding Box";
		this->boundingBoxCheckBox->UseVisualStyleBackColor = true;
		this->boundingBoxCheckBox->CheckedChanged += gcnew System::EventHandler(this, &MainControls::boundingBoxCheckBox_CheckedChanged);
		// 
		// lightGroupBox
		// 
		this->lightGroupBox->Controls->Add(this->lightRotateCheckBox);
		this->lightGroupBox->Controls->Add(this->lightSpecularColorPanel);
		this->lightGroupBox->Controls->Add(this->lightSpecularColorButton);
		this->lightGroupBox->Controls->Add(this->lightDiffuseColorPanel);
		this->lightGroupBox->Controls->Add(this->lightDiffuseColorButton);
		this->lightGroupBox->Controls->Add(this->lightAmbientColorPanel);
		this->lightGroupBox->Controls->Add(this->drawTestSpheresCheckBox);
		this->lightGroupBox->Controls->Add(this->lightAmbientColorButton);
		this->lightGroupBox->Controls->Add(this->lightDrawCheckBox);
		this->lightGroupBox->Controls->Add(this->lightEnabledCheckBox);
		this->lightGroupBox->Location = System::Drawing::Point(225, 223);
		this->lightGroupBox->Name = L"lightGroupBox";
		this->lightGroupBox->Size = System::Drawing::Size(200, 180);
		this->lightGroupBox->TabIndex = 12;
		this->lightGroupBox->TabStop = false;
		this->lightGroupBox->Text = L"Light";
		// 
		// lightSpecularColorPanel
		// 
		this->lightSpecularColorPanel->BackColor = System::Drawing::Color::Red;
		this->lightSpecularColorPanel->Location = System::Drawing::Point(158, 153);
		this->lightSpecularColorPanel->Name = L"lightSpecularColorPanel";
		this->lightSpecularColorPanel->Size = System::Drawing::Size(16, 16);
		this->lightSpecularColorPanel->TabIndex = 19;
		this->lightSpecularColorPanel->Click += gcnew System::EventHandler(this, &MainControls::lightSpecularColorButton_Click);
		// 
		// lightSpecularColorButton
		// 
		this->lightSpecularColorButton->Location = System::Drawing::Point(11, 149);
		this->lightSpecularColorButton->Name = L"lightSpecularColorButton";
		this->lightSpecularColorButton->Padding = System::Windows::Forms::Padding(0, 0, 25, 0);
		this->lightSpecularColorButton->Size = System::Drawing::Size(177, 24);
		this->lightSpecularColorButton->TabIndex = 18;
		this->lightSpecularColorButton->Text = L"Change specular color";
		this->lightSpecularColorButton->UseVisualStyleBackColor = true;
		this->lightSpecularColorButton->Click += gcnew System::EventHandler(this, &MainControls::lightSpecularColorButton_Click);
		// 
		// lightDiffuseColorPanel
		// 
		this->lightDiffuseColorPanel->BackColor = System::Drawing::Color::Red;
		this->lightDiffuseColorPanel->Location = System::Drawing::Point(158, 123);
		this->lightDiffuseColorPanel->Name = L"lightDiffuseColorPanel";
		this->lightDiffuseColorPanel->Size = System::Drawing::Size(16, 16);
		this->lightDiffuseColorPanel->TabIndex = 17;
		this->lightDiffuseColorPanel->Click += gcnew System::EventHandler(this, &MainControls::lightDiffuseColorButton_Click);
		// 
		// lightDiffuseColorButton
		// 
		this->lightDiffuseColorButton->Location = System::Drawing::Point(11, 119);
		this->lightDiffuseColorButton->Name = L"lightDiffuseColorButton";
		this->lightDiffuseColorButton->Padding = System::Windows::Forms::Padding(0, 0, 25, 0);
		this->lightDiffuseColorButton->Size = System::Drawing::Size(177, 24);
		this->lightDiffuseColorButton->TabIndex = 16;
		this->lightDiffuseColorButton->Text = L"Change diffuse color";
		this->lightDiffuseColorButton->UseVisualStyleBackColor = true;
		this->lightDiffuseColorButton->Click += gcnew System::EventHandler(this, &MainControls::lightDiffuseColorButton_Click);
		// 
		// lightAmbientColorPanel
		// 
		this->lightAmbientColorPanel->BackColor = System::Drawing::Color::Red;
		this->lightAmbientColorPanel->Location = System::Drawing::Point(158, 93);
		this->lightAmbientColorPanel->Name = L"lightAmbientColorPanel";
		this->lightAmbientColorPanel->Size = System::Drawing::Size(16, 16);
		this->lightAmbientColorPanel->TabIndex = 15;
		this->lightAmbientColorPanel->Click += gcnew System::EventHandler(this, &MainControls::lightAmbientColorButton_Click);
		// 
		// drawTestSpheresCheckBox
		// 
		this->drawTestSpheresCheckBox->AutoSize = true;
		this->drawTestSpheresCheckBox->Location = System::Drawing::Point(7, 66);
		this->drawTestSpheresCheckBox->Name = L"drawTestSpheresCheckBox";
		this->drawTestSpheresCheckBox->Size = System::Drawing::Size(143, 17);
		this->drawTestSpheresCheckBox->TabIndex = 2;
		this->drawTestSpheresCheckBox->Text = L"Draw Light Test Spheres";
		this->drawTestSpheresCheckBox->UseVisualStyleBackColor = true;
		this->drawTestSpheresCheckBox->CheckedChanged += gcnew System::EventHandler(this, &MainControls::drawTestSpheresCheckBox_CheckedChanged);
		// 
		// lightAmbientColorButton
		// 
		this->lightAmbientColorButton->Location = System::Drawing::Point(11, 89);
		this->lightAmbientColorButton->Name = L"lightAmbientColorButton";
		this->lightAmbientColorButton->Padding = System::Windows::Forms::Padding(0, 0, 25, 0);
		this->lightAmbientColorButton->Size = System::Drawing::Size(177, 24);
		this->lightAmbientColorButton->TabIndex = 14;
		this->lightAmbientColorButton->Text = L"Change ambient color";
		this->lightAmbientColorButton->UseVisualStyleBackColor = true;
		this->lightAmbientColorButton->Click += gcnew System::EventHandler(this, &MainControls::lightAmbientColorButton_Click);
		// 
		// lightDrawCheckBox
		// 
		this->lightDrawCheckBox->AutoSize = true;
		this->lightDrawCheckBox->Location = System::Drawing::Point(7, 43);
		this->lightDrawCheckBox->Name = L"lightDrawCheckBox";
		this->lightDrawCheckBox->Size = System::Drawing::Size(114, 17);
		this->lightDrawCheckBox->TabIndex = 1;
		this->lightDrawCheckBox->Text = L"Draw Light Source";
		this->lightDrawCheckBox->UseVisualStyleBackColor = true;
		this->lightDrawCheckBox->CheckedChanged += gcnew System::EventHandler(this, &MainControls::lightDrawCheckBox_CheckedChanged);
		// 
		// lightEnabledCheckBox
		// 
		this->lightEnabledCheckBox->AutoSize = true;
		this->lightEnabledCheckBox->Location = System::Drawing::Point(7, 20);
		this->lightEnabledCheckBox->Name = L"lightEnabledCheckBox";
		this->lightEnabledCheckBox->Size = System::Drawing::Size(65, 17);
		this->lightEnabledCheckBox->TabIndex = 0;
		this->lightEnabledCheckBox->Text = L"Enabled";
		this->lightEnabledCheckBox->UseVisualStyleBackColor = true;
		this->lightEnabledCheckBox->CheckedChanged += gcnew System::EventHandler(this, &MainControls::lightEnabledCheckBox_CheckedChanged);
		// 
		// shadingModeGroupBox
		// 
		this->shadingModeGroupBox->Controls->Add(this->flatShadingRadioButton);
		this->shadingModeGroupBox->Controls->Add(this->gouraudShadingRadioButton);
		this->shadingModeGroupBox->Location = System::Drawing::Point(12, 162);
		this->shadingModeGroupBox->Name = L"shadingModeGroupBox";
		this->shadingModeGroupBox->Size = System::Drawing::Size(200, 74);
		this->shadingModeGroupBox->TabIndex = 13;
		this->shadingModeGroupBox->TabStop = false;
		this->shadingModeGroupBox->Text = L"Shading Model";
		// 
		// flatShadingRadioButton
		// 
		this->flatShadingRadioButton->AutoSize = true;
		this->flatShadingRadioButton->Location = System::Drawing::Point(13, 47);
		this->flatShadingRadioButton->Name = L"flatShadingRadioButton";
		this->flatShadingRadioButton->Size = System::Drawing::Size(82, 17);
		this->flatShadingRadioButton->TabIndex = 1;
		this->flatShadingRadioButton->Text = L"Flat shading";
		this->flatShadingRadioButton->UseVisualStyleBackColor = true;
		// 
		// gouraudShadingRadioButton
		// 
		this->gouraudShadingRadioButton->AutoSize = true;
		this->gouraudShadingRadioButton->Location = System::Drawing::Point(13, 26);
		this->gouraudShadingRadioButton->Name = L"gouraudShadingRadioButton";
		this->gouraudShadingRadioButton->Size = System::Drawing::Size(106, 17);
		this->gouraudShadingRadioButton->TabIndex = 0;
		this->gouraudShadingRadioButton->Text = L"Gouraud shading";
		this->gouraudShadingRadioButton->UseVisualStyleBackColor = true;
		this->gouraudShadingRadioButton->CheckedChanged += gcnew System::EventHandler(this, &MainControls::gouraudShadingRadioButton_CheckedChanged);
		// 
		// lightAmbientColorDialog
		// 
		this->lightAmbientColorDialog->AnyColor = true;
		this->lightAmbientColorDialog->FullOpen = true;
		// 
		// lightDiffuseColorDialog
		// 
		this->lightDiffuseColorDialog->AnyColor = true;
		this->lightDiffuseColorDialog->FullOpen = true;
		// 
		// lightSpecularColorDialog
		// 
		this->lightSpecularColorDialog->AnyColor = true;
		this->lightSpecularColorDialog->FullOpen = true;
		// 
		// globalAmbientColorPanel
		// 
		this->globalAmbientColorPanel->BackColor = System::Drawing::Color::Red;
		this->globalAmbientColorPanel->Location = System::Drawing::Point(168, 375);
		this->globalAmbientColorPanel->Name = L"globalAmbientColorPanel";
		this->globalAmbientColorPanel->Size = System::Drawing::Size(21, 19);
		this->globalAmbientColorPanel->TabIndex = 15;
		this->globalAmbientColorPanel->Click += gcnew System::EventHandler(this, &MainControls::globalAmbientColorButton_Click);
		// 
		// globalAmbientColorButton
		// 
		this->globalAmbientColorButton->Location = System::Drawing::Point(19, 366);
		this->globalAmbientColorButton->Name = L"globalAmbientColorButton";
		this->globalAmbientColorButton->Padding = System::Windows::Forms::Padding(0, 0, 25, 0);
		this->globalAmbientColorButton->Size = System::Drawing::Size(177, 37);
		this->globalAmbientColorButton->TabIndex = 14;
		this->globalAmbientColorButton->Text = L"Change global ambient color";
		this->globalAmbientColorButton->UseVisualStyleBackColor = true;
		this->globalAmbientColorButton->Click += gcnew System::EventHandler(this, &MainControls::globalAmbientColorButton_Click);
		// 
		// globalAmbientColorDialog
		// 
		this->globalAmbientColorDialog->AnyColor = true;
		this->globalAmbientColorDialog->FullOpen = true;
		// 
		// lightRotateCheckBox
		// 
		this->lightRotateCheckBox->AutoSize = true;
		this->lightRotateCheckBox->Location = System::Drawing::Point(85, 20);
		this->lightRotateCheckBox->Name = L"lightRotateCheckBox";
		this->lightRotateCheckBox->Size = System::Drawing::Size(58, 17);
		this->lightRotateCheckBox->TabIndex = 20;
		this->lightRotateCheckBox->Text = L"Rotate";
		this->lightRotateCheckBox->UseVisualStyleBackColor = true;
		this->lightRotateCheckBox->CheckedChanged += gcnew System::EventHandler(this, &MainControls::lightRotateCheckBox_CheckedChanged);
		// 
		// MainControls
		// 
		this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
		this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
		this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(228)), static_cast<System::Int32>(static_cast<System::Byte>(249)),
			static_cast<System::Int32>(static_cast<System::Byte>(245)));
		this->ClientSize = System::Drawing::Size(439, 467);
		this->ControlBox = false;
		this->Controls->Add(this->globalAmbientColorPanel);
		this->Controls->Add(this->globalAmbientColorButton);
		this->Controls->Add(this->shadingModeGroupBox);
		this->Controls->Add(this->lightGroupBox);
		this->Controls->Add(this->boundingBoxCheckBox);
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
		this->lightGroupBox->ResumeLayout(false);
		this->lightGroupBox->PerformLayout();
		this->shadingModeGroupBox->ResumeLayout(false);
		this->shadingModeGroupBox->PerformLayout();
		this->ResumeLayout(false);
		this->PerformLayout();

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
	renderer->camera.fitActor(renderer->actors[0]);
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
	glm::vec4 color = renderer->actors[0].color * 255.0f;
	System::Drawing::Color winColor = System::Drawing::Color::FromArgb(color.a, color.r, color.g, color.b);
	colorButtonChip->BackColor = winColor;
	actorColorDialog->Color = winColor;

	// Show Bounding Box
	boundingBoxCheckBox->Checked = renderer->actors[0].showBoundingBox;

	// Light config
	lightEnabledCheckBox->Checked = renderer->light.enabled;
	lightRotateCheckBox->Checked = renderer->light.animateRotation;
	lightDrawCheckBox->Checked = renderer->light.enableDraw;
	drawTestSpheresCheckBox->Checked = renderer->light.enableTestSpheres;

	// Shading model
	gouraudShadingRadioButton->Checked = renderer->shadingModel == GL_SMOOTH;
	flatShadingRadioButton->Checked = renderer->shadingModel == GL_FLAT;

	// Light Colors
	glm::vec4 ambientColor = renderer->light.ambientColor * 255.0f;
	glm::vec4 diffuseColor = renderer->light.diffuseColor * 255.0f;
	glm::vec4 specularColor = renderer->light.specularColor * 255.0f;
	System::Drawing::Color ambientWinColor = System::Drawing::Color::FromArgb(ambientColor.a, ambientColor.r, ambientColor.g, ambientColor.b);
	System::Drawing::Color diffuseWinColor = System::Drawing::Color::FromArgb(diffuseColor.a, diffuseColor.r, diffuseColor.g, diffuseColor.b);
	System::Drawing::Color specularWinColor = System::Drawing::Color::FromArgb(specularColor.a, specularColor.r, specularColor.g, specularColor.b);
	lightAmbientColorPanel->BackColor = ambientWinColor;
	lightDiffuseColorPanel->BackColor = diffuseWinColor;
	lightSpecularColorPanel->BackColor = specularWinColor;
	lightAmbientColorDialog->Color = ambientWinColor;
	lightDiffuseColorDialog->Color = diffuseWinColor;
	lightSpecularColorDialog->Color = specularWinColor;

	// Global ambient color
	glm::vec4 globalAmbientColor = renderer->ambientColor * 255.0f;
	System::Drawing::Color globalAmbientWinColor = System::Drawing::Color::FromArgb(globalAmbientColor.a, globalAmbientColor.r, globalAmbientColor.g, globalAmbientColor.b);
	globalAmbientColorPanel->BackColor = globalAmbientWinColor;
	globalAmbientColorDialog->Color = globalAmbientWinColor;
}

private: System::Void setRendererValues(System::Object^  sender, System::EventArgs^  e) {
	if(nearClipNumericUpDown->Value >= 0)
		renderer->camera.nearDistance = System::Convert::ToSingle(nearClipNumericUpDown->Value);
	if (farClipNumericUpDown->Value >= 0)
		renderer->camera.farDistance = System::Convert::ToSingle(farClipNumericUpDown->Value);

}
private: System::Void colorButton_Click(System::Object^  sender, System::EventArgs^  e) {
	// Show dialog & check validation
	if (actorColorDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		System::Drawing::Color newColor = actorColorDialog->Color;
		renderer->actors[0].color = glm::vec4(newColor.R / 255.0f, newColor.G / 255.0f, newColor.B / 255.0f, newColor.A / 255.0f);
	}
}
private: System::Void loadModelButton_Click(System::Object^  sender, System::EventArgs^  e) {
	if (modelOpenFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		Actor mainActor = WavefrontParser::wavefrontToActor(msclr::interop::marshal_as<string>(modelOpenFileDialog->FileName));
		renderer->actors[0] = mainActor;
		renderer->camera.fitActor(mainActor);
	}
}
private: System::Void boundingBoxCheckBox_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
	renderer->actors[0].showBoundingBox = boundingBoxCheckBox->Checked;
}
private: System::Void lightEnabledCheckBox_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
	renderer->light.enabled = lightEnabledCheckBox->Checked;
}
private: System::Void lightDrawCheckBox_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
	renderer->light.enableDraw = lightDrawCheckBox->Checked;
}
private: System::Void drawTestSpheresCheckBox_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
	renderer->light.enableTestSpheres = drawTestSpheresCheckBox->Checked;
}
private: System::Void gouraudShadingRadioButton_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
	if (gouraudShadingRadioButton->Checked)
	{
		renderer->shadingModel = GL_SMOOTH;
	}
	else
	{
		renderer->shadingModel = GL_FLAT;
	}
}
private: System::Void lightAmbientColorButton_Click(System::Object^  sender, System::EventArgs^  e) {
	// Show dialog & check validation
	if (lightAmbientColorDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		System::Drawing::Color newColor = lightAmbientColorDialog->Color;
		renderer->light.ambientColor = glm::vec4(newColor.R/255.0f, newColor.G / 255.0f, newColor.B / 255.0f, newColor.A / 255.0f);
	}
}
private: System::Void lightDiffuseColorButton_Click(System::Object^  sender, System::EventArgs^  e) {
	// Show dialog & check validation
	if (lightDiffuseColorDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		System::Drawing::Color newColor = lightDiffuseColorDialog->Color;
		renderer->light.diffuseColor = glm::vec4(newColor.R / 255.0f, newColor.G / 255.0f, newColor.B / 255.0f, newColor.A / 255.0f);
	}
}
private: System::Void lightSpecularColorButton_Click(System::Object^  sender, System::EventArgs^  e) {
	// Show dialog & check validation
	if (lightSpecularColorDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		System::Drawing::Color newColor = lightSpecularColorDialog->Color;
		renderer->light.specularColor = glm::vec4(newColor.R / 255.0f, newColor.G / 255.0f, newColor.B / 255.0f, newColor.A / 255.0f);
	}
}
private: System::Void globalAmbientColorButton_Click(System::Object^  sender, System::EventArgs^  e) {
	// Show dialog & check validation
	if (globalAmbientColorDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		System::Drawing::Color newColor = globalAmbientColorDialog->Color;
		renderer->ambientColor = glm::vec4(newColor.R / 255.0f, newColor.G / 255.0f, newColor.B / 255.0f, newColor.A / 255.0f);
	}
}
private: System::Void lightRotateCheckBox_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
	renderer->light.animateRotation = lightRotateCheckBox->Checked;
}
};
