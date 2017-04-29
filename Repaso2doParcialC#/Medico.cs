using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Repaso2doParcial
{
    public abstract class Medico: Persona
    {
        Paciente pacienteAcutal;

        protected static Random tiempoAleatorio;

        public Paciente AtenderA
        {
            set
            {
                this.pacienteAcutal = value;
            }
        }

        public virtual string EstaAtiendiendoA
        {
            get
            {
                return this.pacienteAcutal.ToString();
            }
        }

        static Medico()
        {
            tiempoAleatorio = new Random();
        }

        public Medico(string nombre, string apellido)
            :base(nombre, apellido)
        {

        }

        protected abstract void Atender();

        protected virtual void FinalizarAtencion()
        {
            this.FinAtencionPaciente(pacienteAcutal, this);
            pacienteAcutal = null;
        }

        public delegate void FinAtencion(Paciente p, Medico m);
        public event FinAtencion FinAtencionPaciente;


    }
}
