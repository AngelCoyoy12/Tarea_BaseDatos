#pragma once

namespace TrabajoHoy {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace MySql::Data::MySqlClient; // Incluir esta linea

	/// <summary>
	/// Resumen de MyForm1
	/// </summary>
	public ref class MyForm1 : public System::Windows::Forms::Form
	{
	public:
		MyForm1(void)
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
		~MyForm1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	protected:
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::DataGridView^ dataGridView1;

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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 36, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(101, 20);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(607, 69);
			this->label1->TabIndex = 0;
			this->label1->Text = L"PATROCINADORES";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(330, 432);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(146, 50);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Registrar";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm1::button1_Click);
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(113, 115);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersWidth = 51;
			this->dataGridView1->RowTemplate->Height = 24;
			this->dataGridView1->Size = System::Drawing::Size(581, 296);
			this->dataGridView1->TabIndex = 2;
			// 
			// MyForm1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(840, 503);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label1);
			this->Name = L"MyForm1";
			this->Text = L"MyForm1";
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
			MySqlCommand^ cmd = gcnew MySqlCommand("SELECT * FROM patrocinadores", conn);
			MySqlDataReader^ reader = cmd->ExecuteReader();

			// Limpiar el DataGridView
			dataGridView1->Rows->Clear();
			dataGridView1->Columns->Clear();

			// Definir columnas del DataGridView
			dataGridView1->Columns->Add("ID_prs", "ID_prs");
			dataGridView1->Columns->Add("Nombre", "Nombre");
			dataGridView1->Columns->Add("Dir_patrocinio", "Dir_patrocinio");
			dataGridView1->Columns->Add("Can_inversion", "Can_inversion");


			// Leer los datos y agregarlos al DataGridView
			while (reader->Read()) {
				int id = reader->GetInt32("ID_prs");
				String^ nombres = reader->GetString("Nombre");
				String^ Dir_patrocinio = reader->GetString("Dir_patrocinio");
				int Can_inversion = reader->GetInt32("Can_inversion");

				dataGridView1->Rows->Add(id, nombres, Dir_patrocinio, Can_inversion);
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
	};
}
