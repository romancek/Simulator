#pragma once

#include "FormSetting.h"
#include "Controller.h"
#include "Node.h"
#include "Form1.h"
#include "Visualizer.h"
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
	private: System::Windows::Forms::ToolStripMenuItem^  settingSToolStripMenuItem;
	private: String^ fileName;      // 読み書きファイル名
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: Node^ node;
	private: bool UpdatePanel;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::Label^  label_ground;
	private: System::Windows::Forms::Splitter^  splitter1;
	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::Label^  label_radius;
	private: Thread^ Run_Algorithm;
	private: System::Windows::Forms::Label^  label_topology;
	private: Settings* settings;
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: ここにコンストラクター コードを追加します
			//
			this->settings = new Settings;
			this->settings->topology = 0;//Random
			this->controller = gcnew Controller(this->graph_panel->Size.Width,this->graph_panel->Size.Height);
			this->controller->InitializeGraph(this->settings->topology);
			this->visualizer = gcnew Visualizer(controller,graph_panel->CreateGraphics());
			this->Run_Algorithm = gcnew Thread( gcnew ThreadStart( this->visualizer, &Visualizer::Run ) );
			//this->visualizer->Draw();
			this->UpdatePanel = true;
		}

	protected:
		/// <summary>
		/// 使用中のリソースをすべてクリーンアップします。
		/// </summary>
		virtual void OnPaint( PaintEventArgs^ e ) override
		{
			Form::OnPaint( e );
			
		}
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  btn_auto;
	protected: 
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
	private:
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
			this->label_radius = (gcnew System::Windows::Forms::Label());
			this->label_ground = (gcnew System::Windows::Forms::Label());
			this->splitter1 = (gcnew System::Windows::Forms::Splitter());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->label_topology = (gcnew System::Windows::Forms::Label());
			this->menuStrip1->SuspendLayout();
			this->groupBox1->SuspendLayout();
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// btn_auto
			// 
			this->btn_auto->Location = System::Drawing::Point(42, 75);
			this->btn_auto->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->btn_auto->Name = L"btn_auto";
			this->btn_auto->Size = System::Drawing::Size(70, 29);
			this->btn_auto->TabIndex = 0;
			this->btn_auto->Text = L"Auto";
			this->btn_auto->UseVisualStyleBackColor = true;
			this->btn_auto->Click += gcnew System::EventHandler(this, &Form1::btn_auto_Click);
			// 
			// btn_step
			// 
			this->btn_step->Location = System::Drawing::Point(42, 19);
			this->btn_step->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->btn_step->Name = L"btn_step";
			this->btn_step->Size = System::Drawing::Size(70, 29);
			this->btn_step->TabIndex = 1;
			this->btn_step->Text = L"Step";
			this->btn_step->UseVisualStyleBackColor = true;
			this->btn_step->Click += gcnew System::EventHandler(this, &Form1::btn_step_Click);
			// 
			// btn_stop
			// 
			this->btn_stop->Location = System::Drawing::Point(42, 131);
			this->btn_stop->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->btn_stop->Name = L"btn_stop";
			this->btn_stop->Size = System::Drawing::Size(70, 29);
			this->btn_stop->TabIndex = 2;
			this->btn_stop->Text = L"Stop";
			this->btn_stop->UseVisualStyleBackColor = true;
			this->btn_stop->Click += gcnew System::EventHandler(this, &Form1::btn_stop_Click);
			// 
			// textBox_n
			// 
			this->textBox_n->Location = System::Drawing::Point(42, 225);
			this->textBox_n->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->textBox_n->Name = L"textBox_n";
			this->textBox_n->Size = System::Drawing::Size(69, 21);
			this->textBox_n->TabIndex = 3;
			// 
			// textBox_m
			// 
			this->textBox_m->Location = System::Drawing::Point(42, 257);
			this->textBox_m->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->textBox_m->Name = L"textBox_m";
			this->textBox_m->Size = System::Drawing::Size(69, 21);
			this->textBox_m->TabIndex = 4;
			// 
			// textBox_density
			// 
			this->textBox_density->Location = System::Drawing::Point(42, 288);
			this->textBox_density->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->textBox_density->Name = L"textBox_density";
			this->textBox_density->Size = System::Drawing::Size(69, 21);
			this->textBox_density->TabIndex = 5;
			// 
			// btn_set
			// 
			this->btn_set->Location = System::Drawing::Point(896, 372);
			this->btn_set->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->btn_set->Name = L"btn_set";
			this->btn_set->Size = System::Drawing::Size(40, 28);
			this->btn_set->TabIndex = 6;
			this->btn_set->Text = L"Set";
			this->btn_set->UseVisualStyleBackColor = true;
			this->btn_set->Click += gcnew System::EventHandler(this, &Form1::btn_set_Click);
			// 
			// label_mouse_position
			// 
			this->label_mouse_position->AutoSize = true;
			this->label_mouse_position->Location = System::Drawing::Point(20, 29);
			this->label_mouse_position->Name = L"label_mouse_position";
			this->label_mouse_position->Size = System::Drawing::Size(81, 15);
			this->label_mouse_position->TabIndex = 8;
			this->label_mouse_position->Text = L"MousePosition";
			// 
			// graph_panel
			// 
			this->graph_panel->Location = System::Drawing::Point(12, 34);
			this->graph_panel->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->graph_panel->Name = L"graph_panel";
			this->graph_panel->Size = System::Drawing::Size(817, 729);
			this->graph_panel->TabIndex = 9;
			this->graph_panel->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Form1::graph_panel_Paint);
			this->graph_panel->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::graph_panel_MouseMove);
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->fileToolStripMenuItem, 
				this->toolToolStripMenuItem});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Padding = System::Windows::Forms::Padding(7, 2, 0, 2);
			this->menuStrip1->Size = System::Drawing::Size(1006, 24);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// fileToolStripMenuItem
			// 
			this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {this->openToolStripMenuItem, 
				this->saveToolStripMenuItem, this->exitToolStripMenuItem});
			this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			this->fileToolStripMenuItem->Size = System::Drawing::Size(51, 20);
			this->fileToolStripMenuItem->Text = L"File(&F)";
			// 
			// openToolStripMenuItem
			// 
			this->openToolStripMenuItem->Name = L"openToolStripMenuItem";
			this->openToolStripMenuItem->Size = System::Drawing::Size(118, 22);
			this->openToolStripMenuItem->Text = L"Open(&O)...";
			this->openToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::Form1_Open);
			// 
			// saveToolStripMenuItem
			// 
			this->saveToolStripMenuItem->Name = L"saveToolStripMenuItem";
			this->saveToolStripMenuItem->Size = System::Drawing::Size(118, 22);
			this->saveToolStripMenuItem->Text = L"Save(&S)...";
			this->saveToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::Form1_FileSave);
			// 
			// exitToolStripMenuItem
			// 
			this->exitToolStripMenuItem->Name = L"exitToolStripMenuItem";
			this->exitToolStripMenuItem->Size = System::Drawing::Size(118, 22);
			this->exitToolStripMenuItem->Text = L"Exit(&C)";
			this->exitToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::Form1_Exit);
			// 
			// toolToolStripMenuItem
			// 
			this->toolToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) {this->settingSToolStripMenuItem});
			this->toolToolStripMenuItem->Name = L"toolToolStripMenuItem";
			this->toolToolStripMenuItem->Size = System::Drawing::Size(54, 20);
			this->toolToolStripMenuItem->Text = L"Tool(&T)";
			// 
			// settingSToolStripMenuItem
			// 
			this->settingSToolStripMenuItem->Name = L"settingSToolStripMenuItem";
			this->settingSToolStripMenuItem->Size = System::Drawing::Size(121, 22);
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
			this->saveFileDialog1->FileName = L"Save file";
			this->saveFileDialog1->Filter = L"PNGファイル(*.png)|*.png|JSONファイル(*.json)|*.json|CSVファイル(*.csv)|*.csv|すべてのファイル(*.*)|*" 
				L".*";
			this->saveFileDialog1->RestoreDirectory = true;
			this->saveFileDialog1->SupportMultiDottedExtensions = true;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(117, 228);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(13, 15);
			this->label2->TabIndex = 10;
			this->label2->Text = L"n";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(117, 260);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(16, 15);
			this->label3->TabIndex = 11;
			this->label3->Text = L"m";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(117, 288);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(43, 15);
			this->label4->TabIndex = 12;
			this->label4->Text = L"density";
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->label_topology);
			this->groupBox1->Controls->Add(this->label_radius);
			this->groupBox1->Controls->Add(this->label_ground);
			this->groupBox1->Controls->Add(this->label_mouse_position);
			this->groupBox1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->groupBox1->Location = System::Drawing::Point(5, 400);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(155, 305);
			this->groupBox1->TabIndex = 13;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Parameter";
			// 
			// label_radius
			// 
			this->label_radius->AutoSize = true;
			this->label_radius->Location = System::Drawing::Point(20, 88);
			this->label_radius->Name = L"label_radius";
			this->label_radius->Size = System::Drawing::Size(49, 15);
			this->label_radius->TabIndex = 10;
			this->label_radius->Text = L"Radius : ";
			// 
			// label_ground
			// 
			this->label_ground->AutoSize = true;
			this->label_ground->Location = System::Drawing::Point(20, 59);
			this->label_ground->Name = L"label_ground";
			this->label_ground->Size = System::Drawing::Size(83, 15);
			this->label_ground->TabIndex = 9;
			this->label_ground->Text = L"Global Round : ";
			// 
			// splitter1
			// 
			this->splitter1->Location = System::Drawing::Point(0, 24);
			this->splitter1->Name = L"splitter1";
			this->splitter1->Size = System::Drawing::Size(3, 746);
			this->splitter1->TabIndex = 14;
			this->splitter1->TabStop = false;
			// 
			// panel1
			// 
			this->panel1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
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
			this->panel1->Location = System::Drawing::Point(835, 34);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(170, 729);
			this->panel1->TabIndex = 15;
			// 
			// label_topology
			// 
			this->label_topology->AutoSize = true;
			this->label_topology->Font = (gcnew System::Drawing::Font(L"メイリオ", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label_topology->ForeColor = System::Drawing::Color::Purple;
			this->label_topology->Location = System::Drawing::Point(21, 281);
			this->label_topology->Name = L"label_topology";
			this->label_topology->Size = System::Drawing::Size(73, 18);
			this->label_topology->TabIndex = 11;
			this->label_topology->Text = L"Topology : ";
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSize = true;
			this->BackColor = System::Drawing::Color::Gainsboro;
			this->ClientSize = System::Drawing::Size(1006, 770);
			this->Controls->Add(this->splitter1);
			this->Controls->Add(this->btn_set);
			this->Controls->Add(this->menuStrip1);
			this->Controls->Add(this->graph_panel);
			this->Controls->Add(this->panel1);
			this->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
			this->MainMenuStrip = this->menuStrip1;
			this->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->Name = L"Form1";
			this->Text = L"Simulator";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
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

private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {

	}

private: void UpdateDistributedSystem( void ){

	}

//TODO AA reset problem
private: System::Void btn_set_Click(System::Object^  sender, System::EventArgs^  e) {
		if(this->textBox_n->Text == "" || this->textBox_m->Text == "" || this->textBox_density->Text == "" ){
			MessageBox::Show("parameter is empty", "Simulator", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}else{
			this->visualizer->Clear();
			int n = Convert::ToInt32(this->textBox_n->Text,10);
			int m = Convert::ToInt32(this->textBox_m->Text,10);
			//restrict number of edges
			if( ((n*(n-1))/2) < m ){
				MessageBox::Show("m is too large", "Simulator", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}else{
				int density = Convert::ToInt32(this->textBox_density->Text,10);
				this->controller->InitializeGraph( n, m, density, this->settings->topology);
				this->visualizer->Draw();
			}
		}
	}

private: void graph_panel_MouseMove( Object^ /*sender*/, System::Windows::Forms::MouseEventArgs^ e ){
		this->label_mouse_position->Text=String::Format("({0},{1})", e->X, e->Y);
	}

private: void graph_panel_Paint( Object^ sender, System::Windows::Forms::PaintEventArgs^ e ){
		//TODO
		this->visualizer->Draw();
		this->label_ground->Text = String::Format("Global Round : {0}",this->controller->GlobalRound);
	}

private: System::Void Form1_Exit(System::Object^  sender, System::EventArgs^  e) {
		this->Close();
	}

private: System::Void Form1_Open(System::Object^  sender, System::EventArgs^  e) {
		this->openFileDialog1->Title = L"Open File";

		if (openFileDialog1->ShowDialog() != System::Windows::Forms::DialogResult::OK) return;

		if( OpenFile( openFileDialog1->FileName ) == false){
			MessageBox::Show("ファイルの読み込みに失敗しました", "Simulator", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}
		this->fileName = openFileDialog1->FileName;
		UpdateDistributedSystem();
	}

private: System::Void Form1_FileSave(System::Object^  sender, System::EventArgs^  e) {
		this->saveFileDialog1->Title = L"Save File";

		if (saveFileDialog1->ShowDialog() != System::Windows::Forms::DialogResult::OK) return;

		SaveFile( saveFileDialog1->FileName );
		this->fileName = saveFileDialog1->FileName;
	}

//
// Save
//
private: bool SaveFile( String^ path ) {
		if ( path->EndsWith(".csv")) {
			// CSV形式で保存
			return SaveCsvFile( path );
		} else if ( path->EndsWith(".json")) {
			// JSON形式で保存
			return SaveJsonFile( path );
		}else if  ( path->EndsWith(".png")) {
			return SavePngFile( path );
		} else {
			// その他の場合はCSV形式で保存
			return SaveCsvFile( path );
		}
	}

private: bool SaveCsvFile( String^ path ) {
		StreamWriter^ writer = gcnew StreamWriter( path, false,System::Text::Encoding::GetEncoding("UTF-8"));
		writer->WriteLine("THIS,IS,TEST,WRITE,FILE");
		writer->Close();
		return true;
	}

private: bool SaveJsonFile( String^ path ) {
		return true;
	}

private: bool SavePngFile( String^ path ) {
		return true;
	}

//
// Open
//
private: bool OpenFile( String^ path ) {
		if ( path->EndsWith(".csv")) {
			// CSV形式で開く
			return LoadCsvFile( path );
		} else if ( path->EndsWith(".json")) {
			// JSON形式で開く
			return LoadJsonFile( path );
		} else if ( path->EndsWith(".png")) {
			// PNG形式で開く
			return LoadPngFile( path );	
		} else {
			// その他の場合はCSV形式で開く
			return LoadCsvFile( path );
		}
	}

private: bool LoadCsvFile( String^ path ) {
		return true;
	}

private: bool LoadJsonFile( String^ path ) {
		return true;
	}

private: bool LoadPngFile( String^ path ) {
		return true;
	}

private: System::Void settingSToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		FormSetting^ fs = gcnew FormSetting();
		fs->ShowDialog();
		System::Diagnostics::Debug::WriteLine("Setting Form return");
		settings = fs->GetSetting();
		this->visualizer->SetParameter(settings);
		this->controller->SetGraphParameter(settings);
		this->label_radius->Text = String::Format("Radius : {0}",settings->unitdisk_r);
		this->label_topology->Text = String::Format("Topology : {0}",this->TopologyInt2String(settings->topology));
		this->visualizer->Draw();
	}

private: System::Void btn_auto_Click(System::Object^  sender, System::EventArgs^  e) {
		if(this->visualizer->Stop){
			this->Run_Algorithm = gcnew Thread( gcnew ThreadStart( this->visualizer, &Visualizer::Run ) );
			this->Run_Algorithm->Start();
		}
		this->visualizer->Stop = false;
	}

private: System::Void btn_stop_Click(System::Object^  sender, System::EventArgs^  e) {
		this->visualizer->Stop = true;
	}

private: System::Void btn_step_Click(System::Object^  sender, System::EventArgs^  e) {
		
	}
private: System::String^ TopologyInt2String(int topology){
		if(topology == 0){
			return "Random";
		}else if(topology == 1){
			return "UnitDisk";
		}else{
			return "None";
		}
	}
};
}

