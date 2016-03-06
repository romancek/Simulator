#pragma once
#include "stdafx.h"
namespace BeepingModel {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Diagnostics;
	/// <summary>
	/// FormSetting の概要
	/// </summary>
	public ref class FormSetting : public System::Windows::Forms::Form
	{
	private: Node^ node;
	private: System::Windows::Forms::NumericUpDown^  numericUpDown_UnitDisk_radius;

	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::ListBox^  listBox_topology;

	private: System::Windows::Forms::Label^  label_topology;
	private: System::Windows::Forms::Label^  label_channels;
	private: System::Windows::Forms::NumericUpDown^  numericUpDown_channels;
	private: System::Windows::Forms::CheckBox^  checkBox_drawing;
	private: System::Windows::Forms::GroupBox^  groupBox_Drawing;
	private: System::Windows::Forms::GroupBox^  groupBox_Parameter;
	private: System::Windows::Forms::GroupBox^  groupBox_LineSize;

	private: System::Windows::Forms::NumericUpDown^  numericUpDown_PEN_WIDTH;


	private: System::Windows::Forms::Label^  label_PEN_WIDTH;
	private: System::Windows::Forms::NumericUpDown^  numericUpDown_NODE_SIZE;
	private: System::Windows::Forms::Label^  label_NODE_SIZE;
	private: Settings* settings;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::CheckBox^  checkBox_isSameTopology;
	private: System::Windows::Forms::GroupBox^  groupBox2;
	private: System::Windows::Forms::NumericUpDown^  numericUpDown_Execution_Condition_End;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::NumericUpDown^  numericUpDown_Execution_Condition_Interval;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::NumericUpDown^  numericUpDown_Execution_Condition_Start;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::NumericUpDown^  numericUpDown_Execution_times;
	private: System::Windows::Forms::GroupBox^  groupBox_FieldSize;



	private: System::Windows::Forms::Label^  label_FieldY;
	private: System::Windows::Forms::NumericUpDown^  numericUpDown_FieldX;



	private: System::Windows::Forms::Label^  label_FieldX;
	private: System::Windows::Forms::NumericUpDown^  numericUpDown_FieldY;
	private: System::Windows::Forms::CheckBox^  checkBox_Connected;
	private: System::Windows::Forms::GroupBox^  groupBox_CheckConnected;
	private: System::Windows::Forms::Label^  label_ConnectedCheckNum;
	private: System::Windows::Forms::NumericUpDown^  numericUpDown_ConnectedCheckNum;
	private: System::Windows::Forms::GroupBox^  groupBox3;
	private: System::Windows::Forms::ListBox^  listBox_Algorithm;
	private: System::Windows::Forms::CheckBox^  checkBox_SimulationMode;


	private: bool cancel;
	public:
		FormSetting(Settings* settings)
		{
			InitializeComponent();
			this->settings = settings;
			ReflectDisplay();
			this->cancel = false;
		}
		Settings* GetSetting()
		{
			return this->settings;
		}
		bool Cancel(){
			return this->cancel;
		}
	protected:
		/// <summary>
		/// 使用中のリソースをすべてクリーンアップします。
		/// </summary>
		~FormSetting()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  btn_ok;
	private: System::Windows::Forms::Button^  btn_cancel;
	private: System::Windows::Forms::CheckBox^  checkBox_AA;
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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(FormSetting::typeid));
			this->btn_ok = (gcnew System::Windows::Forms::Button());
			this->btn_cancel = (gcnew System::Windows::Forms::Button());
			this->checkBox_AA = (gcnew System::Windows::Forms::CheckBox());
			this->numericUpDown_UnitDisk_radius = (gcnew System::Windows::Forms::NumericUpDown());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->listBox_topology = (gcnew System::Windows::Forms::ListBox());
			this->label_topology = (gcnew System::Windows::Forms::Label());
			this->label_channels = (gcnew System::Windows::Forms::Label());
			this->numericUpDown_channels = (gcnew System::Windows::Forms::NumericUpDown());
			this->checkBox_drawing = (gcnew System::Windows::Forms::CheckBox());
			this->groupBox_Drawing = (gcnew System::Windows::Forms::GroupBox());
			this->groupBox_FieldSize = (gcnew System::Windows::Forms::GroupBox());
			this->numericUpDown_FieldY = (gcnew System::Windows::Forms::NumericUpDown());
			this->label_FieldY = (gcnew System::Windows::Forms::Label());
			this->numericUpDown_FieldX = (gcnew System::Windows::Forms::NumericUpDown());
			this->label_FieldX = (gcnew System::Windows::Forms::Label());
			this->groupBox_LineSize = (gcnew System::Windows::Forms::GroupBox());
			this->numericUpDown_PEN_WIDTH = (gcnew System::Windows::Forms::NumericUpDown());
			this->label_PEN_WIDTH = (gcnew System::Windows::Forms::Label());
			this->numericUpDown_NODE_SIZE = (gcnew System::Windows::Forms::NumericUpDown());
			this->label_NODE_SIZE = (gcnew System::Windows::Forms::Label());
			this->groupBox_Parameter = (gcnew System::Windows::Forms::GroupBox());
			this->groupBox_CheckConnected = (gcnew System::Windows::Forms::GroupBox());
			this->label_ConnectedCheckNum = (gcnew System::Windows::Forms::Label());
			this->numericUpDown_ConnectedCheckNum = (gcnew System::Windows::Forms::NumericUpDown());
			this->checkBox_Connected = (gcnew System::Windows::Forms::CheckBox());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->checkBox_isSameTopology = (gcnew System::Windows::Forms::CheckBox());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->numericUpDown_Execution_Condition_End = (gcnew System::Windows::Forms::NumericUpDown());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->numericUpDown_Execution_Condition_Interval = (gcnew System::Windows::Forms::NumericUpDown());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->numericUpDown_Execution_Condition_Start = (gcnew System::Windows::Forms::NumericUpDown());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->numericUpDown_Execution_times = (gcnew System::Windows::Forms::NumericUpDown());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->listBox_Algorithm = (gcnew System::Windows::Forms::ListBox());
			this->checkBox_SimulationMode = (gcnew System::Windows::Forms::CheckBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown_UnitDisk_radius))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown_channels))->BeginInit();
			this->groupBox_Drawing->SuspendLayout();
			this->groupBox_FieldSize->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown_FieldY))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown_FieldX))->BeginInit();
			this->groupBox_LineSize->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown_PEN_WIDTH))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown_NODE_SIZE))->BeginInit();
			this->groupBox_Parameter->SuspendLayout();
			this->groupBox_CheckConnected->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown_ConnectedCheckNum))->BeginInit();
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown_Execution_Condition_End))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown_Execution_Condition_Interval))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown_Execution_Condition_Start))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown_Execution_times))->BeginInit();
			this->groupBox3->SuspendLayout();
			this->SuspendLayout();
			// 
			// btn_ok
			// 
			this->btn_ok->BackColor = System::Drawing::Color::White;
			this->btn_ok->FlatAppearance->BorderColor = System::Drawing::Color::DimGray;
			this->btn_ok->FlatAppearance->BorderSize = 2;
			this->btn_ok->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btn_ok->Font = (gcnew System::Drawing::Font(L"Verdana", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_ok->ForeColor = System::Drawing::Color::DarkCyan;
			this->btn_ok->Location = System::Drawing::Point(536, 468);
			this->btn_ok->Name = L"btn_ok";
			this->btn_ok->Size = System::Drawing::Size(92, 34);
			this->btn_ok->TabIndex = 0;
			this->btn_ok->Text = L"OK";
			this->btn_ok->UseVisualStyleBackColor = false;
			this->btn_ok->Click += gcnew System::EventHandler(this, &FormSetting::btn_ok_Click);
			// 
			// btn_cancel
			// 
			this->btn_cancel->BackColor = System::Drawing::Color::White;
			this->btn_cancel->FlatAppearance->BorderColor = System::Drawing::Color::DimGray;
			this->btn_cancel->FlatAppearance->BorderSize = 2;
			this->btn_cancel->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btn_cancel->Font = (gcnew System::Drawing::Font(L"Verdana", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_cancel->ForeColor = System::Drawing::Color::IndianRed;
			this->btn_cancel->Location = System::Drawing::Point(639, 468);
			this->btn_cancel->Name = L"btn_cancel";
			this->btn_cancel->Size = System::Drawing::Size(92, 34);
			this->btn_cancel->TabIndex = 1;
			this->btn_cancel->Text = L"Cancel";
			this->btn_cancel->UseVisualStyleBackColor = false;
			this->btn_cancel->Click += gcnew System::EventHandler(this, &FormSetting::btn_cancel_Click);
			// 
			// checkBox_AA
			// 
			this->checkBox_AA->AutoSize = true;
			this->checkBox_AA->Location = System::Drawing::Point(37, 24);
			this->checkBox_AA->Name = L"checkBox_AA";
			this->checkBox_AA->Size = System::Drawing::Size(130, 18);
			this->checkBox_AA->TabIndex = 2;
			this->checkBox_AA->Text = L"AntiAlias(On/Off)";
			this->checkBox_AA->UseVisualStyleBackColor = true;
			this->checkBox_AA->CheckedChanged += gcnew System::EventHandler(this, &FormSetting::checkBox_AA_CheckedChanged);
			// 
			// numericUpDown_UnitDisk_radius
			// 
			this->numericUpDown_UnitDisk_radius->Location = System::Drawing::Point(30, 22);
			this->numericUpDown_UnitDisk_radius->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 256, 0, 0, 0 });
			this->numericUpDown_UnitDisk_radius->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->numericUpDown_UnitDisk_radius->Name = L"numericUpDown_UnitDisk_radius";
			this->numericUpDown_UnitDisk_radius->Size = System::Drawing::Size(47, 22);
			this->numericUpDown_UnitDisk_radius->TabIndex = 3;
			this->numericUpDown_UnitDisk_radius->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 50, 0, 0, 0 });
			this->numericUpDown_UnitDisk_radius->ValueChanged += gcnew System::EventHandler(this, &FormSetting::numericUpDown_UnitDisk_radius_ValueChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(83, 26);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(101, 14);
			this->label1->TabIndex = 4;
			this->label1->Text = L"UnitDisk radius";
			// 
			// listBox_topology
			// 
			this->listBox_topology->FormattingEnabled = true;
			this->listBox_topology->ItemHeight = 14;
			this->listBox_topology->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Random", L"UnitDisk" });
			this->listBox_topology->Location = System::Drawing::Point(6, 58);
			this->listBox_topology->Name = L"listBox_topology";
			this->listBox_topology->Size = System::Drawing::Size(71, 32);
			this->listBox_topology->TabIndex = 5;
			this->listBox_topology->SelectedIndexChanged += gcnew System::EventHandler(this, &FormSetting::listBox_topology_SelectedIndexChanged);
			// 
			// label_topology
			// 
			this->label_topology->AutoSize = true;
			this->label_topology->Location = System::Drawing::Point(83, 67);
			this->label_topology->Name = L"label_topology";
			this->label_topology->Size = System::Drawing::Size(106, 14);
			this->label_topology->TabIndex = 6;
			this->label_topology->Text = L"Graph Topology";
			// 
			// label_channels
			// 
			this->label_channels->AutoSize = true;
			this->label_channels->Location = System::Drawing::Point(83, 112);
			this->label_channels->Name = L"label_channels";
			this->label_channels->Size = System::Drawing::Size(66, 14);
			this->label_channels->TabIndex = 7;
			this->label_channels->Text = L"Channels";
			// 
			// numericUpDown_channels
			// 
			this->numericUpDown_channels->Location = System::Drawing::Point(20, 111);
			this->numericUpDown_channels->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1024, 0, 0, 0 });
			this->numericUpDown_channels->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->numericUpDown_channels->Name = L"numericUpDown_channels";
			this->numericUpDown_channels->Size = System::Drawing::Size(53, 22);
			this->numericUpDown_channels->TabIndex = 8;
			this->numericUpDown_channels->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->numericUpDown_channels->ValueChanged += gcnew System::EventHandler(this, &FormSetting::numericUpDown_channels_ValueChanged);
			// 
			// checkBox_drawing
			// 
			this->checkBox_drawing->AutoSize = true;
			this->checkBox_drawing->Location = System::Drawing::Point(37, 58);
			this->checkBox_drawing->Name = L"checkBox_drawing";
			this->checkBox_drawing->Size = System::Drawing::Size(129, 18);
			this->checkBox_drawing->TabIndex = 9;
			this->checkBox_drawing->Text = L"Drawing(On/Off)";
			this->checkBox_drawing->UseVisualStyleBackColor = true;
			this->checkBox_drawing->CheckedChanged += gcnew System::EventHandler(this, &FormSetting::checkBox_drawing_CheckedChanged);
			// 
			// groupBox_Drawing
			// 
			this->groupBox_Drawing->Controls->Add(this->groupBox_FieldSize);
			this->groupBox_Drawing->Controls->Add(this->groupBox_LineSize);
			this->groupBox_Drawing->Controls->Add(this->checkBox_drawing);
			this->groupBox_Drawing->Controls->Add(this->checkBox_AA);
			this->groupBox_Drawing->Font = (gcnew System::Drawing::Font(L"Verdana", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->groupBox_Drawing->Location = System::Drawing::Point(27, 12);
			this->groupBox_Drawing->Name = L"groupBox_Drawing";
			this->groupBox_Drawing->Size = System::Drawing::Size(681, 93);
			this->groupBox_Drawing->TabIndex = 10;
			this->groupBox_Drawing->TabStop = false;
			this->groupBox_Drawing->Text = L"Rendering";
			// 
			// groupBox_FieldSize
			// 
			this->groupBox_FieldSize->Controls->Add(this->numericUpDown_FieldY);
			this->groupBox_FieldSize->Controls->Add(this->label_FieldY);
			this->groupBox_FieldSize->Controls->Add(this->numericUpDown_FieldX);
			this->groupBox_FieldSize->Controls->Add(this->label_FieldX);
			this->groupBox_FieldSize->Location = System::Drawing::Point(455, 13);
			this->groupBox_FieldSize->Name = L"groupBox_FieldSize";
			this->groupBox_FieldSize->Size = System::Drawing::Size(224, 69);
			this->groupBox_FieldSize->TabIndex = 15;
			this->groupBox_FieldSize->TabStop = false;
			this->groupBox_FieldSize->Text = L"Field Size";
			// 
			// numericUpDown_FieldY
			// 
			this->numericUpDown_FieldY->Location = System::Drawing::Point(115, 26);
			this->numericUpDown_FieldY->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->numericUpDown_FieldY->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->numericUpDown_FieldY->Name = L"numericUpDown_FieldY";
			this->numericUpDown_FieldY->Size = System::Drawing::Size(60, 22);
			this->numericUpDown_FieldY->TabIndex = 13;
			this->numericUpDown_FieldY->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1000, 0, 0, 0 });
			this->numericUpDown_FieldY->ValueChanged += gcnew System::EventHandler(this, &FormSetting::numericUpDown_FieldY_ValueChanged);
			// 
			// label_FieldY
			// 
			this->label_FieldY->AutoSize = true;
			this->label_FieldY->Location = System::Drawing::Point(181, 28);
			this->label_FieldY->Name = L"label_FieldY";
			this->label_FieldY->Size = System::Drawing::Size(14, 14);
			this->label_FieldY->TabIndex = 12;
			this->label_FieldY->Text = L"y";
			// 
			// numericUpDown_FieldX
			// 
			this->numericUpDown_FieldX->Location = System::Drawing::Point(11, 26);
			this->numericUpDown_FieldX->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->numericUpDown_FieldX->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->numericUpDown_FieldX->Name = L"numericUpDown_FieldX";
			this->numericUpDown_FieldX->Size = System::Drawing::Size(60, 22);
			this->numericUpDown_FieldX->TabIndex = 11;
			this->numericUpDown_FieldX->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1000, 0, 0, 0 });
			this->numericUpDown_FieldX->ValueChanged += gcnew System::EventHandler(this, &FormSetting::numericUpDown_FieldX_ValueChanged);
			// 
			// label_FieldX
			// 
			this->label_FieldX->AutoSize = true;
			this->label_FieldX->Location = System::Drawing::Point(75, 28);
			this->label_FieldX->Name = L"label_FieldX";
			this->label_FieldX->Size = System::Drawing::Size(14, 14);
			this->label_FieldX->TabIndex = 10;
			this->label_FieldX->Text = L"x";
			// 
			// groupBox_LineSize
			// 
			this->groupBox_LineSize->Controls->Add(this->numericUpDown_PEN_WIDTH);
			this->groupBox_LineSize->Controls->Add(this->label_PEN_WIDTH);
			this->groupBox_LineSize->Controls->Add(this->numericUpDown_NODE_SIZE);
			this->groupBox_LineSize->Controls->Add(this->label_NODE_SIZE);
			this->groupBox_LineSize->Location = System::Drawing::Point(225, 13);
			this->groupBox_LineSize->Name = L"groupBox_LineSize";
			this->groupBox_LineSize->Size = System::Drawing::Size(224, 69);
			this->groupBox_LineSize->TabIndex = 14;
			this->groupBox_LineSize->TabStop = false;
			this->groupBox_LineSize->Text = L"Size";
			// 
			// numericUpDown_PEN_WIDTH
			// 
			this->numericUpDown_PEN_WIDTH->DecimalPlaces = 1;
			this->numericUpDown_PEN_WIDTH->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 65536 });
			this->numericUpDown_PEN_WIDTH->Location = System::Drawing::Point(117, 26);
			this->numericUpDown_PEN_WIDTH->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 5, 0, 0, 0 });
			this->numericUpDown_PEN_WIDTH->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 65536 });
			this->numericUpDown_PEN_WIDTH->Name = L"numericUpDown_PEN_WIDTH";
			this->numericUpDown_PEN_WIDTH->Size = System::Drawing::Size(46, 22);
			this->numericUpDown_PEN_WIDTH->TabIndex = 13;
			this->numericUpDown_PEN_WIDTH->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 65536 });
			this->numericUpDown_PEN_WIDTH->ValueChanged += gcnew System::EventHandler(this, &FormSetting::numericUpDown_PEN_WIDTH_ValueChanged);
			// 
			// label_PEN_WIDTH
			// 
			this->label_PEN_WIDTH->AutoSize = true;
			this->label_PEN_WIDTH->Location = System::Drawing::Point(170, 28);
			this->label_PEN_WIDTH->Name = L"label_PEN_WIDTH";
			this->label_PEN_WIDTH->Size = System::Drawing::Size(33, 14);
			this->label_PEN_WIDTH->TabIndex = 12;
			this->label_PEN_WIDTH->Text = L"Line";
			// 
			// numericUpDown_NODE_SIZE
			// 
			this->numericUpDown_NODE_SIZE->Location = System::Drawing::Point(11, 26);
			this->numericUpDown_NODE_SIZE->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 50, 0, 0, 0 });
			this->numericUpDown_NODE_SIZE->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->numericUpDown_NODE_SIZE->Name = L"numericUpDown_NODE_SIZE";
			this->numericUpDown_NODE_SIZE->Size = System::Drawing::Size(46, 22);
			this->numericUpDown_NODE_SIZE->TabIndex = 11;
			this->numericUpDown_NODE_SIZE->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->numericUpDown_NODE_SIZE->ValueChanged += gcnew System::EventHandler(this, &FormSetting::numericUpDown_NODE_SIZE_ValueChanged);
			// 
			// label_NODE_SIZE
			// 
			this->label_NODE_SIZE->AutoSize = true;
			this->label_NODE_SIZE->Location = System::Drawing::Point(64, 28);
			this->label_NODE_SIZE->Name = L"label_NODE_SIZE";
			this->label_NODE_SIZE->Size = System::Drawing::Size(40, 14);
			this->label_NODE_SIZE->TabIndex = 10;
			this->label_NODE_SIZE->Text = L"Node";
			// 
			// groupBox_Parameter
			// 
			this->groupBox_Parameter->BackColor = System::Drawing::Color::White;
			this->groupBox_Parameter->Controls->Add(this->groupBox_CheckConnected);
			this->groupBox_Parameter->Controls->Add(this->numericUpDown_channels);
			this->groupBox_Parameter->Controls->Add(this->label_channels);
			this->groupBox_Parameter->Controls->Add(this->label_topology);
			this->groupBox_Parameter->Controls->Add(this->listBox_topology);
			this->groupBox_Parameter->Controls->Add(this->label1);
			this->groupBox_Parameter->Controls->Add(this->numericUpDown_UnitDisk_radius);
			this->groupBox_Parameter->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->groupBox_Parameter->Font = (gcnew System::Drawing::Font(L"Verdana", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->groupBox_Parameter->Location = System::Drawing::Point(28, 111);
			this->groupBox_Parameter->Name = L"groupBox_Parameter";
			this->groupBox_Parameter->Size = System::Drawing::Size(496, 151);
			this->groupBox_Parameter->TabIndex = 11;
			this->groupBox_Parameter->TabStop = false;
			this->groupBox_Parameter->Text = L"Graph Property";
			// 
			// groupBox_CheckConnected
			// 
			this->groupBox_CheckConnected->Controls->Add(this->label_ConnectedCheckNum);
			this->groupBox_CheckConnected->Controls->Add(this->numericUpDown_ConnectedCheckNum);
			this->groupBox_CheckConnected->Controls->Add(this->checkBox_Connected);
			this->groupBox_CheckConnected->Location = System::Drawing::Point(215, 19);
			this->groupBox_CheckConnected->Name = L"groupBox_CheckConnected";
			this->groupBox_CheckConnected->Size = System::Drawing::Size(268, 62);
			this->groupBox_CheckConnected->TabIndex = 19;
			this->groupBox_CheckConnected->TabStop = false;
			this->groupBox_CheckConnected->Text = L"Connectedness Checking";
			// 
			// label_ConnectedCheckNum
			// 
			this->label_ConnectedCheckNum->AutoSize = true;
			this->label_ConnectedCheckNum->Location = System::Drawing::Point(184, 26);
			this->label_ConnectedCheckNum->Name = L"label_ConnectedCheckNum";
			this->label_ConnectedCheckNum->Size = System::Drawing::Size(58, 14);
			this->label_ConnectedCheckNum->TabIndex = 18;
			this->label_ConnectedCheckNum->Text = L"Try Num";
			// 
			// numericUpDown_ConnectedCheckNum
			// 
			this->numericUpDown_ConnectedCheckNum->Location = System::Drawing::Point(114, 23);
			this->numericUpDown_ConnectedCheckNum->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->numericUpDown_ConnectedCheckNum->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->numericUpDown_ConnectedCheckNum->Name = L"numericUpDown_ConnectedCheckNum";
			this->numericUpDown_ConnectedCheckNum->Size = System::Drawing::Size(64, 22);
			this->numericUpDown_ConnectedCheckNum->TabIndex = 17;
			this->numericUpDown_ConnectedCheckNum->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 100, 0, 0, 0 });
			this->numericUpDown_ConnectedCheckNum->ValueChanged += gcnew System::EventHandler(this, &FormSetting::numericUpDown_ConnectedCheckNum_ValueChanged);
			// 
			// checkBox_Connected
			// 
			this->checkBox_Connected->AutoSize = true;
			this->checkBox_Connected->Location = System::Drawing::Point(20, 25);
			this->checkBox_Connected->Name = L"checkBox_Connected";
			this->checkBox_Connected->Size = System::Drawing::Size(75, 18);
			this->checkBox_Connected->TabIndex = 16;
			this->checkBox_Connected->Text = L"Check \?";
			this->checkBox_Connected->UseVisualStyleBackColor = true;
			this->checkBox_Connected->CheckedChanged += gcnew System::EventHandler(this, &FormSetting::checkBox_Connected_CheckedChanged);
			// 
			// groupBox1
			// 
			this->groupBox1->BackColor = System::Drawing::Color::White;
			this->groupBox1->Controls->Add(this->checkBox_isSameTopology);
			this->groupBox1->Controls->Add(this->groupBox2);
			this->groupBox1->Controls->Add(this->label4);
			this->groupBox1->Controls->Add(this->numericUpDown_Execution_times);
			this->groupBox1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->groupBox1->Font = (gcnew System::Drawing::Font(L"Verdana", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->groupBox1->Location = System::Drawing::Point(29, 307);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(679, 114);
			this->groupBox1->TabIndex = 12;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Simulation Property";
			// 
			// checkBox_isSameTopology
			// 
			this->checkBox_isSameTopology->AutoSize = true;
			this->checkBox_isSameTopology->Location = System::Drawing::Point(65, 76);
			this->checkBox_isSameTopology->Name = L"checkBox_isSameTopology";
			this->checkBox_isSameTopology->Size = System::Drawing::Size(129, 18);
			this->checkBox_isSameTopology->TabIndex = 15;
			this->checkBox_isSameTopology->Text = L"SameTopology \?";
			this->checkBox_isSameTopology->UseVisualStyleBackColor = true;
			this->checkBox_isSameTopology->CheckedChanged += gcnew System::EventHandler(this, &FormSetting::checkBox_isSameTopology_CheckedChanged);
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->numericUpDown_Execution_Condition_End);
			this->groupBox2->Controls->Add(this->label5);
			this->groupBox2->Controls->Add(this->numericUpDown_Execution_Condition_Interval);
			this->groupBox2->Controls->Add(this->label3);
			this->groupBox2->Controls->Add(this->numericUpDown_Execution_Condition_Start);
			this->groupBox2->Controls->Add(this->label2);
			this->groupBox2->Location = System::Drawing::Point(262, 21);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(411, 73);
			this->groupBox2->TabIndex = 13;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Condition(n)";
			// 
			// numericUpDown_Execution_Condition_End
			// 
			this->numericUpDown_Execution_Condition_End->Location = System::Drawing::Point(135, 32);
			this->numericUpDown_Execution_Condition_End->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {
				1000000, 0,
					0, 0
			});
			this->numericUpDown_Execution_Condition_End->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->numericUpDown_Execution_Condition_End->Name = L"numericUpDown_Execution_Condition_End";
			this->numericUpDown_Execution_Condition_End->Size = System::Drawing::Size(86, 22);
			this->numericUpDown_Execution_Condition_End->TabIndex = 12;
			this->numericUpDown_Execution_Condition_End->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->numericUpDown_Execution_Condition_End->ValueChanged += gcnew System::EventHandler(this, &FormSetting::numericUpDown_Execution_Condition_End_ValueChanged);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(226, 36);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(31, 14);
			this->label5->TabIndex = 11;
			this->label5->Text = L"End";
			// 
			// numericUpDown_Execution_Condition_Interval
			// 
			this->numericUpDown_Execution_Condition_Interval->Location = System::Drawing::Point(262, 32);
			this->numericUpDown_Execution_Condition_Interval->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {
				100000,
					0, 0, 0
			});
			this->numericUpDown_Execution_Condition_Interval->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {
				1, 0, 0,
					0
			});
			this->numericUpDown_Execution_Condition_Interval->Name = L"numericUpDown_Execution_Condition_Interval";
			this->numericUpDown_Execution_Condition_Interval->Size = System::Drawing::Size(76, 22);
			this->numericUpDown_Execution_Condition_Interval->TabIndex = 10;
			this->numericUpDown_Execution_Condition_Interval->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {
				1000, 0,
					0, 0
			});
			this->numericUpDown_Execution_Condition_Interval->ValueChanged += gcnew System::EventHandler(this, &FormSetting::numericUpDown_Execution_Condition_Interval_ValueChanged);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(343, 36);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(56, 14);
			this->label3->TabIndex = 9;
			this->label3->Text = L"Interval";
			// 
			// numericUpDown_Execution_Condition_Start
			// 
			this->numericUpDown_Execution_Condition_Start->Location = System::Drawing::Point(6, 32);
			this->numericUpDown_Execution_Condition_Start->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {
				100000, 0,
					0, 0
			});
			this->numericUpDown_Execution_Condition_Start->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->numericUpDown_Execution_Condition_Start->Name = L"numericUpDown_Execution_Condition_Start";
			this->numericUpDown_Execution_Condition_Start->Size = System::Drawing::Size(81, 22);
			this->numericUpDown_Execution_Condition_Start->TabIndex = 8;
			this->numericUpDown_Execution_Condition_Start->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 100, 0, 0, 0 });
			this->numericUpDown_Execution_Condition_Start->ValueChanged += gcnew System::EventHandler(this, &FormSetting::numericUpDown_Execution_Condition_Start_ValueChanged);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(92, 34);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(38, 14);
			this->label2->TabIndex = 7;
			this->label2->Text = L"Start";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(82, 32);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(108, 14);
			this->label4->TabIndex = 4;
			this->label4->Text = L"Execution Times";
			// 
			// numericUpDown_Execution_times
			// 
			this->numericUpDown_Execution_times->Location = System::Drawing::Point(29, 28);
			this->numericUpDown_Execution_times->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 256, 0, 0, 0 });
			this->numericUpDown_Execution_times->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->numericUpDown_Execution_times->Name = L"numericUpDown_Execution_times";
			this->numericUpDown_Execution_times->Size = System::Drawing::Size(47, 22);
			this->numericUpDown_Execution_times->TabIndex = 3;
			this->numericUpDown_Execution_times->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 100, 0, 0, 0 });
			this->numericUpDown_Execution_times->ValueChanged += gcnew System::EventHandler(this, &FormSetting::numericUpDown_Execution_times_ValueChanged);
			// 
			// groupBox3
			// 
			this->groupBox3->BackColor = System::Drawing::Color::White;
			this->groupBox3->Controls->Add(this->listBox_Algorithm);
			this->groupBox3->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->groupBox3->Font = (gcnew System::Drawing::Font(L"Verdana", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->groupBox3->Location = System::Drawing::Point(530, 111);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(178, 151);
			this->groupBox3->TabIndex = 16;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"Algorithm";
			// 
			// listBox_Algorithm
			// 
			this->listBox_Algorithm->FormattingEnabled = true;
			this->listBox_Algorithm->ItemHeight = 14;
			this->listBox_Algorithm->Items->AddRange(gcnew cli::array< System::Object^  >(3) {
				L"Maximal Independent Set", L"Maximal Matching",
					L"Leader Election"
			});
			this->listBox_Algorithm->Location = System::Drawing::Point(4, 26);
			this->listBox_Algorithm->Name = L"listBox_Algorithm";
			this->listBox_Algorithm->Size = System::Drawing::Size(170, 74);
			this->listBox_Algorithm->TabIndex = 6;
			this->listBox_Algorithm->SelectedIndexChanged += gcnew System::EventHandler(this, &FormSetting::listBox_Algorithm_SelectedIndexChanged);
			// 
			// checkBox_SimulationMode
			// 
			this->checkBox_SimulationMode->AutoSize = true;
			this->checkBox_SimulationMode->Font = (gcnew System::Drawing::Font(L"Verdana", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->checkBox_SimulationMode->Location = System::Drawing::Point(28, 276);
			this->checkBox_SimulationMode->Name = L"checkBox_SimulationMode";
			this->checkBox_SimulationMode->Size = System::Drawing::Size(180, 18);
			this->checkBox_SimulationMode->TabIndex = 16;
			this->checkBox_SimulationMode->Text = L"Simulation Mode(On/Off)";
			this->checkBox_SimulationMode->UseVisualStyleBackColor = true;
			this->checkBox_SimulationMode->CheckedChanged += gcnew System::EventHandler(this, &FormSetting::checkBox_SimulationMode_CheckedChanged);
			// 
			// FormSetting
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->ClientSize = System::Drawing::Size(743, 514);
			this->Controls->Add(this->checkBox_SimulationMode);
			this->Controls->Add(this->groupBox3);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->groupBox_Parameter);
			this->Controls->Add(this->groupBox_Drawing);
			this->Controls->Add(this->btn_cancel);
			this->Controls->Add(this->btn_ok);
			this->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::SizableToolWindow;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->Name = L"FormSetting";
			this->Opacity = 0.9;
			this->Text = L"Setting";
			this->Load += gcnew System::EventHandler(this, &FormSetting::FormSetting_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown_UnitDisk_radius))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown_channels))->EndInit();
			this->groupBox_Drawing->ResumeLayout(false);
			this->groupBox_Drawing->PerformLayout();
			this->groupBox_FieldSize->ResumeLayout(false);
			this->groupBox_FieldSize->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown_FieldY))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown_FieldX))->EndInit();
			this->groupBox_LineSize->ResumeLayout(false);
			this->groupBox_LineSize->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown_PEN_WIDTH))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown_NODE_SIZE))->EndInit();
			this->groupBox_Parameter->ResumeLayout(false);
			this->groupBox_Parameter->PerformLayout();
			this->groupBox_CheckConnected->ResumeLayout(false);
			this->groupBox_CheckConnected->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown_ConnectedCheckNum))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown_Execution_Condition_End))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown_Execution_Condition_Interval))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown_Execution_Condition_Start))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown_Execution_times))->EndInit();
			this->groupBox3->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: System::Void FormSetting_Load(System::Object^  sender, System::EventArgs^  e) {
	}
