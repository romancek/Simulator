#pragma once
#include <string>
#include <boost/version.hpp>
#include "FormSetting.h"
#include "Controller.h"
#include "Node.h"
#include "picojson.h"


namespace BeepingModel {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;
	/// <summary>
	/// Form1 の概要
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	private: Controller^ controller;
	private: System::Windows::Forms::ToolStripMenuItem^  settingSToolStripMenuItem;
	private: String^ fileName;      // 読み書きファイル名

	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: ここにコンストラクター コードを追加します
			//
			this->controller = gcnew Controller();
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
			}
		}
	private: System::Windows::Forms::Button^  btn_auto;
	protected: 
	private: System::Windows::Forms::Button^  btn_step;
	private: System::Windows::Forms::Button^  btn_stop;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::TextBox^  textBox3;
	private: System::Windows::Forms::Button^  btn_set;
	private: System::Windows::Forms::PictureBox^  pict_graph;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  fileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  openToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  saveToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  exitToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  toolToolStripMenuItem;

	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;
	private: System::Windows::Forms::SaveFileDialog^  saveFileDialog1;


	protected: 

	protected: 











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
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->btn_set = (gcnew System::Windows::Forms::Button());
			this->pict_graph = (gcnew System::Windows::Forms::PictureBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->openToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->saveToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->exitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->saveFileDialog1 = (gcnew System::Windows::Forms::SaveFileDialog());
			this->settingSToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pict_graph))->BeginInit();
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// btn_auto
			// 
			this->btn_auto->Location = System::Drawing::Point(882, 116);
			this->btn_auto->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->btn_auto->Name = L"btn_auto";
			this->btn_auto->Size = System::Drawing::Size(70, 29);
			this->btn_auto->TabIndex = 0;
			this->btn_auto->Text = L"Auto";
			this->btn_auto->UseVisualStyleBackColor = true;
			// 
			// btn_step
			// 
			this->btn_step->Location = System::Drawing::Point(882, 60);
			this->btn_step->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->btn_step->Name = L"btn_step";
			this->btn_step->Size = System::Drawing::Size(70, 29);
			this->btn_step->TabIndex = 1;
			this->btn_step->Text = L"Step";
			this->btn_step->UseVisualStyleBackColor = true;
			// 
			// btn_stop
			// 
			this->btn_stop->Location = System::Drawing::Point(882, 172);
			this->btn_stop->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->btn_stop->Name = L"btn_stop";
			this->btn_stop->Size = System::Drawing::Size(70, 29);
			this->btn_stop->TabIndex = 2;
			this->btn_stop->Text = L"Stop";
			this->btn_stop->UseVisualStyleBackColor = true;
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(882, 266);
			this->textBox1->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(69, 21);
			this->textBox1->TabIndex = 3;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(882, 298);
			this->textBox2->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(69, 21);
			this->textBox2->TabIndex = 4;
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(882, 329);
			this->textBox3->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(69, 21);
			this->textBox3->TabIndex = 5;
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
			// 
			// pict_graph
			// 
			this->pict_graph->Location = System::Drawing::Point(12, 34);
			this->pict_graph->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->pict_graph->Name = L"pict_graph";
			this->pict_graph->Size = System::Drawing::Size(817, 729);
			this->pict_graph->TabIndex = 7;
			this->pict_graph->TabStop = false;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(884, 579);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(35, 15);
			this->label1->TabIndex = 8;
			this->label1->Text = L"label1";
			// 
			// panel1
			// 
			this->panel1->Location = System::Drawing::Point(12, 34);
			this->panel1->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(817, 729);
			this->panel1->TabIndex = 9;
			this->panel1->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::panel1_MouseMove);
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
			this->openToolStripMenuItem->Size = System::Drawing::Size(152, 22);
			this->openToolStripMenuItem->Text = L"Open(&O)...";
			this->openToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::Form1_Open);
			// 
			// saveToolStripMenuItem
			// 
			this->saveToolStripMenuItem->Name = L"saveToolStripMenuItem";
			this->saveToolStripMenuItem->Size = System::Drawing::Size(152, 22);
			this->saveToolStripMenuItem->Text = L"Save(&S)...";
			this->saveToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::Form1_FileSave);
			// 
			// exitToolStripMenuItem
			// 
			this->exitToolStripMenuItem->Name = L"exitToolStripMenuItem";
			this->exitToolStripMenuItem->Size = System::Drawing::Size(152, 22);
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
			// settingSToolStripMenuItem
			// 
			this->settingSToolStripMenuItem->Name = L"settingSToolStripMenuItem";
			this->settingSToolStripMenuItem->Size = System::Drawing::Size(152, 22);
			this->settingSToolStripMenuItem->Text = L"Setting(&S)";
			this->settingSToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::settingSToolStripMenuItem_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSize = true;
			this->BackColor = System::Drawing::Color::Gainsboro;
			this->ClientSize = System::Drawing::Size(1006, 770);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->pict_graph);
			this->Controls->Add(this->btn_set);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->btn_stop);
			this->Controls->Add(this->btn_step);
			this->Controls->Add(this->btn_auto);
			this->Controls->Add(this->menuStrip1);
			this->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
			this->MainMenuStrip = this->menuStrip1;
			this->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->Name = L"Form1";
			this->Opacity = 1.0;
			this->Text = L"Simulator";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pict_graph))->EndInit();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {

	}
private: void UpdateDistributedSystem( void ){

	}
private: void panel1_MouseMove( Object^ /*sender*/, System::Windows::Forms::MouseEventArgs^ e ){
		this->label1->Text=String::Format("({0},{1})", e->X, e->Y);
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
		System::Diagnostics::Debug::WriteLine(fs->GetValue());
	}
};
}

