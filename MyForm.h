#pragma once
#include "MyForm1.h"
#include "MyForm2.h"

namespace TrabajoHoy {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace MySql::Data::MySqlClient; // Incluir esta linea

	/// <summary>
	/// Resumen de MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	protected:

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(326, 391);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(122, 54);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Registrar";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(82, 102);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersWidth = 51;
			this->dataGridView1->RowTemplate->Height = 24;
			this->dataGridView1->Size = System::Drawing::Size(656, 262);
			this->dataGridView1->TabIndex = 1;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 36, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(188, 21);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(412, 69);
			this->label1->TabIndex = 2;
			this->label1->Text = L"JUGADORES";
			this->label1->Click += gcnew System::EventHandler(this, &MyForm::label1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(591, 396);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(133, 49);
			this->button2->TabIndex = 3;
			this->button2->Text = L"Ir a patrocinadores";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(40, 391);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(139, 59);
			this->button3->TabIndex = 4;
			this->button3->Text = L"Formulario de registro";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(796, 462);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->button1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ connStr = "server=127.0.0.1;user=root;password=;database=equipo;";
		MySqlConnection^ conn = gcnew MySqlConnection(connStr);

		try {
			conn->Open();

			// Crear el comando para la consulta
			MySqlCommand^ cmd = gcnew MySqlCommand("SELECT * FROM jugadores", conn);
			MySqlDataReader^ reader = cmd->ExecuteReader();

			// Limpiar el DataGridView
			dataGridView1->Rows->Clear();
			dataGridView1->Columns->Clear();

			// Definir columnas del DataGridView
			dataGridView1->Columns->Add("ID_jugador", "ID_jugador");
			dataGridView1->Columns->Add("Nombre", "Nombre");
			dataGridView1->Columns->Add("Apellido", "Apellido");
			dataGridView1->Columns->Add("edad", "edad");
			dataGridView1->Columns->Add("NumeroCamiseta", "NumeroCamiseta");
			dataGridView1->Columns->Add("equipo", "equipo");

			// Leer los datos y agregarlos al DataGridView
			while (reader->Read()) {
				int id = reader->GetInt32("ID_jugador");
				String^ nombres = reader->GetString("Nombre");
				String^ apellidos = reader->GetString("Apellido");
				int edad = reader->GetInt32("edad");
				int NumeroCamiseta = reader->GetInt32("NumeroCamiseta");
				String^ equipo = reader->GetString("equipo");

				dataGridView1->Rows->Add(id, nombres, apellidos, edad, NumeroCamiseta, equipo);
			}

			reader->Close();
		}
		catch (Exception^ ex) {
			MessageBox::Show("Error: " + ex->Message);
		}
		finally {
			conn->Close();
		}
	}

	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		MyForm1^ form = gcnew MyForm1();
		form->ShowDialog();
	}
	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
		MyForm2^ form = gcnew MyForm2();
		form->ShowDialog();
	}
};
};
