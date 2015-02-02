#pragma once
#include "Node.h"
#include "StdAfx.h"
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
	private: Settings* settings;
	public:
		FormSetting(void)
		{
			InitializeComponent();
			this->settings = new Settings;
			this->settings->unitdisk_r = UDK_R;
			this->settings->AA = false;
		}
		Settings* GetSetting()
		{
			return this->settings;
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
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown_UnitDisk_radius))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown_channels))->BeginInit();
			this->SuspendLayout();
			// 
			// btn_ok
			// 
			this->btn_ok->Location = System::Drawing::Point(536, 468);
			this->btn_ok->Name = L"btn_ok";
			this->btn_ok->Size = System::Drawing::Size(92, 34);
			this->btn_ok->TabIndex = 0;
			this->btn_ok->Text = L"OK";
			this->btn_ok->UseVisualStyleBackColor = true;
			this->btn_ok->Click += gcnew System::EventHandler(this, &FormSetting::btn_ok_Click);
			// 
			// btn_cancel
			// 
			this->btn_cancel->Location = System::Drawing::Point(639, 468);
			this->btn_cancel->Name = L"btn_cancel";
			this->btn_cancel->Size = System::Drawing::Size(92, 34);
			this->btn_cancel->TabIndex = 1;
			this->btn_cancel->Text = L"Cancel";
			this->btn_cancel->UseVisualStyleBackColor = true;
			this->btn_cancel->Click += gcnew System::EventHandler(this, &FormSetting::btn_cancel_Click);
			// 
			// checkBox_AA
			// 
			this->checkBox_AA->AutoSize = true;
			this->checkBox_AA->Location = System::Drawing::Point(92, 29);
			this->checkBox_AA->Name = L"checkBox_AA";
			this->checkBox_AA->Size = System::Drawing::Size(116, 19);
			this->checkBox_AA->TabIndex = 2;
			this->checkBox_AA->Text = L"AntiAlias(On/Off)";
			this->checkBox_AA->UseVisualStyleBackColor = true;
			this->checkBox_AA->CheckedChanged += gcnew System::EventHandler(this, &FormSetting::checkBox_AA_CheckedChanged);
			// 
			// numericUpDown_UnitDisk_radius
			// 
			this->numericUpDown_UnitDisk_radius->Location = System::Drawing::Point(58, 72);
			this->numericUpDown_UnitDisk_radius->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {256, 0, 0, 0});
			this->numericUpDown_UnitDisk_radius->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
			this->numericUpDown_UnitDisk_radius->Name = L"numericUpDown_UnitDisk_radius";
			this->numericUpDown_UnitDisk_radius->Size = System::Drawing::Size(47, 21);
			this->numericUpDown_UnitDisk_radius->TabIndex = 3;
			this->numericUpDown_UnitDisk_radius->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {50, 0, 0, 0});
			this->numericUpDown_UnitDisk_radius->ValueChanged += gcnew System::EventHandler(this, &FormSetting::numericUpDown_UnitDisk_radius_ValueChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(111, 72);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(84, 15);
			this->label1->TabIndex = 4;
			this->label1->Text = L"UnitDisk radius";
			// 
			// listBox_topology
			// 
			this->listBox_topology->FormattingEnabled = true;
			this->listBox_topology->ItemHeight = 15;
			this->listBox_topology->Items->AddRange(gcnew cli::array< System::Object^  >(2) {L"Random", L"UnitDisk"});
			this->listBox_topology->Location = System::Drawing::Point(34, 117);
			this->listBox_topology->Name = L"listBox_topology";
			this->listBox_topology->Size = System::Drawing::Size(71, 34);
			this->listBox_topology->TabIndex = 5;
			this->listBox_topology->SelectedIndexChanged += gcnew System::EventHandler(this, &FormSetting::listBox_topology_SelectedIndexChanged);
			// 
			// label_topology
			// 
			this->label_topology->AutoSize = true;
			this->label_topology->Location = System::Drawing::Point(111, 126);
			this->label_topology->Name = L"label_topology";
			this->label_topology->Size = System::Drawing::Size(88, 15);
			this->label_topology->TabIndex = 6;
			this->label_topology->Text = L"Graph Topology";
			// 
			// label_channels
			// 
			this->label_channels->AutoSize = true;
			this->label_channels->Location = System::Drawing::Point(111, 175);
			this->label_channels->Name = L"label_channels";
			this->label_channels->Size = System::Drawing::Size(51, 15);
			this->label_channels->TabIndex = 7;
			this->label_channels->Text = L"Channels";
			// 
			// numericUpDown_channels
			// 
			this->numericUpDown_channels->Location = System::Drawing::Point(58, 173);
			this->numericUpDown_channels->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {128, 0, 0, 0});
			this->numericUpDown_channels->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
			this->numericUpDown_channels->Name = L"numericUpDown_channels";
			this->numericUpDown_channels->Size = System::Drawing::Size(43, 21);
			this->numericUpDown_channels->TabIndex = 8;
			this->numericUpDown_channels->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
			this->numericUpDown_channels->ValueChanged += gcnew System::EventHandler(this, &FormSetting::numericUpDown_channels_ValueChanged);
			// 
			// FormSetting
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(743, 514);
			this->Controls->Add(this->numericUpDown_channels);
			this->Controls->Add(this->label_channels);
			this->Controls->Add(this->label_topology);
			this->Controls->Add(this->listBox_topology);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->numericUpDown_UnitDisk_radius);
			this->Controls->Add(this->checkBox_AA);
			this->Controls->Add(this->btn_cancel);
			this->Controls->Add(this->btn_ok);
			this->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
			this->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->Name = L"FormSetting";
			this->Opacity = 0.95;
			this->Text = L"Setting";
			this->Load += gcnew System::EventHandler(this, &FormSetting::FormSetting_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown_UnitDisk_radius))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown_channels))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: System::Void FormSetting_Load(System::Object^  sender, System::EventArgs^  e) {
	}
private: System::Void btn_cancel_Click(System::Object^  sender, System::EventArgs^  e) {
		this->Close();
	}
private: System::Void btn_ok_Click(System::Object^  sender, System::EventArgs^  e) {
		this->Close();
	}
private: System::Void checkBox_AA_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
		if( this->checkBox_AA->Checked ){
		this->settings->AA = true;
		}else{
		this->settings->AA = false; 
		}
	}
private: System::Void numericUpDown_UnitDisk_radius_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
		this->settings->unitdisk_r = (int)this->numericUpDown_UnitDisk_radius->Value;
	}
private: System::Void numericUpDown_channels_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
		this->settings->F = (int)this->numericUpDown_channels->Value;
	}
private: System::Void listBox_topology_SelectedIndexChanged(System::Object^  /*sender*/, System::EventArgs^  /*e*/) {
		String^ selectedStr = this->listBox_topology->SelectedItem->ToString();
		Debug::WriteLine(selectedStr);
		if(selectedStr == "Random"){
			this->settings->topology = 0;
		}else if(selectedStr == "UnitDisk"){
			this->settings->topology = 1;
		}
	}
};
}
