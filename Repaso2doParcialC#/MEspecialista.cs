using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Repaso2doParcial
{
    class MEspecialista : Medico, IMedico
    {
        Especialidad especialidad;

        public enum Especialidad
        {
            Traumatologo,
            Odontologo
        }

        public MEspecialista(string nombre, string apellido, Especialidad e)
            :base(nombre, apellido)
        {
            this.especialidad = e;
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
            System.Threading.Thread.Sleep(Medico.tiempoAleatorio.Next(5000, 10000));
            this.FinalizarAtencion();
        }

        public override string ToString()
        {
            return String.Format("{0}, {1}", this.Apellido, this.Nombre);
        }
    }
}
