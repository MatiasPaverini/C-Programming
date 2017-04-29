using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Repaso2doParcial
{
    class MGeneral : Medico, IMedico
    {
        public MGeneral(string nombre, string apellido)
            :base(nombre, apellido)
        {

        }
        public void IniciarAtencionPaciente(Paciente p)
        {
            this.AtenderA = p;
            System.Threading.Thread newThread;
            newThread = new System.Threading.Thread(Atender);
            newThread.Start();
        }

        protected override void Atender()
        {
            System.Threading.Thread.Sleep(Medico.tiempoAleatorio.Next(1500, 2200));
            this.FinalizarAtencion();
        }

        public override string ToString()
        {
            return String.Format("{0}, {1}", this.Apellido, this.Nombre);
        }
    }
}
