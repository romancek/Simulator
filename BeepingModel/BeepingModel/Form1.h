#pragma once
#include <string>
#include <boost/version.hpp>

namespace BeepingModel {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Form1 �̊T�v
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: �����ɃR���X�g���N�^�[ �R�[�h��ǉ����܂�
			//
		}

	protected:
		/// <summary>
		/// �g�p���̃��\�[�X�����ׂăN���[���A�b�v���܂��B
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


	protected: 

	protected: 











	private:
		/// <summary>
		/// �K�v�ȃf�U�C�i�[�ϐ��ł��B
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// �f�U�C�i�[ �T�|�[�g�ɕK�v�ȃ��\�b�h�ł��B���̃��\�b�h�̓��e��
		/// �R�[�h �G�f�B�^�[�ŕύX���Ȃ��ł��������B
		/// </summary>
		void InitializeComponent(void)
		{
			this->btn_auto = (gcnew System::Windows::Forms::Button());
			this->btn_step = (gcnew System::Windows::Forms::Button());
			this->btn_stop = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->btn_set = (gcnew System::Windows::Forms::Button());
			this->pict_graph = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pict_graph))->BeginInit();
			this->SuspendLayout();
			// 
			// btn_auto
			// 
			this->btn_auto->Location = System::Drawing::Point(687, 80);
			this->btn_auto->Name = L"btn_auto";
			this->btn_auto->Size = System::Drawing::Size(60, 23);
			this->btn_auto->TabIndex = 0;
			this->btn_auto->Text = L"Auto";
			this->btn_auto->UseVisualStyleBackColor = true;
			// 
			// btn_step
			// 
			this->btn_step->Location = System::Drawing::Point(687, 35);
			this->btn_step->Name = L"btn_step";
			this->btn_step->Size = System::Drawing::Size(60, 23);
			this->btn_step->TabIndex = 1;
			this->btn_step->Text = L"Step";
			this->btn_step->UseVisualStyleBackColor = true;
			// 
			// btn_stop
			// 
			this->btn_stop->Location = System::Drawing::Point(687, 125);
			this->btn_stop->Name = L"btn_stop";
			this->btn_stop->Size = System::Drawing::Size(60, 23);
			this->btn_stop->TabIndex = 2;
			this->btn_stop->Text = L"Stop";
			this->btn_stop->UseVisualStyleBackColor = true;
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(686, 231);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(60, 19);
			this->textBox1->TabIndex = 3;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(686, 256);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(60, 19);
			this->textBox2->TabIndex = 4;
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(686, 281);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(60, 19);
			this->textBox3->TabIndex = 5;
			// 
			// btn_set
			// 
			this->btn_set->Location = System::Drawing::Point(698, 316);
			this->btn_set->Name = L"btn_set";
			this->btn_set->Size = System::Drawing::Size(34, 22);
			this->btn_set->TabIndex = 6;
			this->btn_set->Text = L"Set";
			this->btn_set->UseVisualStyleBackColor = true;
			// 
			// pict_graph
			// 
			this->pict_graph->Location = System::Drawing::Point(4, 3);
			this->pict_graph->Name = L"pict_graph";
			this->pict_graph->Size = System::Drawing::Size(666, 602);
			this->pict_graph->TabIndex = 7;
			this->pict_graph->TabStop = false;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(789, 616);
			this->Controls->Add(this->pict_graph);
			this->Controls->Add(this->btn_set);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->btn_stop);
			this->Controls->Add(this->btn_step);
			this->Controls->Add(this->btn_auto);
			this->Name = L"Form1";
			this->Text = L"Simulator";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pict_graph))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {

			 }
	};
}