private: void ReflectDisplay ( ) {
		this->numericUpDown_UnitDisk_radius->Value = this->settings->unitdisk_r;
		this->numericUpDown_channels->Value = this->settings->F;
		this->numericUpDown_NODE_SIZE->Value = this->settings->NODE_SIZE;
		this->numericUpDown_PEN_WIDTH->Value = (Decimal)this->settings->PEN_WIDTH;
		this->numericUpDown_FieldX->Value = this->settings->Field_Size[0];
		this->numericUpDown_FieldY->Value = this->settings->Field_Size[1];
		this->numericUpDown_Execution_times->Value = this->settings->execution_times;
		this->numericUpDown_Execution_Condition_Start->Value = this->settings->execution_condition[0];
		this->numericUpDown_Execution_Condition_End->Value = this->settings->execution_condition[1];
		this->numericUpDown_Execution_Condition_Interval->Value = this->settings->execution_condition[2];

		this->checkBox_AA->Checked = this->settings->AA;
		this->checkBox_drawing->Checked = this->settings->Drawing;
		this->checkBox_isSameTopology->Checked = this->settings->isSameTopology;
		this->checkBox_Connected->Checked = this->settings->Req_Connectivity;
		this->numericUpDown_ConnectedCheckNum->Value = this->settings->Check_num;
		this->checkBox_SimulationMode->Checked = this->settings->simulation_mode;
		this->groupBox1->Enabled = this->settings->simulation_mode;

		switch ( this->settings->topology )
		{
		case 0:
			this->listBox_topology->SelectedItem = L"Random";
			break;
		case 1:
			this->listBox_topology->SelectedItem = L"UnitDisk";
			break;
		default:
			break;
		}

		switch (this->settings->algorithm_type)
		{
		case 0:
			this->listBox_Algorithm->SelectedItem = L"Maximal Independent Set";
			break;
		case 1:
			this->listBox_Algorithm->SelectedItem = L"Maximal Matching";
			break;
		case 2:
			this->listBox_Algorithm->SelectedItem = L"Leader Election";
			break;
		default:
			break;
		}
	}
