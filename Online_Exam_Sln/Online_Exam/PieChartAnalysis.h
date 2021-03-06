#pragma once
#include "Database.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace Database;


namespace Online_Exam {

	/// <summary>
	/// Summary for PieChartAnalysis
	/// </summary>
	public ref class PieChartAnalysis : public System::Windows::Forms::UserControl
	{
	public:
		PieChartAnalysis(String ^ examCode, String ^ userName)
		{
			this->ExamCode = examCode;
			this->username = userName;
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~PieChartAnalysis()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TabControl^  tabControl1;
	protected:
	private: System::Windows::Forms::TabPage^  tabPage1;
	private: System::Windows::Forms::TabPage^  tabPage2;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;
		OES ^ examInfo;
		OES ^ studentPerf;
		String ^ ExamCode;
		String ^ username;
		array<Int32> ^ correct;
		array<Int32> ^ unattempted;
		array<Int32> ^ incorrect;

	private: System::Windows::Forms::DataVisualization::Charting::Chart^  pieChart;
	private: System::Windows::Forms::Label^  label1;
			 System::Windows::Forms::DataVisualization::Charting::Series^  Scorrect = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			 
#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::Windows::Forms::DataVisualization::Charting::ChartArea^  chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^  legend1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^  series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->pieChart = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->tabControl1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pieChart))->BeginInit();
			this->SuspendLayout();
			// 
			// tabControl1
			// 
			this->tabControl1->Controls->Add(this->tabPage1);
			this->tabControl1->Controls->Add(this->tabPage2);
			this->tabControl1->Location = System::Drawing::Point(38, 71);
			this->tabControl1->Margin = System::Windows::Forms::Padding(2);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(840, 444);
			this->tabControl1->TabIndex = 1;
			// 
			// tabPage1
			// 
			this->tabPage1->Location = System::Drawing::Point(4, 25);
			this->tabPage1->Margin = System::Windows::Forms::Padding(2);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(2);
			this->tabPage1->Size = System::Drawing::Size(832, 415);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"tabPage1";
			this->tabPage1->UseVisualStyleBackColor = true;
			// 
			// tabPage2
			// 
			this->tabPage2->Location = System::Drawing::Point(4, 25);
			this->tabPage2->Margin = System::Windows::Forms::Padding(2);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(2);
			this->tabPage2->Size = System::Drawing::Size(832, 415);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"tabPage2";
			this->tabPage2->UseVisualStyleBackColor = true;
			// 
			// pieChart
			// 
			chartArea1->Name = L"ChartArea1";
			this->pieChart->ChartAreas->Add(chartArea1);
			this->pieChart->Dock = System::Windows::Forms::DockStyle::Fill;
			legend1->Name = L"Legend1";
			this->pieChart->Legends->Add(legend1);
			this->pieChart->Location = System::Drawing::Point(2, 2);
			this->pieChart->Name = L"pieChart";
			series1->ChartArea = L"ChartArea1";
			series1->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Pie;
			series1->Legend = L"Legend1";
			series1->Name = L"Series1";
			this->pieChart->Series->Add(series1);
			this->pieChart->Size = System::Drawing::Size(828, 411);
			this->pieChart->TabIndex = 0;
			this->pieChart->Text = L"piechart";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Century Gothic", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(39, 24);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(282, 28);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Individual Performance";
			// 
			// PieChartAnalysis
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->Controls->Add(this->label1);
			this->Controls->Add(this->tabControl1);
			this->Name = L"PieChartAnalysis";
			this->Size = System::Drawing::Size(916, 532);
			this->Load += gcnew System::EventHandler(this, &PieChartAnalysis::PieChartAnalysis_Load);
			this->tabControl1->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pieChart))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void PieChartAnalysis_Load(System::Object^  sender, System::EventArgs^  e) {
				 examInfo = gcnew OES();
				 examInfo->ExecQuery("SELECT NumSections\
									 FROM  Exam\
									WHERE(ExamCode = " + this->ExamCode + " )");

				 studentPerf = gcnew OES();
				 studentPerf->ExecQuery("SELECT SectionMarks, CorrectSect, IncorrectSect, UnattemptSect, ExamCode, Username "\
					 "FROM  Performance "\
					 "WHERE(ExamCode = " + this->ExamCode + " ) AND(Username = '" + this->username + "' );");

				 tabControl1->Controls->Clear();
				 int numSect = Convert::ToInt32(examInfo->DBDT->Rows[0]->default["NumSections"]);
				 for (int i = 0; i < numSect; i++)
				 {
					 TabPage^ Section = gcnew TabPage();
					 Section->Text = "Section" + (i + 1).ToString();
					 tabControl1->Controls->Add(Section);
				 }
				 tabControl1->SelectedIndexChanged += gcnew EventHandler(this, &PieChartAnalysis::TabSelect);
				 tabControl1->SelectedIndex = 0;

				 correct = gcnew array<Int32>(numSect);
				 incorrect = gcnew array<Int32>(numSect);
				 unattempted = gcnew array<Int32>(numSect);
				 array<String^>^delimiters = { "," };

				 String ^y = studentPerf->DBDT->Rows[0]->default["CorrectSect"]->ToString()->Trim();
				 array<String^> ^temp = y->Split(delimiters, StringSplitOptions::RemoveEmptyEntries);
				 for (int i = 0; i < temp->Length; i++)
				 {
					 correct[i] = Convert::ToInt32(temp[i]);
				 }

				 y = studentPerf->DBDT->Rows[0]->default["IncorrectSect"]->ToString()->Trim();
				 temp = y->Split(delimiters, StringSplitOptions::RemoveEmptyEntries);
				 for (int i = 0; i < temp->Length; i++)
				 {
					 incorrect[i] = Convert::ToInt32(temp[i]);
				 }

				 y = studentPerf->DBDT->Rows[0]->default["UnattemptSect"]->ToString()->Trim();
				 temp = y->Split(delimiters, StringSplitOptions::RemoveEmptyEntries);
				 for (int i = 0; i < temp->Length; i++)
				 {
					 unattempted[i] = Convert::ToInt32(temp[i]);
				 }

				 int selInd = 0;
				 this->pieChart->Series->Clear();
				 //Define Series
				 Scorrect->IsValueShownAsLabel = true;
				 Scorrect->LabelFormat = L"#";
				 Scorrect->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Pie;
				 Scorrect->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));

				 array<String^>^ xValue = { "Unattempted", "Correct", "Incorrect" };
				 array<Int32>^ yValue = { unattempted[selInd], correct[selInd], incorrect[selInd] };
				 Scorrect->Points->DataBindXY(xValue, yValue);//DataBindXY({1, 2, 3}, { "a", "b", "c" });

				 this->pieChart->Series->Add(Scorrect);

				 tabControl1->TabPages[selInd]->Controls->Add(this->pieChart);
				 this->pieChart->Show();
	}

	private: System::Void TabSelect(System::Object^ sender, EventArgs^ e) {
				 int selInd = static_cast<int>(static_cast<TabControl^>(sender)->SelectedIndex);
				 this->pieChart->Series->Clear();
				
				 array<String^>^ xValue = { "Unattempted", "Correct", "Incorrect" };
				 array<Int32>^ yValue = { unattempted[selInd], correct[selInd], incorrect[selInd] };
				 Scorrect->Points->DataBindXY(xValue, yValue);//DataBindXY({1, 2, 3}, { "a", "b", "c" });

				 this->pieChart->Series->Add(Scorrect); 
				 
				 tabControl1->TabPages[selInd]->Controls->Add(this->pieChart);
				 this->pieChart->Show();

	}
};
}
