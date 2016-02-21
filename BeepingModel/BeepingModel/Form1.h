#pragma once

#include "StdAfx.h"

namespace BeepingModel {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;
	using namespace System::Threading;
	/// <summary>
	/// Form1 の概要
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	private: Controller^ controller;
	private: Visualizer^ visualizer;
	private: Observer^ observer;
	private: DataManager^ data_manager;
	private: Thread^ Run_Algorithm;
	private: Thread^ Demo_Algorithm;
	private: Thread^ UpdateInfo;
	private: String^ fileName;      // 読み書きファイル名

	private: System::Windows::Forms::ToolStripMenuItem^  settingSToolStripMenuItem;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::Label^  label_ground;

	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::Label^  label_radius;
	private: System::Windows::Forms::Label^  label_topology;
	private: System::Windows::Forms::Label^  label_channels;
	private: System::Windows::Forms::Label^  label_F;
	private: System::Windows::Forms::Button^  btn_simulate;
	private: System::Windows::Forms::Label^  label_Delta;
	private: System::Windows::Forms::Label^  label_FieldSize;
	private: System::Windows::Forms::Label^  label_ComponentNum;
	private: System::Windows::Forms::Button^  btn_demo;
	private: System::Windows::Forms::Button^  btn_reset;
	private: System::Windows::Forms::Label^  label_Algorithm_type;



	private: Settings* settings;
	public:
		Form1(void)
		{
			InitializeComponent();
			InitSetting();
			this->controller = gcnew Controller( this->graph_panel->Size.Width, this->graph_panel->Size.Height );
			this->controller->SetGraphParameter(this->settings);
			this->visualizer = gcnew Visualizer( controller, graph_panel->CreateGraphics() );
			this->visualizer->SetParameter(this->settings);
			this->data_manager = gcnew DataManager(this->controller);
			this->observer = gcnew Observer( this->controller, this->visualizer , this->data_manager);
			this->Run_Algorithm = gcnew Thread( gcnew ThreadStart( this->observer, &Observer::Run) );
			this->Demo_Algorithm = gcnew Thread(gcnew ThreadStart(this->observer, &Observer::Demonstrate));
			this->UpdateInfo = gcnew Thread( gcnew ThreadStart(this, &Form1::UpdateDistributedSystem) );
			this->UpdateInfo->Start();
		}

