using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Repaso2doParcial
{
    public partial class FrmFinal : Form
    {

        MGeneral medicoGeneral;
        MEspecialista medicoEspecialista;
        System.Threading.Thread mocker;
        Queue<Paciente> pacientesEnEspera;
        public FrmFinal()
        {
            InitializeComponent();
            this.medicoGeneral = new MGeneral("Luis", "Salinas");
            this.medicoEspecialista = new MEspecialista("Jorge", "Iglesias", MEspecialista.Especialidad.Traumatologo);
            pacientesEnEspera = new Queue<Paciente>();
            this.medicoEspecialista.FinAtencionPaciente += FinAtencion;
            this.medicoGeneral.FinAtencionPaciente += FinAtencion;
            this.Load += FrmFinal_Load;
        }

        private void FinAtencion(Paciente p, Medico m)
        {
            StringBuilder str = new StringBuilder();
            str.AppendFormat("Finalizó la atención de {0} por {1}", p.ToString(), m.ToString());
            MessageBox.Show(str.ToString());
        }

        private void MockPacientes()
        {
            this.pacientesEnEspera.Enqueue(new Paciente("ss", "aa"));
            System.Threading.Thread.Sleep(5000);
        }

        private void AtenderPaciente(IMedico medico)
        {
            if (this.pacientesEnEspera.Count > 0)
                medico.IniciarAtencionPaciente(this.pacientesEnEspera.Dequeue());
            else
                MessageBox.Show("No hay más pacientes");
        }

        private void BtnGeneral_Click(object sender, EventArgs e)
        {
            AtenderPaciente(this.medicoGeneral);
        }

        private void BtnEspecialista_Click(object sender, EventArgs e)
        {
            AtenderPaciente(this.medicoEspecialista);
        }

        private void FrmFinal_Closing(object sender, FormClosingEventArgs e)
        {
            if (this.mocker.IsAlive)
                this.mocker.Abort();
        }

        private void FrmFinal_Load(object sender, EventArgs e)
        {
            this.mocker = new System.Threading.Thread(MockPacientes);
            this.mocker.Start();
            this.BtnEspecialista.Visible = true;
            this.BtnGeneral.Visible = true;
        }
    }

}