private: System::Void btn_cancel_Click(System::Object^  sender, System::EventArgs^  e) {
		this->cancel = true;
		this->Close();
	}
private: System::Void btn_ok_Click(System::Object^  sender, System::EventArgs^  e) {
		this->cancel = false;
		this->Close();
	}
private: System::Void checkBox_AA_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
	this->settings->AA = this->checkBox_AA->Checked;
	}
private: System::Void checkBox_drawing_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
	this->settings->Drawing = this->checkBox_drawing->Checked;
	}
private: System::Void numericUpDown_UnitDisk_radius_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
		this->settings->unitdisk_r = (int)this->numericUpDown_UnitDisk_radius->Value;
	}
private: System::Void numericUpDown_channels_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
		this->settings->F = (int)this->numericUpDown_channels->Value;
	}
private: System::Void numericUpDown_PEN_WIDTH_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
		this->settings->PEN_WIDTH = (float)this->numericUpDown_PEN_WIDTH->Value;
	}
private: System::Void numericUpDown_NODE_SIZE_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
		this->settings->NODE_SIZE = (int)this->numericUpDown_NODE_SIZE->Value;
	}
private: System::Void listBox_topology_SelectedIndexChanged(System::Object^  /*sender*/, System::EventArgs^  /*e*/) {
		String^ selectedStr = this->listBox_topology->SelectedItem->ToString();
		Debug::WriteLine(selectedStr);
		if ( selectedStr == "Random" )
		{
			this->settings->topology = 0;
		}
		else if ( selectedStr == "UnitDisk" )
		{
			this->settings->topology = 1;
		}
	}