	protected:
		/// <summary>
		/// 使用中のリソースをすべてクリーンアップします。
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
				delete data_manager;
			}
		}
	private: System::Windows::Forms::Button^  btn_auto;
	private: System::Windows::Forms::Button^  btn_step;
	private: System::Windows::Forms::Button^  btn_stop;
	private: System::Windows::Forms::TextBox^  textBox_n;
	private: System::Windows::Forms::TextBox^  textBox_m;
	private: System::Windows::Forms::TextBox^  textBox_density;
	private: System::Windows::Forms::Button^  btn_set;
	private: System::Windows::Forms::Label^  label_mouse_position;

	private: System::Windows::Forms::Panel^  graph_panel;
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  fileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  openToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  saveToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  exitToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  toolToolStripMenuItem;
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;
	private: System::Windows::Forms::SaveFileDialog^  saveFileDialog1;
		/// <summary>
		/// 必要なデザイナー変数です。
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// デザイナー サポートに必要なメソッドです。このメソッドの内容を
		/// コード エディターで変更しないでください。
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
			this->btn_auto = (gcnew System::Windows::Forms::Button());
			this->btn_step = (gcnew System::Windows::Forms::Button());
			this->btn_stop = (gcnew System::Windows::Forms::Button());
			this->textBox_n = (gcnew System::Windows::Forms::TextBox());
			this->textBox_m = (gcnew System::Windows::Forms::TextBox());
			this->textBox_density = (gcnew System::Windows::Forms::TextBox());
			this->btn_set = (gcnew System::Windows::Forms::Button());
			this->label_mouse_position = (gcnew System::Windows::Forms::Label());
			this->graph_panel = (gcnew System::Windows::Forms::Panel());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->openToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->saveToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->exitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->settingSToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->saveFileDialog1 = (gcnew System::Windows::Forms::SaveFileDialog());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->label_ComponentNum = (gcnew System::Windows::Forms::Label());
			this->label_FieldSize = (gcnew System::Windows::Forms::Label());
			this->label_Delta = (gcnew System::Windows::Forms::Label());
			this->label_F = (gcnew System::Windows::Forms::Label());
			this->label_channels = (gcnew System::Windows::Forms::Label());
			this->label_topology = (gcnew System::Windows::Forms::Label());
			this->label_radius = (gcnew System::Windows::Forms::Label());
			this->label_ground = (gcnew System::Windows::Forms::Label());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->btn_reset = (gcnew System::Windows::Forms::Button());
			this->btn_demo = (gcnew System::Windows::Forms::Button());
			this->btn_simulate = (gcnew System::Windows::Forms::Button());
			this->label_Algorithm_type = (gcnew System::Windows::Forms::Label());
			this->menuStrip1->SuspendLayout();
			this->groupBox1->SuspendLayout();
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// btn_auto
			// 
			this->btn_auto->BackColor = System::Drawing::Color::Transparent;
			this->btn_auto->FlatAppearance->BorderColor = System::Drawing::Color::DimGray;
			this->btn_auto->FlatAppearance->BorderSize = 2;
			this->btn_auto->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btn_auto->ForeColor = System::Drawing::Color::White;
			this->btn_auto->Location = System::Drawing::Point(26, 71);
			this->btn_auto->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->btn_auto->Name = L"btn_auto";
			this->btn_auto->Size = System::Drawing::Size(60, 27);
			this->btn_auto->TabIndex = 0;
			this->btn_auto->Text = L"Auto";
			this->btn_auto->UseVisualStyleBackColor = false;
			this->btn_auto->Click += gcnew System::EventHandler(this, &Form1::btn_auto_Click);
			// 
			// btn_step
			// 
			this->btn_step->BackColor = System::Drawing::Color::Transparent;
			this->btn_step->FlatAppearance->BorderColor = System::Drawing::Color::DimGray;
			this->btn_step->FlatAppearance->BorderSize = 2;
			this->btn_step->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btn_step->ForeColor = System::Drawing::Color::White;
			this->btn_step->Location = System::Drawing::Point(26, 22);
			this->btn_step->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->btn_step->Name = L"btn_step";
			this->btn_step->Size = System::Drawing::Size(60, 27);
			this->btn_step->TabIndex = 1;
			this->btn_step->Text = L"Step";
			this->btn_step->UseVisualStyleBackColor = false;
			this->btn_step->Click += gcnew System::EventHandler(this, &Form1::btn_step_Click);
			// 
			// btn_stop
			// 
			this->btn_stop->BackColor = System::Drawing::Color::Transparent;
			this->btn_stop->FlatAppearance->BorderColor = System::Drawing::Color::DimGray;
			this->btn_stop->FlatAppearance->BorderSize = 2;
			this->btn_stop->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btn_stop->ForeColor = System::Drawing::Color::White;
			this->btn_stop->Location = System::Drawing::Point(26, 118);
			this->btn_stop->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->btn_stop->Name = L"btn_stop";
			this->btn_stop->Size = System::Drawing::Size(60, 27);
			this->btn_stop->TabIndex = 2;
			this->btn_stop->Text = L"Stop";
			this->btn_stop->UseVisualStyleBackColor = false;
			this->btn_stop->Click += gcnew System::EventHandler(this, &Form1::btn_stop_Click);
			// 
			// textBox_n
			// 
			this->textBox_n->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->textBox_n->Location = System::Drawing::Point(48, 173);
			this->textBox_n->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->textBox_n->Name = L"textBox_n";
			this->textBox_n->Size = System::Drawing::Size(78, 22);
			this->textBox_n->TabIndex = 3;
			// 
			// textBox_m
			// 
			this->textBox_m->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->textBox_m->Location = System::Drawing::Point(48, 203);
			this->textBox_m->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->textBox_m->Name = L"textBox_m";
			this->textBox_m->Size = System::Drawing::Size(78, 22);
			this->textBox_m->TabIndex = 4;
			// 
			// textBox_density
			// 
			this->textBox_density->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->textBox_density->Location = System::Drawing::Point(48, 232);
			this->textBox_density->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->textBox_density->Name = L"textBox_density";
			this->textBox_density->Size = System::Drawing::Size(78, 22);
			this->textBox_density->TabIndex = 5;
			// 
			// btn_set
			// 
			this->btn_set->BackColor = System::Drawing::Color::Transparent;
			this->btn_set->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->btn_set->FlatAppearance->BorderColor = System::Drawing::Color::DimGray;
			this->btn_set->FlatAppearance->BorderSize = 2;
			this->btn_set->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btn_set->ForeColor = System::Drawing::Color::White;
			this->btn_set->Location = System::Drawing::Point(42, 268);
			this->btn_set->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->btn_set->Name = L"btn_set";
			this->btn_set->Size = System::Drawing::Size(91, 50);
			this->btn_set->TabIndex = 6;
			this->btn_set->Text = L"Generation";
			this->btn_set->UseVisualStyleBackColor = false;
			this->btn_set->Click += gcnew System::EventHandler(this, &Form1::btn_set_Click);
			// 
			// label_mouse_position
			// 
			this->label_mouse_position->AutoSize = true;
			this->label_mouse_position->ForeColor = System::Drawing::Color::White;
			this->label_mouse_position->Location = System::Drawing::Point(17, 27);
			this->label_mouse_position->Name = L"label_mouse_position";
			this->label_mouse_position->Size = System::Drawing::Size(98, 14);
			this->label_mouse_position->TabIndex = 8;
			this->label_mouse_position->Text = L"MousePosition";
			// 
			// graph_panel
			// 
			this->graph_panel->AutoSize = true;
			this->graph_panel->Location = System::Drawing::Point(0, 30);
			this->graph_panel->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->graph_panel->Name = L"graph_panel";
			this->graph_panel->Size = System::Drawing::Size(948, 776);
			this->graph_panel->TabIndex = 9;
			this->graph_panel->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Form1::graph_panel_Paint);
			this->graph_panel->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::graph_panel_MouseMove);
			// 
			// menuStrip1
			// 
			this->menuStrip1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->menuStrip1->Font = (gcnew System::Drawing::Font(L"Verdana", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->fileToolStripMenuItem,
					this->toolToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Padding = System::Windows::Forms::Padding(8, 2, 0, 2);
			this->menuStrip1->RenderMode = System::Windows::Forms::ToolStripRenderMode::Professional;
			this->menuStrip1->Size = System::Drawing::Size(1150, 24);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// fileToolStripMenuItem
			// 
			this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->openToolStripMenuItem,
					this->saveToolStripMenuItem, this->exitToolStripMenuItem
			});
			this->fileToolStripMenuItem->ForeColor = System::Drawing::Color::White;
			this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			this->fileToolStripMenuItem->Size = System::Drawing::Size(57, 20);
			this->fileToolStripMenuItem->Text = L"File(&F)";
			// 
			// openToolStripMenuItem
			// 
			this->openToolStripMenuItem->Name = L"openToolStripMenuItem";
			this->openToolStripMenuItem->Size = System::Drawing::Size(140, 22);
			this->openToolStripMenuItem->Text = L"Open(&O)...";
			this->openToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::Form1_Open);
			// 
			// saveToolStripMenuItem
			// 
			this->saveToolStripMenuItem->Name = L"saveToolStripMenuItem";
			this->saveToolStripMenuItem->Size = System::Drawing::Size(140, 22);
			this->saveToolStripMenuItem->Text = L"Save(&S)...";
			this->saveToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::Form1_FileSave);
			// 
			// exitToolStripMenuItem
			// 
			this->exitToolStripMenuItem->Name = L"exitToolStripMenuItem";
			this->exitToolStripMenuItem->Size = System::Drawing::Size(140, 22);
			this->exitToolStripMenuItem->Text = L"Exit(&C)";
			this->exitToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::Form1_Closed);
			// 
			// toolToolStripMenuItem
			// 
			this->toolToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->settingSToolStripMenuItem });
			this->toolToolStripMenuItem->ForeColor = System::Drawing::Color::White;
			this->toolToolStripMenuItem->Name = L"toolToolStripMenuItem";
			this->toolToolStripMenuItem->Size = System::Drawing::Size(62, 20);
			this->toolToolStripMenuItem->Text = L"Tool(&T)";
			// 
			// settingSToolStripMenuItem
			// 
			this->settingSToolStripMenuItem->Name = L"settingSToolStripMenuItem";
			this->settingSToolStripMenuItem->Size = System::Drawing::Size(137, 22);
			this->settingSToolStripMenuItem->Text = L"Setting(&S)";
			this->settingSToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::settingSToolStripMenuItem_Click);
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->DefaultExt = L"fileopen";
			this->openFileDialog1->FileName = L"Let open file";
			this->openFileDialog1->Filter = L"JSONファイル(*.json)|*.json|CSVファイル(*.csv)|*.csv|Dataファイル(*.dat)|*.dat|すべてのファイル(*.*)|"
				L"*.*";
			this->openFileDialog1->RestoreDirectory = true;
			this->openFileDialog1->SupportMultiDottedExtensions = true;
			// 
			// saveFileDialog1
			// 
			this->saveFileDialog1->DefaultExt = L"Save";
			this->saveFileDialog1->Filter = L"PNGファイル(*.png)|*.png|JSONファイル(*.json)|*.json|CSVファイル(*.csv)|*.csv|すべてのファイル(*.*)|*"
				L".*";
			this->saveFileDialog1->RestoreDirectory = true;
			this->saveFileDialog1->SupportMultiDottedExtensions = true;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->ForeColor = System::Drawing::Color::White;
			this->label2->Location = System::Drawing::Point(134, 176);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(15, 14);
			this->label2->TabIndex = 10;
			this->label2->Text = L"n";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->ForeColor = System::Drawing::Color::White;
			this->label3->Location = System::Drawing::Point(134, 206);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(18, 14);
			this->label3->TabIndex = 11;
			this->label3->Text = L"m";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->ForeColor = System::Drawing::Color::White;
			this->label4->Location = System::Drawing::Point(134, 232);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(53, 14);
			this->label4->TabIndex = 12;
			this->label4->Text = L"density";
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->label_Algorithm_type);
			this->groupBox1->Controls->Add(this->label_ComponentNum);
			this->groupBox1->Controls->Add(this->label_FieldSize);
			this->groupBox1->Controls->Add(this->label_Delta);
			this->groupBox1->Controls->Add(this->label_F);
			this->groupBox1->Controls->Add(this->label_channels);
			this->groupBox1->Controls->Add(this->label_topology);
			this->groupBox1->Controls->Add(this->label_radius);
			this->groupBox1->Controls->Add(this->label_ground);
			this->groupBox1->Controls->Add(this->label_mouse_position);
			this->groupBox1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->groupBox1->ForeColor = System::Drawing::Color::White;
			this->groupBox1->Location = System::Drawing::Point(6, 373);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(177, 351);
			this->groupBox1->TabIndex = 13;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Parameter";
			// 
			// label_ComponentNum
			// 
			this->label_ComponentNum->AutoSize = true;
			this->label_ComponentNum->ForeColor = System::Drawing::Color::White;
			this->label_ComponentNum->Location = System::Drawing::Point(16, 219);
			this->label_ComponentNum->Name = L"label_ComponentNum";
			this->label_ComponentNum->Size = System::Drawing::Size(125, 14);
			this->label_ComponentNum->TabIndex = 16;
			this->label_ComponentNum->Text = L"Component Num : ";
			// 
			// label_FieldSize
			// 
			this->label_FieldSize->AutoSize = true;
			this->label_FieldSize->ForeColor = System::Drawing::Color::White;
			this->label_FieldSize->Location = System::Drawing::Point(17, 191);
			this->label_FieldSize->Name = L"label_FieldSize";
			this->label_FieldSize->Size = System::Drawing::Size(79, 14);
			this->label_FieldSize->TabIndex = 15;
			this->label_FieldSize->Text = L"Field Size : ";
			// 
			// label_Delta
			// 
			this->label_Delta->AutoSize = true;
			this->label_Delta->ForeColor = System::Drawing::Color::White;
			this->label_Delta->Location = System::Drawing::Point(17, 163);
			this->label_Delta->Name = L"label_Delta";
			this->label_Delta->Size = System::Drawing::Size(128, 14);
			this->label_Delta->TabIndex = 14;
			this->label_Delta->Text = L"Maximum Degree : ";
			// 
			// label_F
			// 
			this->label_F->AutoSize = true;
			this->label_F->ForeColor = System::Drawing::Color::White;
			this->label_F->Location = System::Drawing::Point(17, 135);
			this->label_F->Name = L"label_F";
			this->label_F->Size = System::Drawing::Size(27, 14);
			this->label_F->TabIndex = 13;
			this->label_F->Text = L"F : ";
			// 
			// label_channels
			// 
			this->label_channels->AutoSize = true;
			this->label_channels->ForeColor = System::Drawing::Color::White;
			this->label_channels->Location = System::Drawing::Point(17, 108);
			this->label_channels->Name = L"label_channels";
			this->label_channels->Size = System::Drawing::Size(79, 14);
			this->label_channels->TabIndex = 12;
			this->label_channels->Text = L"Channels : ";
			// 
			// label_topology
			// 
			this->label_topology->AutoSize = true;
			this->label_topology->Font = (gcnew System::Drawing::Font(L"Verdana", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label_topology->ForeColor = System::Drawing::Color::Violet;
			this->label_topology->Location = System::Drawing::Point(15, 318);
			this->label_topology->Name = L"label_topology";
			this->label_topology->Size = System::Drawing::Size(77, 14);
			this->label_topology->TabIndex = 11;
			this->label_topology->Text = L"Topology : ";
			// 
			// label_radius
			// 
			this->label_radius->AutoSize = true;
			this->label_radius->ForeColor = System::Drawing::Color::White;
			this->label_radius->Location = System::Drawing::Point(17, 81);
			this->label_radius->Name = L"label_radius";
			this->label_radius->Size = System::Drawing::Size(62, 14);
			this->label_radius->TabIndex = 10;
			this->label_radius->Text = L"Radius : ";
			// 
			// label_ground
			// 
			this->label_ground->AutoSize = true;
			this->label_ground->ForeColor = System::Drawing::Color::White;
			this->label_ground->Location = System::Drawing::Point(17, 54);
			this->label_ground->Name = L"label_ground";
			this->label_ground->Size = System::Drawing::Size(103, 14);
			this->label_ground->TabIndex = 9;
			this->label_ground->Text = L"Global Round : ";
			// 
			// panel1
			// 
			this->panel1->AutoSize = true;
			this->panel1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->panel1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel1->Controls->Add(this->btn_reset);
			this->panel1->Controls->Add(this->btn_demo);
			this->panel1->Controls->Add(this->btn_simulate);
			this->panel1->Controls->Add(this->btn_set);
			this->panel1->Controls->Add(this->label4);
			this->panel1->Controls->Add(this->groupBox1);
			this->panel1->Controls->Add(this->label3);
			this->panel1->Controls->Add(this->label2);
			this->panel1->Controls->Add(this->textBox_density);
			this->panel1->Controls->Add(this->textBox_m);
			this->panel1->Controls->Add(this->textBox_n);
			this->panel1->Controls->Add(this->btn_stop);
			this->panel1->Controls->Add(this->btn_step);
			this->panel1->Controls->Add(this->btn_auto);
			this->panel1->ForeColor = System::Drawing::Color::DimGray;
			this->panel1->Location = System::Drawing::Point(954, 30);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(194, 777);
			this->panel1->TabIndex = 15;
			// 
			// btn_reset
			// 
			this->btn_reset->BackColor = System::Drawing::Color::Transparent;
			this->btn_reset->FlatAppearance->BorderColor = System::Drawing::Color::DimGray;
			this->btn_reset->FlatAppearance->BorderSize = 2;
			this->btn_reset->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btn_reset->ForeColor = System::Drawing::Color::Gold;
			this->btn_reset->Location = System::Drawing::Point(112, 71);
			this->btn_reset->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->btn_reset->Name = L"btn_reset";
			this->btn_reset->Size = System::Drawing::Size(60, 27);
			this->btn_reset->TabIndex = 16;
			this->btn_reset->Text = L"Reset";
			this->btn_reset->UseVisualStyleBackColor = false;
			this->btn_reset->Click += gcnew System::EventHandler(this, &Form1::btn_reset_Click);
			// 
			// btn_demo
			// 
			this->btn_demo->BackColor = System::Drawing::Color::Transparent;
			this->btn_demo->FlatAppearance->BorderColor = System::Drawing::Color::DimGray;
			this->btn_demo->FlatAppearance->BorderSize = 2;
			this->btn_demo->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btn_demo->Font = (gcnew System::Drawing::Font(L"Verdana", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_demo->ForeColor = System::Drawing::Color::Aqua;
			this->btn_demo->Location = System::Drawing::Point(42, 731);
			this->btn_demo->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->btn_demo->Name = L"btn_demo";
			this->btn_demo->Size = System::Drawing::Size(91, 34);
			this->btn_demo->TabIndex = 15;
			this->btn_demo->Text = L"Demo";
			this->btn_demo->UseVisualStyleBackColor = false;
			this->btn_demo->Click += gcnew System::EventHandler(this, &Form1::btn_demo_Click);
			// 
			// btn_simulate
			// 
			this->btn_simulate->BackColor = System::Drawing::Color::Transparent;
			this->btn_simulate->FlatAppearance->BorderColor = System::Drawing::Color::DimGray;
			this->btn_simulate->FlatAppearance->BorderSize = 2;
			this->btn_simulate->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btn_simulate->ForeColor = System::Drawing::Color::White;
			this->btn_simulate->Location = System::Drawing::Point(48, 339);
			this->btn_simulate->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->btn_simulate->Name = L"btn_simulate";
			this->btn_simulate->Size = System::Drawing::Size(80, 27);
			this->btn_simulate->TabIndex = 14;
			this->btn_simulate->Text = L"Simulate";
			this->btn_simulate->UseVisualStyleBackColor = false;
			this->btn_simulate->Click += gcnew System::EventHandler(this, &Form1::btn_simulate_Click);
			// 
			// label_Algorithm_type
			// 
			this->label_Algorithm_type->AutoSize = true;
			this->label_Algorithm_type->ForeColor = System::Drawing::Color::White;
			this->label_Algorithm_type->Location = System::Drawing::Point(17, 250);
			this->label_Algorithm_type->Name = L"label_Algorithm_type";
			this->label_Algorithm_type->Size = System::Drawing::Size(75, 14);
			this->label_Algorithm_type->TabIndex = 17;
			this->label_Algorithm_type->Text = L"Algorithm :";
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 14);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->ClientSize = System::Drawing::Size(1150, 812);
			this->Controls->Add(this->menuStrip1);
			this->Controls->Add(this->graph_panel);
			this->Controls->Add(this->panel1);
			this->Font = (gcnew System::Drawing::Font(L"Verdana", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MainMenuStrip = this->menuStrip1;
			this->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->Name = L"Form1";
			this->Text = L"Simulator";
			this->Closed += gcnew System::EventHandler(this, &Form1::Form1_Closed);
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->Resize += gcnew System::EventHandler(this, &Form1::Form1_Resize);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: 
		System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
		}
	private:
		System::Void UpdateDistributedSystem( ){
			while(1)
			{
				if ( this->observer->Stop == false )
				{
					this->SetText( String::Format("Global Round : {0}",this->controller->GlobalRound) );
				}
				Thread::Sleep(_CheckInfo_Speed_ms);
			}
		}
	private:
		delegate System::Void SetTextDelegate(String^ text);
	private:
		System::Void SetText( String^ text){
			if (this->label_ground->InvokeRequired)
			{	
				SetTextDelegate^ d = gcnew SetTextDelegate(this, &Form1::SetText);
				this->Invoke(d, gcnew cli::array<System::Object^> { text });
			}
			else
			{
				this->label_ground->Text = text;
			}
		}
	//TODO AA reset problem
	private:
		System::Void btn_set_Click(System::Object^  sender, System::EventArgs^  e) {
			if ( this->textBox_n->Text == "" || this->textBox_m->Text == "" || this->textBox_density->Text == "" )
			{
				MessageBox::Show("parameter is empty", "Simulator", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
			else
			{
				int n = Convert::ToInt32(this->textBox_n->Text,10);
				int m;
				if ( this->settings->topology == 1 /*Unit Disk Graph*/)
				{
					if (n >= 1000)
					{
						m = MAXIMUM_CHANNEL;//n*(n-1)/2;
					}
					else
					{
						m = n*(n - 1) / 2;
					}
					this->textBox_m->Clear();
					this->textBox_m->Paste(Convert::ToString(m));
				}
				else /*Random Graph*/
				{
					m = Convert::ToInt32(this->textBox_m->Text,10);
				}
				//restrict number of edges
				if ( ((n*(n-1))/2) < m )
				{
					MessageBox::Show("m is too large", "Simulator", MessageBoxButtons::OK, MessageBoxIcon::Error);
				}
				else
				{
					double density = Convert::ToDouble(this->textBox_density->Text);
					if (Math::Pow(2*density*this->settings->NODE_SIZE,2)*n > this->settings->Field_Size[0]*this->settings->Field_Size[1]){
						MessageBox::Show("n or density or NODE_SIZE is too large", "Simulator", MessageBoxButtons::OK, MessageBoxIcon::Error);
						return;
					}
					this->controller->SetGraphParameter(settings);
					this->controller->InitializeGraph( n, m, density);
					this->settings->F = this->controller->F;

					this->visualizer->SetParameter(settings);
					this->observer->SetCondition(settings);
					this->visualizer->Draw();
					this->PrintParam();
					this->label_ComponentNum->Text = String::Format("Component Num : {0}",this->controller->component_num );
					if ( this->settings->topology == 1 )
					{
						this->label_channels->Text = String::Format("Channels : {0}",this->controller->channel_num);
					}
					else
					{
						this->label_channels->Text = String::Format("Channels : {0}", this->controller->M);
					}
					this->label_Delta->Text = String::Format("Maximum Degree : {0}", this->controller->delta);
				}
			}
		}

	private: 
		void graph_panel_MouseMove( Object^ /*sender*/, System::Windows::Forms::MouseEventArgs^ e ){
			this->label_mouse_position->Text=String::Format("(x,y)=({0},{1})", e->X, e->Y);
		}

	private: 
		void graph_panel_Paint( Object^ sender, System::Windows::Forms::PaintEventArgs^ e ){
		}

	private:
		System::Void Form1_Closed(System::Object^  sender, System::EventArgs^  e) {
			this->Close();
			exit(0);
		}
	/**
	 ** 終了処理
	 **/
	private:
		void Close(){
			this->Run_Algorithm->Abort();
			this->UpdateInfo->Abort();
		#ifdef _DEBUG
			String^ a = String::Format("Thread Abort");
			System::Diagnostics::Debug::WriteLine(a);
		#endif
		}

	private:
		System::Void Form1_Open(System::Object^  sender, System::EventArgs^  e) {
			this->openFileDialog1->Title = L"Open File";

			if (openFileDialog1->ShowDialog() != System::Windows::Forms::DialogResult::OK ) return;

			if ( OpenFile( openFileDialog1->FileName ) == false )
			{
				MessageBox::Show("ファイルの読み込みに失敗しました", "Simulator", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			}
			this->fileName = openFileDialog1->FileName;
		}

	private:
		System::Void Form1_FileSave(System::Object^  sender, System::EventArgs^  e) {
			this->saveFileDialog1->Title = L"Save File";

			if ( saveFileDialog1->ShowDialog() != System::Windows::Forms::DialogResult::OK ) return;

			if (SaveFile(saveFileDialog1->FileName) == false)
			{
				MessageBox::Show("ファイル名を入力してください", "Simulator", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			}

			SaveFile( saveFileDialog1->FileName );
			this->fileName = saveFileDialog1->FileName;
		}

	/**
	 ** Save File
	 **/
	private:
		bool SaveFile( String^ path ) {
			if ( path->EndsWith(".csv") )
			{
				// CSV形式で保存
				return SaveCsvFile( path );
			}
			else if ( path->EndsWith(".json") )
			{
				// JSON形式で保存
				return SaveJsonFile( path );
			}
			else if ( path->EndsWith(".png") )
			{
				return SavePngFile( path );
			}
			else
			{
				// その他の場合はCSV形式で保存
				return SaveCsvFile( path );
			}
		}

	private:
		bool SaveCsvFile( String^ path ) {
			StreamWriter^ writer = gcnew StreamWriter( path, false,System::Text::Encoding::GetEncoding("UTF-8"));
			writer->WriteLine("THIS,IS,TEST,WRITE,FILE");
			writer->Close();
			return true;
		}

	private:
		bool SaveJsonFile( String^ path ) {
			delete this->data_manager;
			this->data_manager = gcnew DataManager(this->controller);
			StreamWriter^ writer = gcnew StreamWriter(path, false, System::Text::Encoding::GetEncoding("UTF-8"));
			writer->WriteLine(this->data_manager->OutPutJSONrefController());
			writer->Close();
			return true;
		}

	private:
		bool SavePngFile( String^ path ) {
			return true;
		}

	/**
	 ** Open File
	 **/
	private:
		bool OpenFile( String^ path ) {
			if ( path->EndsWith(".csv"))
			{
				// CSV形式で開く
				return LoadCsvFile( path );
			}
			else if ( path->EndsWith(".json") )
			{
				// JSON形式で開く
				return LoadJsonFile( path );
			}
			else
			{
				// その他の場合はCSV形式で開く
				return LoadCsvFile( path );
			}
		}

	private:
		bool LoadCsvFile( String^ path ) {
			return true;
		}

	private:
		bool LoadJsonFile( String^ path ) {
			return true;
		}

	private:
		void InitSetting () {
			this->settings = new Settings;
			this->settings->AA = true;
			this->settings->Drawing = true;
			this->settings->NODE_SIZE = 10;
			this->settings->PEN_WIDTH = 0.5f;
			this->settings->unitdisk_r = 50;
			this->settings->F = 10;
			this->settings->Req_Connectivity = false;
			this->settings->Check_num = 100;
			this->settings->topology = 1;
			this->settings->algorithm_type = 1;
			this->settings->execution_times = 100;
			this->settings->execution_condition[0] = 1000;
			this->settings->execution_condition[1] = 10000;
			this->settings->execution_condition[2] = 1000;
			this->settings->isSameTopology = true;
			this->settings->Field_Size[0] = this->graph_panel->Size.Width;
			this->settings->Field_Size[1] = this->graph_panel->Size.Height;
		}
	private:
		System::Void settingSToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			FormSetting^ fs = gcnew FormSetting(this->settings);
				
			fs->ShowDialog();
			if (fs->Cancel())return;
			settings = fs->GetSetting();
			if (settings->algorithm_type != this->controller->algorithm_type)
			{
				this->controller->Initialize();
			}
			this->controller->RefleshFrequency(settings->F);
			this->visualizer->SetParameter(settings);
			if (settings->Field_Size[0] != this->controller->x || settings->Field_Size[1] != this->controller->y)
			{
				this->controller->ResizeField(settings->Field_Size[0], settings->Field_Size[1]);
			}
			this->controller->SetGraphParameter(settings);
			this->observer->SetCondition(settings);
			this->visualizer->Draw();
			this->PrintParam();
		}

	private:
		System::Void PrintParam() {
			this->label_radius->Text = String::Format("Radius : {0}",settings->unitdisk_r);
			this->label_topology->Text = String::Format("Topology : {0}",this->TopologyInt2String(settings->topology));
			this->label_F->Text = String::Format("F : {0}",settings->F);
			this->label_FieldSize->Text = String::Format("Field Size : {0},{1}", settings->Field_Size[0], settings->Field_Size[1]);
			this->label_Algorithm_type->Text = String::Format("Algorithm : {0}", AlgorithmUIntToString(settings->algorithm_type));
		}

	private:
		System::Void btn_auto_Click(System::Object^  sender, System::EventArgs^  e) {
			if ( this->observer->Stop )
			{
				this->Run_Algorithm = gcnew Thread( gcnew ThreadStart( this->observer, &Observer::Run ) );
				this->Run_Algorithm->Start();
			}
			this->observer->Stop = false;
		}

	 private:
		 System::Void btn_simulate_Click(System::Object^  sender, System::EventArgs^  e) {
			this->observer->Simulate();
		}

	private:
		System::Void btn_stop_Click(System::Object^  sender, System::EventArgs^  e) {
			this->observer->Stop = true;
		}

	private:
		System::Void btn_step_Click(System::Object^  sender, System::EventArgs^  e) {
			if ( this->observer->Stop )
			{
				this->controller->Run();
				this->visualizer->Draw();
				this->SetText(String::Format("Global Round : {0}", this->controller->GlobalRound));
			}
		}

	private:
		System::Void btn_reset_Click(System::Object^  sender, System::EventArgs^  e) {
			this->controller->Initialize();
			this->visualizer->Draw();
			this->observer->Stop = true;
		}


	private:
		System::Void btn_demo_Click(System::Object^  sender, System::EventArgs^  e) {
			if (this->observer->Stop)
			{
				this->Demo_Algorithm = gcnew Thread(gcnew ThreadStart(this->observer, &Observer::Demonstrate));
				this->Demo_Algorithm->Start();
			}
		}

	private:
		System::String^ TopologyInt2String(int topology){
			if ( topology == 0 )
			{
				return "Random";
			}
			else if ( topology == 1 )
			{
				return "UnitDisk";
			}
			else
			{
				return "None";
			}
		}
	private: 
		System::String^ AlgorithmUIntToString(unsigned int algorithm_type){
			if (algorithm_type == 0)
			{
				return "MIS";
			}
			else if (algorithm_type == 1)
			{
				return "MM";
			}
			else if (algorithm_type == 2)
			{
				return "LE";
			}
			else
			{
				return "None";
			}
		}
	/*
	 * Dynamic Layout
	 */
	private:
		System::Void Form1_Resize(System::Object^  sender, System::EventArgs^  e) {
			this->graph_panel->Size = System::Drawing::Size( this->Width - 210 - 6, this->Height - 120 );
			this->settings->Field_Size[0] = this->graph_panel->Width;
			this->settings->Field_Size[1] = this->graph_panel->Height;
			this->panel1->Size = System::Drawing::Size( 194, this->Height - 120 );
			this->panel1->Location = System::Drawing::Point( this->Width - 210, 32 );
			this->controller->ResizeField( this->graph_panel->Size.Width, this->graph_panel->Size.Height );
			this->PrintParam();
		}
	};
}

