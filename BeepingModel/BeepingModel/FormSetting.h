#pragma once
#include "Node.h"

namespace BeepingModel {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// FormSetting の概要
	/// </summary>
	public ref class FormSetting : public System::Windows::Forms::Form
	{
	private: Node^ node;
	private: bool aa;
	public:
		FormSetting(void)
		{
			InitializeComponent();
			node = gcnew Node();
			this->aa = false;
		}
		//設定出力 TODO
		int GetValue()
		{
			return 1;
		}
		bool isCheckedAA()
		{
			return this->aa;
		}
		/*Node^ GetNodeInfo()
		{
			return node;
		}*/
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
			this->checkBox_AA->Location = System::Drawing::Point(24, 30);
			this->checkBox_AA->Name = L"checkBox_AA";
			this->checkBox_AA->Size = System::Drawing::Size(116, 19);
			this->checkBox_AA->TabIndex = 2;
			this->checkBox_AA->Text = L"AntiAlias(On/Off)";
			this->checkBox_AA->UseVisualStyleBackColor = true;
			this->checkBox_AA->CheckedChanged += gcnew System::EventHandler(this, &FormSetting::checkBox_AA_CheckedChanged);
			// 
			// FormSetting
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(743, 514);
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
				this->aa = true;
			 }else{
				this->aa = false; 
			 }
		 }
};
}
