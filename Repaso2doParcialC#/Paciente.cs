using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Repaso2doParcial
{
    public class Paciente : Persona
    {
        int turno;
        static int ultimoTurnoDado;

        public int Turno
        {
            get
            {
                return this.turno;
            }

        }

        static Paciente()
        {
            ultimoTurnoDado = 0;
        }

        public Paciente(string nombre, string apellido)
            : base(nombre, apellido)
        {
            ultimoTurnoDado++;
            turno = ultimoTurnoDado;
        }

        public Paciente(string nombre, string apellido, int turno)
            : base(nombre, apellido)
        {
            this.turno = turno;
            ultimoTurnoDado = turno;
        }

        public override string ToString()
        {
            StringBuilder str = new StringBuilder();
            str.AppendFormat("Turno Nº {0}: {2}, {1}", this.turno, this.Nombre, this.Apellido);
            return str.ToString();
        }

    }
}