private: System::Void numericUpDown_Execution_times_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
	this->settings->execution_times = (unsigned int)this->numericUpDown_Execution_times->Value;
}
private: System::Void numericUpDown_Execution_Condition_Start_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
	this->settings->execution_condition[0] = (unsigned int)this->numericUpDown_Execution_Condition_Start->Value;
}
private: System::Void numericUpDown_Execution_Condition_End_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
	this->settings->execution_condition[1] = (unsigned int)this->numericUpDown_Execution_Condition_End->Value;
}
private: System::Void numericUpDown_Execution_Condition_Interval_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
	this->settings->execution_condition[2] = (unsigned int)this->numericUpDown_Execution_Condition_Interval->Value;
}
private: System::Void checkBox_isSameTopology_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
	this->settings->isSameTopology = this->checkBox_isSameTopology->Checked;
}
private: System::Void numericUpDown_FieldX_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
	this->settings->Field_Size[0] = (unsigned int)this->numericUpDown_FieldX->Value;
}
private: System::Void numericUpDown_FieldY_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
	this->settings->Field_Size[1] = (unsigned int)this->numericUpDown_FieldY->Value;
}
private: System::Void checkBox_Connected_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
	this->settings->Req_Connectivity = this->checkBox_Connected->Checked;
}
private: System::Void numericUpDown_ConnectedCheckNum_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
	this->settings->Check_num = (unsigned int)this->numericUpDown_ConnectedCheckNum->Value;
}
private: System::Void listBox_Algorithm_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
	String^ selectedStr = this->listBox_Algorithm->SelectedItem->ToString();
	Debug::WriteLine(selectedStr);
	if (selectedStr == "Maximal Independent Set")
	{
		this->settings->algorithm_type = 0;
	}
	else if (selectedStr == "Maximal Matching")
	{
		this->settings->algorithm_type = 1;
	}
	else if (selectedStr == "Leader Election")
	{
		this->settings->algorithm_type = 2;
	}
}
private: System::Void checkBox_SimulationMode_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
	this->groupBox1->Enabled = this->checkBox_SimulationMode->Checked;
	this->settings->simulation_mode = this->checkBox_SimulationMode->Checked;
}
};
}
