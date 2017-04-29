using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Repaso2doParcial
{
    public abstract class Persona
    {
        string nombre;
        public string Nombre
        {
            get
            {
                return this.nombre;
            }

            set
            {
                this.nombre = value;
            }
        }

        string apellido;
        public string Apellido
        {
            get
            {
                return this.apellido;
            }

            set
            {
                this.apellido = value;
            }
        }

        public Persona(string nombre, string apellido)
        {
            this.Nombre = nombre;
            this.Apellido = apellido;
        }
    }
}
